#include <math.h>

#include "../headers/marble.h"
#include "../headers/clouds.h"
#include "../headers/hsl.h"
#include "../headers/turbulence.h"
#include "../headers/texture.h"

// Generates Marble RGB texture.
RGB *generateMarble(int width, int height, int layers, double yRepetitionFactor, double xRepetitionFactor, double twistFactor) {
    int size = (int) pow(2, layers);
    double *pattern = turbulencePattern(width, height, size);

    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = i / height;

        double repetitionFactors = xRepetitionFactor * x / width + yRepetitionFactor * y / height;
        double xyFactor = repetitionFactors + twistFactor * pattern[i] / 256.0;
        pattern[i] = 256 * fabs(sin(xyFactor * M_PI));
    }

    RGB *texture = generateBMPTexture(pattern, width, height);

    return texture;
}
