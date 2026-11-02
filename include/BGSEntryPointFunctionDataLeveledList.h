// Source layout: BGSEntryPointFunctionDataLeveledList. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATALEVELEDLIST_H
#define FNV_BGSENTRYPOINTFUNCTIONDATALEVELEDLIST_H
#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
#pragma pack(push, 4)
class BGSEntryPointFunctionDataLeveledList : public BGSEntryPointFunctionData
{
  public:
    TESLevItem* pLeveledList;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataLeveledList) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataLeveledList, pLeveledList) == 0x4);
#endif
