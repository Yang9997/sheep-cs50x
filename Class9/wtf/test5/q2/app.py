from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/hello")
def greet():
    name = request.args.get("person")
    return render_template("hello.html", person=name)
