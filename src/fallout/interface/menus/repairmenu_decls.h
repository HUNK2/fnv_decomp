// Source layout: RepairMenu. PC corrections are in generate_headers.py.
#ifndef FNV_REPAIRMENU_DECLS_H
#define FNV_REPAIRMENU_DECLS_H

#include "layout_support.h"
#include "ListBox_ItemChange___.h"
#include "Menu.h"
#pragma pack(push, 4)
class RepairMenu : public Menu
{
  public:
    Tile* m_pTiles[13];                   // +0x28
    ListBox_ItemChange___ m_kRepairList;  // +0x5C
    int GetClass();
    void AssignTileByID(int tileID, Tile* tile);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RepairMenu) == 0x8C);
FNV_STATIC_ASSERT(offsetof(RepairMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(RepairMenu, m_kRepairList) == 0x5C);
#endif
