// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/StatsMenu__HealingOption.h
#ifndef FNV_STATSMENU__HEALINGOPTION_H
#define FNV_STATSMENU__HEALINGOPTION_H

#include "statsmenu_layout_support.h"
class StatsMenu__HealingOption
{
  public:
    AlchemyItem* m_pHealingItem;                                 // +0x0
    Tile* pTile;                                                 // +0x4
    InventoryStackRecord* m_pStatusEffect;                                 // +0x8
    bool___cdecl__StatsMenu__HealingOption__* m_pfnIsAvailable;  // +0xC
};
FNV_STATIC_ASSERT(sizeof(StatsMenu__HealingOption) == 0x10);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, m_pHealingItem) == 0x0);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, pTile) == 0x4);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, m_pStatusEffect) == 0x8);
FNV_STATIC_ASSERT(offsetof(StatsMenu__HealingOption, m_pfnIsAvailable) == 0xC);
#endif
