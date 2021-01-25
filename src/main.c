#include "headers/bmp.h"
#include "headers/turbulence.h"
#include "headers/smoothNoise.h"
#include "headers/texture.h"

int main(void) {
    int width, height;
    width = height = 128;

    double *pattern = turbulencePattern(width, height, 64);
    Pixel *texture = generateBMPTexture(pattern, width, height);
    BMP *obrazek = generateBMPFile(texture, width, height);
    saveBMP("zapisany.bmp", obrazek);
    return 0;
}
