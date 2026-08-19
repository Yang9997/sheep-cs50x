# 计数
import csv

def getLanguage():
    with open("favorites.csv", "r") as file:
        reader = csv.DictReader(file)

        counts = {}
        for row in reader:
            language = row["language"]
            if language in counts:
                counts[language] += 1
            else:
                counts[language] = 1
    return counts


def getProblem():
    with open("favorites.csv", "r") as file:
        reader = csv.DictReader(file)
        counts = {}
        for row in reader:
            favorite = row["problem"]
            if favorite in counts:
                counts[favorite] += 1
            else:
                counts[favorite] = 1
    return counts


# 按需排序
counts1 = getLanguage()
for favorite in sorted(counts1, key = lambda language: counts1[language], reverse=True):
    print(f"{favorite}: {counts1[favorite]}")
print("===")
counts2 = getProblem()
for favorite in sorted(counts2, key = lambda problem: counts2[problem], reverse=True):
    print(f"{favorite}: {counts2[favorite]}")
