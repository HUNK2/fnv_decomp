// fallout_shared/aiformulas.cpp: AIFormulas (22 functions)

#include "aiformulas_decls.h"
// Returns base plus the attribute and luck contributions, each scaled by a runtime float setting and passed through a helper.
// @fnv 0x00643c20
float __cdecl AIFormulas::CalculateSkillValue(float base, float attribute, float luck)
{
    float result = base;
    result += FUN_00406ce0(attribute * originalRuntimeFloatSetting326.Float()->f);
    result += FUN_004e4450(luck * originalRuntimeFloatSetting314.Float()->f);
    return result;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting293;

// Returns 1 if afHeightOrLength is not above the runtime float setting, otherwise the integer quotient of afHeightOrLength divided by that setting.
// @fnv 0x00642e80
int __cdecl FUN_00642e80(float afHeightOrLength)
{
    int iresult = 1;
    if (afHeightOrLength > *reinterpret_cast<float*>(originalRuntimeFloatSetting293.Float()))
    {
        iresult =
            static_cast<int>(afHeightOrLength / *reinterpret_cast<float*>(originalRuntimeFloatSetting293.Float()));
    }
    return iresult;
}

struct SettingT_GameSettingCollection_
{
    float* Float();
};
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting277;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting272;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting268;
extern SettingT_GameSettingCollection_* DAT_0119b194[];
extern SettingT_GameSettingCollection_* DAT_0119b1ac[];
float __cdecl RandomFloat(float, float);
// Computes a base duration from settings scaled by energy level and proc index, then returns a random duration within a jittered min/max range.
// @fnv 0x006435c0
float FUN_006435c0(int aiEngergyLevel, int aiProcIndex)
{
    float fenergyMult;
    float fdurationMax;
    float fdurationMin;
    float fbaseDuration;
    float fenergy;
    float fduration;
    fenergy = (float)aiEngergyLevel;
    fbaseDuration = *originalRuntimeFloatSetting268.Float() * *DAT_0119b194[aiProcIndex]->Float();
    fenergyMult = *originalRuntimeFloatSetting272.Float() * *DAT_0119b1ac[aiProcIndex]->Float();
    fbaseDuration = (1 + fenergy * fenergyMult) * fbaseDuration;
    fdurationMin = (1 - *originalRuntimeFloatSetting277.Float()) * fbaseDuration;
    fdurationMax = (1 + *originalRuntimeFloatSetting277.Float()) * fbaseDuration;
    fduration = RandomFloat(fdurationMin, fdurationMax);
    return fduration;
}

extern int DAT_0119b144[];
extern SettingT<GameSettingCollection>* DAT_0119b17c[];

// Looks up the primary attribute and base value for a skill index from DAT_0119b144 and the setting table DAT_0119b17c, writing them to the output pointers.
// @fnv 0x00643bf0
void __cdecl GetSkillAttributeAndBase(int aiSkill, int* aiPrimaryAttribute, float* afBase)
{
    *aiPrimaryAttribute = DAT_0119b144[aiSkill];
    *afBase = *reinterpret_cast<float*>(DAT_0119b17c[aiSkill]->Float());
}

void __cdecl FUN_00ec6f20(int a, int b, int c, int d);
struct FUN_006c8980_stand
{
    int pad;
    int a;
    int b;
    void FUN_006c8980(int fn);
};
// Calls FUN_00ec6f20 with the object's a and b fields, 0x10 and fn.
// @fnv 0x006c8980
void FUN_006c8980_stand::FUN_006c8980(int fn)
{
    FUN_00ec6f20(a, b, 0x10, fn);
}

struct ActorValue
{
    enum Index
    {
    };
    static float __cdecl ClampValue(Index, float);
};

void __cdecl FUN_00643870(int*, float);

struct VObj
{
    virtual float m0(int);
    virtual float m1(int);
    virtual float m2(int);
    virtual float m3(int);
    virtual float m4(int);
    virtual float m5(int);
    virtual float m6(int);
    virtual float m7(int);
    virtual float m8(int);
};

// @fnv 0x00643820
void __cdecl FUN_00643820(int* pObj)
{
    float result = ((VObj*)pObj)->m8(7);
    result = ActorValue::ClampValue((ActorValue::Index)7, result);
    FUN_00643870(pObj, result);
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting310;

// @fnv 0x00643a50
float FUN_00643a50()
{
    return originalRuntimeFloatSetting310.Float()->f;
}

float __cdecl GetSkillValue(void*, int, bool);

// Calls GetSkillValue with arg2, arg3 and false, returning the resulting float.
// @fnv 0x00643bd0
float __cdecl FUN_00643bd0(void* arg2, int arg3)
{
    float result = GetSkillValue(arg2, arg3, 0);
    return result;
}

struct SettingFloat
{
    float* Float();
};

extern SettingFloat g_011cd48c;
extern SettingFloat originalRuntimeFloatSetting154;
extern SettingFloat g_011cd8e4;
extern SettingFloat originalRuntimeFloatSetting157;
extern SettingFloat g_011cda88;
extern SettingFloat originalRuntimeFloatSetting153;
extern SettingFloat g_011cdef8;
extern SettingFloat originalRuntimeFloatSetting156;

// Computes a weighted sum of three inputs using float settings, truncates it to int, and clamps it between two setting bounds.
// @fnv 0x00643400
int __cdecl ComputeClampedSettingSum(int aiFirst, int aiSecond, float afThird)
{
    int iresult = 0;
    float fTerm1 = *g_011cdef8.Float() + *g_011cd8e4.Float() * aiFirst;
    float fTerm2 = *g_011cd48c.Float() + *originalRuntimeFloatSetting153.Float() * aiSecond;
    float fTerm3 = *g_011cda88.Float() + *originalRuntimeFloatSetting154.Float() * afThird;
    iresult = (int)(fTerm1 + fTerm2 + fTerm3);
    if (iresult < *originalRuntimeFloatSetting156.Float())
        iresult = (int)*originalRuntimeFloatSetting156.Float();
    else if (iresult > *originalRuntimeFloatSetting157.Float())
        iresult = (int)*originalRuntimeFloatSetting157.Float();
    return iresult;
}

namespace fnv_00643a70 {
struct ActorValueOwner
{
    int GetActorValueAsInteger(int aeIndex);
};

struct SettingFloat
{
    float* Float();
};

extern SettingFloat g_011cd4d8;
extern SettingFloat g_011cd360;
extern SettingFloat g_011cda10;
extern SettingFloat originalRuntimeFloatSetting311;
extern SettingFloat originalRuntimeFloatSetting312;

// Reads actor value index 7 and returns the float from one of five settings based on the value (6-10), otherwise 0.
// @fnv 0x00643a70
float __cdecl FUN_00643a70(ActorValueOwner* apActor)
{
    float fresult = 0.0f;
    switch (apActor->GetActorValueAsInteger(7))
    {
    case 6:
        fresult = *g_011cd4d8.Float();
        break;
    case 7:
        fresult = *g_011cd360.Float();
        break;
    case 8:
        fresult = *g_011cda10.Float();
        break;
    case 9:
        fresult = *originalRuntimeFloatSetting311.Float();
        break;
    case 10:
        fresult = *originalRuntimeFloatSetting312.Float();
        break;
    }
    return fresult;
}
}  // namespace fnv_00643a70

struct Setting_S
{
    float* Float();
};
extern Setting_S g_011cd550;
extern Setting_S g_011cd7f0;
extern Setting_S originalRuntimeFloatSetting155;
// Computes a value from two float settings scaled by a, subtracts it from another setting, and halves the result.
// @fnv 0x006434f0
float FUN_006434f0(int aiValue)
{
    float fResult = *g_011cd550.Float() + *g_011cd7f0.Float() * aiValue;
    fResult = (*originalRuntimeFloatSetting155.Float() - fResult) / 2.0;
    return fResult;
}

namespace fnv_00643670 {
struct ActorValue
{
    enum Index
    {
        VAL7 = 7
    };
    static float __cdecl ClampValue(Index, float);
};
struct Dummy
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float Func(int);
};
void __cdecl ComputeActorLevel(Dummy*, float);
// @fnv 0x00643670
void __cdecl FUN_00643670(Dummy* p)
{
    float f = p->Func(7);
    f = ActorValue::ClampValue((ActorValue::Index)7, f);
    ComputeActorLevel(p, f);
}
}  // namespace fnv_00643670

namespace fnv_006439d0 {
struct Setting_S
{
    float* Float();
};
struct ActorValue
{
    enum Index
    {
        kDummy = 0
    };
};
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(ActorValue::Index);
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting306;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting307;
// @fnv 0x006439d0
float FUN_006439d0(ActorValueOwner* apActorValueOwner)
{
    return (float)((double)apActorValueOwner->GetActorValueFloatByIndex((ActorValue::Index)10) *
                       *reinterpret_cast<Setting_S*>(&originalRuntimeFloatSetting306)->Float() +
                   *reinterpret_cast<Setting_S*>(&originalRuntimeFloatSetting307)->Float());
}
}  // namespace fnv_006439d0

namespace fnv_00643a10 {
struct ActorValue
{
    enum Index
    {
        AV_Dummy = 0
    };
};
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(ActorValue::Index);
};
struct Setting_S
{
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting308;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting309;
// @fnv 0x00643a10
float FUN_00643a10(ActorValueOwner* pActorValueOwner)
{
    return (double)pActorValueOwner->GetActorValueFloatByIndex((ActorValue::Index)5) *
               *reinterpret_cast<Setting_S*>(&originalRuntimeFloatSetting308)->Float() +
           *reinterpret_cast<Setting_S*>(&originalRuntimeFloatSetting309)->Float();
}
}  // namespace fnv_00643a10

namespace fnv_00643b50 {
class Setting_S
{
  public:
    float* Float();
};

class ActorValueOwner
{
  public:
    float GetActorValueFloatByIndex(int);
};

extern Setting_S originalRuntimeFloatSetting313;
extern Setting_S g_011cd12c;
extern double _DAT_01012060;

// @fnv 0x00643b50
float FUN_00643b50(ActorValueOwner* owner, int value)
{
    float fResult = 0.0f;

    switch (value)
    {
    case 17: {
        float fClampedValue = FUN_00406ce0(static_cast<float>(
            ((static_cast<double>(owner->GetActorValueFloatByIndex(5)) + *originalRuntimeFloatSetting313.Float()) *
             *g_011cd12c.Float())));

        if (fClampedValue > _DAT_01012060)
            fResult += fClampedValue;
        break;
    }
    }

    return fResult;
}
}  // namespace fnv_00643b50

namespace fnv_00643540 {
struct SettingFloat
{
    float* Float();
};

struct SettingSlot16
{
    SettingFloat* m_00;
    SettingFloat* m_04;
    SettingFloat* m_08;
    SettingFloat* m_0c;
};

extern SettingSlot16 DAT_011cd680[];

float __cdecl FUN_006429e0(float a, float b);
float __cdecl FUN_00476b70(float a, float b);

// Reads four floats from the setting slot at aiIndex, combines the first two into afOutA and the last two into afOutB.
// @fnv 0x00643540
void __cdecl GetSettingPairValues(int aiIndex, float* afOutA, float* afOutB)
{
    SettingSlot16* slot = &DAT_011cd680[aiIndex];
    *afOutA = FUN_006429e0(*slot->m_00->Float(), *slot->m_04->Float());
    *afOutB = FUN_00476b70(*slot->m_08->Float(), *slot->m_0c->Float());
}
}  // namespace fnv_00643540

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting295;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting294;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting298;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting297;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting296;
struct TESActorBaseS
{
    unsigned int GetLevelStub(int a);
};
struct ActorBase0
{
    virtual bool v000();
    virtual bool v004();
    virtual bool v008();
    virtual bool v00C();
    virtual bool v010();
    virtual bool v014();
    virtual bool v018();
    virtual bool v01C();
    virtual bool v020();
    virtual bool v024();
    virtual bool v028();
    virtual bool v02C();
    virtual bool v030();
    virtual bool v034();
    virtual bool v038();
    virtual bool v03C();
    virtual bool v040();
    virtual bool v044();
    virtual bool v048();
    virtual bool v04C();
    virtual bool v050();
    virtual bool v054();
    virtual bool v058();
    virtual bool v05C();
    virtual bool v060();
    virtual bool v064();
    virtual bool v068();
    virtual bool v06C();
    virtual bool v070();
    virtual bool v074();
    virtual bool v078();
    virtual bool v07C();
    virtual bool v080();
    virtual bool v084();
    virtual bool v088();
    virtual bool v08C();
    virtual bool v090();
    virtual bool v094();
    virtual bool v098();
    virtual bool v09C();
    virtual bool v0A0();
    virtual bool v0A4();
    virtual bool v0A8();
    virtual bool v0AC();
    virtual bool v0B0();
    virtual bool v0B4();
    virtual bool v0B8();
    virtual bool v0BC();
    virtual bool v0C0();
    virtual bool v0C4();
    virtual bool v0C8();
    virtual bool v0CC();
    virtual bool v0D0();
    virtual bool v0D4();
    virtual bool v0D8();
    virtual bool v0DC();
    virtual bool v0E0();
    virtual bool v0E4();
    virtual bool v0E8();
    virtual bool v0EC();
    virtual bool v0F0();
    virtual bool v0F4();
    virtual bool v0F8();
    virtual bool v0FC();
    virtual bool v100();
    virtual bool v104();
    virtual bool v108();
    virtual bool v10C();
    virtual bool v110();
    virtual bool v114();
    virtual bool v118();
    virtual bool v11C();
    virtual bool v120();
    virtual bool v124();
    virtual bool v128();
    virtual bool v12C();
    virtual bool v130();
    virtual bool v134();
    virtual bool v138();
    virtual bool v13C();
    virtual bool v140();
    virtual bool v144();
    virtual bool v148();
    virtual bool v14C();
    virtual bool v150();
    virtual bool v154();
    virtual bool v158();
    virtual bool v15C();
    virtual bool v160();
    virtual bool v164();
    virtual bool v168();
    virtual bool v16C();
    virtual bool v170();
    virtual bool v174();
    virtual bool v178();
    virtual bool v17C();
    virtual bool v180();
    virtual bool v184();
    virtual bool v188();
    virtual bool v18C();
    virtual bool v190();
    virtual bool v194();
    virtual bool v198();
    virtual bool v19C();
    virtual bool v1A0();
    virtual bool v1A4();
    virtual bool v1A8();
    virtual bool v1AC();
    virtual bool v1B0();
    virtual bool v1B4();
    virtual bool v1B8();
    virtual bool v1BC();
    virtual bool v1C0();
    virtual bool v1C4();
    virtual bool v1C8();
    virtual bool v1CC();
    virtual bool v1D0();
    virtual bool v1D4();
    virtual bool v1D8();
    virtual bool v1DC();
    virtual bool v1E0();
    virtual bool v1E4();
    virtual bool v1E8();
    virtual bool v1EC();
    virtual bool v1F0();
    virtual bool v1F4();
    virtual bool v1F8();
    virtual bool v1FC();
    virtual bool v200();
    virtual bool v204();
    virtual bool v208();
    virtual bool v20C();
    virtual bool v210();
    virtual bool v214();
    virtual bool v218();
    virtual bool v21C();
    virtual bool v220();
    virtual bool v224();
    virtual bool v228();
    virtual bool v22C();
    virtual bool v230();
    virtual bool v234();
    virtual bool v238();
    virtual bool v23C();
    virtual bool v240();
    virtual bool v244();
    virtual bool v248();
    virtual bool v24C();
    virtual bool v250();
    virtual bool v254();
    virtual bool v258();
    virtual bool v25C();
    virtual bool v260();
    virtual bool v264();
    virtual bool v268();
    virtual bool v26C();
    virtual bool v270();
    virtual bool v274();
    virtual bool v278();
    virtual bool v27C();
    virtual bool v280();
    virtual bool v284();
    virtual bool v288();
    virtual bool v28C();
    virtual bool v290();
    virtual bool v294();
    virtual bool v298();
    virtual bool v29C();
    virtual bool v2A0();
    virtual bool v2A4();
    virtual bool v2A8();
    virtual bool v2AC();
    virtual bool v2B0();
    virtual bool v2B4();
    virtual bool v2B8();
    virtual bool v2BC();
    virtual bool v2C0();
    virtual bool v2C4();
    virtual bool v2C8();
    virtual bool v2CC();
    virtual bool v2D0();
    virtual bool v2D4();
    virtual bool v2D8();
    virtual bool v2DC();
    virtual bool v2E0();
    virtual bool v2E4();
    virtual bool v2E8();
    virtual bool v2EC();
    virtual bool v2F0();
    virtual bool v2F4();
    virtual bool v2F8();
    virtual bool v2FC();
    virtual bool v300();
    virtual bool v304();
    virtual bool v308();
    virtual bool v30C();
    virtual bool v310();
    virtual bool v314();
    virtual bool v318();
    virtual bool v31C();
    virtual bool v320();
    virtual bool v324();
    virtual bool v328();
    virtual bool v32C();
    virtual bool v330();
    virtual bool v334();
    virtual bool v338();
    virtual bool v33C();
    virtual bool v340();
    virtual bool v344();
    virtual bool v348();
    virtual bool v34C();
    virtual bool v350();
    virtual bool v354();
    virtual bool v358();
    virtual bool v35C();
    virtual bool v360();

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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
};
struct ActorBase1
{
    virtual void w00();
    virtual void w04();
    virtual void w08();
    virtual void w0C();
    virtual void w10();
    virtual void w14();
    virtual void w18();
    virtual void w1C();
    virtual void w20();
    virtual void w24();
    virtual unsigned short GetLevel();
};
struct ActorS : ActorBase0, ActorBase1
{
    bool IsStub();
    TESActorBaseS* GetActorBase();
};
// Computes a level value from afLevel and runtime float settings, branching on v218/v360 and adjusting for stub actors or positive GetLevel.
// @fnv 0x006436c0
float __cdecl ComputeActorLevel(ActorBase1* apObj, float afLevel)
{
    float fResult = 0.0f;
    ActorS* pActor2 = static_cast<ActorS*>(apObj);
    bool b4 = pActor2->v218();
    bool b3 = pActor2->v360();
    if (b3)
    {
        fResult = (afLevel + originalRuntimeFloatSetting295.Float()->f) * originalRuntimeFloatSetting294.Float()->f;
    }
    else if (b4)
    {
        fResult = (afLevel + originalRuntimeFloatSetting298.Float()->f) * originalRuntimeFloatSetting297.Float()->f;
    }
    if (pActor2->IsStub() && b4 && !b3)
    {
        TESActorBaseS* pBase2 = pActor2->GetActorBase();
        fResult = (float)pBase2->GetLevelStub(0);
    }
    else if (b3 && pActor2->GetLevel() > 0)
    {
        fResult += (pActor2->GetLevel() - 1) * originalRuntimeFloatSetting296.Float()->f;
    }
    return fResult;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting86;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting151;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting152;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting99;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting100;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting98;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting97;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting150;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting101;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting87;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting102;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting90;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting88;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting91;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting93;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting95;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting96;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting92;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting89;
extern SettingT<GameSettingCollection> g_011cdc80;
extern SettingT<GameSettingCollection> g_011cd080;
extern SettingT<GameSettingCollection> g_011cdb84;
extern SettingT<GameSettingCollection> g_011cdeec;
extern SettingT<GameSettingCollection> g_011cd310;
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011cd8c0, g_011cd13c, g_011cd4c0;
int FUN_00647b70(int, int);
float FUN_00404010(float, float);
double FUN_00ec9ac0(double, double);
// @fnv 0x00642ed0
int __cdecl ComputeDamageResult(int aiLevel, int aiBaseDamage, int a10, int aiDamage, float afCurrentHealth, int a1c,
                                int aiPercent, bool a24, int a28, bool abApplyAttackBonus, bool abApplyDeduction,
                                bool abApplyMultiplier, bool abFlag38, bool abFlag3c, int aiCount, int aiRepeats,
                                bool abMaxHealth, bool abFlag4c, int aiBonusType, float* apFirstDamage,
                                float* apSecondaryDamage, float* apThirdDamage, int a60, int a64, int aiPenalty)
{
    float fScaleTmp;
    float adjusted;
    float multiplier9;
    int flag3;
    float factors4;
    int count101;
    int base14;
    int flag6;
    int flag4c_2;
    float fTotal4;
    float bonusA;
    int extra6;
    float attackVal;
    int result7;
    int damage;
    int flag2cB;
    float ratio2;
    float secondary8;
    float first3;
    float repeats4;
    float weighted9;
    int flagA;
    float third_2;
    int flagVal5;
    float maximum3;
    float percentTmp;
    float deduction2;
    int flagVal9;
    float level5;

    result7 = 0;
    fTotal4 = originalRuntimeFloatSetting86.Float()->f;
    base14 = aiBaseDamage;
    extra6 = *g_011cd8c0.Int();
    base14 += *g_011cd13c.Int() * (a64 - a60);
    extra6 -= a64 * *g_011cd4c0.Int();
    base14 += FUN_00647b70(extra6, 0);
    base14 -= aiPenalty;
    flag6 = 0;
    flagVal5 = 0;
    flag4c_2 = 0;
    if (abFlag3c)
        flag6 = 1;
    if (abFlag38)
        flagVal5 = 1;
    if (abFlag4c)
        flag4c_2 = 1;
    bonusA = 0.0f;
    if (aiBonusType == 1)
        bonusA = originalRuntimeFloatSetting151.Float()->f;
    else if (aiBonusType == 2.0)
        bonusA = originalRuntimeFloatSetting152.Float()->f;
    fScaleTmp =
        originalRuntimeFloatSetting99.Float()->f +
        (originalRuntimeFloatSetting100.Float()->f - originalRuntimeFloatSetting99.Float()->f) * (aiLevel / 10.0f);
    fScaleTmp *= 1.0 + flag6 * originalRuntimeFloatSetting98.Float()->f +
                 flagVal5 * originalRuntimeFloatSetting97.Float()->f +
                 flag4c_2 * originalRuntimeFloatSetting150.Float()->f + bonusA;
    damage = aiDamage;
    if (a24)
        damage = 0;
    flagA = 0;
    if (a10 > 0)
        flagA = 1;
    flagVal9 = 0;
    if (abApplyDeduction)
        flagVal9 = 1;
    flag3 = 0;
    if (abApplyMultiplier)
        flag3 = 1;
    flag2cB = 0;
    if (abApplyAttackBonus)
        flag2cB = 1;
    maximum3 = abMaxHealth ? originalRuntimeFloatSetting101.Float()->f * originalRuntimeFloatSetting87.Float()->f
                           : originalRuntimeFloatSetting87.Float()->f;
    ratio2 = FUN_00404010((maximum3 - afCurrentHealth) / maximum3, 0.0f);
    ratio2 = FUN_00ec9ac0(ratio2, originalRuntimeFloatSetting102.Float()->f);
    adjusted = ratio2;
    if (!flagA && aiBonusType != 1)
        adjusted = ratio2 * originalRuntimeFloatSetting90.Float()->f;
    attackVal = flag2cB * (originalRuntimeFloatSetting88.Float()->f + g_011cdc80.Float()->f * a28);
    multiplier9 = 1.0f;
    if (flag3)
        multiplier9 = originalRuntimeFloatSetting91.Float()->f;
    attackVal *= multiplier9;
    count101 = (int)g_011cd080.Float()->f * aiCount;
    first3 = FUN_00404010(adjusted * originalRuntimeFloatSetting93.Float()->f * (count101 + attackVal), 0.0f);
    *apFirstDamage = first3;
    factors4 =
        1.0 + flag2cB * originalRuntimeFloatSetting95.Float()->f + flag3 * originalRuntimeFloatSetting96.Float()->f;
    level5 = (g_011cdb84.Float()->f + a1c) * originalRuntimeFloatSetting92.Float()->f;
    percentTmp = (100 - aiPercent) / 100;
    repeats4 = aiRepeats <= 1 ? 1.0 : 1.0 + (aiRepeats - 1.0) * g_011cdeec.Float()->f;
    secondary8 = FUN_00404010(damage * ratio2 * factors4 * level5 * percentTmp * repeats4, 0.0f);
    if (a24)
        secondary8 *= g_011cd310.Float()->f;
    *apSecondaryDamage = secondary8;
    deduction2 = base14 * flagVal9;
    weighted9 = fScaleTmp * ratio2;
    third_2 = originalRuntimeFloatSetting89.Float()->f * (weighted9 - deduction2);
    *apThirdDamage = third_2;
    fTotal4 = fTotal4 + first3 + secondary8 + third_2;
    if (fTotal4 < 1.0 && fTotal4 > 0.0)
        result7 = 1;
    else
        result7 = (int)fTotal4;
    return result7;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting327;
bool __cdecl FUN_0047f060(int);
void __cdecl GetSkillAttributeAndBase(int aiSkill, int* aiPrimaryAttribute, float* afBase);
float __cdecl CalcSkillBase(float, float, float);
struct TESClass
{
    bool IsTagSkill(ActorValue::Index);
};
struct TESForm
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f1a();
    virtual void f1b();
    virtual void f1c();
    virtual void f1d();
    virtual void f1e();
    virtual void f1f();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f2a();
    virtual void f2b();
    virtual void f2c();
    virtual void f2d();
    virtual void f2e();
    virtual void f2f();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f3a();
    virtual void f3b();
    virtual bool IsActorBase();
    virtual void f3d();
    virtual void f3e();
    virtual void f3f();
    virtual bool IsNPC();
};
struct TESNPC : TESForm
{
    TESClass* GetClass();
};
struct ActorStub
{
    virtual void v0();
    virtual float GetActorValue(int);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float GetActorValueModifierAmount(int);
    virtual void v7();
    virtual void v8();
    virtual TESForm* GetBaseForm();
    float GetPermanentActorValue(int);
};
// @fnv 0x00643c90
float __cdecl GetSkillValue(ActorStub* apActor, int aiSkill, bool abCurrent)
{
    float fResult = 0.0f;
    if (FUN_0047f060(aiSkill))
    {
        int iAttribute = -1;
        GetSkillAttributeAndBase(aiSkill, &iAttribute, &fResult);
        bool bUnused = false;
        if (iAttribute != -1)
        {
            if (!abCurrent)
            {
                fResult = CalcSkillBase(fResult, apActor->GetPermanentActorValue(iAttribute),
                                        apActor->GetPermanentActorValue(11));
            }
            else
            {
                fResult = CalcSkillBase(
                    fResult,
                    ActorValue::ClampValue((ActorValue::Index)iAttribute,
                                           apActor->GetActorValue(iAttribute) + apActor->GetActorValueModifierAmount(iAttribute)),
                    ActorValue::ClampValue((ActorValue::Index)11,
                                           apActor->GetActorValue(11) + apActor->GetActorValueModifierAmount(11)));
            }
        }
        TESForm* pBase = apActor->GetBaseForm();
        if (pBase && pBase->IsActorBase())
        {
            TESForm* pForm = pBase;
            if (pForm->IsNPC())
            {
                TESNPC* pNPC = (TESNPC*)pForm;
                if (pNPC->GetClass() && pNPC->GetClass()->IsTagSkill((ActorValue::Index)aiSkill))
                {
                    fResult += originalRuntimeFloatSetting327.Float()->f;
                }
            }
        }
    }
    return fResult;
}

namespace fnv_00643ff0 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float FUN_004a7290() const;
};
class TESPackage;
struct Actor
{
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00C();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01C();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02C();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03C();
    virtual void virtual040();
    virtual void virtual044();
    virtual void virtual048();
    virtual void virtual04C();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05C();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06C();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07C();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08C();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09C();
    virtual void virtual0A0();
    virtual void virtual0A4();
    virtual void virtual0A8();
    virtual void virtual0AC();
    virtual void virtual0B0();
    virtual void virtual0B4();
    virtual void virtual0B8();
    virtual void virtual0BC();
    virtual void virtual0C0();
    virtual void virtual0C4();
    virtual void virtual0C8();
    virtual void virtual0CC();
    virtual void virtual0D0();
    virtual void virtual0D4();
    virtual void virtual0D8();
    virtual void virtual0DC();
    virtual void virtual0E0();
    virtual void virtual0E4();
    virtual void virtual0E8();
    virtual void virtual0EC();
    virtual void virtual0F0();
    virtual void virtual0F4();
    virtual void virtual0F8();
    virtual void virtual0FC();
    virtual void virtual100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10C();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual void virtual11C();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12C();
    virtual void virtual130();
    virtual void virtual134();
    virtual void virtual138();
    virtual void virtual13C();
    virtual void virtual140();
    virtual void virtual144();
    virtual void virtual148();
    virtual void virtual14C();
    virtual void virtual150();
    virtual void virtual154();
    virtual void virtual158();
    virtual void virtual15C();
    virtual void virtual160();
    virtual void virtual164();
    virtual void virtual168();
    virtual void virtual16C();
    virtual void virtual170();
    virtual void virtual174();
    virtual void virtual178();
    virtual void virtual17C();
    virtual void virtual180();
    virtual void virtual184();
    virtual void virtual188();
    virtual void virtual18C();
    virtual void virtual190();
    virtual void virtual194();
    virtual void virtual198();
    virtual void virtual19C();
    virtual void virtual1A0();
    virtual void virtual1A4();
    virtual void virtual1A8();
    virtual void virtual1AC();
    virtual void virtual1B0();
    virtual void virtual1B4();
    virtual void virtual1B8();
    virtual void virtual1BC();
    virtual void virtual1C0();
    virtual void virtual1C4();
    virtual void virtual1C8();
    virtual void virtual1CC();
    virtual void virtual1D0();
    virtual void virtual1D4();
    virtual void virtual1D8();
    virtual void virtual1DC();
    virtual void virtual1E0();
    virtual void virtual1E4();
    virtual void virtual1E8();
    virtual void virtual1EC();
    virtual void virtual1F0();
    virtual const NiPoint3& GetPosition();
    struct ExtraData* FUN_005d43c0();
    TESPackage* GetCurrentPackage();
    float FUN_008be1b0();
};
class TESPackage
{
  public:
    int GetPackType();
    float GetPackageResult(Actor*, bool);
};
struct FollowerNode
{
    Actor* actor;
    FollowerNode* next;
    bool FUN_008256d0();
    Actor** FUN_006815c0();
    FollowerNode* FUN_00726070();
};
struct ExtraFollower
{
    void* type;
    void* next;
    unsigned int flags;
    FollowerNode* followers;
};
struct ExtraData
{
    ExtraFollower* FUN_00422700();
};
struct FollowerEntry
{
    Actor* actor;
    float distance;
    float spacing;
    float radius;
};
int __cdecl CompareObjects(const void*, const void*);
struct FollowerArray
{
    void* operations;
    FollowerEntry* entries;
    unsigned int count;
    unsigned int capacity;
    FollowerArray(unsigned int);
    ~FollowerArray();
    FollowerEntry& FUN_00558dd0(unsigned int);
    void FUN_006c8980(int(__cdecl*)(const void*, const void*));
    unsigned int FUN_0044ddc0();
};
class GlobalObject2_0040c150
{
  public:
    int* Int();
};
extern GlobalObject2_0040c150 g_011cde98;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting291;
float __cdecl FUN_00404010(float, float);

// Builds a sorted list of the leader's followers whose current package is type 1 and returns the accumulated spacing offset up to the given actor.
// @fnv 0x00643ff0
float __cdecl GetFollowerOffset(Actor* actor, Actor* leader)
{
    float offset = 0.0f;
    ExtraFollower* pExtraFollower = leader ? leader->FUN_005d43c0()->FUN_00422700() : 0;
    if (pExtraFollower)
    {
        unsigned int count = 0;
        if (!pExtraFollower->followers->FUN_008256d0())
        {
            FollowerNode* node = pExtraFollower->followers;
            while (node)
            {
                Actor* follower = *node->FUN_006815c0();
                TESPackage* package = follower->GetCurrentPackage();
                if (package && package->GetPackType() == 1)
                    ++count;
                node = node->FUN_00726070();
            }
        }
        if (count > 0)
        {
            FollowerArray followerList(count);
            unsigned int index = 0;
            FollowerNode* followers = pExtraFollower->followers;
            while (followers)
            {
                Actor* follower = *followers->FUN_006815c0();
                TESPackage* package = follower->GetCurrentPackage();
                if (package && package->GetPackType() == 1)
                {
                    FollowerEntry& entry = followerList.FUN_00558dd0(index);
                    entry.actor = follower;
                    entry.distance = (leader->GetPosition() - follower->GetPosition()).FUN_004a7290();
                    entry.spacing = (float)*g_011cde98.Int();
                    entry.radius = follower->FUN_008be1b0();
                    entry.spacing = package->GetPackageResult(actor, false);
                    ++index;
                }
                followers = followers->FUN_00726070();
            }
            followerList.FUN_006c8980(CompareObjects);
            float distance = 0.0f;
            for (index = 0; index < followerList.FUN_0044ddc0(); ++index)
            {
                FollowerEntry& entry = followerList.FUN_00558dd0(index);
                if (index > 0)
                    distance += followerList.FUN_00558dd0(index - 1).radius + entry.radius +
                                originalRuntimeFloatSetting291.Float()->f;
                distance = FUN_00404010(distance, entry.spacing);
                if (followerList.FUN_00558dd0(index).actor == actor)
                {
                    offset = distance - followerList.FUN_00558dd0(index).spacing;
                    break;
                }
            }
        }
    }
    return offset;
}
}  // namespace fnv_00643ff0

struct FloatSetting428
{
    SETTING_VALUE* FUN_00403e20();
};
extern "C" FloatSetting428 g_011cdee0;
extern "C" FloatSetting428 g_011cdb48;
class ActorValueOwner428
{
  public:
    float FUN_0066ef50(unsigned actorValue);
};
// Returns the sum of a base setting value and the owner's actor value 11 multiplied by another setting value.
// @fnv 0x00643b10
float __cdecl FUN_00643b10(ActorValueOwner428* apActorValueOwner)
{
    float result = g_011cdee0.FUN_00403e20()->f + apActorValueOwner->FUN_0066ef50(11) * g_011cdb48.FUN_00403e20()->f;
    return result;
}

extern SettingT<GameSettingCollection> originalRuntimeFloatSetting300;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting301;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting302;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting303;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting304;

struct S00643870_Primary
{
    virtual void s000();
    virtual void s004();
    virtual void s008();
    virtual void s00c();
    virtual void s010();
    virtual void s014();
    virtual void s018();
    virtual void s01c();
    virtual void s020();
    virtual void s024();
    virtual void s028();
    virtual void s02c();
    virtual void s030();
    virtual void s034();
    virtual void s038();
    virtual void s03c();
    virtual void s040();
    virtual void s044();
    virtual void s048();
    virtual void s04c();
    virtual void s050();
    virtual void s054();
    virtual void s058();
    virtual void s05c();
    virtual void s060();
    virtual void s064();
    virtual void s068();
    virtual void s06c();
    virtual void s070();
    virtual void s074();
    virtual void s078();
    virtual void s07c();
    virtual void s080();
    virtual void s084();
    virtual void s088();
    virtual void s08c();
    virtual void s090();
    virtual void s094();
    virtual void s098();
    virtual void s09c();
    virtual void s0a0();
    virtual void s0a4();
    virtual void s0a8();
    virtual void s0ac();
    virtual void s0b0();
    virtual void s0b4();
    virtual void s0b8();
    virtual void s0bc();
    virtual void s0c0();
    virtual void s0c4();
    virtual void s0c8();
    virtual void s0cc();
    virtual void s0d0();
    virtual void s0d4();
    virtual void s0d8();
    virtual void s0dc();
    virtual void s0e0();
    virtual void s0e4();
    virtual void s0e8();
    virtual void s0ec();
    virtual void s0f0();
    virtual void s0f4();
    virtual void s0f8();
    virtual void s0fc();
    virtual void s100();
    virtual void s104();
    virtual void s108();
    virtual void s10c();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11c();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12c();
    virtual void s130();
    virtual void s134();
    virtual void s138();
    virtual void s13c();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14c();
    virtual void s150();
    virtual void s154();
    virtual void s158();
    virtual void s15c();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16c();
    virtual void s170();
    virtual void s174();
    virtual void s178();
    virtual void s17c();
    virtual void s180();
    virtual void s184();
    virtual void s188();
    virtual void s18c();
    virtual void s190();
    virtual void s194();
    virtual void s198();
    virtual void s19c();
    virtual void s1a0();
    virtual void s1a4();
    virtual void s1a8();
    virtual void s1ac();
    virtual void s1b0();
    virtual void s1b4();
    virtual void s1b8();
    virtual void s1bc();
    virtual void s1c0();
    virtual void s1c4();
    virtual void s1c8();
    virtual void s1cc();
    virtual void s1d0();
    virtual void s1d4();
    virtual void s1d8();
    virtual void s1dc();
    virtual void s1e0();
    virtual void s1e4();
    virtual void s1e8();
    virtual void s1ec();
    virtual void s1f0();
    virtual void s1f4();
    virtual void s1f8();
    virtual void s1fc();
    virtual void s200();
    virtual void s204();
    virtual void s208();
    virtual void s20c();
    virtual void s210();
    virtual void s214();
    virtual bool v218();
    virtual void s21c();
    virtual void s220();
    virtual void s224();
    virtual void s228();
    virtual void s22c();
    virtual void s230();
    virtual void s234();
    virtual void s238();
    virtual void s23c();
    virtual void s240();
    virtual void s244();
    virtual void s248();
    virtual void s24c();
    virtual void s250();
    virtual void s254();
    virtual void s258();
    virtual void s25c();
    virtual void s260();
    virtual void s264();
    virtual void s268();
    virtual void s26c();
    virtual void s270();
    virtual void s274();
    virtual void s278();
    virtual void s27c();
    virtual void s280();
    virtual void s284();
    virtual void s288();
    virtual void s28c();
    virtual void s290();
    virtual void s294();
    virtual void s298();
    virtual void s29c();
    virtual void s2a0();
    virtual void s2a4();
    virtual void s2a8();
    virtual void s2ac();
    virtual void s2b0();
    virtual void s2b4();
    virtual void s2b8();
    virtual void s2bc();
    virtual void s2c0();
    virtual void s2c4();
    virtual void s2c8();
    virtual void s2cc();
    virtual void s2d0();
    virtual void s2d4();
    virtual void s2d8();
    virtual void s2dc();
    virtual void s2e0();
    virtual void s2e4();
    virtual void s2e8();
    virtual void s2ec();
    virtual void s2f0();
    virtual void s2f4();
    virtual void s2f8();
    virtual void s2fc();
    virtual void s300();
    virtual void s304();
    virtual void s308();
    virtual void s30c();
    virtual void s310();
    virtual void s314();
    virtual void s318();
    virtual void s31c();
    virtual void s320();
    virtual void s324();
    virtual void s328();
    virtual void s32c();
    virtual void s330();
    virtual void s334();
    virtual void s338();
    virtual void s33c();
    virtual void s340();
    virtual void s344();
    virtual void s348();
    virtual void s34c();
    virtual void s350();
    virtual void s354();
    virtual void s358();
    virtual void s35c();
    virtual bool v360();
    char pad04[0xa0];
};
struct S00643870_Base1
{
    virtual void b00();
    virtual void b04();
    virtual void b08();
    virtual void b0c();
    virtual void b10();
    virtual void b14();
    virtual void b18();
    virtual void b1c();
    virtual void b20();
    virtual void b24();
    virtual unsigned short GetLevel();
};
struct S00643870_TESActorBase
{
    unsigned int ComputeDerivedValue(int);
};
struct S00643870_Actor : S00643870_Primary, S00643870_Base1
{
    S00643870_TESActorBase* FUN_004181e0();
};
struct S00643870_FUN_0087f4e0_shell
{
    bool FUN_0087f4e0();
};

// Computes a float result from afValue and runtime settings based on actor traits, level, and a shell check.
// @fnv 0x00643870
float __cdecl FUN_00643870(S00643870_Base1* apObj, float afValue)
{
    float fResult = 0.0f;
    S00643870_Actor* pActor2 = static_cast<S00643870_Actor*>(apObj);
    bool bHasTrait4 = pActor2->v218();
    bool bHasSpecial3 = pActor2->v360();

    if (bHasSpecial3)
    {
        fResult = originalRuntimeFloatSetting300.Float()->f + afValue * originalRuntimeFloatSetting301.Float()->f;
    }
    else if (bHasTrait4)
    {
        fResult = originalRuntimeFloatSetting303.Float()->f + afValue * originalRuntimeFloatSetting304.Float()->f;
    }

    if (((S00643870_FUN_0087f4e0_shell*)pActor2)->FUN_0087f4e0() && bHasTrait4 && !bHasSpecial3)
    {
        S00643870_TESActorBase* base2 = pActor2->FUN_004181e0();
        fResult = (float)base2->ComputeDerivedValue(1);
    }
    else if (bHasSpecial3)
    {
        if (pActor2->GetLevel() > 0)
        {
            fResult = (double)(pActor2->GetLevel() - 1) * originalRuntimeFloatSetting302.Float()->f + fResult;
        }
    }

    return fResult;
}
