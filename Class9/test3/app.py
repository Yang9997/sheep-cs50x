from flask import Flask, request, render_template, session, redirect
from flask_session import Session

app = Flask(__name__)

app.config["SESSION_PRIMATY"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/login", methods=["POST", "GET"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")


@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")

@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")
