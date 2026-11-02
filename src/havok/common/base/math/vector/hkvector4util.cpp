
// src/havok/common/base/math/vector/hkvector4util.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/vector/hkvector4util.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
extern __m128 g_010d4020;
extern __m128 g_010d4010;

union FloatBits
{
    __m128 value;
    unsigned int bits[4];
};

// Applies a scale and bias to four floats via SSE, then combines selected bit fields into a 32-bit unsigned integer.
// @fnv 0x00d975d0
unsigned int __cdecl PackFloatsToUInt(const __m128* apFloats)
{
    FloatBits converted;
    converted.value = _mm_add_ps(_mm_mul_ps(*apFloats, g_010d4020), g_010d4010);
    return ((converted.bits[3] & 0xffffffc0u) << 18) | ((converted.bits[2] & 0x3fc0u) << 10) |
           ((converted.bits[1] & 0x3fc0u) << 2) | ((converted.bits[0] >> 6) & 0xffu);
}
