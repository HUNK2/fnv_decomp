// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSDECALMANAGER_H
#define FNV_BGSDECALMANAGER_H

#include "layout_support.h"
#include "layout_support.h"
class BGSDecalManager;
class BSRenderedTexture;
class BSShaderAccumulator;
class NiCamera;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___;
class NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator;
class NiTListItem_BGSDecalEmitter___;
class NiTListItem_NiPointer_BSTempEffectSimpleDecal___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_BGSDecalEmitter___;
class NiTPointerList_NiPointer_BSTempEffectSimpleDecal___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___;
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
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
{
  public:
    NiTListItem_NiPointer_BSTempEffectSimpleDecal___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_BSTempEffectSimpleDecal___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(NiTListItem<NiPointer<BSTempEffectSimpleDecal> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(NiTListItem<NiPointer<BSTempEffectSimpleDecal> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*, NiTListItem<NiPointer<BSTempEffectSimpleDecal> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*, NiTListItem<NiPointer<BSTempEffectSimpleDecal> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___,
                           m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___,
                           m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___,
                           m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(const NiPointer<BSTempEffectSimpleDecal>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(const NiPointer<BSTempEffectSimpleDecal>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*, const NiPointer<BSTempEffectSimpleDecal>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*, const NiPointer<BSTempEffectSimpleDecal>&)
    // const NiPointer<BSTempEffectSimpleDecal>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // const NiPointer<BSTempEffectSimpleDecal>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // const NiPointer<BSTempEffectSimpleDecal>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*)
    // const NiPointer<BSTempEffectSimpleDecal>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*&)
    // const NiPointer<BSTempEffectSimpleDecal>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*&)
    // NiPointer<BSTempEffectSimpleDecal> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // NiPointer<BSTempEffectSimpleDecal> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // NiPointer<BSTempEffectSimpleDecal> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(const NiPointer<BSTempEffectSimpleDecal>&)
    // NiPointer<BSTempEffectSimpleDecal> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(const NiPointer<BSTempEffectSimpleDecal>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<BSTempEffectSimpleDecal> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(NiTListItem<NiPointer<BSTempEffectSimpleDecal> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___) ==
                  12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_BSTempEffectSimpleDecal___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<BSTempEffectSimpleDecal> > at +0x0, size 12
    // NiTPointerList<NiPointer<BSTempEffectSimpleDecal> >
    // void __cdecl NiTPointerList<NiPointer<BSTempEffectSimpleDecal> >::*()
    // NiTPointerList<NiPointer<BSTempEffectSimpleDecal> >& __cdecl NiTPointerList<NiPointer<BSTempEffectSimpleDecal> >::*(const NiTPointerList<NiPointer<BSTempEffectSimpleDecal> >&)
    // void* __cdecl NiTPointerList<NiPointer<BSTempEffectSimpleDecal> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_BSTempEffectSimpleDecal___) == 12);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
{
  public:
    NiTListItem_BGSDecalEmitter___* m_pkHead;                                                           // +0x0, 4 bytes
    NiTListItem_BGSDecalEmitter___* m_pkTail;                                                           // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator m_kItemCount;  // +0x8, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___) == 12);
#pragma pack(push, 4)
class NiTPointerList_BGSDecalEmitter___ : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_BGSDecalEmitter___) == 12);
#pragma pack(push, 4)
class BGSDecalManager
{
  public:
    NiPointer<BSRenderedTexture> m_pDecalRenderTexture;  // +0x0, 4 bytes
    bool m_bDecalRenderingEnabled;                       // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    NiTPointerList_NiPointer_BSTempEffectSimpleDecal___ m_kSimpleDecalList;  // +0x8, 12 bytes
    NiTPointerList_BGSDecalEmitter___ BGSDecalEmitterList;                   // +0x14, 12 bytes
    NiPointer<BSShaderAccumulator> m_spShaderAccumulator;                    // +0x20, 4 bytes
    NiPointer<NiCamera> m_pDecalCamera;                                      // +0x24, 4 bytes
    void RenderDecals();
    void RemoveDecal(BSTempEffectSimpleDecal*);
    // void __cdecl BGSDecalManager::*()
    // BGSDecalManager* __cdecl BGSDecalManager::*()
    // bool __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*(BSTempEffectSimpleDecal*)
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // bool __cdecl BGSDecalManager::*(TESObjectREFR*, BGSDecalManager::DECAL_TYPE)
    // void __cdecl BGSDecalManager::*(int, NiPoint3*, NiPoint3*, float, float, float, float)
    // BGSDecalManager
    // BGSDecalManager& __cdecl BGSDecalManager::*(const BGSDecalManager&)
    // void* __cdecl BGSDecalManager::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDecalManager) == 40);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_pDecalRenderTexture) == 0);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_bDecalRenderingEnabled) == 4);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_kSimpleDecalList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, BGSDecalEmitterList) == 20);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_spShaderAccumulator) == 32);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_pDecalCamera) == 36);
#endif
