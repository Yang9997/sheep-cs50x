#include<stdio.h>
#include<stdlib.h>
int main(void)
{

    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // realloc: 分配新内存，复制原内容，释放原内存
    // list依然指向原地址内存，但这块内存已被释放，所以是个悬置指针
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        // realloc失败，原内存没被释放
        free(list);
        return 1;
    }
    tmp[3] = 4;

    list = tmp;
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n",list[i]);
    }

    free(list);
    return 0;

}
