# 字符串相关操作

print("hello".startswith("he"))  # 是否以开头 True
print("hello".endswith("lo"))    # 是否以结尾 True
print("   hello  \n\t".strip())  # 去掉首尾空格 hello
print("fhusahgfu".isalpha())     # 是否全字母 True
print("523fs".isalpha())         # False
print("3242345235".isdigit())    # 是否全数字 True
print("gdsgd".isdigit())         # False
print("fstg6575".isalnum())      # 是否全是数字和字母 True
print("twesdrf353..::".isalnum())# False
print("bagehjgujhbarhg".replace("b","a")) # 字符串替换
print("hello Hello Hello hello".count("hello")) # 字符串匹配个数
print("a b c\n c \n dad\n \tdaw".split()) # 空白拆分
print("fs, fgs'  ,fsff,f   , g".split(",")) # 指定字符串拆分
print("-".join(["f","3423 f","4234","tr"])) # 字符串连接
