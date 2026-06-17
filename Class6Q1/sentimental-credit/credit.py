# TODO
def getCredit():
    while(1):
        try:
            credit = input("Number: ")
            if credit.isdigit():
                return credit
        except ValueError:
            continue

def creditNumber(number):
    tmp = int(number)
    tmp1 = 0
    tmp2 = 0
    count = 0
    while(tmp > 0):
        tmp1 = tmp % 10
        tmp = tmp // 10
        tmp2 = tmp % 10 * 2
        if tmp2 > 9:
            tmp2 = tmp2 // 10 + tmp2 % 10
        count += tmp1 + tmp2
        tmp = tmp // 10
        # print(f"count = {count}")
    if count % 10 != 0:
        print("INVALID\n")
    else :
        if number.startswith(("34", "37")):
            print("AMEX\n")
        elif number.startswith(("51", "52", "53", "54", "55")):
            print("MASTERCARD\n")
        elif number.startswith("4") and int(number) > 1000000000000 :
            print("VISA\n")
        else:
            print("INVALID\n")

def main():
    number = getCredit()
    creditNumber(number)


main()
