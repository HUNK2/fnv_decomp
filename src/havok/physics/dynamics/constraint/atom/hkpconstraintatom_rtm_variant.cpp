
// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpConstraintAtom.h"
struct FUN_00d21ce0_cls
{
    void* m_base;
    void* m_pBridge;
    void* m_pConstraintData;
    void FUN_00d21ce0(void* data);
};
struct FUN_00d22090_cls
{
    int FUN_00d22090(void* a, void* b);
};
int __cdecl FUN_00d22120(void* pNode, void* a, void* b);
void __stdcall FUN_00d21d00(int, int, int, int, int, int);
struct FUN_00d21de0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    FUN_00d21de0_cls* __thiscall FUN_00d21de0(int a);
};
struct ConstraintAtom;
struct ConstraintInfo
{
    int maxSizeOfSchema;
    int sizeOfSchemas;
    int numSolverResults;
    int numSolverElemTemps;
    ConstraintAtom* atoms;
    unsigned int sizeOfAllAtoms;
};
struct ConstraintAtom
{
    unsigned short type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short count;
    ConstraintAtom* next;
    int FUN_00d22030(ConstraintInfo* info);
};
void __cdecl FUN_00d21a60(ConstraintAtom* atom, unsigned int count, ConstraintInfo* result);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void mul4(const hkVector4q& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};
struct hkSimdRealq
{
    __m128 m_vValue;

    __forceinline hkSimdRealq(const __m128& q)
    {
        m_vValue = q;
    }
};
struct hkMatrix3q
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }

    void setTransposeMul(const hkMatrix3q& a, const hkMatrix3q& b);
    void SetProduct(const hkMatrix3q& a, const hkMatrix3q& b);
    void SetInverseProduct(const hkMatrix3q& a, const hkMatrix3q& b);
    void mul(const hkSimdRealq& scale);
};
struct hkpSimpleConstraintInfoInitInputq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3q m_kInverseInertiaMatrix;
    hkVector4q m_vInverseInertiaAndMass;
    const hkMatrix3q* m_rotation;
};
class hkpMassChangerModifierConstraintAtomq
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
    hkVector4q m_kFactorA;
    hkVector4q m_kFactorB;

    void ScaleInverseInertia(const void* cp, hkpSimpleConstraintInfoInitInputq& inA, void* velA,
                             hkpSimpleConstraintInfoInitInputq& inB, void* velB);
};
struct hkpConstraintInfoD220
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
};
class hkpModifierConstraintAtomD220
{
  public:
    unsigned short m_type;

    int FUN_00d22030(hkpConstraintInfoD220& kInfo) const;
    int FUN_00d22090(hkpConstraintInfoD220& kInfo, unsigned char& ucUsedFlagsOut) const;
};
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int c);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
struct Vec4
{
    __m128 m_vComponents;

    __forceinline void sub4(const Vec4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xC9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xD2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xD2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xC9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};
struct Mat3
{
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
};
struct Transform
{
    Mat3 m_rotation;
    Vec4 m_vTranslation;
};
static __forceinline void SetRotatedDirection(Vec4& out, const Mat3& a, const Vec4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xAA);
    const __m128 r1 = _mm_mul_ps(b1, a.m_kColumn1.m_vComponents);
    const __m128 r0 = _mm_mul_ps(b0, a.m_kColumn0.m_vComponents);
    const __m128 r2 = _mm_mul_ps(b2, a.m_kColumn2.m_vComponents);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}
static __forceinline __m128 crossq(const __m128& v1, const __m128& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xC9), _mm_shuffle_ps(v2, v2, 0xD2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xD2), _mm_shuffle_ps(v2, v2, 0xC9));
    return _mm_sub_ps(cross0, cross1);
}
struct InitInput
{
    Vec4 m_kFirstVector;
    Mat3 m_kInverseInertiaMatrix;
    Vec4 m_vInverseInertiaAndMass;
    const Transform* m_kMotionTransform;
};
struct BodyVelocity
{
    Vec4 m_kTranslationalVelocity;
    Vec4 m_kAngularVelocity;
};
struct ComChangerAtom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kDisplacementA;
    Vec4 m_kDisplacementB;

    void FUN_00d22160(const void* cp, InitInput& inA, BodyVelocity& velA, InitInput& inB, BodyVelocity& velB);
};
extern __m128 DAT_012689a0;
extern __m128 DAT_012689b0;
extern __m128 DAT_012689c0;
extern __m128 DAT_012689d0;
void __stdcall SetGlobalVectors(int, int, const __m128* source1, int, const __m128* source2);
extern "C" __m128 _mm_load_ps(float const* p);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
struct FUN_00d21fc0_n
{
    float x, y, z, w;
};
struct Cls_00d21fc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d21fc0_n m_uiValueCount;
    void __thiscall FUN_00d21fc0(__m128* a, int b, int c, int d, int e, int out);
};

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ss(float const* a);
extern "C" __m128 _mm_set1_ps(float a);
extern "C" __m128 _mm_move_ss(__m128 a, __m128 b);
extern __m128 DAT_010ec7f0;
extern __m128 DAT_012689a0;
extern __m128 DAT_012689b0;
extern __m128 DAT_012689c0;
extern __m128 DAT_012689d0;
static inline __m128 Blend_d21d10(const __m128& v, const __m128& kRef, const float& t)
{
    __m128 s = _mm_load_ss(&t);
    s = _mm_shuffle_ps(s, s, 0);
    return _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, s), kRef), _mm_mul_ps(v, s));
}
struct SoftContactVelocityBlend
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fWeight;
    void FUN_00d21d10(int a1, int a2, int a3, __m128* pkA, int a5, __m128* pkB);
};
// @fnv 0x00d21d10
void SoftContactVelocityBlend::FUN_00d21d10(int a1, int a2, int a3, __m128* pkA, int a5, __m128* pkB)
{
    float t = m_fWeight;
    pkA[0] = Blend_d21d10(pkA[0], DAT_012689a0, t);
    pkA[1] = Blend_d21d10(pkA[1], DAT_012689b0, t);
    pkB[0] = Blend_d21d10(pkB[0], DAT_012689c0, t);
    pkB[1] = Blend_d21d10(pkB[1], DAT_012689d0, t);
}
