#include<stdio.h>
int main(void)
{
    char *s;
    printf("s: ");
    // error 没规定字符串大小，没动态或静态划分内存
    scanf("%s", s);
    printf("s: %s\n", s);

    return 0;
}
