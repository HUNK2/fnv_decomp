// Private declaration copy; original: relay_work/queue/queue008/01_fallout_shared_magic_effectsetting_cpp/include/BGSPerk.h
// Source layout: BGSPerk. PC corrections are in generate_headers.py.
#ifndef FNV_BGSPERK_H
#define FNV_BGSPERK_H

#include "statsmenu_layout_support.h"
#include "statsmenu_PerkData.h"
#include "statsmenu_TESCondition.h"
#include "statsmenu_TESDescription.h"
#include "statsmenu_TESForm.h"
#include "statsmenu_TESFullName.h"
#include "statsmenu_TESIcon.h"
class BGSPerk : public TESForm
{
  public:
    TESFullName tESFullNameComponent;        // +0x18
    TESDescription tESDescriptionComponent;  // +0x24
    TESIcon tESIconComponent;                // +0x2C
    bool IsPerkHidden() const;
    PerkData Data;  // +0x38
    unsigned char layoutPadding3D[3];
    PerkEntryConditionSet m_kConditions;                // +0x40
    BSSimpleList<BGSPerkEntry*> m_kEntryList;  // +0x48
};
FNV_STATIC_ASSERT(sizeof(BGSPerk) == 0x50);
FNV_STATIC_ASSERT(offsetof(BGSPerk, tESFullNameComponent) == 0x18);
FNV_STATIC_ASSERT(offsetof(BGSPerk, tESDescriptionComponent) == 0x24);
FNV_STATIC_ASSERT(offsetof(BGSPerk, tESIconComponent) == 0x2C);
FNV_STATIC_ASSERT(offsetof(BGSPerk, Data) == 0x38);
FNV_STATIC_ASSERT(offsetof(BGSPerk, m_kConditions) == 0x40);
FNV_STATIC_ASSERT(offsetof(BGSPerk, m_kEntryList) == 0x48);
#endif
