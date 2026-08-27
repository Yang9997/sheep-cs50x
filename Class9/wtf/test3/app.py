from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    # # request.args用于读取发送给服务器的query string，参数就是变量名字符串，?name=sheep中的name
    # name = request.args.get("name")
    # return  render_template("index.html", name=name)

    # 找name,就是找有没有?name=...这一段，有的话就按这一段算，没有的话就默认是sheep这个字符串
    name = request.args.get("name", "sheep")
    return  render_template("index.html", name=name)



