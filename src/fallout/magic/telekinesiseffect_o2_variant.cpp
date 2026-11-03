
// src/fallout/magic/telekinesiseffect_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/telekinesiseffect.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_0082a510_shell
{
    void FUN_0082a540();
    void* DestroyIfFlagged(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct FUN_0082aab0_shell
{
    void SetField644(float value);
};
struct FUN_0082af40_shell
{
    float fTelekinesisStrength;  // +0x644
    float GetTelekinesisStrength();
};
struct Actor
{
};
struct ValueModifierEffect
{
    unsigned short __thiscall ValueModifierEffect_GetSaveSize(Actor* apActor);
};
struct TelekinesisEffect : ValueModifierEffect
{
    unsigned short __thiscall TelekinesisEffect_GetSaveSize(Actor* apActor);
};
struct FUN_008df040_shell
{
    unsigned char __thiscall FUN_008df040();
};
extern FUN_008df040_shell* g_TESSaveLoadGame;
struct FUN_0082a670_shell
{
    void __thiscall TelekinesisEffect_Start();
    void __thiscall ValueModifierEffect_Start();
    void __thiscall StartTelekinesisEffect();
};
void* __cdecl FUN_00703390();
struct Flt
{
    operator unsigned int();
};
struct FUN_0082aa90_shell
{
    unsigned int GetFloatAsUInt();
};
void* __cdecl FUN_004b5a80(void const*);
struct FUN_0082aeb0_shell
{
    void* __thiscall FUN_0082aee0();
    void* __thiscall FUN_0082aeb0();
};
