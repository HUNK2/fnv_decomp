// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSBATCHRENDERER_GEOMETRYGROUP_H
#define FNV_BSBATCHRENDERER_GEOMETRYGROUP_H

#include "layout_support.h"
#include "layout_support.h"
class BSBatchRenderer;
class BSBatchRenderer__GeometryGroup;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator;
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem;
class NiTAbstractPoolAllocator_unsigned_int_;
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
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int ItemUpdateArray;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator,
             ItemUpdateArray) == 0);
#pragma pack(push, 4)
class BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem*
        pHead;  // +0x4, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem*
        pTail;  // +0x8, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____ListItem*
        m_pCachedListItems;  // +0xC, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass_____AntiBloatAllocator
        Allocator;  // +0x10, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___) == 20);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___,
                           pHead) == 4);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___,
                           pTail) == 8);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___,
                           m_pCachedListItems) == 12);
FNV_STATIC_ASSERT(offsetof(BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___,
                           Allocator) == 16);
#pragma pack(push, 4)
class BSBatchRenderer__GeometryGroup
{
  public:
    unsigned char m_ucEntryType;  // +0x0, 1 bytes
    unsigned char layoutPadding1[1];
    unsigned short m_usPassCountLocal;             // +0x2, 2 bytes
    unsigned int auiGroupKey;           // +0x4, 4 bytes
    BSBatchRenderer* m_pGroupRenderer;  // +0x8, 4 bytes
    BSTPersistentList_NiTPointerAllocator_unsigned_int__BSShaderProperty__RenderPass___
        PassTextureSlotCollection;  // +0xC, 20 bytes
    float m_fProjectionDepth;       // +0x20, 4 bytes
    void ClearPassTextureSlots();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__GeometryGroup) == 36);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer__GeometryGroup, m_ucEntryType) == 0);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer__GeometryGroup, m_usPassCountLocal) == 2);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer__GeometryGroup, auiGroupKey) == 4);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer__GeometryGroup, m_pGroupRenderer) == 8);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer__GeometryGroup, PassTextureSlotCollection) == 12);
FNV_STATIC_ASSERT(offsetof(BSBatchRenderer__GeometryGroup, m_fProjectionDepth) == 32);
#endif
