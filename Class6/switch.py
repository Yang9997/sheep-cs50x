from cs50 import *

x = get_int("Please enter a integer: ")
y = get_int("Please enter a integer: ")

if x < y:
    print("x is less than y.")
elif x > y:
    print("x is more than y.")
else:
    print("x is equal to y.")
