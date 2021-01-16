#include "bmp.h"
#include "noise.h"
//#include "types/bmp.h"

int main(void) {
//    BMP *obrazek = loadBMP("obrazek.bmp");
    BMP *obrazek = createNoise(200, 200);
    saveBMP("zapisany.bmp", *obrazek);
}
