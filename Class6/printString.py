# get_string 和 print，使用连接

from cs50 import get_string

answer = get_string("What's your name? ")
print("hello, " + answer)
print(f"hello, {answer}")
