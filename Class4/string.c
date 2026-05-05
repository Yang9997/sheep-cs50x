#include<stdio.h>
#include<cs50.h>
int main(void)
{
    string s = "HI!";

    printf("%p\n",&s[0]);
    printf("%p\n",&s[1]);
    printf("%p\n",&s[2]);
    printf("%p\n",&s[3]);

    printf("%c\n",s[0]);
    printf("%c\n",s[1]);
    printf("%c\n",s[2]);
    printf("%c\n",s[3]);

    printf("%s\n",s);

    printf("\n//======\n\n");

    char *s1 = "HI!";

    printf("%c\n",s1[0]);
    printf("%c\n",s1[1]);
    printf("%c\n",s1[2]);
    printf("%c\n",s1[3]);

    printf("%c\n",*s1);
    printf("%c\n",*(s1 + 1));
    printf("%c\n",*(s1 + 2));
    printf("%c\n",*(s1 + 50)); // ?

    printf("%s\n",s1);


    return 0;
}
