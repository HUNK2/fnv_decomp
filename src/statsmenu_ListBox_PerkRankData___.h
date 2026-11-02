// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/ListBox_PerkRankData___.h
#ifndef FNV_LISTBOX_PERKRANKDATA____H
#define FNV_LISTBOX_PERKRANKDATA____H

#include "statsmenu_layout_support.h"
#include "statsmenu_ListBoxBase.h"
class ListBox_PerkRankData___ : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem_PerkRankData___*> bSSimpleList_ListBoxItem_PerkRankData______Component;  // +0x4
    Tile* m_pListTile;                                                                                // +0xC
    Tile* m_pSelectedTile;                                                                            // +0x10
    Tile* m_pHighlightedTile;                                                                         // +0x14
    const char* pTemplateName;                                                                        // +0x18
    unsigned short m_usSelectedIndex;                                                                 // +0x1C
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned char layoutPadding2E[2];
};
FNV_STATIC_ASSERT(sizeof(ListBox_PerkRankData___) == 0x30);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, bSSimpleList_ListBoxItem_PerkRankData______Component) == 0x4);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_pListTile) == 0xC);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_pSelectedTile) == 0x10);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_pHighlightedTile) == 0x14);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, pTemplateName) == 0x18);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_usSelectedIndex) == 0x1C);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_fFirstListValue) == 0x20);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_fSecondListValue) == 0x24);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, m_fThirdListValue) == 0x28);
FNV_STATIC_ASSERT(offsetof(ListBox_PerkRankData___, usFlags) == 0x2C);
#endif
