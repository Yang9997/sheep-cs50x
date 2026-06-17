s = input("input: ")
dic = {}
for c in s:
    if c in dic:
        dic[c] += 1
    else:
        dic[c] = 1
for key in sorted(dic):
    print(f"{key}: {dic[key]}")
