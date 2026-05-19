greeting = input("input: ").lower()
list = greeting.split()
if list[0] == "hello" or list[0] == "hello," or list[0] == "hello!" or list[0] == "hello." or list[0] == "hello?":
    print("$0")
elif list[0][0] == "h":
    print("$20")
else:
    print("$100")
