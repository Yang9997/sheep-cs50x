from flask import Flask, render_template, redirect, request
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = [
    "volleyball",
    "soccer",
    "swimming",
    "basketball"
]

@app.route("/")
def index():
    # python语法中""不能跨行，要跨行的话必须""" """三个双引号
    # 即便是在python里面用这种创建table的命令，还是得在sqlite xxx.db创建数据库之后才行
    db.execute("""create table if not exists registrants(
               id integer primary key autoincrement,
               name text not null,
               sport text not null)""")
    return render_template("index.html", sports=SPORTS)

@app.route("/regist", methods=["POST"])
def regist():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
         return render_template("failure.html")

    # (name, sport)不能少的，不然从第一个变量开始赋值，就是id = name name = sport sport没有值
    db.execute("insert into registrants (name, sport) values (?, ?)", name, sport)
    return redirect("/registrants")

@app.route("/deregist", methods=["POST"])
def deregist():
    name = request.form.get("name")
    sport = request.form.get("sport")
    # sql的语法是这样的
    db.execute("delete from registrants where name = ? and sport = ?", name, sport)
    # 什么时候restrict，什么时候render_template？
    # 重定向url变化，后者不变。
    # 重定向用于处理完表单（注册、注销、删除等操作），希望用户看到更新后的页面并避免重复提交时。
    # render用于显示数据（比如注册成功后展示注册列表），并且不需要改变 URL 时。
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    # select句型的返回值是个字典列表
    REGISTRANTS = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=REGISTRANTS)

