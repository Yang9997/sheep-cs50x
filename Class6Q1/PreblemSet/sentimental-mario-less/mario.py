# TODO

def get_height():
    while True:
        try:
            h = int(input("Height: "))
            if h > 0 and h < 9:
                return h
            else:
                print("0 ~ 8!!")
        except ValueError:
            print("Int!!")



height = get_height()
for i in range(height):
    print(" " * (height - 1 - i) + "#" * (i + 1))

