
// src/havok/physics/constraintsolver/solve/hkpsolver_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/havok/physics/constraintsolver/solve/hkpsolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/solve/hkpsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/solve/hkpsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern unsigned char DAT_011b9434[128];
int __cdecl FUN_00d921d0(const signed char* index);
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
// @fnv 0x00c6cce0
extern "C" void __cdecl AddScalarFloat(__m128* out, const __m128* a, const __m128* b)
{
    *out = _mm_add_ss(*a, *b);
}

// @fnv 0x00d921c0
char* __cdecl FUN_00d921c0(char* dst, const char* src)
{
    *dst = *src;
    return dst;
}

extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
// @fnv 0x00c6ccc0
extern "C" void __cdecl SubtractScalarFloat(__m128* out, const __m128* a, const __m128* b)
{
    *out = _mm_sub_ss(*a, *b);
}

extern "C" __m128 _mm_mul_ss(__m128 a, __m128 b);

struct Vec4Src
{
    __m128* GetVec();
};

struct Vec4Dst
{
    void SetVec(const __m128& v);
};

// @fnv 0x00891060
Vec4Dst* __cdecl FUN_00891060(Vec4Dst* out, Vec4Src* b, Vec4Src* a)
{
    out->SetVec(_mm_mul_ss(*b->GetVec(), *a->GetVec()));
    return out;
}
