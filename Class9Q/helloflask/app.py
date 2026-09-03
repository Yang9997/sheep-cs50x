from flask import Flask, render_template, request, redirect

app = Flask(__name__)


@app.route("/", methods=["POST", "GET"])
def index():
    if request.method == "POST":
        print("form submitted!")
        color = request.form.get("color")
        return render_template("color.html", color=color)
    return render_template("index.html")



