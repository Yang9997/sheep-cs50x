#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main(void)
{
    // 获取两个字符串
    // 这样创建的字符串就是会被系统自动安排在两个不同的空内存里面
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%s\n",s);
    printf("%s\n",t);

    printf("%p\n",s);
    printf("%p\n",t);

    // 比较两个字符串地址
    if (s == t)
    {
        printf("Same.\n");
    }
    else
    {
        printf("Different.\n");
    }
    // 比较两个字符串
    if (!strcmp(s,t))
    {
        printf("Same.\n");
    }
    else
    {
        printf("Different.\n");
    }


}
