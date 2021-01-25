//
// Created by avemike on 25.01.2021.
//

#include <stdlib.h>
#include "../headers/texture.h"

Pixel *generateBMPTexture(double *pattern, int width, int height) {
    Pixel *data = (Pixel *) malloc(sizeof(Pixel) * width * height);

    for (int i = 0; i < width * height; i++) {
        data[i].blue =
        data[i].green =
        data[i].red =
                (unsigned char) (pattern[i]);
    }

    return data;
}
