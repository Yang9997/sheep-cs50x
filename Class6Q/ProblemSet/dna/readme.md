## DNA 问题笔记 (CS50 2023/x/dna)

### 1. 读取数据库时，如何正确将数据存入列表？
**Q:** 为什么用 `dnalist += dnadict` 会导致后续 `item["AGATC"]` 报错？
**A:** `dnalist += dnadict` 等价于 `dnalist.extend(dnadict)`，会将字典的**键**（人名）添加到列表，而不是字典本身。应改用 `dnalist.append(row)`，直接添加每行字典。

### 2. STR 列的值在比较时为什么总不相等？
**Q:** `item["AGATC"] == length1` 明明数值一样却返回 False？
**A:** CSV 读取的 STR 值是**字符串**（如 `"4"`），而 `longest_match` 返回**整数**。需在读入时转换：`row[key] = int(row[key])`。

### 3. 如何动态获取 CSV 中的所有 STR 列名？
**Q:** 不想硬编码 `["AGATC","AATG","TATC"]`，怎么写？
**A:** 使用列表推导式：
```python
str_list = [key for key in reader.fieldnames if key != "name"]
```
该语句从 CSV 表头中过滤掉 `"name"`，得到所有 STR 列名。

### 4. `longest_match` 函数需要修改吗？
**Q:** 官方提供的 `longest_match` 在部分测试中导致错误匹配（如 sequences/18.txt 误输出 Harry）？
**A:** 可以不改，但推荐使用更稳健的版本（避免重叠匹配问题）。如果通过 19/20 个测试，仅 18.txt 失败，很可能是 STR 列表不完整或比较时遗漏了列，而非 `longest_match` 本身错误。

### 5. 为什么 sequences/18.txt 会错误地匹配到 Harry？
**Q:** `check50` 显示期望 `No match`，实际输出 `Harry`？
**A:** 常见原因：
- 数据库读入时未转换 STR 为整数，导致字符串与整数比较永远不等，但 Harry 的 STR 值恰好等于整数？不，这会导致不匹配。实际是 STR 列不全：可能你只处理了部分 STR（如只用了前3个），而 Harry 在这些列上恰好与序列值相同，但被忽略的其他 STR 列其实不匹配。
- 或 `longest_match` 计算了错误的连续重复次数（重叠计数）。建议动态读取所有 STR 列，并全部比较。

### 6. 完整的匹配逻辑模板？
**Q:** 如何正确匹配 DNA 数据库？
**A:**
```python
# 读取数据库并转换 STR 为整数
with open(csvfile) as f:
    reader = csv.DictReader(f)
    str_list = [k for k in reader.fieldnames if k != "name"]
    database = []
    for row in reader:
        for key in str_list:
            row[key] = int(row[key])
        database.append(row)

# 计算序列中各 STR 最长连续次数
counts = [longest_match(sequence, s) for s in str_list]

# 匹配
for person in database:
    if all(person[s] == counts[i] for i, s in enumerate(str_list)):
        print(person["name"])
        return
print("No match")
```
