#include <stdio.h>
#include <cs50.h>
int main()
{
    char c = get_char("Do you agree?");

    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
}