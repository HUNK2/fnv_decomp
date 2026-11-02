// Source layout: Tile::Action. PC corrections are in generate_headers.py.
#ifndef FNV_TILE__ACTION_H
#define FNV_TILE__ACTION_H

#include "layout_support.h"
#pragma pack(push, 4)
class Tile__Action
{
  public:
    void** m_ppVirtualMethodTable;                   // +0x0
    Tile__VALUE_ACTION eActionType;    // +0x4
    Tile__Action* m_pActionSuccessor;  // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Tile__Action) == 0xC);
FNV_STATIC_ASSERT(offsetof(Tile__Action, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(Tile__Action, eActionType) == 0x4);
FNV_STATIC_ASSERT(offsetof(Tile__Action, m_pActionSuccessor) == 0x8);
#endif
