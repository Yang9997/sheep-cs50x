# TODO

text = input("Text: ")
words = 0
alphas = 0
sentences = 0

for c in text:
    if c == " ":
        words += 1
    if c in ("!", ".", "?"):
        sentences += 1
    if c.isalpha():
        alphas += 1

if words > 0:
    words += 1

L = alphas / words * 100
S = sentences / words * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade > 0 and grade < 17:
    print(f"Grade {grade}")
elif grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
    
