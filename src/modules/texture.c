//
// Created by avemike on 25.01.2021.
//

#include <stdlib.h>
#include "texture.h"

Pixel *generateBMPTexture(double *pattern, int width, int height) {
    Pixel *data = (Pixel *) malloc(sizeof(Pixel) * width * height);

    for (int i = 0; i < width * height; i++) {
        data[i].blue =
        data[i].green =
        data[i].red =
                (unsigned char) (pattern[i] * 256);
    }

    return data;
}
