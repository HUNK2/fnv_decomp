// Source layout: Menu. PC corrections are in generate_headers.py.
#ifndef FNV_MENU_H
#define FNV_MENU_H
#include "layout_support.h"
#pragma pack(push, 4)
class Menu
{
  public:
    void** m_ppVirtualMethodTable;                                        // +0x0
    TileMenu* pMenu;                                        // +0x4
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;  // +0x8
    Tile* m_pMenuTile;                                        // +0x10
    int m_iModalMenuId;                                     // +0x14
    int m_iSecondaryValue;                                  // +0x18
    bool m_bIsSpecial;                                      // +0x1C
    bool m_bVisible;                                        // +0x1D
    unsigned short layoutPadding1E;
    int m_iMenuId;                       // +0x20
    Interface__FADE_STATE m_eFadeState;  // +0x24
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Menu) == 0x28);
FNV_STATIC_ASSERT(offsetof(Menu, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(Menu, pMenu) == 0x4);
FNV_STATIC_ASSERT(offsetof(Menu, m_kTileTemplateList) == 0x8);
FNV_STATIC_ASSERT(offsetof(Menu, m_pMenuTile) == 0x10);
FNV_STATIC_ASSERT(offsetof(Menu, m_iModalMenuId) == 0x14);
FNV_STATIC_ASSERT(offsetof(Menu, m_iSecondaryValue) == 0x18);
FNV_STATIC_ASSERT(offsetof(Menu, m_bIsSpecial) == 0x1C);
FNV_STATIC_ASSERT(offsetof(Menu, m_bVisible) == 0x1D);
FNV_STATIC_ASSERT(offsetof(Menu, m_iMenuId) == 0x20);
FNV_STATIC_ASSERT(offsetof(Menu, m_eFadeState) == 0x24);
#endif
