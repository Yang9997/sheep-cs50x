from flask import Flask, render_template, request

app = Flask(__name__)

ages = []

@app.route("/", methods=["POST"])
def index():
    age = request.form.get("age")
    try:
        age = int(age)
        if age < 30 or age > 70:
            return render_template("error.html", message="Invalid Age")
    except ValueError:
        return render_template("error.html", message="Error Age")

    ages.append(age)
    return render_template("age.html", ages=ages)
