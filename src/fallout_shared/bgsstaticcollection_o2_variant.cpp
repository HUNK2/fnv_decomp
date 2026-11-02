
// src/fallout_shared/bgsstaticcollection_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsstaticcollection.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsstaticcollection_decls.h"
#include <malloc.h>

// sub ecx,0x30; jmp target  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x30)
struct PrimaryBase
{
    virtual void FUN_004fe630();
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

struct SecondaryBase
{
    virtual void FUN_004fe630();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fe630
    virtual void FUN_004fe630();
};

Derived::Derived()
{}
