// Source layout: BGSEntryPointFunctionData. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATA_H
#define FNV_BGSENTRYPOINTFUNCTIONDATA_H

#include "layout_support.h"
#pragma pack(push, 4)
class BGSEntryPointFunctionData
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointFunctionData) == 0x4);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionData, m_ppVirtualMethodTable) == 0x0);
#endif
