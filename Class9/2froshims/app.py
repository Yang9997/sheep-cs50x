from flask import Flask, render_template, request, redirect

app = Flask(__name__)

SPORTS = [
    "soccer",
    "basketball",
    "swimming",
    "volleyball"
]

REGISTRANTS = {}

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="No Name")
    sport = request.form.get("sport")
    if not sport or sport not in SPORTS:
        return render_template("error.html", message="No Sport or Invalid Sport")

    REGISTRANTS[name] = sport
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)

