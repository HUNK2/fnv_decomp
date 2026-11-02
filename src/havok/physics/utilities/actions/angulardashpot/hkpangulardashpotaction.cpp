
// src/havok/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/angulardashpot/hkpangulardashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpAngularDashpotAction.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkQuaternionD4DB
{
    __m128 m_vec;
};

extern const __m128 DAT_010c71b0;

class FUN_00cf4d80
{
  public:
    FUN_00cf4d80(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw();
    virtual ~FUN_00cf4d80() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned long m_ulUserData;
    const char* m_name;
    void* m_pEntityA;
    void* m_pEntityB;
};

class FUN_00d4dbe0 : public FUN_00cf4d80
{
  public:
    FUN_00d4dbe0(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw();
    virtual ~FUN_00d4dbe0() throw();

    hkQuaternionD4DB m_rotation;
    float m_fSpringStrength;
    float m_fMotorDamping;
    int unk38, unk3C;
};

// @fnv 0x00d4dbe0
FUN_00d4dbe0::FUN_00d4dbe0(void* pkEntityA, void* pkEntityB, unsigned long ulUserData) throw()
    : FUN_00cf4d80(pkEntityA, pkEntityB, ulUserData), m_fSpringStrength(0.1f), m_fMotorDamping(0.01f)
{
    m_rotation.m_vec = DAT_010c71b0;
}

namespace fnv_00d4dc30 {
class hkMemoryAllocatorD4DC
{
  public:
    virtual ~hkMemoryAllocatorD4DC() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterD4DC
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4DC* m_pStreamAllocator;
    hkMemoryAllocatorD4DC& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4DC& __cdecl FUN_00c85750();

struct __declspec(align(16)) hkVector4D4DC
{
    __m128 m_vComponents;
    void operator=(const hkVector4D4DC& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkpEntityPairD4DC
{
    void* m_pEntityA;
    void* m_pEntityB;
};

struct hkpConstraintInputD4DC
{
    hkpEntityPairD4DC* m_pair;
    int m_type;
};

class hkReferencedObjectD4DC
{
  public:
    virtual ~hkReferencedObjectD4DC() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int uiSize)
    {
        hkReferencedObjectD4DC* pkObj =
            static_cast<hkReferencedObjectD4DC*>(FUN_00c85750().heap().AllocateMemoryBlock(uiSize));
        pkObj->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObj;
    }
    static void operator delete(void* p) throw();
};

class FUN_00d4dbe0 : public hkReferencedObjectD4DC
{
  public:
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4D4DC m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;
    int unk38;
    int unk3C;

    FUN_00d4dbe0(void* pvEntityA, void* pvEntityB, int iUserData) throw();
    virtual ~FUN_00d4dbe0() throw();
};

class hkpConstraintTemplateD4DC
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_ulUserData;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4D4DC m_kAxisEndPoints;
    float m_kMinimumCorner;
    float m_kMaximumCorner;

    FUN_00d4dbe0* FUN_00d4dc30(const hkpConstraintInputD4DC& kA, const hkpConstraintInputD4DC& kB);
};

// Returns null unless kA.m_type is 2 and kB.m_type is 0; otherwise creates a FUN_00d4dbe0 from kA's entity pair and copies axis end points and min/max corners.
// @fnv 0x00d4dc30
FUN_00d4dbe0* hkpConstraintTemplateD4DC::FUN_00d4dc30(const hkpConstraintInputD4DC& kA,
                                                      const hkpConstraintInputD4DC& kB)
{
    if (kA.m_type != 2)
        return 0;
    if (kB.m_type != 0)
        return 0;
    FUN_00d4dbe0* pkResult = new FUN_00d4dbe0(kA.m_pair->m_pEntityA, kA.m_pair->m_pEntityB, m_ulUserData);
    pkResult->m_kAxisEndPoints = m_kAxisEndPoints;
    pkResult->m_kMinimumCorner = m_kMinimumCorner;
    pkResult->m_kMaximumCorner = m_kMaximumCorner;
    return pkResult;
}
}  // namespace fnv_00d4dc30
