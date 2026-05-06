#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char *s = get_string("s: ");
    if ( s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(t) + 1);
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    return 0;
}
