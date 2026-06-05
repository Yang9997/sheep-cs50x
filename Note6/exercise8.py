# 文件读写

with open("input.txt", "r") as f:
    text = f.read()

lines = text.count("\n")
words = len(text.split())
chars = len(text)

print(f"lines: {lines}")
print(f"words: {words}")
print(f"chars: {chars}")
