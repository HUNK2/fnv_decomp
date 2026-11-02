// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TASK_TYPES_BSTPERSISTENTLIST_H
#define FNV_TASK_TYPES_BSTPERSISTENTLIST_H

#include "layout_support.h"
#include "layout_support.h"
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
    void ResetPassList();
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
#endif
