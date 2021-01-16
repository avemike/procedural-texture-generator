#include <stdio.h>
#include <stdlib.h>
#include "../types/bmp.h"
#include "../types/memDescriptor.h"


MemDescriptor *loadBMP(const char *bmpFileIn) {
    FILE *fp = NULL;
    BmpHeader bH;
    Pixel *pixels = NULL;

    fp = fopen(bmpFileIn, "rb");

    // Read header
    fread(&bH, 54, 1, fp); // read full header

    // Read bmp
    pixels = malloc(sizeof(Pixel) * bH.pixWidth * bH.pixHeight);

    fseek(fp, bH.dataOffset, SEEK_SET);
    int padding = abs((bH.pixWidth * 3) % 4);
    for (int y = 0; y < bH.pixHeight; y++) {
        for (int x = 0; x < bH.pixWidth; x++) {
            fread(&pixels[(x + bH.pixWidth * y)], 1, 3, fp);
        }
        fseek(fp, padding, SEEK_CUR);
    }

    // Create MemDescriptor instance
    MemDescriptor *output = (MemDescriptor *) malloc(sizeof(MemDescriptor));
    output->pixels = pixels;
    output->header = bH;
    fclose(fp);
    return output;
}

void saveBMP(const char *bmpFileOut, MemDescriptor m) {
    FILE *fp = NULL;

    fp = fopen(bmpFileOut, "wb");
    int pad = 0;

    fwrite(&m.header, m.header.dataOffset, 1, fp);
    int padding = abs((m.header.pixWidth * 3) % 4);

    for (int y = 0; y < m.header.pixHeight; y++) {
        for (int x = 0; x < m.header.pixWidth; x++) {
            fwrite(&m.pixels[(x + m.header.pixWidth * y)], 1, 3, fp);
        }
        for (int i = 0; i < padding; i++) {
            fwrite(&pad, 1, 1, fp);
        }

    }
    fclose(fp);
}
