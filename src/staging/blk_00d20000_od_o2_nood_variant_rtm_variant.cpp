// src/staging/blk_00d20000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00d20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
}
struct hkVector4
{
    __m128 m_vComponents;

    __forceinline float lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 z = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), y);
        float r;
        _mm_store_ss(&r, z);
        return r;
    }
};
struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};
bool FUN_00d28560(void* unused, char** items, int count, int offset);
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}
struct FinishingFlag
{
    int m_bFinishing;
};
static inline FinishingFlag NotFinishing()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    return flag;
}
class S00d2c8a0_Base
{
  public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class S00d2c8a0_Derived : public S00d2c8a0_Base
{
  public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag)
    {}
    virtual void vf04();
    __m128 m_kScaleFactors;
};
const void* __cdecl FUN_00d2c8a0();
struct SortPair
{
    unsigned int key;
    unsigned int val;
};
// @fnv 0x00d36520
extern "C" void FUN_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;)
    {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do
        {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val))
            {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val))
            {
                --j;
            }
            if (j < i)
            {
                break;
            }
            if (j != i)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j)
        {
            FUN_00d36520(arr, lo, j, extra);
        }
        if (i >= hi)
        {
            break;
        }
        lo = i;
    }
}
struct hkpAgent3FuncsD367
{
    hkpAgent3FuncsD367()
    {
        m_bIsPredictive = false;
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction7 = 0;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};
void __cdecl FUN_00d367b0(hkpAgent3FuncsD367& kFuncs);
class hkpCollisionDispatcherD367
{
  public:
    void AddEntry(const hkpAgent3FuncsD367& kFuncs, int iTypeA, int iTypeB);
};
void __cdecl FUN_00d367d0(hkpCollisionDispatcherD367* pkDispatcher);
struct hkpAgent3FuncsD398
{
    hkpAgent3FuncsD398()
    {
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
        m_pAgentFunction7 = 0;
        m_bIsPredictive = false;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};
class hkpCollisionDispatcherD398
{
  public:
    void AddEntry(const hkpAgent3FuncsD398& kFuncs, int iTypeA, int iTypeB);
};
void InitOutputDefaults();
void FUN_00d39130();
void ReleaseHandles();
void RemoveKeyFromTable();
void InsertIntoSlotArray();
void FUN_00d39090();
void FUN_00d39150();
void FUN_00d39390();
void __cdecl FUN_00d39840(hkpCollisionDispatcherD398* pkDispatcher);
extern "C"
{
    __m128 _mm_set_ps1(float a);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    void _mm_store_ps(float* p, __m128 a);
}
extern "C" double fabs(double);
struct ClosestPointResult
{
    float distSq;
    float s;
    float t;
    float unk0C;
    __m128 p1;
    __m128 p2;
};
static __forceinline void Dot3(float& result, __m128 u, __m128 v)
{
    __m128 m = _mm_mul_ps(u, v);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    _mm_store_ss(&result, _mm_add_ss(z, _mm_add_ss(y, m)));
}
int FUN_00d231b0(const __m128* pa, const __m128* pb, const __m128* pc, const __m128* pd, ClosestPointResult* out);

namespace MoppSimd {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ps1(float);
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ps1(const float*);

    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern float DAT_01016248;
extern MoppSimd::__m128 DAT_010ec7f0;
extern char DAT_010ce8e8[];
extern char DAT_010c41f8[];

struct MoppCastProfRec
{
    const char* name;
    unsigned long tick;
    unsigned long unk08;
};
struct MoppCastProfBuf
{
    unsigned long unk00;
    MoppCastProfRec* cur;
    unsigned long unk08;
    MoppCastProfRec* end;
};
struct MoppCastQuad
{
    union
    {
        MoppSimd::__m128 v;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct MoppCastMatrix
{
    MoppCastQuad col0, col1, col2, translation;
    void FUN_00cb22f0(const MoppCastMatrix*, const MoppCastMatrix*);
};
struct MoppCastVector
{
    MoppCastQuad quad;
    void FUN_004b4ab0(const MoppCastMatrix*, const MoppCastVector*);
};
struct MoppCastBounds
{
    MoppCastQuad min, max;
};
struct MoppCastInner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Eval(const MoppCastMatrix*, float, MoppCastBounds*);
};
struct MoppCastBody
{
    MoppCastInner* shape;
    int unk04;
    MoppCastMatrix* transform;
};
struct MoppCastInput
{
    void* unk00;
    int unk04;
    float tolerance;
    int unk0c;
    MoppCastMatrix transform;
    MoppCastVector direction;
};
struct MoppCastQuery
{
    MoppCastQuad start, end, radius;
    MoppCastInput* input;
    MoppCastBody* a;
    MoppCastBody* b;
    int unk3c;
};
struct MoppCastCollector
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    MoppCastInner* shape;
    float inverse;
    void* unk18;
    float unk1c;
    float unk20;
    int d, e;
    MoppCastQuery* query;
    int unk30;
    void FUN_00da8180(MoppCastQuery*, int, int);
};
static void ProfMark(const char* name)
{
    MoppCastProfBuf* buf = (MoppCastProfBuf*)TlsGetValue(DAT_0126835c);
    if (buf->cur < buf->end)
    {
        MoppCastProfRec* rec = buf->cur;
        rec->name = name;
        _ReadWriteBarrier();
        volatile unsigned long tick = (unsigned long)__rdtsc();
        rec->tick = tick;
        buf->cur = rec + 1;
    }
}
struct MoppCastCastGeometry
{
    MoppCastBounds bounds;
    MoppCastQuery query;
    MoppCastVector direction;
    int unk70;
    int unk74;
    int unk78;
    MoppCastCollector collector;
    MoppCastMatrix relative;
};
// @fnv 0x00d2f0d0
void __cdecl FUN_00d2f0d0(MoppCastBody* a, MoppCastBody* b, MoppCastInput* c, int d, int e)
{
    ProfMark(DAT_010ce8e8);
    MoppCastCastGeometry ls;
    ls.relative.FUN_00cb22f0(b->transform, a->transform);

    a->shape->Eval(&ls.relative, c->tolerance, &ls.bounds);

    ls.direction.FUN_004b4ab0(b->transform, &c->direction);

    float tolerance = c->tolerance;
    MoppSimd::__m128 scalarHalf = MoppSimd::_mm_load_ss(&DAT_01016248);
    MoppSimd::__m128 half = MoppSimd::_mm_shuffle_ps(MoppSimd::_mm_load_ss(&DAT_01016248), scalarHalf, 0);
    (MoppSimd::__m128&)ls.query.start = MoppSimd::_mm_add_ps(
        MoppSimd::_mm_mul_ps(MoppSimd::_mm_sub_ps(DAT_010ec7f0, half), (MoppSimd::__m128&)ls.bounds.min),
        MoppSimd::_mm_mul_ps(half, (MoppSimd::__m128&)ls.bounds.max));
    (MoppSimd::__m128&)ls.query.end =
        MoppSimd::_mm_add_ps((MoppSimd::__m128&)ls.direction.quad, (MoppSimd::__m128&)ls.query.start);
    MoppSimd::__m128 radius = MoppSimd::_mm_add_ps(
        MoppSimd::_mm_mul_ps(MoppSimd::_mm_shuffle_ps(scalarHalf, scalarHalf, 0),
                             MoppSimd::_mm_sub_ps((MoppSimd::__m128&)ls.bounds.max, (MoppSimd::__m128&)ls.bounds.min)),
        MoppSimd::_mm_shuffle_ps(MoppSimd::_mm_load_ss(&tolerance), MoppSimd::_mm_load_ss(&tolerance), 0));
    ls.query.a = a;
    ls.query.b = b;
    (MoppSimd::__m128&)ls.query.radius = radius;
    ls.query.input = c;
    ls.collector.FUN_00da8180(&ls.query, d, e);
    ProfMark(DAT_010c41f8);
}
