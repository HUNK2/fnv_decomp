// Source layout: CachedValuesOwner. PC corrections are in generate_headers.py.
#ifndef FNV_CACHEDVALUESOWNER_H
#define FNV_CACHEDVALUESOWNER_H
#include "layout_support.h"
#pragma pack(push, 4)
class CachedValuesOwner
{
  public:
    virtual float GetFloatValue0();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CachedValuesOwner) == 0x4);
#endif
