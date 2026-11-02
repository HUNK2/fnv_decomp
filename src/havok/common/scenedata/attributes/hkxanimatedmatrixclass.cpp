
// src/havok/common/scenedata/attributes/hkxanimatedmatrixclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxanimatedmatrixclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int DAT_0102e388;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void v10(void* apMemory, unsigned int auiSize);
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

struct FUN_00e02650_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    int m_0c;
    unsigned int m_10;

    FUN_00e02650_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00e02650
FUN_00e02650_cls* FUN_00e02650_cls::Destroy(unsigned char acFlags)
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    m_0c = 0;
    unsigned int uFlags = m_10;
    if ((uFlags & 0x80000000u) == 0)
    {
        unsigned int uCount = uFlags & 0x3fffffffu;
        pAllocator->v10((void*)m_08, uCount * 64u);
    }
    bool bFree = (acFlags & 1) != 0;
    m_08 = 0;
    m_10 = 0x80000000u;
    m_vptr = (int)&DAT_0102e388;
    if (bFree)
    {
        AudioHolder* pHolder2 = FUN_00c85750();
        AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
        pAllocator2->Free(this, m_uSize);
    }
    return this;
}
