# TODO

from cs50 import *

def main():
    cash = get_cash()

    n25 = int(cash / 25)
    cash = cash % 25
    n10 = int(cash / 10)
    cash = cash % 10
    n5 = int(cash / 5)
    n1 = cash % 5

    print(n25 + n10 + n5 + n1)


def get_cash():
    while True:
        try:
            cash = get_float("Change owed: ")
            # int()函数是截断，好
            cash = int(cash * 100)
            if cash >= 0:
                return cash
            else:
                print("Error. Please enter a float.")
        except ValueError:
            print("Error. Please enter a float.")

main()
