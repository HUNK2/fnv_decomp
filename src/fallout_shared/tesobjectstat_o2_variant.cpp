
// src/fallout_shared/tesobjectstat_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectstat.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectstat_load.h"
#include "tesobjectstat_global.h"
#include "tesobjectstat_types_TESObjectSTAT.h"

struct Primary231
{
    virtual void* DestroyIfFlagged(unsigned int);
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
};
struct Secondary231
{
    virtual void* DestroyIfFlagged(unsigned int) = 0;
};
struct FUN_0051b6d0 : Primary231, Secondary231
{
// @fnv 0x0051b6d0
    FUN_0051b6d0();
    void* DestroyIfFlagged(unsigned int);
};
struct Complete231 : FUN_0051b6d0
{
};
void* operator new(unsigned int, void* storage)
{
    return storage;
}
void* Make231(void* storage)
{
    return new (storage) Complete231;
}
