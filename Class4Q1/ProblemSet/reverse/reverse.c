#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

#define BLOCK_HEADER 44
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
    if (!(argv[1][strlen(argv[1]) - 3] == 'w' && argv[1][strlen(argv[1]) - 2] == 'a' && argv[1][strlen(argv[1]) - 1] == 'v'))
    {
        printf("Input is not a WAV file.\n");
        return 0;
    }
    if (!(argv[2][strlen(argv[2]) - 3] == 'w' && argv[2][strlen(argv[2]) - 2] == 'a' && argv[2][strlen(argv[2]) - 1] == 'v'))
    {
        printf("Output is not a WAV file.\n");
        return 0;
    }
    // Open input file for reading
    // TODO #2
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Error file open.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER buffer;
    fread(&buffer, 1, BLOCK_HEADER, inputFile);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(buffer))
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL)
    {
        printf("Error file open.\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&buffer, 1, BLOCK_HEADER, outputFile);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blockSize = get_block_size(buffer);
    // Write reversed audio to file
    // TODO #8
    fseek(inputFile, - blockSize, SEEK_END);
    fseek(outputFile, BLOCK_HEADER, SEEK_SET);
    BYTE block[blockSize];

    while (ftell(inputFile) != BLOCK_HEADER)
    {
        fread(block, 1, blockSize, inputFile);
        fwrite(block, 1, blockSize, outputFile);
        fseek(inputFile, - blockSize * 2, SEEK_CUR);
    }
    fread(block, 1, blockSize, inputFile);
    fwrite(block, 1, blockSize, outputFile);

    fclose(inputFile);
    fclose(outputFile);

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
    // 这里还是忘记乘了，依旧读不明白题
    // 文件可能是多声道，不论是多声道还是单声道，一个块（采样帧）的大小都是按题意给的 声道数 * 每样本字节数
    int bytesPerSample = header.numChannels * header.bitsPerSample / 8;
    return bytesPerSample;
}
