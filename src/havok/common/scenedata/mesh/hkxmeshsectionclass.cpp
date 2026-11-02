
// src/havok/common/scenedata/mesh/hkxmeshsectionclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxmeshsectionclass.cpp).
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

extern int DAT_0102e388;

struct FreeableItem
{
    void FUN_00c905b0();
};

struct FUN_00e01f70_cls
{
    int m_vptr;
    int unk04;
    FreeableItem* m_pObj08;
    FreeableItem** m_ppData0c;
    int m_iCount10;
    unsigned int m_uCapBits14;
    FreeableItem* m_pObj18;
    FreeableItem** m_ppData1c;
    int m_iCount20;
    unsigned int m_uCapBits24;

    void Destroy();
};

// @fnv 0x00e01f70
void FUN_00e01f70_cls::Destroy()
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    FreeableItem** ppItems = m_ppData1c;
    int iCount = m_iCount20;
    for (int i = 0; i < iCount; ++i)
    {
        if (ppItems[i] != 0)
        {
            ppItems[i]->FUN_00c905b0();
        }
        ppItems[i] = 0;
    }
    m_iCount20 = 0;
    unsigned int uCapBits = m_uCapBits24;
    if ((uCapBits & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_ppData1c, (uCapBits & 0x3fffffffu) * 4);
    }
    m_ppData1c = 0;
    *(volatile unsigned int*)&m_uCapBits24 = 0x80000000u;

    FreeableItem* pItem18 = *(FreeableItem* volatile*)&m_pObj18;
    if (pItem18 != 0)
    {
        pItem18->FUN_00c905b0();
    }
    m_pObj18 = 0;

    pHolder = FUN_00c85750();
    pAllocator = pHolder->m_pAllocator;
    ppItems = m_ppData0c;
    iCount = m_iCount10;
    for (int j = 0; j < iCount; ++j)
    {
        if (ppItems[j] != 0)
        {
            ppItems[j]->FUN_00c905b0();
        }
        ppItems[j] = 0;
    }
    m_iCount10 = 0;
    uCapBits = m_uCapBits14;
    if ((uCapBits & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_ppData0c, (uCapBits & 0x3fffffffu) * 4);
    }
    m_ppData0c = 0;
    *(volatile unsigned int*)&m_uCapBits14 = 0x80000000u;

    FreeableItem* pItem08 = *(FreeableItem* volatile*)&m_pObj08;
    if (pItem08 != 0)
    {
        pItem08->FUN_00c905b0();
    }
    m_pObj08 = 0;
    m_vptr = (int)&DAT_0102e388;
}

namespace fnv_00e02090 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct FUN_00e02090
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00e02090();
    virtual ~FUN_00e02090();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        unsigned int uiSize = ((FUN_00e02090*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Constructor that zeroes m_u04 and m_u06.
// @fnv 0x00e02090
FUN_00e02090::FUN_00e02090()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00e02090
