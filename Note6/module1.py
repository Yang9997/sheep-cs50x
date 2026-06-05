# 类型转换

age = input("How old are you?")
# int() 里面的字符串只能是看着像整数的类型
age = int(input("How old are you?"))

print(float("2342.4523"))
print(str(42))
print(int("25"))
print(int(3.99))

try:
    n = int(input("input number:"))
except ValueError:
    print("Not Int.")

