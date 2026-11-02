
// src/havok/common/base/math/quaternion/hkquaternion_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/quaternion/hkquaternion.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/quaternion/hkquaternion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/quaternion/hkquaternion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
/* PACKET-DECLARATIONS IS PROVIDED BY THE CHECKER; DO NOT INCLUDE IT IN YOUR SUBMISSION.
   Only submit the TARGET definition and any genuinely missing declarations that are required
   for compilation. Do not write or repeat packet-declarations, nor any headers that might
   be present in the checker's context. */
class FUN_005611c0_t
{
  public:
    void FUN_005611c0();
    void FUN_00cb2830(float* pts);
};
static float g_sink2550;
extern "C" double cb2550_clobber(double x);
static __declspec(noinline) void FUN_00cb2550(FUN_005611c0_t* obj, float* pts)
{
    float s = pts[0] * pts[1];
    s = (float)cb2550_clobber(s);
    s += pts[5];
    g_sink2550 = s;
    if (s > 1.0e9f)
        *(int*)obj = 0;
}
#include <xmmintrin.h>
#include <math.h>
struct FUN_00cb24c0_cls
{
    __m128 m_00;
    void FUN_00c7f500(unsigned char* flag);
    unsigned char* IsNormalized(unsigned char* flag);
};
struct Block64
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
    __m128 v3;
};
struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    void CallSub(Block64* p);
};
__declspec(align(16)) struct FUN_00cf5950_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    SubObj m_sub;
    Block64 m_block;

    void CopyBlock(Block64* src);
};
struct S00cb2550_V4
{
    union
    {
        __m128 q;
        float v[4];
    };
};
struct S00cb2550_Rot
{
    float m[3][4];
    float operator()(int r, int c) const
    {
        return m[c][r];
    }
};
struct S00cb2550_Quat
{
    S00cb2550_V4 q;
};
static void FUN_00cb2550(S00cb2550_Quat* self, const S00cb2550_Rot& r);
void S00cb2550_caller(S00cb2550_Quat* q, const S00cb2550_Rot& r);

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00cb2700 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};
extern "C"
{
    __m128 _mm_setzero_ps();
    void _mm_store_ps(float*, __m128);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}

union VecStorage
{
    __m128 quad;
    float axis[4];
};

struct PerpendicularVector
{
    __m128 m_result;

    void FUN_00cb2700(const float* v);
};

extern "C" double fabs(double);
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern "C" void _ReadWriteBarrier();

static __forceinline __m128 inverse_length(__m128 t)
{
    __m128 mask = _mm_cmpeq_ss(t, _mm_set_ss(0.0f));
    __m128 inv = _mm_rsqrt_ss(t);
    __m128 xi = _mm_mul_ss(_mm_mul_ss(t, inv), inv);
    __m128 yy = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inv), _mm_sub_ss(_mm_set_ss(DAT_01017718), xi));
    return _mm_andnot_ps(mask, yy);
}

// @fnv 0x00cb2700
void PerpendicularVector::FUN_00cb2700(const float* v)
{
    VecStorage w;
    float a;
    float b;
    float c;
    int i0 = 0;
    int i1 = i0 + 1;
    int i2 = i0 + 2;

    {
        volatile float rounded = (float)fabs((double)v[0]);
        a = rounded;
    }
    {
        volatile float rounded = (float)fabs((double)v[1]);
        b = rounded;
    }
    {
        volatile float rounded = (float)fabs((double)v[2]);
        c = rounded;
    }

    if (b < a)
    {
        a = b;
        i1 = 0;
        i0 = i2 - 1;
    }
    if (c < a)
    {
        i2 = i0;
    }

    w.quad = _mm_setzero_ps();
    w.axis[i1] = v[i2];
    w.axis[i2] = -v[i1];

    float zz = 0.0f;
    __m128 sq = _mm_mul_ps(w.quad, w.quad);
    __m128 p1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 p2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 t = _mm_add_ss(p1, sq);
    t = _mm_add_ss(p2, t);

    __m128 s = inverse_length(t);

    __m128 sv = _mm_shuffle_ps(s, s, 0);
    __m128 r = _mm_mul_ps(sv, w.quad);
    r.m128_f32[3] = zz;
    m_result = r;
}
}  // namespace fnv_00cb2700
