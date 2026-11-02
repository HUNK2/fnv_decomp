// bscore/memorypool_decls.h: declares MemoryPool__FreePoolBlock, MemoryPool
#ifndef FNV_MEMORYPOOL_DECLS_H
#define FNV_MEMORYPOOL_DECLS_H


struct MemoryPool__FreePoolBlock
{
    MemoryPool__FreePoolBlock* m_pPreviousBlock;
    MemoryPool__FreePoolBlock* pNext;
};

class RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    unsigned char layoutPadding8[24];

    void Lock(const char* name);
};

class MemoryPool
{
  public:
    const char* pDescription;
    char* m_pPoolBase;
    MemoryPool__FreePoolBlock* m_pFreeBlockHead;
    unsigned char layoutPaddingC[20];
    RecursiveSpinLock m_kCriticalSection;
    unsigned int m_uiAllocationSize;
    unsigned int m_uiPeakPageCount;
    unsigned short* m_pPageBlockCounts;
    unsigned int m_uiPageCount;
    unsigned int m_uiPoolSize;
    unsigned int m_uiFreeBlockCount;
    unsigned int m_uiAllocatedPageCount;
    unsigned char layoutPadding5C[36];

    void PushFreeBlock(void* pointer);
    void Free(void* pointer);
};

#endif
