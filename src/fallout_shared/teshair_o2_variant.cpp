
// src/fallout_shared/teshair_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/teshair.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "teshair_types_TESHair.h"
#include "teshair_decls.h"
#include <malloc.h>

// sub ecx,0x24; jmp FUN_005fdb60  ==  MSVC adjustor thunk (multiple inheritance).
// The primary base occupies 0x24 bytes; both bases declare the same virtual, and the
// derived class defines only its constructor, so the compiler emits the this-adjusting
// thunk for the secondary base's vtable slot.
struct PrimaryBase
{
    virtual void FUN_005fe030();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SecondaryBase
{
    virtual void FUN_005fe030();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fe030
    virtual void FUN_005fe030();
};

Derived::Derived()
{}
