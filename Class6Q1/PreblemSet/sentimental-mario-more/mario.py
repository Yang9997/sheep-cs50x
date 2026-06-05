# TODO

def get_height():
    while True:
        try:
            h = int(input("Height: "))
            if h < 9 and h > 0:
                return h
            else:
                print("0 ~ 8!!")
        except ValueError:
            print("Int!!")


height = get_height()
for i in range(height):
    print(" " * (height - 1 - i) + "#" * (i + 1) + "  " + "#" * (i + 1))
