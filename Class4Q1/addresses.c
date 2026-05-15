#include<cs50.h>
#include<stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n",s);
    printf("%p\n",&s[0]);
    printf("%p\n",&s[1]);
    printf("%p\n",&s[2]);
    printf("%p\n",&s[3]);

    char* s0 = "HI!";
    printf("%p\n",s);
    printf("%p\n",&s0[0]);
    printf("%p\n",&s0[1]);
    printf("%p\n",&s0[2]);
    printf("%p\n",&s0[3]);

    char* s1 = "HELLO!";
    printf("%s\n",s1);

    char* s2 = "HELLO";
    printf("%c\n",s2[0]);
    printf("%c\n",s2[1]);
    printf("%c\n",s2[2]);

    char* s3 = "HELLO";
    printf("%c\n",*s3);
    printf("%c\n",*(s3 + 1));
    printf("%c\n",*(s3 + 1));

    // 安全起见不要这样做
    // printf("%c\n",*(s3 + 50));
    return 0;
}
