#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEADERLENGTH 44
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // 这是我这个新手能想出来的处理方法吗...我指针其实还没太明白怎么回事
    // 代码写少了，没见过这种
    // 文件名后缀得是4个单位，小于4位不可能是.wav格式文件
    // 输入文件的格式
    if (strlen(argv[1]) < 4)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }
    // 文件名后缀从倒数第四个字符地址开始算
    char *suffix = argv[1] + strlen(argv[1]) - 4;
    if (strcmp(suffix, ".wav") != 0)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }
    // 输出文件的格式
    if (strlen(argv[2]) < 4)
    {
        printf("Output is not a WAV file.\n");
        return 1;
    }
    // 文件名后缀从倒数第四个字符地址开始算
    suffix = argv[2] + strlen(argv[2]) - 4;
    if (strcmp(suffix, ".wav") != 0)
    {
        printf("Output is not a WAV file.\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Can't open the inputfile.\n");
        return 1;
    }
    // Read header
    // TODO #3
    WAVHEADER wavheader;
    fread(&wavheader, HEADERLENGTH, 1, input_file);
    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(wavheader))
    {
        printf("Input file is not a wav.\n");
        return 1;
    }
    // Open output file for writing
    // TODO #5
    FILE *output_file = fopen(argv[2], "w");
    // Write header to file
    // TODO #6
    if (output_file == NULL)
    {
        printf("Can't open the outputfile.\n");
    }
    fwrite(&wavheader, HEADERLENGTH , 1, output_file);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(wavheader);
    // Write reversed audio to file
    // TODO #8
    // 一块是好几个bytes字节
    BYTE buffer[block_size];
    // fseek函数第三个参数只能是SEEK_END，SEEK_CUR，SEEK_SET这三个中的一个
    fseek(input_file, - block_size, SEEK_END);
    fseek(output_file, 0, SEEK_END);
    // ftell函数用于判断当前光标距离文件开始处的相对位置，最后一次反转的块是在wav头后面的第一块
    while (ftell(input_file) >= sizeof(WAVHEADER))
    {
        fread(&buffer, 1, block_size, input_file);
        fwrite(&buffer, 1, block_size, output_file);
        fseek(input_file, - (2 * block_size), SEEK_CUR);
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}
