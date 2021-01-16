#include "bmpHeader.h"
#include "pixel.h"

#ifndef BMP_H_
#define BMP_H_

#pragma pack(push, 1)
typedef struct bmp {
    BmpHeader header;
    Pixel data[];
}
#ifdef __linux__
    __attribute__((__packed__, aligned(1)))
#endif
        BMP;
#pragma pack(pop)

#endif
