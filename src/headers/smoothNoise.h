//
// Created by avemike on 19.01.2021.
//
#include "rgbType.h"

#ifndef PROJEKT_SMOOTHNOISE_H
#define PROJEKT_SMOOTHNOISE_H

RGB *createSmoothNoise(int width, int height, int factor);
double smoothPixel(double x, double y, int noiseWidth, int noiseHeight, RGB *noise);
double *smoothNoisePattern(int width, int height, double size);
double smooth(double *texture, double x, double y, int noiseWidth, int noiseHeight);

#endif //PROJEKT_SMOOTHNOISE_H
