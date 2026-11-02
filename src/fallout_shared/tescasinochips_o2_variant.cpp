
// src/fallout_shared/tescasinochips_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tescasinochips.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tescasinochips_packet.h"
#include <malloc.h>

struct S_00504ff0_Base1
{
    virtual void FUN_00504ff0();
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
struct S_00504ff0_Base2
{
    virtual void FUN_00504ff0();
};
struct S_00504ff0_Derived : S_00504ff0_Base1, S_00504ff0_Base2
{
    S_00504ff0_Derived();
// @fnv 0x00504ff0
    virtual void FUN_00504ff0();
};
S_00504ff0_Derived::S_00504ff0_Derived()
{}
