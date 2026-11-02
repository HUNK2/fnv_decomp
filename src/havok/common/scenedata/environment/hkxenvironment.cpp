
// src/havok/common/scenedata/environment/hkxenvironment.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/environment/hkxenvironment.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxEnvironment.h"

struct HKXMemoryManager
{
    virtual void Unused1()
    {}
    virtual void Unused2()
    {}
    virtual void Free(void* p, unsigned short size) = 0;
};

struct HKXMemoryRouter
{
    char padding[0x10];
    HKXMemoryManager* manager;
};

struct HKXEnvironmentStandIn
{
    char padding[4];
    unsigned short size;
    void DestroyEnvironment();
    HKXEnvironmentStandIn* FUN_00e3f8a0(unsigned char flags);
};

HKXMemoryRouter* _D1A0E0GetMemoryRouter();

// Calls DestroyEnvironment, then if bit 0 of flags is set frees this through the memory router's manager, and returns this.
// @fnv 0x00e3f8a0
HKXEnvironmentStandIn* HKXEnvironmentStandIn::FUN_00e3f8a0(unsigned char flags)
{
    DestroyEnvironment();

    if (flags & 1)
    {
        HKXMemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->manager->Free(this, size);
    }

    return this;
}

extern int DAT_010ebab8;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00e3f510(unsigned int unusedArg);
};

// @fnv 0x00e3f510
FnvVtObj* FnvVtObj::FUN_00e3f510(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010ebab8;
    return this;
}

struct HavokString
{
    char* text;
};
struct EnvironmentVariable
{
    HavokString name;
    HavokString value;
};
struct HavokAllocator
{
    virtual ~HavokAllocator();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
};
HKXMemoryRouter* __cdecl FUN_00c85750();
void __fastcall FUN_00cb0c00(HavokString* string);
struct EnvironmentArray
{
    EnvironmentVariable* data;
    int size;
    int capacityAndFlags;

    __forceinline void release()
    {
        HavokAllocator* allocator = reinterpret_cast<HavokAllocator*>(FUN_00c85750()->manager);
        EnvironmentVariable* entry = data;
        if (size > 0)
        {
            int remaining = size;
            do
            {
                FUN_00cb0c00(&entry->value);
                FUN_00cb0c00(&entry->name);
                ++entry;
            } while (--remaining != 0);
        }
        size = 0;
        if ((static_cast<unsigned int>(capacityAndFlags) & 0x80000000u) == 0)
            allocator->ReturnMemory(data, (capacityAndFlags & 0x3fffffff) * sizeof(EnvironmentVariable));
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};
struct EnvironmentLayout
{
    void** vtable;
    unsigned short memoryFlags;
    short referenceCount;
    EnvironmentArray variables;
};
hkBaseObject::~hkBaseObject()
{}
// Releases the environment's variable array, then calls the hkBaseObject destructor.
// @fnv 0x00e3f820
void HKXEnvironmentStandIn::DestroyEnvironment()
{
    EnvironmentLayout* environment = reinterpret_cast<EnvironmentLayout*>(this);
    environment->variables.release();
    reinterpret_cast<hkBaseObject*>(environment)->hkBaseObject::~hkBaseObject();
}

void ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem);

struct PlaceTagE3F3
{
};
inline void* operator new(unsigned int, void* p, PlaceTagE3F3) throw()
{
    return p;
}
inline void operator delete(void*, void*, PlaceTagE3F3) throw()
{}

class hkStringPtrE3F3
{
  public:
    const char* m_pcText;

    void FUN_00cb0a60() throw();
    void FUN_00cb0bd0(const hkStringPtrE3F3& kOther) throw();
    void FUN_00cb0c00() throw();
    void FUN_00cb0c10(const char* pcString) throw();

    hkStringPtrE3F3()
    {
        FUN_00cb0a60();
    }
    hkStringPtrE3F3(const hkStringPtrE3F3& kOther)
    {
        FUN_00cb0bd0(kOther);
    }
    ~hkStringPtrE3F3()
    {
        FUN_00cb0c00();
    }
    void operator=(const char* pcString)
    {
        FUN_00cb0c10(pcString);
    }
};

struct hkxAttributePairE3F3
{
    hkStringPtrE3F3 m_name;
    hkStringPtrE3F3 m_uiFilterValue;
};

template <int ELEMENTSIZE> __forceinline void memCpyOneAlignedE3F3(void* pvDst, const void* pvSrc)
{
    for (int i = 0; i < ELEMENTSIZE / 4; ++i)
        static_cast<unsigned int*>(pvDst)[i] = static_cast<const unsigned int*>(pvSrc)[i];
}

template <typename T> __forceinline void destructE3F3(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <typename T> struct hkArrayE3F3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void removeAt(int iIndex)
    {
        destructE3F3<T>(&m_data[iIndex], 1);
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            memCpyOneAlignedE3F3<sizeof(T)>(m_data + iIndex, m_data + m_iElementCount);
    }
    __forceinline void AddBack(const T& kElem)
    {
        HKXMemoryRouter* pRouter = FUN_00c85750();
        HavokAllocator* pAlloc = reinterpret_cast<HavokAllocator*>(pRouter->manager);
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(pAlloc, this, sizeof(T));
        new (&m_data[m_iElementCount], PlaceTagE3F3()) T(kElem);
        m_iElementCount++;
    }
};

class hkxAttributeMapE3F3
{
  public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkArrayE3F3<hkxAttributePairE3F3> m_pCustomAttributes;

    int FindEntryByKey(const char* pcName) throw();
    int FUN_00e3f3b0(const char* pcName, const char* pcValue) throw();
};

// Sets or removes a custom attribute by name, returning 1 if a missing attribute was requested for removal, otherwise 0.
// @fnv 0x00e3f3b0
int hkxAttributeMapE3F3::FUN_00e3f3b0(const char* pcName, const char* pcValue) throw()
{
    int iIndex = FindEntryByKey(pcName);
    if (pcValue == 0)
    {
        if (iIndex == -1)
            return 1;
        m_pCustomAttributes.removeAt(iIndex);
        return 0;
    }
    if (iIndex != -1)
    {
        m_pCustomAttributes[iIndex].m_uiFilterValue = pcValue;
        return 0;
    }
    hkxAttributePairE3F3 kPair;
    kPair.m_name = pcName;
    kPair.m_uiFilterValue = pcValue;
    m_pCustomAttributes.AddBack(kPair);
    return 0;
}
