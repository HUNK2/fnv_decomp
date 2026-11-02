// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/StatsMenu__NamedEffectsList.h
// Source layout: StatsMenu::NamedEffectsList. PC corrections are in generate_headers.py.
#ifndef FNV_STATSMENU__NAMEDEFFECTSLIST_H
#define FNV_STATSMENU__NAMEDEFFECTSLIST_H

#include "statsmenu_layout_support.h"
class StatsMenu__NamedEffectsList
{
  public:
    void** m_ppVirtualMethodTable;                                                      // +0x0
    BSSimpleList<EffectSetting*> bSSimpleList_EffectSetting___Component;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(StatsMenu__NamedEffectsList) == 0xC);
FNV_STATIC_ASSERT(offsetof(StatsMenu__NamedEffectsList, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(StatsMenu__NamedEffectsList, bSSimpleList_EffectSetting___Component) == 0x4);
#endif
