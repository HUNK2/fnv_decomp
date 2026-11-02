// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_ABSTRACTHEAP_H
#define FNV_ABSTRACTHEAP_H

#include "layout_support.h"
#include "RecursiveLock.h"
#include "IMemoryHeap.h"
class AbstractHeap;
class HeapFreeBlock;
class HeapFreeList;
class MemoryBlockHeader;
class HeapBlockList;
#pragma pack(push, 4)
class HeapFreeList
{
  public:
    HeapFreeBlock* pHead;  // +0x0, 4 bytes
    HeapFreeBlock* pTail;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(HeapFreeList) == 8);
FNV_STATIC_ASSERT(offsetof(HeapFreeList, pHead) == 0);
FNV_STATIC_ASSERT(offsetof(HeapFreeList, pTail) == 4);
#pragma pack(push, 4)
class HeapBlockList
{
  public:
    int iCount;            // +0x0, 4 bytes
    HeapFreeList* pFirst;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(HeapBlockList) == 8);
FNV_STATIC_ASSERT(offsetof(HeapBlockList, iCount) == 0);
FNV_STATIC_ASSERT(offsetof(HeapBlockList, pFirst) == 4);
#pragma pack(push, 4)
class AbstractHeap : public IMemoryHeap
{
  public:
    // base IMemoryHeap at +0x0, size 4
    const char* pName;                     // +0x4, 4 bytes
    int m_iBlockAlignment;                 // +0x8, 4 bytes
    unsigned int m_uiBlockHeaderSize;      // +0xC, 4 bytes
    unsigned int m_uiHeapGrowthEnabled;    // +0x10, 4 bytes
    unsigned int m_uiMaximumHeapSize;      // +0x14, 4 bytes
    unsigned int m_uiMinimumCommitSize;    // +0x18, 4 bytes
    unsigned int m_uiCurrentCommitSize;    // +0x1C, 4 bytes
    unsigned int m_uiInitialCommitSize;    // +0x20, 4 bytes
    int m_iUsedSize;                       // +0x24, 4 bytes
    int m_iAllocationCount;                // +0x28, 4 bytes
    int m_iAllocatedBlockSize;             // +0x2C, 4 bytes
    char* m_pHeapBase;                     // +0x30, 4 bytes
    int m_iFreeBlockCount;                 // +0x34, 4 bytes
    MemoryBlockHeader* m_pFirstBlock;              // +0x38, 4 bytes
    MemoryBlockHeader* m_pLastBlock;               // +0x3C, 4 bytes
    int m_uiFreeBlockCount;                // +0x40, 4 bytes
    HeapFreeList m_kFreeLists[1024];       // +0x44, 8192 bytes
    HeapFreeList* m_pCurrentFreeList;      // +0x2044, 4 bytes
    HeapFreeList m_kFreeListSentinel;      // +0x2048, 8 bytes
    MemoryBlockHeader** m_ppHeapBlocks;            // +0x2050, 4 bytes
    unsigned int m_uiBlockCount;           // +0x2054, 4 bytes
    HeapBlockList m_kSubBucketLists[16];   // +0x2058, 128 bytes
    RecursiveLock m_kCriticalSection;  // +0x20D8, 40 bytes
    bool ContainsBlockImpl(const void* pointer);
    // AbstractHeap
    // void __cdecl AbstractHeap::*()
    // const char* __cdecl AbstractHeap::*()
    // void* __cdecl AbstractHeap::*(unsigned int, unsigned int)
    // void __cdecl AbstractHeap::*(void*, unsigned int)
    // bool __cdecl AbstractHeap::*(const void*)
    // void __cdecl AbstractHeap::*()
    // int __cdecl AbstractHeap::*(IMemoryManagerFile*)
    // int __cdecl AbstractHeap::*(IMemoryManagerFile*, bool)
    // unsigned int __cdecl AbstractHeap::*(const void*, unsigned int)
    // unsigned int __cdecl AbstractHeap::*(const void*)
    // unsigned int __cdecl AbstractHeap::*(const void*)
    // void __cdecl AbstractHeap::*(void*, unsigned int)
    // void __cdecl AbstractHeap::*()
    // void __cdecl AbstractHeap::*()
    // void __cdecl AbstractHeap::*()
    // void* __cdecl AbstractHeap::*(unsigned int)
    // void __cdecl AbstractHeap::*(void*)
    // void __cdecl AbstractHeap::*(HeapFreeBlock*)
    // void __cdecl AbstractHeap::*(HeapFreeBlock*, HeapFreeBlock*)
    // void __cdecl AbstractHeap::*(HeapFreeBlock*)
    // void __cdecl AbstractHeap::*()
    // HeapFreeList* __cdecl AbstractHeap::*(unsigned int)
    // void __cdecl AbstractHeap::*(HeapFreeBlock*)
    // RemoveBlockFromFreeList
    // int __cdecl AbstractHeap::*(int)
    // bool __cdecl AbstractHeap::*(int, HeapFreeList*)
    // void __cdecl AbstractHeap::*(int)
    // void __cdecl AbstractHeap::*(int)
    // void __cdecl AbstractHeap::*()
    // void __cdecl AbstractHeap::*(unsigned int, HeapFreeList*)
    // AbstractHeap& __cdecl AbstractHeap::*(const AbstractHeap&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(AbstractHeap) == 8448);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, pName) == 4);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_iBlockAlignment) == 8);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiBlockHeaderSize) == 12);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiHeapGrowthEnabled) == 16);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiMaximumHeapSize) == 20);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiMinimumCommitSize) == 24);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiCurrentCommitSize) == 28);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiInitialCommitSize) == 32);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_iUsedSize) == 36);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_iAllocationCount) == 40);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_iAllocatedBlockSize) == 44);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_pHeapBase) == 48);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_iFreeBlockCount) == 52);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_pFirstBlock) == 56);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_pLastBlock) == 60);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiFreeBlockCount) == 64);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kFreeLists) == 68);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_pCurrentFreeList) == 8260);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kFreeListSentinel) == 8264);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_ppHeapBlocks) == 8272);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_uiBlockCount) == 8276);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kSubBucketLists) == 8280);
FNV_STATIC_ASSERT(offsetof(AbstractHeap, m_kCriticalSection) == 8408);
#endif

// @fnv 0x00aa7e70
bool AbstractHeap::ContainsBlockImpl(const void* pointer)
{
    return pointer >= m_pHeapBase && pointer < m_pHeapBase + m_uiMaximumHeapSize;
}
