#include "bmp.h"
#include "turbulence.h"
#include "smoothNoise.h"
#include "texture.h"

int main(void) {
    int width, height;
    width = height = 128;

    double *pattern = smoothNoisePattern(width, height, 4);
    Pixel *texture = generateBMPTexture(pattern, width, height);
    BMP *obrazek = generateBMPFile(texture, width, height);
    saveBMP("zapisany.bmp", obrazek);
    return 0;
}
