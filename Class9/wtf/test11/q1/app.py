try:
    age = int(age)
    if age < 18 or age > 100:
    return render_template("error.html", message="Invalid age")
except ValueError:
    return render_template("error.html", message="Invalid age")
