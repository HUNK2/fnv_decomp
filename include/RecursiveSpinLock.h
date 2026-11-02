#ifndef FNV_BSSPINLOCK_H
#define FNV_BSSPINLOCK_H
#include "layout_support.h"
#pragma pack(push, 4)
class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;  // +0x0
    unsigned int m_uiRecursionCount;              // +0x4
    unsigned int layoutPadding8[6];
    void Lock(const char* name);
    FNV_FORCEINLINE void Unlock()
    {
        if (--m_uiRecursionCount == 0)
            m_uiOwningThreadID = 0;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RecursiveSpinLock) == 0x20);
FNV_STATIC_ASSERT(offsetof(RecursiveSpinLock, m_uiOwningThreadID) == 0x0);
FNV_STATIC_ASSERT(offsetof(RecursiveSpinLock, m_uiRecursionCount) == 0x4);
#endif
