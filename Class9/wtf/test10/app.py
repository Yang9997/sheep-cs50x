from flask import Flask, request, render_template

app = Flask(__name__)

registrants = {}

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    username = request.form.get("username")
    age = request.form.get("age")
    registrants[username] = age
    return render_template("register.html", registrants=registrants)

