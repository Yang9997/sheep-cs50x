#include<stdio.h>
int main(void)
{
    // error!没有为字符串分配足够的内存空间
    // char *s;
    char s[4]; // 在栈上分配4个字节的数组名字。s是数组名，是不可修改的左值，即不能s = "yes"
    printf("s: ");
    scanf("%s",s);
    printf("s: %s\n",s);

    return 0;
}
