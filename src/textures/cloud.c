//
// Created by avemike on 27.01.2021.
//
#include <math.h>
#include "../headers/cloud.h"
#include "../types/hslType.h"
#include "../headers/hsl.h"
#include "../headers/turbulence.h"
#include "../headers/texture.h"

// Explanation:
// After we've got turbulence pattern generated
// We need to make it more bluish, but we cannot make it using RGB
// Adding some B(lue) and decreasing R(red)G(reen), would affect things
// Like saturation or lightness and destroy the result
// That's why we need to use HSL
// For pretty cloud-like color H(ue) would be somewhere around 155-170 (max 255)
// and saturation will be max (255)
// Now we need only to extract lightness factor from each pixel by conversion
RGB *generateCloud(int width, int height, int layers) {
    int size = pow(2, layers);
    double *pattern = turbulencePattern(width, height, size);
    RGB *texture = generateBMPTexture(pattern, width, height);
    for(int i = 0; i < width * height; i++) {
        unsigned char H = 162;
        unsigned char S = 255;
        unsigned char L = (int)192 + (texture[i].red / 4);
        HSL color = {H, S, L};
        RGB colorOut = HSL2RGB(color);
        texture[i] = colorOut;
    }
    return texture;

}