import sys
from pyfiglet import Figlet
import random


if len(sys.argv) == 2:
    print("Invalid usage")
    sys.exit(1)
elif len(sys.argv) == 3:
    if sys.argv[1] == "-f" or sys.argv[1] == "--font":
        figlet = Figlet()
        seq = figlet.getFonts()
        f = sys.argv[2]
        if sys.argv[2] in seq:
            s = input("input a string: ")
            figlet.setFont(font=f)
            print(figlet.renderText(s))
        else:
            print("Invalid usage")
            sys.exit(1)
    else:
        print("Invalid usage")
        sys.exit(1)
elif len(sys.argv) == 1:
    s = input("input a string: ")
    figlet = Figlet()
    seq = figlet.getFonts()
    f = random.choice(seq)
    figlet.setFont(font=f)
    print(figlet.renderText(s))
else:
    print("Invalid usage")
    sys.exit(1)

