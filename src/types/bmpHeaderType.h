#ifndef BMPHEADER_H_
#define BMPHEADER_H_

typedef unsigned char byte;
typedef signed char si1B;
typedef signed short si2B;
typedef signed int si4B;

#pragma pack(push, 1)
typedef // ## BMPv3 HEADER ###################### //
struct BmpHeaderTAG // sizeof(BmpHeader) must be 54 [Byte] //
{ // ====================================== //
//// FILE HEADER /////// the very basic (main) file header ////
    si1B id[2]; /* 0x4D42 must be here, meaning 'B'and'M' */// ((fixed))
    si4B fileSize; /* (xDim * yDim * 3) + 54L + padding */// ((variable))
    si2B reserved[2]; /* ignore or set-zero */// ((ignored))
    si4B dataOffset; /* 54 [Byte] ((expected)) */// ((fixed))@Write ((variable))@Read
//// DIB HEADER //////// 'device-independent bitmap' header ////
    si4B DIBHeaderSize; /* should be 40 for us *//* 14 + 40 = 54 */// ((fixed))
    /* version-wise values */
/* 12: (BMPv2) Windows 2.x + OS/2 1.x */
/* 40: (BMPv3) Windows 3.x + Windows NT */
/* 108: (BMPv4) Windows 4.x (Windows 95) */
    si4B pixWidth; /* xDim, horizontal size */// ((variable))
    si4B pixHeight; /* yDim, vertical size */// ((variable))
    si2B biPlanes; /* 1 assumed and hard-coded */// ((fixed))
    si2B bitsPerPixel; /* 24 assumed and hard-coded */// ((fixed))
    si4B biCompression; /* 0 assumed and hard-coded */// ((fixed))
    si4B biImageByteSize; /* ignore or set-zero, memset(_,0x0,_) */// ((ignored))
    si4B biXPixPerMeter; /* ignore or set-zero, memset(_,0x0,_) */// ((ignored))
    si4B biYPixPerMeter; /* ignore or set-zero, memset(_,0x0,_) */// ((ignored))
    si4B biClrUsed; /* ignore or set-zero, memset(_,0x0,_) */// ((ignored))
    si4B biClrImportant; /* ignore or set-zero, memset(_,0x0,_) */// ((ignored))
}
#ifdef __linux__
    __attribute__((__packed__, aligned(1)))
#endif
        BmpHeader;
#pragma pack(pop)

#endif
