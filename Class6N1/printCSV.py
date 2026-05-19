import csv

name = input("name: ")

# 追加模式打开文件，追加模式是不会覆盖原有内容，没有这个文件会自动创建。with保证结束后自动关闭文件
with open("phonebook.csv", "a") as file:
    # csv.writer是一个csv写入器，接受要写入内容的文件作参数
    # 写入器这个操作只需要调用一次，紧跟在with句就可以
    writer = csv.writer(file)
    while name != "exit":
        number = input("number: ")
        writer.writerow([name, number])
        name = input("name: ")
