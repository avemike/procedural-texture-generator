#include <stdlib.h>
#include <time.h>

#include "../headers/bmp.h"

// Returns array of doubles, each equal (0..1)
double *randomNoisePattern(int width, int height) {
    double *texturePattern = (double *) malloc(width * height * sizeof(double));

    int seed;
    time_t tt;
    seed = time(&tt);
    srand(seed);

    for (int i = 0; i < height * width; i++)
        texturePattern[i] = (rand() % 32768) / 32768.0;

    return texturePattern;
}
