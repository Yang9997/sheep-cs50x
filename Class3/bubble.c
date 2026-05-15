#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int length = get_int("Length: ");
    int numbers[length];
    for (int i = 0; i < length; i++)
    {
        numbers[i] = get_int("number: ");
    }

    int temp = 0;
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (length - 1 - i); j++)
        {
            if ( numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%i ",numbers[i]);
    }
    printf("\n");
}
