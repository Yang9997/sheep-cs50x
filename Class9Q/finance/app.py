import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    ifhasShare = db.execute("select * from share where user_id = ?", session["user_id"])
    if not ifhasShare:
        cash = 10000.00
        return render_template("indexOrg.html", message="no share", cash=cash)
    rows = db.execute("select symbol, sum(shares) as sharesSum from share where user_id = ? group by symbol having sum(shares) > 0", session["user_id"])
    cash = db.execute("select cash from users where id = ?", session["user_id"])[0]["cash"]
    # 总资产
    money = cash
    # row 引用了 rows 列表中当前那个字典对象，所以修改这个字典对象会反映在 rows 中
    # 因为 rows 本身是列表，row 指向的是其中一个元素
    for row in rows:
        symbol = row["symbol"]
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol", 400)
        price= float(quote["price"])
        nowmoney = price * row["sharesSum"]
        money += nowmoney
        # 塞
        row["price"] = price
        row["money"] = nowmoney
    return render_template("index.html", rows=rows, cash=cash, money=money)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        # 多少股
        shares = request.form.get("shares")
        if not symbol:
            return apology("no symbol", 400)
        symDct = lookup(symbol)
        if not symDct:
            return apology("invalid symbol", 400)
        if not shares:
            return apology("no shares", 400)
        if not shares.isdigit() or int(shares) == 0:
            return apology("invalid shares", 400)
        # 总价格 = 一股多少钱 * 多少股
        price = symDct["price"]
        shares = int(shares)
        money = price * shares
        # price小数real
        cash = db.execute("select cash from users where id = ?", session["user_id"])[0]["cash"]
        # 买不起
        if cash < money:
            return apology("not enough.", 409)
        cash = cash - money
        # "%"是使用like时的通配符，其他语法不能用
        db.execute("insert into share (user_id, symbol, price, shares) values (?, ?, ?, ?)", session["user_id"], symbol, price, shares)
        db.execute("update users set cash = ? where id = ?", cash, session["user_id"])
        return redirect("/")
    if not session["user_id"]:
        return redirect("/register")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    # sqlite允许order指定多个字段
    rows = db.execute("select symbol, price, shares, created_at from share where user_id = ? order by symbol asc, created_at desc", session["user_id"])
    for row in rows:
        if row["shares"] > 0:
            row["attitude"] = "buy"
        else:
            row["shares"] = -row["shares"]
            row["attitude"] = "sell"

    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    db.execute("""create table if not exists share(
                id integer primary key autoincrement not null,
                user_id integer not null,
                symbol text not null,
                price real not null,
                shares integer not null,
                created_at datetime not null default current_timestamp,
                foreign key (user_id) references users(id))""")

    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("no symbol", 400)
        symDct = lookup(symbol)
        if not symDct:
            return apology("invalid symbol", 400)
        name = symDct["name"]
        price = symDct["price"]
        return render_template("quoted.html", name=name, price=price)
    if not session["user_id"]:
        return redirect("/register")
    return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        name = db.execute("select username from users where username = ?", username)
        if name:
            # name已存在
            # 409 conflict 和服务器现有数据冲突
            return apology("Username has existed.", 400)
        if not username or not password or not confirmation or password != confirmation:
            # 400 bad request 两次密码不一致；空字段
            return apology("Password error.", 400)

        db.execute("insert into users (username, hash) values (?, ?)", username, generate_password_hash(password))
        user_id = db.execute("select id from users where username = ?", username)[0]["id"]
        session["user_id"] = user_id
        # 注册成功之后直接进到主页
        return redirect("/")

    return render_template("/register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if not symbol:
            return apology("symbol error", 400)
        if not shares:
            return apology("shares error", 400)
        try:
            shares = int(shares)
        except ValueError:
            return apology("shares is not a integer", 400)
        if shares <= 0:
            return apology("invalid shares", 400)
        ifhasSym = db.execute("select * from share where symbol = ? and user_id = ?", symbol, session["user_id"])
        if not ifhasSym:
            return apology("have not buy this symbol", 400)
        nowshares = db.execute("select sum(shares) as sharesSum from share where symbol = ? and user_id = ?", symbol, session["user_id"])[0]["sharesSum"]
        if nowshares < shares:
            return apology("shares is not enough", 400)
        price = lookup(symbol)["price"]
        db.execute("insert into share (user_id, symbol, price, shares) values (?, ?, ?, ?)", session["user_id"], symbol, price, -shares)
        cash = db.execute("select cash from users where id = ?", session["user_id"])[0]["cash"]
        cash += price * shares
        db.execute("update users set cash = ? where id = ?", cash, session["user_id"])
        return redirect("/")

    # sum(shares) 是聚合函数，不能这样放在 where 里。
    # symbols = db.execute("select symbol from share where user_id = ? and sum(shares) > 0 group by symbol", session["user_id"])
    # where：分组前过滤普通行
    # having：分组之后过滤聚合结果
    symbols = db.execute("select symbol from share where user_id = ? group by symbol having sum(shares) > 0", session["user_id"])
    return render_template("sell.html", symbols=symbols)
