# 查询数据库中问题的受欢迎程度

import csv

from cs50 import SQL

# 打开数据库
db = SQL("sqlite:///favorites.db")

# 提示用户输入他们最喜欢的问题
favorite = input("Favorite: ")

# 搜索标题
rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")

# 获取结果的第一行（也是唯一的一行）
row = rows[0]

# 打印查询结果
print(row["COUNT(*)"])
