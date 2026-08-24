# 我重新做了一遍 2026 0824 星期一
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

# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    previous_cases = {}
    new_cases = {}

    for row in reader:
        if row["state"] not in previous_cases:
            previous_cases[row["state"]] = int(row["cases"])
            new_cases[row["state"]] = []

        cases = int(row["cases"]) - previous_cases[row["state"]]
        previous_cases[row["state"]] = int(row["cases"])
        new_cases[row["state"]].append(cases)
        if len(new_cases[row["state"]]) > 14:
            new_cases[row["state"]].pop(0)

    # for state in new_cases:
    #     print(f"{state}: {new_cases[state]}")
    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        if state in new_cases:
            lst0 = new_cases[state][:7]
            lst1 = new_cases[state][7:]
            avg0 = sum(lst0) / 7
            avg1 = sum(lst1) / 7

            try:
                avg = (avg1 - avg0) / avg0
                avg *= 100
                if avg > 0:
                    print(f"{state} had a 7-day average of {avg1:.0f} and an increase of {avg:.0f}%.")
                elif avg < 0:
                    avg = -avg
                    print(f"{state} had a 7-day average of {avg1:.0f} and a decrease of {avg:.0f}%.")
                else:
                    print(f"{state} had a 7-day average of {avg1:.0f} and no change.")
            except ZeroDivisionError:
                print(f"{state} had a 7-day average of {avg1:.0f} and there is no record for the past seven days.")

main()
