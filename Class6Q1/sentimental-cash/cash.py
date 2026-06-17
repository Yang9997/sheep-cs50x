# TODO

def getCent():
    while(1):
        try:
            cent = float(input("Change owed: "))
            if cent >= 0:
                return cent
            else:
                print("Please enter a positive number.")
        except ValueError:
            print("Please enter a number.")

def main():
    cent = getCent()
    cent = 100 * cent
    number = 0
    for i in [25, 10, 5, 1]:
        number += cent // i
        cent = cent % i
    number = int(number)
    print(number)

main()

