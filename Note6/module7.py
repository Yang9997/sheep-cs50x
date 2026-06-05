# 字典操作
# 字典：键值对。键必须是不可变类型（如字符串、数字、元组），值可以是任意类型。
d = {
    "a": 1,
    "b": 2
}

# 遍历键
for key in d:
    print(key, d[key])

# 遍历键值对（好的）
for key, value in d.items():
    print(key, value)

# 安全访问
print(d.get("c", 0)) # 如果"c"不存在，返回0
print(d.get("a", 0))

# 更新
d["c"] = 3 # 添加或更新
# 批量添加或更新
d.update({
    "d": 4,
    "e": 5
          })
