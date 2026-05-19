**【Home Federal Savings Bank - CS50x 2023】**

在辛菲尔德的第7季第24集中，克莱默拜访了一家银行，该银行承诺向任何没有被“hello”问候的人提供 100 美元。克莱默被招呼了一声“hey”，但他认为这不算“hello”，因此要求获得100美元的赔偿。银行经理提出折中方案：“既然你的招呼语是以'h'开头的，给你20美元怎么样？” 克莱默接受了。

在一个名为 `bank.py` 的文件中，实现一个程序，提示用户输入问候语。如果问候语以“hello”开头，则输出 `$0`。如果问候语以“h”开头（但不是“hello”），则输出 `$20`。否则，输出 `$100`。忽略用户问候语中的任何前导空格，并且不区分大小写地处理用户的问候语。

**小贴士**

- 别忘了，`str` 类型有很多内置方法，可以参考 docs.python.org/3/library/stdtypes.html#string-methods。
- 请确保对于“hello”、“hello there”、“hello, Newman”等以“hello”开头的问候语，都输出 `$0`。

**演示**

（本练习没有给出演示的截图，按照题目要求实现即可）

**开始之前**

- 使用您的 GitHub 帐户登录 cs50.dev。
- 在终端窗口中点击，然后执行 `cd` 命令。
- 执行以下命令下载 zip 文件：

    ```bash
    wget https://cdn.cs50.net/2022/fall/labs/6/bank.zip
    ```

- 现在执行 `unzip bank.zip` 以创建一个名为 `bank` 的文件夹。
- 删除 ZIP 文件可以执行 `rm bank.zip` 命令，然后根据提示输入 `y` 并回车。

**如何测试**

以下是手动测试代码的方法：

- 使用 `python bank.py` 运行您的程序。键入 `Hello` 并按 Enter 键。您的程序应输出：
    ```
    $0
    ```
- 使用 `python bank.py` 运行您的程序。键入 `Hello, Newman` 并按 Enter 键。您的程序应输出：
    ```
    $0
    ```
- 使用 `python bank.py` 运行您的程序。键入 `How you doing?` 并按 Enter 键。您的程序应输出：
    ```
    $20
    ```
- 使用 `python bank.py` 运行您的程序。键入 `What's happening?` 并按 Enter 键。您的程序应输出：
    ```
    $100
    ```

您可以执行以下命令，使用 `check50` 检查您的代码：

```bash
check50 cs50/problems/2022/python/bank
```

**如何提交**

无需提交，这只是一个练习。


