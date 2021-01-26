//
// Created by avemike on 26.01.2021.
//

#include <stdlib.h>
#include "../headers/textureToBlue.h"
#include "rgbType.h"

RGB *textureToBlue(RGB *texture, int width, int height, double blueFactor) {
    RGB *outputTexture = (RGB *) malloc(sizeof(RGB) * width * height);

    for (int i = 0; i < width * height; i++) {
        outputTexture[i].green = outputTexture[i].red = texture[i].blue * blueFactor;
        outputTexture[i].blue = texture[i].blue;
    }

    return outputTexture;
}