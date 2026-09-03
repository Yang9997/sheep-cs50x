# 先写html代码，再根据跳转的逻辑来写py路由代码，初步判断这样是更好的

from flask import Flask, request, render_template, redirect, session
from flask_session import Session

app = Flask(__name__)
app.config["SESSION_PRIMARY"] = False
app.config["SESSION_TYPE"] = "filesystem"

Session(app)

@app.route("/login", methods=["POST","GET"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    # 跳转到登录页面
    return render_template("login.html")

@app.route("/")
def index():
    # 首次访问url
    # 如果session["name"] 没有值
    if not session.get("name")
        return redirict("/login")
    # 跳转到主页
    return render_template("index.html")

@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")
