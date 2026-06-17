s = input("Text: ")
upper = lower = digit = other = 0

for c in s:
    if c.isupper():
        upper += 1
    elif c.islower():
        lower += 1
    elif c.isdigit():
        digit += 1
    else:
        other += 1

print(f"upper = {upper}, lower = {lower}, digit = {digit}, other = {other}")
