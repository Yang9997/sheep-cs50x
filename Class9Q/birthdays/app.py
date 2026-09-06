import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        # 实现一个页面多个按钮触发不同submit的方法，给button相同的name不同的value
        action = request.form.get("action")
        if action == "add":
            name = request.form.get("name")
            month = request.form.get("month")
            day = request.form.get("day")
            if not name or not month or not day:
                return redirect("/")
            if not month.isdigit() or not day.isdigit():
                return redirect("/")
            month = int(month)
            day = int(day)
            # 这里其实应该对闰年闰月什么的进行详细判定，我不想写了好长，就这样吧
            if month < 1 or month > 12 or day < 1 or day > 31:
                return redirect("/")
            db.execute("insert into birthdays (name, month, day) values (?, ?, ?)", name, month, day)
            return redirect("/")
        elif action == "delete":
            id = request.form.get("id")
            if not id:
                return redirect("/")
            if not id.isdigit():
                return redirect("/")
            id = int(id)
            # 如果执行成功了但什么都没删也并不会抛出异常，抛出异常查一下是不是table名字写错了或者语法有问题
            db.execute("delete from birthdays where id = ?", id)
            return redirect("/")
    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("select name, month, day from birthdays order by month, day")
        return render_template("index.html", birthdays=birthdays)

