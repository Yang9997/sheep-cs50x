s = input("Enter the string: ")
s = s.lstrip().lower()
if s.startswith("hello"):
    print("$0")
elif s.startswith("h"):
    print("$20")
else:
    print("$100")

