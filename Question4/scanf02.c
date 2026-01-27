#include<stdio.h>
int main(void)
{
    // right 划分了静态内存空间
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);

    return 0;
}
