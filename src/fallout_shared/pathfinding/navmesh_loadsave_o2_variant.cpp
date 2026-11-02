
// src/fallout_shared/pathfinding/navmesh_loadsave_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/pathfinding/navmesh_loadsave.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "navmesh_loadsave_decls.h"

// FUN_00692940 : MSVC this-adjusting thunk  (sub ecx, 0x1c ; jmp <impl>)
struct A1_00692940
{
    A1_00692940();
    virtual void FUN_00692940();
    char pad[0x18];
};
struct A2_00692940
{
    A2_00692940();
    virtual void FUN_00692940();
};
struct Own_00692940 : A1_00692940, A2_00692940
{
    Own_00692940();
    virtual void key_fn();
// @fnv 0x00692940
    void FUN_00692940();
};
Own_00692940::Own_00692940()
{}
void Own_00692940::key_fn()
{}
Own_00692940* make_00692940()
{
    static Own_00692940 o;
    return &o;
}
