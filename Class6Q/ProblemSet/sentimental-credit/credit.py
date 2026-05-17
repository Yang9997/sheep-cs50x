# TODO
"""
对于Visa卡，它只需校验13位或16位长度即可。
校验时，除了长度，最关键的是看它是否以数字4开头，
以及能否通过Luhn算法的检验

万事达卡(MasterCard)：长度为16位，一般以51、52、53、54、55开头。

美国运通卡(American Express)：长度为15位，一般以34、37开头。

银联卡(China UnionPay)：长度为16位，一般以62开头。
"""
def main():
    credit = get_credit()
    if isCredit(credit):
        if isAmex(credit):
            print("AMEX")
        if isMastercard(credit):
            print("MASTERCARD")
        if isVisa(credit):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

def get_credit():
    while True:
        number = input("Number: ")
        try:
            int(number)
            number = int(number)
            return number
        except ValueError:
            continue

def isCredit(credit):
    sum = 0
    number2 = 0
    number1 = 0
    number = 0
    tmp = credit
    while tmp:
        # 取末尾两位
        number2 = tmp % 100
        # 取末尾两位的十位处的数字
        number2 = int(number2 / 10)
        # 取末尾一位
        number1 = tmp % 10
        sum += number1
        number2 *= 2
        if number2 > 9:
            number2 = number2 % 10 + int(number2 / 10)
        sum += number2
        tmp = int(tmp / 100)

    if sum % 10 == 0:
        return True
    else:
        return False

def isAmex(credit):
    while int(credit / 100):
        credit = int(credit / 10)
        # print(credit)
    if credit == 34 or credit == 37:
        return True
    else:
        return False

def isMastercard(credit):
    while int(credit / 100):
        credit = int(credit / 10)
    if credit == 51 or credit == 52 or credit == 53 or credit == 54 or credit == 55:
        return True
    else:
        return False

def isVisa(credit):
    count = 0
    while int(credit / 10):
        credit = int(credit / 10)
        count += 1
        # print(credit)
    if credit == 4 and (count + 1 in (13, 16)):
        return True
    else:
        return False


main()

















