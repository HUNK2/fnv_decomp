
// src/havok/common/base/types/color/hkcolor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/color/hkcolor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkColor.h"

int __cdecl FUN_00cbfef0(float f);
unsigned int __cdecl PackBytesBigEndian(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

// Scales RGBA floats to 0-255 via FUN_00cbfef0 and packs them into a big-endian unsigned int via PackBytesBigEndian.
// @fnv 0x00cabb30
unsigned int __cdecl PackColorBigEndian(float afRed, float afGreen, float afBlue, float afAlpha)
{
    unsigned char ucAlpha = FUN_00cbfef0((float)(afAlpha * 255.0));
    unsigned char ucRed = FUN_00cbfef0((float)(afRed * 255.0));
    unsigned char ucGreen = FUN_00cbfef0((float)(afGreen * 255.0));
    return PackBytesBigEndian(ucRed, ucGreen, FUN_00cbfef0((float)(afBlue * 255.0)), ucAlpha);
}
