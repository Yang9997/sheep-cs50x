## Python 类设计常见错误总结

### 原版代码（有问题）

```python
class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            return ValueError
        self.capacity = capacity
        self.size = 0
        return self

    def __str__(self):
        return "🍪" * self.capacity

    def deposit(self, n):
        if self.size + n > self.capacity:
            return ValueError
        self.size += n

    def withdraw(self, n):
        if self.size - n < 0:
            return ValueError
        self.size -= n

    @property
    def capacity(self):
        return self.capacity

    @property
    def size(self):
        return self.size
```

---

### 错误与解释

| 错误点 | 原版写法 | 原因 | 修正方法 |
|--------|----------|------|----------|
| 属性递归 | `@property def capacity(self): return self.capacity` | 属性名与内部变量同名，调用自身导致无限递归 | 用 `_capacity` 存储，属性返回它 |
| 构造函数返回非 None | `return ValueError` 和 `return self` | `__init__` 应返回 `None`，不应返回其他值 | 移除所有 `return`，用 `raise ValueError` 抛出异常 |
| 错误处理方式错误 | `return ValueError` | `return` 只返回异常类，不会终止程序 | 改用 `raise ValueError("message")` |
| `__str__` 逻辑错误 | 使用 `self.capacity` 生成字符串 | 应显示当前 `size` 个饼干，而非容量 | 改用 `self._size` |
| 缺少参数合法性检查 | 未检查 `n >= 0` | `deposit` 和 `withdraw` 可能传入负数 | 添加 `if n < 0: raise ValueError` |

---

### 无限递归详解

#### 问题代码

```python
@property
def capacity(self):
    return self.capacity   # 错误：这里导致无限递归
```

#### 为什么会无限递归？

当你访问 `jar.capacity` 时，Python 会调用 `capacity` 方法。在该方法内部，你写了 `return self.capacity`。

但是，`capacity` 已经被 `@property` 装饰器重新定义为一个方法，而不是一个普通的实例变量。所以 `self.capacity` 实际上又是调用 `capacity` 方法本身，而不是返回一个存储的值。

于是形成一个循环：
1. 调用 `jar.capacity`
2. 进入 `capacity` 方法
3. 方法内执行 `return self.capacity`，再次触发 `capacity` 方法
4. 回到第 2 步，无限循环

最终 Python 会抛出 `RecursionError: maximum recursion depth exceeded`。

#### 核心原因

属性（`@property`）会覆盖同名的实例变量。一旦定义了 `capacity` 作为属性，那么 `self.capacity` 就不再指向一个普通变量，而是指向属性方法本身。

因此，**属性名和内部存储名必须不同**，否则方法会调用自身。

---

### 修正后代码

```python
class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Capacity must be non-negative")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        if n < 0:
            raise ValueError("Deposit amount must be non-negative")
        if self._size + n > self._capacity:
            raise ValueError("Exceeds capacity")
        self._size += n

    def withdraw(self, n):
        if n < 0:
            raise ValueError("Withdraw amount must be non-negative")
        if self._size - n < 0:
            raise ValueError("Insufficient cookies")
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size
```

---

### 关键原则总结

1. `@property` 方法不能与实例变量同名，否则会无限递归
2. 内部存储变量建议加下划线前缀（如 `_capacity`、`_size`）
3. `__init__` 不应有 `return` 语句
4. 错误应通过 `raise` 抛出异常，而不是 `return`
5. 方法参数应检查合法性（如 `n >= 0`）
6. `__str__` 应返回当前状态的表示，通常基于 `size` 而非 `capacity`

---

### 测试代码

```python
def main():
    jar = Jar(9)
    print(jar.capacity)     # 9
    print(jar)              # 空（size=0）
    jar.deposit(2)
    print(jar)              # 🍪🍪
    print(jar.size)         # 2
    jar.withdraw(1)
    print(jar)              # 🍪
    print(jar.size)         # 1

if __name__ == "__main__":
    main()
```
