
// src/staging/blk_00d20000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct FourFloatVector
{
    float x, y, z, w;
};
union AlignedVector
{
    FourFloatVector value;
    __m128 simd;
};
struct Transform4
{
    FourFloatVector x, y, z, translation;
};
struct ShapeGeometry
{
    void* vtable;
    int userData;
    int type;
    int flags;
    float radius;
    float welding;
    int material;
    int extra;
    __m128 vertices[3];
};
struct CollisionBody
{
    ShapeGeometry* shape;
    int key;
    Transform4* transform;
};
struct BodyPair
{
    CollisionBody* a;
    CollisionBody* b;
};
struct QueryInput
{
    int flags;
    int mode;
    FourFloatVector direction;
};
struct ContactResult
{
    __m128 normal;
    FourFloatVector first;
    __m128 firstAux;
    FourFloatVector second;
    __m128 secondAux;
    __m128 extra;
};
extern float DAT_0104da48;
void __cdecl FUN_00cd6520(const __m128*, float, const __m128*, float, const FourFloatVector*, float, int,
                          ContactResult*, void*);

// @fnv 0x00d39150
void __cdecl FUN_00d39150(BodyPair* bodies, void* unused, QueryInput* input, __m128* output)
{
    ShapeGeometry* shapeA = bodies->a->shape;
    CollisionBody* bodyB = bodies->b;
    ShapeGeometry* shapeB = bodyB->shape;
    __m128 pointsA[2];
    __m128 pointsB[3];
    ContactResult result;
    {
        Transform4* transform = bodies->a->transform;
        AlignedVector axisX;
        axisX.value = transform->x;
        AlignedVector axisY;
        axisY.value = transform->y;
        AlignedVector axisZ;
        axisZ.value = transform->z;
        AlignedVector translation;
        translation.value = transform->translation;
        int i = 1;
        do
        {
            __m128 p = shapeA->vertices[i];
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 x = _mm_shuffle_ps(p, p, 0);
            x = _mm_mul_ps(x, axisX.simd);
            y = _mm_mul_ps(y, axisY.simd);
            y = _mm_add_ps(y, x);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            z = _mm_mul_ps(z, axisZ.simd);
            z = _mm_add_ps(z, translation.simd);
            pointsA[i] = _mm_add_ps(y, z);
        } while (--i >= 0);
    }
    {
        Transform4* transform = bodyB->transform;
        AlignedVector axisX;
        axisX.value = transform->x;
        AlignedVector axisY;
        axisY.value = transform->y;
        AlignedVector axisZ;
        axisZ.value = transform->z;
        AlignedVector translation;
        translation.value = transform->translation;
        int i = 2;
        do
        {
            __m128 p = shapeB->vertices[i];
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 x = _mm_shuffle_ps(p, p, 0);
            x = _mm_mul_ps(x, axisX.simd);
            y = _mm_mul_ps(y, axisY.simd);
            y = _mm_add_ps(y, x);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            z = _mm_mul_ps(z, axisZ.simd);
            z = _mm_add_ps(z, translation.simd);
            pointsB[i] = _mm_add_ps(y, z);
        } while (--i >= 0);
    }
    FUN_00cd6520(pointsA, shapeA->radius, pointsB, shapeB->radius, &input->direction, DAT_0104da48, 0, &result, 0);
    if (result.first.w < result.second.w)
        *output = *reinterpret_cast<__m128*>(&result.first);
    else
        *output = *reinterpret_cast<__m128*>(&result.second);
}
