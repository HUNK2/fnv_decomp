// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITPOINTERLISTBASE_NITPOINTERALLOCATOR_UNSIGNED_INT_CHAR_H
#define FNV_NITPOINTERLISTBASE_NITPOINTERALLOCATOR_UNSIGNED_INT_CHAR_H

#include "layout_support.h"
#include "layout_support.h"
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__char___;
class NiTListBase_NiTPointerAllocator_unsigned_int__char_____AntiBloatAllocator;
class NiTListItem_char___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__char___;
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__char_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__char_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__char_____AntiBloatAllocator, m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__char___
{
  public:
    NiTListItem_char___* m_pkHead;                                                           // +0x0, 4 bytes
    NiTListItem_char___* m_pkTail;                                                           // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__char_____AntiBloatAllocator m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,char *>
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(NiTListItem<char *>*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(NiTListItem<char *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*, NiTListItem<char *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*, NiTListItem<char *>*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,char *>& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(const NiTListBase<NiTPointerAllocator<unsigned int>,char *>&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,char *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__char___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__char___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__char___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__char___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__char___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__char___
{
  public:
    char* Remove(char*& item);
    // base NiTListBase<NiTPointerAllocator<unsigned int>,char *> at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(char*&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(char*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*, char*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*, char*&)
    // char*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // char*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // char*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*)
    // char*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*&)
    // char*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*&)
    // char* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // char* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // char* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(char*&)
    // char* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(char*&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(int __cdecl (void*, void*)*)
    // NiTListItem<char *>* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(NiTListItem<char *>*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,char *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__char___) == 12);
#endif
