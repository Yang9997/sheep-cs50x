# TODO
from cs50 import get_string

def getNumber():
    while True:
        number = get_string("Number: ")
        if not number.isdigit():
            print("Please enter a number.")
        else:
            return number

def ifValid(number):
    sum = 0
    tmp = 0
    number = int(number)

    while number > 0:
        sum += number % 10
        number //= 10
        tmp = number % 10 * 2
        if tmp > 9:
            sum += tmp // 10 + tmp % 10
        else:
            sum += tmp
        number //= 10

    if sum % 10 != 0:
        print("INVALID")
        return False
    else:
        return True

def printCredit(number, isvalid):
    if isvalid:
        if len(number) == 15 and (number.startswith("37") or number .startswith("34")):
            print("AMEX")
        elif len(number) == 16 and (number.startswith("51") or number.startswith("52") or number.startswith("53") or number.startswith("54") or number.startswith("55")):
            print("MASTERCARD")
        elif (len(number) == 16 or len(number) == 13) and number.startswith("4"):
            print("VISA")
        else:
            print("INVALID")

number = getNumber()
printCredit(number, ifValid(number))
