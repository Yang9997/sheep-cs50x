#include<stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n",n);
    // &n：取n的地址
    printf("%p\n",&n);

    // p是地址类型变量
    // *p是int类型变量
    // p = &n
    int *p = &n;
    printf("%p\n",p);
    // *p：p指向的变量
    printf("%i\n",*p);

    return 0;
}
