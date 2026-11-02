
// fallout_shared/gameplayformulas.cpp
// ActorValueUtility::ConvertActorValue (0x00648b50).
//
// XP thresholds come from two SettingT<GameSettingCollection> globals
// (iXPBase / iXPBumpBase). The canonical Setting.h omits the vanilla value
// accessors, so the needed declarations are authored locally for this TU,
// following the accepted actionpoints.cpp precedent.

#pragma pack(push, 4)
union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};
#pragma pack(pop)

class GameSettingCollection
{
};

class SettingT_GameSettingCollection_
{
  public:
    SettingT_GameSettingCollection_();
    ~SettingT_GameSettingCollection_();
    SETTING_VALUE* Int();
};

extern SettingT_GameSettingCollection_ iXPBase;
extern SettingT_GameSettingCollection_ iXPBumpBase;

class ActorValueUtility
{
  public:
    static int ConvertActorValue(int aiLevel);
};

// Returns 0 for levels <= 1, otherwise sums iXPBase plus repeated iXPBump increments across levels up to aiLevel - 1.
// @fnv 0x00648b50
int ActorValueUtility::ConvertActorValue(int aiLevel)
{
    if (aiLevel <= 1)
        return 0;
    int iTotal = iXPBase.Int()->i;
    int iBase = iTotal;
    int iBump = iXPBumpBase.Int()->i;
    for (int i = 1; i < aiLevel - 1; ++i)
    {
        iBase += iBump;
        iTotal += iBase;
    }
    return iTotal;
}

// @fnv 0x005be4d0
int __fastcall FUN_005be4d0(char* pThis)
{
    return *(int*)(pThis + 0x7b8);
}

class SettingT_GameSettingCollection_2
{
  public:
    SETTING_VALUE* Float();
};

class InventoryStackRecord
{
  public:
    static float __cdecl RoundToNearestStep(float, float);
};

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting868;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting869;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting870;

double __cdecl FUN_00408860(float);
float __cdecl FUN_004dd130(float, float);

// @fnv 0x00647c00
float __cdecl ComputeItemValue(float afItemValue, float afItemHealthPercent)
{
    float fvalue = afItemValue;
    float fcondition = afItemHealthPercent / 10.0;
    if (fcondition < 0.0)
    {
        fcondition = 10.0f;
    }
    if (fvalue > 0.0)
    {
        fvalue = (1.0 - ((SettingT_GameSettingCollection_2*)&originalRuntimeFloatSetting870)->Float()->f) * fvalue *
                     ((SettingT_GameSettingCollection_2*)&originalRuntimeFloatSetting868)->Float()->f *
                     FUN_004dd130(fcondition,
                                  ((SettingT_GameSettingCollection_2*)&originalRuntimeFloatSetting869)->Float()->f) +
                 fvalue * ((SettingT_GameSettingCollection_2*)&originalRuntimeFloatSetting870)->Float()->f;
    }
    return FUN_00408860(fvalue) >= 1.0 ? InventoryStackRecord::RoundToNearestStep(fvalue, 1.0f) : fvalue;
}

template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting830;
float __cdecl FUN_00647d10(void*, void*, void*, bool, bool, bool, bool);

// @fnv 0x00647f00
float __cdecl FUN_00647f00(void* apActor, void* apWeapon, void* pArmor, bool abNoWeapon, bool abIsNpc,
                           bool abIsSneaking, bool abOverEncumbered)
{
    float runSpeed = 0.0f;
    runSpeed += FUN_00647d10(apActor, apWeapon, pArmor, abIsSneaking, abNoWeapon, abIsNpc, abOverEncumbered);
    runSpeed *= originalRuntimeFloatSetting830.Float()->f;
    return runSpeed;
}

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting861;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting862;

struct SettingT_GameSettingCollection__Float_Access : public SettingT_GameSettingCollection_
{
    SETTING_VALUE* Float();
};

// Returns the sum of the base float setting and aiEndurance multiplied by the per-point float setting.
// @fnv 0x00648a10
float __cdecl FUN_00648a10(int aiEndurance)
{
    return ((SettingT_GameSettingCollection__Float_Access*)&originalRuntimeFloatSetting861)->Float()->f +
           (float)aiEndurance *
               ((SettingT_GameSettingCollection__Float_Access*)&originalRuntimeFloatSetting862)->Float()->f;
}

extern double DAT_01011588;
double __cdecl _floor(float);

// Computes a floored value from aiIntelligence and DAT_01011588 plus 10, adding 1 when aiLevel is even and aiIntelligence is odd.
// @fnv 0x00648c10
int __cdecl ComputeIntelligenceResult(int aiIntelligence, int aiLevel)
{
    float fresult = (double)aiIntelligence * DAT_01011588 + 10.0;
    int iresult = _floor(fresult);
    if (aiLevel % 2 == 0 && aiIntelligence % 2 == 1)
    {
        iresult += 1;
    }
    return iresult;
}

float __cdecl FUN_00647d10(void*, void*, void*, bool, bool, bool, bool);

// @fnv 0x00647f50
float __cdecl FUN_00647f50(void* apActor, void* apWeapon, void* pArmor, bool abIsNpc, bool abIsSneaking,
                           bool abOverEncumbered)
{
    float runSpeed = FUN_00647d10(apActor, apWeapon, pArmor, false, abIsNpc, abIsSneaking, abOverEncumbered);
    return runSpeed;
}

extern double g_d100;
extern double DAT_0104ee98;

// @fnv 0x00648d70
void __cdecl ComputeInjuryEffectScalars(float* afResistanceTime, float* afMagnitude, float* afMouseScalar,
                                        float afInjuryPercent, float afPainPercent, int aiMedicineSkill)
{
    *afResistanceTime =
        (float)(aiMedicineSkill / g_d100 * DAT_0104ee98 + (1.0 - afInjuryPercent) * 0.20000000298023224 +
                (1.0 - afPainPercent) * 0.10000000149011612);
    *afMagnitude = (float)((g_d100 - aiMedicineSkill) / g_d100 * DAT_0104ee98 + afInjuryPercent * 0.20000000298023224 +
                           afPainPercent * 0.10000000149011612);
    *afMouseScalar = (float)(aiMedicineSkill / g_d100 * DAT_0104ee98 + (1.0 - afInjuryPercent) * 0.20000000298023224 +
                             (1.0 - afPainPercent) * 0.10000000149011612);
}

extern double DAT_01012638;

// @fnv 0x00648e10
float ScaleByConstant(float afValue)
{
    return static_cast<float>(afValue * DAT_01012638);
}

extern double DAT_01011588;

// @fnv 0x00648e30
float ScaleLimbWoundPercent(float afLimbWoundPercent)
{
    return static_cast<float>(afLimbWoundPercent * DAT_01011588);
}

namespace ActorValue {
enum Index
{
    kNone = -1
};
}
class ActorValueOwner
{
  public:
    virtual float GetBaseActorValue(ActorValue::Index aeActorValueIndex);
    virtual int GetBaseActorValueI(ActorValue::Index aeActorValueIndex);
    virtual int GetActorValueI(ActorValue::Index aeActorValueIndex);
    virtual float GetActorValue(ActorValue::Index aeActorValueIndex);
};
struct Setting_S
{
    float* Float();
};
struct TESObjectWEAP
{
    int GetWeaponType() const;
    bool FUN_00646cb0();
};
struct TESObjectARMO
{
    unsigned char GetArmorType();
};
struct CombatDamageCalculator
{
    static float __cdecl GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
};
extern double _gModifierZero;
extern Setting_S originalRuntimeFloatSetting832;
extern Setting_S originalRuntimeFloatSetting826;
extern Setting_S originalRuntimeFloatSetting1088;
extern Setting_S originalRuntimeFloatSetting833;
extern Setting_S originalRuntimeFloatSetting828;
extern Setting_S originalRuntimeFloatSetting829;
extern Setting_S originalRuntimeFloatSetting831;
extern Setting_S originalRuntimeFloatSetting827;
extern Setting_S originalRuntimeFloatSetting1087;

// @fnv 0x00647d10
float FUN_00647d10(ActorValueOwner* pActor, TESObjectWEAP* pWeapon, TESObjectARMO* pArmor, bool bSneaking,
                   bool bIsPlayer, bool bScoped, bool bIgnoreSkill)
{
    float fMult = 0.0f;
    if (pArmor)
    {
        unsigned char ucWeight = pArmor->GetArmorType();
        if (ucWeight == 1)
            fMult += *originalRuntimeFloatSetting827.Float();
        else if (ucWeight == 2)
            fMult += *originalRuntimeFloatSetting826.Float();
    }
    if (pWeapon && !bIsPlayer && pWeapon->FUN_00646cb0())
    {
        if (pWeapon->GetWeaponType() == 8 || pWeapon->GetWeaponType() == 9)
            fMult += *originalRuntimeFloatSetting829.Float();
        else if (pWeapon->GetWeaponType() != 2)
            fMult += *originalRuntimeFloatSetting828.Float();
    }
    float fPenalty = (1.0f - CombatDamageCalculator::GetActorValueMultiplier(pActor, (ActorValue::Index)0x1d, false)) +
                     (1.0f - CombatDamageCalculator::GetActorValueMultiplier(pActor, (ActorValue::Index)0x1e, false));
    float fBase = 1.0f;
    if (fPenalty == 1.0)
        fBase = *originalRuntimeFloatSetting1087.Float();
    else if (fPenalty == 2.0)
        fBase = *originalRuntimeFloatSetting1088.Float();
    if (!bIgnoreSkill && pActor->GetActorValueI((ActorValue::Index)0x48))
        fBase = 1.0f;
    float fResult = pActor->GetActorValue((ActorValue::Index)0x15) * 1.1;
    float fCrippled = fResult * *originalRuntimeFloatSetting833.Float() * fBase;
    float fSkill = fCrippled;
    if (bScoped && bIsPlayer)
        fSkill *= *originalRuntimeFloatSetting831.Float();
    fSkill = (1.0f - fMult) * fSkill;
    if (bSneaking)
        fSkill *= *originalRuntimeFloatSetting832.Float();
    if (fSkill < _gModifierZero)
        return 0.0f;
    return fSkill;
}

namespace fnv_00648090 {
extern double g_d100;
struct Setting_S
{
    float* Float();
};
struct InventoryStackRecord
{
    static float __cdecl RoundToNearestStep(float, float);
};
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
extern Setting_S originalRuntimeFloatSetting941;
extern Setting_S originalRuntimeFloatSetting944;
extern Setting_S originalRuntimeFloatSetting942;
extern Setting_S originalRuntimeFloatSetting940;
extern Setting_S originalRuntimeFloatSetting943;

// @fnv 0x00648090
float ComputeSkillValue(int aiSkill, float afA, float afB, int* apResult)
{
    float fMaxBonus;
    float fTotal = 0.0f;
    afA = afA / 10.0;
    afB = afB / 10.0;
    fMaxBonus = (*originalRuntimeFloatSetting941.Float() - *originalRuntimeFloatSetting940.Float()) * aiSkill / g_d100;
    float fSkillValue = *originalRuntimeFloatSetting942.Float() * FUN_0040ebd0(afA, afB);
    float fMin = *originalRuntimeFloatSetting943.Float() +
                 (*originalRuntimeFloatSetting944.Float() - *originalRuntimeFloatSetting943.Float()) * aiSkill / 100.0f;
    float fSkillBonus = FUN_00404010(afA, afB);
    fTotal = fSkillBonus + *originalRuntimeFloatSetting940.Float() + fMaxBonus + fSkillValue;
    if (apResult)
    {
        if ((int)InventoryStackRecord::RoundToNearestStep(fTotal * g_d100, 1.0f) <=
            (int)InventoryStackRecord::RoundToNearestStep(fSkillBonus * g_d100, 1.0f))
            *apResult = (int)((fSkillBonus + (double)0.1f - *originalRuntimeFloatSetting943.Float()) * g_d100 /
                              (*originalRuntimeFloatSetting944.Float() - *originalRuntimeFloatSetting943.Float()));
    }
    return fTotal * 10.0;
}
}  // namespace fnv_00648090

extern double g_d100;
extern double DAT_01011588;
struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator();
    float Float(float afMin, float afMax);
};

// @fnv 0x00648fa0
void ComputeMedicineHealing(float& afLimbHealPercent, float& afHealthDamagePercent, int aiMedicineSkill,
                            bool abMorphineUsed, float afWoundPercent)
{
    afLimbHealPercent = MersenneTwister::GetRandomGenerator()->Float(0.0f, aiMedicineSkill * g_d100 / g_d100 *
                                                                      (1.0 + abMorphineUsed * DAT_01011588));
    afHealthDamagePercent = MersenneTwister::GetRandomGenerator()->Float(
        0.0f, (aiMedicineSkill - g_d100) / g_d100 * ((afWoundPercent - g_d100) / g_d100) * g_d100 *
                  (1.0 - abMorphineUsed * DAT_01011588));
}

float __cdecl FUN_00647f00(void*, void*, void*, bool, bool, bool, bool);
// Calls FUN_00647f00 with the given actor, weapon, armor and flags, passing false for the sixth argument, and returns the resulting swim speed.
// @fnv 0x00647f90
float __cdecl GetSwimSpeed(void* apActor, void* apWeapon, void* pArmor, bool abNoWeapon, bool abIsNpc,
                           bool abOverEncumbered)
{
    float swimSpeed;
    swimSpeed = FUN_00647f00(apActor, apWeapon, pArmor, abNoWeapon, abIsNpc, false, abOverEncumbered);
    return swimSpeed;
}

namespace fnv_00648a50 {
struct Setting_S
{
    float* Float();
};
template <typename T> class SettingT : public Setting_S
{
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting863;
// @fnv 0x00648a50
float GetScaledLevelValue(int aiLevel)
{
    return (double)aiLevel * *originalRuntimeFloatSetting863.Float();
}
}  // namespace fnv_00648a50

namespace fnv_00648b00 {
struct Setting_S
{
    float* Float();
};
extern double _DAT_01012640;
extern Setting_S originalRuntimeFloatSetting1092;
extern Setting_S originalRuntimeFloatSetting1093;
// @fnv 0x00648b00
float __cdecl ScaleFloatSetting(float afValue, bool abApplySettings)
{
    float result = afValue / _DAT_01012640;
    if (abApplySettings)
    {
        result = *originalRuntimeFloatSetting1092.Float() / _DAT_01012640 +
                 result * *originalRuntimeFloatSetting1093.Float();
    }
    return result;
}
}  // namespace fnv_00648b00

int __cdecl MinInt(int, int);
int __cdecl ComputeIntelligenceResult(int, int);
struct Dummy648bc0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int func1c(int);
    virtual void f8();
    virtual void f9();
    virtual unsigned short func28();
};
// Calls func1c(9), passes the result and 10 to MinInt, then passes that and func28() to ComputeIntelligenceResult and returns the result.
// @fnv 0x00648bc0
int __cdecl FUN_00648bc0(Dummy648bc0* apDummy)
{
    int v;
    v = ComputeIntelligenceResult(MinInt(apDummy->func1c(9), 10), apDummy->func28());
    return v;
}

namespace fnv_00648d30 {
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting1069;
int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);
// @fnv 0x00648d30
int FUN_00648d30(int aiPlayerSkill, int aiLockLevelMax)
{
    return FUN_00647b70(MinInt(aiPlayerSkill - aiLockLevelMax + (int)*originalRuntimeFloatSetting1069.Float(), 100), 0);
}
}  // namespace fnv_00648d30

// @fnv 0x00647cf0
float ConvertUIntToFloat(unsigned int auiValue)
{
    return (float)auiValue;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting839;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting840;

// @fnv 0x00647fd0
float __cdecl FUN_00647fd0(ActorValueOwner* actor)
{
    float result;        // Actor-value coefficient.
    float scale = 0.0f;  // Running interpolated output.
    result = (float)(actor->GetActorValue((ActorValue::Index)21) * 0.01);
    scale = originalRuntimeFloatSetting839.Float()->f;
    scale += (originalRuntimeFloatSetting840.Float()->f - originalRuntimeFloatSetting839.Float()->f) * result;
    if (scale < _gModifierZero)
        return 0.0f;
    return scale;
}

extern SettingT<GameSettingCollection> DAT_011d198c;
extern SettingT<GameSettingCollection> DAT_011d00e4;
extern SettingT<GameSettingCollection> DAT_011d1998;
extern SettingT<GameSettingCollection> DAT_011d06b8;
extern SettingT<GameSettingCollection> DAT_011d0568;
extern SettingT<GameSettingCollection> DAT_011d02b0;
extern SettingT<GameSettingCollection> DAT_011d009c;
extern SettingT<GameSettingCollection> DAT_011d022c;

// Computes two values from afBase, afDivisor and game settings, then applies type-dependent multipliers and flags to both.
// @fnv 0x006482f0
void __cdecl ComputeDerivedValues(float* afValue1, float* afValue2, float afDivisor, float afBase, int aiType,
                                  bool abFlag1, float afMult1, float afMult2, float afMult3, bool abFlag2)
{
    *afValue1 = FUN_004dd130(afBase * DAT_011d00e4.Float()->f / afDivisor, 1.0 / (DAT_011d198c.Float()->f + 1.0));
    *afValue2 = *afValue1 / DAT_011d00e4.Float()->f / DAT_011d1998.Float()->f;

    switch (aiType)
    {
    case 1:
        if (!abFlag1 && !abFlag2)
        {
            *afValue1 += afMult1 * DAT_011d06b8.Float()->f * *afValue1;
            *afValue2 += afMult1 * DAT_011d0568.Float()->f * *afValue2;
        }
    case 2:
        if (abFlag1 && !abFlag2)
        {
            *afValue1 += afMult2 * DAT_011d02b0.Float()->f * *afValue1;
            *afValue2 += afMult2 * DAT_011d009c.Float()->f * *afValue2;
        }
        break;
    case 5:
        if (abFlag1 && !abFlag2)
        {
            *afValue1 += afMult2 * DAT_011d02b0.Float()->f * *afValue1 + afMult3 * DAT_011d022c.Float()->f * *afValue1;
            *afValue2 += afMult2 * DAT_011d009c.Float()->f * *afValue2 + afMult3 * DAT_011d022c.Float()->f * *afValue2;
        }
        else
        {
            *afValue1 += afMult3 * DAT_011d022c.Float()->f * *afValue1;
            *afValue2 += afMult3 * DAT_011d022c.Float()->f * *afValue2;
        }
    case 3:
        *afValue1 += afMult3 * DAT_011d022c.Float()->f * *afValue1;
        *afValue2 += afMult3 * DAT_011d022c.Float()->f * *afValue2;
        break;
    case 4:
        if (!abFlag1 && !abFlag2)
        {
            *afValue1 += *afValue1 * afMult1 * DAT_011d06b8.Float()->f + *afValue2 * afMult3 * DAT_011d022c.Float()->f;
            *afValue2 += *afValue2 * afMult1 * DAT_011d0568.Float()->f + *afValue2 * afMult3 * DAT_011d022c.Float()->f;
        }
        else
        {
            *afValue1 += afMult3 * DAT_011d022c.Float()->f * *afValue1;
            *afValue2 += afMult3 * DAT_011d022c.Float()->f * *afValue2;
        }
        break;
    }
}

extern Setting_S originalRuntimeFloatSetting1115;
extern Setting_S originalRuntimeFloatSetting954;
extern Setting_S originalRuntimeFloatSetting955;
extern Setting_S originalRuntimeFloatSetting956;

// Divides afValue by afDivisor and a runtime setting into pfResult, then adds scaled adjustments selected by aiType and the two flags.
// @fnv 0x00648620
void __cdecl ComputeScaledResult(float* pfResult, float afDivisor, float afValue, int aiType, bool abFlagA,
                                 float afScaleA, float afScaleB, float afScaleC, bool abFlagB)
{
    *pfResult = afValue / afDivisor / *originalRuntimeFloatSetting1115.Float();
    switch (aiType)
    {
    case 1:
        if (!abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleA * *originalRuntimeFloatSetting954.Float();
        }
    case 2:
        if (abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleB * *originalRuntimeFloatSetting956.Float();
        }
        break;
    case 3:
        *pfResult += *pfResult * afScaleC * *originalRuntimeFloatSetting955.Float();
        break;
    case 5:
        if (abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleB * *originalRuntimeFloatSetting956.Float() +
                         *pfResult * afScaleC * *originalRuntimeFloatSetting955.Float();
        }
        else
        {
            *pfResult += *pfResult * afScaleC * *originalRuntimeFloatSetting955.Float();
        }
        break;
    case 4:
        if (!abFlagA && !abFlagB)
        {
            *pfResult += *pfResult * afScaleA * *originalRuntimeFloatSetting954.Float() +
                         *pfResult * afScaleC * *originalRuntimeFloatSetting955.Float();
        }
        else
        {
            *pfResult += *pfResult * afScaleC * *originalRuntimeFloatSetting955.Float();
        }
        break;
    }
}

namespace fnv_00648810 {
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting957;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting958;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting959;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1115;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1209;

// Computes a value from a and b via FUN_004dd130 and applies per-kind setting-based multipliers to it, writing the result to out.
// @fnv 0x00648810
void __cdecl ComputeSettingAdjustedValue(float* pfResult, float afDivisor, float afDividend, int kind, bool flag,
                                         float x, float y, float z, bool other)
{
    *pfResult = FUN_004dd130((afDividend / afDivisor) / originalRuntimeFloatSetting1115.Float()->f,
                             1.0f / originalRuntimeFloatSetting1209.Float()->f);

    switch (kind)
    {
    case 1:
        if (!flag && !other)
            *pfResult = *pfResult + (*pfResult * x) * originalRuntimeFloatSetting957.Float()->f;
    case 2:
        if (flag && !other)
            *pfResult = *pfResult + (*pfResult * y) * originalRuntimeFloatSetting959.Float()->f;
        break;
    case 3:
        *pfResult = *pfResult + (*pfResult * z) * originalRuntimeFloatSetting958.Float()->f;
        break;
    case 5:
        if (flag && !other)
            *pfResult = *pfResult + (((*pfResult * y) * originalRuntimeFloatSetting959.Float()->f) * z) *
                                        originalRuntimeFloatSetting958.Float()->f;
        else
            *pfResult = *pfResult + (*pfResult * z) * originalRuntimeFloatSetting958.Float()->f;
        break;
    case 4:
        if (!flag && !other)
            *pfResult = *pfResult + (((*pfResult * x) * originalRuntimeFloatSetting957.Float()->f) * z) *
                                        originalRuntimeFloatSetting958.Float()->f;
        else
            *pfResult = *pfResult + (*pfResult * z) * originalRuntimeFloatSetting958.Float()->f;
        break;
    }
}
}  // namespace fnv_00648810

namespace fnv_00648a80 {
template <class T> class SettingT
{
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1089;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1090;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1091;
float& __fastcall FUN_00403e20(float* pSetting);
// @fnv 0x00648a80
float ComputeSettingLerp(float fValue)
{
    if (fValue > FUN_00403e20((float*)&originalRuntimeFloatSetting1089))
        return 0.0f;
    float fRatio = 1.0f - fValue / FUN_00403e20((float*)&originalRuntimeFloatSetting1089);
    float fLerp = FUN_00403e20((float*)&originalRuntimeFloatSetting1090) +
                  (FUN_00403e20((float*)&originalRuntimeFloatSetting1091) -
                   FUN_00403e20((float*)&originalRuntimeFloatSetting1090)) *
                      fRatio;
    return fLerp;
}
}  // namespace fnv_00648a80

class Setting648
{
  public:
    SETTING_VALUE* FUN_00403e20();
};

extern Setting648 DAT_011d05ec;
extern Setting648 DAT_011d0fd8;

// Returns the sum of two setting values, with the second multiplied by fValue times 10.0f.
// @fnv 0x00648050
float __cdecl FUN_00648050(float fValue)
{
    return DAT_011d05ec.FUN_00403e20()->f + DAT_011d0fd8.FUN_00403e20()->f * (fValue * 10.0f);
}

class SettingD8230
{
  public:
    float& Float();
};

extern SettingD8230 g_kSettingBaseD8230;
extern SettingD8230 g_kSettingMaxD8230;
extern SettingD8230 g_kSettingMultD8230;

float __cdecl FUN_004bd510(float fValue, float fMin);
int __cdecl FUN_00647b70(int iValue, int iMin);

// Computes a level-scaled multiplier from base/max settings and difficulty, clamps it to a minimum of 1.0, and returns the integer result.
// @fnv 0x00648230
int __cdecl GetLevelAdjustedMult(int iLevel, float fDiff, float fMult)
{
    int iResult = 0;
    float fValue = 0.0f;
    float fLevelValue =
        g_kSettingBaseD8230.Float() + (g_kSettingMaxD8230.Float() - g_kSettingBaseD8230.Float()) * iLevel / 100.0f;
    fDiff = fDiff / 10.0;
    fValue = g_kSettingMultD8230.Float() * fMult * ((fLevelValue - fDiff) / 10.0);
    if (fValue > 0.5)
        iResult = FUN_00647b70((int)FUN_004bd510(fValue, 1.0f), 1);
    return iResult;
}

namespace fnv_00649050 {
struct Setting_S
{
    float fValue;
};
struct originalRuntimeFloatSetting1295_t
{
    Setting_S* Float();
};
extern originalRuntimeFloatSetting1295_t DAT_011d03c4;
extern originalRuntimeFloatSetting1295_t DAT_011d040c;
extern originalRuntimeFloatSetting1295_t DAT_011d0760;
extern originalRuntimeFloatSetting1295_t DAT_011d0370;
// Computes buy and sell price multipliers from skill-based float settings and writes them to the output pointers.
// @fnv 0x00649050
void FUN_00649050(int iSkill, float* pfBuyMult, float* pfSellMult)
{
    *pfBuyMult = DAT_011d03c4.Float()->fValue + DAT_011d040c.Float()->fValue * iSkill / 100.0f;
    *pfSellMult = DAT_011d0760.Float()->fValue + DAT_011d0370.Float()->fValue * iSkill / 100.0f;
}
}  // namespace fnv_00649050
