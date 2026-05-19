import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    txtfile = sys.argv[2]
    with open(txtfile, "r", encoding = "utf-8") as file:
        variable = file.read()

    # TODO: Read DNA sequence file into a variable
    csvfile = sys.argv[1]
    # newline=""：Python 不再自动转换换行符，让 csv 模块自己处理边界，从而防止多余空行数据错位。
    with open(csvfile, "r", newline="", encoding = "utf-8") as file:
        reader = csv.DictReader(file)
        # STR大小数据库列项数量不一样
        # 但行等价于：
        # str_list = []
        # for key in reader.fieldnames:
        #     if key != "name":
        #         str_list.append(key)
        str_list = [key for key in reader.fieldnames if key != "name"]
        database = []
        for row in reader:
            for key in str_list:
                if key != "name":
                    row[key] = int(row[key])
            # list添加一条一条的dict项
            database.append(row)

    # TODO: Find longest match of each STR in DNA sequence
    counts = [longest_match(variable, s) for s in str_list]

    # TODO: Check database for matching profiles
    tag = 0
    for item in database:
        if all(item[s] == counts[i] for i, s in enumerate(str_list)):
            print(item["name"])
            tag = 1
            break
    if tag == 0:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
