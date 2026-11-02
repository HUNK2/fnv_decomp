
// src/havok/physics/utilities/deprecated/disableentity/hkpdisableentitycollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/deprecated/disableentity/hkpdisableentitycollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpDisableEntityCollisionFilter.h"

// @fnv 0x00e467b0
void __stdcall FUN_00e467b0(char* flag, int a, int b)
{
    *flag = 1;
}

// @fnv 0x00e46780
void __stdcall FUN_00e46780(unsigned char* flag, int p2, int p3, int p4, int p5, int p6)
{
    *flag = 1;
}

// @fnv 0x00e46790
void __stdcall FUN_00e46790(char* flag, int a, int b, int c, int d)
{
    *flag = 1;
}

// @fnv 0x00e467a0
void __stdcall FUN_00e467a0(char* flag, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    *flag = 1;
}

void* __cdecl FUN_00c85750(void);

struct FUN_00e46900_Obj
{
    void FUN_00e46900();
};

struct FUN_00dff930_Alloc
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08(void* p, int n);
};

struct FUN_00dff930_Mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dff930_Alloc* m_10;
};

struct FUN_00dff930_class : hkpDisableEntityCollisionFilter
{
    void* FUN_00dff930(unsigned char flag);
};

// @fnv 0x00dff930
void* FUN_00dff930_class::FUN_00dff930(unsigned char uiFlags)
{
    reinterpret_cast<FUN_00e46900_Obj*>(this)->FUN_00e46900();
    if (uiFlags & 1)
    {
        FUN_00dff930_Mgr* mgr = reinterpret_cast<FUN_00dff930_Mgr*>(FUN_00c85750());
        mgr->m_10->slot08(this, m_usMemSizeAndFlags);
    }
    return this;
}

// Empty function that takes an unsigned int argument and does nothing.
// @fnv 0x00e467c0
void __stdcall FUN_00e467c0(unsigned int a1)
{}

struct hkBoolE467
{
    char m_cBooleanValue;
    hkBoolE467(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkpCollidableE467
{
    int m_00;
};

class hkpRigidBodyE467
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkpCollidableE467 m_kCollidable;

    const hkpCollidableE467* getCollidable() const
    {
        return &m_kCollidable;
    }
};

template <class T> class hkArrayE467
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkpProjectileGunE467
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_iMaxProjectiles;
    hkReal m_fReloadTime;
    hkReal m_fTimeSinceLastShot;
    hkArrayE467<hkpRigidBodyE467*> m_kRigidBodies;

    hkBoolE467 FUN_00e467d0(const hkpCollidableE467& kA, const hkpCollidableE467& kB) const;
};

// Returns false if either collidable is found among the rigid bodies' collidables in the array, otherwise true.
// @fnv 0x00e467d0
hkBoolE467 hkpProjectileGunE467::FUN_00e467d0(const hkpCollidableE467& kA, const hkpCollidableE467& kB) const
{
    for (int i = 0; i < m_kRigidBodies.GetLogicalSize(); i++)
    {
        const hkpCollidableE467* pkCollidable = m_kRigidBodies[i]->getCollidable();
        if (pkCollidable == &kA || pkCollidable == &kB)
            return false;
    }
    return true;
}

struct FnvDisabledCollisionFilter : hkpDisableEntityCollisionFilter
{
    char* FUN_00e46820(char* wasRemoved, hkpEntity* entity);
};
// Removes the entity from the filter's array by swapping in the last element, writing 1 to wasRemoved if found, else 0.
// @fnv 0x00e46820
char* FnvDisabledCollisionFilter::FUN_00e46820(char* wasRemoved, hkpEntity* entity)
{
    if (!entity)
    {
        *wasRemoved = 0;
        return wasRemoved;
    }
    for (int index = 0; index < m_kDisabledEntities.m_iElementCount; ++index)
    {
        if (m_kDisabledEntities.m_data[index] == entity)
        {
            volatile int& count = m_kDisabledEntities.m_iElementCount;
            --count;
            int last = count;
            if (last != index)
                m_kDisabledEntities.m_data[index] = m_kDisabledEntities.m_data[last];
            *wasRemoved = 1;
            return wasRemoved;
        }
    }
    *wasRemoved = 0;
    return wasRemoved;
}

struct hkBoolE46
{
    char m_cBooleanValue;
    hkBoolE46(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkpEntityListenerE46;

class hkpEntityE46
{
  public:
    void FUN_00c9c670(hkpEntityListenerE46* listener);
};

class hkpCollisionFilterE46
{
  public:
    virtual ~hkpCollisionFilterE46();
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
};

class hkpEntityListenerE46
{
  public:
    virtual void EntityAddedCallback(hkpEntityE46* entity);
    virtual void FUN_00e46880(hkpEntityE46* entity);
};

class hkpDisableEntityCollisionFilterE46 : public hkpCollisionFilterE46, public hkpEntityListenerE46
{
  public:
    hkBoolE46 FUN_00e46820(hkpEntityE46* entity);
    virtual void FUN_00e46880(hkpEntityE46* entity);
};

// If entity is non-null, calls FUN_00e46820(entity) and then FUN_00c9c670(this) on the entity.
// @fnv 0x00e46880
void hkpDisableEntityCollisionFilterE46::FUN_00e46880(hkpEntityE46* entity)
{
    if (entity)
    {
        FUN_00e46820(entity);
        entity->FUN_00c9c670(this);
    }
}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00dff960();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00dff960();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff960
    virtual void FUN_00dff960();
};

Derived::Derived()
{}

namespace fnv_00dff970 {
// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00dff970();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00dff970();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff970
    virtual void FUN_00dff970();
};

Derived::Derived()
{}
}  // namespace fnv_00dff970

namespace fnv_00dff980 {
struct Base1
{
    virtual void FUN_00dff980();
    int unk04;
    int unk08;
    int unk0C;
};
struct Base2
{
    virtual void FUN_00dff980();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00dff980
    virtual void FUN_00dff980();
};
Derived::Derived()
{}
}  // namespace fnv_00dff980

namespace fnv_00dff990 {
// sub ecx,0x30; jmp target == MSVC adjustor thunk (Derived overrides a virtual both bases declare).
struct PrimaryBase
{
    virtual void FUN_00dff990();
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
};

struct SecondaryBase
{
    virtual void FUN_00dff990();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff990
    virtual void FUN_00dff990();
};

Derived::Derived()
{}
}  // namespace fnv_00dff990

namespace fnv_00dff9a0 {
// Adjustor thunk for FUN_00dff9a0: "sub ecx, 0x14; jmp FUN_00dff930".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function
// inherited from a secondary base: it moves the secondary-base sub-object
// pointer back to the derived object pointer (sub ecx, 0x14) and tail jumps to
// the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 4 int members (4 + 4 * 4 = 0x14).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00dff9a0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00dff9a0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff9a0
    virtual void FUN_00dff9a0();
};

Derived::Derived()
{}
}  // namespace fnv_00dff9a0
