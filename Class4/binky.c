#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *x;
    x = malloc(sizeof(int));
    *x = 45;
    printf("*x: %i\n", *x);

    int *y;
    // error!指针不可以在没指向任何内存的时候赋值
    // *y = 13;
    // xy指向同一块内存
    y = x;
    printf("*y: %i\n", *y);
    *y = 13;
    printf("*x: %i\n", *x);
    printf("*y: %i\n", *y);
}
