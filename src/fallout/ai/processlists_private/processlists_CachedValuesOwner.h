// Source layout: CachedValuesOwner. PC corrections are in generate_headers.py.
#ifndef FNV_CACHEDVALUESOWNER_H
#define FNV_CACHEDVALUESOWNER_H

#include "processlists_layout_support.h"
class CachedValuesOwner
{
  public:
    virtual float GetFloatValue0();
};
FNV_STATIC_ASSERT(sizeof(CachedValuesOwner) == 0x4);
#endif
