#include "bmp.h"
#include "noise.h"
#include "bluredNoise.h"
#include "smoothNoise.h"
//#include "types/bmp.h"

int main(void) {
    int width, height;
    width = height = 128;
    Pixel *texture = createSmoothNoise(width, height, 4);
    BMP *obrazek = generateBMPFile(texture, width, height);
    saveBMP("zapisany.bmp", obrazek);
}
