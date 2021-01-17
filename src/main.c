#include "bmp.h"
#include "noise.h"
//#include "types/bmp.h"

int main(void) {
//    BMP *obrazek = loadBMP("obrazek.bmp");
    BMP *obrazek = generateBMPFile(createNoise(200, 200), 200, 200);
    saveBMP("zapisany.bmp", obrazek);
}
