
// src/fallout_shared/bgsaddonnode_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsaddonnode.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgsaddonnode_types_BGSAddonNode.h"
#include "bgsaddonnode_decls.h"
#include <malloc.h>
#include <string.h>

// sub ecx,0x30; jmp FUN_004f8b90  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x30).
// Derived overrides a virtual that both of its bases declare, so the second base's vtable slot
// holds a thunk that moves `this` back by the size of the first base (0x30) and tail-jumps to
// the final overrider. Only the constructor is defined, so the vtables (and the thunk) get emitted.
struct PrimaryBase
{
    virtual void FUN_004f93a0();
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
    virtual void FUN_004f93a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004f93a0
    virtual void FUN_004f93a0();
};

Derived::Derived()
{}
