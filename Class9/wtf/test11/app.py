from flask import Flask, render_template, request

app = Flask(__name__)

registrants = {}

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    username = request.form.get("username")
    while username == '':
        return render_template("index.html")
    age = request.form.get("age")
    while not age.isdigit():
        return render_template("index.html")

    registrants[username] = age
    return render_template("register.html", registrants=registrants)

@app.route("/register")
def back():
    return render_template("index.html")
