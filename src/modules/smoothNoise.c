//
// Created by avemike on 19.01.2021.
//

#include <stdlib.h>
#include <string.h>
#include "smoothNoise.h"
#include "noise.h"

double smoothPixel(double x, double y, int noiseWidth, int noiseHeight, Pixel *noise) {
    double fractionX = x - (int) x;
    double fractionY = y - (int) y;

    //wrap around
    int x1 = ((int) x + noiseWidth) % noiseWidth;
    int y1 = ((int) y + noiseHeight) % noiseHeight;

    //neighbor values
    int x2 = (x1 + noiseWidth - 1) % noiseWidth;
    int y2 = (y1 + noiseHeight - 1) % noiseHeight;

    double value = 0.0;
    value += fractionX * fractionY * (noise[y1 * noiseWidth + x1].green);
    value += (1 - fractionX) * fractionY * (noise[y1 * noiseWidth + x2].green);
    value += fractionX * (1 - fractionY) * (noise[y2 * noiseWidth + x1].green);
    value += (1 - fractionX) * (1 - fractionY) * (noise[y2 * noiseWidth + x2].green);

    return value;
}


Pixel *createSmoothNoise(int width, int height, int factor) {
    Pixel *temp = createNoise(width, height);
    Pixel *data = (Pixel *) malloc(sizeof(Pixel) * width * height);
    memcpy(data, temp, (sizeof(Pixel) * width * height));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            data[x + width * y].green =
            data[x + width * y].blue =
            data[x + width * y].red =
                    (unsigned char) (smoothPixel((double) x / factor, (double) y / factor, width, height, temp));
        }
    }

    return data;
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