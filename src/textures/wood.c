#include <math.h>

#include "../headers/wood.h"
#include "../headers/texture.h"
#include "../headers/turbulence.h"

// Generates Wood RGB texture.
RGB *generateWood(const int width, const int height, const int layers, double repetitionFactor, double twistFactor) {
    int size = (int) pow(2, layers);

    double *pattern = turbulencePattern(width, height, size);
    RGB *texture = generateBMPTexture(pattern, width, height);

    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = i / height;

        double xVal = (double) (x - ((double) width / 2)) / (double) width;
        double yVal = (double) (y - ((double) height / 2)) / (double) height;

        double distVal = sqrt(pow(xVal, 2) + pow(yVal, 2)) + twistFactor * pattern[i] / 256;

        double sinVal = 128 * fabs(sin(2 * repetitionFactor * distVal * M_PI));
        texture[i].red = 110 + (unsigned char) sinVal; // sinVal won't be greater than 128, so we don't have to worry about overflow
        texture[i].green = 40 + (unsigned char) sinVal;
        texture[i].blue = 30;
    }

    return texture;
}
