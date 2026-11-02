// Source layout: _FILETIME. PC corrections are in generate_headers.py.
#ifndef FNV__FILETIME_H
#define FNV__FILETIME_H
#include "layout_support.h"
#ifndef _WINDEF_  // the Win32 SDK, when included first, defines this type
#pragma pack(push, 4)
class _FILETIME
{
  public:
    unsigned long dwHighDateTime;  // +0x0
    unsigned long dwLowDateTime;   // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(_FILETIME) == 0x8);
FNV_STATIC_ASSERT(offsetof(_FILETIME, dwHighDateTime) == 0x0);
FNV_STATIC_ASSERT(offsetof(_FILETIME, dwLowDateTime) == 0x4);
#endif
#endif
