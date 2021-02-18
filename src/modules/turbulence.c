//
// Created by avemike on 19.01.2021.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/turbulence.h"
#include "../headers/smoothNoise.h"
#include "../headers/noise.h"

double *turbulencePattern(int width, int height, int size) {
    double *outputPattern = (double *) malloc(sizeof(double) * width * height);
    memset(outputPattern, 0, sizeof(double) * width * height);
    double *startingNoisePattern = noisePattern(width, height);

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
