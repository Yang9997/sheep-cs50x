#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
bool isBiggerThanZero(int height);
int main(void)
{
    int height = 0;
    while (!isBiggerThanZero(height))
    {
        height = get_int("Height: ");
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height - 1 - i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
bool isBiggerThanZero(int height)
{
    if (height >= 1 && height <= 8)
    {
        return true;
    }
    return false;
}
