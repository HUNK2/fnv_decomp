
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstraintChainInstance.h"

struct FUN_00c91120
{
    void ExecutePendingOperations();
};
struct FUN_00c91140
{
    void ExecutePendingOperationQueues();
};
struct FUN_00c97510
{
    void ProcessPointer(void*);
};
struct FUN_00cb3da0
{
    static void AddConstraintToCriticalLockedIsland(void*, void*);
};
struct FUN_00dd0460
{
    void EntityRemovedCallback(void*);
};
// @fnv 0x00dd0460
void FUN_00dd0460::EntityRemovedCallback(void* a)
{
    FUN_00c97510* w = *(FUN_00c97510**)((char*)a + 8);
    ++*(int*)((char*)w + 0x94);
    FUN_00c97510* w2 = *(FUN_00c97510**)((char*)this + 0x44);
    w->ProcessPointer(w2);
    FUN_00cb3da0::AddConstraintToCriticalLockedIsland(w, this);
    if (--*(int*)((char*)w + 0x94) == 0 && !*(char*)((char*)w + 0x9c))
    {
        if (*(int*)((char*)w + 0x8c))
            ((FUN_00c91120*)w)->ExecutePendingOperations();
        if (*(int*)((char*)w + 0xa4) == 1 && *(int*)((char*)w + 0x90))
            ((FUN_00c91140*)w)->ExecutePendingOperationQueues();
    }
}

class hkMemoryAllocatorDD04;

struct hkMemoryRouterDD04
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDD04* m_pStreamAllocator;
    hkMemoryAllocatorDD04& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDD04& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyDD04(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayDD04
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorDD04& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyDD04(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkReferencedObjectDD04
{
  public:
    void FUN_00c90510() throw();
};

class hkpPhantomOverlapDD04
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkReferencedObjectDD04* m_pHeadNode[2];
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkArrayDD04<hkReferencedObjectDD04*> m_kTrackedObjects;

    void AddReferencedObject(hkReferencedObjectDD04* pkObject);
};

// @fnv 0x00dd04d0
void hkpPhantomOverlapDD04::AddReferencedObject(hkReferencedObjectDD04* pkObject)
{
    int iSlot = m_kTrackedObjects.m_iElementCount;
    if (iSlot < 2 && m_pHeadNode[iSlot] == 0)
    {
        m_pHeadNode[iSlot] = pkObject;
        pkObject->FUN_00c90510();
    }
    m_kTrackedObjects.AddBack(pkObject);
    pkObject->FUN_00c90510();
}

class hkMemoryAllocatorDD05
{
  public:
    virtual ~hkMemoryAllocatorDD05() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDD05
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDD05* m_pStreamAllocator;
    hkMemoryAllocatorDD05& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDD05 {
extern "C" hkMemoryRouterDD05& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDD05
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayDD05() throw()
    {
        hkMemoryAllocatorDD05& kAlloc = hkRouterDD05::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00d1df70 : public hkReferencedObject
{
  public:
    void removeReference();
};

class FUN_00cf40b0
{
  public:
    virtual ~FUN_00cf40b0() throw();
    int unk04[13];
};

class FUN_00dd05c0 : public FUN_00cf40b0
{
  public:
    hkArrayDD05<FUN_00d1df70*> m_children;
    FUN_00d1df70* m_pOwnerObject;

    virtual ~FUN_00dd05c0() throw();
};

// @fnv 0x00dd05c0
FUN_00dd05c0::~FUN_00dd05c0() throw()
{
    for (int i = 0; i < m_children.m_iElementCount; i++)
        m_children.m_data[i]->removeReference();
    m_pOwnerObject->removeReference();
}

namespace fnv_00dd0630 {
struct FnvCpu_FUN_00dd0630_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00dd0630_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00dd0630_CpuAllocator* allocator;
};
FnvCpu_FUN_00dd0630_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00dd0630_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00dd05c0();
    FnvCpu_FUN_00dd0630_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00dd05c0, and if flags has bit 0 set, frees this via the allocator from FUN_00c85750, then returns this.
// @fnv 0x00dd0630
FnvCpu_FUN_00dd0630_CpuObject* FnvCpu_FUN_00dd0630_CpuObject::Destroy(unsigned int flags)
{
    FUN_00dd05c0();
    if (flags & 1)
    {
        FnvCpu_FUN_00dd0630_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00dd0630

namespace fnv_00dd0530 {
class hkMemoryAllocatorDD05
{
  public:
    virtual ~hkMemoryAllocatorDD05() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDD05
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDD05* m_pStreamAllocator;

    hkMemoryAllocatorDD05& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDD05& __cdecl FUN_00c85750() throw();

namespace hkDD05 {
class hkRefObj
{
  public:
    hkRefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual void unkVirtual00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkRefObj* b = static_cast<hkRefObj*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
};

class hkpConstraintChainData : public hkRefObj
{
  public:
    void FUN_00c90510() throw();
};
}

namespace FUN_00cb0a60 {
class hkStringPtr
{
  public:
    hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace FUN_00cf3f40 {
class hkpConstraintInstance : public hkDD05::hkRefObj
{
  public:
    hkpConstraintInstance(int iPriority) throw();
    int unk08;
    hkDD05::hkpConstraintChainData* m_data;
    int unk10;
    void* m_kActorEntries[2];
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
};
}

class hkpAction : public hkDD05::hkRefObj
{
  public:
    hkpAction() throw() : m_pOwningWorld(0), m_pCurrentSimulationIsland(0), m_ulUserData(0)
    {}
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned long m_ulUserData;
    FUN_00cb0a60::hkStringPtr m_name;
};

class hkpConstraintChainInstanceAction : public hkpAction
{
  public:
    hkpConstraintChainInstanceAction(FUN_00cf3f40::hkpConstraintInstance* pkInstance) throw()
        : m_pConstraintChainInstance(pkInstance)
    {}
    virtual void unkVirtual00();
    FUN_00cf3f40::hkpConstraintInstance* m_pConstraintChainInstance;
};

template <class T> class hkArrayDD05
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDD05() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

namespace FUN_00dd0530 {
class hkpConstraintChainInstance : public FUN_00cf3f40::hkpConstraintInstance
{
  public:
    hkpConstraintChainInstance(hkDD05::hkpConstraintChainData* pkData);
    virtual void unkVirtual00();

    hkArrayDD05<void*> m_ppRigidBodies;
    hkpConstraintChainInstanceAction* m_pAction;
};

// Constructs a constraint chain instance from pkData, nulls actor entries, and creates its owning hkpConstraintChainInstanceAction.
// @fnv 0x00dd0530
hkpConstraintChainInstance::hkpConstraintChainInstance(hkDD05::hkpConstraintChainData* pkData)
    : FUN_00cf3f40::hkpConstraintInstance(1)
{
    m_data = pkData;
    pkData->FUN_00c90510();
    m_kActorEntries[0] = 0;
    m_kActorEntries[1] = 0;
    m_pAction = new hkpConstraintChainInstanceAction(this);
}
}
}  // namespace fnv_00dd0530
