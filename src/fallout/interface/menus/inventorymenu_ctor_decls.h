// Private constructor declarations; field layouts follow the canonical PC headers.
#ifndef FNV_INVENTORYMENU_CTOR_DECLS_H
#define FNV_INVENTORYMENU_CTOR_DECLS_H

#include <stddef.h>
#define FNV_CTOR_JOIN_(a, b) a##b
#define FNV_CTOR_JOIN(a, b) FNV_CTOR_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_CTOR_JOIN(fnv_layout_check_, __LINE__)[(c) ? 1 : -1]
class Tile;
class TileMenu;
class Tile__TileTemplate;
class InventoryStackRecord;
class TESBoundObject;
class ListBoxItem_ItemChange___;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
};
class Menu
{
  public:
    Menu();
    virtual ~Menu();
    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId;
    int m_iSecondaryValue;
    bool m_bIsSpecial;
    bool m_bVisible;
    int m_iMenuId;
    int m_eFadeState;
};
class ListBoxBase
{
  public:
    void** m_ppVirtualMethodTable;
};
class InventoryMenu__sPageState
{
  public:
    int m_iSelectedItemIndex;  // +0x0
    int m_iScrollOffset;       // +0x4
};

class ListBox_ItemChange___ : public ListBoxBase
{
  public:
    ListBox_ItemChange___();
    ~ListBox_ItemChange___();
    BSSimpleList<ListBoxItem_ItemChange___*> bSSimpleList_ListBoxItem_ItemChange______Component;  // +0x4
    Tile* m_pListTile;                                                                            // +0xC
    Tile* m_pSelectedTile;                                                                        // +0x10
    Tile* m_pHighlightedTile;                                                                     // +0x14
    const char* pTemplateName;                                                                    // +0x18
    unsigned short m_usSelectedIndex;                                                             // +0x1C
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue;   // +0x20
    float m_fSecondListValue;  // +0x24
    float m_fThirdListValue;   // +0x28
    unsigned short usFlags;    // +0x2C
    unsigned char layoutPadding2E[2];
};

class HotkeyWheelDisplay
{
  public:
    HotkeyWheelDisplay();
    ~HotkeyWheelDisplay();
    Tile* m_pWheelTile;                  // +0x0
    Tile* m_ppHotkeySlotTiles[8];  // +0x4
    bool m_bHasHotkeySelection;    // +0x24
    unsigned char layoutPadding25[3];
    int m_iTileValueIdAtOffset28;  // +0x28
    int m_iTileValueIdAtOffset2C;  // +0x2C
    int m_iTileValueIdAtOffset30;  // +0x30
};

class InventoryMenu : public Menu
{
  public:
    InventoryMenu();
    virtual ~InventoryMenu();
    static int ms_iValueTileID;
    static int ms_iItemTypeTileID;
    static int ms_iCurrentTabTileID;
    static int ms_iKeyringOpenTileID;
    static int ms_iEquippableItemTileID;
    Tile* m_pTiles[23];                              // +0x28
    int m_iCurrentTab;                               // +0x84
    InventoryMenu__sPageState m_kPageStates[6];      // +0x88
    ListBox_ItemChange___ m_kItemList;               // +0xB8
    HotkeyWheelDisplay m_kMenuData;                        // +0xE8
    BSSimpleList<TESBoundObject*> m_kHotkeyObjects;  // +0x11C
    int GetClass();
    void AssignTileByID(int id, Tile* tile);
};

FNV_STATIC_ASSERT(sizeof(InventoryMenu) == 0x124);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_iCurrentTab) == 0x84);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kPageStates) == 0x88);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kItemList) == 0xB8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kMenuData) == 0xE8);
FNV_STATIC_ASSERT(offsetof(InventoryMenu, m_kHotkeyObjects) == 0x11C);

class Tile
{
  public:
    static int GetTraitID(const char*);
};
#endif
