// Source layout: StatsMenu::StatusEffectList. PC corrections are in generate_headers.py.
#ifndef FNV_STATSMENU__STATUSEFFECTLIST_H
#define FNV_STATSMENU__STATUSEFFECTLIST_H

#include "layout_support.h"
#pragma pack(push, 4)
class StatsMenu__StatusEffectList
{
  public:
    void** m_ppVirtualMethodTable;                                                                          // +0x0
    BSSimpleList<StatsMenu__StatusEffect*> bSSimpleList_StatsMenu__StatusEffect___Component;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(StatsMenu__StatusEffectList) == 0xC);
FNV_STATIC_ASSERT(offsetof(StatsMenu__StatusEffectList, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(StatsMenu__StatusEffectList, bSSimpleList_StatsMenu__StatusEffect___Component) == 0x4);
#endif
