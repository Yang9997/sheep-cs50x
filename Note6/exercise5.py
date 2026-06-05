s = input("Text: ")

upper = 0
lower = 0
number = 0
other = 0
for c in s:
    if c.isupper():
        upper += 1
    elif c.islower():
        lower += 1
    elif c.isdigit():
        number += 1
    else:
        other += 1
print(f"upper = {upper}\nlower = {lower}\nnumber = {number}\nother = {other}")
