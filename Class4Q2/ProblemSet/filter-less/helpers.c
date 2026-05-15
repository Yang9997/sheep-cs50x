#include "helpers.h"
#include <math.h>

// Convert image to grayscale
// 灰色
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            tmp = round(tmp * 1.0 / 3.0);
            image[i][j].rgbtBlue = tmp;
            image[i][j].rgbtGreen = tmp;
            image[i][j].rgbtRed = tmp;
        }
    }
    return;
}

// Convert image to sepia
// 棕褐
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE originalRed = 0;
    BYTE originalGreen = 0;
    BYTE originalBlue = 0;
    double sepiaRed;
    double sepiaGreen;
    double sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
        }
    }
    return;
}

// Reflect image horizontally
// 镜像
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE tmpRed = 0;
    BYTE tmpGreen = 0;
    BYTE tmpBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmpRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = tmpRed;

            tmpGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tmpGreen;

            tmpBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tmpBlue;
        }
    }
    return;
}

// Blur image
// 模糊
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpImage[height + 2][width + 2];

    // 外扩一圈0
    for (int i = 0; i < (height + 2); i++)
    {
        for (int j = 0; j < (width + 2); j++)
        {
            if (i == 0 || j == 0 || i == (height + 1) || j == (width + 1))
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

            // 做第二遍还是会错啊错，这个4, 6, 9
            if ((i == 1 || i == height) && (j == 1 || j == width))
            {
                tmpRed = round(tmpRed * 1.0 / 4.0);
                tmpGreen = round(tmpGreen * 1.0 / 4.0);
                tmpBlue = round(tmpBlue * 1.0 / 4.0);
            }
            else if (i == 1 || i == height || j == 1 || j == width)
            {
                tmpRed = round(tmpRed * 1.0 / 6.0);
                tmpGreen = round(tmpGreen * 1.0 / 6.0);
                tmpBlue = round(tmpBlue * 1.0 / 6.0);
            }
            else
            {
                tmpRed = round(tmpRed * 1.0 / 9.0);
                tmpGreen = round(tmpGreen * 1.0 / 9.0);
                tmpBlue = round(tmpBlue * 1.0 / 9.0);
            }
            image[i - 1][j - 1].rgbtRed = tmpRed;
            image[i - 1][j - 1].rgbtGreen = tmpGreen;
            image[i - 1][j - 1].rgbtBlue = tmpBlue;

            tmpRed = 0;
            tmpGreen = 0;
            tmpBlue = 0;
        }
    }

    return;
}
