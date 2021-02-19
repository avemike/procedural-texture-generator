#include "bmpType.h"

#ifndef _BMP_MODULE_
#define _BMP_MODULE_

void saveBMP(const char *bmpFileOut, BMP *bmpInstance);
BmpHeader *generateBMPHeader(unsigned int width, unsigned int height);
BMP *generateBMPFile(RGB *data, unsigned int width, unsigned int height);

#endif
