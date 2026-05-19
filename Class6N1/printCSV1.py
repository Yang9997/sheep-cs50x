import csv

name = input("name: ")
number = input("number: ")

with open("phonebook1.csv", "a") as file:
    # 创建一个 DictWriter 对象，用于将字典数据写入 CSV 文件。
    # fieldnames=["name", "number"] 指定了字典中键的顺序，也决定了 CSV 文件的列名（表头）。
    # 这个对象会将字典的键映射到对应的列位置。
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
