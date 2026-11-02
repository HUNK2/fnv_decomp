// Source layout: BGSEntryPointFunctionDataTwoValue. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATATWOVALUE_H
#define FNV_BGSENTRYPOINTFUNCTIONDATATWOVALUE_H

#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
#pragma pack(push, 4)
class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
  public:
    float EntryPointTwoValueFunctionData;  // +0x4
    float fSecondFunctionValue;            // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataTwoValue) == 0xC);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataTwoValue, EntryPointTwoValueFunctionData) == 0x4);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataTwoValue, fSecondFunctionValue) == 0x8);
#endif
