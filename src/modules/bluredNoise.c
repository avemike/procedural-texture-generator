//
// Created by avemike on 17.01.2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"
#include "noise.h"

double calcHue(Pixel *pixel) {
    return (double) (pixel->red + pixel->blue + pixel->green) / 3;
}

// Variable Factor adjust how blured is image
Pixel *createBluredNoise(int width, int height, int blur) {
    Pixel *data = createNoise(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            int left = (x + width - 1) % width;
            int bottom = (y + height - 1) % height;

            int right = (x + width + 1) % width;
            int top = (y + height + 1) % height;

            int val;

            // Assume green == blue == red
            val += data[left + y*width].green;
            val += data[x + y*width].green;
            val += data[right + y*width].green;
            val += data[left + top*width].green;
            val += data[x + top*width].green;
            val += data[right + top*width].green;
            val += data[left + bottom*width].green;
            val += data[x + bottom*width].green;
            val += data[right + bottom*width].green;

            val = (val / 9) % 256;
            data[x + y*width].green = data[x + y*width].blue = data[x + y*width].red = val;
        }
    }

    return data;
}