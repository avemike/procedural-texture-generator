#include "bmp.h"

int main(void) {
    MemDescriptor *obrazek = loadBMP("obrazek.bmp");
    saveBMP("zapisany.bmp", *obrazek);
}
