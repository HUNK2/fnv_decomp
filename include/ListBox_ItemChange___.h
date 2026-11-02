// include/ListBox_ItemChange___.h: declares ListBox_ItemChange___
#ifndef FNV_LISTBOX_ITEMCHANGE____H
#define FNV_LISTBOX_ITEMCHANGE____H

#include "layout_support.h"
#include "ListBoxBase.h"
#pragma pack(push, 4)
class ListBox_ItemChange___ : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem_ItemChange___*> bSSimpleList_ListBoxItem_ItemChange______Component;  // +0x4
    Tile* m_pListTile;                                                                            // +0xC
    Tile* m_pSelectedTile;                                                                        // +0x10
    Tile* m_pHighlightedTile;                                                                     // +0x14
    const char* pTemplateName;                                                                    // +0x18
    unsigned short m_usSelectedIndex;                                                             // +0x1C
    unsigned short layoutPadding1E;
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned short layoutPadding2E;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ListBox_ItemChange___) == 0x30);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, bSSimpleList_ListBoxItem_ItemChange______Component) == 0x4);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_pListTile) == 0xC);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_pSelectedTile) == 0x10);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_pHighlightedTile) == 0x14);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, pTemplateName) == 0x18);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_usSelectedIndex) == 0x1C);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_fFirstListValue) == 0x20);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_fSecondListValue) == 0x24);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, m_fThirdListValue) == 0x28);
FNV_STATIC_ASSERT(offsetof(ListBox_ItemChange___, usFlags) == 0x2C);
#endif
