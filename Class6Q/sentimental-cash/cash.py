# TODO

def getCash():
    while True:
        try:
            cash = float(input("Change owed: "))
            if cash < 0.01:
                print("Please enter the number over 0.01.")
                continue
            else:
                return cash
        except ValueError:
            print("Please enter a number.")

cash = getCash()
cash = int(cash * 100)
sum = 0
sum += cash // 25
cash = cash % 25
sum += cash // 10
cash = cash % 10
sum += cash // 5
cash = cash % 5
sum += cash
print(f"{sum}")
