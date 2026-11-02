// Authoring header for fallout/interface/menus/loadingmenu.h (unit 512).
#ifndef FNV_LOADINGMENU_H
#define FNV_LOADINGMENU_H

#include "layout_support.h"
#include "SoundPlaybackHandle.h"
#include "Menu.h"
#include "TESForm.h"
class Tile;

class TileLayout;
class LoadingMenu;
class RgbaColor;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile___;
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator;
class NiTListItem_Tile___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_Tile___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___;
class NiTexture;
class TESLoadScreen;
class TileShaderProperty;
class tagRECT;
enum MiscStatManager__MiscStatID
{
    MiscStatManager__MiscStatID_MS_QUESTS_COMPLETED = 0,
    MiscStatManager__MiscStatID_MS_LOCATIONS_DISCOVERED = 1,
    MiscStatManager__MiscStatID_MS_HUMANS_KILLED = 2,
    MiscStatManager__MiscStatID_MS_CREATURES_KILLED = 3,
    MiscStatManager__MiscStatID_MS_LOCKS_PICKED = 4,
    MiscStatManager__MiscStatID_MS_COMPUTERS_HACKED = 5,
    MiscStatManager__MiscStatID_MS_STIMPAKS_TAKEN = 6,
    MiscStatManager__MiscStatID_MS_RADX_TAKEN = 7,
    MiscStatManager__MiscStatID_MS_RADAWAY_TAKEN = 8,
    MiscStatManager__MiscStatID_MS_CHEMS_TAKEN = 9,
    MiscStatManager__MiscStatID_MS_ADDICTIONS = 10,
    MiscStatManager__MiscStatID_MS_MINES_DISARMED = 11,
    MiscStatManager__MiscStatID_MS_SPEECH_SUCCESSES = 12,
    MiscStatManager__MiscStatID_MS_POCKETS_PICKED = 13,
    MiscStatManager__MiscStatID_MS_PANTS_EXPLODED = 14,
    MiscStatManager__MiscStatID_MS_BOOKS_READ = 15,
    MiscStatManager__MiscStatID_MS_STIMPAK_HEALTH_RESTORED = 16,
    MiscStatManager__MiscStatID_MS_WEAPONS_CONSTRUCTED = 17,
    MiscStatManager__MiscStatID_MS_FOOD_HEALTH_RESTORED = 18,
    MiscStatManager__MiscStatID_MS_WATER_CONSUMED = 19,
    MiscStatManager__MiscStatID_MS_SANDMAN_KILLS = 20,
    MiscStatManager__MiscStatID_MS_PARALYZING_PUNCHES = 21,
    MiscStatManager__MiscStatID_MS_ROBOTS_DISABLED = 22,
    MiscStatManager__MiscStatID_MS_TIMES_SLEPT = 23,
    MiscStatManager__MiscStatID_MS_CORPSES_EATEN = 24,
    MiscStatManager__MiscStatID_MS_STRANGER_ASSISTS = 25,
    MiscStatManager__MiscStatID_MS_DOCTORBAG_USED = 26,
    MiscStatManager__MiscStatID_MS_CHALLENGES_COMPLETED = 27,
    MiscStatManager__MiscStatID_MS_MISS_FORTUNE = 28,
    MiscStatManager__MiscStatID_MS_DISINTEGRATIONS = 29,
    MiscStatManager__MiscStatID_MS_HAVE_LIMBS_CRIPPLED = 30,
    MiscStatManager__MiscStatID_MS_SPEECH_FAILURES = 31,
    MiscStatManager__MiscStatID_MS_ITEMS_CRAFTED = 32,
    MiscStatManager__MiscStatID_MS_WEAPONS_MODDED = 33,
    MiscStatManager__MiscStatID_MS_ITEMS_REPAIRED = 34,
    MiscStatManager__MiscStatID_MS_TOTAL_THINGS_KILLED = 35,
    MiscStatManager__MiscStatID_MS_DISMEMBERMENTS = 36,
    MiscStatManager__MiscStatID_MS_CARAVAN_GAMES_WON = 37,
    MiscStatManager__MiscStatID_MS_CARAVAN_GAMES_LOST = 38,
    MiscStatManager__MiscStatID_MS_BARTER_AMOUNT_TRADED = 39,
    MiscStatManager__MiscStatID_MS_ROULETTE_GAMES_PLAYED = 40,
    MiscStatManager__MiscStatID_MS_BLACKJACK_GAMES_PLAYED = 41,
    MiscStatManager__MiscStatID_MS_SLOTS_GAMES_PLAYED = 42,
    MiscStatManager__MiscStatID_MS_COUNT = 43
};
enum FONTS
{
    FONTS_FONT_NONE = -1,
    FONTS_FONT_1 = 0,
    FONTS_FONT_2 = 1,
    FONTS_FONT_3 = 2,
    FONTS_FONT_4 = 3,
    FONTS_FONT_5 = 4,
    FONTS_FONT_6 = 5,
    FONTS_FONT_7 = 6,
    FONTS_FONT_8 = 7,
    FONTS_FONT_COUNT = 8
};
#pragma pack(push, 4)
class tagRECT
{
  public:
    long left;    // +0x0, 4 bytes
    long top;     // +0x4, 4 bytes
    long right;   // +0x8, 4 bytes
    long bottom;  // +0xC, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(tagRECT) == 16);
FNV_STATIC_ASSERT(offsetof(tagRECT, left) == 0);
FNV_STATIC_ASSERT(offsetof(tagRECT, top) == 4);
FNV_STATIC_ASSERT(offsetof(tagRECT, right) == 8);
FNV_STATIC_ASSERT(offsetof(tagRECT, bottom) == 12);
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator, m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile___
{
  public:
    NiTListItem_Tile___* m_pkHead;                                                           // +0x0, 4 bytes
    NiTListItem_Tile___* m_pkTail;                                                           // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(NiTListItem<Tile *>*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(NiTListItem<Tile *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, NiTListItem<Tile *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, NiTListItem<Tile *>*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(const NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__Tile___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,Tile *> at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, Tile*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, Tile*&)
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*)
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*&)
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*&)
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&)
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(int __cdecl (void*, void*)*)
    // NiTListItem<Tile *>* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(NiTListItem<Tile *>*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___) == 12);
#pragma pack(push, 4)
class NiTPointerList_Tile___ : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *> at +0x0, size 12
    // NiTPointerList<Tile *>
    // void __cdecl NiTPointerList<Tile *>::*()
    // NiTPointerList<Tile *>& __cdecl NiTPointerList<Tile *>::*(const NiTPointerList<Tile *>&)
    // void* __cdecl NiTPointerList<Tile *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_Tile___) == 12);
#pragma pack(push, 4)
class RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
    // void __cdecl RgbaColor::*(float, float, float, float)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor __cdecl RgbaColor::*(const RgbaColor&)
    // operator-
    // operator*
    // operator/
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // operator*=
    // operator/=
    // void __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl RgbaColor::*(const char*)
    // float __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
#pragma pack(push, 4)
class TileLayout
{
  public:
    int m_iXPosition;             // +0x0, 4 bytes
    int m_iYPosition;             // +0x4, 4 bytes
    int nHeight;                  // +0x8, 4 bytes
    int nWidth;                   // +0xC, 4 bytes
    FONTS m_eFont;                // +0x10, 4 bytes
    unsigned char m_ucFontStyle;  // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TileLayout) == 24);
FNV_STATIC_ASSERT(offsetof(TileLayout, m_iXPosition) == 0);
FNV_STATIC_ASSERT(offsetof(TileLayout, m_iYPosition) == 4);
FNV_STATIC_ASSERT(offsetof(TileLayout, nHeight) == 8);
FNV_STATIC_ASSERT(offsetof(TileLayout, nWidth) == 12);
FNV_STATIC_ASSERT(offsetof(TileLayout, m_eFont) == 16);
FNV_STATIC_ASSERT(offsetof(TileLayout, m_ucFontStyle) == 20);
#pragma pack(push, 4)
class LoadingMenu : public Menu
{
  public:
    // base Menu at +0x0, size 40
    Tile* m_pTiles[38];                                       // +0x28, 152 bytes
    tagRECT m_kTileRectangle;                                 // +0xC0, 16 bytes
    NiTPointerList_Tile___ m_kFirstTileList;                  // +0xD0, 12 bytes
    NiTPointerList_Tile___ m_kSecondTileList;                 // +0xDC, 12 bytes
    NiTPointerList_Tile___ m_kThirdTileList;                  // +0xE8, 12 bytes
    NiTPointerList_Tile___ m_kFourthTileList;                 // +0xF4, 12 bytes
    NiTPointerList_Tile___ m_kFifthTileList;                  // +0x100, 12 bytes
    MiscStatManager__MiscStatID m_aeMiscStatIdentifiers[43];  // +0x10C, 172 bytes
    BSStringT<char> m_kLoadingScreenTip;                      // +0x1B8, 8 bytes
    RgbaColor m_kLoadingScreenColor;                          // +0x1C0, 16 bytes
    BSSimpleList<TESLoadScreen*> m_kLoadScreenItems;          // +0x1D0, 8 bytes
    BSSimpleList<TESLoadScreen*>* m_pkLoadScreenList;         // +0x1D8, 4 bytes
    TESLoadScreen* m_pCurrentLoadScreen;                      // +0x1DC, 4 bytes
    unsigned int m_uiLoadScreenIndex;                         // +0x1E0, 4 bytes
    unsigned int LoadScreenData;                              // +0x1E4, 4 bytes
    TESForm* pLocation;                                       // +0x1E8, 4 bytes
    TileShaderProperty* TileShaderState;                      // +0x1EC, 4 bytes
    TileShaderProperty* m_pAlternateTileShaderState;          // +0x1F0, 4 bytes
    SoundPlaybackHandle m_kFirstDate;                               // +0x1F4, 12 bytes
    SoundPlaybackHandle m_kSecondDate;                              // +0x200, 12 bytes
    NiPointer<NiTexture> m_kLoadScreenTextures[4];            // +0x20C, 16 bytes
    unsigned int m_uiLoadingScreenNumber;                     // +0x21C, 4 bytes
    unsigned short m_usAdditionalFlags;                       // +0x220, 2 bytes
    unsigned short usFlags;                                   // +0x222, 2 bytes
    TileLayout m_kTileLayouts[38];                            // +0x224, 912 bytes
    unsigned int m_uiFirstStateValue;                         // +0x5B4, 4 bytes
    unsigned int m_uiSecondStateValue;                        // +0x5B8, 4 bytes
    int m_iStateFlags;                                        // +0x5BC, 4 bytes
    int GetClass();
    void AssignTileByID(int uiIndex, Tile* pTile);

    // LoadingMenu
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(LoadingMenu::Flag, bool)
    // bool __cdecl LoadingMenu::*(LoadingMenu::Flag)
    // void __cdecl LoadingMenu::*(LoadingMenu::Flag)
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // Tile* __cdecl LoadingMenu::*(TESForm*, bool, bool)
    // void __cdecl LoadingMenu::*(bool)
    // bool __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(bool)
    // bool __cdecl LoadingMenu::*()
    // int __cdecl LoadingMenu::*()
    // int __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(int, Tile*)
    // void __cdecl LoadingMenu::*(unsigned int)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(TileShaderProperty*)
    // void __cdecl LoadingMenu::*()
    // bool __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // bool __cdecl LoadingMenu::*(TESLoadScreen*)
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(BSSimpleArray<TESLoadScreen *,1024>&)
    // void __cdecl LoadingMenu::*(BSSimpleArray<TESLoadScreen *,1024>&)
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(LoadingMenu::TileIndex, bool)
    // void __cdecl LoadingMenu::*(NiAVObject*, float)
    // void __cdecl LoadingMenu::*(TESLoadScreen*, float, int)
    // void __cdecl LoadingMenu::*(float, int)
    // void __cdecl LoadingMenu::*(float, int)
    // void __cdecl LoadingMenu::*(float, int)
    // void __cdecl LoadingMenu::*(float, int)
    // void __cdecl LoadingMenu::*(float, int)
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(TESLoadScreen*, bool)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(TESLoadScreen*)
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // bool __cdecl LoadingMenu::*()
    // bool __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*()
    // float __cdecl LoadingMenu::*()
    // void __cdecl LoadingMenu::*(BGSSaveGameBuffer*)
    // void __cdecl LoadingMenu::*(BGSLoadGameBuffer*)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(bool)
    // void __cdecl LoadingMenu::*(TESForm*)
    // void __cdecl LoadingMenu::*(TESForm*)
    // void __cdecl LoadingMenu::*(TESForm*)
    // LoadingMenu& __cdecl LoadingMenu::*(const LoadingMenu&)
    // void __cdecl LoadingMenu::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LoadingMenu) == 1472);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_pTiles) == 40);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kTileRectangle) == 192);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kFirstTileList) == 208);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kSecondTileList) == 220);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kThirdTileList) == 232);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kFourthTileList) == 244);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kFifthTileList) == 256);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_aeMiscStatIdentifiers) == 268);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kLoadingScreenTip) == 440);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kLoadingScreenColor) == 448);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kLoadScreenItems) == 464);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_pkLoadScreenList) == 472);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_pCurrentLoadScreen) == 476);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_uiLoadScreenIndex) == 480);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, LoadScreenData) == 484);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, pLocation) == 488);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, TileShaderState) == 492);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_pAlternateTileShaderState) == 496);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kFirstDate) == 500);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kSecondDate) == 512);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kLoadScreenTextures) == 524);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_uiLoadingScreenNumber) == 540);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_usAdditionalFlags) == 544);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, usFlags) == 546);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_kTileLayouts) == 548);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_uiFirstStateValue) == 1460);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_uiSecondStateValue) == 1464);
FNV_STATIC_ASSERT(offsetof(LoadingMenu, m_iStateFlags) == 1468);

// @fnv 0x00788730
int LoadingMenu::GetClass()
{
    return 1007;
}

// @fnv 0x00788740
void LoadingMenu::AssignTileByID(int uiIndex, Tile* pTile)
{
    if (pTile && uiIndex < 38 && uiIndex >= 0)
        m_pTiles[uiIndex] = pTile;
}
#endif
