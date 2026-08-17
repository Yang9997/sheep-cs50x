import sys
from pyfiglet import Figlet
from random import choice

if len(sys.argv) != 3 and len(sys.argv) != 1:
    print("Please enter 0 or 2 parameters.")
    # 只是个方法，要有括号的，异常退出是非0
    sys.exit(-1)

figlet = Figlet()
fonts = figlet.getFonts()

if len(sys.argv) == 3 and (sys.argv[1] != "-f" and sys.argv[1] != "--font" or sys.argv[2] not in fonts):
    print("Error.")
    sys.exit(-1)

str = input("Please enter a sentence: ")
if len(sys.argv) == 1:
    figlet.setFont(font=choice(fonts))
    print(figlet.renderText(str))
elif len(sys.argv) == 3:
    figlet.setFont(font=sys.argv[2])
    print(figlet.renderText(str))




