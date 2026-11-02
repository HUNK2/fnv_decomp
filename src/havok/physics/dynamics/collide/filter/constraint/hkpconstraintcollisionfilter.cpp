
// src/havok/physics/dynamics/collide/filter/constraint/hkpconstraintcollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/filter/constraint/hkpconstraintcollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct VtableObject
{
    virtual void v0();
    virtual void v1(int value);
    virtual void v2(int value);
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    void FUN_00d87c20(int value, bool mode);
};
// Calls v2(value) on the VtableObject at this+0x40 when mode is true, otherwise calls v1(value).
// @fnv 0x00d87c20
void Owner::FUN_00d87c20(int value, bool mode)
{
    VtableObject* p = (VtableObject*)((char*)this + 0x40);
    if (mode)
        p->v2(value);
    else
        p->v1(value);
}

struct Primary
{
    virtual void Operation();
    unsigned int unk04;
};
struct Interface0
{
    virtual void Operation();
};
struct Interface1
{
    virtual void Operation();
};
struct Interface2
{
    virtual void Operation();
};
struct Interface3
{
    virtual void Operation();
};
struct FUN_00def350 : Primary, Interface0, Interface1, Interface2, Interface3
{
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    FUN_00def350(void*);
};
struct Secondary
{
    virtual void Operation();
    Secondary()
    {}
};
struct FUN_00d87c50 : FUN_00def350, Secondary
{
    FUN_00d87c50(void*);
    virtual void AnotherOperation();
};
// Constructs the object from p, delegating to the base constructor and setting unk20 to 6.
// @fnv 0x00d87c50
FUN_00d87c50::FUN_00d87c50(void* p) : FUN_00def350(p)
{
    unk20 = 6;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
struct hkpCdBody
{
    void* m_pCollisionShape;
};
struct hkpCollidable : hkpCdBody
{
};
struct hkReferencedObject
{
    virtual ~hkReferencedObject();
    int m_usMemSizeAndFlags;
};
struct hkpCollidableCollidableFilter
{
    virtual ~hkpCollidableCollidableFilter();
    virtual hkBool IsCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const = 0;
};
struct hkpCollisionFilter : hkReferencedObject, hkpCollidableCollidableFilter
{
};
struct hkpEntity;
struct hkpWorld
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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int unk98;
    hkBool m_bBlockExecutingPendingOperations;
    int unkA0;
    int m_iPendingOperationQueueCount;
    void FUN_00c91120();
    void FUN_00c91140();
    void ProcessPair(hkpEntity* a, hkpEntity* b);
    __forceinline void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        m_iCriticalOperationsLockCount--;
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations.m_cBooleanValue)
        {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                FUN_00c91140();
        }
    }
};
struct hkpEntity
{
    int unk00;
    int unk04;
    hkpWorld* m_pOwningWorld;
    int unk0C;
    hkpCollidable m_kCollidable;
};
struct S_00d87e30_Typed
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int getType();
};
struct S_00d87e30_Event
{
    int unk00;
    int unk04;
    int unk08;
    S_00d87e30_Typed* m_typed;
    int unk10;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
};
struct S_00d87e30_Base
{
    virtual void v00();
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
    hkpCollisionFilter* m_pCollisionFilter;
};
struct S_00d87e30_Listener
{
    virtual void ProcessCollisionEvent(S_00d87e30_Event* pEvent);
};
struct S_00d87e30 : S_00d87e30_Base, S_00d87e30_Listener
{
    int DecrementPairCount(hkpEntity* a, hkpEntity* b);
    virtual void ProcessCollisionEvent(S_00d87e30_Event* pEvent);
};
// Validates the event's two entities and collision filter, then locks the world, dispatches the collision pair, and unlocks it.
// @fnv 0x00d87e30
void S_00d87e30::ProcessCollisionEvent(S_00d87e30_Event* pEvent)
{
    if (!pEvent || pEvent->m_typed->getType() == 11)
        return;
    if (!pEvent->m_pEntityA->m_kCollidable.m_pCollisionShape || !pEvent->m_pEntityB->m_kCollidable.m_pCollisionShape)
        return;
    hkpEntity* a = pEvent->m_pEntityA;
    hkpEntity* b = pEvent->m_pEntityB;
    if (DecrementPairCount(a, b) > 0)
        return;
    if (m_pCollisionFilter &&
        !m_pCollisionFilter->IsCollisionEnabled(a->m_kCollidable, b->m_kCollidable).m_cBooleanValue)
        return;
    hkpWorld* world = a->m_pOwningWorld;
    if (!world)
        return;
    world->lockCriticalOperations();
    world->ProcessPair(a, b);
    world->unlockAndAttemptToExecutePendingOperations();
}

// FUN_00d87d70 candidate
struct Provider
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual int unk20();
};

struct D;
struct B;
struct C;

struct A
{
    int unk00;
    int unk04;
    int unk08;
    Provider* m_prov;
    int unk10;
    B* m_kPointB;
    C* m_iThirdValue;
    int unk1C;
};

struct B
{
    int unk00;
    int unk04;
    D* m_iFourthElementInteger;
    int unk0C;
    int m_iB10;
};

struct C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iC10;
};

struct D
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
    int m_i8c;
    int m_i90;
    int m_i94;
    int unk98;
    unsigned char m_b9c;
    unsigned char unk9D;
    unsigned char unk9E;
    unsigned char unk9F;
    int unkA0;
    int m_ia4;
    void CleanupFirst();
    void CleanupSecond();
};

class Cls40
{
  public:
    int CheckPair(B* b, C* c);
};

int __cdecl CallA(void* a, void* b);
void __cdecl CallB(void* p);

class FUN_00d87d70_cls
{
  public:
    void FUN_00d87d70(A* p);
};

// Validates p and its linked B/C/D objects, calls CallA on their fields, then runs CallB and cleans up D when its counter drops to zero.
// @fnv 0x00d87d70
void FUN_00d87d70_cls::FUN_00d87d70(A* p)
{
    if (p == 0)
    {
        return;
    }
    if (p->m_prov->unk20() == 0xb)
    {
        return;
    }
    B* b = p->m_kPointB;
    if (b->m_iB10 == 0)
    {
        return;
    }
    if (p->m_iThirdValue->m_iC10 == 0)
    {
        return;
    }
    if (((Cls40*)((char*)this - 0x40))->CheckPair(b, p->m_iThirdValue) != 1)
    {
        return;
    }
    C* pC = p->m_iThirdValue;
    B* pB = p->m_kPointB;
    void* pResult = (void*)CallA(&pB->m_iB10, &pC->m_iC10);
    if (pResult == 0)
    {
        return;
    }
    D* d = b->m_iFourthElementInteger;
    if (d == 0)
    {
        return;
    }
    d->m_i94 += 1;
    CallB(pResult);
    d->m_i94 -= 1;
    if (d->m_i94 != 0)
    {
        return;
    }
    if (d->m_b9c != 0)
    {
        return;
    }
    if (d->m_i8c != 0)
    {
        d->CleanupFirst();
    }
    if (d->m_ia4 != 1)
    {
        return;
    }
    if (d->m_i90 == 0)
    {
        return;
    }
    d->CleanupSecond();
}

struct S_00d87f60_Arg
{
    struct S_00d87f60_Obj* unk00;
    int unk04;
};
struct S_00d87f60_Flag
{
    char unk00;
    S_00d87f60_Flag(char c)
    {
        unk00 = c;
    }
    S_00d87f60_Flag(const S_00d87f60_Flag& o)
    {
        unk00 = o.unk00;
    }
};
struct S_00d87f60_Data
{
    char unk00;
    void* unk04;
    int unk08;
    char unk0c;
};
struct S_00d87f60_Base
{
    void FUN_00d87c20(int, S_00d87f60_Flag);
};
struct S_00d87f60_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    void FUN_00c91160(S_00d87f60_Data*);
};
struct S_00d87f60
{
    int unk00;
    void FUN_00d87f60(S_00d87f60_Arg*);
};
// @fnv 0x00d87f60
void S_00d87f60::FUN_00d87f60(S_00d87f60_Arg* arg)
{
    S_00d87f60_Obj* obj = arg->unk00;
    if (obj->unk94 != 0)
    {
        S_00d87f60_Data d;
        d.unk00 = 0x23;
        d.unk04 = (char*)this - 0x40;
        d.unk08 = arg->unk04;
        d.unk0c = 0;
        obj->FUN_00c91160(&d);
    }
    else
    {
        ((S_00d87f60_Base*)((char*)this - 0x40))->FUN_00d87c20(arg->unk04, S_00d87f60_Flag(0));
    }
}

typedef void(__thiscall* SlotFn)(void* self, void* arg);
struct Sub_b1297
{
    int GetCount();
    void* GetItem(int index);
};
struct Thing_b1297
{
    int unk00;
    void Init();
};
struct Proxy_b1297
{
    int unk00;
    SlotFn m_04;
};
struct Sec_b1297
{
    virtual void v0();
    virtual void v1(void* item);
};
struct Elem_b1297;
struct ListE_b1297
{
    Elem_b1297** m_00;
    int m_04;
};
struct Elem_b1297
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
    Sub_b1297** m_48;
    int m_4c;
};
struct Arg_b1297
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
    ListE_b1297 m_28;
    int unk30;
    ListE_b1297 m_34;
};
struct WorldOpTask
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
    Thing_b1297 m_30;
    int unk34;
    int unk38;
    int unk3C;
    Sec_b1297 m_40;
    void FUN_00d87ca0(Arg_b1297* a1);
};

// Initializes m_30, then iterates both lists in a1 and calls m_40.v1 on every item of each Sub_b1297 found in each Elem_b1297.
// @fnv 0x00d87ca0
void WorldOpTask::FUN_00d87ca0(Arg_b1297* a1)
{
    this->m_30.Init();
    ListE_b1297* pList = &a1->m_28;
    for (int pass = 0; pass < 2; ++pass)
    {
        for (int i = 0; i < pList->m_04; ++i)
        {
            Elem_b1297* pElem = pList->m_00[i];
            for (int k = 0; k < pElem->m_4c; ++k)
            {
                Sub_b1297* pSub = pElem->m_48[k];
                int iCount = pSub->GetCount();
                for (int j = 0; j < iCount; ++j)
                    this->m_40.v1(pSub->GetItem(j));
            }
        }
        pList = &a1->m_34;
    }
}

// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void FUN_00d87fc0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d87fc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d87fc0
    virtual void FUN_00d87fc0();
};

Derived::Derived()
{}

struct D87FD0Primary
{
    virtual void vfunc00();
    virtual void FUN_00d87fd0();

    int unk04;
};

struct D87FD0Secondary
{
    virtual void FUN_00d87fd0();
};

struct D87FD0Object : D87FD0Primary, D87FD0Secondary
{
    D87FD0Object();

// @fnv 0x00d87fd0
    virtual void FUN_00d87fd0();
};

D87FD0Object::D87FD0Object()
{}

struct D87FE0Primary
{
    virtual void vfunc00();
    virtual void FUN_00d87fe0();

    int unk04;
    int unk08;
};

struct D87FE0Secondary
{
    virtual void FUN_00d87fe0();
};

struct D87FE0Object : D87FE0Primary, D87FE0Secondary
{
    D87FE0Object();

// @fnv 0x00d87fe0
    virtual void FUN_00d87fe0();
};

D87FE0Object::D87FE0Object()
{}

namespace fnv_00d87ff0 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for the second base of a multiple-inheritance class.
struct PrimaryBase
{
    virtual void FUN_00d87ff0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d87ff0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d87ff0
    virtual void FUN_00d87ff0();
};

Derived::Derived()
{}
}  // namespace fnv_00d87ff0

namespace fnv_00d88030 {
struct Base1
{
    virtual void FUN_00d88030();
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
};
struct Base2
{
    virtual void FUN_00d88030();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00d88030
    virtual void FUN_00d88030();
};
Derived::Derived()
{}
}  // namespace fnv_00d88030

struct Obj_d87f00;
struct Owner_d87f00;

struct Pair_d87f00
{
    Obj_d87f00* m_pHeadNode;
    unsigned int m_iSecondInteger;
};

struct Event_d87f00
{
    unsigned char m_kind;
    unsigned char unk01;
    unsigned short unk02;
    void* m_ptr;
    unsigned int m_val;
    unsigned char m_flag;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
};

struct Flag_d87f00
{
    Flag_d87f00(unsigned char v) : m_on(v)
    {}
    Flag_d87f00(const Flag_d87f00& o) : m_on(o.m_on)
    {}
    unsigned char m_on;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
};

struct Obj_d87f00
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int m_94;

    void FUN_00c91160(Event_d87f00* apEvent);
};

struct Owner_d87f00
{
    void FUN_00d87c20(unsigned int aValue, Flag_d87f00 aFlag);
};

struct S_00d87f00
{
    int unk00;
    void FUN_00d87f00(Pair_d87f00* apPair);
};

// Dispatches a pair event to the head node when m_94 is set, otherwise forwards the second integer and a flag to the owner.
// @fnv 0x00d87f00
void S_00d87f00::FUN_00d87f00(Pair_d87f00* apPair)
{
    Obj_d87f00* obj = apPair->m_pHeadNode;
    if (obj->m_94 != 0)
    {
        Event_d87f00 ev;
        ev.m_ptr = (char*)this - 0x40;
        ev.m_kind = 0x23;
        ev.m_val = apPair->m_iSecondInteger;
        ev.m_flag = 1;
        obj->FUN_00c91160(&ev);
    }
    else
    {
        Flag_d87f00 f(1);
        reinterpret_cast<Owner_d87f00*>((char*)this - 0x40)->FUN_00d87c20(apPair->m_iSecondInteger, f);
    }
}

struct ConstraintFilterMemory
{
    virtual void unknown00() = 0;
    virtual void unknown04() = 0;
    virtual void Release(void* object, unsigned int bytes) = 0;
};
struct BSAudio
{
    unsigned int unk00, unk04, unk08, unk0c;
    ConstraintFilterMemory* allocator;
};
BSAudio* FUN_00c85750();
struct ConstraintFilterDeleteReceiver
{
    unsigned int unk00;
    unsigned short size4, unk06;
    void FUN_00d87bf0();
    ConstraintFilterDeleteReceiver* FUN_00d88000(unsigned int flags);
};
// Calls FUN_00d87bf0, then if flags has bit 0 set, releases this object via the BSAudio allocator using size4 bytes, and returns this.
// @fnv 0x00d88000
ConstraintFilterDeleteReceiver* ConstraintFilterDeleteReceiver::FUN_00d88000(unsigned int flags)
{
    FUN_00d87bf0();
    if (flags & 1u)
    {
        BSAudio* audio = FUN_00c85750();
        unsigned int bytes = size4;
        audio->allocator->Release(this, bytes);
    }
    return this;
}
