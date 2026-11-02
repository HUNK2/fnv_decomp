// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERACCUMULATOR_PRIVATE_BATCHRENDERER_H
#define FNV_BSSHADERACCUMULATOR_PRIVATE_BATCHRENDERER_H

#include "bsshaderaccumulator_types.h"
#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class BSBatchRenderer;
class BSBatchRenderer__GeometryGroup;
class BSBatchRenderer__PassGroup;
class BSBatchRenderer__RenderContext;
class DFALL_NiTMapItem_unsigned_int_unsigned_int___;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___;
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator;
class NiTListItem_BSBatchRenderer__GeometryGroup___;
class NiTMap_unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_BSBatchRenderer__GeometryGroup___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___;
class DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*()
    // void __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*(void*)
};
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_unsigned_int_unsigned_int___) == 1);
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // base DFALL<NiTMapItem<unsigned int,unsigned int> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
FNV_STATIC_ASSERT(
    sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator,
             m_uiCount) == 0);
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                // +0x4, 4 bytes
    NiTMapItem<unsigned int, unsigned int>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(void*&, unsigned int&, unsigned int&)
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>& __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(const NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
};
FNV_STATIC_ASSERT(sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_) == 16);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_kItemCount) == 12);
class NiTMap_unsigned_int_unsigned_int_
    : public NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    // base NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int> at +0x0, size 16
    // NiTMap<unsigned int,unsigned int>
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMap<unsigned int,unsigned int>::*()
    // void __cdecl NiTMap<unsigned int,unsigned int>::*(NiTMapItem<unsigned int,unsigned int>*)
    // NiTMap<unsigned int,unsigned int>& __cdecl NiTMap<unsigned int,unsigned int>::*(const NiTMap<unsigned int,unsigned int>&)
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
};
FNV_STATIC_ASSERT(sizeof(NiTMap_unsigned_int_unsigned_int_) == 16);
#ifndef FNV_BSSHADERACCUMULATOR_PRIVATE_DECL_NITABSTRACTPOOLALLOCATOR_UNSIGNED_INT_
#define FNV_BSSHADERACCUMULATOR_PRIVATE_DECL_NITABSTRACTPOOLALLOCATOR_UNSIGNED_INT_
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#endif
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#ifndef FNV_BSSHADERACCUMULATOR_PRIVATE_DECL_NITPOINTERALLOCATOR_UNSIGNED_INT_
#define FNV_BSSHADERACCUMULATOR_PRIVATE_DECL_NITPOINTERALLOCATOR_UNSIGNED_INT_
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
#endif
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
FNV_STATIC_ASSERT(
    sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(
    offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator,
             m_uiCount) == 0);
class NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
{
  public:
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_BSBatchRenderer__GeometryGroup___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___, m_pkHead) ==
                  0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___, m_pkTail) ==
                  4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___,
                           m_kItemCount) == 8);
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
{
  public:
};
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___) == 12);
class NiTPointerList_BSBatchRenderer__GeometryGroup___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__BSBatchRenderer__GeometryGroup___
{
  public:
};
FNV_STATIC_ASSERT(sizeof(NiTPointerList_BSBatchRenderer__GeometryGroup___) == 12);
class BSBatchRenderer : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    BSBatchRenderer__PassGroup* m_pPassBucketEntries;           // +0x8, 4 bytes
    NiTMap_unsigned_int_unsigned_int_ m_kGroupIndexMap;         // +0xC, 16 bytes
    unsigned int m_uiGroupCount;                                // +0x1C, 4 bytes
    unsigned int m_uiPassCount;                                 // +0x20, 4 bytes
    unsigned int m_uiBucketCount;                               // +0x24, 4 bytes
    BSBatchRenderer__RenderContext* m_pGeometryGroupAllocator;  // +0x28, 4 bytes
    BSSimpleList<unsigned short> m_kActivePassList;             // +0x2C, 8 bytes
    int m_iActiveGroupCount;                                    // +0x34, 4 bytes
    bool m_bHasActiveGroups;                                    // +0x38, 1 bytes
    unsigned char layoutPadding39[3];
    BSBatchRenderer__GeometryGroup* m_pGeometryGroups[13];                  // +0x3C, 52 bytes
    BSBatchRenderer__GeometryGroup* m_pSecondaryGeometryGroups[2];          // +0x70, 8 bytes
    NiTPointerList_BSBatchRenderer__GeometryGroup___ AlphaGeometryList[2];  // +0x78, 24 bytes
    BSBatchRenderer__GeometryGroup* m_pAlphaGeometryGroups[2];              // +0x90, 8 bytes
    // const NiRTTI* __cdecl BSBatchRenderer::*()
    // BSBatchRenderer
    // void __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*(bool)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&, bool&)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&)
    // bool __cdecl BSBatchRenderer::*(unsigned int, int&)
    // void __cdecl BSBatchRenderer::*(unsigned int, int, bool&)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&, bool&, bool)
    // bool __cdecl BSBatchRenderer::*(unsigned int&, int&, bool&, bool)
    // void __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSBatchRenderer::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSBatchRenderer::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSBatchRenderer::*(unsigned int)
    // void __cdecl BSBatchRenderer::*(unsigned int)
    // void __cdecl BSBatchRenderer::*(const NiBound&, bool, const NiCamera*, bool)
    // void __cdecl BSBatchRenderer::*()
    // bool __cdecl BSBatchRenderer::*()
    // bool __cdecl BSBatchRenderer::*()
    // void __cdecl BSBatchRenderer::*(BSBatchRenderer::GEOMETRY_GROUP_ENUM, bool)
    // void __cdecl BSBatchRenderer::*(const NiCamera*, bool)
    // float __cdecl BSBatchRenderer::*(unsigned int, const NiCamera*, bool)
    // void __cdecl BSBatchRenderer::*(unsigned int, const NiCamera*, bool, float)
    // void __cdecl BSBatchRenderer::*(int)
    // int __cdecl BSBatchRenderer::*(BSBatchRenderer::GEOMETRY_GROUP_ENUM)
    // BSBatchRenderer& __cdecl BSBatchRenderer::*(const BSBatchRenderer&)
};
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer) == 152);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_pPassBucketEntries) == 8);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_kGroupIndexMap) == 12);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_uiGroupCount) == 28);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_uiPassCount) == 32);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_uiBucketCount) == 36);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_pGeometryGroupAllocator) == 40);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_kActivePassList) == 44);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_iActiveGroupCount) == 52);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_bHasActiveGroups) == 56);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_pGeometryGroups) == 60);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_pSecondaryGeometryGroups) == 112);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, AlphaGeometryList) == 120);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer, m_pAlphaGeometryGroups) == 144);
#endif
