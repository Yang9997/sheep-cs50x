import csv
import sys


def main():

    # TODO: Check for command-line usage
    # 检查命令行参数个数
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
    # TODO: Read database file into a variable
    # 把数据库文件读入变量
    fname = sys.argv[1]
    try:
        fhand = open(fname)
    except:
        print("Cannot open the file name.")
        exit(1)
    dict_list = list()

    reader = csv.DictReader(fhand)   # 默认第一行为列名
    ### 没表头指定表头
    ### fieldnames = ['last', 'first', 'number']  # 自定义列名
    ### reader = csv.DictReader(f, fieldnames=fieldnames)
    # 每行是一个字典
    for row in reader:
        dict_list.append(row)
    # print(dict_list)
    fhand.close()

    # TODO: Read DNA sequence file into a variable
    fname1 = sys.argv[2]
    try:
        fhand1 = open(fname1)
    except:
        print("Cannot open the file name.")
        exit(1)
    for line in fhand1:
            s = line.strip()
            # print(s)
            break
    fhand1.close()

    # TODO: Find longest match of each STR in DNA sequence
    l = list()
    count = 0
    # print(dict_list[0].keys())
    for key in dict_list[0].keys():
            if count == 0:
                count += 1
                l.append(-1)
                continue
            else:
                # print(s, key)
                number = longest_match(s, key)
                l.append(number)
    # print(l)
    # TODO: Check database for matching profiles
    # 匹配每行除了第一个元组外的value
    name = "No match"
    for i in range(len(dict_list)):
        dict = dict_list[i]
        # print(dict)
        flag = True
        count = 0
        for value in dict.values():
            if count == 0:
                count += 1
                continue
            else:
                # print(count)
                # print(value,l[count])
                if int(value) != l[count]:
                    flag = False
                    break
                count += 1
        if flag:
            name = dict_list[i]["name"]
            break
    print(name)

    return


# 长度匹配，计算个数？
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
