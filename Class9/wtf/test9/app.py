from flask import Flask, render_templates, request

app = Flask(__name__)

# 列表
SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

