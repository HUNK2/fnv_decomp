// Source layout: ItemModMenu. PC corrections are in generate_headers.py.
#ifndef FNV_ITEMMODMENU_H
#define FNV_ITEMMODMENU_H

#include "layout_support.h"
#include "ListBox_ItemChange___.h"
#include "Menu.h"
#pragma pack(push, 4)
class ItemModMenu : public Menu
{
  public:
    Tile* m_pTiles[14];                 // +0x28
    ListBox_ItemChange___ m_kItemList;  // +0x60
    int GetClass();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ItemModMenu) == 0x90);
FNV_STATIC_ASSERT(offsetof(ItemModMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(ItemModMenu, m_kItemList) == 0x60);
#endif
