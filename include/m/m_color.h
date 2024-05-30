#ifndef M_COLOR_H
#define M_COLOR_H

#include <rvl/GX.h>

struct mColor {

    mColor() { rgba = 0xFFFFFFFF; }
    mColor(u8 red, u8 green, u8 blue, u8 alpha) { r = red; g = green; b = blue; a = alpha; }
    mColor(u32 color) { rgba = color; }

    union {
        struct {
            u8 r;
            u8 g;
            u8 b;
            u8 a;
        };
        u32 rgba;
    };
};
#endif
