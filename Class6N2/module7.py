d = {
    "a": 1,
    "b" : 2
    }

# 遍历键
for key in d:
    print(key, d[key])

print()
# 遍历键值对
for key, value in d.items():
    print(key, value)

# 获取键对应的值
d.get("c", 0) # 如果不存在，返回0

# 添加或更新
d["c"] = 3
# 批量添加或更新
d.update({"d": 4})

print()
for key, value in d.items():
    print(key, value)
