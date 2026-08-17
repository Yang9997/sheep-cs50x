
str = input("Enter a sentence: ")
if str.lstrip().lower().startswith("hello"):
    print("$0")
elif str.lstrip().lower().startswith("h"):
    print("$20")
else:
    print("$100")
