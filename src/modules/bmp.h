#include "../types/bmp.h"

#ifndef _BMP_MODULE_
#define _BMP_MODULE_

BMP *loadBMP(const char *bmpFileIn);

void saveBMP(const char *bmpFileOut, BMP bmpInstance);

#endif
