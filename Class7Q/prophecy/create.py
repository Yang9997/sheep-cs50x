import csv

from cs50 import SQL

db = SQL("sqlite:///roster.db")


students = []
with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        students.append(row)

# 先制作社团表
for row in students:
    db.execute("insert or ignore into societies(house, head) values(?, ?)", row["house"], row["head"])
# 学生表
for row in students:
    db.execute("insert into students(id, student_name) values(?, ?)", row["id"], row["student_name"])
# 社团分配表
for row in students:
    db.execute("insert into society_distribution(student_id, house) values(?, ?)", row["id"], row["house"])




