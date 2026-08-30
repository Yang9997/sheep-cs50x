from flask import Flask, render_template, request, redirect
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = [
    "soccer",
    "volleyball",
    "swimming",
    "basketball"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():

    id = request.form.get("id")
    if id:
        db.execute("delete from registrants where id = ?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():
    name=request.form.get("name")
    sport=request.form.get("sport")
    # 相同的判定方法
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    # 没有数据库的时候是字典增加键值对，这里是sql语言
    db.execute("insert into registrants (name, sport) values (?, ?)", name, sport)

    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    # 比起没有数据库的纯python字典存储，这里直接用了python插入sql语言
    registrants = db.execute("select * from registrants")
    print(type(registrants))
    return render_template("registrants.html", registrants=registrants)

