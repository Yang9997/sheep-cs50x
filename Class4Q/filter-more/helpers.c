#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int temp = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            temp = round(temp * 1.0 / 3.0);
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtBlue = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmpRed = 0;
    int tmpGreen = 0;
    int tmpBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmpRed = image[i][width - j - 1].rgbtRed;
            tmpGreen = image[i][width - j - 1].rgbtGreen;
            tmpBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtRed = image[i][j].rgbtRed;
            image[i][width - j - 1].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - j - 1].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = tmpRed;
            image[i][j].rgbtGreen = tmpGreen;
            image[i][j].rgbtBlue = tmpBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height + 2][width + 2];
    for (int i = 0; i < (height + 2); i++)
    {
        for (int j = 0; j < (width + 2); j++)
        {
            if (i == 0 || i == (height + 1) || j == 0 || j == (width + 1))
            {
                tmpImage[i][j].rgbtRed = 0;
                tmpImage[i][j].rgbtGreen = 0;
                tmpImage[i][j].rgbtBlue = 0;
            }
            else
            {
                tmpImage[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
                tmpImage[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
                tmpImage[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
            }
        }
    }

    int tmpRed = 0;
    int tmpGreen = 0;
    int tmpBlue = 0;
    for (int i = 1; i < (height + 1); i++)
    {
        for (int j = 1; j < (width + 1); j++)
        {
            for (int a = i - 1; a <= (i + 1); a++)
            {
                for (int b = j - 1; b <= (j + 1); b++)
                {
                    tmpRed += tmpImage[a][b].rgbtRed;
                    tmpGreen += tmpImage[a][b].rgbtGreen;
                    tmpBlue += tmpImage[a][b].rgbtBlue;
                }
            }

            if ((i == 1 || i == height) && (j == 1 || j == width))
            {
                image[i - 1][j - 1].rgbtRed = round(tmpRed * 1.0 / 4.0);
                image[i - 1][j - 1].rgbtGreen = round(tmpGreen * 1.0 / 4.0);
                image[i - 1][j - 1].rgbtBlue = round(tmpBlue * 1.0 / 4.0);
            }
            else if (i == 1 || i == height || j == 1 || j == width)
            {
                image[i - 1][j - 1].rgbtRed = round(tmpRed * 1.0 / 6.0);
                image[i - 1][j - 1].rgbtGreen = round(tmpGreen * 1.0 / 6.0);
                image[i - 1][j - 1].rgbtBlue = round(tmpBlue * 1.0 / 6.0);
            }
            else
            {
                image[i - 1][j - 1].rgbtRed = round(tmpRed * 1.0 / 9.0);
                image[i - 1][j - 1].rgbtGreen = round(tmpGreen * 1.0 / 9.0);
                image[i - 1][j - 1].rgbtBlue = round(tmpBlue * 1.0 / 9.0);
            }

            tmpRed = 0;
            tmpGreen = 0;
            tmpBlue = 0;
        }

    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height + 2][width + 2];
    for (int i = 0; i < (height + 2); i++)
    {
        for (int j = 0; j < (width + 2); j++)
        {
            if (i == 0 || i == (height + 1) || j == 0 || j == (width + 1))
            {
                tmpImage[i][j].rgbtRed = 0;
                tmpImage[i][j].rgbtGreen = 0;
                tmpImage[i][j].rgbtBlue = 0;
            }
            else
            {
                tmpImage[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
                tmpImage[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
                tmpImage[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
            }
        }
    }

    // int GxCore[3][3] = {
    //     {-1, 0, 1},
    //     {-2, 0, 2},
    //     {-1, 0, 1}
    // };
    // int GyCore[3][3] = {
    //     {-1, -2, -1},
    //     {0, 0, 0},
    //     {1, 2, 1}
    // };
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         printf("%d\t",GxCore[i][j]);
    //     }
    //     printf("\n");
    // }

    int GxRed = 0;
    int GxGreen = 0;
    int GxBlue = 0;
    int GyRed = 0;
    int GyGreen = 0;
    int GyBlue = 0;
    int tmpRed = 0;
    int tmpGreen = 0;
    int tmpBlue = 0;
    for (int i = 1; i < (height + 1); i++)
    {
        for (int j = 1; j < (width + 1); j++)
        {
            // GxCore和GyCore不知道哪里错了一直算不对，支持老艺术家手搓
            GxRed = tmpImage[i - 1][j + 1].rgbtRed - tmpImage[i - 1][j - 1].rgbtRed + 2 * (tmpImage[i][j + 1].rgbtRed - tmpImage[i][j - 1].rgbtRed) + tmpImage[i + 1][j + 1].rgbtRed - tmpImage[i + 1][j - 1].rgbtRed;
            GxGreen = tmpImage[i - 1][j + 1].rgbtGreen - tmpImage[i - 1][j - 1].rgbtGreen + 2 * (tmpImage[i][j + 1].rgbtGreen - tmpImage[i][j - 1].rgbtGreen) + tmpImage[i + 1][j + 1].rgbtGreen - tmpImage[i + 1][j - 1].rgbtGreen;
            GxBlue = tmpImage[i - 1][j + 1].rgbtBlue - tmpImage[i - 1][j - 1].rgbtBlue + 2 * (tmpImage[i][j + 1].rgbtBlue - tmpImage[i][j - 1].rgbtBlue) + tmpImage[i + 1][j + 1].rgbtBlue - tmpImage[i + 1][j - 1].rgbtBlue;
            GyRed = tmpImage[i + 1][j - 1].rgbtRed - tmpImage[i - 1][j - 1].rgbtRed + 2 * (tmpImage[i + 1][j].rgbtRed - tmpImage[i - 1][j].rgbtRed) + tmpImage[i + 1][j + 1].rgbtRed - tmpImage[i - 1][j + 1].rgbtRed;
            GyGreen = tmpImage[i + 1][j - 1].rgbtGreen - tmpImage[i - 1][j - 1].rgbtGreen + 2 * (tmpImage[i + 1][j].rgbtGreen - tmpImage[i - 1][j].rgbtGreen) + tmpImage[i + 1][j + 1].rgbtGreen - tmpImage[i - 1][j + 1].rgbtGreen;
            GyBlue = tmpImage[i + 1][j - 1].rgbtBlue - tmpImage[i - 1][j - 1].rgbtBlue + 2 * (tmpImage[i + 1][j].rgbtBlue - tmpImage[i - 1][j].rgbtBlue) + tmpImage[i + 1][j + 1].rgbtBlue - tmpImage[i - 1][j + 1].rgbtBlue;
            tmpRed = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            tmpGreen = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            tmpBlue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));
            if (tmpRed > 255)
            {
                tmpRed = 255;
            }
            else if (tmpRed < 0)
            {
                tmpRed = 0;
            }
            if (tmpGreen > 255)
            {
                tmpGreen = 255;
            }
            else if (tmpBlue < 0)
            {
                tmpBlue = 0;
            }
            if (tmpBlue > 255)
            {
                tmpBlue = 255;
            }
            else if (tmpBlue < 0)
            {
                tmpBlue = 0;
            }
            image[i - 1][j - 1].rgbtRed = tmpRed;
            image[i - 1][j - 1].rgbtGreen = tmpGreen;
            image[i - 1][j - 1].rgbtBlue = tmpBlue;
        }
        GxRed = 0;
        GxGreen = 0;
        GxBlue = 0;
        GyRed = 0;
        GyGreen = 0;
        GyBlue = 0;
        tmpRed = 0;
        tmpGreen = 0;
        tmpBlue = 0;
    }
    return;
}
