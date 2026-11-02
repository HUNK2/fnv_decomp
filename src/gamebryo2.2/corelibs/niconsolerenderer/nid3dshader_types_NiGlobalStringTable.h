// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIGLOBALSTRINGTABLE_H
#define FNV_NIGLOBALSTRINGTABLE_H

#include "layout_support.h"
#include "_RTL_CRITICAL_SECTION.h"
#include "layout_support.h"
class NiCriticalSection;
class NiGlobalStringTable;
class NiTPrimitiveArray_char___;
#pragma pack(push, 4)
class NiTPrimitiveArray_char___ : public NiTArray<char*, NiTMallocInterface<char*> >
{
  public:
    // base NiTArray<char *,NiTMallocInterface<char *> > at +0x0, size 16
    // NiTPrimitiveArray<char *>
    // void __cdecl NiTPrimitiveArray<char *>::*()
    // NiTPrimitiveArray<char *>& __cdecl NiTPrimitiveArray<char *>::*(const NiTPrimitiveArray<char *>&)
    // void __cdecl NiTPrimitiveArray<char *>::*()
    // void __cdecl NiTPrimitiveArray<char *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_char___) == 16);
#pragma pack(push, 4)
class NiCriticalSection
{
  public:
    _RTL_CRITICAL_SECTION m_kCriticalSection;  // +0x0, 28 bytes
    unsigned long m_ulThreadOwner;             // +0x1C, 4 bytes
    unsigned int m_uiLockCount;                // +0x20, 4 bytes
    unsigned char layoutPadding24[92];
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // void __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // unsigned int __cdecl NiCriticalSection::*()
    // void* __cdecl NiCriticalSection::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiCriticalSection) == 128);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_kCriticalSection) == 0);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_ulThreadOwner) == 28);
FNV_STATIC_ASSERT(offsetof(NiCriticalSection, m_uiLockCount) == 32);
#pragma pack(push, 4)
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
    NiTPrimitiveArray_char___ m_kHashArray[513];  // +0x0, 8208 bytes
    unsigned char layoutPadding2010[112];
    NiCriticalSection m_kCriticalSection;  // +0x2080, 128 bytes
    // char* __cdecl NiGlobalStringTable::*(const char*)
    // void __cdecl NiGlobalStringTable::*(char*&)
    // void __cdecl NiGlobalStringTable::*(char*&)
    // const char* __cdecl NiGlobalStringTable::*(char*&)
    // unsigned int __cdecl NiGlobalStringTable::*(char*&)
    // unsigned int __cdecl NiGlobalStringTable::*(char*&)
    // bool __cdecl NiGlobalStringTable::*(char*&)
    // void __cdecl NiGlobalStringTable::*()
    // void __cdecl NiGlobalStringTable::*()
    // void __cdecl NiGlobalStringTable::*()
    // unsigned int __cdecl NiGlobalStringTable::*(unsigned int)
    // unsigned int __cdecl NiGlobalStringTable::*()
    // unsigned int __cdecl NiGlobalStringTable::*()
    // char* __cdecl NiGlobalStringTable::*(const char*, unsigned int)
    // void __cdecl NiGlobalStringTable::*(char*&, unsigned int)
    // void __cdecl NiGlobalStringTable::*(char*&)
    // void __cdecl NiGlobalStringTable::*()
    // char* __cdecl NiGlobalStringTable::*(char*&)
    // unsigned int __cdecl NiGlobalStringTable::*(const char*, unsigned int)
    // NiGlobalStringTable
    // void __cdecl NiGlobalStringTable::*()
    // NiGlobalStringTable& __cdecl NiGlobalStringTable::*(const NiGlobalStringTable&)
    // void* __cdecl NiGlobalStringTable::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiGlobalStringTable) == 8448);
FNV_STATIC_ASSERT(offsetof(NiGlobalStringTable, m_kHashArray) == 0);
FNV_STATIC_ASSERT(offsetof(NiGlobalStringTable, m_kCriticalSection) == 8320);
#endif
