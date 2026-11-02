// src/havok/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshapeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshapeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
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

struct FUN_00dfd380_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pDataD;
    int m_iCountD;
    unsigned int m_uCapD;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FUN_00dfd380();
};

// Frees the four data arrays through the audio allocator when their capacity flag is clear, then resets each pointer, count and capacity.
// @fnv 0x00dfd380
void FUN_00dfd380_cls::FUN_00dfd380()
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    AudioHolder* pHolder2 = FUN_00c85750();
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        pAllocator2->FreeArray(m_pDataB, (uCapB & 0x3fffffffu) * 2);
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    AudioHolder* pHolder3 = FUN_00c85750();
    AudioAllocator* pAllocator3 = pHolder3->m_pAllocator;
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        pAllocator3->FreeArray(m_pDataC, (uCapC & 0x3fffffffu) * 2);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;

    AudioHolder* pHolder4 = FUN_00c85750();
    AudioAllocator* pAllocator4 = pHolder4->m_pAllocator;
    unsigned int uCapD = m_uCapD;
    m_iCountD = 0;
    if ((uCapD & 0x80000000u) == 0)
    {
        pAllocator4->FreeArray(m_pDataD, (uCapD & 0x3fffffffu) * 2);
    }
    m_pDataD = 0;
    m_uCapD = 0x80000000u;
}

namespace fnv_00dfd440 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
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

struct FUN_00dfd440_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FUN_00dfd440();
};

// Frees the three capacity-flagged data arrays through the audio allocator and resets each pointer, count and capacity to empty.
// @fnv 0x00dfd440
void FUN_00dfd440_cls::FUN_00dfd440()
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    AudioHolder* pHolder2 = FUN_00c85750();
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        pAllocator2->FreeArray(m_pDataB, (uCapB & 0x3fffffffu));
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    AudioHolder* pHolder3 = FUN_00c85750();
    AudioAllocator* pAllocator3 = pHolder3->m_pAllocator;
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        pAllocator3->FreeArray(m_pDataC, (uCapC & 0x3fffffffu) * 2);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;
}
}  // namespace fnv_00dfd440
