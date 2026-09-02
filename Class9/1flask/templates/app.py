from flask import Flask, render_template, request

# 将app定义为Flask程序
app = Flask('_name_')

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
    return render_template("index.html")


@app.route("/sheep")
def sheep():
    return "sheep"
