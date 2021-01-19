#include "bmp.h"
#include "noise.h"
#include "bluredNoise.h"
//#include "types/bmp.h"

int main(void) {
    Pixel *texture = createBluredNoise(200, 200, 8);
    BMP *obrazek = generateBMPFile(texture, 200, 200);
    saveBMP("zapisany.bmp", obrazek);
}
