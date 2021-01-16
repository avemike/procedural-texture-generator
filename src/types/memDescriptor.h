#include "bmpHeader.h"
#include "pixel.h"

#ifndef MEM_DESCRIPTOR_H_
#define MEM_DESCRIPTOR_H_

typedef struct {
    Pixel *pixels;
    BmpHeader header;
} MemDescriptor;

#endif