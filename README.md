# Harvard CS50x 2022

- [Course Link](https://cs50.harvard.edu/x/)
- [Problem Set 8](https://github.com/csfive/CS50x-pset8)
- [中文站点](https://www.learncs.site/docs/curriculum-resource/cs50x)

代码和题目是按22年的pull的。

题目是按23年的答案验证的。

## 文件结构
```bash
# 单层目录结构
tree -L 1
```

# 1. 环境配置
[CS50 Library for C — CS50 Docs](https://cs50.readthedocs.io/libraries/cs50/c/)
## 库安装
Ubuntu(wsl同)：
```bash
curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
sudo apt install libcs50
```
若有报错：
```bash
# 1. 首先备份并删除有问题的文件
sudo mv /etc/apt/sources.list.d/nvidia-container-toolkit.list /etc/apt/sources.list.d/nvidia-container-toolkit.list.bak
# 2. 清理APT缓存并更新
sudo apt-get clean
sudo apt-get update
# 3. 重新安装libcs50
sudo apt install libcs50
```
## 环境变量设置
```bash
vim ~/.bashrc

# 末尾添加内容
export CC="clang"
export CFLAGS="-ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow"
export LDLIBS="-lcrypt -lcs50 -lm"
# 保存退出

# 使配置立即生效
source ~/.bashrc

# 需要下载clang就正常下载
sudo apt update
sudo apt install clang
```
测试：
```bash
# 检查是否设置正确
echo $CC
echo $CFLAGS
echo $LDLIBS
```
测试成功：
```bash
clang
-ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow
-lcrypt -lcs50 -lm
```
编译代码成功：
```bash
# vscode启动启动启动全部启动
code .
# 进入到Week1的文件夹
cd Week1
# 运行1-hello.c
clang 1-hello.c -o 1-hello -lcs50
# 运行
./1-hello
# 运行成功就说明库安装没问题
```
## 容器环境配置
1. 下载CS50的最新版本`.devcontainer.json`文件来自[https://cs50.dev/.devcontainer.json](https://cs50.dev/.devcontainer.json)，将其保存在cs50代码项目文件夹。由于文件名以点（即句点）开头，因此当您下载该文件时，它可能看起来“消失”了。但是，在 Linux 或 macOS 上的终端窗口中，您应该看到它`ls -a`，并且在 Windows 的命令提示符下，您应该会看到它。
2. 主机启动docker `sudo systemctl start docker`。
3. 安装 VS Code 的[Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)扩展。
4. 打开 VS Code 的[命令面板](https://code.visualstudio.com/docs/getstarted/userinterface#_command-palette)，如在 Linux 上通过**Ctrl+Shift+P** ，选择`>Dev Containers - Open Folder in Container...`，项目文件夹就会在容器内打开。
## 虚拟环境配置
发现在docker内的环境里面用不了check50之类的包，所以在wsl环境里面再开一个python下的虚拟环境
```bash
# 创建
python3 -m venv cs50venv
# 激活
source cs50venv/bin/activate
# 下载包
pip install check50
check50 --help
check50 cs50/problems/2023/x/readability
# 这里首次会需要github授权，https://submit.cs50.io
# 再回来check50，有时候网络连接不稳定Version check failed导致connect失败就多check几次
pip install submit50
submit50 --help
submit50 cs50/problems/2023/x/readability
```
有关check50：[check50 — check50 Docs](https://cs50.readthedocs.io/projects/check50/en/latest/)

其他的50包的下载使用也很类似


# 2. 环境功能
## make
```bash
# 容器内
make my_program
```
## run
```bash
# 容器内
./my_program arg1 arg2
```
## debug
```bash
# 容器内
# make过之后
debug50 ./my_program arg1 arg2
```
## check
```bash
# python虚拟环境内
# 使用check50检查代码
check50 cs50/problems/2023/x/filter/less
```

# 3. 笔记索引

## Class3Q：
1. 关于c语言的string和strlen：Class3Q/PracticeProblem/atoi/readme.md
2. runoff 候选人投票题目代码数组赋值逻辑错误：Class3Q/ProblemSet/runoff/readme.md
3. tideman 候选人投票题目递归代码逻辑：Class3Q/ProblemSet/tideman/readme.md
4. 插入排序：Class3Q/ProblemSet/temps/insertsort.c
5. 选择排序，冒泡排序，归并排序：Class3Q/Lab/sorts/

## Question4:
1. 关于变量类型存储范围超出会溢出截断，比如BYTE类型变量范围是0-255
2. 注意中间值临时变量的使用会不会影响未来要使用的变量，尤其是数组类型要在原数值上整体做改变的时候，注意要完全变化之后再一起用中间值过渡来修改值

## Question7:
1. Class7里面有一些sql代码语法说明
2. songs: 3.sql里面有关于升序降序排序的单词说明

# 附录：git相关

## .gitignore
```bash
# git的忽略模式语法不支持 ./ 前缀
# 在.gitignore文件里面
# error 无效
# ./readme.md
# 有效
/readme.md
```
```bash
# 对于已提交跟踪过的文件没办法通过添加后生效，需要手动删掉
# 检测是否已跟踪
# 列出所有被跟踪且文件名包含filename的路径。
git ls-files | grep "filename"
# 如果输出显示，已经被跟踪了的话
# 以.vscode为例
# 1. 从 Git 的跟踪中移除 .vscode（但保留工作区的实际文件夹）
git rm -r --cached .vscode
# 2. 提交这个移除操作
git commit -m "Remove .vscode from tracking"
# 3. 提交
git push origin main
```








