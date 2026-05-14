// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t bufferHead[HEADER_SIZE];
    fread(bufferHead, 1, HEADER_SIZE, input);
    fwrite(bufferHead, 1, HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    fseek(input, HEADER_SIZE, SEEK_SET);
    fseek(output, HEADER_SIZE, SEEK_SET);
    int16_t buffer;
    while(fread(&buffer, 2, 1, input))
    {
        // 修正，这里不需要round，按check50的逻辑是直接截断
        // buffer = round(buffer * factor);
        buffer = buffer * factor;
        printf("%hd\n",buffer);
        fwrite(&buffer, 2, 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
