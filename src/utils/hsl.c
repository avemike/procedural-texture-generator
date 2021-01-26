//
// Created by avemike on 26.01.2021.
//

#include "../headers/hsl.h"
#include "hslType.h"
#include "rgbType.h"

#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))


RGB HSL2RGB(HSL colorHSL) {
    float r, g, b, h, s, l; //this function works with floats between 0 and 1
    float temp1, temp2, tempr, tempg, tempb;
    h = colorHSL.H / 256.0;
    s = colorHSL.S / 256.0;
    l = colorHSL.L / 256.0;

    // If saturation is 0, the color is a shade of grey
    if (s == 0) r = g = b = l;
    // If saturation > 0, more complex calculations are needed
    else {
        // set the temporary values
        if (l < 0.5) temp2 = l * (1 + s);
        else temp2 = (l + s) - (l * s);
        temp1 = 2 * l - temp2;
        tempr = h + 1.0 / 3.0;
        if (tempr > 1.0) tempr--;
        tempg = h;
        tempb = h - 1.0 / 3.0;
        if (tempb < 0.0) tempb++;

        // RED
        if (tempr < 1.0 / 6.0) r = temp1 + (temp2 - temp1) * 6.0 * tempr;
        else if (tempr < 0.5) r = temp2;
        else if (tempr < 2.0 / 3.0) r = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - tempr) * 6.0;
        else r = temp1;

        // GREEN
        if (tempg < 1.0 / 6.0) g = temp1 + (temp2 - temp1) * 6.0 * tempg;
        else if (tempg < 0.5) g = temp2;
        else if (tempg < 2.0 / 3.0) g = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - tempg) * 6.0;
        else g = temp1;

        // BLUE
        if (tempb < 1.0 / 6.0) b = temp1 + (temp2 - temp1) * 6.0 * tempb;
        else if (tempb < 0.5) b = temp2;
        else if (tempb < 2.0 / 3.0) b = temp1 + (temp2 - temp1) * ((2.0 / 3.0) - tempb) * 6.0;
        else b = temp1;
    }

    RGB colorRGB;
    colorRGB.red = (int) (r * 255.0);
    colorRGB.green = (int) (g * 255.0);
    colorRGB.blue = (int) (b * 255.0);
    return colorRGB;
}

HSL RGB2HSL(RGB colorRGB) {
    float r, g, b, h = 0, s = 0, l; // between 0 and 1
    r = colorRGB.red / 256.0;
    g = colorRGB.green / 256.0;
    b = colorRGB.blue / 256.0;

    float maxColor = MAX(r, MAX(g, b));
    float minColor = MIN(r, MIN(g, b));

    if (minColor == maxColor) {
        h = s = 0;
        l = r;
    } else if(0) {
        l = (minColor + maxColor) / 2;

        if (l < 0.5) s = (maxColor - minColor) / (maxColor + minColor);
        if (l >= 0.5) s = (maxColor - minColor) / (2.0 - maxColor - minColor);

        if (r == maxColor) h = (g - b) / (maxColor - minColor);
        if (g == maxColor) h = 2.0 + (b - r) / (maxColor - minColor);
        if (b == maxColor) h = 4.0 + (r - g) / (maxColor - minColor);

        h /= 6; //to bring it to a number between 0 and 1
        if (h < 0) h += 1;
    }

    HSL colorHSL;
    colorHSL.H = (int) h * 255.0;
    colorHSL.S = (int) s * 255.0;
    colorHSL.L = (int) l * 255.0;
    return colorHSL;
}
