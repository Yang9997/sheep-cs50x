from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    # 如果浏览器之前没有登录名字
    if not session.get("name"):
        # 重定向到/login路由行为
        return redirect("/login")
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    # 如果浏览器向服务器发送post类型的请求
    if request.method == "POST":
        # 获取输入的名字
        session["name"] = request.form.get("name")
        # 重定向到/路由行为
        return redirect("/")
    return render_template("login.html")

@app.route("/logout")
def logout():
    # 置None,没有值
    session["name"] = None
    return redirect("/")
