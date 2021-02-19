#include <stdlib.h>

#include "../headers/texture.h"

// RETURN: RGB array, based on pattern array
// Example:
//      INPUT: double *pattern = { 100, 5}
//      OUTPUT: RGB *texture = { { red: 100, green: 100, blue: 100 }, { red: 15, green: 15, blue = 15 }} }
RGB *generateBMPTexture(const double *pattern, int width, int height) {
    RGB *data = (RGB *) malloc(sizeof(RGB) * width * height);

    for (int i = 0; i < width * height; i++) {
        data[i].blue =
        data[i].green =
        data[i].red =
                (unsigned char) (pattern[i]);
    }

    return data;
}
