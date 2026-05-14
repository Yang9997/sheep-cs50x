// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // 要求三个参数
    if (argc != 3)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }

    // Remember filenames
    // 第二个参数和第三个参数是文件
    // 哦，这样存一下还得
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file
    // 输入文件可读
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
    // 第一个头部的结构体
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    // 第二个头部的结构体
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    // 确认文件是否为要求格式
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 4;
    }

    // Write outfile's BITMAPFILEHEADER
    // 写入第一个头
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    // 写入第二个头
    bi.biHeight = - bi.biHeight;
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Determine padding for scanlines
    // 内边距？这行代码是干什么的？
    //  BMP 格式规定：每一行像素的字节数必须是 4 的倍数。
    //  如果这个数不是 4 的倍数，就需要在行尾添加额外的填充字节（数值为 0），使其成为 4 的倍数。
    //  (bi.biWidth * sizeof(RGBTRIPLE)) % 4 计算原始行字节数除以 4 的余数（可能为 0,1,2,3）。
    //  4 - 余数 得到需要添加的字节数（当余数为 0 时，结果是 4，但实际不需要填充）。
    //  最后再 % 4 将 4 变成 0，避免填充 4 个字节（因为余数为 0 时不需要填充）。
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    // 迭代输入文件的扫描线
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
