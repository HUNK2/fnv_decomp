
// src/fallout/ai/searchpackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/searchpackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SearchPackage
{
    void* DestroyIfFlagged(unsigned int flags);
    void* FUN_009f67b0();
};
extern void __cdecl _Deallocate(void*);

// Calls FUN_009f67b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009f6680
void* SearchPackage::DestroyIfFlagged(unsigned int flags)
{
    FUN_009f67b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESPackage
{
    int unk04;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    TESPackage();
    ~TESPackage()
    {}
    virtual void vfunc();
};
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
};
struct FUN_006e4080
{
    int unk00;
    int unk04;
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    FUN_006e4080();
    ~FUN_006e4080()
    {}
};
struct FUN_006dae60_shell
{
    int unk00;
    void* FUN_006dae60();
};
struct FUN_009f66b0 : TESPackage
{
    float unk80;
    int unk84;
    float unk88;
    int unk8c;
    float unk90;
    NiPoint3 unk94;
    int unka0;
    char unka4;
    char pad_a5;
    char pad_a6;
    char pad_a7;
    FUN_006e4080 unka8;
    FUN_006dae60_shell unk194;
    virtual void vfunc();
    FUN_009f66b0(float, float, float, int, int);
};
// Initializes a TESPackage-derived object: sets position from a, b, c, stores d, and zeroes the float fields.
// @fnv 0x009f66b0
FUN_009f66b0::FUN_009f66b0(float afX, float afY, float afZ, int aiValue, int aiUnused) : TESPackage(), unk94(), unka8()
{
    unk194.FUN_006dae60();
    unk80 = 0.0f;
    unk84 = 1;
    unk88 = 0.0f;
    unk90 = 0.0f;
    unk94.y = afY;
    unk94.x = afX;
    unk94.z = afZ;
    unka0 = aiValue;
    unka4 = 1;
    unk8c = 0;
}

struct DeadShell
{
    int unk00;
    ~DeadShell();
};

struct FUN_009f67b0_cls : TESPackage
{
    float unk80;
    int unk84;
    float unk88;
    int unk8c;
    float unk90;
    NiPoint3 unk94;
    int unka0;
    char unka4;
    char pad_a5;
    char pad_a6;
    char pad_a7;
    FUN_006e4080 unka8;
    DeadShell unk194;
    virtual ~FUN_009f67b0_cls();
};

// Destructor for the package class; the body is empty, leaving member destruction to the compiler-generated code.
// @fnv 0x009f67b0
FUN_009f67b0_cls::~FUN_009f67b0_cls()
{}
