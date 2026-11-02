
// src/havok/physics/vehicle/tyremarks/hkptyremarksinfoclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/tyremarks/hkptyremarksinfoclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiBytes) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct ArrayMember
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~ArrayMember() throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_pData, (uCapacity & 0x3fffffff) * 0x20);
        m_pData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct SizedBase
{
    virtual void b00();

    unsigned short m_uSize;
    unsigned short m_u06;
    int m_i08;
    int m_i0c;

    virtual ~SizedBase() throw()
    {}
};

struct FUN_00dfc2c0 : SizedBase
{
    ArrayMember m_kArray;

    FUN_00dfc2c0();

    // Empty virtual destructor; the m_kArray member's destructor then frees its array through the allocator.
// @fnv 0x00dfc2c0
    virtual ~FUN_00dfc2c0() throw()
    {}

    static void operator delete(void* apMemory) throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, ((FUN_00dfc2c0*)apMemory)->m_uSize);
    }
};

FUN_00dfc2c0::FUN_00dfc2c0()
{
    m_i08 = 0;
}

namespace fnv_00dfc330 {
struct DFC330Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct DFC330MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DFC330Allocator* m_pStreamAllocator;

    DFC330Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DFC330MemoryRouter& __cdecl FUN_00c85750();

struct FUN_00dfc330
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dfc330();
    virtual ~FUN_00dfc330();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dfc330* b = static_cast<FUN_00dfc330*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// Empty default constructor of a class with size/flags and reference count fields.
// @fnv 0x00dfc330
FUN_00dfc330::FUN_00dfc330()
{}
}  // namespace fnv_00dfc330
