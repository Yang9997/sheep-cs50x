import sys

names = ["Bill", "Maria", "Bob", "Amy", "Jean", "Jone", "Dog"]
name = input("Name: ")
# for n in names:
#     if n == name:
#         print("Found")
#         sys.exit(0)
# 另一种写法
if name in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)
