import sys

names = ["Bill", "Bob", "Fred", "Ginny"]
name = input("Name: ")

if name in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)

