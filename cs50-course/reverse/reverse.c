#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Wrong argument count.\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *filename = argv[1];

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    // Read header
    // TODO #3

    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, file);

    // Use check_format to ensure WAV format
    if (!check_format(header))
    {
        return 1;
    }
    // TODO #4

    // Open output file for writing
    // TODO #5
    char *outname = argv[2];

    FILE *out = fopen(outname, "w");

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, out);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);
    // Write reversed audio to file
    // TODO #8
    int audio;
    int pointer = ftell(file);
    int n = 1;
    fseek(file, 0, SEEK_END);
    while (ftell(file) > pointer + block_size)
    {
        int x = n * block_size;
        fseek(file, -x, SEEK_END);
        fread(&audio, block_size, 1, file);
        fwrite(&audio, block_size, 1, out);
        n++;
    }

    fclose(file);
    fclose(out);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    int format[4] = {'W', 'A', 'V', 'E'};
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != format[i])
        {
            return 0;
        }
    }

    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}