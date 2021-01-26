//
// Created by avemike on 26.01.2021.
//
#include <stdlib.h>
#include "../headers/textureToBlue.h"
#include "rgbType.h"

RGB *textureLight(RGB *texture, int width, int height, double lightFactor) {
    RGB *outputTexture = (RGB *) malloc(sizeof(RGB) * width * height);

    for (int i = 0; i < width * height; i++) {
        if(texture[i].green + lightFactor > 255)
            outputTexture[i].green = 255;
        else
            outputTexture[i].green = texture[i].green + lightFactor;

        if(texture[i].red + lightFactor > 255)
            outputTexture[i].red = 255;
        else
            outputTexture[i].red = texture[i].red + lightFactor;

        if(texture[i].blue + lightFactor > 255)
            outputTexture[i].blue = 255;
        else
            outputTexture[i].blue = texture[i].blue + lightFactor;
    }

    return outputTexture;
}