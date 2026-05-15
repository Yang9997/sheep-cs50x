#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
// 灰度
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j].rgbtGreen +image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtGreen = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][j].rgbtRed;
        }
    }
    return;
}

// Reflect image horizontally
// 对称
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;
    for (int i = 0; i < height; i++)
    {
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
    int red = 0;
    int green = 0;
    int blue = 0;

    // 新矩阵 = 原矩阵外围加一圈000
    RGBTRIPLE tmp[height + 2][width + 2];
    for (int i = 0; i <= (height + 1); i++)
    {
        for (int j = 0; j <= (width + 1); j++)
        {
            if ( i == 0 || j == 0 || i == (height + 1) || j == (width + 1))
            {
                tmp[i][j].rgbtRed = 0;
                tmp[i][j].rgbtGreen = 0;
                tmp[i][j].rgbtBlue = 0;
                continue;
            }
            tmp[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
            tmp[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
            tmp[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
        }
    }

    // 求新值
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            // 求值
            for (int a = i - 1; a <= (i + 1); a++)
            {
                for (int b = j - 1; b <= (j + 1); b++)
                {
                    red += tmp[a][b].rgbtRed;
                    green += tmp[a][b].rgbtGreen;
                    blue += tmp[a][b].rgbtBlue;
                }
            }

            // 四个角
            if ((i == 1 || i == height) && (j == 1 || j == width))
            {
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            // 去掉角的四条边
            else if (i == 1 || i == height || j == 1 || j == width)
            {
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            // 其他
            else
            {
                red = round(red / 9.0);
                green = round(green / 9.0);
                blue = round(blue / 9.0);
            }

            image[i - 1][j - 1].rgbtRed = red;
            image[i - 1][j - 1].rgbtGreen = green;
            image[i - 1][j - 1].rgbtBlue = blue;

            red = 0;
            green = 0;
            blue = 0;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int red = 0;
    int green = 0;
    int blue = 0;

    // 新矩阵 = 原矩阵外围加一圈000
    RGBTRIPLE tmp[height + 2][width + 2];
    for (int i = 0; i < (height + 2); i++)
    {
        for (int j = 0; j < (width + 2); j++)
        {
            if ( i == 0 || j == 0 || i == (height + 1) || j == (width + 1))
            {
                tmp[i][j].rgbtRed = 0;
                tmp[i][j].rgbtGreen = 0;
                tmp[i][j].rgbtBlue = 0;
                continue;
            }
            tmp[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
            tmp[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
            tmp[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
        }
    }

    // 原矩阵值全清零，便于处理
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = 0;
            image[i][j].rgbtGreen = 0;
            image[i][j].rgbtBlue = 0;
        }
    }

    int coreGx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int coreGy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int middleX[3][3] = {0};
    int middleY[3][3] = {0};
    int Gx = 0;
    int Gy = 0;

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            // 求值
            // 红的
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    // 例如，为了计算像素的红色通道值Gx，
                    // 我们会取围绕该像素的一个3x3区域内的九个像素的原始红色值，
                    // 将它们分别乘以对应的Gx核中的值，
                    // 然后将所得的值相加。
                    middleX[a][b] = tmp[i - 1 + a][j - 1 + b].rgbtRed * coreGx[a][b];
                    middleY[a][b] = tmp[i - 1 + a][j - 1 + b].rgbtRed * coreGy[a][b];
                }
            }

            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    Gx += middleX[a][b];
                    Gy += middleY[a][b];
                }
            }
            red = round(hypot(Gx, Gy));

            if (red > 255)
                red = 255;
            else if (red < 0)
                red = 0;

            image[i - 1][j - 1].rgbtRed = red;
            red = 0;
            Gx = 0;
            Gy = 0;

            // 绿的
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    middleX[a][b] = tmp[i - 1 + a][j - 1 + b].rgbtGreen * coreGx[a][b];
                    middleY[a][b] = tmp[i - 1 + a][j - 1 + b].rgbtGreen * coreGy[a][b];
                }
            }

            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    Gx += middleX[a][b];
                    Gy += middleY[a][b];
                }
            }
            green = round(hypot(Gx, Gy));

            if (green > 255)
                green = 255;
            else if (green < 0)
                green = 0;

            image[i - 1][j - 1].rgbtGreen = green;
            green = 0;
            Gx = 0;
            Gy = 0;

            // 蓝的
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    middleX[a][b] = tmp[i - 1 + a][j - 1 + b].rgbtBlue * coreGx[a][b];
                    middleY[a][b] = tmp[i - 1 + a][j - 1 + b].rgbtBlue * coreGy[a][b];
                }
            }

            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    Gx += middleX[a][b];
                    Gy += middleY[a][b];
                }
            }
            blue = round(hypot(Gx, Gy));

            if (blue > 255)
                blue = 255;
            else if (blue < 0)
                blue = 0;

            image[i - 1][j - 1].rgbtBlue = blue;
            blue = 0;
            Gx = 0;
            Gy = 0;
        }
    }
    return;
}
