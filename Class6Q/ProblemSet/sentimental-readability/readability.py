# TODO
from cs50 import *
# for j in range(10):
text = input("Text: ")
# 字母
letters = 0
# 单词
words = 0
# 句子
sentences = 0
# rstrip()去掉末尾的空格，包括空格换行符制表符等，具体符号可以作为函数参数选择
for c in text.rstrip():
    # isalpha()判断是不是字母（各种语言的），isascii()判断是不是老式的ASCII字符（含英文字母、数字、符号等）。
    # 两者结合s.isascii() and s.isalpha()就是：纯英文字母（A-Z, a-z）。
    if c.isalpha() and c.isascii():
        letters += 1
    if c == " ":
        words += 1
    if c == "." or c == "?" or c == "!":
        sentences += 1

if words >= 1:
    words += 1

# print(f"letters: {letters}")
# print(f"word: {words}")
# print(f"sentences: {sentences}")

L = letters / words * 100
S = sentences / words * 100
# round(number, ndigits)
# number：要四舍五入的数字（整数或浮点数）。
# ndigits（可选）：保留的小数位数，默认为 0（即四舍五入到整数）。
# 返回值：与 number 类型相同（整数或浮点数）。
CL = int(round(0.0588 * L - 0.296 * S - 15.8))
if CL < 1:
    print("Before Grade 1")
elif CL > 16:
    print("Grade 16+")
else:
    print(f"Grade: {CL}")

