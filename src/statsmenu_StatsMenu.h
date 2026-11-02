// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/StatsMenu.h
// Source layout: StatsMenu. PC corrections are in generate_headers.py.
#ifndef FNV_STATSMENU_H
#define FNV_STATSMENU_H

#include "statsmenu_layout_support.h"
#include "statsmenu_types_MiscStatManager__MiscStatID.h"
#include "statsmenu_ListBox_PerkRankData___.h"
#include "statsmenu_ListBox_StatsMenu__StatusEffect___.h"
#include "statsmenu_ListBox_TESReputation___.h"
#include "statsmenu_ListBox_enum_ActorValue__Index_.h"
#include "statsmenu_ListBox_enum_MiscStatManager__MiscStatID_.h"
#include "statsmenu_Menu.h"
#include "statsmenu_StatsMenu__HealingOption.h"
#include "statsmenu_StatsMenu__NamedEffectsList.h"
#include "statsmenu_StatsMenu__StatusEffectList.h"
class StatsMenu : public Menu
{
  public:
    StatsMenu__HealingOption m_kHealingOptions[4];               // +0x28
    StatsMenu__NamedEffectsList m_kNamedEffectsList;             // +0x68
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex0;            // +0x74
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex1;            // +0x78
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex2;            // +0x7C
    StatsMenu__StatusEffect* m_pStatusEffectAtIndex3;            // +0x80
    StatsMenu__StatusEffectList m_kStatusEffectEntries;          // +0x84
    Tile* m_pTiles[60];                                          // +0x90
    ListBox_enum_ActorValue__Index_ m_kPrimaryActorValueList;    // +0x180
    ListBox_enum_ActorValue__Index_ m_kSecondaryActorValueList;  // +0x1B0
    ListBox_PerkRankData___ m_kPerkRankList;                     // +0x1E0
    ListBox_enum_MiscStatManager__MiscStatID_ m_kMiscStatList;   // +0x210
    ListBox_StatsMenu__StatusEffect___ m_kStatusEffectList;      // +0x240
    ListBox_TESReputation___ m_kReputationList;                  // +0x270
    bool m_bUpdateOption;                                        // +0x2A0
    bool m_bStatUpdatePending;                                   // +0x2A1
    unsigned char layoutPadding2A2[2];
    int GetClass();
    enum Page
    {
        SM_STATUS = 0,
        SM_FIRST_PAGE = 0,
        SM_SPECIAL = 1,
        SM_SKILLS = 2,
        SM_PERKS = 3,
        SM_GENERAL = 4,
        SM_LAST_PAGE = 4,
        SM_PAGE_COUNT = 5
    };
    static StatsMenu* ms_pInventoryMenu;
    static float GetChartScale();
    static void SetStatsPage(unsigned char page);
    void SetCurrentPage(Page page);
    Page GetCurrentPage();
    int GetTraitForValue(ActorValue::Index value);
    void UpdateActorValueTiles();
    void RefreshActorValueTile(ActorValue::Index value);
    static void UpdatePrimaryActorValueTile(Tile* tile, ActorValue::Index value);
    static void UpdateSecondaryActorValueTile(Tile* tile, ActorValue::Index value);
    static void UpdateMiscStatTile(Tile* tile, MiscStatManager__MiscStatID value);
    void RefreshMiscStat(MiscStatManager__MiscStatID value);
    static void UpdateStatusEffects();
    static void ClearPerks();
};
FNV_STATIC_ASSERT(sizeof(StatsMenu) == 0x2A4);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kHealingOptions) == 0x28);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kNamedEffectsList) == 0x68);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_pStatusEffectAtIndex0) == 0x74);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_pStatusEffectAtIndex1) == 0x78);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_pStatusEffectAtIndex2) == 0x7C);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_pStatusEffectAtIndex3) == 0x80);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kStatusEffectEntries) == 0x84);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_pTiles) == 0x90);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kPrimaryActorValueList) == 0x180);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kSecondaryActorValueList) == 0x1B0);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kPerkRankList) == 0x1E0);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kMiscStatList) == 0x210);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kStatusEffectList) == 0x240);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_kReputationList) == 0x270);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_bUpdateOption) == 0x2A0);
FNV_STATIC_ASSERT(offsetof(StatsMenu, m_bStatUpdatePending) == 0x2A1);
#endif
