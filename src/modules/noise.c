#include <stdlib.h>
#include "bmp.h"
//
// Created by avemike on 16.01.2021.
//


Pixel *createNoise(int width, int height) {
    Pixel *data = (Pixel *) malloc(sizeof(Pixel) * width * height);

    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            int random = rand() % 256;
            data[column + row * width].blue = random;
            data[column + row * width].green = random;
            data[column + row * width].red = random;
        }
    }

    return data;
}