from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    # if "name" in request.args:
    #     name = request.args["name"]
    # else:
    #     name = "world"
    
    # 这一句等价于上面四句
    name = request.args.get("name", "world")
    # 左边的name是html里面的占位符
    return render_template("index.html", name=name)
