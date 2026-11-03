
// src/fallout/magic/paralysiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/paralysiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ValueModifierEffect
{
    void ApplyEffect();
};

struct ParalysisEffect : ValueModifierEffect
{
    void FUN_008264b0();
};

// @fnv 0x008264b0
void ParalysisEffect::FUN_008264b0()
{
    ValueModifierEffect::ApplyEffect();
}

namespace fnv_00826550 {
struct Actor;

struct BaseEffect
{
    virtual void ValueModifierEffect_FinishInitLoadGame(Actor* apActor);
};

struct ParalysisEffect : BaseEffect
{
    void ParalysisEffect_FinishInitLoadGame(Actor* apActor);
};

// @fnv 0x00826550
void ParalysisEffect::ParalysisEffect_FinishInitLoadGame(Actor* apActor)
{
    BaseEffect::ValueModifierEffect_FinishInitLoadGame(apActor);
}
}  // namespace fnv_00826550

extern int DAT_0107bfbc;
struct ValueModifierEffect_CallHelper
{
    void ValueModifierEffect(void*, void*, void*);
};
struct FUN_008262e0_Holder
{
    void* FUN_008262e0(void*, void*, void*);
};
// Calls ValueModifierEffect with the three arguments, sets the object's vtable pointer to DAT_0107bfbc, and returns this.
// @fnv 0x008262e0
void* FUN_008262e0_Holder::FUN_008262e0(void* apArg1, void* apArg2, void* apArg3)
{
    ((ValueModifierEffect_CallHelper*)this)->ValueModifierEffect(apArg1, apArg2, apArg3);
    *(void**)this = (void*)&DAT_0107bfbc;
    return this;
}

struct ParalysisActor
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual bool IsParalysisImmune(bool abCheck);
};

struct ParalysisMagicTarget
{
    ParalysisActor* GetActor();
};

struct ParalysisValueModifierEffect
{
    void Update(float afElapsed);
    ParalysisMagicTarget* GetTarget();
    void Dispel(bool abForce);
};

struct ParalysisEffectStandIn : ParalysisValueModifierEffect
{
    void UpdateParalysisEffect(float afElapsed);
};

// Updates the effect, then dispels it if the target actor is paralysis immune.
// @fnv 0x00826430
void ParalysisEffectStandIn::UpdateParalysisEffect(float afElapsed)
{
    ParalysisValueModifierEffect::Update(afElapsed);
    ParalysisActor* pActor = GetTarget() ? GetTarget()->GetActor() : 0;
    if (pActor && pActor->IsParalysisImmune(false))
        Dispel(true);
}

struct ParalysisEffectFactoryObject
{
    int unk00;
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

    ParalysisEffectFactoryObject(void* caster, void* item, void* effect);
};

// Allocates and constructs a ParalysisEffectFactoryObject from the caster, item and effect pointers, returning the new object.
// @fnv 0x008264d0
ParalysisEffectFactoryObject* __cdecl CreateParalysisEffectFactoryObject(void* caster, void* item, void* effect)
{
    return new ParalysisEffectFactoryObject(caster, item, effect);
}

struct FUN_008262e0
{
    unsigned int m00;
    unsigned int m04;
    unsigned int m08;
    unsigned int m0c;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1c;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2c;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3c;
    unsigned int m40;
    unsigned int m44;
    unsigned int m48;
    FUN_008262e0(void* source, void* actor, void* target);
};
struct ParalysisController
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void Register(void* effect);
    unsigned int vtableField04;
    void* actor08;
    void* target0c;
    unsigned int m10, m14, m18, m1c, m20, m24;
    void* source28;
    void* CreateEffect();
};
// Allocates a FUN_008262e0 from source28, actor08 and target0c, registers it, and returns it.
// @fnv 0x00826310
void* ParalysisController::CreateEffect()
{
    FUN_008262e0* effect = new FUN_008262e0(source28, actor08, target0c);
    Register(effect);
    return effect;
}

// Decompiled ParalysisEffect_Start (thiscall, void).
struct ParalysisEffectSubject
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual bool IsSubjectActive();
    void FUN_00934250();
};

struct ParalysisSourceHolder
{
    ParalysisEffectSubject* FUN_00822b40();
};

struct FUN_008263c0_cls
{
    ParalysisSourceHolder* FUN_0059bb30();
    void ValueModifierEffect_Start();
    void ParalysisEffect_Start();
};

// Gets the paralysis subject via FUN_0059bb30/FUN_00822b40, calls FUN_00934250 on it, reads IsSubjectActive, then calls ValueModifierEffect_Start.
// @fnv 0x008263c0
void FUN_008263c0_cls::ParalysisEffect_Start()
{
    bool active;
    {
        ParalysisEffectSubject* subject = (this->FUN_0059bb30() != 0) ? this->FUN_0059bb30()->FUN_00822b40() : 0;
        if (subject == 0)
        {
        }
        else
        {
            subject->FUN_00934250();
            active = subject->IsSubjectActive();
            this->ValueModifierEffect_Start();
        }
    }
}

class NiAVObject;
class TESObjectREFR
{
  public:
    NiAVObject* Get3DSimple();
};

void __cdecl ApplyHavokOperation(NiAVObject*, int, int);

struct ParalysisRevertEffect : ParalysisEffect
{
    void FUN_004534f0(TESObjectREFR* actor);
    void ParalysisEffect_Revert(TESObjectREFR* actor);
};

// Calls FUN_004534f0 with actor, then calls FUN_00c8f210 with 0 and 1 if actor->Get3DSimple() is non-null.
// @fnv 0x00826570
void ParalysisRevertEffect::ParalysisEffect_Revert(TESObjectREFR* actor)
{
    NiAVObject* object;
    FUN_004534f0(actor);
    object = actor->Get3DSimple();
    if (object)
        ApplyHavokOperation(object, 0, 1);
}
