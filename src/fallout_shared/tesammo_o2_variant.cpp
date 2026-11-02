
// src/fallout_shared/tesammo_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesammo.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesammo_load.h"
#include <malloc.h>
#include <string.h>

// The claimed function is a compiler-generated this-adjusting thunk:
//     sub ecx, 0x3c
//     jmp  <the most derived class' implementation of the virtual>
// MSVC emits it for the second copy of a duplicated common base: the most
// derived class inherits the same common base twice, so the vtable slot of
// the second copy has to move `this` back onto the first copy.
class ThunkCommonBase
{
  public:
    virtual void FUN_00503bb0();
};

class ThunkPrimaryBase : public ThunkCommonBase
{
  public:
    int m_pad01[14];
};

class ThunkSecondaryBase : public ThunkCommonBase
{
  public:
};

class ThunkDerived : public ThunkPrimaryBase, public ThunkSecondaryBase
{
  public:
// @fnv 0x00503bb0
    virtual void FUN_00503bb0();
    ThunkDerived();
};

ThunkDerived::ThunkDerived()
{}

ThunkDerived g_thunkDerived;
