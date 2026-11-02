// Source layout: MemoryPool. PC corrections are in generate_headers.py.
#ifndef FNV_MEMORYPOOL_H
#define FNV_MEMORYPOOL_H

#include "layout_support.h"
#include "RecursiveSpinLock.h"
#pragma pack(push, 4)
class MemoryPool
{
  public:
    const char* pDescription;                     // +0x0
    char* m_pPoolBase;                            // +0x4
    MemoryPool__FreePoolBlock* m_pFreeBlockHead;  // +0x8
    unsigned int layoutPaddingC[5];
    RecursiveSpinLock m_kCriticalSection;        // +0x20
    unsigned int m_uiAllocationSize;      // +0x40
    unsigned int m_uiPeakPageCount;       // +0x44
    unsigned short* m_pPageBlockCounts;   // +0x48
    unsigned int m_uiPageCount;           // +0x4C
    unsigned int m_uiPoolSize;            // +0x50
    unsigned int m_uiFreeBlockCount;      // +0x54
    unsigned int m_uiAllocatedPageCount;  // +0x58
    unsigned int layoutPadding5C[9];
    MemoryPool(unsigned int blockSize, unsigned int poolSize, const char* description);
    ~MemoryPool();
    FNV_FORCEINLINE bool IsHeapValid()
    {
        return m_pPoolBase != 0;
    }
    enum
    {
        kAddressRegionCount = 256
    };
    static MemoryPool* ms_pPoolAddressMap[kAddressRegionCount];
    FNV_FORCEINLINE bool PointerInPool(const void* pointer)
    {
        return static_cast<const char*>(pointer) >= m_pPoolBase &&
               static_cast<const char*>(pointer) < m_pPoolBase + m_uiPoolSize;
    }
    FNV_FORCEINLINE unsigned int GetBlockSize()
    {
        return m_uiAllocationSize;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MemoryPool) == 0x80);
FNV_STATIC_ASSERT(offsetof(MemoryPool, pDescription) == 0x0);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_pPoolBase) == 0x4);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_pFreeBlockHead) == 0x8);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_kCriticalSection) == 0x20);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_uiAllocationSize) == 0x40);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_uiPeakPageCount) == 0x44);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_pPageBlockCounts) == 0x48);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_uiPageCount) == 0x4C);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_uiPoolSize) == 0x50);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_uiFreeBlockCount) == 0x54);
FNV_STATIC_ASSERT(offsetof(MemoryPool, m_uiAllocatedPageCount) == 0x58);
#endif
