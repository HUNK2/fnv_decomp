// Source layout: IMemoryHeap. PC corrections are in generate_headers.py.
#ifndef FNV_IMEMORYHEAP_H
#define FNV_IMEMORYHEAP_H

#include "layout_support.h"
#pragma pack(push, 4)
class IMemoryHeap
{
  public:
    virtual ~IMemoryHeap();
    virtual const char* GetName() = 0;
    virtual void* Allocate(unsigned int size, unsigned int alignment) = 0;
    virtual void Deallocate(void* pointer, unsigned int alignment) = 0;
    virtual bool ContainsBlockImpl(const void* pointer) = 0;
    virtual void CheckHeapIntegrity() = 0;
    virtual void GetHeapStats(MemoryHeapStats* stats, bool full) = 0;
    virtual int OutputBucketInfo(IMemoryManagerFile* file) = 0;
    virtual int OutputBlockInfo(IMemoryManagerFile* file, bool full) = 0;
    virtual unsigned int Size(const void* pointer, unsigned int alignment) = 0;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(IMemoryHeap) == 0x4);
#endif
