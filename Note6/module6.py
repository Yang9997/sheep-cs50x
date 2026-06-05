# 列表相关操作
# 列表：对标数组，但是里面元素可以是任何类型
lst = []

lst.append(1)  # 添加元素
print(lst)
lst.insert(0, 2) # 指定索引插入元素
print(lst)
lst.remove(2) # 删除第一个匹配值的元素
print(lst)
del lst[0]   # 删除指定位置元素
print(lst)
lst.append(3)
lst.append(4)
print(lst)
lst.pop()  # 删除并返回最后一个元素
print(lst)
lst.pop(0) # 删除并返回索引位置的元素
print(lst)
print()

lst = [1, 6, 3, 87, 93, 4, 7]
print(len(lst))
print(max(lst))
print(min(lst))
print(sum(lst))
print()

# sorted(lst) 返回排序列表，原列表不变
for i in sorted(lst):
    print(i)
print()
for i in lst:
    print(i)
print()

lst = [6,2,8,4,9,10,1]
# 列表内元素排序
lst.sort()
for i in lst:
    print(i)
print()

lst = [6,2,8,4,9,10,1]
# 表内元素反转
lst.reverse()
for i in lst:
    print(i)




