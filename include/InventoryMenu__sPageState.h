// include/InventoryMenu__sPageState.h: declares InventoryMenu__sPageState
#ifndef FNV_INVENTORYMENU__SPAGESTATE_H
#define FNV_INVENTORYMENU__SPAGESTATE_H

#include "layout_support.h"
#pragma pack(push, 4)
class InventoryMenu__sPageState
{
  public:
    int m_iSelectedItemIndex;  // +0x0
    int m_iScrollOffset;       // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InventoryMenu__sPageState) == 0x8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu__sPageState, m_iSelectedItemIndex) == 0x0);
FNV_STATIC_ASSERT(offsetof(InventoryMenu__sPageState, m_iScrollOffset) == 0x4);
#endif
