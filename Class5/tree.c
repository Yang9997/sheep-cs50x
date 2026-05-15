#include<stdio.h>
#include<stdlib.h>
// 这里面有<stdbool.h>，有bool类型
#include<cs50.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}node;

void free_tree(node *root);
void print_tree(node *root);
bool search_tree(node *root, int number);

int main(void)
{
    // 初始化
    node *tree = NULL;

    // 安装第一个节点
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    // 插入节点
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    if (search_tree(tree, 3) == 0)
    {
        printf("yes.\n");
    }

    print_tree(tree);
    free_tree(tree);

    return 0;

}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        print_tree(root->left);
        printf("%i\n",root->number);
        print_tree(root->right);
    }
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        node *ptrLeft = root->left;
        node *ptrRight = root->right;
        free(root);
        free_tree(ptrLeft);
        free_tree(ptrRight);
    }
}

bool search_tree(node *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    else if (number < root->number)
    {
        search_tree(root->left, number);
    }
    else if (number > root->number)
    {
        search_tree(root->right, number);
    }
    else
    {
        return true;
    }

    // 骗编译器有个永远用不上的返回值
    return false;

}
