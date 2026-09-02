from flask import Flask, request, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/regist", methods=["POST"])
def regist():
    name = request.form.get("name", "world")
    return render_template("regist.html", name=name)
