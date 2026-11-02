
// src/havok/physics/utilities/dynamics/savecontactpoints/hkpphysicssystemwithcontacts.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/savecontactpoints/hkpphysicssystemwithcontacts.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhysicsSystemWithContacts.h"

// Returns 0.
// @fnv 0x00dceb80
int FUN_00dceb80()
{
    return 0;
}

class hkMemoryAllocatorDCEC;

struct hkMemoryRouterDCEC
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCEC* m_pStreamAllocator;
    hkMemoryAllocatorDCEC& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCEC& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyDCEC(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayDCEC
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
        hkMemoryAllocatorDCEC& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyDCEC(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkReferencedObjectDCEC
{
  public:
    void FUN_00c90510() throw();
};

class hkpEntityGroupDCEC
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    hkArrayDCEC<hkReferencedObjectDCEC*> m_kTrackedObjects;

    void AddObject(hkReferencedObjectDCEC* pkObject);
};

// @fnv 0x00dcec70
void hkpEntityGroupDCEC::AddObject(hkReferencedObjectDCEC* pkObject)
{
    if (pkObject)
    {
        pkObject->FUN_00c90510();
        m_kTrackedObjects.AddBack(pkObject);
    }
}

namespace fnv_00dcecc0 {
struct RefAgent
{
    void __thiscall FUN_00c905b0();
};
struct Allocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void Deallocate(void* data, unsigned int size);
};
struct AllocatorManager
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    Allocator* allocator;
};
AllocatorManager* __cdecl FUN_00c85750();
struct FUN_00dcecc0
{
    virtual ~FUN_00dcecc0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkArray<void*> m_ppRigidBodies;
    hkArray<hkpConstraintInstance*> m_ppConstraints;
    hkArray<hkpAction*> m_ppActions;
    hkArray<hkpPhantom*> m_kPhantoms;
    char* m_name;
    unsigned int m_ulUserData;
    unsigned int m_activeFlags;
    hkArray<hkpSerializedAgentNnEntry*> m_kSerializedAgentEntries;
    void __thiscall Destroy();
};
// @fnv 0x00dcecc0
FUN_00dcecc0::~FUN_00dcecc0()
{
    int iAgentCount = m_kSerializedAgentEntries.m_iElementCount;
    for (int i = 0; i < iAgentCount; ++i)
    {
        reinterpret_cast<RefAgent*>(m_kSerializedAgentEntries.m_data[i])->FUN_00c905b0();
    }
    AllocatorManager* pAllocatorManager = FUN_00c85750();
    Allocator* allocator = pAllocatorManager->allocator;
    unsigned int uiArrayFlags = m_kSerializedAgentEntries.m_iCapacityState;
    m_kSerializedAgentEntries.m_iElementCount = 0;
    if (!(uiArrayFlags & 0x80000000u))
    {
        allocator->Deallocate(m_kSerializedAgentEntries.m_data, 4 * (uiArrayFlags & 0x3fffffffu));
    }
    m_kSerializedAgentEntries.m_data = 0;
    m_kSerializedAgentEntries.m_iCapacityState = 0x80000000;
    Destroy();
}
}  // namespace fnv_00dcecc0
