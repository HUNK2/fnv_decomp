// Source layout: BGSEntryPointFunctionDataActivateChoice. PC corrections are in generate_headers.py.
#ifndef FNV_BGSENTRYPOINTFUNCTIONDATAACTIVATECHOICE_H
#define FNV_BGSENTRYPOINTFUNCTIONDATAACTIVATECHOICE_H

#include "layout_support.h"
#include "BGSEntryPointFunctionData.h"
#pragma pack(push, 4)
class BGSEntryPointFunctionDataActivateChoice : public BGSEntryPointFunctionData
{
  public:
    BSStringT<char> m_kChoiceText;  // +0x4
    Script* m_pChoiceScript;        // +0xC
    unsigned int cFlags;            // +0x10
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEntryPointFunctionDataActivateChoice) == 0x14);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataActivateChoice, m_kChoiceText) == 0x4);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataActivateChoice, m_pChoiceScript) == 0xC);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointFunctionDataActivateChoice, cFlags) == 0x10);
#endif
