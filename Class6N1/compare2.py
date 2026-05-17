from cs50 import get_string

s = get_string("Do you agree? ")

if s in ["Y", "y"]:
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")

