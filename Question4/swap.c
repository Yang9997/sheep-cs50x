#include<stdio.h>
void swap(int a, int b);
int main(void)
{
    int x = 2;
    int y = 3;
    printf("x is %i, y is %i.\n",x, y);
    swap(x,y);
    printf("x is %i, y is %i.\n",x, y);

    return 0;
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
