#ifndef FNV_ORIGINAL_MEMORY_H
#define FNV_ORIGINAL_MEMORY_H
#include "MemoryManager.h"
#include "MemoryPool.h"
#include "IMemoryHeap.h"
#ifndef _MSC_VER
extern "C" size_t FNV_CDECL _msize(void* pointer);
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

// Ordinary global allocation wrappers used by the original engine. These
// inline definitions are interop helpers, without accepted function entries.
FNV_FORCEINLINE void* operator new(size_t size)
{
    return MemoryManager::Instance().Allocate(size);
}

FNV_FORCEINLINE void operator delete(void* pointer)
{
    MemoryManager::Instance().Deallocate(pointer);
}
#endif
