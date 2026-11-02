
// src/havok/common/base/math/vector/hkvector4_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/vector/hkvector4.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/vector/hkvector4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/vector/hkvector4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// CheckFloatsFinite (0x00c7f4e0, 21 bytes)
//
// The original is a __thiscall member of a class whose object *is* the float
// array.  It forwards to a file-static helper FUN_00c7f4a0(out, self, count).
//
// MSVC 2008 gives an internal-linkage (file-static) helper its own internal
// "register argument" convention: instead of pushing the arguments on the
// stack they are passed in registers.  With the helper declared as
//     static void* FUN_00c7f4a0(void* out, void* self, int count)
// MSVC 2008 assigns  out->EAX, self->ESI, count->EDX  and the call site
// becomes exactly
//     mov eax,[esp+4] / push esi / mov edx,3 / mov esi,ecx / call / pop esi / ret 4
// The helper returns its first argument, which is what pins that argument
// to EAX; the parameter order (out, self, count) is what makes the call site
// materialise EDX before ESI.
struct Cls_c7f4e0
{
    float unk00[8];
    void CheckFloatsFinite(void* out);
};
static __declspec(noinline) void* FUN_00c7f4a0(void* out, void* self, int count)
{
    for (int i = 0; i < count; i++)
    {
        float v = ((float*)self)[i];
        int bits = *(int*)&v;
        if ((bits & 0x7f800000) == 0x7f800000)
        {
            *(char*)out = 0;
            return out;
        }
    }
    *(char*)out = 1;
    return out;
}

#include <xmmintrin.h>
#include <math.h>
extern "C" double fabs(double x);
extern const double DAT_01012070;

struct hkBool_c7f5
{
    char m_cBooleanValue;
    hkBool_c7f5()
    {}
    hkBool_c7f5(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkVector4_c7f5
{
  public:
    __m128 m_vComponents;
    hkBool_c7f5 CheckFloatsFinite() const;
    hkBool_c7f5 FUN_00c7f520(float eps) const;
};

// @fnv 0x00c7f520
hkBool_c7f5 hkVector4_c7f5::FUN_00c7f520(float eps) const
{
    if (CheckFloatsFinite())
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), len);
        float lenSq;
        _mm_store_ss(&lenSq, len);
        float lenZero = (float)(lenSq - DAT_01012070);
        return (float)fabs(lenZero) < eps;
    }
    return false;
}

extern "C" double fabs(double x);
extern const double DAT_01012070;

struct hkBool_c7f5b
{
    char m_cBooleanValue;
    hkBool_c7f5b()
    {}
    hkBool_c7f5b(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkVector4_c7f5b
{
  public:
    __m128 m_vComponents;
    hkBool_c7f5b FUN_00c7f500() const;
    hkBool_c7f5b FUN_00c7f5b0(float eps) const;
};

// @fnv 0x00c7f5b0
hkBool_c7f5b hkVector4_c7f5b::FUN_00c7f5b0(float eps) const
{
    if (FUN_00c7f500())
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 sum = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
        __m128 len = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
        float lenSq;
        _mm_store_ss(&lenSq, len);
        float lenZero = (float)(lenSq - DAT_01012070);
        return (float)fabs(lenZero) < eps;
    }
    return false;
}
