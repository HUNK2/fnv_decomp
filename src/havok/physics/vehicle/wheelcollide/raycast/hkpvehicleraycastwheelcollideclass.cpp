// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollideclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollideclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

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

struct FUN_00dfeb10
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00dfeb10();
    virtual ~FUN_00dfeb10();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        unsigned int uiSize = ((FUN_00dfeb10*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Initialises m_u04 and m_u06 to zero for a FUN_00dfeb10 instance.
// @fnv 0x00dfeb10
FUN_00dfeb10::FUN_00dfeb10()
{
    m_u04 = 0;
    m_u06 = 0;
}
