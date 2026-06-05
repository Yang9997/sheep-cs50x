#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
// #include <limits.h>
#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    // 需要两个参数
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // 需要第二个参数是.raw结尾
    if (strlen(argv[1]) < 4)
    {
        printf("Error file type. Usage: ./recover IMAGE.raw.\n");
        return 1;
    }
    else if (!(argv[1][strlen(argv[1]) - 4] == '.'
        && argv[1][strlen(argv[1]) - 3] == 'r'
        && argv[1][strlen(argv[1]) - 2] == 'a'
        && argv[1][strlen(argv[1]) - 1] == 'w'))
    {
        printf ("Error file type. Usage: ./recover IMAGE.raw.\n");
        return 1;
    }

    // 打开文件
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error open file. There is no this file.\n");
        return 1;
    }

    // 全正。因为char虽然是8位但是范围可以是负数，不行
    uint8_t buffer[512];
    char name[8];
    int count = 0;
    int tag = 0;
    FILE *image;

    // 注意：char类型根据计算机架构在默认时不一定是全正数
    // printf("char is %s\n", CHAR_MIN < 0 ? "signed" : "unsigned");
    // printf("char max = %d (0x%X)\n", CHAR_MAX, CHAR_MAX);

    // while ((fread(buffer, sizeof(buffer), 1, file)) == 1)
    while ((fread(buffer, 1, BLOCK_SIZE, file)) == BLOCK_SIZE)
    {
        // 遇到第一张图片头
        // 注意：有关第四字节1110开头的筛选
        if (tag == 0 && buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xf0) == 0xE0)
        {
            sprintf(name, "%03d.jpg", count++);
            image = fopen(name, "w");
            if (image == NULL)
            {
                printf("Error open file.\n");
                return 1;
            }
            // printf("0x%x\n",buffer[3]);
            fwrite(buffer, 1, BLOCK_SIZE, image);
            tag = 1;
        }
        else if (tag == 1)
        {
            if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xf0) == 0xE0)
            {
                // printf("0x%x\n",buffer[3]);
                fclose(image);
                sprintf(name, "%03d.jpg", count++);
                image = fopen(name, "w");
                if (image == NULL)
                {
                    printf("Error open file.\n");
                    return 1;
                }
                fwrite(buffer, 1, BLOCK_SIZE, image);
            }
            else
            {
                fwrite(buffer, 1, BLOCK_SIZE, image);
            }
        }
    }


    fclose(file);
    fclose(image);

    return 0;
}
