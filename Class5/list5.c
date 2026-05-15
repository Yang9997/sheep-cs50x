#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // 安装第一个节点
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            node *ptr = list;
            while (ptr != NULL)
            {
                // 头插
                if (list->number > n->number)
                {
                    n->next = list;
                    list = n;
                }
                // 尾插
                else if (ptr->number < number && ptr->next == NULL)
                {
                    ptr->next = n;
                }
                // 中插
                else if (ptr->number < number && ptr->next->number > number)
                {
                    node *tmp = ptr->next;
                    ptr->next = n;
                    n->next = tmp;
                }

                ptr = ptr->next;
            }
        }
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n",ptr->number);
    }

    node *ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}
