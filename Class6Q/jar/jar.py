class Jar:
    def __init__(self, capacity=12):
        # 数据类型的判定 isinstance
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity should be an int over zero.")
        # 被property标记过的属性（方法？都差不多）self时要加_
        # 通常用下划线表示内部使用的变量
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        if n + self._size > self._capacity:
            raise ValueError("Over capacity.")
        else:
            self._size += n

    def withdraw(self, n):
        if self._size < n:
            raise ValueError("Fewer than zero.")
        else:
            self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

jar = Jar()
print(str(jar.capacity))
print(str(jar))
jar.deposit(2)
print(str(jar))
jar.withdraw(1)
print(str(jar))
# jar.withdraw(12)
jar.deposit(15)

