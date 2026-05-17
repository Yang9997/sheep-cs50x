from cs50 import get_int

x = get_int("What is x: ")
y = get_int("What is y: ")

if x < y:
    print("x is less than y.")
elif x > y:
    print("x is more than y.")
else:
    print("x is equal to y.")
    
