
// src/havok/physics/utilities/deprecated/h1group/hkpgroupcollisionfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/deprecated/h1group/hkpgroupcollisionfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpGroupCollisionFilter.h"

struct FUN_00e455f0_Class
{
    void FUN_00e455f0(void*, int, int);
};

struct FUN_00e45990_Class
{
    void* FUN_00e45990(void*, void*, void*);
};

// Calls FUN_00e455f0 on the object at this-0x14 with arg1 and the ints at arg2+0x24 and arg3+0x1c, then returns arg1.
// @fnv 0x00e45990
void* FUN_00e45990_Class::FUN_00e45990(void* arg1, void* arg2, void* arg3)
{
    reinterpret_cast<FUN_00e455f0_Class*>(reinterpret_cast<int>(this) - 0x14)
        ->FUN_00e455f0(arg1, *reinterpret_cast<int*>(reinterpret_cast<char*>(arg2) + 0x24),
                       *reinterpret_cast<int*>(reinterpret_cast<char*>(arg3) + 0x1c));

    return arg1;
}

struct FUN_00e45890_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00e45890_Class : public hkBaseObject
{
  public:
    virtual void* FUN_00e45890(void* param1, void* param2, void* param3);
};

// Calls the base object's FUN_00e455f0 with param1 and the unk1C fields of param2 and param3, then returns param1.
// @fnv 0x00e45890
void* FUN_00e45890_Class::FUN_00e45890(void* param1, void* pObjectA, void* pObjectB)
{
    FUN_00e455f0_Class* base = (FUN_00e455f0_Class*)((char*)this - 8);
    base->FUN_00e455f0(param1, static_cast<FUN_00e45890_Object*>(pObjectA)->unk1C,
                       static_cast<FUN_00e45890_Object*>(pObjectB)->unk1C);
    return param1;
}

struct FUN_00e458c0_Node
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00e458c0_Node* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
};

struct FUN_00e458c0_Vt
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual int s10(int p);
};

struct FUN_00e458c0_class
{
    int unk00;
    int unk04;
    int unk08;
    void* FUN_00e458c0(void* p1, void* p2, FUN_00e458c0_Node* p3, int p4, FUN_00e458c0_Vt* p5, int p6);
};

// @fnv 0x00e458c0
void* FUN_00e458c0_class::FUN_00e458c0(void* p1, void* apUnused, FUN_00e458c0_Node* apNode, int aiUnused,
                                       FUN_00e458c0_Vt* apVt, int aiArg)
{
    int iResult = apVt->s10(aiArg);
    FUN_00e458c0_Node* pLast = apNode;
    while (pLast->m_0c)
    {
        pLast = pLast->m_0c;
    }
    reinterpret_cast<FUN_00e455f0_Class*>(reinterpret_cast<char*>(this) - 0xc)->FUN_00e455f0(p1, pLast->m_1c, iResult);
    return p1;
}

class hkBoolC
{
  public:
    hkBoolC()
    {}
    hkBoolC(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

struct hkLayerFilter
{
    int m_auiShapeKeys[12];
    hkBoolC m_defaultResult;
    int m_layerMasks[32];

    hkBoolC FUN_00e455f0(int mask, int value);
};

// Returns m_defaultResult if mask or value is zero, otherwise ORs selected m_layerMasks entries per mask bits and returns whether value overlaps the result.
// @fnv 0x00e455f0
hkBoolC hkLayerFilter::FUN_00e455f0(int mask, int value)
{
    if (mask == 0 || value == 0)
    {
        return m_defaultResult;
    }
    int iAccumulatedMask = 0;
    if (mask & 0xff)
    {
        iAccumulatedMask = (mask & 0x1) ? m_layerMasks[0] : 0;
        iAccumulatedMask |= (mask & 0x2) ? m_layerMasks[1] : 0;
        iAccumulatedMask |= (mask & 0x4) ? m_layerMasks[2] : 0;
        iAccumulatedMask |= (mask & 0x8) ? m_layerMasks[3] : 0;
        iAccumulatedMask |= (mask & 0x10) ? m_layerMasks[4] : 0;
        iAccumulatedMask |= (mask & 0x20) ? m_layerMasks[5] : 0;
        iAccumulatedMask |= (mask & 0x40) ? m_layerMasks[6] : 0;
        iAccumulatedMask |= (mask & 0x80) ? m_layerMasks[7] : 0;
    }
    if (mask & 0xff00)
    {
        iAccumulatedMask |= (mask & 0x100) ? m_layerMasks[8] : 0;
        iAccumulatedMask |= (mask & 0x200) ? m_layerMasks[9] : 0;
        iAccumulatedMask |= (mask & 0x400) ? m_layerMasks[10] : 0;
        iAccumulatedMask |= (mask & 0x800) ? m_layerMasks[11] : 0;
        iAccumulatedMask |= (mask & 0x1000) ? m_layerMasks[12] : 0;
        iAccumulatedMask |= (mask & 0x2000) ? m_layerMasks[13] : 0;
        iAccumulatedMask |= (mask & 0x4000) ? m_layerMasks[14] : 0;
        iAccumulatedMask |= (mask & 0x8000) ? m_layerMasks[15] : 0;
    }
    if (mask & 0xff0000)
    {
        iAccumulatedMask |= (mask & 0x10000) ? m_layerMasks[16] : 0;
        iAccumulatedMask |= (mask & 0x20000) ? m_layerMasks[17] : 0;
        iAccumulatedMask |= (mask & 0x40000) ? m_layerMasks[18] : 0;
        iAccumulatedMask |= (mask & 0x80000) ? m_layerMasks[19] : 0;
        iAccumulatedMask |= (mask & 0x100000) ? m_layerMasks[20] : 0;
        iAccumulatedMask |= (mask & 0x200000) ? m_layerMasks[21] : 0;
        iAccumulatedMask |= (mask & 0x400000) ? m_layerMasks[22] : 0;
        iAccumulatedMask |= (mask & 0x800000) ? m_layerMasks[23] : 0;
    }
    if (mask & 0xff000000)
    {
        iAccumulatedMask |= (mask & 0x1000000) ? m_layerMasks[24] : 0;
        iAccumulatedMask |= (mask & 0x2000000) ? m_layerMasks[25] : 0;
        iAccumulatedMask |= (mask & 0x4000000) ? m_layerMasks[26] : 0;
        iAccumulatedMask |= (mask & 0x8000000) ? m_layerMasks[27] : 0;
        iAccumulatedMask |= (mask & 0x10000000) ? m_layerMasks[28] : 0;
        iAccumulatedMask |= (mask & 0x20000000) ? m_layerMasks[29] : 0;
        iAccumulatedMask |= (mask & 0x40000000) ? m_layerMasks[30] : 0;
        iAccumulatedMask |= (mask & 0x80000000u) ? m_layerMasks[31] : 0;
    }
    return (value & iAccumulatedMask) != 0;
}

class hkBoolE459
{
  public:
    hkBoolE459()
    {}
    hkBoolE459(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};
class hkpShapeContainerE459
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
};
class hkpCdBodyE459;
class hkpCollisionInputE459;
class hkReferencedObjectE459
{
  public:
    virtual ~hkReferencedObjectE459();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpCollidableCollidableFilterE459
{
  public:
    virtual ~hkpCollidableCollidableFilterE459();
};
class hkpShapeCollectionFilterE459
{
  public:
    virtual hkBoolE459 FUN_00e45910(const hkpCollisionInputE459& input, const hkpCdBodyE459& a, const hkpCdBodyE459& b,
                                    const hkpShapeContainerE459& containerShapeA,
                                    const hkpShapeContainerE459& containerShapeB, unsigned int keyA,
                                    unsigned int keyB) const = 0;
};
class hkpGroupCollisionFilterE459 : public hkReferencedObjectE459,
                                    public hkpCollidableCollidableFilterE459,
                                    public hkpShapeCollectionFilterE459
{
  public:
    hkBoolE459 FUN_00e455f0(unsigned int infoA, unsigned int infoB) const;
    virtual hkBoolE459 FUN_00e45910(const hkpCollisionInputE459& input, const hkpCdBodyE459& a, const hkpCdBodyE459& b,
                                    const hkpShapeContainerE459& containerShapeA,
                                    const hkpShapeContainerE459& containerShapeB, unsigned int keyA,
                                    unsigned int keyB) const;
};
// Gets the filter info for each shape key from its container and returns FUN_00e455f0 applied to both values.
// @fnv 0x00e45910
hkBoolE459 hkpGroupCollisionFilterE459::FUN_00e45910(const hkpCollisionInputE459& input, const hkpCdBodyE459& a,
                                                     const hkpCdBodyE459& b,
                                                     const hkpShapeContainerE459& containerShapeA,
                                                     const hkpShapeContainerE459& containerShapeB, unsigned int keyA,
                                                     unsigned int keyB) const
{
    unsigned int infoA = containerShapeA.GetFilterInfoForKey(keyA);
    unsigned int infoB = containerShapeB.GetFilterInfoForKey(keyB);
    return FUN_00e455f0(infoA, infoB);
}

namespace fnv_00e45950 {
struct hkBoolE459
{
    char m_cBooleanValue;
    hkBoolE459()
    {}
};

struct hkpShapeRayCastInputE459
{
    float m_vFrom[4];
    float m_vTo[4];
    unsigned int m_uiFilterInfo;
};

class hkpShapeE459;

class hkpShapeContainerE459
{
  public:
    virtual ~hkpShapeContainerE459();
    virtual int GetNumChildShapes() const;
    virtual int GetFirstKey() const;
    virtual int GetNextShapeKey(int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(int key) const;
};

class hkReferencedObjectE459
{
  public:
    virtual ~hkReferencedObjectE459();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpCollidableCollidableFilterE459
{
  public:
    virtual ~hkpCollidableCollidableFilterE459();
};

class hkpShapeCollectionFilterE459
{
  public:
    virtual ~hkpShapeCollectionFilterE459();
};

class hkpRayShapeCollectionFilterE459
{
  public:
    virtual ~hkpRayShapeCollectionFilterE459();
    virtual hkBoolE459 FUN_00e45950(const hkpShapeRayCastInputE459& aInput, const hkpShapeE459& bShape,
                                    const hkpShapeContainerE459& bContainer, int bKey) const = 0;
};

class hkpRayCollidableFilterE459
{
  public:
    virtual ~hkpRayCollidableFilterE459();
};

class hkpGroupCollisionFilterE459 : public hkReferencedObjectE459,
                                    public hkpCollidableCollidableFilterE459,
                                    public hkpShapeCollectionFilterE459,
                                    public hkpRayShapeCollectionFilterE459,
                                    public hkpRayCollidableFilterE459
{
  public:
    hkBoolE459 FUN_00e455f0(unsigned int infoA, unsigned int infoB) const;
    virtual hkBoolE459 FUN_00e45950(const hkpShapeRayCastInputE459& aInput, const hkpShapeE459& bShape,
                                    const hkpShapeContainerE459& bContainer, int bKey) const;
};

// Gets the filter info for the shape key from the container and returns the result of FUN_00e455f0 with the input filter info.
// @fnv 0x00e45950
hkBoolE459 hkpGroupCollisionFilterE459::FUN_00e45950(const hkpShapeRayCastInputE459& aInput, const hkpShapeE459& bShape,
                                                     const hkpShapeContainerE459& bContainer, int bKey) const
{
    unsigned int infoB = bContainer.GetFilterInfoForKey(bKey);
    return FUN_00e455f0(aInput.m_uiFilterInfo, infoB);
}
}  // namespace fnv_00e45950

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00cbfc00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00cbfc00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cbfc00
    virtual void FUN_00cbfc00();
};

Derived::Derived()
{}
