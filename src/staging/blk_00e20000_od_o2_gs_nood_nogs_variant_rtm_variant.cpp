
// src/staging/blk_00e20000_od_o2_gs_nood_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e20000_od_o2_gs_nood_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

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
static void FUN_00e2da40(ConvexShapeStub* self, ConvexShapeStub* other, SupportResult* result, const __m128* dir,
                         const TransformStub* xf);
void CallerOfIt(ConvexShapeStub* s, ConvexShapeStub* o, SupportResult* r, const __m128* d, const TransformStub* x);
void FUN_00e31180(const float* base, int stride, int count, int mul, int offset, __m128** dst);
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

struct hkVector4E33
{
    __m128 m_vComponents;
};

__forceinline float ReadScalar(const float& x)
{
    return x;
}
// @fnv 0x00e33440
void __cdecl FUN_00e33440(float u, int iDegree, const float* pfKnots, const hkVector4E33* pkControlPoints,
                          hkVector4E33& kOut)
{
    float N[4];
    float right[4];
    float left[4];

    float* negativeOffsets = left;
    N[0] = 1.0f;
    int iSpan = iDegree - 1;
    for (int j = 1; j <= iDegree; j++)
    {
        left[j] = u - pfKnots[iSpan + 1 - j];
        right[j] = pfKnots[iSpan + j] - u;
        float saved = 0.0f;
        for (int r = 0; r < j; r++)
        {
            float temp = ReadScalar(N[r]) / (right[r + 1] + ReadScalar(negativeOffsets[j - r]));
            N[r] = saved + right[r + 1] * temp;
            saved = ReadScalar(negativeOffsets[j - r]) * temp;
        }
        N[j] = saved;
    }

    __m128 sum = _mm_setzero_ps();
    for (int i = 0; i <= iDegree; i++)
    {
        __m128 w = _mm_load_ss(&N[i]);
        sum = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(w, w, 0), pkControlPoints[i].m_vComponents), sum);
    }
    kOut.m_vComponents = sum;
}
