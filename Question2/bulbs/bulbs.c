#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string s = get_string("Enter a string: ");
    for(int i = 0;i<strlen(s);i++){
        int a[8]={0};
        int temp = s[i];
        for(int j = 0;j<BITS_IN_BYTE;j++){
            a[BITS_IN_BYTE-1-j] = temp%2;
            temp /= 2;
        }
        for(int j = 0;j<BITS_IN_BYTE;j++){
            print_bulb(a[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
