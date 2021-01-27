#include "headers/bmp.h"
#include "headers/turbulence.h"
#include "headers/smoothNoise.h"
#include "headers/texture.h"
#include "headers/textureToBlue.h"
#include "headers/hsl.h"
#include "headers/cloud.h"
#include "headers/marble.h"

int main(void) {
    int width, height;
    width = height = 512;

    RGB* texture = generateMarble(width, height, 7);
    BMP *obrazek = generateBMPFile(texture, width, height);
    saveBMP("zapisany.bmp", obrazek);
    return 0;
}
