from cs50 import get_string

peaple = {
    "Carter": "123-344-5678",
    "David": "234-127-8945"
}

name = get_string("Enter your name: ")
if name in peaple:
    print(f"Number: {peaple[name]}")


