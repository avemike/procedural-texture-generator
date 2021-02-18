#include "../headers/smoothNoise.h"

double smooth(const double *texture, double x, double y, int noiseWidth, int noiseHeight) {
    double fractionX = x - (int) x;
    double fractionY = y - (int) y;

    //wrap around
    int x1 = ((int) x + noiseWidth) % noiseWidth;
    int y1 = ((int) y + noiseHeight) % noiseHeight;

    //neighbor values
    int x2 = (x1 + noiseWidth - 1) % noiseWidth;
    int y2 = (y1 + noiseHeight - 1) % noiseHeight;

    double value = 0.0;
    value += fractionX * fractionY * (texture[y1 * noiseWidth + x1]);
    value += (1 - fractionX) * fractionY * (texture[y1 * noiseWidth + x2]);
    value += fractionX * (1 - fractionY) * (texture[y2 * noiseWidth + x1]);
    value += (1 - fractionX) * (1 - fractionY) * (texture[y2 * noiseWidth + x2]);

    return value;
}
