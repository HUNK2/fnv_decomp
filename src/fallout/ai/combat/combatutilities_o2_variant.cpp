
// src/fallout/ai/combat/combatutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/combatutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/ai/combat/combatutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" float __cdecl FUN_005b9e80(float);
float __cdecl FUN_009a7dd0(float a, float b, float c);
extern int DAT_011a558c;
char FUN_009a97b0(char a1, char a2);
extern "C" double DAT_0103c348;
extern "C" int DAT_011a558c;
float ScaleCharToFloat(char arg);
struct FUN_009a9f00_shell
{
    void __thiscall SetFieldE0(float value);
};
struct BGSProjectile
{
    bool GetFlag(unsigned int) const;
};
struct FUN_009a7f80_shell : BGSProjectile
{
    bool FUN_009a7f80() const;
};
extern "C" double _DAT_0103c348;
long __cdecl ScaleByRatio(float a);
