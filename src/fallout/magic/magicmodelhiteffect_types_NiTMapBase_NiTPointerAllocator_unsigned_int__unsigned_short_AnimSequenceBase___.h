// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef NITMAPBASE_UINT_USHORT_ANIMSEQ_H
#define NITMAPBASE_UINT_USHORT_ANIMSEQ_H

#include "layout_support.h"
#include "layout_support.h"
class AnimSequenceBase;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___;
class NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase_____AntiBloatAllocator;
class NiTPointerAllocator_unsigned_int_;
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
class NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase_____AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___
{
  public:
    void** m_ppVirtualMethodTable;                                                 // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                       // +0x4, 4 bytes
    NiTMapItem<unsigned short, AnimSequenceBase*>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase_____AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>
    // unsigned int __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*()
    // bool __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*()
    // void __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*(unsigned short, AnimSequenceBase*)
    // bool __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*(unsigned short)
    // void __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*()
    // bool __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*(unsigned short, AnimSequenceBase*&)
    // void* __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*()
    // void __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*(void*&, unsigned short&, AnimSequenceBase*&)
    // NiTMapItem<unsigned short,AnimSequenceBase *>* __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*(unsigned short)
    // NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>& __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*(const NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>&)
    // void __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*()
    // void __cdecl NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned short,AnimSequenceBase *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___) == 16);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___, m_ppVirtualMethodTable) ==
                  0);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_NiTPointerAllocator_unsigned_int__unsigned_short_AnimSequenceBase___,
                           m_kItemCount) == 12);
#endif
