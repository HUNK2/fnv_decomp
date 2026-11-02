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
// @fnv 0x00e625c0
static __declspec(noinline) void FUN_00e625c0(const Matrix* matrix, Shape* shape, Shape* other, const Vec* normal,
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
// An ordinary caller keeps this internal helper present and lets the compiler
// assign its internal register ABI. It forwards genuine function arguments.
void ProjectShapes(const Matrix* matrix, Shape* shape, Shape* other, const Vec* normal, Result* result)
{
    FUN_00e625c0(matrix, shape, other, normal, result);
}
