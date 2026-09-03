from flask import Flask, request, render_template, redirect, session
from flask_session import Session
from cs50 import SQL

app = Flask(__name__)
app.config["SESSION_PRIMARY"] = False
app.config["SESSION_TYPT"] = "filesystem"
db = SQL("sqlite:///store.db")
Session(app)

@app.route("/")
def index():
    db.execute("""create table if not exits books(
        id integer key primary autoincrement,
        name text not null )""")
    books = db.execute("select * from books")
    return render_template("books.html", books=books)

@app.route("/cart", methods=["POST", "GET"])
def cart():
    if "cart" not in session:
        session["cart"] = []

    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")

    books = db.execute("select * from books where id in (?)", session["cart"])
    return render_template("cart.html", books=books)
