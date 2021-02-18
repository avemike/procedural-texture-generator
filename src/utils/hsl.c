#include "../headers/hsl.h"
#include "hslType.h"
#include "rgbType.h"

#define MIN(a, b) (( (a) < (b) ) ? (a) : (b))
#define MAX(a, b) (( (a) > (b) ) ? (a) : (b))

RGB HSL2RGB(HSL colorHSL) {
    double red, green, blue, hue, saturation, lightness; // this function works with floats between 0 and 1
    double temp1, temp2, temp_red, temp_green, temp_blue;

    hue = colorHSL.hue / 256.0;
    saturation = colorHSL.saturation / 256.0;
    lightness = colorHSL.lightness / 256.0;

    // if saturation is 0, the color is a shade of grey
    if (saturation == 0) red = green = blue = lightness;

    // If saturation > 0
    else {
        // set the temporary values
        if (lightness < 0.5) temp2 = lightness * (1 + saturation);
        else temp2 = (lightness + saturation) - (lightness * saturation);

        temp1 = 2 * lightness - temp2;

        temp_red = hue + 1.0 / 3.0;
        temp_green = hue;
        temp_blue = hue - 1.0 / 3.0;

        if (temp_red > 1.0) temp_red--;
        if (temp_blue < 0.0) temp_blue++;

        // RED
        if (temp_red < 1.0 / 6.0) red = temp1 + (temp2 - temp1) * 6.0 * temp_red;
        else if (temp_red < 0.5) red = temp2;
        else if (temp_red < 2.0 / 3.0) red = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - temp_red) * 6.0;
        else red = temp1;

        // GREEN
        if (temp_green < 1.0 / 6.0) green = temp1 + (temp2 - temp1) * 6.0 * temp_green;
        else if (temp_green < 0.5) green = temp2;
        else if (temp_green < 2.0 / 3.0) green = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - temp_green) * 6.0;
        else green = temp1;

        // BLUE
        if (temp_blue < 1.0 / 6.0) blue = temp1 + (temp2 - temp1) * 6.0 * temp_blue;
        else if (temp_blue < 0.5) blue = temp2;
        else if (temp_blue < 2.0 / 3.0) blue = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - temp_blue) * 6.0;
        else blue = temp1;
    }

    RGB colorRGB;
    colorRGB.red = (int) (red * 255.0);
    colorRGB.green = (int) (green * 255.0);
    colorRGB.blue = (int) (blue * 255.0);
    return colorRGB;
}

HSL RGB2HSL(RGB colorRGB) {
    float red, green, blue, hue = 0, saturation = 0, lightness; // between 0 and 1
    red = colorRGB.red / 256.0;
    green = colorRGB.green / 256.0;
    blue = colorRGB.blue / 256.0;

    float maxColor = MAX(red, MAX(green, blue));
    float minColor = MIN(red, MIN(green, blue));

    if (minColor == maxColor) {
        hue = saturation = 0;
        lightness = red;
    } else {
        lightness = (minColor + maxColor) / 2;

        if (lightness < 0.5) saturation = (maxColor - minColor) / (maxColor + minColor);
        if (lightness >= 0.5) saturation = (maxColor - minColor) / (2.0 - maxColor - minColor);

        if (red == maxColor) hue = (green - blue) / (maxColor - minColor);
        if (green == maxColor) hue = 2.0 + (blue - red) / (maxColor - minColor);
        if (blue == maxColor) hue = 4.0 + (red - green) / (maxColor - minColor);

        hue /= 6; //to bring it to a number between 0 and 1
        if (hue < 0) hue += 1;
    }

    HSL colorHSL;
    colorHSL.hue = (int) hue * 255.0;
    colorHSL.saturation = (int) saturation * 255.0;
    colorHSL.lightness = (int) lightness * 255.0;
    return colorHSL;
}
