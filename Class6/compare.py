from cs50 import *

s = get_string("Do you agree? ")

if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")

# 另一种写法
if s in ["Y", "y"]:
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")

