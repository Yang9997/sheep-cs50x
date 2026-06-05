number = input("Enter a number:")
number = int(float(number) * 100)

n25 = number // 25
number = number % 25
n10 = number // 10
number = number % 10
n5 = number // 5
n1 = number % 5

print(f"n1 = {n1}\nn5 = {n5}\nn10 = {n10}\nn25 = {n25}")

# amount = float(input("Change owed: "))
# cents = round(amount * 100)

# coins = 0
# for coin in [25, 10, 5, 1]:
#     coins += cents // coin
#     cents = cents % coin

# print(coins)
