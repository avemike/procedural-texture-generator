//
// Created by avemike on 19.01.2021.
//
#include <string.h>
#include <stdlib.h>
#include "pixel.h"
#include "turbulence.h"
#include "smoothNoise.h"
#include "noise.h"

double turbulence(double x, double y, int width, int height, Pixel *data, int size) {
    double val = 0.0;
    double sizeCounter = size;

    while (sizeCounter >= 1) {
        val += smoothPixel(x / sizeCounter, y / sizeCounter, width, height, data);
        sizeCounter /= 2;
    }
    const double output = val / (2 * size);
    return output;
}

//Pixel *createTurbulence(int width, int height, int size) {
//    double *tempPattern = noisePattern(width, height);
//
//    double *outputPattern = (double *) malloc(sizeof(Pixel) * width * height);
//    memcpy(data, temp, (sizeof(Pixel) * width * height));
//
//    double max = 0;
//    for (int y = 0; y < height; y++) {
//        for (int x = 0; x < width; x++) {
//            unsigned  char val = 0;
//            val = (unsigned char) (turbulence(x, y, width, height, temp, size));
//            max = max < val ? val : max;
//            data[x + width * y].green =
//            data[x + width * y].blue =
//            data[x + width * y].red =
//                    val * 20;
//        }
//    }
//
//    return data;
//}
