#ifndef FNV_BSCRITICALSECTION_H
#define FNV_BSCRITICALSECTION_H

#include "layout_support.h"
#include "_RTL_CRITICAL_SECTION.h"
#pragma pack(push, 4)
class RecursiveLock
{
  public:
    _RTL_CRITICAL_SECTION CriticalSection;  // +0x0
    unsigned long m_uiFirstValue;           // +0x1C
    unsigned long m_uiSecondValue;          // +0x20
    int m_uiRecursionCount;                        // +0x24
    void Leave();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RecursiveLock) == 0x28);
FNV_STATIC_ASSERT(offsetof(RecursiveLock, CriticalSection) == 0x0);
FNV_STATIC_ASSERT(offsetof(RecursiveLock, m_uiFirstValue) == 0x1C);
FNV_STATIC_ASSERT(offsetof(RecursiveLock, m_uiSecondValue) == 0x20);
FNV_STATIC_ASSERT(offsetof(RecursiveLock, m_uiRecursionCount) == 0x24);
#endif
