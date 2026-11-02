// Source layout: TESRegionObjectBase. PC corrections are in generate_headers.py.
#ifndef FNV_TESREGIONOBJECTBASE_H
#define FNV_TESREGIONOBJECTBASE_H

#include "layout_support.h"
#pragma pack(push, 4)
class TESRegionObjectBase
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESRegionObjectBase) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESRegionObjectBase, m_ppVirtualMethodTable) == 0x0);
#endif
