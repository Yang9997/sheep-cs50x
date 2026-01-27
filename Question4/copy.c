#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    string s= get_string("s: ");

    // 指针，指向一块内存
    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("s: %p\n", s);
    printf("t: %p\n", t);

    return 0;
}
