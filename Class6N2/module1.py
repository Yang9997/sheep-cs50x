age = input("How old are you?")
age = int(input("How old are you?"))
print(float("24.1241"))  # 24.1241
print(str(42))   # 42
print(int("25"))  # 25
print(int(3.99))  # 3 截断

try:
    n = int(input("enter a number:"))
    print(n)
except ValueError:
    print("It is not a int.")
