// Authored check-time copy of the canonical generated BSSysInfoSystemUtility
// layout. Content mirrors include/BSSysInfoSystemUtility.h; the member
// declaration appended at the end is the canonical generated-header addition
// Initialize, and the PC disassembly of 0x00af3b80). The shared
// FNV_BSSYSINFOSYSTEMUTILITY_H guard keeps this copy conflict-free until the
// canonical header is regenerated and this file retires.
#ifndef FNV_BSSYSINFOSYSTEMUTILITY_H
#define FNV_BSSYSINFOSYSTEMUTILITY_H

#include "layout_support.h"
#pragma pack(push, 4)
class BSSysInfoSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;                               // +0x0
    BSSysInfoSystemUtility__LANGUAGE m_eLanguage;  // +0x4
    unsigned int SystemUtilityData[16];            // +0x8
    void Initialize();
    void Destroy();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSSysInfoSystemUtility) == 0x48);
FNV_STATIC_ASSERT(offsetof(BSSysInfoSystemUtility, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSSysInfoSystemUtility, m_eLanguage) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSSysInfoSystemUtility, SystemUtilityData) == 0x8);
#endif
