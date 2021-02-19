#include <math.h>

#include "../headers/clouds.h"
#include "../types/hslType.h"
#include "../headers/hsl.h"
#include "../headers/turbulence.h"
#include "../headers/texture.h"

#define HUE 162
#define SATURATION 255

// Explanation:
// After we've got turbulence pattern generated
// We need to make it more bluish, but we cannot make it using RGB
// Adding some B(lue) and decreasing R(red)G(reen), would affect things
// Like saturation or lightness and destroy the result
// That's why we need to use HSL
// For pretty cloud-like color hue(ue) would be somewhere around 155-170 (max 255)
// and saturation will be max (255)
// Now we need only to extract lightness factor from each pixel by conversion
RGB *generateCloud(int width, int height, int layers) {
    int size = pow(2, (double) layers);
    double *pattern = turbulencePattern(width, height, size);
    RGB *texture = generateBMPTexture(pattern, width, height);

    for(int i = 0; i < width * height; i++) {
        unsigned char lightness = (int)192 + (texture[i].red / 4);
        HSL color = {HUE, SATURATION, lightness};
        RGB colorOut = HSL2RGB(color);  // Note: HSL2RGB takes color input in range 0..255.
        texture[i] = colorOut;
    }
    return texture;

}
