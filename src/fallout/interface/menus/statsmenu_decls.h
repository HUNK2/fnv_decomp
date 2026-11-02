// Source layout: StatsMenu. PC corrections are in generate_headers.py.
#ifndef FNV_PRIVATE_STATSMENU_DECLS_H
#define FNV_PRIVATE_STATSMENU_DECLS_H

#include "layout_support.h"
class Tile
{
  public:
    enum TILE_FADE_CONTROL_TYPE
    {
        FADE = 1
    };
    void SetTraitFade(int, float, float, float, TILE_FADE_CONTROL_TYPE);
    void UpdateTrait(int);
    void Set(int, int);
};
#include "ListBox_PerkRankData___.h"
#include "ListBox_StatsMenu__StatusEffect___.h"
#include "ListBox_TESReputation___.h"
#include "ListBox_enum_ActorValue__Index_.h"
#include "ListBox_enum_MiscStatManager__MiscStatID_.h"
#include "Menu.h"
#include "StatsMenu__HealingOption.h"
#include "StatsMenu__NamedEffectsList.h"
#include "StatsMenu__StatusEffectList.h"
#pragma pack(push, 4)
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
    static bool SetTileFlashing(Tile*, unsigned int);
    class BodyPartDisplay
    {
      public:
        int m_iBodyPartCount;
        BSSimpleList<Tile*> m_kBodyPartTileLists[6];
        unsigned int m_auiBodyPartValues[6];
        BodyPartDisplay();
    };
    int GetClass();
    void AssignTileByID(int, Tile*);
};
#pragma pack(pop)
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

extern "C" void* __cdecl memset(void*, int, unsigned int) throw(...);
