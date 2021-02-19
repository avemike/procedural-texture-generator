#include <stdlib.h>
#include <time.h>

#include "../headers/bmp.h"

// Completely random noise pattern!
// Returns array of doubles, each equal (0..1)
double *randomNoisePattern(int width, int height) {
    double *texturePattern = (double *) malloc(width * height * sizeof(double));

    int seed;
    time_t tt;
    seed = time(&tt);
    srand(seed);

    for (int i = 0; i < height * width; i++)
        texturePattern[i] = (double) rand() / RAND_MAX;

    return texturePattern;
}
