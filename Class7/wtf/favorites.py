import csv

with open("favorites.csv", "r") as file:

    reader = csv.reader(file)
    next(reader)

    for row in reader:
        # print(type(row))
        # print(len(row))
        # print(row[0])
        print(row[1])
