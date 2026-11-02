// Source layout: Menu. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_TABLINE_MENU_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_TABLINE_MENU_H

#include "interface_rebase_layout_support.h"
class Menu
{
  public:
    virtual ~Menu();  // the original class is polymorphic (rtti_variants.py)
  public:
    static bool IsMenuVisible(Interface::enumMenus);
    Tile* CreateTileFromTemplate(Tile* parent, const char* name, Tile* existing);
    TileMenu* pMenu;                                        // +0x4
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;  // +0x8
    Tile* m_pMenuTile;                                        // +0x10
    int m_iModalMenuId;                                     // +0x14
    int m_iSecondaryValue;                                  // +0x18
    bool m_bIsSpecial;                                      // +0x1C
    bool m_bVisible;                                        // +0x1D
    unsigned char layoutPadding1E[2];
    int m_iMenuId;                       // +0x20
    Interface__FADE_STATE m_eFadeState;  // +0x24
};
FNV_STATIC_ASSERT(sizeof(Menu) == 0x28);
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
