
// src/fallout_shared/tesobjectdoor_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectdoor.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectdoor_decls.h"

// Adjustor thunk: sub ecx,0x3c; jmp FUN_005174d0
// Both bases declare the same virtual; Derived overrides it, so the compiler
// emits a this-adjusting thunk in Derived's vtable for the secondary base.
struct PrimaryBase
{
    virtual void FUN_00519cb0();
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
};

struct SecondaryBase
{
    virtual void FUN_00519cb0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00519cb0
    virtual void FUN_00519cb0();
};

Derived::Derived()
{}
