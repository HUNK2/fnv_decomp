
// src/staging/blk_00e20000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct ConvexShapeStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void GetSupportingVertex(const __m128* dir, __m128* out);
};

struct SupportResult
{
    __m128 pointA;
    __m128 pointB;
    __m128 normal;
};

struct TransformStub
{
    __m128 col0;
    __m128 col1;
    __m128 col2;
    __m128 translation;
};

static const __m128 kNegMask = {-0.0f, -0.0f, -0.0f, -0.0f};

// @fnv 0x00e2da40
static void FUN_00e2da40(ConvexShapeStub* self, ConvexShapeStub* other, SupportResult* result, const __m128* dir,
                         const TransformStub* xf)
{
    __m128 negDir = _mm_xor_ps(*dir, kNegMask);
    __m128 a;
    self->GetSupportingVertex(&negDir, &a);
    __m128 c0 = xf->col0;
    __m128 c2 = xf->col2;
    __m128 c1 = xf->col1;
    {
        __m128 tmp = _mm_unpacklo_ps(c0, c1);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = ctmp;
    }
    __m128 localDir = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*dir, *dir, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(*dir, *dir, 0x00), c0)),
        _mm_mul_ps(_mm_shuffle_ps(*dir, *dir, 0xaa), c2));
    __m128 b;
    other->GetSupportingVertex(&localDir, &b);
    __m128 bw = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0x55), xf->col1), _mm_mul_ps(_mm_shuffle_ps(b, b, 0x00), xf->col0)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xaa), xf->col2), xf->translation));
    __m128 d = _mm_mul_ps(_mm_sub_ps(a, bw), *dir);
    float dist;
    _mm_store_ss(&dist, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d)));
    float* w = (float*)&result->normal;
    if (dist > w[3])
    {
        result->normal = *dir;
        result->pointA = a;
        result->pointB = b;
        w[3] = dist;
    }
}

void CallerOfIt(ConvexShapeStub* s, ConvexShapeStub* o, SupportResult* r, const __m128* d, const TransformStub* x)
{
    FUN_00e2da40(s, o, r, d, x);
    FUN_00e2da40(o, s, r, d + 1, x);
    FUN_00e2da40(s, s, r, d + 2, x);
}

// @fnv 0x00e31180
void FUN_00e31180(const float* base, int stride, int count, int mul, int offset, __m128** dst)
{
    for (int i = 0; i < count; i++)
        (*dst)[i] = _mm_setr_ps(base[(stride * mul + offset) + i * stride], 0.0f, 0.0f, 0.0f);
}

class __declspec(align(16)) hkVector4E3B
{
  public:
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }

    __m128 m_vComponents;
};

class hkRotationE3B
{
  public:
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }

    hkVector4E3B m_kColumn0;
    hkVector4E3B m_kColumn1;
    hkVector4E3B m_kColumn2;
};

class ChildE3B
{
  public:
    void FUN_00cb2d90(const void* pSource);
};

class FrameE3B
{
  public:
    void FUN_00e3b630(const void* pSource);

    int m_unk[8];
    hkRotationE3B m_rotation;
    ChildE3B m_pChildAtom;
};

// @fnv 0x00e3b630
void FrameE3B::FUN_00e3b630(const void* pSource)
{
    m_rotation.setIdentity();
    m_pChildAtom.FUN_00cb2d90(pSource);
}
