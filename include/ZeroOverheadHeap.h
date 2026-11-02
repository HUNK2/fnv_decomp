// Source layout: ZeroOverheadHeap. PC corrections are in generate_headers.py.
#ifndef FNV_ZEROOVERHEADHEAP_H
#define FNV_ZEROOVERHEADHEAP_H

#include "layout_support.h"
#include "RecursiveSpinLock.h"
#include "IMemoryHeap.h"
#pragma pack(push, 4)
class ZeroOverheadHeap : public IMemoryHeap
{
  public:
    unsigned int iSize;      // +0x4
    const char* pName;       // +0x8
    void* m_pPoolBase;       // +0xC
    void* m_pCurrent;        // +0x10
    int m_iAllocationCount;  // +0x14
    unsigned int layoutPadding18[2];
    RecursiveSpinLock lock;  // +0x20
    virtual void* Allocate(unsigned int size, unsigned int alignment);
    virtual void Deallocate(void* pointer, unsigned int alignment);
    virtual bool ContainsBlockImpl(const void* pointer);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ZeroOverheadHeap) == 0x40);
FNV_STATIC_ASSERT(offsetof(ZeroOverheadHeap, iSize) == 0x4);
FNV_STATIC_ASSERT(offsetof(ZeroOverheadHeap, pName) == 0x8);
FNV_STATIC_ASSERT(offsetof(ZeroOverheadHeap, m_pPoolBase) == 0xC);
FNV_STATIC_ASSERT(offsetof(ZeroOverheadHeap, m_pCurrent) == 0x10);
FNV_STATIC_ASSERT(offsetof(ZeroOverheadHeap, m_iAllocationCount) == 0x14);
FNV_STATIC_ASSERT(offsetof(ZeroOverheadHeap, lock) == 0x20);
#endif
