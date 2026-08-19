import csv

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Enter your favorite language: ")

# ？ 将其解析为一个数据值而非sql语句的一部分，防止注入攻击
rows = db.execute("select count(*) from favorites where language like ?", "%" + favorite + "%")

row = rows[0]

print(row["count(*)"])

