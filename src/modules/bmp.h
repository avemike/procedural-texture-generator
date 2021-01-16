#include "../types/memDescriptor.h"

#ifndef _BMP_MODULE_
#define _BMP_MODULE_

MemDescriptor *loadBMP(const char *bmpFileIn);

void saveBMP(const char *bmpFileOut, MemDescriptor m);

#endif
