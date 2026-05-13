import sys

if len(argv) != 2:
    print("缺少命令行参数")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
