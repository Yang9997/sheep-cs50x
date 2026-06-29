class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            # 抛出异常的语法是raise不是return
            raise ValueError("capacity must be non-negative")
        # 使用私有变量
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        s = "🍪" * self._size
        return s

    def deposit(self, n):
        if n < 0 or (self._size + n) > self._capacity:
            raise ValueError("over the capacity.")
        self._size += n

    def withdraw(self, n):
        if n < 0 or (self.size - n) < 0:
            raise ValueError("smaller than 0.")
        self._size -= n

    @property
    def capacity(self):
        # 使用私有变量,否则导致无限递归
        return self._capacity

    @property
    def size(self):
        # 使用私有变量
        return self._size

def main():
    # test: __init__
    jar = Jar(9)
    print(str(jar.capacity))
    # test: __str__
    print(str(jar))
    # test: deposit()
    jar.deposit(2)
    print(str(jar))
    print(str(jar.size))
    # test: withdraw()
    jar.withdraw(1)
    print(str(jar))
    print(str(jar.size))

main()
