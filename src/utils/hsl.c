#include "../headers/hsl.h"
#include "hslType.h"
#include "rgbType.h"

#define MIN(a, b) (( (a) < (b) ) ? (a) : (b))
#define MAX(a, b) (( (a) > (b) ) ? (a) : (b))

// Takes HSL and return RGB
// !    Important: every factor is in range 0..255, hue, lightness, saturation.
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
