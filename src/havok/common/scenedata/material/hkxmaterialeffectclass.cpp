
// src/havok/common/scenedata/material/hkxmaterialeffectclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialeffectclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize) throw();
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

struct SpawnedMember
{
    int unk00;
    int unk04;

    ~SpawnedMember() throw();
};

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

struct FUN_00e022d0_cls : SpawnedBase
{
    unsigned short m_uSize;
    unsigned short m_u06;
    SpawnedMember m_kMemberDescriptor;
    void* m_pData;
    int m_i14;
    unsigned int m_uiObjectFlags;

    FUN_00e022d0_cls* FUN_00e022d0(unsigned char acFlags);
};

// Frees the data array via the audio allocator, resets the members, destroys the base and optionally frees the object itself.
// @fnv 0x00e022d0
FUN_00e022d0_cls* FUN_00e022d0_cls::FUN_00e022d0(unsigned char acFlags)
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uDataFlags = m_uiObjectFlags;
    m_i14 = 0;
    if ((uDataFlags & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, uDataFlags & 0x3fffffff);
    }
    m_pData = 0;
    m_uiObjectFlags = 0x80000000;
    m_kMemberDescriptor.~SpawnedMember();
    this->SpawnedBase::~SpawnedBase();
    if (acFlags & 1)
    {
        AudioHolder* pHolder2 = FUN_00c85750();
        AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
        pAllocator2->Free(this, m_uSize);
    }
    return this;
}
