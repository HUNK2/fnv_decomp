
class NiMaterialResource
{
public:
    long m_uiRefCount;
    virtual ~NiMaterialResource();
    virtual void DeleteThis();
};

extern "C" __declspec(dllimport) long __stdcall
InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall
InterlockedIncrement(volatile long* value);

template <class T>
class NiPointer
{
public:
    T* m_pObject;

    void operator=(const NiPointer& other)
    {
        T* pOld = m_pObject;
        if (pOld != other.m_pObject)
        {
            if (pOld && InterlockedDecrement(&pOld->m_uiRefCount) == 0)
                pOld->DeleteThis();
            m_pObject = other.m_pObject;
            if (m_pObject)
                InterlockedIncrement(&m_pObject->m_uiRefCount);
        }
    }
};

template <class T>
class NiTNewInterface
{
};

template <class T, class Allocator>
class NiTSet
{
public:
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;

    void Add(const T& value);
    void Realloc(unsigned int uiAlloced);
};

void* __cdecl FUN_00c1d790(unsigned int count);
void __cdecl ReleaseObjectArray(void* memory);

typedef NiTSet<NiPointer<NiMaterialResource>,
               NiTNewInterface<NiPointer<NiMaterialResource> > >
    NiMaterialResourceSet;

template <>
// @fnv 0x00e8ea60
void NiMaterialResourceSet::Add(
    const NiPointer<NiMaterialResource>& value)
{
    if (m_uiAllocatedCapacity == m_uiElementCount)
    {
        unsigned int uiNewAlloced;
        if (m_uiElementCount > 0)
            uiNewAlloced = m_uiElementCount + m_uiElementCount;
        else
            uiNewAlloced = 1;
        Realloc(uiNewAlloced);
    }
    m_pBase[m_uiAllocatedCapacity++] = value;
}

template <>
// @fnv 0x00e8e3a0
void NiMaterialResourceSet::Realloc(unsigned int uiAlloced)
{
    if (uiAlloced != m_uiElementCount)
    {
        NiPointer<NiMaterialResource>* pNew;
        if (uiAlloced > 0)
        {
            pNew = static_cast<NiPointer<NiMaterialResource>*>(
                FUN_00c1d790(uiAlloced));
            for (unsigned int i = 0; i < m_uiAllocatedCapacity; ++i)
                pNew[i] = m_pBase[i];
        }
        else
        {
            pNew = 0;
        }

        ReleaseObjectArray(m_pBase);
        m_pBase = pNew;
        m_uiElementCount = uiAlloced;
    }
}

class NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
public:
    unsigned int* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

extern unsigned char DAT_01096968;

void* __cdecl _NiMalloc(unsigned int size);
void __cdecl NiFree(void* memory);

class NiStreamLinkIDSet : public NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
public:
    void Realloc(unsigned int allocationCount);
};

