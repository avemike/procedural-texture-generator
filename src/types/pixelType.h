#ifndef PIXEL_H_
#define PIXEL_H_

#pragma pack(push, 1)
typedef struct pixel {
    unsigned char blue, green, red;
}
#ifdef __linux__
    __attribute__((__packed__, aligned(1)))
#endif
        Pixel;
#pragma pack(pop)
#endif
