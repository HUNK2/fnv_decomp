
// src/fallout/ai/combat/flameprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/flameprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/ai/combat/flameprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/flameprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Flt
{
    operator unsigned int() const;
};
struct FUN_009b3cb0_shell
{
    unsigned int FUN_009b3cb0();
};
struct BGSLoadFormBuffer
{
    void ReadTypedData(void* pBuf, unsigned int uSize);
};
struct BeamProjectile
{
    void LoadProjectile(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct FlameProjectile : BeamProjectile
{
    FlameProjectile();
    void FUN_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer);
};
// placeholder declarations
struct FUN_009b32b0_shell
{
    void ConfigureFlags();
};
struct FUN_005de0a0_shell
{
    void FUN_005de0a0(int, int);
};
struct FUN_009bda10_shell
{
    void FUN_009bda10();
};
