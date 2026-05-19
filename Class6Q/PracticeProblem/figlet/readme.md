**【Frank, Ian 和 Glen 的字母 - CS50x 2023 项目】**

FIGlet，以 Frank, Ian 和 Glen 的字母 命名，是 20 世纪 90 年代初的一个程序，用于用普通文本制作大型字母，这是一种 ASCII 艺术 形式：

```
 _ _ _          _   _     _
| (_) | _____  | |_| |__ (_)___
| | | |/ / _ \ | __| '_ \| / __|
| | |   <  __/ | |_| | | | \__ \
|_|_|_|\_\___|  \__|_| |_|_|___/
```

FIGlet 支持的字体包括 figlet.org/examples.html 上的字体。

FIGlet 后来被移植到 Python 中，作为一个名为 pyfiglet 的模块。

在一个名为 `figlet.py` 的文件中，实现一个程序，该程序：

- 应接受零个或两个命令行参数：
    - 零个参数：表示使用随机字体。
    - 两个参数：第一个参数应为 `-f` 或 `--font`，第二个参数为字体名称。
- 提示用户输入文本（字符串类型）。
- 以所需的字体输出该文本。

如果用户提供两个命令行参数，并且第一个不是 `-f` 或 `--font`，或者第二个不是字体的名称，则程序应通过 `sys.exit` 退出并显示错误消息。

**提示**

- 您可以使用以下命令安装 pyfiglet：

    ```bash
    pip install pyfiglet
    ```

- pyfiglet 的文档不是很清楚，但您可以按如下方式使用该模块：

    ```python
    from pyfiglet import Figlet

    figlet = Figlet()
    ```

- 然后，您可以使用如下代码获取可用字体的列表：

    ```python
    figlet.getFonts()
    ```

- 您可以使用如下代码设置字体，其中 `f` 是字体名称（字符串类型）：

    ```python
    figlet.setFont(font=f)
    ```

- 您可以使用如下代码以该字体输出文本，其中 `s` 是要输出的文本（字符串类型）：

    ```python
    print(figlet.renderText(s))
    ```

- 请注意，`random` 模块附带了相当多的函数，请参阅 docs.python.org/3/library/random.html。

**演示**

本演示的首次输出使用了随机字体，你的输出结果可能不同。

**开始之前**

- 使用您的 GitHub 帐户登录 cs50.dev。
- 单击终端窗口内并执行 `cd`。
- 执行以下命令下载 ZIP 文件：

    ```bash
    wget https://cdn.cs50.net/2022/fall/labs/6/figlet.zip
    ```

- 现在执行 `unzip figlet.zip` 以创建一个名为 `figlet` 的文件夹。
- 删除 ZIP 文件：执行 `rm figlet.zip`，并在提示后输入 `y` 并回车确认。

**如何测试**

下面介绍如何手动测试你的代码的方法：

- 运行你的程序，使用命令 `python figlet.py test`。你的程序应该通过 `sys.exit` 退出并打印错误信息（例如：`Invalid usage`）。

- 运行你的程序，使用命令 `python figlet.py -a slant`。你的程序应该通过 `sys.exit` 退出，并显示错误信息（例如：`Invalid usage`）。

- 运行你的程序，使用命令 `python figlet.py -f invalid_font`。你的程序应该通过 `sys.exit` 退出，并显示错误信息（例如：`Invalid usage`）。

- 运行你的程序，使用命令 `python figlet.py -f slant`。输入 `CS50`。你的程序应该打印以下内容：

    ```
       ___________ __________
      / ____/ ___// ____/ __ \
     / /    \__ \/___ \/ / / /
    / /___ ___/ /___/ / /_/ /
    \____//____/_____/\____/
    ```

- 运行你的程序，使用命令 `python figlet.py -f rectangles`。输入 `Hello, world`。你的程序应该打印以下内容：

    ```
     _____     _ _                        _   _
    |  |  |___| | |___      _ _ _ ___ ___| |_| |
    |     | -_| | | . |_   | | | | . |  _| | . |
    |__|__|___|_|_|___| |  |_____|___|_| |_|___|
                      |_|
    ```

- 运行你的程序，使用命令 `python figlet.py -f alphabet`。输入 `Moo`。你的程序应该打印以下内容：

    ```
    M   M
    MM MM
    M M M ooo ooo
    M   M o o o o
    M   M ooo ooo
    ```

你可以执行以下命令，使用 `check50` 检查你的代码：

```bash
check50 cs50/problems/2022/python/figlet
```

**如何提交**

无需提交！这是一个练习题。

