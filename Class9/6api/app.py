from cs50 import SQL
from flask import Flask, request, render_template, redirect

app = Flask(__name__)
db = SQL("sqlite:///shows.db")

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("select * from shows where title like ? limit 50", "%"+q+"%")
    else:
        shows = []
    return render_template("search.html", shows=shows)

