from cs50 import get_string

s = get_string("Do you agree? ")

# python中没有char类型，使用str类型
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")

