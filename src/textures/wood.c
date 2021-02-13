//
// Created by avemike on 28.01.2021.
//
#include <math.h>
#include "../headers/wood.h"
#include "../headers/texture.h"
#include "../headers/turbulence.h"

RGB *generateWood(const int width, const int height, const int layers) {
    int size = pow(2, layers);

    double *pattern = turbulencePattern(width, height, size);

    double twistFactor = 1;
    double repetitionFactor = 16;

    RGB *texture = generateBMPTexture(pattern, width, height);

    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = i / height;
        double xVal = (double)(x - (width / 2)) / (double) width;
        double yVal = (double)(y - (height / 2)) /(double) height;
        double distVal = sqrt(pow(xVal, 2) + pow(yVal, 2)) + twistFactor * pattern[i] / 256;
        double sinVal = 128 * fabs(sin(2 * repetitionFactor * distVal * M_PI));
        texture[i].red = 110 + sinVal;
        texture[i].green = 40 + sinVal;
        texture[i].blue = 30;
    }


    return texture;
}