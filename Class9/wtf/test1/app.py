from flask import Flask, render_template

# 创建一个flask web应用
app = Flask(__name__)

# 当浏览器访问/时，运行下面的函数index()
@app.route("/index")
def index():
    return render_template("index.html")

@app.route("/about")
def about():
    return render_template("about.html")

