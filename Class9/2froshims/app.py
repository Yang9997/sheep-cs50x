from flask import Flask, render_template, request, redirect
app = Flask(__name__)
REGISTRANTS = {}
SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/", methods=["GET", "POST"])
def index():
    return  render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    # 校验姓名
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="There is no name in form.")

    # 校验运动项目
    sport = request.form.get("sport")
    if not sport:
       return render_template("error.html", message="There is no sport in form.")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport.")

    # 保存注册者信息
    # 这是个字典
    REGISTRANTS[name] = sport

    # 注册成功，正在跳转
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
