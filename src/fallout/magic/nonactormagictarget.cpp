// fallout/magic/nonactormagictarget.cpp: NonActorMagicTarget (6 functions)

#include "MagicTarget.h"

class NonActorMagicTarget : public MagicTarget
{
  public:
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
    TESObjectREFR* pTargetObject;
    BSSimpleList<ActiveEffect*> m_kActiveEffects;
};

// @fnv 0x007d6bb0
BSSimpleList<ActiveEffect*>* NonActorMagicTarget::GetActiveEffectList()
{
    return &m_kActiveEffects;
}

void _Deallocate(void*);
struct FUN_00825f30_shell
{
    void FUN_00825f60();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00825f60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00825f30
void* FUN_00825f30_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00825f60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Shell : NonActorMagicTarget
{
    bool FUN_00826060(MagicCaster* apCaster, MagicItem* apSpell, ActiveEffect* apActiveEffect, bool abAreaTarget);
};
struct Hack
{
    void UpdateActiveEffects(float);
};
// @fnv 0x00826060
bool Shell::FUN_00826060(MagicCaster* apCaster, MagicItem* apSpell, ActiveEffect* apActiveEffect, bool abAreaTarget)
{
    bool bresult;
    bresult = MagicTarget::AddEffectToTarget(apCaster, apSpell, apActiveEffect, abAreaTarget);
    if (bresult)
        ((Hack*)this)->UpdateActiveEffects(1.0F);
    return bresult;
}

struct SBase_cls
{
    int unk00;
    int unk04;
    int unk08;
    ~SBase_cls();
};

struct SubC_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ~SubC_cls();
};

struct Sub20_cls
{
    int unk00;
    ~Sub20_cls();
};

struct FUN_00825f60_cls : SBase_cls
{
    SubC_cls m_0c;
    Sub20_cls m_20;
    ~FUN_00825f60_cls();
};

// Destructor for FUN_00825f60_cls; the body is empty, member destructors run implicitly.
// @fnv 0x00825f60
FUN_00825f60_cls::~FUN_00825f60_cls()
{}

struct SpawnedBase_25fd0
{
    virtual void unk00();
    int m_04;
    int m_08;

    SpawnedBase_25fd0(int value);
    ~SpawnedBase_25fd0();
};

struct SpawnedSecondary_25fd0
{
    virtual void unk00();
    int m_04;
    int m_08;
    int m_0c;

    SpawnedSecondary_25fd0();
    ~SpawnedSecondary_25fd0();
};

struct SpawnedMember_25fd0
{
    int m_00;
    int m_04;

    SpawnedMember_25fd0();
};

class FUN_00825fd0_cls : public SpawnedBase_25fd0, public SpawnedSecondary_25fd0
{
  public:
    int m_1c;
    SpawnedMember_25fd0 m_20;

    FUN_00825fd0_cls(int value);
    virtual void Body();
};

// Initializes the base with 0x33 and stores the given value in m_1c.
// @fnv 0x00825fd0
FUN_00825fd0_cls::FUN_00825fd0_cls(int value) : SpawnedBase_25fd0(0x33)
{
    m_1c = value;
}

struct B1_25ad0
{
    virtual void a();
    int m_04;
    int m_08;
    B1_25ad0(int v);
    ~B1_25ad0();
};
struct B2_25ad0
{
    virtual void b();
    int m_04;
    int m_08;
    B2_25ad0();
};
class FUN_00825ad0_cls : public B1_25ad0, public B2_25ad0
{
  public:
    int m_18;
    int m_1c;
    int m_20;
    FUN_00825ad0_cls(int v);
    virtual void Body();
};
// Initializes the base B1_25ad0 with 0x32, sets m_20 to v, and zeroes m_18 and m_1c.
// @fnv 0x00825ad0
FUN_00825ad0_cls::FUN_00825ad0_cls(int aiValue) : B1_25ad0(0x32), B2_25ad0()
{
    m_20 = aiValue;
    m_18 = 0;
    m_1c = 0;
}
