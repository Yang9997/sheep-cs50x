# list处理
nums = [3, 1, 4, 1, 5]
max(nums)

# 自定义规则
words = ["alpha", "banana", "kiwi"]
max(words, key = len) # 长度
max(words, key = lambda w: w.count"a") # 含a数量
