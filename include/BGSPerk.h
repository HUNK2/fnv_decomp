// Source layout: BGSPerk. PC corrections are in generate_headers.py.
#ifndef FNV_BGSPERK_H
#define FNV_BGSPERK_H

#include "layout_support.h"
#include "PerkData.h"
#include "PerkEntryConditionSet.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#pragma pack(push, 4)
class BGSPerk : public TESForm
{
  public:
    TESFullName tESFullNameComponent;        // +0x18
    TESDescription tESDescriptionComponent;  // +0x24
    TESIcon tESIconComponent;                // +0x2C
    PerkData Data;                           // +0x38
    unsigned char layoutPadding3D;
    unsigned short layoutPadding3E;
    PerkEntryConditionSet m_kConditions;                // +0x40
    BSSimpleList<BGSPerkEntry*> m_kEntryList;  // +0x48
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPerk) == 0x50);
FNV_STATIC_ASSERT(offsetof(BGSPerk, tESFullNameComponent) == 0x18);
FNV_STATIC_ASSERT(offsetof(BGSPerk, tESDescriptionComponent) == 0x24);
FNV_STATIC_ASSERT(offsetof(BGSPerk, tESIconComponent) == 0x2C);
FNV_STATIC_ASSERT(offsetof(BGSPerk, Data) == 0x38);
FNV_STATIC_ASSERT(offsetof(BGSPerk, m_kConditions) == 0x40);
FNV_STATIC_ASSERT(offsetof(BGSPerk, m_kEntryList) == 0x48);
#endif
