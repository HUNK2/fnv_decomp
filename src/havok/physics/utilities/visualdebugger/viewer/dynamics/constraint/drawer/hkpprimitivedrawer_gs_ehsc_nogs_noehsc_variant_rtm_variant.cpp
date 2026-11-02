// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct CpuObject
{
    int value;
    void FUN_00e10a10(int value);
};

#include <xmmintrin.h>

typedef float hkReal;

class __declspec(align(16)) hkVector4
{
  public:
    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_v = v.m_v;
    }
    void setSubMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        __m128 s = _mm_load_ss(&r);
        s = _mm_shuffle_ps(s, s, 0);
        m_v = _mm_sub_ps(a.m_v, _mm_mul_ps(s, b.m_v));
    }
    __m128 m_v;
};

class hkMatrix3
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

class hkDisplayHandlerE10B
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void DisplayLine(const hkVector4& start, const hkVector4& end, int color, int id, int tag);
};

class AxisDisplayOwner
{
  public:
    hkDisplayHandlerE10B* m_handler;
    void FUN_00e10bf0(const hkVector4& pos, const hkMatrix3& rot, hkReal size, int color, int id, int tag);
};

// @fnv 0x00e10bf0
void AxisDisplayOwner::FUN_00e10bf0(const hkVector4& pos, const hkMatrix3& rot, hkReal size, int color, int id, int tag)
{
    hkVector4 x = rot.m_kColumn0;
    hkVector4 y = rot.m_kColumn1;
    hkVector4 z = rot.m_kColumn2;
    hkVector4 start;
    hkVector4 end;
    start.setSubMul4(pos, x, size);
    end.setSubMul4(pos, x, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
    start.setSubMul4(pos, y, size);
    end.setSubMul4(pos, y, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
    start.setSubMul4(pos, z, size);
    end.setSubMul4(pos, z, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
}

extern "C" void _ReadWriteBarrier();
#include <xmmintrin.h>

struct FNV_Allocator
{
    virtual void unk00();
    virtual void unk04();
};
struct FNV_AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FNV_Allocator* m_pAllocator;
};
FNV_AllocHolder* __cdecl FUN_00c85750();
char* __cdecl FUN_00c85690(FNV_Allocator* alloc, int size);
void __cdecl FUN_00c856c0(FNV_Allocator* owner, char* data);

extern __declspec(align(16)) float DAT_010c71e0[4];
extern double DAT_0101ff48;

struct __declspec(align(16)) Quat
{
    float x, y, z, w;
    void FUN_00cb2450(const __m128* axis, float angle);
};

struct Drawer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Line(void* a, void* b, int c, int d, int e);
};

struct VectorArg
{
    __m128* p;
    VectorArg(__m128* v) : p(v)
    {}
    operator __m128*() const
    {
        return p;
    }
};

struct CircleDrawer
{
    Drawer* drawer;
    void FUN_00e10f60(float angle, __m128* base, __m128* a10, VectorArg a14, int count, int a1c, float a20, int a24,
                      int a28);
};

static __forceinline __m128 RotateInitial(const Quat& quat, const __m128& vector)
{
    const __m128& v = vector;
    __m128 q = *(const __m128*)&quat;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(*(const __m128*)DAT_010c71e0, _mm_mul_ps(w, w));
    __m128 scaled = _mm_mul_ps(v, factor);
    __m128 m = _mm_mul_ps(q, v);
    __m128 sumxy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sumxy);
    __m128 d = _mm_shuffle_ps(dot, dot, 0);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(d, q));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 cross = _mm_sub_ps(first, second);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(w, cross));
    return _mm_add_ps(scaled, scaled);
}

static __forceinline __m128 Rotate(const Quat& quat, const __m128& vector)
{
    __m128 v = vector;
    __m128 q = *(const __m128*)&quat;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(*(const __m128*)DAT_010c71e0, _mm_mul_ps(w, w));
    __m128 scaled = _mm_mul_ps(v, factor);
    __m128 m = _mm_mul_ps(q, v);
    __m128 sumxy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sumxy);
    __m128 d = _mm_shuffle_ps(dot, dot, 0);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(d, q));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 cross = _mm_sub_ps(first, second);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(w, cross));
    return _mm_add_ps(scaled, scaled);
}

// @fnv 0x00e10f60
void CircleDrawer::FUN_00e10f60(float angle, __m128* base, __m128* a10, VectorArg a14, int count, int a1c, float a20,
                                int a24, int a28)
{
    FNV_AllocHolder* h = FUN_00c85750();
    FNV_Allocator* allocator = h->m_pAllocator;
    char* buf = FUN_00c85690(allocator, count * 16);
    float r = a20 / angle;
    Quat q1;
    q1.FUN_00cb2450(a14, angle);
    Quat q2;
    float ang2 = (float)(DAT_0101ff48 / (double)count);
    __m128* direction = a10;
    q2.FUN_00cb2450(direction, ang2);
    __m128 v = RotateInitial(q1, *direction);
    __m128* center = base;
    __m128* out = (__m128*)buf;
    for (int i = 0; i < count; i++)
    {
        out[i] = *center;
        _ReadWriteBarrier();
        out[i] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), v), out[i]);
        v = Rotate(q2, v);
    }
    for (int i = 0; i < count; i++)
    {
        drawer->Line(base, buf + i * 16, a1c, a24, a28);
        drawer->Line(buf + i * 16, buf + (((i + 1) % count) * 16), a1c, a24, a28);
    }
    h = FUN_00c85750();
    FUN_00c856c0(h->m_pAllocator, buf);
}

#include <xmmintrin.h>
namespace fnv_00e11180 {
namespace PlaneDrawMath {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}
}

struct PlaneDrawVector
{
    PlaneDrawMath::__m128 m;
    void add(const PlaneDrawVector& a)
    {
        m = PlaneDrawMath::_mm_add_ps(m, a.m);
    }
    PlaneDrawVector& operator=(const PlaneDrawVector& a)
    {
        m = a.m;
        return *this;
    }
};

struct PlaneDrawQuaternion
{
    float x, y, z, w;
    void FUN_00cb2450(int p2, float angle);
};

struct PlaneDrawTarget
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void edge(const PlaneDrawVector* a, const PlaneDrawVector* b, int p4, int p6, int p7);
};

static inline PlaneDrawMath::__m128 PlaneDrawDot3(PlaneDrawMath::__m128 t)
{
    PlaneDrawMath::__m128 a = PlaneDrawMath::_mm_shuffle_ps(t, t, 0x55);
    a = PlaneDrawMath::_mm_add_ss(a, t);
    PlaneDrawMath::__m128 b = PlaneDrawMath::_mm_shuffle_ps(t, t, 0xaa);
    return PlaneDrawMath::_mm_add_ss(b, a);
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
extern const PlaneDrawMath::__m128 DAT_010c71e0;
extern const float DAT_01064f60;
extern const float DAT_0101ff38;
extern const double DAT_010eacc0;

static __forceinline PlaneDrawMath::__m128 PlaneDrawRotate(PlaneDrawMath::__m128 q, PlaneDrawMath::__m128 p)
{
    PlaneDrawMath::__m128 nh = DAT_010c71e0;
    PlaneDrawMath::__m128 qw = PlaneDrawMath::_mm_shuffle_ps(q, q, 0xff);
    PlaneDrawMath::__m128 factor = PlaneDrawMath::_mm_add_ps(nh, PlaneDrawMath::_mm_mul_ps(qw, qw));
    PlaneDrawMath::__m128 sum = PlaneDrawMath::_mm_mul_ps(p, factor);
    PlaneDrawMath::__m128 dot = PlaneDrawDot3(PlaneDrawMath::_mm_mul_ps(q, p));
    dot = PlaneDrawMath::_mm_shuffle_ps(dot, dot, 0);
    sum = PlaneDrawMath::_mm_add_ps(sum, PlaneDrawMath::_mm_mul_ps(dot, q));
    PlaneDrawMath::__m128 cp0 =
        PlaneDrawMath::_mm_mul_ps(PlaneDrawMath::_mm_shuffle_ps(q, q, 0xc9), PlaneDrawMath::_mm_shuffle_ps(p, p, 0xd2));
    PlaneDrawMath::__m128 cp1 =
        PlaneDrawMath::_mm_mul_ps(PlaneDrawMath::_mm_shuffle_ps(q, q, 0xd2), PlaneDrawMath::_mm_shuffle_ps(p, p, 0xc9));
    PlaneDrawMath::__m128 cross = PlaneDrawMath::_mm_sub_ps(cp0, cp1);
    sum = PlaneDrawMath::_mm_add_ps(sum, PlaneDrawMath::_mm_mul_ps(qw, cross));
    return PlaneDrawMath::_mm_add_ps(sum, sum);
}

struct PlaneDrawObject : CpuObject
{
    void FUN_00e11180(const PlaneDrawVector* p1, int p2, const PlaneDrawVector* p3, int p4, float p5, int p6, int p7);
    void FUN_00e10d50(const PlaneDrawVector* p1, int p2, const PlaneDrawVector* v, int p4, float p5, int p6, int p7);
};

// @fnv 0x00e11180
void PlaneDrawObject::FUN_00e11180(const PlaneDrawVector* p1, int p2, const PlaneDrawVector* p3, int p4, float p5,
                                   int p6, int p7)
{
    float s = (float)((double)p5 * DAT_010eacc0);
    PlaneDrawVector L;
    PlaneDrawVector P1v;
    PlaneDrawMath::__m128 t = PlaneDrawMath::_mm_load_ss(&s);
    PlaneDrawMath::__m128 splat = PlaneDrawMath::_mm_shuffle_ps(t, t, 0);
    *(PlaneDrawMath::__m128*)&L = PlaneDrawMath::_mm_mul_ps(splat, *(const PlaneDrawMath::__m128*)p3);
    PlaneDrawQuaternion D1;
    D1.FUN_00cb2450(p2, DAT_0101ff38);
    PlaneDrawQuaternion D2;
    D2.FUN_00cb2450(p2, DAT_01064f60);

    L.m = PlaneDrawRotate(*(PlaneDrawMath::__m128*)&D2, L.m);
    P1v.m = p1->m;
    PlaneDrawVector A[4];
    for (int i = 0; i < 4; ++i)
    {
        A[i] = P1v;
        A[i].add(L);
        L.m = PlaneDrawRotate(*(PlaneDrawMath::__m128*)&D1, L.m);
    }

    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[0], &A[1], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[1], &A[2], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[2], &A[3], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[3], &A[0], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[0], &A[2], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[1], &A[3], p4, p6, p7);
    }

    PlaneDrawMath::__m128 ll = *(const PlaneDrawMath::__m128*)&L;
    PlaneDrawMath::__m128 sq2 = PlaneDrawMath::_mm_mul_ps(ll, ll);
    PlaneDrawMath::__m128 dot = PlaneDrawDot3(sq2);
    PlaneDrawMath::__m128 r = dot;
    r = PlaneDrawMath::_mm_rsqrt_ss(r);
    PlaneDrawMath::__m128 mask = PlaneDrawMath::_mm_cmpeq_ss(dot, PlaneDrawMath::_mm_set_ss(DAT_01011d78));
    PlaneDrawMath::__m128 dr = PlaneDrawMath::_mm_mul_ss(PlaneDrawMath::_mm_mul_ss(dot, r), r);
    PlaneDrawMath::__m128 t3 = PlaneDrawMath::_mm_sub_ss(PlaneDrawMath::_mm_set_ss(DAT_01017718), dr);
    PlaneDrawMath::__m128 scale =
        PlaneDrawMath::_mm_mul_ss(PlaneDrawMath::_mm_mul_ss(PlaneDrawMath::_mm_set_ss(DAT_01016248), r), t3);
    PlaneDrawMath::__m128 sel = PlaneDrawMath::_mm_andnot_ps(mask, scale);
    PlaneDrawMath::__m128 spl = sel;
    spl = PlaneDrawMath::_mm_shuffle_ps(spl, sel, 0);
    *(PlaneDrawMath::__m128*)&L = PlaneDrawMath::_mm_mul_ps(spl, ll);

    this->FUN_00e10d50(p1, p2, &L, p4, p5, p6, p7);
}
}  // namespace fnv_00e11180
