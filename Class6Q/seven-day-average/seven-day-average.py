import csv
import requests


def main():
    # Read NYTimes Covid Database
    # download = requests.get(
    #     "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    # )
    # decoded_content = download.content.decode("utf-8")
    # file = decoded_content.splitlines()
    file = open("us-states.csv")
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)

    file.close()

def getAS(reader):
    for row in reader:
        if row["state"] == "American Samoa":
            print(row)

# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    previous_cases = {}   # 存储每个州上一次的累计病例数
    new_cases = {}        # 存储每个州的新增列表

    for row in reader:
        state = row["state"]
        cases = int(row["cases"])   # 当前累计病例

        # 如果该州第一次出现，无法计算新增，只记录累计值
        if state not in previous_cases:
            previous_cases[state] = cases
            new_cases[state] = []   # 初始化空列表
            continue

        # 计算当日新增
        daily_new = cases - previous_cases[state]
        previous_cases[state] = cases   # 更新累计值供下一次使用

        # 将新增值追加到该州的列表中
        new_cases[state].append(daily_new)

        # 保持列表长度不超过 14，超过则移除最早的数据
        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        if state not in new_cases:
            continue   # 如果该州没有数据，跳过

        cases = new_cases[state]   # 该州的新增病例列表（长度 ≤ 14）

        if len(cases) < 14:
            continue   # 数据不足 14 天，无法比较上周和本周

        # 本周 = 最后 7 天
        this_week = sum(cases[-7:]) / 7
        # 上周 = 前 7 天
        last_week = sum(cases[:7]) / 7

        # 计算变化百分比
        try:
            change = (this_week - last_week) / last_week * 100
        except ZeroDivisionError:
            change = 0   # 如果上周为 0，变化视为 0

        # 格式化输出
        avg = int(round(this_week))
        if change >= 0:
            print(f"{state} had a 7-day average of {avg} and an increase of {round(change)}%.")
        else:
            print(f"{state} had a 7-day average of {avg} and a decrease of {round(abs(change))}%.")

main()
