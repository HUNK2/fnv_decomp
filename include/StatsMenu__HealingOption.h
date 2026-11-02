// include/StatsMenu__HealingOption.h: declares StatsMenu__HealingOption
#ifndef FNV_STATSMENU__HEALINGOPTION_H
#define FNV_STATSMENU__HEALINGOPTION_H

#include "layout_support.h"
#pragma pack(push, 4)
class StatsMenu__HealingOption
{
  public:
    AlchemyItem* m_pHealingItem;                                 // +0x0
    Tile* pTile;                                                 // +0x4
    InventoryStackRecord* m_pStatusEffect;                                 // +0x8
    bool___cdecl__StatsMenu__HealingOption__* m_pfnIsAvailable;  // +0xC
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(StatsMenu__HealingOption) == 0x10);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, m_pHealingItem) == 0x0);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, pTile) == 0x4);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, m_pStatusEffect) == 0x8);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, m_pfnIsAvailable) == 0xC);
#endif
