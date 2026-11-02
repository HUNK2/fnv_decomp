// Source layout: CachedValuesOwner. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_CACHEDVALUESOWNER_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_CACHEDVALUESOWNER_H
#include "interface_rebase_layout_support.h"
class CachedValuesOwner
{
  public:
    virtual float GetFloatValue0();
};
FNV_STATIC_ASSERT(sizeof(CachedValuesOwner) == 0x4);
#endif
