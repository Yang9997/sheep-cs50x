def getANumber():
    while(1):
        try:
            number = int(input("Enter a number:"))
            if number <= 0:
                print("Please enter a positive int.")
                continue
            else:
                return number
        except ValueError:
            print("Please enter a int.")

def main():
    number = getANumber()
    print(number)


main()
