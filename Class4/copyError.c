#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    string s = get_string("s: ");
    // 复制地址而非复制字符串
    // 同处地址，通过地址操作改变变量会令看似两个的字符串一起改变
    string t = s;
    // 将字符串第一个大写字母大写
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    return 0;
}
