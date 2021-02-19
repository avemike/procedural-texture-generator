#include <string.h>
#include <stdlib.h>

#include "../headers/turbulence.h"
#include "../headers/smoothNoise.h"
#include "../headers/randomNoisePattern.h"

// Return pattern based on composition of random patterns affected by value noise
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
                    smooth(startingNoisePattern, x / sizeCounter, y / sizeCounter, width, height) * sizeCounter;
            sizeCounter /= 2;
        }
        outputPattern[i] *= 128 / size;
  }

    return outputPattern;
}