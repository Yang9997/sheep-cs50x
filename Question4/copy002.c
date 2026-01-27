#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    // 空的吗？
    // 嗯，可能是vscode的处理，是空的
    printf("%s\n", t);

    // for (int i = 0; i <= strlen(s); i++)
    // 防止反复计算strlen(s)这个函数，n在for最左边定义之后就不会这样做了
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
