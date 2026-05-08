from cs50 import get_string

words = set()
def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    file.close()
    return True

def size():
    return len(words)

def unload():
    return True


load("/workspaces/CS50/test2.txt")
print("现在你可以输入单词，我帮你检查拼写。按住ctrl + c退出。")
while True:
    w = get_string("Please enter a word:")
    if check(w):
        print(f"{w} is right")
    else:
        print(f"{w} is wrong")
