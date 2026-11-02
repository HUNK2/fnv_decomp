
// src/fallout/ai/combat/hitdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/hitdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/ai/combat/hitdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/hitdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_009b7040_shell
{
    float GetField168();
};
struct FUN_009b73b0_shell
{
    char GetByteAtOffset() const;
};
struct FUN_009b7840_shell
{
    void RaiseMaxValue(float a);
};
bool FUN_0066de30(int a);
extern float DAT_011f4270;
extern float DAT_011f4274;
struct NiPoint3
{
    float x;
    float y;
    float z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct BooleanFloatQuery
{
    void* m_pAggressor;
    void* pTarget;
    void* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
    void FUN_009b4dc0();
};
struct GlobalObject_00869f00
{
    void Clear(bool a);
};
extern int DAT_0108f9e8;
struct FUN_009b7970_shell
{
    void InitializeAndClear();
};
