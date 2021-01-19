#include "bmp.h"
#include "noise.h"
#include "bluredNoise.h"
//#include "types/bmp.h"

int main(void) {
    int width, height;
    width = height = 200;
    Pixel *texture = createBluredNoise(width, height, 2);
    BMP *obrazek = generateBMPFile(texture, width, height);
    saveBMP("zapisany.bmp", obrazek);
}
