
// src/fallout_shared/bgstalkingactivator_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgstalkingactivator.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgstalkingactivator.h"
#include <malloc.h>
static const char s_kTalkingVoiceTypeWarning[] =
    "MASTERFILE: Could not find voice type (%08X) for activator '%s' (%08X).";
#include "bgstalkingactivator_radio.h"
#include "bgstalkingactivator_load.h"

// Adjustor thunk for FUN_004ffa90: "sub ecx, 0x3c; jmp FUN_004fe6e0".
//
// MSVC "this adjusting thunk" emitted for a virtual function inherited from a
// secondary base: the thunk converts the secondary base sub-object pointer
// (this + 0x3c) back into the derived object pointer (sub ecx, 0x3c) and then
// tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 14 int members (4 + 14 * 4 = 0x3c).
// Both bases declare the same virtual, the derived class redeclares it and
// defines only its constructor, which is what makes the compiler emit the
// vtables and the adjusting thunk.
struct AdjustorPrimary
{
    virtual void FUN_004ffa90();
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
    int unk30;
    int unk34;
    int unk38;
};

struct AdjustorSecondary
{
    virtual void FUN_004ffa90();
};

struct AdjustorDerived : AdjustorPrimary, AdjustorSecondary
{
    AdjustorDerived();
// @fnv 0x004ffa90
    virtual void FUN_004ffa90();
};

AdjustorDerived::AdjustorDerived()
{}
