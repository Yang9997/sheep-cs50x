# 文件读写

# 1. 逐行读
with open("file.txt", "r") as f:
    for line in f:
        line = line.strip()
        print(line)

# 2. 一次性全读
with open("file.txt", "r") as f:
    content = f.read() # 整个文件作为一个字符串
    lines = f.readlines() # 每行一个元素组成列表
    lines2 = f.read().splitlines()  # 去掉换行符

# 3. 写入
# "w": 覆盖
# "a": 追加
with open("file.txt", "w") as f:
    f.write("hello\n")
    f.write("world\n")

