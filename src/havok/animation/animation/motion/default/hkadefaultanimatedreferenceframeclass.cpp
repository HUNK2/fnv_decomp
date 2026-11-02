
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
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

struct FUN_00dfe520_cls
{
    int m_vptr00;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    FUN_00dfe520_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00dfe520
FUN_00dfe520_cls* FUN_00dfe520_cls::Destroy(unsigned char acFlags)
{
    AudioHolder* pAudioHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pAudioHolder->m_pAllocator;
    unsigned int uCapacityFlags = m_uCapBits;
    m_iArrayLength = 0;
    if ((uCapacityFlags & 0x80000000u) == 0)
    {
        pAllocator->FreeArray(m_pData, (uCapacityFlags & 0x3fffffff) * 16);
    }
    m_pData = 0;
    m_uCapBits = 0x80000000u;
    m_vptr00 = (int)&DAT_0102e388;
    if (acFlags & 1)
    {
        AudioHolder* pHolder2 = FUN_00c85750();
        AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
        pAllocator2->Free(this, m_uSize);
    }
    return this;
}
