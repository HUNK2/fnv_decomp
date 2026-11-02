// Source layout: BaseExtraList. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_PRIVATE_BASEEXTRALIST_H
#define FNV_MAGICCASTER_PRIVATE_BASEEXTRALIST_H

#include "magiccaster_private_layout_support.h"
class BaseExtraList
{
  public:
    void** m_ppVirtualMethodTable;           // +0x0
    BSExtraData* pHead;        // +0x4
    unsigned char iFlags[21];  // +0x8
    unsigned char layoutPadding1D[3];
    BSExtraData* GetExtraData(unsigned char type);
    BSExtraData* AddExtra(BSExtraData* extra);
};
FNV_STATIC_ASSERT(sizeof(BaseExtraList) == 0x20);
FNV_STATIC_ASSERT(offsetof(BaseExtraList, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BaseExtraList, pHead) == 0x4);
FNV_STATIC_ASSERT(offsetof(BaseExtraList, iFlags) == 0x8);
#endif
