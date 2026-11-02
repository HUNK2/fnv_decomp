// gamebryo2.2/corelibs/nimain/nitpool_decls.h: declares D3DRenderStateGroup, NiStreamLinkIDSet

#include "MemoryManager.h"
extern MemoryManager g_memoryManager;
struct D3DRenderStateGroup
{
    unsigned char data[20];
};
D3DRenderStateGroup* FUN_00e7f0a0(unsigned int);
class NiStreamLinkIDSet
{
  public:
    D3DRenderStateGroup** m_pBase;
    unsigned int m_uiElementCount, m_uiAllocatedCapacity;
    void Realloc(unsigned int);
    void Add(D3DRenderStateGroup* p)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            Realloc(m_uiElementCount > 0 ? m_uiElementCount * 2 : 1);
        m_pBase[m_uiAllocatedCapacity++] = p;
    }
};
template <class T, class A> class ObjectPoolBlock
{
  public:
    T* objects;
    unsigned int count;
    ObjectPoolBlock* next;
    static void* operator new(unsigned int n) throw()
    {
        return g_memoryManager.Allocate(n);
    }
    ObjectPoolBlock(unsigned int n) throw() : count(n), next(0)
    {
        if (n > 0)
            objects = FUN_00e7f0a0(n);
        else
            objects = 0;
    }
    T* GetAt(unsigned int i)
    {
        if (i >= count)
            return 0;
        return objects + i;
    }
};
template <class T, class A> class ObjectPool
{
  public:
    NiStreamLinkIDSet freeObjects;
    ObjectPoolBlock<T, A>* containers;
    unsigned int currentSize, initialSize;
    void AddPoolBlock(unsigned int n);
};
