from string import digits
from itertools import product

# 0123456789
print(digits)
# <class 'str'>
print(type(digits))

for passcode in product(digits, repeat=4):
    # 元组解包
    print(*passcode)


