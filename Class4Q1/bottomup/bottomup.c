// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#define BITMAPFILEHEADERLENGTH 14
#define BITMAPINFOHEADERLENGTH 40
#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // 三个参数
    if (argc != 3)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file
    // 输入文件只读
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    // 输出文件可写
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    // bmp文件头
    BITMAPFILEHEADER bf;
    // 读bmp的bmp文件头，存进去
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    // bmp信息头
    BITMAPINFOHEADER bi;
    // 读bmp的bmp信息头，存进去
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    // 确认文件格式是.bmp
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 4;
    }

    // Write outfile's BITMAPFILEHEADER
    // 抄
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    // 抄
    bi.biHeight = - bi.biHeight;
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    // Determine padding for scanlines
    // BMP 格式规定：每一行像素数据（Scanline）占用的字节数必须是4的倍数
    // 每行像素末尾字节填充
    // 最后的 % 4 是为了处理刚好整除的情况，即如果本来就是4的倍数，计算结果是4，模4后变回0，表示不需要填充
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // Temporary storage
            RGBTRIPLE triple;

            // Read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // Write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // Then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Close infile
    fclose(inptr);

    // Close outfile
    fclose(outptr);

    // Success
    return 0;
}
