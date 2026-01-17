#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int length = get_int("Enter the length: ");
    int numbers[length];
    for (int i = 0; i < length; i++)
    {
        numbers[i] = get_int("number: ");
    }
    // for (int i = 0; i < length; i++)
    // {
    //     printf("%i\n",numbers[i]);
    // }
    int mintag ;
    int min ;
    int temp ;
    for (int i = 0; i < (length - 1); i++)
    {
        // 存当前位置值
        temp = numbers[i];
        // 最小值
        min = numbers[i];
        mintag = i;
        for (int j = i + 1; j < length; j++)
        {
            // 选出后面最小值
            if (min > numbers[j])
            {
                min = numbers[j];
                mintag = j;
                // printf("i = %i, mintag = %i, min = %i\n", i, mintag, min);
            }
        }
        if (i != min)
        {
            numbers[i] = min;
            numbers[mintag] = temp;
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%i ",numbers[i]);
    }
    printf("\n");
}
