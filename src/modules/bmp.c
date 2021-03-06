#include <stdio.h>
#include <stdlib.h>

#include "bmpType.h"

// Simply saves bmp
void saveBMP(const char *bmpFileOut, BMP *bmpInstance) {
    FILE *fp = NULL;

    fp = fopen(bmpFileOut, "wb");
    int pad = 0;

    fwrite(bmpInstance->header, bmpInstance->header->dataOffset, 1, fp);
    int padding = abs((bmpInstance->header->pixWidth * 3) % 4);

    for (int y = 0; y < bmpInstance->header->pixHeight; y++) {
        for (int x = 0; x < bmpInstance->header->pixWidth; x++) {
            fwrite(&bmpInstance->data[(x + bmpInstance->header->pixWidth * y)], 1, 3, fp);
        }
        for (int i = 0; i < padding; i++) {
            fwrite(&pad, 1, 1, fp);
        }
    }

    fclose(fp);
}

BmpHeader *generateBMPHeader(unsigned int width, unsigned int height) {
    BmpHeader *header = (BmpHeader *) malloc(sizeof(BmpHeader));

    header->id[0] = 'B';
    header->id[1] = 'M';
    header->pixWidth = width;
    header->pixHeight = height;
    header->dataOffset = 54;
    header->fileSize = width * height * 3 + 54;
    header->DIBHeaderSize = 40;
    header->bitsPerPixel = 24;
    header->biImageByteSize = width * height * 3;
    header->biPlanes = 0;
    header->biCompression = 0;
    header->biXPixPerMeter = 0;
    header->biYPixPerMeter = 0;
    header->biClrUsed = 0;
    header->biClrImportant = 0;

    return header;
}

BMP *generateBMPFile(RGB *data, unsigned int width, unsigned int height) {
    BMP *image = (BMP *) malloc(sizeof(BMP));
    image->header = generateBMPHeader(width, height);
    image->data = data;
    return image;
}
