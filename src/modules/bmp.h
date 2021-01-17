#include "../types/bmp.h"

#ifndef _BMP_MODULE_
#define _BMP_MODULE_

BMP *loadBMP(const char *bmpFileIn);

void saveBMP(const char *bmpFileOut, BMP *bmpInstance);

BmpHeader *generateBMPHeader(unsigned int width, unsigned int height);

BMP *generateBMPFile(Pixel *data, unsigned int width, unsigned int height);

#endif
