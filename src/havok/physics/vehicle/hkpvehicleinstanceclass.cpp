// src/havok/physics/vehicle/hkpvehicleinstanceclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstanceclass.cpp).
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

struct FUN_00dfbe50_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00e38bf0();

    FUN_00dfbe50_cls* FUN_00dfbe50(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00e38bf0, then if bit 0 of acFlags is set frees this via the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00dfbe50
FUN_00dfbe50_cls* FUN_00dfbe50_cls::FUN_00dfbe50(unsigned char acFlags)
{
    FUN_00e38bf0();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
