# TODO

def getHeight():
    while(1):
        try:
            number = int(input("Height: "))
            if number > 0 and number < 9:
                return number
            else:
                print("Please enter a number 1 - 8.")
        except ValueError:
            print("Please enter a number.")

def main():
    height = getHeight()
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i + "  " + "#" * i)

main()
