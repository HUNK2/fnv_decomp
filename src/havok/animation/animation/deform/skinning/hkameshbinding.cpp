
// src/havok/animation/animation/deform/skinning/hkameshbinding.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/deform/skinning/hkameshbinding.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaMeshBinding.h"

struct hkaMemoryManager
{
    virtual void FUN_00000000()
    {}
    virtual void FUN_00000004()
    {}
    virtual void Free(void* ptr, unsigned short size)
    {}
};

struct hkaMemoryRouter
{
    void* m_p0000;
    void* m_p0004;
    void* m_p0008;
    void* m_p000C;
    hkaMemoryManager* m_pMemoryManager;
};

extern hkaMemoryRouter* _D1A0E0GetMemoryRouter();

struct hkaMeshBindingStandIn
{
    virtual void FUN_00000000()
    {}
    virtual void FUN_00000004()
    {}

    unsigned short m_nDataSize;

    void FUN_00e34820();
    void* FUN_00e34920(int flags);
};

// Calls FUN_00e34820, then if bit 0 of flags is set frees this through the memory router's manager using m_nDataSize, and returns this.
// @fnv 0x00e34920
void* hkaMeshBindingStandIn::FUN_00e34920(int flags)
{
    FUN_00e34820();

    if (flags & 1)
    {
        hkaMemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->m_pMemoryManager->Free(this, m_nDataSize);
    }

    return this;
}

class hkMemoryAllocatorE348
{
  public:
    virtual ~hkMemoryAllocatorE348() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE348
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE348* m_pStreamAllocator;

    hkMemoryAllocatorE348& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterE348& __cdecl FUN_00c85750() throw();

namespace hkE348 {
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
        hkMemoryAllocatorE348& kAlloc = FUN_00c85750().heap();
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
}

namespace FUN_00cb0c00 {
class hkStringPtr
{
  public:
    ~hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace hkE348 {
struct hkTransformE348
{
    float m_rotation[12];
    float m_vTranslation[4];
};
}

namespace FUN_00e34820 {
class hkaMeshBinding : public hkE348::hkReferencedObject
{
  public:
    virtual ~hkaMeshBinding();

    hkE348::ReferenceCountedPointer<hkE348::hkReferencedObject> m_pMesh;
    FUN_00cb0c00::hkStringPtr m_name;
    hkE348::ReferenceCountedPointer<hkE348::hkReferencedObject> m_pSkeleton;
    hkE348::hkArray<hkE348::hkArray<short> > m_kMappings;
    hkE348::hkArray<hkE348::hkTransformE348> m_kBoneFromSkinningTransforms;
};

// @fnv 0x00e34820
hkaMeshBinding::~hkaMeshBinding()
{}
}
