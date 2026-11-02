// bscore/memoryheap_decls.h: declares AbstractHeap, MemoryHeap
#ifndef MEMORYHEAP_DECLS_H
#define MEMORYHEAP_DECLS_H

class AbstractHeap
{
  public:
    unsigned int layoutPrefix[4];
    unsigned int m_uiHeapGrowthEnabled;
    void* BaseAllocate(unsigned int);
    void BaseFree(void*);
};
class MemoryHeap : public AbstractHeap
{
  public:
    unsigned int Size(const void*, unsigned int);
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*, unsigned int);
    unsigned int CommitRange(void*, unsigned int, unsigned int);
};
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned int, unsigned int);
#endif
