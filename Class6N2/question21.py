def getCents():
    while(1):
        try:
            cent = float(input("Enter a number: "))
            if cent >= 0:
                return cent
            else:
                print("Please a positive number.")
        except ValueError:
            print("Please enter a number.")

def main():
    cent = getCents()
    cent = int(100 * cent)
    number25 = cent // 25
    cent = cent % 25
    number10 = cent // 10
    cent = cent % 10
    number5 = cent // 5
    number1 = cent % 5
    number = number25 + number10 + number5 + number1
    print(number)

main()
