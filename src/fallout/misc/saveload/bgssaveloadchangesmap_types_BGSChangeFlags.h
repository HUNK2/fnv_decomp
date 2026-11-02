// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSCHANGEFLAGS_H
#define FNV_BGSCHANGEFLAGS_H

#include "layout_support.h"
class FormChangeMask;
#pragma pack(push, 4)
class FormChangeMask
{
  public:
    int iFlags;  // +0x0, 4 bytes
    FormChangeMask();
    int FUN_00559450();
    bool ContainsAnyFlags(int flags);
    // FormChangeMask
    // bool __cdecl FormChangeMask::*(int)
    // bool __cdecl FormChangeMask::*(int)
    // bool __cdecl FormChangeMask::*(int)
    // void __cdecl FormChangeMask::*(int)
    // void __cdecl FormChangeMask::*(int)
    // void __cdecl FormChangeMask::*(int)
    // FormChangeMask __cdecl FormChangeMask::*(int)
    // int __cdecl FormChangeMask::*()
    // const char* __cdecl FormChangeMask::*(int, unsigned int, bool)
    // const char* __cdecl FormChangeMask::*(int, unsigned int)
    // bool __cdecl FormChangeMask::*(int, unsigned int, unsigned int)
    // bool __cdecl FormChangeMask::*(TESForm*)
    // FormChangeMask __cdecl FormChangeMask::*(FormChangeMask, FormChangeMask, unsigned int, bool)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormChangeMask) == 4);
FNV_STATIC_ASSERT(offsetof(FormChangeMask, iFlags) == 0);
#endif
