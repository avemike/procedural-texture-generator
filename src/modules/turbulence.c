#include <string.h>
#include <stdlib.h>

#include "../headers/turbulence.h"
#include "../headers/smoothNoise.h"
#include "../headers/randomNoisePattern.h"

double *turbulencePattern(int width, int height, int size) {
    double *outputPattern = (double *) malloc(sizeof(double) * width * height);
    memset(outputPattern, 0, sizeof(double) * width * height);
    double *startingNoisePattern = randomNoisePattern(width, height);

    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = (int) i / width;

        double sizeCounter = size;
        while (sizeCounter >= 1) {
            outputPattern[i] +=
                    128 * smooth(startingNoisePattern, x / sizeCounter, y / sizeCounter, width, height) * sizeCounter /
                    size;
            sizeCounter /= 2;
        }
    }

    return outputPattern;
}
