
// src/fallout_shared/tesobjectcont_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectcont.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectcont_decls.h"
#include "tesobjectcont_types_TESObjectCONT.h"
#include "tesobjectcont_match_decls.h"
#include <new>
#include <string.h>

// FUN_005173d0 : 8-byte MSVC this-adjusting (adjustor) thunk.
//     sub ecx, 0x48 ; jmp <final overrider>
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot from two bases: the slot of the secondary base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, sizeof of
// the primary base) and tail-jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 17 int members (4 + 68 = 0x48 bytes).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct ContainerPrimaryBase
{
    virtual void FUN_005173d0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
};

struct ContainerSecondaryBase
{
    virtual void FUN_005173d0();
};

struct ContainerDerived : ContainerPrimaryBase, ContainerSecondaryBase
{
    ContainerDerived();
// @fnv 0x005173d0
    virtual void FUN_005173d0();
};

ContainerDerived::ContainerDerived()
{}
