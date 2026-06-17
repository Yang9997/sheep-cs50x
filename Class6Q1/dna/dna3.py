# dictionary
person = {
    "name": "Alice",
    "age": 20
}

print(person["name"])
print(person["age"])

person["age"] = 21
person["school"] = "PKU"
print(person)

for key, value in person.items():
    print(key, value)
