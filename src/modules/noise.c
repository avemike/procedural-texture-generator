#include <stdlib.h>
#include "../types/bmp.h"
//
// Created by avemike on 16.01.2021.
//

BMP* createNoise(int width, int height) {
    // Init image header
    BMP* image = (BMP*)malloc(sizeof (BMP));
    image->header.pixWidth = width;
    image->header.pixHeight = height;
    image->header.dataOffset = 54;
    image->header.id[0] = 'B';
    image->header.id[1] = 'M';
    image->header.fileSize = width * height * 3 + 54;
    image->header.DIBHeaderSize = 40;
    image->header.bitsPerPixel = 24;
    image->header.biImageByteSize = width * height * 3;

    image->data = (Pixel*)malloc(sizeof(Pixel) * width * height);

    for(int row = 0; row < height; row++) {
        for(int column = 0; column < width; column++) {
            int random = rand() % 256;
            image->data[column + row*width].blue = random;
            image->data[column + row*width].green = random;
            image->data[column + row*width].red = random;
        }
    }

    return image;
}