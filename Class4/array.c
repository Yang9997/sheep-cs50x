#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    // 向编译器请求一块内存时，不能保证该内存是空的。
    int scores[1024];

    // 这里面可能会有值非0
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }

    return 0;
}
