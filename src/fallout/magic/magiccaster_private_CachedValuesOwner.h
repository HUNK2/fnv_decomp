// Source layout: CachedValuesOwner. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_PRIVATE_CACHEDVALUESOWNER_H
#define FNV_MAGICCASTER_PRIVATE_CACHEDVALUESOWNER_H

#include "magiccaster_private_layout_support.h"
class CachedValuesOwner
{
  public:
    virtual float GetFloatValue0();
};
FNV_STATIC_ASSERT(sizeof(CachedValuesOwner) == 0x4);
#endif
