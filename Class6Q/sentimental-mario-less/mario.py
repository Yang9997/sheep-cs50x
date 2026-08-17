def getHeight():
    while True:
        try:
            number = int(input("Height: "))
            if number > 8 or number <= 0:
                print("Don't over 8 and smaller than or equal to 0.")
                continue
            else:
                return number
        except ValueError:
            print("Please enter a number.")



height = getHeight()
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)

