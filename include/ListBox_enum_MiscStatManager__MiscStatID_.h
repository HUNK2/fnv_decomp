// include/ListBox_enum_MiscStatManager__MiscStatID_.h: declares ListBox_enum_MiscStatManager__MiscStatID_
#ifndef FNV_LISTBOX_ENUM_MISCSTATMANAGER__MISCSTATID__H
#define FNV_LISTBOX_ENUM_MISCSTATMANAGER__MISCSTATID__H

#include "layout_support.h"
#include "ListBoxBase.h"
#pragma pack(push, 4)
class ListBox_enum_MiscStatManager__MiscStatID_ : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem_enum_MiscStatManager__MiscStatID_*>
        bSSimpleList_ListBoxItem_enum_MiscStatManager__MiscStatID____Component;  // +0x4
    Tile* m_pListTile;                                                           // +0xC
    Tile* m_pSelectedTile;                                                       // +0x10
    Tile* m_pHighlightedTile;                                                    // +0x14
    const char* pTemplateName;                                                   // +0x18
    unsigned short m_usSelectedIndex;                                            // +0x1C
    unsigned short layoutPadding1E;
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned short layoutPadding2E;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ListBox_enum_MiscStatManager__MiscStatID_) == 0x30);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_,
                           bSSimpleList_ListBoxItem_enum_MiscStatManager__MiscStatID____Component) == 0x4);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_pListTile) == 0xC);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_pSelectedTile) == 0x10);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_pHighlightedTile) == 0x14);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, pTemplateName) == 0x18);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_usSelectedIndex) == 0x1C);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_fFirstListValue) == 0x20);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_fSecondListValue) == 0x24);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, m_fThirdListValue) == 0x28);
FNV_STATIC_ASSERT(offsetof(ListBox_enum_MiscStatManager__MiscStatID_, usFlags) == 0x2C);
#endif
