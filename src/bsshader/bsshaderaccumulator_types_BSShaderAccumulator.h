// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERACCUMULATOR_H
#define FNV_BSSHADERACCUMULATOR_H

#include "layout_support.h"
#include "NiObject.h"
#include "_RTL_CRITICAL_SECTION.h"
#include "layout_support.h"
class BSBatchRenderer;
class BSBatchRenderer__RenderContext;
class RenderQuery;
class BSRenderedTexture;
class BSShaderAccumulator;
class BSShaderProperty__RenderPass;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____ListItem;
class NiAVObject;
class NiAccumulator;
class NiAlphaAccumulator;
class NiBackToFrontAccumulator;
class NiCamera;
class RgbaColor;
class NiCriticalSection;
class NiGeometry;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator;
class NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___;
class NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume_____AntiBloatAllocator;
class NiTListItem_NiGeometry___;
class NiTListItem_ReferenceVolume___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiGeometry___;
class NiTPointerList_ReferenceVolume___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiGeometry___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___;
class ShadowSceneLight;
class ShadowSceneNode;
class RenderQueryState;
enum BSShaderAccumulator__etAccumulationMode
{
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMNORMAL = 0,
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMDEPTHMAP = 1,
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMLOD = 2,
    BSShaderAccumulator__etAccumulationMode_BSSA_ACCUMNONE = 3
};
enum BSShaderManager__etRenderMode
{
    BSShaderManager__etRenderMode_BSSM_RENDER_NORMAL = 0,
    BSShaderManager__etRenderMode_BSSM_RENDER_NUMLIGHTS = 1,
    BSShaderManager__etRenderMode_BSSM_RENDER_NUMPASSES = 2,
    BSShaderManager__etRenderMode_BSSM_RENDER_SINGLEPASS = 3,
    BSShaderManager__etRenderMode_BSSM_RENDER_TEXUSAGE = 4,
    BSShaderManager__etRenderMode_BSSM_RENDER_DEGRADE = 5,
    BSShaderManager__etRenderMode_BSSM_RENDER_OVERDRAW = 6,
    BSShaderManager__etRenderMode_BSSM_RENDER_DEPTHMAP = 7,
    BSShaderManager__etRenderMode_BSSM_RENDER_CONSTALPHA = 8,
    BSShaderManager__etRenderMode_BSSM_RENDER_LOCALMAP = 9,
    BSShaderManager__etRenderMode_BSSM_RENDER_INTERFACE = 10,
    BSShaderManager__etRenderMode_BSSM_RENDER_FROZEN = 11,
    BSShaderManager__etRenderMode_BSSM_RENDER_FIRST_PERSON = 12,
    BSShaderManager__etRenderMode_BSSM_RENDER_SCREEN_SPLATTER = 13,
    BSShaderManager__etRenderMode_BSSM_RENDER_WATER_DEPTH = 14,
    BSShaderManager__etRenderMode_BSSM_RENDER_SILHOUETTE = 15,
    BSShaderManager__etRenderMode_BSSM_RENDER_COUNT = 16
};
#pragma pack(push, 4)
class NiAccumulator : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    const NiCamera* m_pkAccumulationCamera;  // +0x8, 4 bytes
    // const NiRTTI* __cdecl NiAccumulator::*()
    // void __cdecl NiAccumulator::*(NiStream&)
    // void __cdecl NiAccumulator::*(NiStream&)
    // bool __cdecl NiAccumulator::*(NiStream&)
    // void __cdecl NiAccumulator::*(NiStream&)
    // bool __cdecl NiAccumulator::*(NiObject*)
    // NiAccumulator
    // void __cdecl NiAccumulator::*()
    // bool __cdecl NiAccumulator::*()
    // NiAccumulator& __cdecl NiAccumulator::*(const NiAccumulator&)
    // void __cdecl NiAccumulator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiAccumulator) == 12);
FNV_STATIC_ASSERT(offsetof(NiAccumulator, m_pkAccumulationCamera) == 8);
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
class NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___
{
  public:
    NiTListItem_NiGeometry___* m_pkHead;                                                           // +0x0, 4 bytes
    NiTListItem_NiGeometry___* m_pkTail;                                                           // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiTListItem<NiGeometry *>*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiTListItem<NiGeometry *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*, NiTListItem<NiGeometry *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*, NiTListItem<NiGeometry *>*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiGeometry___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiGeometry___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiGeometry *> at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*, NiGeometry*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*, NiGeometry*&)
    // NiGeometry*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*)
    // NiGeometry*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*&)
    // NiGeometry*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*&)
    // NiGeometry* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&)
    // NiGeometry* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiGeometry *>* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiTListItem<NiGeometry *>*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiGeometry___) == 12);
#pragma pack(push, 4)
class NiTPointerList_NiGeometry___ : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiGeometry___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiGeometry *> at +0x0, size 12
    // NiTPointerList<NiGeometry *>
    // void __cdecl NiTPointerList<NiGeometry *>::*()
    // NiTPointerList<NiGeometry *>& __cdecl NiTPointerList<NiGeometry *>::*(const NiTPointerList<NiGeometry *>&)
    // void* __cdecl NiTPointerList<NiGeometry *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiGeometry___) == 12);
#pragma pack(push, 4)
class NiBackToFrontAccumulator : public NiAccumulator
{
  public:
    // base NiAccumulator at +0x0, size 12
    NiTPointerList_NiGeometry___ m_kUnsortedGeometryList;  // +0xC, 12 bytes
    NiTPointerList_NiGeometry___* m_pkGeometryList;        // +0x18, 4 bytes
    int m_iGeometryCount;                                  // +0x1C, 4 bytes
    int m_iGeometryCapacity;                               // +0x20, 4 bytes
    NiGeometry** m_ppGeometries;                           // +0x24, 4 bytes
    float* m_pfGeometrySortValues;                         // +0x28, 4 bytes
    int m_iCurrentItem;                                    // +0x2C, 4 bytes
    // const NiRTTI* __cdecl NiBackToFrontAccumulator::*()
    // void __cdecl NiBackToFrontAccumulator::*(NiStream&)
    // void __cdecl NiBackToFrontAccumulator::*(NiStream&)
    // bool __cdecl NiBackToFrontAccumulator::*(NiStream&)
    // void __cdecl NiBackToFrontAccumulator::*(NiStream&)
    // bool __cdecl NiBackToFrontAccumulator::*(NiObject*)
    // NiObject* __cdecl NiBackToFrontAccumulator::*()
    // NiBackToFrontAccumulator
    // void __cdecl NiBackToFrontAccumulator::*()
    // void __cdecl NiBackToFrontAccumulator::*(NiVisibleArray&)
    // void __cdecl NiBackToFrontAccumulator::*()
    // void __cdecl NiBackToFrontAccumulator::*(int, int)
    // float __cdecl NiBackToFrontAccumulator::*(int, int)
    // NiBackToFrontAccumulator& __cdecl NiBackToFrontAccumulator::*(const NiBackToFrontAccumulator&)
    // void __cdecl NiBackToFrontAccumulator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBackToFrontAccumulator) == 48);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_kUnsortedGeometryList) == 12);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_pkGeometryList) == 24);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_iGeometryCount) == 28);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_iGeometryCapacity) == 32);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_ppGeometries) == 36);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_pfGeometrySortValues) == 40);
FNV_STATIC_ASSERT(offsetof(NiBackToFrontAccumulator, m_iCurrentItem) == 44);
#pragma pack(push, 4)
class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
  public:
    // base NiBackToFrontAccumulator at +0x0, size 48
    bool m_bSkipObjectsWithFlag13;  // +0x30, 1 bytes
    bool m_bSkipObjectsWithFlag14;  // +0x31, 1 bytes
    bool m_bInterface;              // +0x32, 1 bytes
    unsigned char layoutPadding33[1];
    // const NiRTTI* __cdecl NiAlphaAccumulator::*()
    // void __cdecl NiAlphaAccumulator::*(NiStream&)
    // void __cdecl NiAlphaAccumulator::*(NiStream&)
    // bool __cdecl NiAlphaAccumulator::*(NiStream&)
    // void __cdecl NiAlphaAccumulator::*(NiStream&)
    // bool __cdecl NiAlphaAccumulator::*(NiObject*)
    // NiObject* __cdecl NiAlphaAccumulator::*()
    // NiAlphaAccumulator
    // void __cdecl NiAlphaAccumulator::*()
    // void __cdecl NiAlphaAccumulator::*(bool)
    // bool __cdecl NiAlphaAccumulator::*()
    // void __cdecl NiAlphaAccumulator::*(bool)
    // bool __cdecl NiAlphaAccumulator::*()
    // void __cdecl NiAlphaAccumulator::*(bool)
    // void __cdecl NiAlphaAccumulator::*(NiVisibleArray&)
    // bool __cdecl NiAlphaAccumulator::*(NiGeometry*)
    // void __cdecl NiAlphaAccumulator::*()
    // NiAlphaAccumulator& __cdecl NiAlphaAccumulator::*(const NiAlphaAccumulator&)
    // void __cdecl NiAlphaAccumulator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiAlphaAccumulator) == 52);
FNV_STATIC_ASSERT(offsetof(NiAlphaAccumulator, m_bSkipObjectsWithFlag13) == 48);
FNV_STATIC_ASSERT(offsetof(NiAlphaAccumulator, m_bSkipObjectsWithFlag14) == 49);
FNV_STATIC_ASSERT(offsetof(NiAlphaAccumulator, m_bInterface) == 50);
#pragma pack(push, 4)
class RenderQueryState
{
  public:
    RenderQuery* m_pRenderQuery;  // +0x0, 4 bytes
    bool m_bQueryPending;         // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    float m_fQueryValue;           // +0x8, 4 bytes
    unsigned int m_uiQueryFlags;   // +0xC, 4 bytes
    unsigned int m_uiQueryResult;  // +0x10, 4 bytes
    // void __cdecl RenderQueryState::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RenderQueryState) == 20);
FNV_STATIC_ASSERT(offsetof(RenderQueryState, m_pRenderQuery) == 0);
FNV_STATIC_ASSERT(offsetof(RenderQueryState, m_bQueryPending) == 4);
FNV_STATIC_ASSERT(offsetof(RenderQueryState, m_fQueryValue) == 8);
FNV_STATIC_ASSERT(offsetof(RenderQueryState, m_uiQueryFlags) == 12);
FNV_STATIC_ASSERT(offsetof(RenderQueryState, m_uiQueryResult) == 16);
#pragma pack(push, 4)
class BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int ItemUpdateArray;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator,
                           ItemUpdateArray) == 0);
#pragma pack(push, 4)
class BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___
{
  public:
    void** m_ppVirtualMethodTable;                                                                                  // +0x0, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____ListItem* pHead;               // +0x4, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____ListItem* pTail;               // +0x8, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____ListItem* m_pCachedListItems;  // +0xC, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry_____AntiBloatAllocator Allocator;  // +0x10, 4 bytes
    // BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>
    // unsigned int __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // bool __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&)
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&)
    // NiGeometry*& __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry*& __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry*& __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*)
    // void* __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void* __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // NiGeometry*& __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*&)
    // NiGeometry*& __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(void*&)
    // void* __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(NiGeometry*&, void*)
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(int __cdecl (void*, void*)*)
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
    // BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>& __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*(const BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>&)
    // void __cdecl BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___) == 20);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___, pHead) == 4);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___, pTail) == 8);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___, m_pCachedListItems) ==
                  12);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___, Allocator) == 16);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___
{
  public:
    NiTListItem_ReferenceVolume___* m_pkHead;                                                           // +0x0, 4 bytes
    NiTListItem_ReferenceVolume___* m_pkTail;                                                           // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume_____AntiBloatAllocator m_kItemCount;  // +0x8, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___) == 12);
#pragma pack(push, 4)
class NiTPointerList_ReferenceVolume___ : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__ReferenceVolume___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_ReferenceVolume___) == 12);
#pragma pack(push, 4)
class RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
    // void __cdecl RgbaColor::*(float, float, float, float)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor __cdecl RgbaColor::*(const RgbaColor&)
    // operator-
    // operator*
    // operator/
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // operator*=
    // operator/=
    // void __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl RgbaColor::*(const char*)
    // float __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
#pragma pack(push, 4)
class BSShaderProperty__RenderPass
{
  public:
    NiGeometry* m_pShaderGeometry;             // +0x0, 4 bytes
    unsigned short m_usShaderPassType;         // +0x4, 2 bytes
    unsigned char m_ucLightIndex;              // +0x6, 1 bytes
    bool m_bIsBest;                            // +0x7, 1 bytes
    bool m_bRendered;                          // +0x8, 1 bytes
    unsigned char m_ucLightCount;              // +0x9, 1 bytes
    unsigned char m_ucLightCapacity;           // +0xA, 1 bytes
    unsigned char m_ucPassIndex;               // +0xB, 1 bytes
    ShadowSceneLight** m_ppShadowSceneLights;  // +0xC, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderProperty__RenderPass) == 16);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_pShaderGeometry) == 0);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_usShaderPassType) == 4);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_ucLightIndex) == 6);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_bIsBest) == 7);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_bRendered) == 8);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_ucLightCount) == 9);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_ucLightCapacity) == 10);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_ucPassIndex) == 11);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPass, m_ppShadowSceneLights) == 12);
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
class BSShaderAccumulator : public NiAlphaAccumulator
{
  public:
    // base NiAlphaAccumulator at +0x0, size 52
    BSShaderAccumulator__etAccumulationMode m_eAccumulationMode;  // +0x34, 4 bytes
    bool m_bUseFirstPersonCamera;                                 // +0x38, 1 bytes
    bool m_bAccumulationFlag;                                     // +0x39, 1 bytes
    bool ShaderAccumulationState;                                 // +0x3A, 1 bytes
    unsigned char layoutPadding3B[1];
    unsigned int m_uiAccumulationFlags;  // +0x3C, 4 bytes
    bool m_bSkipGeometryPass;            // +0x40, 1 bytes
    unsigned char layoutPadding41[3];
    float m_fRenderParameter;                   // +0x44, 4 bytes
    RenderQueryState m_akRenderQueryStates[3];  // +0x48, 60 bytes
    bool m_bFirstPersonMode;                    // +0x84, 1 bytes
    bool b1stPerson;                            // +0x85, 1 bytes
    bool m_bFlagAfterFirstPerson;               // +0x86, 1 bytes
    unsigned char layoutPadding87[1];
    unsigned short m_usRenderQueryCount;                                                         // +0x88, 2 bytes
    unsigned short GeometryRenderGroup;                                                          // +0x8A, 2 bytes
    RenderQuery** m_ppRenderQueries;                                                             // +0x8C, 4 bytes
    NiTPointerList_NiGeometry___ m_kGeometryList;                                                // +0x90, 12 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___ m_kGeometryListArray[4];   // +0x9C, 80 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__NiGeometry___ m_kGeometryListArray2[4];  // +0xEC, 80 bytes
    NiPointer<NiGeometry> GeometryCollection;                                                    // +0x13C, 4 bytes
    NiTPointerList_ReferenceVolume___ m_kReferenceVolumeList;                                    // +0x140, 12 bytes
    unsigned int m_uiGeometryCount;                                                              // +0x14C, 4 bytes
    bool m_bGeometryFlag;                                                                        // +0x150, 1 bytes
    unsigned char layoutPadding151[3];
    RgbaColor m_kDataAfterGeometryFlag;      // +0x154, 16 bytes
    bool m_bFirstSpecialPassFlag;            // +0x164, 1 bytes
    bool m_bSecondSpecialPassFlag;           // +0x165, 1 bytes
    bool m_bThirdSpecialPassFlag;            // +0x166, 1 bytes
    bool m_bFourthBooleanFlagBeforeInteger;  // +0x167, 1 bytes
    int m_iValueAfterBooleanFlags;           // +0x168, 4 bytes
    bool m_bFlagAfterInteger;                // +0x16C, 1 bytes
    unsigned char layoutPadding16D[3];
    BSBatchRenderer__RenderContext* m_pGeometryGroupAllocator;  // +0x170, 4 bytes
    BSBatchRenderer* m_pGroupRenderer[2];                       // +0x174, 8 bytes
    unsigned int* m_puiRendererOutput;                          // +0x17C, 4 bytes
    int* m_piRendererOutput;                                    // +0x180, 4 bytes
    bool* m_pbRendererOutput;                                   // +0x184, 4 bytes
    bool* m_pbRendererResults;                                  // +0x188, 4 bytes
    unsigned int m_uiRendererCount;                             // +0x18C, 4 bytes
    unsigned int ShadowSceneState;                              // +0x190, 4 bytes
    ShadowSceneNode* m_pShadowSceneNode;                        // +0x194, 4 bytes
    NiPointer<BSRenderedTexture> m_spRenderedShadowTexture;     // +0x198, 4 bytes
    BSShaderManager__etRenderMode m_eRenderMode;                // +0x19C, 4 bytes
    NiPointer<ShadowSceneLight> m_pShadowSceneLight;            // +0x1A0, 4 bytes
    BSShaderProperty__RenderPass m_eRenderPass;                 // +0x1A4, 16 bytes
    NiTPointerMap<NiAVObject*, bool> m_kAVObjectFlagMap;        // +0x1B4, 16 bytes
    unsigned char layoutPadding1C4[60];
    NiCriticalSection m_kFirstCriticalSection;            // +0x200, 128 bytes
    NiTPointerMap<NiAVObject*, bool> m_kSecondObjectMap;  // +0x280, 16 bytes
    unsigned char layoutPadding290[112];
    NiCriticalSection m_kSecondCriticalSection;  // +0x300, 128 bytes
    // const NiRTTI* __cdecl BSShaderAccumulator::*()
    // BSShaderAccumulator
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(const NiCamera*)
    // bool __cdecl BSShaderAccumulator::*(NiGeometry*)
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // void __cdecl BSShaderAccumulator::*(BSShaderAccumulator*)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(bool)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(bool)
    // void __cdecl BSShaderAccumulator::*(bool)
    // void __cdecl BSShaderAccumulator::*(bool)
    // void __cdecl BSShaderAccumulator::*(bool)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(bool)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(bool)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(ShadowSceneLight*)
    // void __cdecl BSShaderAccumulator::*(bool)
    // void __cdecl BSShaderAccumulator::*(unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&, unsigned long&)
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // unsigned int __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*(NiCamera*, BSRenderedTexture*)
    // void __cdecl BSShaderAccumulator::*(int)
    // bool __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*(NiCamera*, BSRenderedTexture*)
    // void __cdecl BSShaderAccumulator::*(NiCamera*, NiCamera*, BSRenderedTexture*)
    // void __cdecl BSShaderAccumulator::*(BSRenderedTexture*)
    // void __cdecl BSShaderAccumulator::*(NiCamera*, NiCamera*)
    // void __cdecl BSShaderAccumulator::*(NiCamera*)
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(const NiBound&, bool)
    // void __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(NiGeometry*, unsigned int, NiCamera*)
    // void __cdecl BSShaderAccumulator::*()
    // float __cdecl BSShaderAccumulator::*()
    // unsigned int __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(bool, bool)
    // void __cdecl BSShaderAccumulator::*(bool)
    // NiGeometry* __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(NiGeometry*)
    // void __cdecl BSShaderAccumulator::*(unsigned int, const NiBound&, bool)
    // void __cdecl BSShaderAccumulator::*(unsigned int)
    // bool __cdecl BSShaderAccumulator::*(unsigned int, bool)
    // unsigned int __cdecl BSShaderAccumulator::*(unsigned int)
    // void __cdecl BSShaderAccumulator::*()
    // ShadowSceneNode* __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(ShadowSceneNode*)
    // void __cdecl BSShaderAccumulator::*(bool)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(bool)
    // bool __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(int)
    // int __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*(unsigned int)
    // void __cdecl BSShaderAccumulator::*(BSRenderedTexture*)
    // const NiCamera* __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum, bool, int)
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(unsigned int, bool)
    // void __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // bool __cdecl BSShaderAccumulator::*(BSShaderManager::eBSSMPassEnum, BSShaderManager::eBSSMPassEnum)
    // BSShaderManager::etRenderMode __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(BSShaderManager::etRenderMode)
    // void __cdecl BSShaderAccumulator::*(ShadowSceneLight*)
    // ShadowSceneLight* __cdecl BSShaderAccumulator::*()
    // bool __cdecl BSShaderAccumulator::*(NiAVObject*)
    // void __cdecl BSShaderAccumulator::*()
    // RgbaColor __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*(RgbaColor&)
    // void __cdecl BSShaderAccumulator::*(unsigned int)
    // NiNode* __cdecl BSShaderAccumulator::*()
    // int __cdecl BSShaderAccumulator::*(void*, void*)
    // int __cdecl BSShaderAccumulator::*(void*, void*)
    // RenderAlphaGeometry
    // bool __cdecl BSShaderAccumulator::*(unsigned short, unsigned short)
    // bool __cdecl BSShaderAccumulator::*(unsigned int)
    // short __cdecl BSShaderAccumulator::*(unsigned short)
    // BSShaderAccumulator& __cdecl BSShaderAccumulator::*(const BSShaderAccumulator&)
    // void __cdecl BSShaderAccumulator::*()
    // void __cdecl BSShaderAccumulator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderAccumulator) == 896);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_eAccumulationMode) == 52);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bUseFirstPersonCamera) == 56);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bAccumulationFlag) == 57);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, ShaderAccumulationState) == 58);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_uiAccumulationFlags) == 60);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bSkipGeometryPass) == 64);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_fRenderParameter) == 68);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_akRenderQueryStates) == 72);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bFirstPersonMode) == 132);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, b1stPerson) == 133);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bFlagAfterFirstPerson) == 134);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_usRenderQueryCount) == 136);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, GeometryRenderGroup) == 138);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_ppRenderQueries) == 140);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kGeometryList) == 144);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kGeometryListArray) == 156);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kGeometryListArray2) == 236);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, GeometryCollection) == 316);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kReferenceVolumeList) == 320);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_uiGeometryCount) == 332);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bGeometryFlag) == 336);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kDataAfterGeometryFlag) == 340);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bFirstSpecialPassFlag) == 356);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bSecondSpecialPassFlag) == 357);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bThirdSpecialPassFlag) == 358);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bFourthBooleanFlagBeforeInteger) == 359);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_iValueAfterBooleanFlags) == 360);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_bFlagAfterInteger) == 364);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_pGeometryGroupAllocator) == 368);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_pGroupRenderer) == 372);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_puiRendererOutput) == 380);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_piRendererOutput) == 384);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_pbRendererOutput) == 388);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_pbRendererResults) == 392);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_uiRendererCount) == 396);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, ShadowSceneState) == 400);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_pShadowSceneNode) == 404);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_spRenderedShadowTexture) == 408);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_eRenderMode) == 412);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_pShadowSceneLight) == 416);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_eRenderPass) == 420);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kAVObjectFlagMap) == 436);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kFirstCriticalSection) == 512);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kSecondObjectMap) == 640);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulator, m_kSecondCriticalSection) == 768);
#endif
