# csv

import csv

with open("databases/small.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)


# 关键理解：

# csv.DictReader 把每一行变成一个字典
# 第一行（name,AGATC,AATG...）自动变成键（key）
# 每一行的值都是字符串（注意 '2' 不是数字 2，要用 int() 转）
