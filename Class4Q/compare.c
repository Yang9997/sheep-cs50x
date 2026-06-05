#include<cs50.h>
#include<stdio.h>

int main(void)
{
    // 在尝试比较字符串时使用==操作符会试图比较字符串的内存位置，
    // 而不是字符本身。
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (s == t)
    {
        printf("Same.\n");
    }
    else
    {
        printf("Different.\n");
    }

    printf("%s\n",s);
    printf("%s\n",t);

    printf("%p\n",s);
    printf("%p\n",t);
}
