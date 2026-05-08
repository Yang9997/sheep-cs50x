for i in range(4):
    # print函数end值默认是\n
    print("?", end = "")
print()

# 另一种写法
from cs50 import *
i = get_int("Please enter a number: ")
print("?" * i)
