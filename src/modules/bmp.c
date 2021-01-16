#include <stdio.h>
#include <stdlib.h>
#include "../types/bmp.h"

BMP *loadBMP(const char *bmpFileIn) {
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

    // Create BMP instance
    BMP *output = (BMP *) malloc(sizeof(BMP));
    output->data = pixels;
    output->header = bH;
    fclose(fp);
    return output;
}

void saveBMP(const char *bmpFileOut, BMP bmpInstance) {
    FILE *fp = NULL;

    fp = fopen(bmpFileOut, "wb");
    int pad = 0;

    fwrite(&bmpInstance.header, bmpInstance.header.dataOffset, 1, fp);
    int padding = abs((bmpInstance.header.pixWidth * 3) % 4);

    for (int y = 0; y < bmpInstance.header.pixHeight; y++) {
        for (int x = 0; x < bmpInstance.header.pixWidth; x++) {
            fwrite(&bmpInstance.data[(x + bmpInstance.header.pixWidth * y)], 1, 3, fp);
        }
        for (int i = 0; i < padding; i++) {
            fwrite(&pad, 1, 1, fp);
        }

    }
    fclose(fp);
}
