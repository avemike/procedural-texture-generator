#include <stdlib.h>
#include <time.h>

#include "bmp.h"

//
// Created by avemike on 16.01.2021.
//


Pixel *createNoise(int width, int height) {
    Pixel *data = (Pixel *) malloc(sizeof(Pixel) * width * height);

    // random generator helpers
    int seed;
    time_t tt;
    seed = time(&tt);
    srand(seed);
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            unsigned char random = rand() % 256;
            data[column + row * width].blue = random;
            data[column + row * width].green = random;
            data[column + row * width].red = random;
        }
    }

    return data;
}

// Returns array of doubles, each equal (0..1)
double *noisePattern(int width, int height) {
    double *texturePattern = (double *) malloc(width * height * sizeof(double));

    int seed;
    time_t tt;
    seed = time(&tt);
    srand(seed);

    for (int i = 0; i < height * width; i++)
        texturePattern[i] = (rand() % 32768) / 32768.0;

    return texturePattern;
}