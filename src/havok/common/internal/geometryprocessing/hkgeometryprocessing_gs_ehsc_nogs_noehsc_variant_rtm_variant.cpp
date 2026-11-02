
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;
struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};
extern "C" void __cdecl FUN_00dedf10(void*, void*, void*, void*, int, int);
void __cdecl FUN_00dee5f0(void* first, void* second, void* third, void* fourth);
struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float FUN_00dee6b0(int testFlag);
};
extern int DAT_010cd664;
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
AudioHolder* __cdecl FUN_00c85750() throw();
struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};
#include <xmmintrin.h>
#include <math.h>
double __cdecl Atan2(float y, float x);
struct Vector3
{
    float x, y, z;
};
void FUN_00de98c0(const Vector3* v, __m128* out);
class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue()
    {}
    __forceinline VectorComponentValue(const __m128& x) : m_vValue(x)
    {}
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __m128 m_vValue;
};
class hkVector4
{
  public:
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        m_vComponents =
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2))),
                       _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                  _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1))));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2));
        return _mm_add_ss(z, xySum);
    }
    __m128 m_vComponents;
};
struct Interval
{
    VectorComponentValue m_kMinimumCorner;
    VectorComponentValue m_kMaximumCorner;
};
static __forceinline void projectTriangle(const hkVector4* tri, const hkVector4& axis, Interval& out)
{
    out.m_kMaximumCorner = tri[0].dot3(axis);
    out.m_kMinimumCorner = out.m_kMaximumCorner;
    for (int i = 1; i < 3; i++)
    {
        VectorComponentValue d = tri[i].dot3(axis);
        if (d < out.m_kMinimumCorner)
        {
            out.m_kMinimumCorner = d;
        }
        else if (d > out.m_kMaximumCorner)
        {
            out.m_kMaximumCorner = d;
        }
    }
}
static __forceinline bool isSeparatingAxis(const hkVector4* triA, const hkVector4* triB, const hkVector4& axis,
                                           Interval& a, Interval& b)
{
    projectTriangle(triA, axis, a);
    projectTriangle(triB, axis, b);
    return a.m_kMinimumCorner > b.m_kMaximumCorner || a.m_kMaximumCorner < b.m_kMinimumCorner;
}
static __forceinline void calcEdgeAxis(const hkVector4& a0, const hkVector4& a1, const hkVector4& b0,
                                       const hkVector4& b1, hkVector4& axis)
{
    hkVector4 ea;
    ea.setSub4(a1, a0);
    hkVector4 eb;
    eb.setSub4(b1, b0);
    axis.setCross(ea, eb);
}
int __cdecl FUN_00deab10(const hkVector4* triA, const hkVector4* triB);
struct Point4;
extern Point4 DAT_01267e30;
struct __declspec(align(16)) Point4
{
    float x, y, z, w;
    __forceinline Point4()
    {
        *this = DAT_01267e30;
    }
};
extern Point4 DAT_01267e30;
struct VertexArray
{
    Point4* data;
    int size;
    int capacity;
};
struct FourPoints
{
    Point4 x, y, z;
    __forceinline void transpose(const Point4* p)
    {
        _mm_store_ps(&x.x, _mm_setr_ps(p[0].x, p[1].x, p[2].x, p[3].x));
        _mm_store_ps(&y.x, _mm_setr_ps(p[0].y, p[1].y, p[2].y, p[3].y));
        _mm_store_ps(&z.x, _mm_setr_ps(p[0].z, p[1].z, p[2].z, p[3].z));
    }
};
struct FourPointArray
{
    FourPoints* data;
    int size;
    int capacity;
};
void __cdecl FUN_00c908c0(AudioAllocator*, void*, int, int);
void __cdecl FUN_00dedcf0(const VertexArray& vertices, FourPointArray& output);

#include <math.h>
#include <xmmintrin.h>

struct __declspec(align(16)) S_V4
{
    union
    {
        __m128 q;
        float data[4];
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00c7f700(const struct S_Rot* r, const S_V4* v);
    S_V4()
    {}
    S_V4(const S_V4& o)
    {
        _mm_store_ps(&x, _mm_load_ps(&o.x));
    }
    S_V4& operator=(const S_V4& o)
    {
        _mm_store_ps(&x, _mm_load_ps(&o.x));
        return *this;
    }
};

static __forceinline void perpendicular(S_V4& out, const S_V4& src, S_V4& scratch)
{
    float a = fabs(src.x);
    float b = fabs(src.y);
    float c = fabs(src.z);
    int i = 0, j = 1, k = 2;
    if (b < a)
    {
        a = b;
        j = 0;
        i = 1;
    }
    if (c < a)
    {
        k = i;
    }
    _mm_store_ps(&out.x, _mm_setzero_ps());
    out.data[j] = src.data[k];
    out.data[k] = -src.data[j];
    scratch = out;
    __m128 m = _mm_load_ps(&scratch.x);
    __m128 sq = _mm_mul_ps(m, m);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sum);
    float len;
    _mm_store_ss(&len, sum);
    if (len != 0.0f)
    {
        float inv = 1.0f / (float)sqrt(len);
        _mm_store_ps(&out.x, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&inv), _mm_load_ss(&inv), 0), m));
    }
}

struct S_Rot
{
    S_V4 r0;
    S_V4 r1;
    S_V4 r2;
    S_V4 translation;
};

struct S_Body
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    S_V4 velocity;
    S_V4 axis;  // 0xe0
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int type;
};

struct S_Self
{
    int unk00;
    int unk04;
    S_Body* body;
    void FUN_00d76d80(float* diag, S_Rot* rot);
};

struct AxisOwner : S_Self
{
    S_V4 FUN_00d76d90();
};

// @fnv 0x00d76d90
S_V4 AxisOwner::FUN_00d76d90()
{
    S_V4 out;
    _mm_store_ps(&out.x, _mm_setzero_ps());
    S_V4 zero;
    _mm_store_ps(&zero.x, _mm_setzero_ps());
    S_Body* bd = body;
    switch (bd->type)
    {
    case 1: {
        perpendicular(out, bd->velocity, zero);
        break;
    }
    case 2:
        out = bd->axis;
        break;
    case 3: {
        float d[4];
        S_Rot rot;
        FUN_00d76d80(d, &rot);
        int idx;
        if (d[0] < d[1])
            idx = (d[2] > d[0]) ? 0 : 2;
        else
            idx = (d[2] > d[1]) ? 1 : 2;
        S_V4 v;
        v = zero;
        ((float*)&v)[idx] = 1.0f;
        out.FUN_00c7f700(&rot, &v);
        break;
    }
    }
    out.w = 0;
    return out;
}
