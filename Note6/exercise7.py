str = input("Enter: ")

d = {}
for c in str:
    if c in d:
        d[c] += 1
    else:
        d[c] = 1

for key in sorted(d):
    print(f"{key}: {d[key]}")

