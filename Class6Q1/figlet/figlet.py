import sys
import random
from pyfiglet import Figlet

if len(sys.argv) != 1 and len(sys.argv) != 3:
    print("Erorr.")
    exit(1)
elif len(sys.argv) == 1:
    f = Figlet()
    fonts = f.getFonts()
    f = Figlet(font=random.choice(fonts))
    s = input("Enter your string: ")
    print(f.renderText(s))
else:
    if sys.argv[1] == "-f" or sys.argv[1] == "-font":
        f = Figlet()
        if sys.argv[2] in sys.argv[2]:
            f = Figlet(font=sys.argv[2])
            s = input("Enter your string: ")
            print(f.renderText(s))
        else:
            print("Erorr.")
            exit(1)
    else:
        print("Erorr.")
        exit(1)
