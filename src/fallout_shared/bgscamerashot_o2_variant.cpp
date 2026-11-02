
// src/fallout_shared/bgscamerashot_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgscamerashot.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bgscamerashot_decls.h"
#include "bgscamerashot_types_BGSCameraShot.h"
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<3>);
struct FUN_0058c2e0_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    void FUN_0058c2e0();
};
void _Deallocate(void*);
struct FUN_0058be60_host
{
    void FUN_0058be90();
    void* DestroyIfFlagged(unsigned int);
};
void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct FUN_0058bfc0_shell
{
    void CopyFromCameraShot(TESForm*);
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_0048cee0_shell
{
    char data[0x18];
    int FUN_0048cee0();
};
struct FUN_0058d630_shell
{
    char pad0[0x18];
    FUN_0048cee0_shell model;
    char pad1[8];
    int field_38;
    char pad2[0x30];
    Flt flt;
    bool FUN_0058d630();
};
