#include <math.h>
#include "../headers/smoothNoise.h"

double lerp(const double lo, const double hi, const double t) { return lo * (1 - t) + hi * t; }
double smoothstep(const double t) { return t * t * (3 - 2 * t); }

double smooth(const double *texture, double x, double y, int noiseWidth, int noiseHeight) {
    int x0 = floor(x);
    int y0 = floor(y);

    double fractionX = x - x0;
    double fractionY = y - y0;

    int x1 = (x0 + 1) % (noiseWidth - 1);
    int y1 = (y0 + 1) % (noiseHeight - 1);

    // 01 - upper left      11 - upper right
    // 00 - bottom left     10 - bottom right
    const double val_00 = texture[y0 * (noiseWidth) + x0];
    const double val_10 = texture[y0 * (noiseWidth) + x1];
    const double val_01 = texture[y1 * (noiseWidth) + x0];
    const double val_11 = texture[y1 * (noiseWidth) + x1];

    // remapping of tx and ty using the Smoothstep function
    double sx = smoothstep(fractionX);
    double sy = smoothstep(fractionY);

    // linearly interpolate values along the x axis
    double nx0 = lerp(val_00, val_10, sx);
    double nx1 = lerp(val_01, val_11, sx);

    // linearly interpolate the nx0/nx1 along their y axis
    return lerp(nx0, nx1, sy);
}
