# TODO
from cs50 import get_string

context = get_string("Text: ")
words = 1
sentences = 0
alphas = 0

for c in context:
    if c == '.' or c == '!' or c == '?':
        sentences += 1
    elif c == ' ':
        words += 1
    elif c.isalpha():
        alphas += 1

L = alphas / words * 100
S = sentences / words * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
