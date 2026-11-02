
// src/havok/common/scenedata/graph/hkxnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/graph/hkxnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxNode.h"

class hkMemoryAllocatorDFF6
{
  public:
    virtual ~hkMemoryAllocatorDFF6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDFF6
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDFF6* m_pStreamAllocator;

    hkMemoryAllocatorDFF6& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDFF6& __cdecl FUN_00c85750() throw();

namespace hkDFF6 {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};

template <class T> class ReferenceCountedPointer
{
  public:
    __forceinline ~ReferenceCountedPointer() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
    T* m_pRetainedObject;
};

template <class T> __forceinline void destruct(T* ptr, int size)
{
    for (int i = 0; i < size; i++)
        ptr[i].~T();
}

template <class T> class hkArray
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~hkArray() throw()
    {
        hkMemoryAllocatorDFF6& kAlloc = FUN_00c85750().heap();
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
}

class FUN_00dff6a0
{
  public:
    ~FUN_00dff6a0();

    hkDFF6::hkReferencedObject m_kBase;
    hkDFF6::hkArray<hkDFF6::ReferenceCountedPointer<hkDFF6::hkReferencedObject> > m_kChildList;
    hkDFF6::ReferenceCountedPointer<hkDFF6::hkReferencedObject> m_spOwner;
};

// Destructor for a DFF6 node that releases its child list and owner reference.
// @fnv 0x00dff6a0
FUN_00dff6a0::~FUN_00dff6a0()
{}
