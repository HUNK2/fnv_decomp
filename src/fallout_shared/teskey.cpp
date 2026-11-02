
// src/fallout_shared/teskey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/teskey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl _Deallocate(void*);

struct TESKey
{
    void* Destroy(unsigned int flags);
    void FUN_0050a6a0();
};

void TESKey::FUN_0050a6a0()
{}

// Calls FUN_0050a6a0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0050a670
void* TESKey::Destroy(unsigned int flags)
{
    FUN_0050a6a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESSub00
{
    virtual ~TESSub00();
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
};
struct TESSub01
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
};
struct TESSub02
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct TESSub03
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
};
struct TESSub04
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
};
struct TESSub05
{
    virtual void Vslot00()
    {}
    int unk04;
};
struct TESSub06
{
    virtual void Vslot00()
    {}
    int unk04;
};
struct TESSub07
{
    virtual void Vslot00()
    {}
    int unk04;
};
struct TESSub08
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
    int unk0C;
};
struct TESSub09
{
    virtual void Vslot00()
    {}
    int unk04;
};
struct FUN_0050a6a0 : TESSub00, TESSub01, TESSub02, TESSub03, TESSub04, TESSub05, TESSub06, TESSub07, TESSub08, TESSub09
{
    virtual ~FUN_0050a6a0();
    void Cleanup();
};

// @fnv 0x0050a6a0
FUN_0050a6a0::~FUN_0050a6a0()
{
    Cleanup();
}
