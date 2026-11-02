// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CONTAINERMENU_H
#define FNV_CONTAINERMENU_H

#include "layout_support.h"

#include "InventoryStackRecord.h"
#include "ListBox_ItemChange___.h"
#include "Menu.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class ContainerMenu;
enum Interface__CONTAINER_MENU_MODE
{
    Interface__CONTAINER_MENU_MODE_CMM_NONE = 0,
    Interface__CONTAINER_MENU_MODE_CMM_STANDARD = 1,
    Interface__CONTAINER_MENU_MODE_CMM_PICKPOCKET = 2,
    Interface__CONTAINER_MENU_MODE_CMM_TEAMMATE = 3,
    Interface__CONTAINER_MENU_MODE_CMM_ROCK_N_LOAD = 4
};
enum ContainerMenu__FILTER_MODE
{
    ContainerMenu__FILTER_MODE_FM_ALL = 0,
    ContainerMenu__FILTER_MODE_FM_WEAPONS = 1,
    ContainerMenu__FILTER_MODE_FM_APPAREL = 2,
    ContainerMenu__FILTER_MODE_FM_AID = 3,
    ContainerMenu__FILTER_MODE_FM_MISC = 4,
    ContainerMenu__FILTER_MODE_FM_AMMO = 5,
    ContainerMenu__FILTER_MODE_FM_COUNT = 6
};
enum MENU_SOUNDS
{
    MENU_SOUNDS_MENU_SOUND_NONE = -1,
    MENU_SOUNDS_MENU_SOUND_OK = 1,
    MENU_SOUNDS_MENU_SOUND_CANCEL = 2,
    MENU_SOUNDS_MENU_SOUND_NEXT_PREVIOUS = 3,
    MENU_SOUNDS_MENU_SOUND_FOCUS = 4,
    MENU_SOUNDS_MENU_SOUND_BOOK_NEXT_PAGE = 5,
    MENU_SOUNDS_MENU_SOUND_SPEECH_ROLLOVER = 6,
    MENU_SOUNDS_MENU_SOUND_SPEECH_ROTATE = 7,
    MENU_SOUNDS_MENU_SOUND_QUEST_NEW = 8,
    MENU_SOUNDS_MENU_SOUND_QUEST_UPDATE = 9,
    MENU_SOUNDS_MENU_SOUND_MESSAGE = 10,
    MENU_SOUNDS_MENU_SOUND_CLICK = 11,
    MENU_SOUNDS_MENU_SOUND_WHIR = 12,
    MENU_SOUNDS_MENU_SOUND_WHIR_CLICK = 13,
    MENU_SOUNDS_MENU_SOUND_FADE = 14,
    MENU_SOUNDS_MENU_SOUND_INVENTORY_OPEN = 15,
    MENU_SOUNDS_MENU_SOUND_INVENTORY_CLOSE = 16,
    MENU_SOUNDS_MENU_SOUND_POTION_CREATE = 17,
    MENU_SOUNDS_MENU_SOUND_DOOR_LOCKED = 18,
    MENU_SOUNDS_MENU_SOUND_PLACE_TOKEN = 19,
    MENU_SOUNDS_MENU_SOUND_REMOVE_TOKEN = 20,
    MENU_SOUNDS_MENU_SOUND_LEVEL_UP = 21,
    MENU_SOUNDS_MENU_SOUND_SPELL_EQUIP = 22,
    MENU_SOUNDS_MENU_SOUND_ENCHANTMENT_RECHARGE = 23,
    MENU_SOUNDS_MENU_SOUND_SCROLL_OPEN = 24,
    MENU_SOUNDS_MENU_SOUND_SCROLL_CLOSE = 25,
    MENU_SOUNDS_MENU_SOUND_BOOK_OPEN = 26,
    MENU_SOUNDS_MENU_SOUND_BOOK_CLOSE = 27,
    MENU_SOUNDS_MENU_SOUND_TAKE_ALL = 28,
    MENU_SOUNDS_MENU_SOUND_NOTHING_HARVESTED = 29,
    MENU_SOUNDS_MENU_SOUND_INGREDIENT_SELECTED = 30,
    MENU_SOUNDS_MENU_SOUND_SOUL_TRAP = 31,
    MENU_SOUNDS_MENU_SOUND_HAMMER_BREAK = 32,
    MENU_SOUNDS_MENU_SOUND_SIGIL_CREATE = 33,
    MENU_SOUNDS_MENU_SOUND_GOLD = 34,
    MENU_SOUNDS_MENU_SOUND_ENCHANT = 35,
    MENU_SOUNDS_MENU_SOUND_MODE = 36
};
#pragma pack(push, 4)
class ContainerMenu : public Menu
{
  public:
    // base Menu at +0x0, size 40
    Tile* m_pTiles[19];                                   // +0x28, 76 bytes
    TESObjectREFR* m_pContainer;                          // +0x74, 4 bytes
    BSSimpleList<TESBoundObject*> m_kContainerItems;      // +0x78, 8 bytes
    Interface__CONTAINER_MENU_MODE m_eContainerMenuMode;  // +0x80, 4 bytes
    int m_iStolenItemCount;                               // +0x84, 4 bytes
    bool m_bFirstContainerFlag;                           // +0x88, 1 bytes
    bool m_bSecondContainerFlag;                          // +0x89, 1 bytes
    unsigned char layoutPadding8A[2];
    ContainerMenu__FILTER_MODE m_eFilterMode;        // +0x8C, 4 bytes
    ContainerMenu__FILTER_MODE m_eSecondFilterMode;  // +0x90, 4 bytes
    MENU_SOUNDS m_eMenuSounds;                       // +0x94, 4 bytes
    ListBox_ItemChange___ m_kFirstItemChangeList;    // +0x98, 48 bytes
    ListBox_ItemChange___ m_kSecondItemChangeList;   // +0xC8, 48 bytes
    ListBox_ItemChange___* m_pCurrentList;           // +0xF8, 4 bytes
    unsigned int m_uiCurrentItemIndex;               // +0xFC, 4 bytes
    SoundPlaybackHandle m_kFadeSequence;                   // +0x100, 12 bytes
    static void Close();
    void UpdateContainer(TESObjectREFR*, bool);
    // void __cdecl ContainerMenu::*(TESTopic*)
    // void __cdecl ContainerMenu::*()
    // void __cdecl ContainerMenu::*(TESObjectREFR*, bool)
    // void __cdecl ContainerMenu::*(TESBoundObject*)
    // bool __cdecl ContainerMenu::*(Actor*, int)
    // void __cdecl ContainerMenu::*(Tile*)
    // void __cdecl ContainerMenu::*(const char*)
    // void __cdecl ContainerMenu::*(int)
    // ContainerMenu
    // void __cdecl ContainerMenu::*()
    // Tile* __cdecl ContainerMenu::*(TESObjectREFR*, Interface::CONTAINER_MENU_MODE)
    // int __cdecl ContainerMenu::*()
    // int __cdecl ContainerMenu::*()
    // bool __cdecl ContainerMenu::*()
    // void __cdecl ContainerMenu::*(int, Tile*)
    // void __cdecl ContainerMenu::*()
    // void __cdecl ContainerMenu::*(int, Tile*)
    // void __cdecl ContainerMenu::*(int, Tile*)
    // void __cdecl ContainerMenu::*(int, Tile*)
    // bool __cdecl ContainerMenu::*(int, float)
    // bool __cdecl ContainerMenu::*(int, float)
    // bool __cdecl ContainerMenu::*(int)
    // void __cdecl ContainerMenu::*(int, Tile*)
    // void __cdecl ContainerMenu::*()
    // TESObjectREFR* __cdecl ContainerMenu::*()
    // void __cdecl ContainerMenu::*()
    // Interface::CONTAINER_MENU_MODE __cdecl ContainerMenu::*()
    // ContainerMenu& __cdecl ContainerMenu::*(const ContainerMenu&)
    // void __cdecl ContainerMenu::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ContainerMenu) == 268);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_pTiles) == 40);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_pContainer) == 116);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_kContainerItems) == 120);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_eContainerMenuMode) == 128);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_iStolenItemCount) == 132);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_bFirstContainerFlag) == 136);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_bSecondContainerFlag) == 137);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_eFilterMode) == 140);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_eSecondFilterMode) == 144);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_eMenuSounds) == 148);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_kFirstItemChangeList) == 152);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_kSecondItemChangeList) == 200);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_pCurrentList) == 248);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_uiCurrentItemIndex) == 252);
FNV_STATIC_ASSERT(offsetof(ContainerMenu, m_kFadeSequence) == 256);
#endif
