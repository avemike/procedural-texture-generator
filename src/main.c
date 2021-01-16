#include "bmp.h"
#include "types/bmp.h"

int main(void) {
    BMP *obrazek = loadBMP("obrazek.bmp");
    saveBMP("zapisany.bmp", *obrazek);
}
