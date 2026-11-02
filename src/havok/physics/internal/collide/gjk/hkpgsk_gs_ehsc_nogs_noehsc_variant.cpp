
// src/havok/physics/internal/collide/gjk/hkpgsk_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/hkpgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/hkpgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/hkpgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Entry
{
    char pad[12];
    unsigned short val;
    char pad2[2];
};
struct Dest
{
    unsigned short words[4];
    unsigned char count1;
    unsigned char count2;
};
struct ThisClass
{
    int count1;
    int count2;
    char pad[0x18];
    Entry entries1[3];
    char pad2[0x90];
    Entry entries2[3];

    void FUN_00da9790(Dest* out);
};

#include <xmmintrin.h>
struct PlainVector
{
    float x, y, z, w;
};

struct Vector
{
    __m128 quad;
    Vector()
    {}
    Vector& operator=(const Vector& v)
    {
        quad = v.quad;
        return *this;
    }
};

struct SolverOutput
{
    Vector normal;
    Vector point;
    float distance;
};

struct Transform
{
    PlainVector x, y, z, translation;
};

extern const float runtimeFloatSettingDefault726;

int __cdecl TestPenetration(void*, void*, const Transform*, float, Vector*, Vector*, Vector*, int, SolverOutput*);

void __cdecl FUN_00d22e40(Vector*, Vector*, Vector*, Vector*, Vector*);

struct Simplex
{

    int countA, countB, unk08, unk0c, unk10, status, unk18, unk1c;

    Vector a[4];

    Vector unk60, unk70, unk80, unk90;

    Vector verticesB[8];

    Vector result, axis;

    void FUN_00da98f0();

    void FUN_00daa7e0(void*, void*, const Transform*);
};

static __forceinline Vector copyVector(const PlainVector& p)
{
    Vector v;
    reinterpret_cast<PlainVector&>(v.quad) = p;
    return v;
}

// @fnv 0x00daa7e0
void Simplex::FUN_00daa7e0(void* arg1, void* arg2, const Transform* transform)
{

    int count = 4;

    if (countB >= 3)
    {

        if (countB > 3)
            a[3] = a[0];

        else if (countA > 1)
        {
            a[3] = a[1];
            verticesB[4 + 3] = verticesB[4 + 0];
            verticesB[3] = verticesB[0];
        }

        else
            count = 3;

        a[1] = a[0];
        a[2] = a[0];
    }
    else if (countA >= 3)
    {

        if (countA > 3)
        {
            verticesB[4 + 3] = verticesB[4 + 0];
            verticesB[3] = verticesB[0];
        }

        else if (countB > 1)
        {
            a[3] = a[0];
            verticesB[4 + 3] = verticesB[4 + 1];
            verticesB[3] = verticesB[1];
        }

        else
            count = 3;

        verticesB[4 + 1] = verticesB[4 + 0];
        verticesB[1] = verticesB[0];
        verticesB[4 + 2] = verticesB[4 + 0];
        verticesB[2] = verticesB[0];
    }
    else
    {

        Vector v = copyVector(reinterpret_cast<const PlainVector&>(a[0].quad));
        a[countA] = v;
        a[countA + 1] = v;

        v = copyVector(reinterpret_cast<const PlainVector&>(verticesB[4 + 0].quad));
        verticesB[4 + countB] = v;
        verticesB[4 + countB + 1] = v;

        v = copyVector(reinterpret_cast<const PlainVector&>(verticesB[0].quad));
        verticesB[countB] = v;
        verticesB[countB + 1] = v;

        count = 1;
    }

    Vector differences[4];
    SolverOutput output;

    for (int i = 0; i < count; ++i)
        differences[i].quad = _mm_sub_ps(a[i].quad, verticesB[i].quad);

    if (TestPenetration(arg1, arg2, transform, runtimeFloatSettingDefault726, a, verticesB + 4, differences, count,
                        &output) == 1)
    {

        countA = 1;
        countB = 1;
        status = 1;
        result = output.normal;
        return;
    }

    unsigned tag2 = *(unsigned*)&a[2].quad.m128_f32[3] & 0xc0ffffff;

    unsigned tag1 = *(unsigned*)&a[1].quad.m128_f32[3] & 0xc0ffffff;

    countA = 3;
    countB = 3;

    if (tag1 == tag2 || ((*(unsigned*)&a[0].quad.m128_f32[3] & 0xc0ffffff) == tag2))
        countA = 2;

    if ((*(unsigned*)&a[0].quad.m128_f32[3] & 0xc0ffffff) == tag1)
    {
        --countA;
        a[0] = a[countA];
    }

    tag2 = *(unsigned*)&verticesB[4 + 2].quad.m128_f32[3] & 0xc0ffffff;

    tag1 = *(unsigned*)&verticesB[4 + 1].quad.m128_f32[3] & 0xc0ffffff;

    if (tag1 == tag2)
        --countB;
    else if ((*(unsigned*)&verticesB[4 + 0].quad.m128_f32[3] & 0xc0ffffff) == tag2)
        --countB;

    if (countB >= 2 && ((*(unsigned*)&verticesB[4 + 0].quad.m128_f32[3] & 0xc0ffffff) == tag1))
    {
        --countB;
        verticesB[4 + 0] = verticesB[4 + countB];
    }

    Vector tx = copyVector(transform->x), ty = copyVector(transform->y), tz = copyVector(transform->z),
           tw = copyVector(transform->translation);

    int j = countB - 1;
    Vector* cursor = &verticesB[4 + j];
    do
    {

        __m128 p = cursor->quad;

        __m128 xy =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0x55), ty.quad), _mm_mul_ps(_mm_shuffle_ps(p, p, 0), tx.quad));

        __m128 zw = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0xaa), tz.quad), tw.quad);

        cursor[-4].quad = _mm_add_ps(xy, zw);
        --j;
        --cursor;

    } while (j >= 0);

    if (countA + countB > 4)
        FUN_00da98f0();

    if (countA == 2 && countB == 2)
    {

        Vector da, db;

        da.quad = _mm_sub_ps(a[1].quad, a[0].quad);

        db.quad = _mm_sub_ps(verticesB[1].quad, verticesB[0].quad);

        FUN_00d22e40(a, &da, verticesB, &db, &axis);
        status = 1;
    }

    else
        status = 1;
    result = output.normal;
}
