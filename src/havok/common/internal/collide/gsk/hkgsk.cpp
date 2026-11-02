
// src/havok/common/internal/collide/gsk/hkgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier(void);

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

typedef float hkReal;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setNeg4(const hkVector4& v);
    __forceinline int lessZeroXYZ() const
    {
        return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
    }
};

extern __m128 DAT_010c44d0;

__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}

static __forceinline int hkDot3LessZero(const hkVector4& a, const hkVector4& b)
{
    __m128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    __m128 xyz = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
    return _mm_movemask_ps(xyz) & 1;
}

static __forceinline void hkTranspose3(hkVector4& c0, hkVector4& c1, hkVector4& c2)
{
    __m128 tmp = _mm_unpacklo_ps(c0.m_vComponents, c1.m_vComponents);
    __m128 ctmp = _mm_unpackhi_ps(c0.m_vComponents, c1.m_vComponents);
    c0.m_vComponents = _mm_movelh_ps(tmp, c2.m_vComponents);
    c1.m_vComponents = _mm_shuffle_ps(_mm_movehl_ps(c0.m_vComponents, tmp), c2.m_vComponents, 0xd4);
    c2.m_vComponents = _mm_shuffle_ps(ctmp, c2.m_vComponents, 0xe4);
}

static __forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                                    const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
    hkVector4 c0;
    c0.setMul4(a0, b0);
    hkVector4 c1;
    c1.setMul4(a1, b1);
    hkVector4 c2;
    c2.setMul4(a2, b2);
    hkTranspose3(c0, c1, c2);
    dotsOut.setAdd4(c0, c1);
    dotsOut.add4(c2);
}

template <class T> static __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct TriangleVerts
{
    hkVector4 m_kVertices[3];
    hkVector4 m_extra30;
    hkVector4 m_extra40;
    hkVector4 m_extra50;
};

struct TriangleSolver
{
    hkVector4 m_barycentric;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_flipped;
    hkVector4 m_kPoint;
    hkVector4 m_unk30;
    hkVector4 m_unk40;
    hkVector4 m_unk50;
    hkVector4 m_unk60;
    hkVector4 m_unk70;
    hkVector4 m_unk80;
    hkVector4 m_unk90;
    hkVector4 m_kSmartReference;

    int FUN_00e4da90(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut);
};

// Computes three dot products into m_barycentric, stores the normal, and may flip the winding and swap values when mask is 7.
// @fnv 0x00e4da90
int TriangleSolver::FUN_00e4da90(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut)
{
    hkVector4 e0;
    e0.setSub4(tri.m_kVertices[2], tri.m_kVertices[1]);
    hkVector4 e1;
    e1.setSub4(tri.m_kVertices[0], tri.m_kVertices[2]);
    hkVector4 e2;
    e2.setSub4(tri.m_kVertices[1], tri.m_kVertices[0]);

    hkVector4 normal;
    normal.setCross(e0, e1);

    hkVector4 d1;
    d1.setSub4(p, tri.m_kVertices[1]);
    hkVector4 d2;
    d2.setSub4(p, tri.m_kVertices[2]);
    hkVector4 d0;
    d0.setSub4(p, tri.m_kVertices[0]);

    hkVector4 c0;
    c0.setCross(d1, e0);
    hkVector4 c1;
    c1.setCross(d2, e1);
    hkVector4 c2;
    c2.setCross(d0, e2);

    dot3_3vs3(c0, normal, c1, normal, c2, normal, m_barycentric);

    int mask = m_barycentric.lessZeroXYZ();
    normalOut = normal;
    if (mask == 7)
    {
        hkVector4 diff;
        diff.setSub4(m_kPoint, m_kSmartReference);
        if (hkDot3LessZero(diff, normal))
        {
            normal.setNeg4(normal);
            hkSwap(tri.m_kVertices[0], tri.m_kVertices[1]);
            _ReadWriteBarrier();
            normalOut = normal;
            hkSwap(m_barycentric.m_vComponents.m128_f32[0], m_barycentric.m_vComponents.m128_f32[1]);
            hkVector4* __restrict pExtra = &tri.m_extra40;
            hkSwap(pExtra[0], pExtra[1]);
            m_flipped = 1;
        }
    }
    return mask;
}

namespace fnv_00e4dc70 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    int _mm_movemask_ps(__m128);
}
struct hkVector4
{
    __m128 m_vComponents;
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4& a, const hkVector4& b)
    {
        const __m128 a1 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
        const __m128 a2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
        const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
        const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
        const __m128 c0 = _mm_mul_ps(a1, b2);
        const __m128 c1 = _mm_mul_ps(a2, b1);
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    int lessZero3() const
    {
        return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
    }
    int FUN_00e4dc70(const hkVector4&, const hkVector4*, void*);
};
static inline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, hkVector4& out)
{
    __m128 d0 = _mm_mul_ps(a0.m_vComponents, b0.m_vComponents);
    __m128 d1 = _mm_mul_ps(a1.m_vComponents, b1.m_vComponents);
    __m128 d2 = _mm_mul_ps(a2.m_vComponents, b2.m_vComponents);
    {
        __m128 low, high;
        low = _mm_unpacklo_ps(d0, d1);
        high = _mm_shuffle_ps(_mm_unpackhi_ps(d0, d1), d2, 0xe4);
        d0 = _mm_movelh_ps(low, d2);
        d1 = _mm_shuffle_ps(_mm_movehl_ps(d0, low), d2, 0xd4);
        d2 = high;
    }
    out.m_vComponents = _mm_add_ps(_mm_add_ps(d0, d1), d2);
}

// Computes three dot products of cross products with the normal, stores them, and returns a bitmask of negative first three components.
// @fnv 0x00e4dc70
int hkVector4::FUN_00e4dc70(const hkVector4& point, const hkVector4* apTriangle, void*)
{
    const hkVector4& v0 = apTriangle[0];
    const hkVector4& v1 = apTriangle[1];
    const hkVector4& v2 = apTriangle[2];
    hkVector4 e0;
    e0.setSub4(v2, v1);
    hkVector4 e1;
    e1.setSub4(v0, v2);
    hkVector4 e2;
    e2.setSub4(v1, v0);
    hkVector4 n;
    n.setCross(e0, e1);
    hkVector4 p1;
    p1.setSub4(point, v1);
    hkVector4 p2;
    p2.setSub4(point, v2);
    hkVector4 p0;
    p0.setSub4(point, v0);
    hkVector4 c0;
    c0.setCross(p1, e0);
    hkVector4 c1;
    c1.setCross(p2, e1);
    hkVector4 c2;
    c2.setCross(p0, e2);
    dot3_3vs3(c0, n, c1, n, c2, n, *this);
    return lessZero3();
}
}  // namespace fnv_00e4dc70

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_setzero_ps();
    int _mm_movemask_ps(__m128);
    void _mm_store_ss(float*, __m128);
}

struct Out
{
    int* p;
    Out(int* a) : p(a)
    {}
};
static const __m128 one4 = {1, 1, 1, 1};

struct Scalar
{
    __m128 q;
    Scalar()
    {}
    Scalar(const __m128& a) : q(a)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, q);
        return value;
    }
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
inline Scalar operator*(const Scalar& a, const Scalar& b)
{
    return _mm_mul_ss(a.q, b.q);
}
inline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.q, b.q);
}
inline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.q, b.q);
}
struct V
{
    union
    {
        __m128 q;
        struct
        {
            unsigned x, y, z, w;
        };
    };
    V()
    {}
    V(const V& a) : x(a.x), y(a.y), z(a.z), w(a.w)
    {}
    V& operator=(const V& a)
    {
        q = a.q;
        return *this;
    }
    void sub(const V& a, const V& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    void cross(const V& a, const V& b)
    {
        __m128 l = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 r = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(l, r);
    }
    Scalar dot(const V& b) const
    {
        __m128 p = _mm_mul_ps(q, b.q);
        __m128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), t);
    }
    void interpolate(const V& a, const V& b, const Scalar& f)
    {
        __m128 t = f.broadcast();
        __m128 s = _mm_sub_ps(one4, t);
        q = _mm_add_ps(_mm_mul_ps(s, a.q), _mm_mul_ps(t, b.q));
    }
    Scalar component(int i) const
    {
        switch (i)
        {
        case 0:
            return q;
        case 1:
            return _mm_shuffle_ps(q, q, 0x55);
        case 2:
            return _mm_shuffle_ps(q, q, 0xaa);
        default:
            return _mm_shuffle_ps(q, q, 0xff);
        }
    }
};
static __forceinline void Swap(V& a, V& b)
{
    V saved = a;
    a = b;
    b = saved;
}
static __forceinline bool ComparePlane(const V& oldValue, const V& newValue, int i, int j)
{
    Scalar oldI = oldValue.component(i);
    Scalar oldJ = oldValue.component(j);
    Scalar deltaI = newValue.component(i) - oldI;
    Scalar deltaJ = newValue.component(j) - oldJ;
    return float(oldJ * deltaI) > float(oldI * deltaJ);
}

struct Shape
{
    V points[4];
    V anchors[3];
};
struct Clip
{
    V point;
    V separation;
    float distance;
};
struct Both
{
    Clip first;
    Clip second;
};
extern "C" int FUN_00d22e40(Shape*, const V*, const V*, const V*, Clip*);

static __forceinline void ThreeDots(const V& first, const V& firstWeight, const V& second, const V& secondWeight,
                                    const V& third, const V& thirdWeight, V& out)
{
    register __m128 products0 = _mm_mul_ps(first.q, firstWeight.q);
    register __m128 products1 = _mm_mul_ps(second.q, secondWeight.q);
    register __m128 products2 = _mm_mul_ps(third.q, thirdWeight.q);
    __m128 lower = _mm_unpacklo_ps(products0, products1);
    __m128 upper = _mm_shuffle_ps(_mm_unpackhi_ps(products0, products1), products2, 0xe4);
    products0 = _mm_movelh_ps(lower, products2);
    products1 = _mm_shuffle_ps(_mm_movehl_ps(products0, lower), products2, 0xd4);
    products2 = upper;
    out.q = _mm_add_ps(_mm_add_ps(products0, products1), products2);
}

static __forceinline int mask(const V& p, const Shape* b)
{
    V e0, e1, e2, n, d0, d1, d2, c0, c1, c2;
    e0.sub(b->points[2], b->points[1]);
    e1.sub(b->points[0], b->points[2]);
    e2.sub(b->points[1], b->points[0]);
    n.cross(e0, e1);
    d0.sub(p, b->points[1]);
    d1.sub(p, b->points[2]);
    d2.sub(p, b->points[0]);
    c0.cross(d0, e0);
    c1.cross(d1, e1);
    c2.cross(d2, e2);
    V sum;
    ThreeDots(c0, n, c1, n, c2, n, sum);
    return _mm_movemask_ps(_mm_cmplt_ps(sum.q, _mm_setzero_ps())) & 7;
}
static __forceinline void ReplaceSelected(V& point, V& anchor, const V& newPoint, const V& newAnchor, int* count)
{
    point = newPoint;
    anchor = newAnchor;
    *count = 2;
}

static __forceinline void CollapseFirst(Shape* shape, const V& point, int* count)
{
    *count = 1;
    shape->points[0] = point;
    shape->anchors[0] = shape->anchors[1];
}

struct State
{
    V origin;
    int m10, m14, m18, m1c;
    V m20, m30, m40, m50, m60, m70, m80, m90, ma0, mb0, mc0, md0, me0, mf0, m100, m110;
    V direction;
    int FUN_00e4da90(Shape*, Shape*, V*);
    int FUN_00e4dc70(V*, Shape*, V*);
    int FUN_00e4bbe0(Shape*, Shape*, int*, int*, unsigned char, int);
};
// Branches on flag, updates shape points and anchors, writes through out1 or out2 on selected paths, and returns status values.
// @fnv 0x00e4bbe0
int State::FUN_00e4bbe0(Shape* apShapeA, Shape* apShapeB, int* __restrict apOutCount1, int* __restrict apOutCount2,
                        unsigned char flag, int val)
{
    if (flag)
    {
        V edge0, edge1, normal;
        edge0.sub(apShapeB->points[1], apShapeB->points[2]);
        edge1.sub(apShapeB->points[0], apShapeB->points[2]);
        normal.cross(edge0, edge1);
        V d0;
        d0.sub(apShapeA->points[0], apShapeB->points[0]);
        Scalar s0 = d0.dot(normal);
        d0.sub(apShapeA->points[1], apShapeB->points[0]);
        Scalar s1 = d0.dot(normal);
        if (_mm_movemask_ps((s0 * s1).q) & 1)
        {
            Scalar t = s0 / (s0 - s1);
            V p;
            p.interpolate(apShapeA->points[0], apShapeA->points[1], t);
            if (mask(p, apShapeB) == 7)
                return 1;
        }
        else
        {
            if (float(s0 * s0) > float(s1 * s1))
            {
                Swap(apShapeA->points[0], apShapeA->points[1]);
                Swap(apShapeA->anchors[0], apShapeA->anchors[1]);
            }
            if (FUN_00e4da90(apShapeA, apShapeB, &direction) == 7)
            {
                *apOutCount1 = 1;
                return 0;
            }
        }
        V diff;
        diff.sub(apShapeA->points[1], apShapeA->points[0]);
        Clip clip0, clip1;
        Clip* later = &clip1;
        FUN_00d22e40(apShapeA, &diff, &apShapeB->points[2], &edge0, &clip0);
        FUN_00d22e40(apShapeA, &diff, &apShapeB->points[2], &edge1, later);
        int index = clip0.distance > clip1.distance ? 1 : 0;
        ReplaceSelected(apShapeB->points[index], apShapeB->anchors[index], apShapeB->points[2], apShapeB->anchors[2],
                        apOutCount2);
        return 2;
    }
    else
    {
        V saved = origin;
        V* end = &apShapeA->points[0];
        V d0;
        d0.sub(*end, apShapeB->points[0]);
        Scalar s0 = d0.dot(direction);
        ++end;
        d0.sub(*end, apShapeB->points[0]);
        Scalar s1 = d0.dot(direction);
        if (_mm_movemask_ps((s0 * s1).q) & 1)
        {
            V p;
            p.interpolate(apShapeA->points[0], *end, s0 / (s0 - s1));
            if (mask(p, apShapeB) == 7)
                return 1;
        }
        int r = FUN_00e4dc70(end, apShapeB, &direction);
        if (r == 7)
        {
            CollapseFirst(apShapeA, *end, apOutCount1);
            m14 = val;
            return 0;
        }
        *apOutCount2 = 2;
        if (r == 6)
            goto replace0;
        if (r == 5)
            goto replace1;
        if (r == 3)
            goto done;
        if (r == 1)
        {
            if (ComparePlane(saved, origin, 1, 2))
                goto done;
            goto replace1;
        }
        if (r == 2)
        {
            if (ComparePlane(saved, origin, 2, 0))
                goto replace0;
            goto done;
        }
        else if (r == 4)
        {
            if (ComparePlane(saved, origin, 0, 1))
                goto replace1;
        }
    replace0:
        apShapeB->points[0] = apShapeB->points[2];
        apShapeB->anchors[0] = apShapeB->anchors[2];
    done:
        return 2;
    replace1:
        apShapeB->points[1] = apShapeB->points[2];
        apShapeB->anchors[1] = apShapeB->anchors[2];
        return 2;
    }
}
