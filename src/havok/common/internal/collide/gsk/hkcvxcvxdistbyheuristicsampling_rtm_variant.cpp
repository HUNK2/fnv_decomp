// src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Baseline from an unnamed contributor, 2026-10-28, packet score 58 (unverified).
// The inherited volatile-global caller is replaced by an ordinary argument-forwarding caller.
// No unverified non-aliasing qualifier is imposed on the result pointer.
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C"
{
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
    void _mm_store_ps(float*, __m128);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const float*);
    int _mm_movemask_ps(__m128);
    float _mm_cvtss_f32(__m128);
}
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern const __m128 DAT_010c44d0;
struct Matrix;
struct Scalar
{
    __m128 v;
    Scalar(__m128 x) : v(x)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, v);
        return value;
    }
};
struct Vec
{
    union
    {
        __m128 v;
        struct
        {
            float x, y, z, w;
        };
    };
    Vec()
    {}
    Vec(const Vec& a) : v(a.v)
    {}
    void operator=(const Vec& a)
    {
        v = a.v;
    }
    void negative(const Vec& n)
    {
        v = _mm_xor_ps(n.v, DAT_010c44d0);
    }
    void inv(const Matrix& m, const Vec& n);
    void point(const Matrix& m, const Vec& b);
    void difference(const Vec& a, const Vec& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    Scalar dot(const Vec& n) const
    {
        __m128 p = _mm_mul_ps(v, n.v);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return Scalar(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy));
    }
    Scalar at(int i) const
    {
        if (i == 0)
            return Scalar(v);
        if (i == 1)
            return Scalar(_mm_shuffle_ps(v, v, 0x55));
        if (i == 2)
            return Scalar(_mm_shuffle_ps(v, v, 0xaa));
        return Scalar(_mm_shuffle_ps(v, v, 0xff));
    }
    void set(float a, float b, float c, float d)
    {
        v = _mm_setr_ps(a, b, c, d);
    }
};
struct Matrix
{
    Vec row0, row1, row2, row3;
};
__forceinline void Vec::inv(const Matrix& m, const Vec& n)
{
    __m128 a = m.row0.v, b = m.row1.v, c = m.row2.v;
    __m128 low = _mm_unpacklo_ps(a, b);
    __m128 high = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c, 0xe4);
    a = _mm_movelh_ps(low, c);
    b = _mm_shuffle_ps(_mm_movehl_ps(a, low), c, 0xd4);
    c = high;
    __m128 x = _mm_shuffle_ps(n.v, n.v, 0);
    __m128 px = _mm_mul_ps(a, x);
    __m128 y = _mm_shuffle_ps(n.v, n.v, 0x55);
    __m128 py = _mm_mul_ps(b, y);
    __m128 z = _mm_shuffle_ps(n.v, n.v, 0xaa);
    __m128 pz = _mm_mul_ps(c, z);
    v = _mm_add_ps(_mm_add_ps(px, py), pz);
}
__forceinline void Vec::point(const Matrix& m, const Vec& b)
{
    __m128 x = _mm_shuffle_ps(b.v, b.v, 0);
    __m128 px = _mm_mul_ps(m.row0.v, x);
    __m128 y = _mm_shuffle_ps(b.v, b.v, 0x55);
    __m128 py = _mm_mul_ps(m.row1.v, y);
    __m128 z = _mm_shuffle_ps(b.v, b.v, 0xaa);
    __m128 pz = _mm_mul_ps(m.row2.v, z);
    v = _mm_add_ps(_mm_add_ps(px, py), _mm_add_ps(pz, m.row3.v));
}
struct Shape
{
    virtual void reserved() = 0;
    virtual void transform(const Vec*, Vec*) = 0;
};
struct Result
{
    Vec pointA, pointB, localB, plane;
};
static void FUN_00e625c0(const Matrix* matrix, Shape* shape, Shape* other, const Vec* normal, Result* result);
void ProjectShapes(const Matrix* matrix, Shape* shape, Shape* other, const Vec* normal, Result* result);

#include <string.h>

#include <math.h>

extern const float DAT_01017d00 = 0.001f;

extern "C" ::__m128(_mm_setzero_ps)();

extern "C" ::__m128(_mm_set_ss)(float);

extern "C" ::__m128(_mm_rsqrt_ss)(::__m128);

extern "C" ::__m128(_mm_cmpeq_ss)(::__m128, ::__m128);

extern "C" ::__m128(_mm_andnot_ps)(::__m128, ::__m128);

extern "C" ::__m128(_mm_mul_ss)(::__m128, ::__m128);

extern ::Vec DAT_01268370;

struct SamplingOutPair_e62740
{
    ::Vec first, second;
};

static __forceinline ::__m128 SamplingRecipSqrt_e62740(::__m128 r, const ::Vec& three, const ::Vec& half,
                                                       const ::Vec& zero)

{

    ::__m128 e = (_mm_rsqrt_ss)(r);

    ::__m128 cmp = (_mm_cmpeq_ss)(r, zero.v);

    ::__m128 t = (_mm_mul_ss)((_mm_mul_ss)(r, e), e);

    ::__m128 q = (_mm_mul_ss)((_mm_mul_ss)(half.v, e), (_mm_sub_ss)(three.v, t));

    return (_mm_andnot_ps)(cmp, q);
}

static __forceinline void SamplingSetMul_e62740(::Vec& o, ::__m128 s, const ::Vec& a)

{

    o.v = (_mm_mul_ps)(s, a.v);
}

struct SamplingShuffles_e62740
{
    ::Vec d, c;
};

static __forceinline void SamplingPrepare_e62740(SamplingShuffles_e62740& sh, ::__m128 q)
{
    sh.d.v = (_mm_shuffle_ps)(q, q, 0xd2);
    sh.c.v = (_mm_shuffle_ps)(q, q, 0xc9);
}

static __forceinline void SamplingCross_e62740(::Vec& o, const ::Vec& a, const SamplingShuffles_e62740& sh)

{

    ::__m128 m1 = (_mm_mul_ps)((_mm_shuffle_ps)(a.v, a.v, 0xd2), sh.c.v);

    ::__m128 m2 = (_mm_mul_ps)((_mm_shuffle_ps)(a.v, a.v, 0xc9), sh.d.v);

    o.v = (_mm_sub_ps)(m2, m1);
}

static __forceinline void SamplingSetMulS_e62740(::Vec& o, ::__m128 s, const ::Vec& a)

{

    o.v = (_mm_mul_ps)((_mm_shuffle_ps)(s, s, 0), a.v);
}

static __declspec(noinline) void FUN_00e625c0(const Matrix* matrix, Shape* shape, Shape* other, Vec* normal,
                                              Result* result)
{
    Result* output = result;
    Vec opposite, local, a, b;
    opposite.negative(*normal);
    local.inv(*matrix, *normal);
    shape->transform(&opposite, &a);
    other->transform(&local, &b);
    Vec mapped, delta;
    mapped.point(*matrix, b);
    delta.difference(a, mapped);
    Vec n = *normal;
    Scalar distance = delta.dot(n);
    if (_mm_movemask_ps(_mm_sub_ss(output->plane.at(3).v, distance.v)) & 1)
    {

        output->plane.set(n.at(0), n.at(1), n.at(2), distance);
        output->pointA = a;
        output->localB = b;
        output->pointB = mapped;
    }
}

// @fnv 0x00e62740
__declspec(noinline) void FUN_00e62740(Shape* shape, Shape* other, const Matrix* matrix, ::Vec* outA, ::Vec* outB,
                                       SamplingOutPair_e62740* outPair)

{

    Result result;

    result.plane.w = -3.402820018375656e+38f;

    const ::Vec* axisPtr = &DAT_01268370;

    int count = 3;

    do
    {

        ::Vec axis;

        memcpy(&axis, axisPtr, sizeof(::Vec));

        axisPtr += 1;

        axis.v = (_mm_xor_ps)(DAT_010c44d0, axis.v);

        FUN_00e625c0(matrix, shape, other, &axis, &result);

        FUN_00e625c0(matrix, shape, other, &axis, &result);

    } while (--count != 0);

    ::Vec zeroA;

    zeroA.v = (_mm_setzero_ps)();

    ::Vec zeroB;

    zeroB.v = (_mm_set_ss)(0.0f);

    ::Vec cThree;

    cThree.v = (_mm_set_ss)(3.0f);

    ::Vec cHalf;

    cHalf.v = (_mm_set_ss)(0.5f);

    float limit = 1.0f;

    do
    {

        limit = (float)(limit * 0.9900000095367431640625);

        float absX = fabs(result.plane.x);

        float absY = fabs(result.plane.y);

        float absZ = fabs(result.plane.z);

        int iMin = 0;

        int i1 = iMin + 1;

        int i2 = iMin + 2;

        if (absY < absX)
        {
            absX = absY;
            i1 = 0;
            iMin = 1;
        }

        if (absZ < absX)
            i2 = iMin;

        ::Vec perp;

        perp = zeroA;

        float* planeC = &result.plane.x;

        float* perpC = &perp.x;

        perpC[i1] = planeC[i2];

        perpC[i2] = -planeC[i1];

        ::Vec perpN;

        SamplingSetMulS_e62740(perpN, SamplingRecipSqrt_e62740(perp.dot(perp).v, cThree, cHalf, zeroB), perp);

        ::__m128 ls1 = (_mm_load_ss)(&limit);

        ::__m128 ls2 = (_mm_load_ss)(&limit);

        SamplingShuffles_e62740 sh;
        SamplingPrepare_e62740(sh, perpN.v);

        ::Vec scaledPerp;

        SamplingSetMulS_e62740(scaledPerp, ls1, perpN);

        ::Vec cross;

        SamplingCross_e62740(cross, result.plane, sh);

        ::Vec crossScaled;

        SamplingSetMulS_e62740(crossScaled, ls2, cross);

        ::Vec sum;

        sum.v = (_mm_add_ps)(result.plane.v, scaledPerp.v);

        ::__m128 is2 = SamplingRecipSqrt_e62740(sum.dot(sum).v, cThree, cHalf, zeroB);

        ::__m128 splat2 = (_mm_shuffle_ps)(is2, is2, 0);

        ::Vec n1;

        SamplingSetMul_e62740(n1, splat2, sum);

        ::Vec n2;

        n2.v = (_mm_mul_ps)((_mm_sub_ps)(result.plane.v, scaledPerp.v), splat2);

        ::__m128 add3 = (_mm_add_ps)(crossScaled.v, result.plane.v);

        ::__m128 sub4 = (_mm_sub_ps)(result.plane.v, crossScaled.v);

        ::Vec n3;

        n3.v = (_mm_mul_ps)(add3, splat2);

        ::Vec n4;

        n4.v = (_mm_mul_ps)(sub4, splat2);

        FUN_00e625c0(matrix, shape, other, &n1, &result);

        FUN_00e625c0(matrix, shape, other, &n2, &result);

        FUN_00e625c0(matrix, shape, other, &n3, &result);

        FUN_00e625c0(matrix, shape, other, &n4, &result);

        limit = (float)(limit * 0.5);

    } while (limit > DAT_01017d00);

    *outA = result.pointA;

    *outB = result.localB;

    outPair->first = result.plane;

    outPair->second = result.pointA;
}
