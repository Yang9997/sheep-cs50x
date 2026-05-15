#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Can't open the file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *output_file = NULL;
    int file_count = 0;
    int is_head = 0;
    char file_name[8];

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            is_head = 1;
        }
        // 是第一张图片的第一块头
        if (is_head)
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }
            sprintf(file_name, "%03i.jpg", file_count);
            output_file = fopen(file_name, "w");
            file_count++;
            is_head = 0;
        }

        // 写头和身体，头和身体要放进一个文件里面
        if (output_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output_file);
        }
    }

    // 文件在关闭时要保证存在且没关再关， 不想检查就所有文件都加判断再关闭
    if (output_file != NULL)
    {
        fclose(output_file);
    }


    fclose(file);

    return 0;
}
