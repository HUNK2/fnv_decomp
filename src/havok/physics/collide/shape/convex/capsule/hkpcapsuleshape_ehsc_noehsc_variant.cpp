// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpCapsuleShape.h"
extern char const* const g_01268970_arg1;
void __cdecl FUN_00c90360(char const* const* arg1, char const* const* arg2);
void __cdecl FUN_00d22360(char const* const* arg1, char const* const* arg2);
int __cdecl hkpCapsuleShape_getNumCollisionSpheresImpl();
int __stdcall FUN_00d22d60(int a, int b);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, __m128 v);
class FUN_00d223f0_cls
{
  public:
    void GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out);
};
struct __declspec(align(16)) hkVector4D224
{
    __m128 m_vComponents;

    hkVector4D224()
    {}
    hkVector4D224(const hkVector4D224& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
class FUN_00d22480_cls
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
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4D224 m_vector;

    hkVector4D224 FUN_00d22480() const;
};
struct FUN_00d224a0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 unk20;
    __m128 unk30;

    void __thiscall hkpCapsuleShape_getCollisionSpheresImpl(__m128* result);
};
extern int DAT_010ce25c;
union __declspec(align(16)) AlignedHKVector4
{
    __m128 simd;
    struct
    {
        float x, y, z, w;
    };
};
struct FUN_00d22590_Class : hkpCapsuleShape
{
    FUN_00d22590_Class* __thiscall FUN_00d22590(const AlignedHKVector4& first, const AlignedHKVector4& second,
                                                float radius);
};
struct __declspec(align(16)) Point4
{
    float x, y, z, w;
};
struct ClosestLineResult
{
    float distance;
    float fractionA;
    float fractionB;
    float extraValue;
    Point4 pointA;
    Point4 pointB;
};
void __cdecl FUN_00d231b0(const Point4& a, const Point4& b, const Point4& c, const Point4& d, ClosestLineResult* out);
void __cdecl GetClosestLinePoints(const Point4& aLineAStart, const Point4& aLineAEnd, const Point4& aLineBStart,
                                  const Point4& aLineBEnd, float* pfDistance, float* pfFractionA, float* pfFractionB,
                                  Point4* pointA, Point4* pointB);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern float DAT_01016248;
class Aabb_d22440
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
    __m128 m_kMin;
    __m128 m_kMax;

    void __thiscall FUN_00d22440(__m128* pkCenter) const;
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);
void __cdecl FUN_00d224c0(float* arg1, float* arg2, float* arg3, float* out);
