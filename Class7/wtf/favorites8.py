import cs50

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

rows = db.execute("select count(*) from favorites where problem like?", "%" + favorite + "%")

row = rows[0]

print(row["count(*)"])
