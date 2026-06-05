1. todo1：判断判断文件后缀是否符合要求的方法
```c
// 文件名后缀得是4个单位，小于4位不可能是.wav格式文件
if (strlen(argv[1]) < 4)
{
    printf("Input is not a WAV file.\n");
    return 1;
}
// 文件名后缀从倒数第四个字符地址开始算
char *suffix = argv[1] + strlen(argv[1]) - 4;
if (strcmp(suffix, ".wav") != 0)
{
    printf("Input is not a WAV file.\n");
    return 1;
}
```
2. todo4：fread，fwrite函数传递的第一个参数是指针/引用变量；c没有原生bool类型，if里面用int，非0是true，0是false
3. todo5：fopen权限w就包含r，不用wr都写
4. todo7：get_block_size函数算的是一块字节大小，不是块数。本题中不需要计算块数
5. todo8：buffer不要存完整的所有块数据，要每次存一块，数组大小就是block_size
