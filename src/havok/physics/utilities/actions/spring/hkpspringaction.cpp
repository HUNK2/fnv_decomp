
// src/havok/physics/utilities/actions/spring/hkpspringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/spring/hkpspringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSpringAction.h"

extern int g_unk01269168;

// @fnv 0x00cf4ef0
int* __cdecl FUN_00cf4ef0()
{
    return &g_unk01269168;
}

void* __cdecl _fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiNumBytes);

struct hkShape00D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x47];
    hkShape00D4F0()
    {
        m_type = 2;
    }
};

struct hkShape90D4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape90D4F0()
    {
        m_type = 9;
    }
};

struct hkShape9CD4F0
{
    unsigned short m_type;
    unsigned short unk02[5];
    hkShape9CD4F0()
    {
        m_type = 8;
    }
};

struct hkShapeA8D4F0
{
    unsigned short m_type;
    unsigned short unk02;
    hkShapeA8D4F0()
    {
        m_type = 7;
    }
};

struct hkShapeB0D4F0
{
    unsigned short m_type;
    unsigned short unk02[0x37];
    hkShapeB0D4F0()
    {
        m_type = 4;
    }
};

struct hkShape120D4F0
{
    unsigned short m_type;
    hkShape120D4F0()
    {
        m_type = 12;
    }
};

class FUN_00d4f000
{
  public:
    hkShape00D4F0 m_s00;
    hkShape90D4F0 m_s90;
    hkShape9CD4F0 m_s9C;
    hkShapeA8D4F0 m_sA8;
    hkShapeA8D4F0 m_sAC;
    hkShapeB0D4F0 m_sB0;
    hkShape120D4F0 m_s120;

    FUN_00d4f000() throw();
};

// Constructs the object by initialising its embedded shape members; the zero-fill branch is never taken because pcBegin equals pcEnd.
// @fnv 0x00d4f000
FUN_00d4f000::FUN_00d4f000() throw()
{
    char* pcBegin = (char*)&m_sB0;
    char* pcEnd = (char*)&m_sB0;
    if (pcBegin < pcEnd)
        _fnv_zlib_memset(pcBegin, 0, pcEnd - pcBegin);
}

struct FUN_00cf4d80
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
    float m_fMass;
    float m_fSpringConstant;
    float m_fDamping;
    bool m_bModifierActive;
    bool m_bEnableState;
    FUN_00cf4d80(void* a, void* b, unsigned long c);
};
extern int DAT_010d08f4;
extern float DAT_01013974;
extern float DAT_0101e2bc;
struct FUN_00d4d340 : FUN_00cf4d80
{
    FUN_00d4d340(void* a, void* b, unsigned long c);
};
// Calls the base constructor, sets the vtable, m_fMass to 1.0, spring constant and damping from globals, and sets both bool flags to true.
// @fnv 0x00d4d340
FUN_00d4d340::FUN_00d4d340(void* a, void* b, unsigned long c) : FUN_00cf4d80(a, b, c)
{
    float* __restrict pf = &m_fSpringConstant;
    m_fMass = 1.0f;
    *pf = DAT_01013974;
    *(int* __restrict*)this = &DAT_010d08f4;
    m_fDamping = DAT_0101e2bc;
    *(volatile bool*)&m_bModifierActive = true;
    *(volatile bool*)&m_bEnableState = true;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sqrt_ss(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkSimdRealD4D3
{
    __m128 m_vValue;

    hkSimdRealD4D3(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkTransformD4D3;

struct hkVector4D4D3
{
    __m128 m_vComponents;

    void FUN_00c7f690(const hkTransformD4D3& kT, const hkVector4D4D3& kV);
    void setSub4(const hkVector4D4D3& a, const hkVector4D4D3& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD4D3 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
    }
};

struct hkTransformD4D3
{
    hkVector4D4D3 m_rotation[3];
    hkVector4D4D3 m_vTranslation;
};

struct hkpEntityD4D3
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    hkTransformD4D3 m_kMotionTransform;
};

class hkBaseObjectD4D3
{
  public:
    virtual ~hkBaseObjectD4D3() throw();
};

class hkpStiffSpringWrapperD4D3 : public hkBaseObjectD4D3
{
  public:
    void UpdatePivotsAndRestLength(const hkVector4D4D3& kPivotAW, const hkVector4D4D3& kPivotBW);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntityD4D3* m_pEntityA;
    hkpEntityD4D3* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4D4D3 m_kPivotInA;
    hkVector4D4D3 m_kPivotInB;
    float m_fSpringRestLength;
};

// Transforms world-space pivots into local entity space, then stores their 3D distance as the spring rest length.
// @fnv 0x00d4d390
void hkpStiffSpringWrapperD4D3::UpdatePivotsAndRestLength(const hkVector4D4D3& kPivotAW, const hkVector4D4D3& kPivotBW)
{
    hkpEntityD4D3* pkA = m_pEntityA;
    hkpEntityD4D3* pkB = m_pEntityB;
    m_kPivotInA.FUN_00c7f690(pkA->m_kMotionTransform, kPivotAW);
    m_kPivotInB.FUN_00c7f690(pkB->m_kMotionTransform, kPivotBW);
    hkVector4D4D3 kDiff;
    kDiff.setSub4(kPivotAW, kPivotBW);
    m_fSpringRestLength = kDiff.length3();
}

namespace fnv_00d4d410 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sqrt_ss(__m128 a);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkSimdRealD4D41
{
    __m128 m_vValue;

    hkSimdRealD4D41(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkTransformD4D41;

struct hkVector4D4D41
{
    __m128 m_vComponents;

    hkVector4D4D41()
    {}
    hkVector4D4D41(const hkVector4D4D41& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D4D41& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void FUN_00c7f640(const hkTransformD4D41& kT, const hkVector4D4D41& kV);
    void setSub4(const hkVector4D4D41& a, const hkVector4D4D41& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD4D41 length3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum));
    }
};

struct hkTransformD4D41
{
    hkVector4D4D41 m_rotation[3];
    hkVector4D4D41 m_vTranslation;
};

struct hkpEntityD4D41
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    hkTransformD4D41 m_kMotionTransform;
};

class hkBaseObjectD4D41
{
  public:
    virtual ~hkBaseObjectD4D41() throw();
};

class hkpStiffSpringWrapperD4D41 : public hkBaseObjectD4D41
{
  public:
    void SetPivots(const hkVector4D4D41& kPivotA, const hkVector4D4D41& kPivotB);

    unsigned int unk04, unk08, unk0C, unk10, unk14;
    hkpEntityD4D41* m_pEntityA;
    hkpEntityD4D41* m_pEntityB;
    unsigned int unk20, unk24, unk28, unk2C;
    hkVector4D4D41 m_kPivotInA;
    hkVector4D4D41 m_kPivotInB;
    float m_fSpringRestLength;
};

// Stores the given pivot vectors and computes the spring rest length from the world-space distance between the two pivots.
// @fnv 0x00d4d410
void hkpStiffSpringWrapperD4D41::SetPivots(const hkVector4D4D41& kPivotA, const hkVector4D4D41& kPivotB)
{
    hkpEntityD4D41* pkA = m_pEntityA;
    hkpEntityD4D41* pkB = m_pEntityB;
    m_kPivotInA = kPivotA;
    m_kPivotInB = kPivotB;
    hkVector4D4D41 kPivotAW;
    kPivotAW.FUN_00c7f640(pkA->m_kMotionTransform, kPivotA);
    hkVector4D4D41 kPivotBW;
    kPivotBW.FUN_00c7f640(pkB->m_kMotionTransform, kPivotB);
    hkVector4D4D41 kDiff;
    kDiff.setSub4(kPivotAW, kPivotBW);
    m_fSpringRestLength = kDiff.length3();
}
}  // namespace fnv_00d4d410

namespace fnv_00d4d4a0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4D4A0
{
    __m128 m_vComponents;

    void operator=(const hkVector4D4A0& value)
    {
        m_vComponents = value.m_vComponents;
    }
};

struct hkMemoryAllocatorD4A0
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterD4A0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkMemoryAllocatorD4A0* m_pStreamAllocator;

    hkMemoryAllocatorD4A0& heap() const
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterD4A0* __cdecl FUN_00c85750();

struct hkpEntityPairD4A0
{
    void* m_pEntityA;
    void* m_pEntityB;
};

struct hkpCloneArgD4A0
{
    hkpEntityPairD4A0* m_kActorEntries;
    int m_type;
};

struct S00d4d4a0_Obj
{
    static void* operator new(unsigned int size)
    {
        S00d4d4a0_Obj* memory = reinterpret_cast<S00d4d4a0_Obj*>(FUN_00c85750()->heap().AllocateMemoryBlock(size));
        memory->m_usMemSizeAndFlags = static_cast<unsigned short>(size);
        return memory;
    }

    S00d4d4a0_Obj* FUN_00d4d340(void* entityA, void* entityB, void* data);

    S00d4d4a0_Obj* FUN_00d4d4a0(const hkpCloneArgD4A0& argA, const hkpCloneArgD4A0& argB) const;

    unsigned int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* unk08;
    void* unk0C;
    void* m_ulUserData;
    void* unk14;
    void* m_pEntityA;
    void* m_pEntityB;
    hkVector4D4A0 m_kLastForce;
    hkVector4D4A0 m_kPivotInA;
    hkVector4D4A0 m_kPivotInB;
    float m_fRestLength;
    float m_fSpringStrength;
    float m_fMotorDamping;
    unsigned char m_bSpringEnabled;
    unsigned char m_bElastic;
    unsigned short unk5E;
};

// Returns null unless argA.m_type is 2 and argB.m_type is 0; else builds a copy on argA's entity pair and copies pivots, rest length, spring, damping and flags.
// @fnv 0x00d4d4a0
S00d4d4a0_Obj* S00d4d4a0_Obj::FUN_00d4d4a0(const hkpCloneArgD4A0& argA, const hkpCloneArgD4A0& argB) const
{
    if (argA.m_type != 2)
        return 0;

    if (argB.m_type != 0)
        return 0;

    S00d4d4a0_Obj* clone = new S00d4d4a0_Obj;

    clone = clone->FUN_00d4d340(argA.m_kActorEntries->m_pEntityA, argA.m_kActorEntries->m_pEntityB, m_ulUserData);

    clone->m_kPivotInA = m_kPivotInA;
    clone->m_kPivotInB = m_kPivotInB;
    clone->m_fRestLength = m_fRestLength;
    clone->m_fSpringStrength = m_fSpringStrength;
    clone->m_fMotorDamping = m_fMotorDamping;
    clone->m_bSpringEnabled = m_bSpringEnabled;
    clone->m_bElastic = m_bElastic;

    return clone;
}
}  // namespace fnv_00d4d4a0
