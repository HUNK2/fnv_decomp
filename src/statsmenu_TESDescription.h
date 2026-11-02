// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/TESDescription.h
// Source layout: TESDescription. PC corrections are in generate_headers.py.
#ifndef FNV_TESDESCRIPTION_H
#define FNV_TESDESCRIPTION_H

#include "statsmenu_layout_support.h"
#include "statsmenu_BaseFormComponent.h"
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESDescription, m_uiDescriptionFileOffset) == 0x4);
#endif
