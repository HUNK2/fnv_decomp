// Source layout: BGSEntryPointFunctionDataOneValue. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATAONEVALUE_H
#define FNV_BGSENTRYPOINTFUNCTIONDATAONEVALUE_H
#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
#pragma pack(push, 4)
class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
{
  public:
    float fValue;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataOneValue) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataOneValue, fValue) == 0x4);
#endif
