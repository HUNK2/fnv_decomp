// Source layout: MemoryManager. PC corrections are in generate_headers.py.
#ifndef FNV_MEMORYMANAGER_H
#define FNV_MEMORYMANAGER_H

#include "layout_support.h"
#include "MemoryPool.h"
#include "IMemoryHeap.h"
class ScrapHeapBuffer
{
  public:
    char data[16];
    ScrapHeapBuffer();
    static __forceinline void* operator new(size_t size);
    static __forceinline void operator delete(void* p);
};
template <class K, class V> class BSMapBase
{
  public:
    char data[16];
    bool GetAt(K, V&);
    void SetAt(K, V);
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
// Partial PC prefix through m_bPoolAllocationEnabled; sizeof is the prefix, not the runtime allocation.
#pragma pack(push, 4)
class MemoryManager
{
  public:
    unsigned char layoutPadding0[0x114];
    BSMapBase<unsigned long, ScrapHeapBuffer*> threadScrapHeaps;
    char pad124[5];
    bool m_bPoolAllocationEnabled;  // +0x129
    unsigned char layoutPadding12A[2];
    static MemoryManager& Instance();
    ScrapHeapBuffer* GetGeneralAllocator();
    void CreatePool(unsigned int blockSize, unsigned int poolSize, char* description);
    void* Allocate(unsigned int size);
    void Deallocate(void* pointer);
    void* Reallocate(void* pointer, unsigned int size);
    unsigned int Size(const void* pointer);
    IMemoryHeap* GetHeapForPointer(const void* pointer);
    IMemoryHeap* GetHeapForPhysicalPointer(const void* pointer);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MemoryManager) == 0x12C);
FNV_STATIC_ASSERT(offsetof(MemoryManager, m_bPoolAllocationEnabled) == 0x129);
#endif

extern MemoryManager g_memoryManager;
enum
{
    kMinimumPoolBlockSize = 8,
    kPoolAddressRegionShift = 24
};
FNV_FORCEINLINE MemoryManager& MemoryManager::Instance()
{
    return g_memoryManager;
}
FNV_FORCEINLINE void* operator new(size_t size)
{
    return g_memoryManager.Allocate(size);
}
FNV_FORCEINLINE void operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}

__forceinline void* ScrapHeapBuffer::operator new(size_t size)
{  // Preserve five unused allocator-local slots from the original PC build.
    struct Reserved
    {
        unsigned int slots[5];
    };
    Reserved reserved;
    return g_memoryManager.Allocate(size);
}
__forceinline void ScrapHeapBuffer::operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}
