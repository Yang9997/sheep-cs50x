# 字典里面的单词
words = set()
def check(word):
    if word.lower() in words:
        return True
    else:
        return false

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


