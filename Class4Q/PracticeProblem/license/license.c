#include <stdio.h>
// 什么玩意儿malloc？
// 什么玩意儿strcpy？
// 全都没有！
int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[8][7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer[idx], 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[idx][6] = '\0';

        // Save plate number in array
        plates[idx] = buffer[idx];
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
}
