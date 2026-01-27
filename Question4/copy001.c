#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string s = get_string("s: ");
    // 还是指向同一块内存
    string t = s;
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("%p\n", s);
    printf("%p\n", t);

    return 0;
}
