//
// Created by avemike on 19.01.2021.
//
#include "pixel.h"

#ifndef PROJEKT_SMOOTHNOISE_H
#define PROJEKT_SMOOTHNOISE_H

Pixel *createSmoothNoise(int width, int height, int factor);
double smoothPixel(double x, double y, int noiseWidth, int noiseHeight, Pixel *noise);
double *smoothNoisePattern(int width, int height, double size);

#endif //PROJEKT_SMOOTHNOISE_H
