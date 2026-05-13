from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Please enter your score: ")
    scores.append(score)
    # 另一种写法
    # scores += [score]


average = sum(scores) / len(scores)
print(f"Average score is: {average}")
