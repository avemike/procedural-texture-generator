//
// Created by avemike on 19.01.2021.
//

#include <stdlib.h>
#include <string.h>
#include "../headers/smoothNoise.h"
#include "../headers/noise.h"

double smooth(double *texture, double x, double y, int noiseWidth, int noiseHeight) {
    double fractionX = x - (int) x;
    double fractionY = y - (int) y;

    //wrap around
    int x1 = ((int) x + noiseWidth) % noiseWidth;
    int y1 = ((int) y + noiseHeight) % noiseHeight;

    //neighbor values
    int x2 = (x1 + noiseWidth - 1) % noiseWidth;
    int y2 = (y1 + noiseHeight - 1) % noiseHeight;

    double value = 0.0;
    value += fractionX * fractionY * (texture[y1 * noiseWidth + x1]);
    value += (1 - fractionX) * fractionY * (texture[y1 * noiseWidth + x2]);
    value += fractionX * (1 - fractionY) * (texture[y2 * noiseWidth + x1]);
    value += (1 - fractionX) * (1 - fractionY) * (texture[y2 * noiseWidth + x2]);

    return value;
}

double *smoothNoisePattern(int width, int height, double size) {
    double *noisePatternOutput = noisePattern(width, height);
    double *noisePatternCopy = (double *) malloc(sizeof(double) * width * height);
    memcpy(noisePatternCopy, noisePatternOutput, sizeof(double) * width * height);

    for (int i = 0; i < height * width; i++) {
        double x = (i % width) / size;
        double y = (double) (i / width) / size;

        //get fractional part of x and y
        double fractX = x - (int) x;
        double fractY = y - (int) y;

        //wrap around
        int x1 = ((int) x + width) % width;
        int y1 = ((int) y + height) % height;

        //neighbor values
        int x2 = (x1 + width - 1) % width;
        int y2 = (y1 + height - 1) % height;

        //smooth the noise with bilinear interpolation
        double value = 0.0;
        value += fractX * fractY * noisePatternCopy[y1 * width + x1];
        value += (1 - fractX) * fractY * noisePatternCopy[y1 * width + x2];
        value += fractX * (1 - fractY) * noisePatternCopy[y2 * width + x1];
        value += (1 - fractX) * (1 - fractY) * noisePatternCopy[y2 * width + x2];

        noisePatternOutput[(int) ((y * size) * width + (x * size))] = value;
    }

    return noisePatternOutput;
}