
// src/havok/common/geometryutilities/mesh/memory/hkmemorymeshshapeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/geometryutilities/mesh/memory/hkmemorymeshshapeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_0126e330;

// @fnv 0x00e014c0
int* __cdecl FUN_00e014c0()
{
    return &DAT_0126e330;
}

struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int FUN_00e01500();
};
// Returns the value of unk2C with the lowest bit cleared.
// @fnv 0x00e01500
int State::FUN_00e01500()
{
    return unk2C & ~1;
}

struct E014D0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct E014D0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E014D0Allocator* m_pStreamAllocator;

    E014D0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" E014D0MemoryRouter& __cdecl FUN_00c85750();

struct FUN_00e014d0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00e014d0();
    virtual ~FUN_00e014d0();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00e014d0* b = static_cast<FUN_00e014d0*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00e014d0
FUN_00e014d0::FUN_00e014d0()
{}
