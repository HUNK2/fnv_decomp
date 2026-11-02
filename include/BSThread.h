// Source layout: BSThread. PC corrections are in generate_headers.py.
#ifndef FNV_BSTHREAD_H
#define FNV_BSTHREAD_H

#include "layout_support.h"
#include "RecursiveLock.h"
#pragma pack(push, 4)
class BSThread
{
  public:
    void** m_ppVirtualMethodTable;                    // +0x0
    RecursiveLock CriticalSection;  // +0x4
    void* m_pThreadHandle;              // +0x2C
    void* m_pCurrentThreadHandle;       // +0x30
    unsigned int m_uiCreatedThreadId;   // +0x34
    unsigned int m_uiCurrentThreadId;   // +0x38
    bool m_bThreadStarted;              // +0x3C
    unsigned char layoutPadding3D;
    unsigned short layoutPadding3E;
    void SetSchedulingPriority(unsigned int);
    unsigned int ThreadProc();
    void SetName(const char*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSThread) == 0x40);
FNV_STATIC_ASSERT(offsetof(BSThread, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSThread, CriticalSection) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSThread, m_pThreadHandle) == 0x2C);
FNV_STATIC_ASSERT(offsetof(BSThread, m_pCurrentThreadHandle) == 0x30);
FNV_STATIC_ASSERT(offsetof(BSThread, m_uiCreatedThreadId) == 0x34);
FNV_STATIC_ASSERT(offsetof(BSThread, m_uiCurrentThreadId) == 0x38);
FNV_STATIC_ASSERT(offsetof(BSThread, m_bThreadStarted) == 0x3C);
#endif
