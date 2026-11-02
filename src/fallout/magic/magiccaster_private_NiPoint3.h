// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_PRIVATE_NIPOINT3_H
#define FNV_MAGICCASTER_PRIVATE_NIPOINT3_H
#include "magiccaster_private_layout_support.h"
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    static const NiPoint3 ZERO;
};
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);
#endif
