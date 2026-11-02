// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITSET_UNSIGNED_INT_NITMALLOCINTERFACE_UNSIGNED_INT_H
#define FNV_NITSET_UNSIGNED_INT_NITMALLOCINTERFACE_UNSIGNED_INT_H

#include "layout_support.h"
class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___;
#pragma pack(push, 4)
class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
  public:
    unsigned int* m_pBase;               // +0x0, 4 bytes
    unsigned int m_uiElementCount;       // +0x4, 4 bytes
    unsigned int m_uiAllocatedCapacity;  // +0x8, 4 bytes
    // NiTSet<unsigned int,NiTMallocInterface<unsigned int> >
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // unsigned int __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // unsigned int* __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // GetAt
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
    // bool __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // bool __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int, const unsigned int&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // Realloc
    // int __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const unsigned int&)
    // NiTSet<unsigned int,NiTMallocInterface<unsigned int> >& __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(const NiTSet<unsigned int,NiTMallocInterface<unsigned int> >&)
    // void __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*()
    // void* __cdecl NiTSet<unsigned int,NiTMallocInterface<unsigned int> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_pBase) == 0);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_uiElementCount) == 4);
FNV_STATIC_ASSERT(offsetof(NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___, m_uiAllocatedCapacity) == 8);
#endif
