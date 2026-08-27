from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    city = request.args.get("city", "China")
    return render_template("index.html", city=city)
