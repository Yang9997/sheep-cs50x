from cs50 import *

def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        # get_int()这个函数必须要接收参数，不能空
        n = get_int("Height: ")
        if n > 0:
            return n

main()
