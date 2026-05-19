import sys

# list 列表
names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

name = input("Name: ")

# 线性搜索
for n in names:
    if n == name:
        print("Found")
        sys.exit(0)

print("Not found")
sys.exit(1)


