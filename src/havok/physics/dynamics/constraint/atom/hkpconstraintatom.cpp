
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

// @fnv 0x00d21ce0
void FUN_00d21ce0_cls::FUN_00d21ce0(void* data)
{
    m_pConstraintData = data;
    m_pBridge = (void*)0xd21cc0;
}

struct FUN_00d22090_cls
{
    int FUN_00d22090(void* a, void* b);
};

// Walks a linked list from self while the node's first ushort is at least 0x17, OR-ing each node's FUN_00d22090(a, b) result and returning it.
// @fnv 0x00d22120
int __cdecl FUN_00d22120(void* pNode, void* a, void* b)
{
    int result = 0;
    if (*(unsigned short*)pNode >= 0x17)
    {
        void* p = pNode;
        do
        {
            result |= ((FUN_00d22090_cls*)p)->FUN_00d22090(a, b);
            p = *(void**)((char*)p + 0x14);
        } while (*(unsigned short*)p >= 0x17);
    }
    return result;
}

// @fnv 0x00d21d00
void __stdcall FUN_00d21d00(int, int, int, int, int, int)
{}

struct FUN_00d21de0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    FUN_00d21de0_cls* __thiscall FUN_00d21de0(int a);
};

// @fnv 0x00d21de0
FUN_00d21de0_cls* FUN_00d21de0_cls::FUN_00d21de0(int a)
{
    if (a != 0)
    {
        unk0A = (unsigned char)((unk09 + unk08 + 5) * 4);
    }
    return this;
}

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

// Walks the atom chain while type >= 23, then subtracts the partial solver temps, results and schema size from info unless the atom type is 22 or 1.
// @fnv 0x00d22030
int ConstraintAtom::FUN_00d22030(ConstraintInfo* info)
{
    ConstraintAtom* atom = this;
    unsigned int count = 0;
    while (atom->type >= 23)
    {
        count = atom->count;
        atom = atom->next;
    }
    if (atom->type != 22 && atom->type != 1)
    {
        ConstraintInfo partialInfo;
        FUN_00d21a60(atom, count, &partialInfo);
        info->numSolverElemTemps -= partialInfo.numSolverElemTemps;
        info->numSolverResults -= partialInfo.numSolverResults;
        info->sizeOfSchemas -= partialInfo.sizeOfSchemas;
    }
    return 0;
}

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

// Scales the inverse inertia matrix and mass of two constraint inputs by m_kFactorA and m_kFactorB, handling isotropic and anisotropic cases.
// @fnv 0x00d21e00
void hkpMassChangerModifierConstraintAtomq::ScaleInverseInertia(const void* cp, hkpSimpleConstraintInfoInitInputq& inA,
                                                                void* velA, hkpSimpleConstraintInfoInitInputq& inB,
                                                                void* velB)
{
    hkVector4q factor = m_kFactorA;
    hkpSimpleConstraintInfoInitInputq* in = &inA;
    for (int i = 0; i < 2; i++)
    {
        in->m_vInverseInertiaAndMass.mul4(factor);
        if (factor(0) == factor(1) && factor(1) == factor(2))
        {
            in->m_kInverseInertiaMatrix.mul(factor.m_vComponents);
        }
        else
        {
            const hkMatrix3q& rot = *in->m_rotation;
            hkMatrix3q local;
            local.setTransposeMul(rot, in->m_kInverseInertiaMatrix);
            hkMatrix3q scaled;
            scaled.SetProduct(local, rot);
            scaled(0, 0) *= factor(0);
            scaled(1, 1) *= factor(1);
            scaled(2, 2) *= factor(2);
            local.SetInverseProduct(scaled, rot);
            in->m_kInverseInertiaMatrix.SetProduct(rot, local);
        }
        factor = m_kFactorB;
        in = &inB;
    }
}

namespace fnv_00d21f50 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkSimdRealD21F
{
    __m128 m_vValue;

    hkSimdRealD21F(const __m128& x) : m_vValue(x)
    {}
};

struct hkVector4D21F
{
    __m128 m_vComponents;

    hkSimdRealD21F dot3(const hkVector4D21F& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void subMul4(const hkSimdRealD21F& s, const hkVector4D21F& a)
    {
        m_vComponents =
            _mm_sub_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), a.m_vComponents));
    }
    void add4(const hkVector4D21F& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

struct hkContactPointD21F
{
    hkVector4D21F m_vContactPosition;
    hkVector4D21F m_vSeparatingNormal;
};

class hkpMovingSurfaceModifierConstraintAtomD21F
{
  public:
    void FUN_00d21f50(const hkContactPointD21F& kCp, void* pvA, void* pvB, void* pvC, hkVector4D21F& kVelOut);

    unsigned short m_type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkVector4D21F m_fVelocity;
};

// Subtracts a copy of m_fVelocity scaled by its dot product with the separating normal from that copy, and adds the result to kVelOut.
// @fnv 0x00d21f50
void hkpMovingSurfaceModifierConstraintAtomD21F::FUN_00d21f50(const hkContactPointD21F& kCp, void* pvA, void* pvB,
                                                              void* pvC, hkVector4D21F& kVelOut)
{
    hkVector4D21F kVel = m_fVelocity;
    kVel.subMul4(kCp.m_vSeparatingNormal.dot3(kVel), kVel);
    kVelOut.add4(kVel);
}
}  // namespace fnv_00d21f50

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

// @fnv 0x00d22090
int hkpModifierConstraintAtomD220::FUN_00d22090(hkpConstraintInfoD220& kInfo, unsigned char& ucUsedFlagsOut) const
{
    int iCallbackRequest = 0;
    switch (m_type)
    {
    case 0x19:
        ucUsedFlagsOut |= 0x10;
        break;
    case 0x17:
        ucUsedFlagsOut |= 8;
        break;
    case 0x18:
        kInfo.m_iSchemaByteSize += 0x50;
        ucUsedFlagsOut |= 1;
        break;
    case 0x1a:
        kInfo.m_iSchemaByteSize += 0x50;
        ucUsedFlagsOut |= 4;
        break;
    case 0x1b:
        iCallbackRequest = FUN_00d22030(kInfo);
        break;
    case 0x1c:
        kInfo.m_iSchemaByteSize += 0xd0;
        ucUsedFlagsOut |= 2;
        break;
    }
    return iCallbackRequest;
}

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

// @fnv 0x00d22160
void ComChangerAtom::FUN_00d22160(const void* cp, InitInput& inA, BodyVelocity& velA, InitInput& inB,
                                  BodyVelocity& velB)
{
    Vec4 vRotatedDisplacementA;
    SetRotatedDirection(vRotatedDisplacementA, inA.m_kMotionTransform->m_rotation, m_kDisplacementA);
    Vec4 vRotatedDisplacementB;
    SetRotatedDirection(vRotatedDisplacementB, inB.m_kMotionTransform->m_rotation, m_kDisplacementB);
    inA.m_kFirstVector.sub4(vRotatedDisplacementA);
    inB.m_kFirstVector.sub4(vRotatedDisplacementB);
    __m128 vAngularCorrectionA = crossq(vRotatedDisplacementA.m_vComponents, velA.m_kAngularVelocity.m_vComponents);
    __m128 vAngularCorrectionB = crossq(vRotatedDisplacementB.m_vComponents, velB.m_kAngularVelocity.m_vComponents);
    velA.m_kTranslationalVelocity.m_vComponents =
        _mm_sub_ps(velA.m_kTranslationalVelocity.m_vComponents, vAngularCorrectionA);
    velB.m_kTranslationalVelocity.m_vComponents =
        _mm_sub_ps(velB.m_kTranslationalVelocity.m_vComponents, vAngularCorrectionB);
}

extern __m128 DAT_012689a0;
extern __m128 DAT_012689b0;
extern __m128 DAT_012689c0;
extern __m128 DAT_012689d0;

// Copies two pairs of __m128 values from source1 and source2 into the global DAT_012689a0 through DAT_012689d0.
// @fnv 0x00d21f10
void __stdcall SetGlobalVectors(int, int, const __m128* source1, int, const __m128* source2)
{
    DAT_012689a0 = source1[0];
    DAT_012689b0 = source1[1];
    DAT_012689c0 = source2[0];
    DAT_012689d0 = source2[1];
}

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
// Computes d = dot3(a[1], m_uiValueCount), then subtracts (m_uiValueCount - d * m_uiValueCount) from the vector at out.
// @fnv 0x00d21fc0
void __thiscall Cls_00d21fc0::FUN_00d21fc0(__m128* a, int b, int c, int d, int e, int out)
{
    __declspec(align(16)) FUN_00d21fc0_n n = m_uiValueCount;
    __m128 nv = _mm_load_ps(&n.x);
    __m128 p = _mm_mul_ps(a[1], nv);
    int iOut = *(volatile int*)&out;
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    __m128 t = _mm_sub_ps(nv, _mm_mul_ps(_mm_shuffle_ps(r, r, 0), nv));
    __m128* pOut = (__m128*)iOut;
    *pOut = _mm_sub_ps(*pOut, t);
}
