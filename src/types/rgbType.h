#ifndef RGB_H_
#define RGB_H_

#pragma pack(push, 1)
typedef struct RGBTag {
    unsigned char blue, green, red;
}
#ifdef __linux__
    __attribute__((__packed__, aligned(1)))
#endif
        RGB;
#pragma pack(pop)
#endif
