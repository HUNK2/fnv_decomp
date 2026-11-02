#ifndef FNV_ENTRYPOINTPERKENTRYDATA_H
#define FNV_ENTRYPOINTPERKENTRYDATA_H

#include "layout_support.h"
#pragma pack(push, 4)
class PerkEntryPointData
{
  public:
    unsigned char m_ucEntryPoint;      // +0x0
    unsigned char m_ucFunction;        // +0x1
    unsigned char m_ucConditionCount;  // +0x2
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PerkEntryPointData) == 0x3);
FNV_STATIC_ASSERT(offsetof(PerkEntryPointData, m_ucEntryPoint) == 0x0);
FNV_STATIC_ASSERT(offsetof(PerkEntryPointData, m_ucFunction) == 0x1);
FNV_STATIC_ASSERT(offsetof(PerkEntryPointData, m_ucConditionCount) == 0x2);
#endif
