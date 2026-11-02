
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSphereMotion.h"
struct hkVector4D12
{
    float x, y, z, w;
};
struct hkMatrix3D12
{
    hkVector4D12 m_kColumn0;
    hkVector4D12 m_kColumn1;
    hkVector4D12 m_kColumn2;
};
template <class T> inline T hkMax2D12(T x, T y)
{
    return x > y ? x : y;
}
class hkpSphereMotionD12
{
  public:
    virtual ~hkpSphereMotionD12();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D12 m_kMotionState[11];
    hkVector4D12 m_kInertiaAndMassInv;

    void FUN_00d1e290(const hkMatrix3D12& inertia);
};
class hkpSphereMotion_L : public hkpMotion
{
  public:
    void SetInertiaAndMassInv(const float* param_2);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
struct hkVector4D1E41
{
    __m128 m_vComponents;

    __m128 getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    void setMul4(const __m128& s, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents);
    }
    void setMul4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E41& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void setCross(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};
class hkBaseObjectD1E41
{
  public:
    virtual ~hkBaseObjectD1E41() throw();
};
class hkReferencedObjectD1E41 : public hkBaseObjectD1E41
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpSphereMotionD1E41 : public hkReferencedObjectD1E41
{
  public:
    void ApplyImpulse(const hkVector4D1E41& kImpulse, const hkVector4D1E41& kPos);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E41 m_motionState0[5];
    hkVector4D1E41 m_kCenterOfMass1;
    hkVector4D1E41 m_motionState1[5];
    hkVector4D1E41 m_kInertiaAndMassInv;
    hkVector4D1E41 m_kTranslationalVelocity;
    hkVector4D1E41 m_kAngularVelocity;
};
class hkVector4D1E4
{
  public:
    __m128 m_vComponents;
    void setMul4(const hkVector4D1E4& a, const hkVector4D1E4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};
class hkpSphereMotionD1E4
{
  public:
    virtual ~hkpSphereMotionD1E4();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_deactivationNumInactiveFrames0;
    unsigned short m_deactivationNumInactiveFrames1;
    unsigned short m_pad0e;
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    hkVector4D1E4 m_kInertiaAndMassInv;
    hkVector4D1E4 m_kTranslationalVelocity;
    hkVector4D1E4 m_kAngularVelocity;
    const hkVector4D1E4& AddAngularImpulse(const hkVector4D1E4& imp);
};

extern "C" __m128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float* p, __m128 v);
extern const double DAT_010c9300;
extern float DAT_0104da4c;
struct C
{
    char pad[0xc0];
    float m_vScale;
    void FUN_00d1e230(float* out);
};
// @fnv 0x00d1e230
void C::FUN_00d1e230(float* out)
{
    float t = m_vScale;
    float s;
    if (DAT_010c9300 > t)
        s = DAT_0104da4c;
    else
        s = t;
    float inv = 1.0f / s;
    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(out, zero);
    _mm_store_ps(out + 4, zero);
    _mm_store_ps(out + 8, zero);
    out[0] = inv;
    out[5] = inv;
    out[10] = inv;
}
