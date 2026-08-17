import sys

menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

price = 0
while True:
    try:
        item = input("Enter your food: ")
        if item.title() in menu.keys():
            price += menu[item.title()]
            print(f"${price:.2f}")
        else:
            print("Item: {item} is not in menu. Please try again.")
    except EOFError:
        print(f"\n${price:.2f}")
        sys.exit(0)


