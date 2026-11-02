
// src/staging/blk_00e40000_od_o2_nood_variant_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e40000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct FloatLess
{
    bool operator()(const float& a, const float& b) const
    {
        return a < b;
    }
};
void __cdecl FUN_00e50f10(float* pArr, int d, int h, FloatLess cmpLess);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" int _mm_movemask_ps(__m128);
static inline __m128 Dot3v(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
static inline __m128 Dot3_e4b570(__m128 p)
{
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
int __cdecl FUN_00e4b570(const __m128* point, const __m128* verts, float* out);

extern "C" double __cdecl sqrt(double);

extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" void _mm_store_ps(float*, __m128);

struct Quaternion81
{
    float x, y, z, w;
};
// @fnv 0x00e52590
void __cdecl FUN_00e52590(const Quaternion81* quaternion, unsigned char* packed)
{
    static float scale = static_cast<float>(sqrt(2.0)) * 2047.0;
    const float* components = &quaternion->x;
    __declspec(align(16)) static const unsigned int absMask[4] = {0x7fffffffu, 0x7fffffffu, 0x7fffffffu, 0x7fffffffu};
    __declspec(align(16)) float abs[4];
    _mm_store_ps(abs,
                 _mm_and_ps(*reinterpret_cast<const __m128*>(quaternion), *reinterpret_cast<const __m128*>(absMask)));
    unsigned int largest = 0;
    if (abs[1] > abs[0])
        largest = 1;
    if (abs[2] > abs[largest])
        largest = 2;
    if (abs[3] > abs[largest])
        largest = 3;
    unsigned int lane = largest == 0;
    short quantized[3];
    quantized[0] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    ++lane;
    lane += lane == largest;
    quantized[1] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    ++lane;
    lane += lane == largest;
    quantized[2] = static_cast<short>(static_cast<unsigned int>(components[lane] * scale) + 2047);
    packed[0] = static_cast<unsigned char>(quantized[0]);
    packed[1] = static_cast<unsigned char>((quantized[0] >> 8) | (quantized[1] << 4));
    packed[2] = static_cast<unsigned char>(quantized[1] >> 4);
    packed[3] = static_cast<unsigned char>(quantized[2]);
    unsigned int negative = components[largest] < 0.0f;
    packed[4] = static_cast<unsigned char>(((largest | (negative << 2)) << 4) | (quantized[2] >> 8));
}
