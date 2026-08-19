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
    previous_case = {}
    new_cases = {}

    for row in reader:
        state = row["state"]
        cases = int(row["cases"])

        if state not in previous_cases:
            previous_cases[state] = cases
            new_cases[state] = []
            continue

        daily_new = cases - previous_cases[state]
        previous_cases[state] = cases

        new_cases[state].append(daily_new)

        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

    return new_cases

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        if state not in new_cases:
            continue

        cases = new_cases[state]

        if len(cases) < 14:
            continue

        this_week = sum(cases[-7:]) / 7
        last_week = sum(cases[:7]) / 7

        try:
            change = (this_week - last_week) / last_week * 100
        except ZeroDivisionError:
            change = 0

        avg = int(round(this_week))
        if change >= 0:
            print(f"{state} had a 7-day average of {avg} and an increase of {round(change)}%.")
        else:
            print(f"{state} had a 7-day average of {avg} and an increase of {round(abs(change))}%.")

main()
