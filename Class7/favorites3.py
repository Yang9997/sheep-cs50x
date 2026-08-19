import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = {}
    for row in reader:
        favorite = row["problem"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

item = input("Enter your problem: ")
if item in counts:
    print(counts[item])
