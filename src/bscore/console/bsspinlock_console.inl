
#include "layout_support.h"

#pragma pack(push, 4)
class FNV_ALIGN(32) RecursiveSpinLock
{
public:
    volatile unsigned int m_uiOwningThreadID; // +0x0
    unsigned int m_uiRecursionCount;             // +0x4
    unsigned char layoutPadding8[24];

    void Lock();
};
#pragma pack(pop)

void __fastcall Sleep(unsigned long milliseconds);

// @fnv 0x00868250
void RecursiveSpinLock::Lock()
{
    Sleep(m_uiOwningThreadID);
}
