# TODO
def main():
    height = get_height()
    for i in range(height):
        print(" " * (height - 1 - i) + "#" * (i + 1) + "  " + "#" * (i + 1))

def get_height():
    while True:
        number = input("Height: ")
        try:
            int(number)
            number = int(number)
            if number < 9 and number > 0:
                return number
            else:
                print("Error. Please try again.")
        except ValueError:
            print("Error. Please try again.")

main()
