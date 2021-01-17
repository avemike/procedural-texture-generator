#include <stdlib.h>
#include "bmp.h"
//
// Created by avemike on 16.01.2021.
//

BMP* createNoise(int width, int height) {
    // Init image header
    BMP* image = (BMP*)malloc(sizeof (BMP));
    generateBMPHeader(image, width, height);
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