# TODO

def get_cash():
    while True:
        try:
            cash = float(input("Change owed: "))
            if cash > 0:
                return cash
            else:
                print("Positive.")
        except ValueError:
            print("Number.")


cash = get_cash()
cash = int(cash * 100)
n25 = cash // 25
cash = cash % 25
n10 = cash // 10
cash = cash % 10
n5 = cash // 5
n1 = cash % 5
n = n25 + n10 + n5 + n1
print(n)
