from flask import Flask, render_template
app = Flask(__name__)

COLORS = [
    "red",
    "blue",
    "green"
]

@app.route("/")
def index():
    return render_template("index.html", colors=COLORS)
