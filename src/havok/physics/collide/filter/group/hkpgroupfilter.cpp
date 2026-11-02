
// src/havok/physics/collide/filter/group/hkpgroupfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/group/hkpgroupfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpGroupFilter.h"

extern int DAT_0102e388;
extern int DAT_010c3b80;
extern int DAT_010c3b8c;
extern int DAT_010c3b98;
extern int DAT_010c3bac;

struct FUN_00e48a80_struct
{
    int* p0;
    int* p1;
    int* p2;
    int* p3;
    int* p4;
    int* p5;
    void InitGroupFilterPointers();
};

// @fnv 0x00e48a80
void FUN_00e48a80_struct::InitGroupFilterPointers()
{
    p5 = &DAT_010c3b8c;
    p4 = &DAT_010c3bac;
    p3 = &DAT_010c3b98;
    p2 = &DAT_010c3b80;
    p0 = &DAT_0102e388;
}

struct FUN_00e48970_struct
{
    void ClearMaskedBits(unsigned int, unsigned int);
};

// @fnv 0x00e48970
void FUN_00e48970_struct::ClearMaskedBits(unsigned int auiMaskA, unsigned int auiMaskB)
{
    unsigned int* mask = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x34);

    unsigned int bit = 1;
    unsigned int count = 32;

    do
    {
        if (auiMaskA & bit)
            *mask &= ~auiMaskB;

        if (auiMaskB & bit)
            *mask &= ~auiMaskA;

        ++mask;
        bit = (bit << 1) | (bit >> 31);
    } while (--count);
}

struct FUN_00e48830_class
{
    void ShouldCollide(int* value, int value0, int value1);
};

struct FUN_00e48b60_arg2
{
    int unknown_00[7];
    int value_1c;
};

struct FUN_00e48b60_arg1
{
    int unknown_00[9];
    int value_24;
};

struct FUN_00e48b60_class
{
    int* FUN_00e48b60(int* value, FUN_00e48b60_arg1* arg1, FUN_00e48b60_arg2* arg2);
};

// Calls ShouldCollide on the object 0x14 bytes before this, passing value, arg1->value_24 and arg2->value_1c, then returns value.
// @fnv 0x00e48b60
int* FUN_00e48b60_class::FUN_00e48b60(int* value, FUN_00e48b60_arg1* arg1, FUN_00e48b60_arg2* arg2)
{
    reinterpret_cast<FUN_00e48830_class*>(reinterpret_cast<char*>(this) - 0x14)
        ->ShouldCollide(value, arg1->value_24, arg2->value_1c);
    return value;
}

struct hkBoolRet
{
    char b;
    hkBoolRet(bool v) : b(v)
    {}
};

class GroupFilter : public hkpGroupFilter
{
  public:
    hkBoolRet ShouldCollide(unsigned int infoA, unsigned int infoB);
};

// Checks whether two collision filter infos may collide, using group/subgroup masks or the group filter table.
// @fnv 0x00e48830
hkBoolRet GroupFilter::ShouldCollide(unsigned int infoA, unsigned int infoB)
{
    if (((infoA ^ infoB) & 0xffff0000) == 0 && (infoA & 0xffff0000) != 0)
    {
        if ((((infoB >> 5) ^ infoA) & 0x3e0) == 0)
            return false;

        if ((((infoA >> 5) ^ infoB) & 0x3e0) == 0)
            return false;

        return true;
    }

    return (m_uiCollisionGroupMasks[infoA & 0x1f] & (1 << (infoB & 0x1f))) != 0;
}

struct FUN_00e488a0_data
{
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int value20;
};

struct FUN_00e488a0_object
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual int getValue(int input);
};

struct FUN_00e488a0_class
{
    int* CallGetValueAndDispatch(int* value, FUN_00e488a0_data* data, int unused, FUN_00e488a0_object* object,
                                 int input);
};

// Calls object->getValue(input), then forwards value and data->value20 with the result to ShouldCollide on the owner at this-16, returning value.
// @fnv 0x00e488a0
int* FUN_00e488a0_class::CallGetValueAndDispatch(int* value, FUN_00e488a0_data* data, int unused,
                                                 FUN_00e488a0_object* object, int input)
{
    int result = object->getValue(input);
    FUN_00e48830_class* owner = reinterpret_cast<FUN_00e48830_class*>(reinterpret_cast<char*>(this) - 16);
    owner->ShouldCollide(value, data->value20, result);
    return value;
}

class hkpGroupFilterE489
{
  public:
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
    unsigned int m_uiCollisionGroupMasks[32];

    void DisableCollisionPair(int iLayerA, int iLayerB);
};

// Clears the collision bit for iLayerB in row iLayerA and the bit for iLayerA in row iLayerB of the layer mask table.
// @fnv 0x00e48940
void hkpGroupFilterE489::DisableCollisionPair(int iLayerA, int iLayerB)
{
    m_uiCollisionGroupMasks[iLayerA] &= ~(1 << iLayerB);
    m_uiCollisionGroupMasks[iLayerB] &= ~(1 << iLayerA);
}

struct FUN_00e48ab0_value
{
    int unknown_00[7];
    int value_1c;
};

struct FUN_00e48ab0_class
{
    int* __thiscall FUN_00e48ab0(int* value, FUN_00e48ab0_value* arg2, FUN_00e48ab0_value* arg3);
};

// Calls ShouldCollide on the object at this-8, passing value and the value_1c fields of arg2 and arg3, then returns value.
// @fnv 0x00e48ab0
int* FUN_00e48ab0_class::FUN_00e48ab0(int* value, FUN_00e48ab0_value* pFirstValue, FUN_00e48ab0_value* pSecondValue)
{
    reinterpret_cast<FUN_00e48830_class*>(reinterpret_cast<char*>(this) - 8)
        ->ShouldCollide(value, pFirstValue->value_1c, pSecondValue->value_1c);
    return value;
}

struct hkBoolE48B
{
    char m_cBooleanValue;
    hkBoolE48B(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef __declspec(align(16)) unsigned int hkpShapeBufferE48B[128];

struct hkpShapeContainerE48B
{
    virtual ~hkpShapeContainerE48B() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual hkUint32 GetFilterInfoForKey(hkUint32 uiKey) const throw();
};

class hkpShapeE48B : public hkReferencedObject
{
  public:
    hkUlong m_ulUserData;
    int m_type;
};

class hkpShapeCollectionE48B : public hkpShapeE48B, public hkpShapeContainerE48B
{
};

struct hkpCollidableE48B;

struct hkpCdBodyE48B
{
    const hkpShapeE48B* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyE48B* m_parent;

    const hkpShapeE48B* getShape() const
    {
        return m_pCollisionShape;
    }
    hkUint32 getShapeKey() const
    {
        return m_uiCollisionShapeKey;
    }
    const hkpCdBodyE48B* getParent() const
    {
        return m_parent;
    }
    __forceinline const hkpCollidableE48B* getRootCollidable() const
    {
        const hkpCdBodyE48B* pkBody = this;
        while (pkBody->m_parent)
            pkBody = pkBody->m_parent;
        return (const hkpCollidableE48B*)pkBody;
    }
};

struct hkpCollidableE48B : public hkpCdBodyE48B
{
    hkInt8 m_iOwnerOffset;
    hkInt8 m_uiForceCollideOntoPpu;
    hkInt16 m_uiShapeSizeOnSpu;
    hkUint32 m_broadPhaseId;
    hkInt8 m_cBroadPhaseType;
    hkInt8 m_broadPhaseOwnerOffset;
    hkUint16 m_ucObjectQualityType;
    hkUint32 m_uiCollisionFilterData;

    hkUint32 GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};

struct hkpCollisionDispatcherE48B
{
    int m_unk000, m_unk004, m_unk008, m_unk00c, m_unk010, m_unk014, m_unk018, m_unk01c;
    int m_unk020, m_unk024, m_unk028, m_unk02c, m_unk030, m_unk034, m_unk038, m_unk03c;
    int m_unk040, m_unk044, m_unk048, m_unk04c, m_unk050, m_unk054, m_unk058, m_unk05c;
    int m_unk060, m_unk064, m_unk068, m_unk06c, m_unk070, m_unk074, m_unk078, m_unk07c;
    int m_unk080, m_unk084, m_unk088, m_unk08c, m_unk090, m_unk094, m_unk098, m_unk09c;
    int m_unk0a0, m_unk0a4, m_unk0a8, m_unk0ac, m_unk0b0, m_unk0b4, m_unk0b8, m_unk0bc;
    int m_unk0c0, m_unk0c4, m_unk0c8, m_unk0cc, m_unk0d0, m_unk0d4, m_unk0d8, m_unk0dc;
    int m_unk0e0, m_unk0e4, m_unk0e8, m_unk0ec, m_unk0f0, m_unk0f4, m_unk0f8, m_unk0fc;
    int m_unk100, m_unk104, m_unk108, m_unk10c;
    hkUint32 m_auiAlternateTypeFlags[32];

    hkUint32 hasAlternateType(int iType, int iAlternate) const
    {
        return m_auiAlternateTypeFlags[iType] & (1 << iAlternate);
    }
};

struct hkpCollisionInputE48B
{
    hkpCollisionDispatcherE48B* m_pCollisionDispatcher;
};

const hkpShapeContainerE48B* __cdecl FUN_00d2d4b0(const hkpCdBodyE48B* pkBody, hkpShapeBufferE48B& kBuffer) throw();

struct hkpCollidableCollidableFilterE48B
{
    virtual void V0() throw();
};

struct hkpShapeCollectionFilterE48B
{
    virtual hkBoolE48B ShapeCollectionFilter(const hkpCollisionInputE48B& kInput, const hkpCdBodyE48B& kA,
                                             const hkpCdBodyE48B& kB, const hkpShapeContainerE48B& kBContainer,
                                             hkUint32 uiBKey) const throw();
};

class hkpGroupFilterE48B : public hkReferencedObject,
                           public hkpCollidableCollidableFilterE48B,
                           public hkpShapeCollectionFilterE48B
{
  public:
    hkBoolE48B ShouldCollide(hkUint32 uiInfoA, hkUint32 uiInfoB) const throw();
    virtual hkBoolE48B ShapeCollectionFilter(const hkpCollisionInputE48B& kInput, const hkpCdBodyE48B& kA,
                                             const hkpCdBodyE48B& kB, const hkpShapeContainerE48B& kBContainer,
                                             hkUint32 uiBKey) const throw();
};

// Computes the collision filter info for both bodies, walking up the parent chain for alternate shape types, then tests the pair with ShouldCollide.
// @fnv 0x00e48b90
hkBoolE48B hkpGroupFilterE48B::ShapeCollectionFilter(const hkpCollisionInputE48B& kInput, const hkpCdBodyE48B& kA,
                                                     const hkpCdBodyE48B& kB, const hkpShapeContainerE48B& kBContainer,
                                                     hkUint32 uiBKey) const throw()
{
    hkUint32 uiInfoB = kBContainer.GetFilterInfoForKey(uiBKey);
    if (uiInfoB == 0xffffffff)
        uiInfoB = kB.getRootCollidable()->GetFilterInfoForKey();

    hkUint32 uiInfoA;
    if (kA.getParent() == 0)
    {
        uiInfoA = kA.getRootCollidable()->GetFilterInfoForKey();
    }
    else
    {
        const hkpCdBodyE48B* pkChild = &kA;
        const hkpCdBodyE48B* pkParent = kA.getParent();
        do
        {
            const int iType = pkParent->getShape()->m_type;
            if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, 7))
            {
                const hkpShapeCollectionE48B* pkCollection =
                    static_cast<const hkpShapeCollectionE48B*>(pkParent->getShape());
                uiInfoA = pkCollection->GetFilterInfoForKey(pkChild->getShapeKey());
                goto done;
            }
            else if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, 8))
            {
                hkpShapeBufferE48B kBuffer;
                const hkpShapeContainerE48B* pkContainer = FUN_00d2d4b0(pkParent, kBuffer);
                uiInfoA = pkContainer->GetFilterInfoForKey(pkChild->getShapeKey());
                goto done;
            }
            else if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, 21))
            {
                uiInfoA = kA.getRootCollidable()->GetFilterInfoForKey();
                goto done;
            }
            else if (kInput.m_pCollisionDispatcher->hasAlternateType(iType, 22))
            {
                return true;
            }
            pkChild = pkParent;
            pkParent = pkParent->getParent();
        } while (pkParent);
        uiInfoA = static_cast<const hkpCollidableE48B*>(pkChild)->GetFilterInfoForKey();
    }
done:
    return ShouldCollide(uiInfoA, uiInfoB);
}

class hkBoolE48
{
  public:
    hkBoolE48()
    {}
    hkBoolE48(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
class hkpShapeContainerE48
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
};
class hkpCdBodyE48
{
  public:
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyE48* m_parent;
    const class hkpCollidableE48* getRootCollidable() const
    {
        const hkpCdBodyE48* body = this;
        while (body->m_parent)
            body = body->m_parent;
        return reinterpret_cast<const hkpCollidableE48*>(body);
    }
};
class hkpCollidableE48 : public hkpCdBodyE48
{
  public:
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiCollisionFilterData;
    unsigned int GetFilterInfoForKey() const
    {
        return m_uiCollisionFilterData;
    }
};
class hkpCollisionInputE48;
class hkReferencedObjectE48
{
  public:
    virtual ~hkReferencedObjectE48();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpCollidableCollidableFilterE48
{
  public:
    virtual ~hkpCollidableCollidableFilterE48();
};
class hkpShapeCollectionFilterE48
{
  public:
    virtual hkBoolE48 FUN_00e48ae0(const hkpCollisionInputE48& input, const hkpCdBodyE48& a, const hkpCdBodyE48& b,
                                   const hkpShapeContainerE48& containerShapeA,
                                   const hkpShapeContainerE48& containerShapeB, unsigned int keyA,
                                   unsigned int keyB) const = 0;
};
class hkpGroupFilterE48 : public hkReferencedObjectE48,
                          public hkpCollidableCollidableFilterE48,
                          public hkpShapeCollectionFilterE48
{
  public:
    enum
    {
        USE_COLLIDABLE_FILTER_INFO = 0xffffffff
    };
    hkBoolE48 ShouldCollide(unsigned int infoA, unsigned int infoB) const;
    virtual hkBoolE48 FUN_00e48ae0(const hkpCollisionInputE48& input, const hkpCdBodyE48& a, const hkpCdBodyE48& b,
                                   const hkpShapeContainerE48& containerShapeA,
                                   const hkpShapeContainerE48& containerShapeB, unsigned int keyA,
                                   unsigned int keyB) const;
};
// Resolves per-shape or root-collidable filter info for two shapes and returns whether they should collide via ShouldCollide.
// @fnv 0x00e48ae0
hkBoolE48 hkpGroupFilterE48::FUN_00e48ae0(const hkpCollisionInputE48& input, const hkpCdBodyE48& a,
                                          const hkpCdBodyE48& b, const hkpShapeContainerE48& containerShapeA,
                                          const hkpShapeContainerE48& containerShapeB, unsigned int keyA,
                                          unsigned int keyB) const
{
    unsigned int infoA = containerShapeA.GetFilterInfoForKey(keyA);
    if (infoA == USE_COLLIDABLE_FILTER_INFO)
        infoA = a.getRootCollidable()->GetFilterInfoForKey();
    unsigned int infoB = containerShapeB.GetFilterInfoForKey(keyB);
    if (infoB == USE_COLLIDABLE_FILTER_INFO)
        infoB = b.getRootCollidable()->GetFilterInfoForKey();
    return ShouldCollide(infoA, infoB);
}

class GFilterE488 : public hkpGroupFilter
{
  public:
    void FUN_00e488e0(hkUint32 infoA, hkUint32 infoB);
};

// For each of 32 collision groups, if infoA has the bit set, OR infoB into the group mask, and if infoB has the bit set, OR infoA into it.
// @fnv 0x00e488e0
void GFilterE488::FUN_00e488e0(hkUint32 infoA, hkUint32 infoB)
{
    hkUint32 mask = 1;
    hkUint32* pGroupMask = m_uiCollisionGroupMasks;
    int count = 32;

    do
    {
        if (infoA & mask)
            *pGroupMask |= infoB;
        if (infoB & mask)
            *pGroupMask |= infoA;

        ++pGroupMask;
        mask = (mask << 1) | (mask >> 31);
        --count;
    } while (count);
}

class S00e489b0_A
{
  public:
    S00e489b0_A();  // FUN_00cbfba0
    virtual void vfA();
    int unk04;
};

class __declspec(novtable) S00e489b0_B
{
  public:
    virtual void vfB();
};
class __declspec(novtable) S00e489b0_C
{
  public:
    virtual void vfC();
};
class __declspec(novtable) S00e489b0_D
{
  public:
    virtual void vfD();
};
class __declspec(novtable) S00e489b0_E
{
  public:
    virtual void vfE();
    int unk18;
    int unk1C;
};

class FUN_00e489b0 : public S00e489b0_A, public S00e489b0_B, public S00e489b0_C, public S00e489b0_D, public S00e489b0_E
{
  public:
    FUN_00e489b0();
    virtual void vfA();
    virtual void vfB();
    virtual void vfC();
    virtual void vfD();
    virtual void vfE();

    int m_iMode;
    int unk24;
    int unk28;
    int unk2C;
    int m_iArrayLength;
    int m_aiSlots[32];
};

// @fnv 0x00e489b0
FUN_00e489b0::FUN_00e489b0()
{
    m_iMode = 2;
    for (int i = 0; i < 32; i++)
        m_aiSlots[i] = -1;
    m_iArrayLength = 0;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void FUN_00e00c00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00e00c00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c00
    virtual void FUN_00e00c00();
};

Derived::Derived()
{}

namespace fnv_00e00c10 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk (multiple inheritance, primary base size 0x14).
// Derived overrides a virtual that both of its bases declare, so the second base's vtable slot
// gets a thunk that moves `this` back by the size of the first base (0x14) and tail-jumps to
// the derived implementation. Only the constructor is defined, so the vtables (and the thunk)
// get emitted.
struct PrimaryBase
{
    virtual void FUN_00e00c10();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00e00c10();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c10
    virtual void FUN_00e00c10();
};

Derived::Derived()
{}
}  // namespace fnv_00e00c10

namespace fnv_00e00c20 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00e00c20();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00e00c20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e00c20
    virtual void FUN_00e00c20();
};

Derived::Derived()
{}
}  // namespace fnv_00e00c20

// FUN_00e00c30 : MSVC this-adjusting thunk  (sub ecx, 0x0c ; jmp <impl>)
struct A1_00e00c30
{
    A1_00e00c30();
    virtual void FUN_00e00c30();
    char pad[0x08];
};
struct A2_00e00c30
{
    A2_00e00c30();
    virtual void FUN_00e00c30();
};
struct Own_00e00c30 : A1_00e00c30, A2_00e00c30
{
    Own_00e00c30();
    virtual void key_fn();
// @fnv 0x00e00c30
    void FUN_00e00c30();
};
Own_00e00c30::Own_00e00c30()
{}
void Own_00e00c30::key_fn()
{}
Own_00e00c30* make_00e00c30()
{
    static Own_00e00c30 o;
    return &o;
}
