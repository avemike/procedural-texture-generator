//
// Created by avemike on 27.01.2021.
//

#include "../headers/marble.h"
#include <math.h>
#include "../headers/cloud.h"
#include "../types/hslType.h"
#include "../headers/hsl.h"
#include "../headers/turbulence.h"
#include "../headers/texture.h"

RGB *generateMarble(int width, int height, int layers) {
    int size = pow(2, layers);
    double *pattern = turbulencePattern(width, height, size);

    double twistFactor = 3;
    double xRepetitionFactor = 2;
    double yRepetitionFactor = 3.3;

    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = i / height;
        double repetitionFactors = xRepetitionFactor * x / width + yRepetitionFactor * y / height;
        double xyValue = repetitionFactors + twistFactor * pattern[i] / 256.0;
        pattern[i] = 256 * fabs(sin(xyValue * M_PI));
    }

    RGB *texture = generateBMPTexture(pattern, width, height);

    return texture;

}