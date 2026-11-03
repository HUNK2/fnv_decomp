
// src/fallout/magic/lockeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/lockeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0080f390
{
    char d[0x48];
    FUN_0080f390(int, int, int);
    ~FUN_0080f390();
};
struct FUN_0080f3c0 : FUN_0080f390
{
    void* __thiscall Copy();
};
// Allocates a FUN_0080f390 from three fields of this object, copies into it via the object's vtable slot 0x11, and returns the new object.
// @fnv 0x0080f3c0
void* __thiscall FUN_0080f3c0::Copy()
{
    FUN_0080f390* pCopy =
        new FUN_0080f390(*(int*)((char*)this + 0x28), *(int*)((char*)this + 8), *(int*)((char*)this + 0xc));
    ((void(__thiscall*)(void*, FUN_0080f390*))(*(void***)this)[0x11])(this, pCopy);
    return pCopy;
}

struct LockExtraData
{
    char m_cOwner;
    char unk01;
    char unk02;
    char unk03;
    int m_iArrayLength;
    char m_cActionFlags;
};

struct TESObjectREFR
{
    LockExtraData* GetLock();
    LockExtraData* TESObjectREFR_AddLock();
    void FUN_005789b0();
    void Lock();
};

class MagicTarget
{
  public:
    virtual ~MagicTarget();
    virtual TESObjectREFR* GetParent();
};

class BSExtraData
{
  public:
    virtual ~BSExtraData();
    int unk04;
    int unk08;
};

class NonActorMagicTarget : public BSExtraData, public MagicTarget
{
};

struct ActiveEffect
{
    MagicTarget* GetTarget();
    float GetFloatAtOffset1C();
    void Dispel(bool bForce);
    void ApplyLockEffect();
};

// @fnv 0x0080f470
void ActiveEffect::ApplyLockEffect()
{
    NonActorMagicTarget* pTarget = dynamic_cast<NonActorMagicTarget*>(GetTarget());
    if (!pTarget || !pTarget->GetParent())
        return;

    LockExtraData* pLock = pTarget->GetParent()->GetLock();
    if (pLock && (!(pLock->m_cActionFlags & 2) || (pLock->m_cActionFlags & 1)))
    {
        Dispel(false);
        return;
    }

    pLock = pTarget->GetParent()->TESObjectREFR_AddLock();
    pLock->m_cOwner = (char)GetFloatAtOffset1C();
    pLock->m_iArrayLength = 0;
    pLock->m_cActionFlags = 2;
    pTarget->GetParent()->FUN_005789b0();
    pTarget->GetParent()->Lock();
}

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};

class TESObjectDOOR : public TESBoundObject
{
};

class TESObjectCONT : public TESBoundObject
{
};

struct TESObjectREFR_80f580 : TESObjectREFR
{
    TESBoundObject* __thiscall FUN_007af430();
};

struct S_80f580_cls
{
    bool FUN_0080f580(MagicTarget* a);
};

// Checks whether the parent reference's base object is a TESObjectDOOR or TESObjectCONT.
// @fnv 0x0080f580
bool S_80f580_cls::FUN_0080f580(MagicTarget* apTarget)
{
    NonActorMagicTarget* t = dynamic_cast<NonActorMagicTarget*>(apTarget);
    if (!t || !t->GetParent())
        return false;
    TESObjectDOOR* door =
        dynamic_cast<TESObjectDOOR*>(static_cast<TESObjectREFR_80f580*>(t->GetParent())->FUN_007af430());
    TESObjectCONT* cont_2 =
        dynamic_cast<TESObjectCONT*>(static_cast<TESObjectREFR_80f580*>(t->GetParent())->FUN_007af430());
    return door || cont_2;
}
