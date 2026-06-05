input = input("Enter a list: ")
lst = input.split()
number = 0
sum = 0
for c in lst:
    if c.isdigit():
        number += 1
        sum += int(c)
# python3 默认浮点除法
average = sum / number
print(f"{average:.1f}")
