// src/havok/physics/utilities/serialize/hkpphysicsdataclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkpphysicsdataclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
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

struct FUN_00d48370_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FinishObject();

    FUN_00d48370_cls* FUN_00d48370(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FinishObject, then if acFlags bit 0 is set frees this object through the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00d48370
FUN_00d48370_cls* FUN_00d48370_cls::FUN_00d48370(unsigned char acFlags)
{
    FinishObject();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
