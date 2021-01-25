//
// Created by avemike on 17.01.2021.
//
#include "bmpType.h"
#include "pixelType.h"
#include "../headers/noise.h"

// x1 < x2 and y1 < y2. pixelsNum gets modified
int calcVal(int x1, int y1, int x2, int y2, int width, const Pixel* data, int *pixelsNum) {
    int val = 0;
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            (*pixelsNum)++;
            val += data[x + y * width].green;
        }
    }
    return val;
}
// Variable Factor adjust how blured is image
Pixel *createBluredNoise(int width, int height, int blur) {
    Pixel *data = createNoise(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int x1 = (x + width - blur) % width;
            int x2 = (x + width + blur) % width;
            int y1 = (y + height - blur) % height;
            int y2 = (y + height + blur) % height;

            int val = 0, pixelsNum = 0;

            val += calcVal(x, y, x2, y2, width, data, &pixelsNum);
            val += calcVal(x1, y, x, y2, width, data, &pixelsNum);
            val += calcVal(x, y1, x2, y, width, data, &pixelsNum);
            val += calcVal(x1, y1, x, y, width, data, &pixelsNum);

            val = (val / pixelsNum) % 256;
            data[x + y * width].green = data[x + y * width].blue = data[x + y * width].red = val;
        }
    }

    return data;
}