// Source layout: BGSEntryPointPerkEntry. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTPERKENTRY_H
#define FNV_BGSENTRYPOINTPERKENTRY_H

#include "layout_support.h"
#include "BGSPerkEntry.h"
#include "PerkEntryPointData.h"
#pragma pack(push, 4)
class BGSEntryPointPerkEntry : public BGSPerkEntry
{
  public:
    PerkEntryPointData Data;  // +0x8
    unsigned char layoutPaddingB;
    BGSEntryPointFunctionData* m_pFunctionData;  // +0xC
    PerkEntryConditionSet* m_pConditions;                 // +0x10
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointPerkEntry) == 0x14);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, Data) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, m_pFunctionData) == 0xC);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, m_pConditions) == 0x10);
#endif
