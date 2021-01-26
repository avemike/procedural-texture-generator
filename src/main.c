#include "headers/bmp.h"
#include "headers/turbulence.h"
#include "headers/smoothNoise.h"
#include "headers/texture.h"
#include "headers/textureToBlue.h"
#include "headers/textureLight.h"
#include "headers/hsl.h"

int main(void) {
    int width, height;
    width = height = 512;

    double *pattern = turbulencePattern(width, height, 16);
    RGB *texture = generateBMPTexture(pattern, width, height);
    for(int i = 0; i < width * height; i++) {
        unsigned char H = 162;
        unsigned char S = 255;
        unsigned char L = (int)192 + (texture[i].red / 4);
        HSL color = {H, S, L};
        RGB colorOut = HSL2RGB(color);
        texture[i] = colorOut;
    }

    BMP *obrazek = generateBMPFile(texture, width, height);
    saveBMP("zapisany.bmp", obrazek);
    return 0;
}
