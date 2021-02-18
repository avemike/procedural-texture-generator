#ifndef HSL_H_
#define HSL_H_

#pragma pack(push, 1)
typedef struct HSLTag {
    unsigned char hue, saturation, lightness;
}
#ifdef __linux__
    __attribute__((__packed__, aligned(1)))
#endif
        HSL;
#pragma pack(pop)
#endif
