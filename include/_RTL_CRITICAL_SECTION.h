// Source layout: _RTL_CRITICAL_SECTION. PC corrections are in generate_headers.py.
#ifndef FNV__RTL_CRITICAL_SECTION_H
#define FNV__RTL_CRITICAL_SECTION_H
#include "layout_support.h"
#include "_RTL_CRITICAL_SECTION___unnamed_type_Synchronization_.h"
#ifndef _WINNT_  // the Win32 SDK, when included first, defines this type
#pragma pack(push, 4)
class _RTL_CRITICAL_SECTION
{
  public:
    _RTL_CRITICAL_SECTION___unnamed_type_Synchronization_ Synchronization;  // +0x0
    long LockCount;                                                         // +0x10
    long RecursionCount;                                                    // +0x14
    void* OwningThread;                                                     // +0x18
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(_RTL_CRITICAL_SECTION) == 0x1C);
FNV_STATIC_ASSERT(offsetof(_RTL_CRITICAL_SECTION, Synchronization) == 0x0);
FNV_STATIC_ASSERT(offsetof(_RTL_CRITICAL_SECTION, LockCount) == 0x10);
FNV_STATIC_ASSERT(offsetof(_RTL_CRITICAL_SECTION, RecursionCount) == 0x14);
FNV_STATIC_ASSERT(offsetof(_RTL_CRITICAL_SECTION, OwningThread) == 0x18);
#endif
#endif
