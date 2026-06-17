# 三种字符串遍历方法
s = "Hello"

for c in s:
    print(c)

print()

for i in range(len(s)):
    print(i, s[i])

print()

for i, c in enumerate(s):
    print(i, c)


