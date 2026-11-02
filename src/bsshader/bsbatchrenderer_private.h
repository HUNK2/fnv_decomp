#ifndef BSBATCHRENDERER_PRIVATE_H
#define BSBATCHRENDERER_PRIVATE_H

#include "bsbatchrenderer_types_BSBatchRenderer.h"
class BSBatchRenderer__ActivePassList
{
  public:
    unsigned short item;
    BSBatchRenderer__ActivePassList* next;
    __forceinline BSBatchRenderer__ActivePassList* GetHead()
    {
        if (next || item)
            return this;
        return 0;
    }
    void FUN_00b99730();
};
__forceinline int BSBatchRenderer_Max(int a, int b)
{
    return a > b ? a : b;
}
#include "MemoryManager.h"
extern MemoryManager g_memoryManager;
class BSBatchRenderer__AlphaList
{
  public:
    BSBatchRenderer__GeometryGroup* Remove(BSBatchRenderer__GeometryGroup*&);
};
#pragma pack(push, 4)
struct BSBatchRenderer__PassGroup
{
    BSBatchRenderer__PassBucketEntry buckets[5];
    unsigned int padding;
};
struct BSBatchRenderer__RenderPassInfo
{
    unsigned char padding[7];
    bool bAlpha;
};
struct BSBatchRenderer__RenderPass
{
    unsigned char padding[8];
    BSBatchRenderer__RenderPassInfo* pInfo;
};
class BSBatchRenderer__PassList
{
  public:
    void* pHead;
    void* pTail;
    void* m_pCachedListItems;
    struct AllocatorData
    {
        unsigned int ItemUpdateArray;
    } Allocator;
    __declspec(nothrow) void ResetPassList();
    __declspec(nothrow) virtual ~BSBatchRenderer__PassList()
    {
        ResetPassList();
        m_pCachedListItems = pHead;
        pHead = 0;
        pTail = 0;
        Allocator.ItemUpdateArray = 0;
        ResetPassList();
    }
};
class BSBatchRenderer__GeometryGroup
{
  public:
    unsigned char m_ucEntryType;
    unsigned char padding1;
    unsigned short m_usPassCountLocal;
    unsigned int auiGroupKey;
    BSBatchRenderer* m_pGroupRenderer;
    BSBatchRenderer__PassList PassTextureSlotCollection;
    float m_fProjectionDepth;
    void ClearPassTextureSlots();
    ~BSBatchRenderer__GeometryGroup();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__PassGroup) == 104);
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__RenderPassInfo) == 8);
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__RenderPass) == 12);
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__PassList) == 20);
FNV_STATIC_ASSERT(sizeof(BSBatchRenderer__GeometryGroup) == 36);
#endif
