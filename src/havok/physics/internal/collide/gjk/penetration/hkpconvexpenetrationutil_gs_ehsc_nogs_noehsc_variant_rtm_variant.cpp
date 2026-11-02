// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
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
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};
struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};
struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void FUN_00e2d440();
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};
struct FUN_00df9c40_Obj
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6C;

    void PushVectorTriple(const __m128* src);
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern const __m128 DAT_010c44d0;
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);
class hkMatrix3DF9B;
struct hkVector4DF9B
{
    __m128 m_vComponents;

    hkVector4DF9B()
    {}
    hkVector4DF9B(const hkVector4DF9B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4DF9B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b);
    void setSub4(const hkVector4DF9B& a, const hkVector4DF9B& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setNeg4(const hkVector4DF9B& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void _setTransformedPos(const struct hkTransformDF9B& t, const hkVector4DF9B& b);
};
class hkMatrix3DF9B
{
  public:
    __forceinline void SetMulInverse(const hkMatrix3DF9B& kA, const hkMatrix3DF9B& kB)
    {
        hkMatrix3DF9B kATrans;
        kATrans.m_kColumn0 = kA.m_kColumn0;
        kATrans.m_kColumn1 = kA.m_kColumn1;
        kATrans.m_kColumn2 = kA.m_kColumn2;
        kATrans.transpose();
        for (int i = 0; i < 3; i++)
        {
            hkVector4DF9B kCol = kB.getColumn(i);
            getColumn(i)._setRotatedDir(kATrans, kCol);
        }
    }

    hkVector4DF9B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4DF9B& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4DF9B m_kColumn0;
    hkVector4DF9B m_kColumn1;
    hkVector4DF9B m_kColumn2;
};
__forceinline void hkVector4DF9B::_setRotatedDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4DF9B::_setRotatedInverseDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b)
{
    hkVector4DF9B kC0 = r.m_kColumn0;
    hkVector4DF9B kC1 = r.m_kColumn1;
    hkVector4DF9B kC2 = r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(kC0.m_vComponents, kC1.m_vComponents);
    const __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(kC0.m_vComponents, kC1.m_vComponents), kC2.m_vComponents, 0xe4);
    kC0.m_vComponents = _mm_movelh_ps(tmp, kC2.m_vComponents);
    tmp = _mm_movehl_ps(kC0.m_vComponents, tmp);
    kC1.m_vComponents = _mm_shuffle_ps(tmp, kC2.m_vComponents, 0xd4);
    kC2.m_vComponents = ctmp;
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), kC0.m_vComponents);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), kC1.m_vComponents);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), kC2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
struct hkTransformDF9B
{
    hkMatrix3DF9B m_rotation;
    hkVector4DF9B m_vTranslation;
};
__forceinline void hkVector4DF9B::_setTransformedPos(const hkTransformDF9B& t, const hkVector4DF9B& b)
{
    const __m128 r0 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), t.m_rotation.m_kColumn0.m_vComponents);
    const __m128 r1 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), t.m_rotation.m_kColumn1.m_vComponents);
    const __m128 r2 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), t.m_rotation.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}
struct hkVector4StoreDF9B
{
    __declspec(align(16)) float m_v[4];

    void operator=(const hkVector4DF9B& v)
    {
        _mm_store_ps(m_v, v.m_vComponents);
    }
    operator const hkVector4DF9B&() const
    {
        return *reinterpret_cast<const hkVector4DF9B*>(m_v);
    }
};
struct hkpCdVertexPairDF9B
{
    hkVector4DF9B m_vContactPosition;
    hkVector4DF9B m_kVertexA;
    hkVector4DF9B m_kVertexB;
};
class hkpConvexShapeDF9B
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void GetSupportPoint(const hkVector4DF9B& kDirection, hkVector4DF9B& kSupportOut) const = 0;
};
class hkpMinkowskiDF9B
{
  public:
    void FUN_00df9b50(const hkVector4DF9B& kDirection, hkpCdVertexPairDF9B& kOut) const;

    hkTransformDF9B m_kTransform;
    unsigned int unk40, unk44, unk48, unk4C, unk50;
    const hkpConvexShapeDF9B* m_pShapeA;
    const hkpConvexShapeDF9B* m_pShapeB;
};
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);
struct __declspec(align(16)) S00df9ef0_Vec4
{
    float x;
    float y;
    float z;
    float w;
};
template <class T> struct S00df9ef0_Pad
{
    T* m_p;
    __forceinline T* val() const
    {
        return m_p;
    }
    __forceinline T* operator->() const
    {
        return m_p;
    }
};
struct S00df9ef0_Hit
{
    S00df9ef0_Vec4 a;
    S00df9ef0_Vec4 b;
    S00df9ef0_Vec4 c;
    int d;
};
struct S00df9ef0_Obj
{
    void FUN_00df9b50(const S00df9ef0_Vec4* in, S00df9ef0_Vec4* out);

    void FUN_00df9ef0(S00df9ef0_Vec4* p, S00df9ef0_Pad<S00df9ef0_Vec4> r, S00df9ef0_Hit* q, S00df9ef0_Pad<float> outF);
};
static float S00df9ef0_Dot3(__m128 v)
{
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s1);
    float f;
    _mm_store_ss(&f, s);
    return f;
}
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" int _mm_movemask_ps(__m128 a);
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
struct Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const Vec4* m_p0;
    int unk14;
    int unk18;
    int unk1C;
    const Vec4* m_p1;
    int unk24;
    int unk28;
    int unk2C;
    const Vec4* m_p2;
};
struct Edges
{
    Vec4 e0;
    Vec4 e1;
    Vec4 e2;
};
struct Result4 : Vec4
{
    __declspec(noalias) void FUN_004b4ab0(const Edges* edges, const Tri* tri);
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_iThirdValue;
    int m_10;
    int FUN_00dfb040(const Tri* tri, const Vec4* pos, int* outA, int* outB);
    int FUN_00e2d1b0(int a, int b, const Vec4* pos);
};
struct Tester
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    Vec4 m_40;
    int FUN_00df9c90(Shape* shape, const Tri* tri, const Vec4* pos, int* result);
};

extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _ReadWriteBarrier();
#include <math.h>
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" double fabs(double);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_set_ss(float);
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_01268380;
extern const __m128 DAT_01017d10;
extern const __m128 DAT_010ec7f0;
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
extern const double DAT_010c9300;
extern const int DAT_01267e30;
void __cdecl FUN_00cd7530(const void* g, void* a, void* b, void* c, void* out);

struct Scalar
{
    __m128 v;
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, v);
        return f;
    }
};
struct Vector
{
    union
    {
        __m128 v;
        float f[4];
    };
    __forceinline void operator=(const Vector& b)
    {
        v = b.v;
    }
    __forceinline void sub(const Vector& a, const Vector& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    __forceinline Scalar dot(const Vector& b) const
    {
        __m128 t = _mm_mul_ps(v, b.v);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t);
        Scalar s;
        s.v = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), xy);
        return s;
    }
    __forceinline Scalar sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
        Scalar s;
        s.v = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), xy);
        return s;
    }
    __forceinline void cross(const Vector& a, const Vector& b)
    {
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));
        v = _mm_sub_ps(x, y);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 len = dot(*this).v;
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 inv = _mm_rsqrt_ss(len);
        __m128 factor = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, inv), inv)));
        factor = _mm_andnot_ps(eq, factor);
        v = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), v);
    }
};
struct Support
{
    Vector c, a, b;
    int flag;
};
struct Output
{
    Vector direction, point;
    float distance;
};
struct Host
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Vector v30;
    float f40;
    int unk44;
    int unk48;
    int unk4c;
    float thresh;
    int unk54;
    int unk58;
    int unk5c;
    Vector* mat;
    int unk64;
    Vector* pts;
    int feat;
    void FUN_00df9b50(const Vector* direction, Support* support);
    void PushVectorTriple(const Support* support);
    void FUN_00df9ef0(const Vector* direction, const Vector* point, Support* support, float* distance);
    int FUN_00df9fe0(Output* out, int* pfeat);
};

static inline float absScalar(float v)
{
    return fabsf(v);
}
static __forceinline void makePerp(const Vector& edge, Vector& perp)
{
    int idx = 0, other = 1, sel = 2;
    float a0 = absScalar(edge.f[0]);
    float a1 = absScalar(edge.f[1]);
    float a2 = absScalar(edge.f[2]);
    if (a1 < a0)
    {
        other = 0;
        idx = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        sel = idx;
        idx = 2;
    }
    perp.v = _mm_setzero_ps();
    perp.f[other] = edge.f[sel];
    perp.f[sel] = -edge.f[other];
}
// @fnv 0x00df9fe0
int Host::FUN_00df9fe0(Output* out, int* pfeat)
{
    const Vector* point;
    int best = -1;
    Vector normal, initial, scratch;
    Support support, support2;
    switch (feat)
    {
    case 0:
        goto stage0;
    case 1:
        goto stage1;
    case 2:
        goto stage2;
    case 3:
        goto stage3;
    case 4:
        goto stage4;
    default:
        goto failedDefault;
    }
stage4: {
    Vector e1, e2, d;
    e1.sub(pts[0], pts[1]);
    e2.sub(pts[1], pts[2]);
    normal.cross(e1, e2);
    float len = normal.dot(normal);
    d.sub(pts[3], pts[0]);
    float dot = normal.dot(d);
    float prod = thresh * len;
    if (dot * dot <= prod)
    {
        if (best < 3)
        {
            feat = 3;
            goto stage3;
        }
        *pfeat = 3;
        _ReadWriteBarrier();
        return 1;
    }
    *pfeat = 0;
    _ReadWriteBarrier();
    return 0;
}
stage3: {
    Vector e1, e2;
    e1.sub(pts[0], pts[1]);
    e2.sub(pts[1], pts[2]);
    normal.cross(e1, e2);
    float len = normal.dot(normal);
    if (len == 0.0f)
    {
        int two = 2;
        if (best < two)
        {
            feat = two;
            goto stage2;
        }
        goto outLine;
    }
    goto triangleSupport;
}
stage2: {
    Vector e;
    e.sub(pts[0], pts[1]);
    float len = e.dot(e);
    if (!(len <= thresh))
        goto lineSupport;
}
    if (best < 1)
    {
        feat = 1;
        goto stage1;
    }
    *pfeat = 3;
    return 1;
stage1: {
    point = pts;
    float len = point[0].dot(point[0]);
    if (!(len <= thresh))
        goto pointSupport;
}
    if (best < 0)
    {
        feat = 0;
        goto stage0;
    }
    *pfeat = 3;
    return 1;
stage0: {
    Scalar simdLen = v30.dot(v30);
    _ReadBarrier();
    float lv = simdLen;
    {
        __m128 mask = DAT_010c44d0;
        __m128 v = v30.v;
        initial.v = _mm_xor_ps(v, mask);
    }
    if (lv <= thresh)
        initial.v = DAT_01268380;
    FUN_00df9b50(&initial, &support);
    PushVectorTriple(&support);
    point = pts;
    float nextLen = point[0].dot(point[0]);
    if (nextLen <= thresh)
        goto outPoint;
    best = 0;
    goto stage1;
}
pointSupport: {
    point = pts;
    best = 1;
    FUN_00df9b50(point, &support2);
    Vector delta, negative;
    delta.sub(support2.c, pts[0]);
    float distance = delta.dot(delta);
    negative.v = _mm_xor_ps(point->v, DAT_010c44d0);
    FUN_00df9b50(&negative, &support);
    Vector delta2;
    delta2.sub(support.c, pts[0]);
    float distance2 = delta2.dot(delta2);
    if (distance >= distance2)
    {
        PushVectorTriple(&support2);
        goto stage2;
    }
    PushVectorTriple(&support);
    goto stage2;
}
lineSupport: {
    Vector perp, second;
    scratch.sub(pts[0], pts[1]);
    best = 2;
    makePerp(scratch, perp);
    second.cross(scratch, perp);
    perp.normalize();
    second.normalize();
    float d1, d2;
    FUN_00df9ef0(&perp, pts, &support, &d1);
    FUN_00df9ef0(&second, pts, &support2, &d2);
    if (d1 > d2)
    {
        PushVectorTriple(&support);
        goto stage3;
    }
    PushVectorTriple(&support2);
    goto stage3;
}
triangleSupport: {
    best = 3;
    normal.normalize();
    float distance;
    FUN_00df9ef0(&normal, pts, &support, &distance);
    if (distance < f40)
        goto outTriangle;
    PushVectorTriple(&support);
    goto stage4;
}
outPoint: {
    const Vector* finalPoint = pts;
    Scalar len;
    len.v = _mm_sqrt_ss(finalPoint[0].dot(finalPoint[0]).v);
    out->distance = len;
    out->direction = initial;
    out->point = support.a;
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
outLine: {
    out->distance = 0.0f;
    Vector edge;
    edge.sub(pts[0], pts[1]);
    makePerp(edge, out->direction);
    out->direction.normalize();
    Vector ab;
    ab.v = _mm_and_ps(pts[0].v, DAT_01017d10);
    float s = ab.sum(), u = ab.sum();
    float t = s / (s + u + DAT_010c9300);
    __m128 ts = _mm_load_ss(&t);
    ts = _mm_shuffle_ps(ts, ts, 0);
    out->point.v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, ts), mat[0].v), _mm_mul_ps(mat[1].v, ts));
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
outTriangle: {
    out->distance = 0.0f;
    out->direction = normal;
    FUN_00cd7530(&DAT_01267e30, pts, &pts[1], &pts[2], &scratch);
    __m128 c0 = _mm_load_ss(&scratch.f[0]);
    __m128 c1, c2;
    {
        float y = scratch.f[1];
        c1 = _mm_load_ss(&y);
    }
    {
        float z = scratch.f[2];
        c2 = _mm_load_ss(&z);
    }
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0), mat[1].v);
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(c0, c0, 0), mat[0].v);
    __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0), mat[2].v);
    out->point.v = _mm_add_ps(_mm_add_ps(t1, t0), t2);
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
failedDefault:
    *pfeat = 3;
    return 1;
}
