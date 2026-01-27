#include "helpers.h"
#include <math.h>
// Convert image to grayscale
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
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE blue = 0x00;
    BYTE red = 0x00;
    BYTE green = 0x00;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= (width / 2); j++)
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
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE red = 0x00;
    BYTE green = 0x00;
    BYTE blue =0x00;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = 0x00;
            green = 0x00;
            blue = 0x00;
            if ( i == 0 && j == 0)
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            else if ( i == 0 && j == (width - 1))
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = width - 2; b <= j; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            else if (i == (height - 1) && j == 0)
            {
                for (int a = height - 2; a <= i; a++)
                {
                    for (int b = 0; b <= 1; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            else if (i == (height - 1) && j == (width - 1))
            {
                for (int a = height - 2; a <= i; a++)
                {
                    for (int b = width - 2; b <= j; b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 4.0);
                green = round(green / 4.0);
                blue = round(blue / 4.0);
            }
            else if (i == 0)
            {
                for (int a = 0; a <= 1; a++)
                {
                    for (int b = j - 1; b <= (j + 1); b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            else if (i == (height - 1))
            {
                for (int a = height - 2; a <= (height - 1); a++)
                {
                    for (int b = j - 1; b <= (j + 1); b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 6.0);
                green = round(green / 6.0);
                blue = round(blue / 6.0);
            }
            else if (j == 0)
            {

            }
            else if (j == (width - 1))
            {

            }
            else
            {
                for (int a = i - 1; a <= (i + 1); a++)
                {
                    for (int b = j - 1; b <= (j + 1); b++)
                    {
                        red += image[a][b].rgbtRed;
                        green += image[a][b].rgbtGreen;
                        blue += image[a][b],rgbtBlue;
                    }
                }
                red = round(red / 9.0);
                green = round(green / 9.0);
                blue = round(blue / 9.0);
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = Green;
            image[i][j].rgbtBlue = Blue;
        }
    }
    return;
}
