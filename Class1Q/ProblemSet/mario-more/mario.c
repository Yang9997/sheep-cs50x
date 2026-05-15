#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
bool isInTheRange(int height);
int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (!isInTheRange(height));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height - 1 - i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
bool isInTheRange(int height)
{
    if (height <= 8 && height >= 1)
    {
        return true;
    }
    return false;
}
