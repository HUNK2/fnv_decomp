
// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00dad640_Entry
{
    unsigned short unk0;
    unsigned short id;
    unsigned int unk4;
};

struct S_00dad640_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[1];
};

struct S_00dad640_Target
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void Release(unsigned short id, void* arg);
};

// @fnv 0x00dad640
void ReleaseAllEntries(S_00dad640_Set* set, S_00dad640_Target* target, void* arg)
{
    for (unsigned int i = 0; i < set->count; i++)
    {
        unsigned short id = set->entries[i].id;
        if (id != 0xffff)
            target->Release(id, arg);
    }
    set->count = 0;
    set->unk0 = 0;
    set->unk1 = 0;
}

struct S_00dad4d0_Key
{
    unsigned short ids[4];
    unsigned char numA;
    unsigned char numB;
};
struct S_00dad4d0_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dad4d0_Raw
{
    unsigned int lo;
    unsigned int hi;
};
struct S_00dad4d0_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad4d0_Entry entries[1];

    unsigned short Id(unsigned char off)
    {
        return *(unsigned short*)((char*)&entries[count] + (off >> 3));
    }
};

// @fnv 0x00dad4d0
bool FindAndPromoteEntry(S_00dad4d0_Set* set, S_00dad4d0_Key* key)
{
    unsigned i;
    for (i = 0; i < set->count; i++)
    {
        S_00dad4d0_Entry* pEntry = &set->entries[i];
        if (key->numA == pEntry->numA && key->numB == pEntry->numB)
        {
            int iIdCount = key->numA + key->numB;
            if (key->ids[0] == set->Id(pEntry->offs[0]) && key->ids[1] == set->Id(pEntry->offs[1]) &&
                (iIdCount <= 2 || key->ids[2] == set->Id(pEntry->offs[2])) &&
                (iIdCount <= 3 || key->ids[3] == set->Id(pEntry->offs[3])))
            {
                if (i > 0)
                {
                    S_00dad4d0_Raw* pRawEntries = (S_00dad4d0_Raw*)set->entries;
                    S_00dad4d0_Raw rawTemp = pRawEntries[i];
                    pRawEntries[i] = pRawEntries[0];
                    pRawEntries[0] = rawTemp;
                }
                return true;
            }
        }
    }
    if (key->numA == 1 || key->numB == 1)
    {
        for (unsigned uiScanIndex = 0; uiScanIndex < set->count; uiScanIndex++)
        {
            S_00dad4d0_Entry* pEntry = &set->entries[uiScanIndex];
            if (key->numA == 1 && pEntry->numA == 1 && set->Id(pEntry->offs[0]) == key->ids[0])
            {
                pEntry->numA = 0;
                pEntry->numB = 0;
                return false;
            }
            if (key->numB == 1 && pEntry->numB == 1 && set->Id(pEntry->offs[pEntry->numA]) == key->ids[key->numA])
            {
                pEntry->numA = 0;
                pEntry->numB = 0;
                return false;
            }
        }
    }
    return false;
}

void __fastcall FUN_00dae220(int unused, S_00dad640_Set* set);

// @fnv 0x00dae340
void __cdecl FUN_00dae340(S_00dad640_Set* set, unsigned int index)
{
    unsigned int n = set->count;
    unsigned int last = n - 1;
    set->count = (unsigned char)last;
    unsigned int* puiDst = (unsigned int*)&set->entries[last];
    set->entries[index] = set->entries[last];
    unsigned int* puiSrc = (unsigned int*)&set->entries[n];
    int iShift = ((int)set->unk1 + (int)set->unk0 - 1) >> 1;
    unsigned int* puiBaseDst = puiDst;
    for (; iShift >= 0; iShift--)
    {
        *puiDst = *(unsigned int*)((char*)puiSrc + ((char*)puiDst - (char*)puiBaseDst));
        ++puiDst;
    }
    FUN_00dae220(iShift, set);
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_setzero_ps();
    __m128 _mm_set_ss(float);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    void _mm_store_ss(float*, __m128);
}
extern float DAT_01011d78, DAT_01017718, DAT_01016248;
extern __m128 DAT_010ec7f0, DAT_010c44d0;

class Scalar
{
    __m128 q;

  public:
    Scalar()
    {}
    Scalar(const __m128& x) : q(x)
    {}

    operator float() const
    {
        float x;
        _mm_store_ss(&x, q);
        return x;
    }
    __forceinline const __m128& packet() const
    {
        return q;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
__forceinline Scalar operator+(const Scalar& a, const Scalar& b)
{
    return _mm_add_ss(a.packet(), b.packet());
}
__forceinline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.packet(), b.packet());
}
__forceinline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.packet(), b.packet());
}
struct Comparison
{
    __m128 bits;
    enum
    {
        MASK_XY = 3,
        MASK_W = 8
    };
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(bits);
    }
    __forceinline int anyIsSet(int mask) const
    {
        return GetLaneMask() & mask;
    }
};
class Vector
{
    __m128 q;

  public:
    __forceinline Vector()
    {}
    __forceinline Vector(const Vector& a) : q(a.q)
    {}
    __forceinline Vector(const __m128& a) : q(a)
    {}
    __forceinline operator __m128() const
    {
        return q;
    }
    __forceinline void operator=(const Vector& a)
    {
        q = a.q;
    }
    __forceinline void operator=(const __m128& a)
    {
        q = a;
    }
    __forceinline __m128& packet()
    {
        return q;
    }
    __forceinline const __m128& packet() const
    {
        return q;
    }
    __forceinline float& operator()(int n)
    {
        return q.m128_f32[n];
    }
    __forceinline const float& operator()(int n) const
    {
        return q.m128_f32[n];
    }
    __forceinline Scalar getSimdAt(int n) const
    {
        switch (n)
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
    __forceinline void setSub4(const Vector& a, const Vector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void setCross(const Vector& a, const Vector& b)
    {
        __m128 first;
        first = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 second;
        second = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(first, second);
    }
    __forceinline Scalar dot3(const Vector& a) const
    {
        __m128 product = _mm_mul_ps(q, a.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline Scalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline Scalar inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        __m128 squared = dot3(*this).packet();
        __m128 iszero = _mm_cmpeq_ss(squared, zero);
        __m128 estimate = _mm_rsqrt_ss(squared);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate));
        return _mm_andnot_ps(iszero, _mm_mul_ss(_mm_mul_ss(half, estimate), correction));
    }
    __forceinline void normalize3()
    {
        __m128 inverse = inverseLength().splat();
        q = _mm_mul_ps(inverse, q);
    }
    __forceinline void setInterpolate4(const Vector& a, const Vector& b, const Scalar& t)
    {
        static const __m128 one = {1.0f, 1.0f, 1.0f, 1.0f};
        __m128 weight = t.splat(), complement = _mm_sub_ps(one, weight);
        q = _mm_add_ps(_mm_mul_ps(complement, a.q), _mm_mul_ps(weight, b.q));
    }
    __forceinline void setAddMul4(const Vector& a, const Vector& b, const Scalar& t)
    {
        q = _mm_add_ps(a.q, _mm_mul_ps(t.splat(), b.q));
    }
    __forceinline void setNeg4(const Vector& a)
    {
        static const __declspec(align(16)) unsigned int mask[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
        q = _mm_xor_ps(a.q, *reinterpret_cast<const __m128*>(mask));
    }
    __forceinline Comparison compareLessThanZero4() const
    {
        Comparison c;
        c.bits = _mm_cmplt_ps(q, _mm_setzero_ps());
        return c;
    }
};
namespace VectorUtil {
__forceinline void dot3_3vs3(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& e,
                             const Vector& f, Vector& result)
{
    __m128 x = _mm_mul_ps(a.packet(), b.packet()), y = _mm_mul_ps(c.packet(), d.packet()),
           z = _mm_mul_ps(e.packet(), f.packet());
    __m128 low, high;
    low = _mm_unpacklo_ps(x, y);
    high = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), z, 0xe4);
    x = _mm_movelh_ps(low, z);
    y = _mm_shuffle_ps(_mm_movehl_ps(x, low), z, 0xd4);
    z = high;
    result.packet() = _mm_add_ps(_mm_add_ps(x, y), z);
}
__forceinline void dot3_1vs4(const Vector& normal, const Vector& a, const Vector& b, const Vector& c, const Vector& d,
                             Vector& result)
{
    __m128 x = _mm_mul_ps(a.packet(), normal.packet()), y = _mm_mul_ps(b.packet(), normal.packet());
    __m128 z = _mm_mul_ps(c.packet(), normal.packet()), w = _mm_mul_ps(d.packet(), normal.packet());
    __m128 t3, t2, t1, t0;
    t0 = _mm_shuffle_ps(x, y, 0x44);
    t2 = _mm_shuffle_ps(x, y, 0xee);
    t1 = _mm_shuffle_ps(z, w, 0x44);
    t3 = _mm_shuffle_ps(z, w, 0xee);
    x = _mm_shuffle_ps(t0, t1, 0x88);
    y = _mm_shuffle_ps(t0, t1, 0xdd);
    z = _mm_shuffle_ps(t2, t3, 0x88);
    w = _mm_shuffle_ps(t2, t3, 0xdd);
    result.packet() = _mm_add_ps(_mm_add_ps(x, y), z);
}
__forceinline void dot3_2vs2(const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& result)
{
    __m128 x = _mm_mul_ps(a.packet(), c.packet()), y = _mm_mul_ps(a.packet(), d.packet());
    __m128 z = _mm_mul_ps(b.packet(), c.packet()), w = _mm_mul_ps(b.packet(), d.packet());
    __m128 t3, t2, t1, t0;
    t0 = _mm_shuffle_ps(x, y, 0x44);
    t2 = _mm_shuffle_ps(x, y, 0xee);
    t1 = _mm_shuffle_ps(z, w, 0x44);
    t3 = _mm_shuffle_ps(z, w, 0xee);
    x = _mm_shuffle_ps(t0, t1, 0x88);
    y = _mm_shuffle_ps(t0, t1, 0xdd);
    z = _mm_shuffle_ps(t2, t3, 0x88);
    w = _mm_shuffle_ps(t2, t3, 0xdd);
    result.packet() = _mm_add_ps(_mm_add_ps(x, y), z);
}
}

class FloatField
{
    float v;

  public:
    __forceinline FloatField()
    {}
    __forceinline FloatField(float x) : v(x)
    {}
    __forceinline float value() const
    {
        return v;
    }
    __forceinline operator float() const
    {
        return value();
    }
    __forceinline void operator=(float x)
    {
        v = x;
    }
};
struct ContactVertex : Vector
{
};
struct ContactWork
{
    ContactVertex vertices[16];
    Vector direction;
    FloatField radiusA, radiusB, tolerance, toleranceSquared;
    __forceinline const Vector& vertex(unsigned int off) const
    {
        return *reinterpret_cast<const ContactVertex*>(reinterpret_cast<const char*>(vertices) + off);
    }
};

struct ContactResult
{
    Vector point, delta, normal;
};

static __forceinline int pointPoint(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    Vector separation;
    separation.setSub4(a, b);
    float squared = separation.lengthSquared3();
    if (squared > w.toleranceSquared)
        return 1;
    r.delta = separation;
    r.normal = w.direction;
    r.point = a;
    return 0;
}
static __forceinline int pointEdge(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    r.point = a;
    r.normal = w.direction;
    Vector edge, first, second, area, weights;
    edge.setSub4(c, b);
    first.setSub4(c, a);
    second.setSub4(a, b);
    area.setCross(edge, first);
    VectorUtil::dot3_3vs3(first, edge, second, edge, area, area, weights);
    float squared = edge.lengthSquared3();
    int negative = weights.compareLessThanZero4().anyIsSet(Comparison::MASK_XY);
    if (weights(3) > w.toleranceSquared * squared || negative)
        return 1;
    Scalar fraction = weights.getSimdAt(0) / (weights.getSimdAt(0) + weights.getSimdAt(1));
    Vector closest;
    closest.setInterpolate4(b, c, fraction);
    r.delta.setSub4(a, closest);
    return 0;
}
static __forceinline int edgePoint(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    r.normal = w.direction;
    Vector keepB(b);
    Vector edge, first, second, area, weights;
    edge.setSub4(keepB, a);
    first.setSub4(keepB, c);
    second.setSub4(c, a);
    area.setCross(edge, first);
    VectorUtil::dot3_3vs3(first, edge, second, edge, area, area, weights);
    float squared = edge.lengthSquared3();
    int negative = weights.compareLessThanZero4().anyIsSet(Comparison::MASK_XY);
    if (weights(3) > w.toleranceSquared * squared || negative)
        return 1;
    Scalar fraction = weights.getSimdAt(0) / (weights.getSimdAt(0) + weights.getSimdAt(1));
    r.point.setInterpolate4(keepB, a, fraction);
    r.delta.setSub4(r.point, c);
    return 0;
}
static __forceinline int pointFace(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    const Vector& d = w.vertex(f.offs[3]);
    r.point = a;
    r.delta.setSub4(a, b);
    Vector edge0, edge1, edge2, normal, weights;
    edge0.setSub4(d, c);
    edge1.setSub4(b, d);
    edge2.setSub4(c, b);
    normal.setCross(edge0, edge1);
    normal.normalize3();
    {
        Vector ray0, ray1, ray2, side0, side1, side2;
        ray0.setSub4(a, c);
        ray1.setSub4(a, d);
        ray2.setSub4(a, b);
        side0.setCross(ray0, edge0);
        side1.setCross(ray1, edge1);
        side2.setCross(ray2, edge2);
        VectorUtil::dot3_1vs4(normal, side0, side1, side2, w.direction, weights);
    }
    r.normal = normal;
    int mask = weights.compareLessThanZero4().GetLaneMask();
    if (mask & Comparison::MASK_W)
        r.normal.setNeg4(normal);
    return (mask & 7) ^ 7;
}
static __forceinline int facePoint(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    const Vector& d = w.vertex(f.offs[3]);
    r.point = d;
    r.delta.setSub4(a, d);
    Vector edge0, edge1, edge2, normal, weights;
    edge0.setSub4(c, b);
    edge1.setSub4(a, c);
    edge2.setSub4(b, a);
    normal.setCross(edge0, edge1);
    normal.normalize3();
    {
        Vector ray0, ray1, ray2, side0, side1, side2;
        ray0.setSub4(d, b);
        ray1.setSub4(d, c);
        ray2.setSub4(d, a);
        side0.setCross(ray0, edge0);
        side1.setCross(ray1, edge1);
        side2.setCross(ray2, edge2);
        VectorUtil::dot3_1vs4(normal, side0, side1, side2, w.direction, weights);
    }
    Scalar projection = r.delta.dot3(normal);
    r.point.setAddMul4(d, normal, projection);
    r.normal = normal;
    int mask = weights.compareLessThanZero4().GetLaneMask();
    if (mask & Comparison::MASK_W)
        r.normal.setNeg4(normal);
    return (mask & 7) ^ 7;
}
static __forceinline int edgeEdge(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    const Vector& d = w.vertex(f.offs[3]);
    Vector edgeA, edgeB, diffA, diffB, normal, ortA, ortB, weights;
    edgeA.setSub4(b, a);
    edgeB.setSub4(d, c);
    diffA.setSub4(a, c);
    diffB.setSub4(b, d);
    normal.setCross(edgeA, edgeB);
    ortA.setCross(edgeA, normal);
    ortB.setCross(edgeB, normal);
    r.normal = w.direction;
    VectorUtil::dot3_2vs2(diffA, diffB, ortB, ortA, weights);
    int mask = weights.compareLessThanZero4().GetLaneMask();
    if (mask != 3 && mask != 12)
        return 1;
    Scalar x = weights.getSimdAt(0);
    Scalar fraction = x / (x - weights.getSimdAt(2));
    r.point.setInterpolate4(a, b, fraction);
    Scalar y = weights.getSimdAt(1);
    Scalar other = y / (y - weights.getSimdAt(3));
    Vector closest;
    closest.setInterpolate4(c, d, other);
    r.delta.setSub4(r.point, closest);
    return 0;
}
struct EntryParameter
{
    const S_00dad4d0_Entry* p;
};
// Switches on 4 * f.numA + f.numB to call pointPoint, pointEdge, pointFace, edgePoint, edgeEdge or facePoint; returns 1 for other combinations.
// @fnv 0x00dad990
static __declspec(noinline) int FUN_00dad990(const ContactWork& w, ContactResult& r, EntryParameter entry)
{
    const S_00dad4d0_Entry& f = *entry.p;
    switch (4 * f.numA + f.numB)
    {
    case 0:
        return 1;
    case 5:
        return pointPoint(w, f, r);
    case 6:
        return pointEdge(w, f, r);
    case 7:
        return pointFace(w, f, r);
    case 9:
        return edgePoint(w, f, r);
    case 10:
        return edgeEdge(w, f, r);
    case 13:
        return facePoint(w, f, r);
    default:
        return 1;
    }
}
int probeCaller(const ContactWork& w, ContactResult& r, const S_00dad4d0_Entry* f)
{
    EntryParameter e = {f};
    return FUN_00dad990(w, r, e);
}
