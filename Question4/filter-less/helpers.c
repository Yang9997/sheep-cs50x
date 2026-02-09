#include "helpers.h"
#include <math.h>
// i行j列
// Convert image to grayscale
// 灰度
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE avg = 0x00;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
// 棕褐色
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // 这里要是用BYTE的话是不是也会溢出形成循环？没有试，还是保险起见用int吧
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // printf("%i %i %i\n",sepiaRed,sepiaGreen,sepiaBlue);
            if (sepiaRed < 0)
                sepiaRed = 0;
            else if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen < 0)
                sepiaRed = 0;
            else if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue < 0)
                sepiaBlue = 0;
            else if (sepiaBlue > 255)
                sepiaBlue = 255;
            // 对原图片重新赋值
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
// 对称
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE blue = 0x00;
    BYTE red = 0x00;
    BYTE green = 0x00;
    for (int i = 0; i < height; i++)
    {
        // 这里是j < (width / 2)，注意中间位置
        for (int j = 0; j < (width / 2); j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtRed = red;
            image[i][width - 1 - j].rgbtGreen = green;
            image[i][width - 1 - j].rgbtBlue = blue;
        }
    }
    return;
}

// Blur image
// 模糊
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // 这里存多个rgb用来求平均值的话不能用BYTE，要用int，要不然求平均值之前加和会溢出截断
    int red = 0;
    int green = 0;
    int blue =0;

    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j].rgbtRed = 0;
            tmp[i][j].rgbtGreen = 0;
            tmp[i][j].rgbtBlue = 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = 0;
            green = 0;
            blue = 0;
            // 左上角
            if ( i == 0 && j == 0)
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            // 右上角
            else if ( i == 0 && j == (width - 1))
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = j - 1; b <= j; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            // 左下角
            else if (i == (height - 1) && j == 0)
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            // 右上角
            else if (i == (height - 1) && j == (width - 1))
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = j - 1; b <= j; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            // 第一行
            else if (i == 0)
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = j - 1; b <= (j + 1); b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            // 最后一行
            else if (i == (height - 1))
            {
                for (int a = i - 1; a <= i; a++)
                {
                    for (int b = j - 1; b <= (j + 1); b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            // 第一列
            else if (j == 0)
            {
                for (int a = i - 1; a <= (i + 1); a++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            // 最后一列
            else if (j == (width - 1))
            {
                for (int a = i - 1; a <= (i + 1); a++)
                {
                    for (int b = j - 1; b <= j; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            // 除去外围一圈的里面格子
            else
            {
                for (int a = i - 1; a <= (i + 1); a++)
                {
                    for (int b = j - 1; b <= (j + 1); b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b].rgbtBlue;
                    }
                }
                red = round(red / 9.0);
                green = round(green / 9.0);
                blue = round(blue / 9.0);
            }

            // 不要对原图片重新赋值，要借助中间变量整体赋值之后再赋值
            tmp[i][j].rgbtRed = red;
            tmp[i][j].rgbtGreen = green;
            tmp[i][j].rgbtBlue = blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            // printf("%i %i %i\n",image[i][j].rgbtRed,image[i][j].rgbtGreen,image[i][j].rgbtBlue);
        }
    }
    return;
}
