// src/staging/blk_00e20000_od_o2_nood_variant_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00e20000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include <windows.h>

// src/staging/blk_00e20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; } __m128;
extern "C" {
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_mul_ss(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,int);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_set_ss(float);
__m128 _mm_cmpeq_ss(__m128,__m128);
__m128 _mm_andnot_ps(__m128,__m128);
void _mm_store_ss(float*,__m128);
void _ReadWriteBarrier();
}
struct Vertex { __m128 position; __m128 supportA; __m128 supportB; int flags; int unk34; int unk38; int unk3c; };
struct Face;
struct Edge {
    Vertex* vertex;
    Edge* next;
    Edge* opposite;
    Face* face;
};
struct Face {
    __m128 normal;
    Edge edges[3];
    float distance;
    int flags;
    int unk48;
    int unk4c;
    __declspec(noinline) Vertex* ComputePlane();
};
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
static __forceinline __m128 dot3(__m128 a, __m128 b) {
    __m128 v = _mm_mul_ps(a,b);
    return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa), _mm_add_ss(_mm_shuffle_ps(v,v,0x55),v));
}
Vertex* Face::ComputePlane() {
    Vertex* first = edges[0].vertex;
    __m128 a = _mm_sub_ps(first->position,edges[1].vertex->position);
    __m128 b = _mm_sub_ps(edges[1].vertex->position,edges[2].vertex->position);
    __m128 n = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a,a,0xc9),_mm_shuffle_ps(b,b,0xd2)),_mm_mul_ps(_mm_shuffle_ps(a,a,0xd2),_mm_shuffle_ps(b,b,0xc9)));
    __m128 len = dot3(n,n);
    __m128 inv = _mm_rsqrt_ss(len);
    __m128 scale = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248),inv), _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(len,inv),inv)));
    scale = _mm_andnot_ps(_mm_cmpeq_ss(len,_mm_set_ss(DAT_01011d78)), scale);
    normal = n;
    _ReadWriteBarrier();
    normal = _mm_mul_ps(n,_mm_shuffle_ps(scale,scale,0));
    float d;
    _mm_store_ss(&d,dot3(normal,first->position));
    distance = d;
    return first;
}
struct InitEntry { int vertexOffset; int faceOffset; int edgeOffset; };
extern InitEntry DAT_010ed0f0[];
struct Hull {
    int unk00; int unk04; int unk08; int unk0c;
    int faceCount; int unk14; int unk18; int unk1c;
    Vertex vertices[55];
    Face* freeFaces[100];
    Face faces[4];
    void FUN_00e2d440();
};
struct E29Src { int idx[4]; int n; };
struct E29SrcList { E29Src* data; int count; };
struct E29Item { __m128 a; __m128 b; char flag20; int val24; };
struct E29Out1 { E29Item item; void* ptr30; int one34; int zero38; char unk3c; char flag3d; };
struct E29Out2 { E29Item items[4]; int count; char flagC4; void* ptrs[4]; int unkD8; int unkDC; int zeros[4]; int unkF0; };
void FUN_00e29a10(E29SrcList* src, const __m128* posA, const __m128* posB, char* base, E29Out1* out1, int* outCount1, E29Out2* out2, int* outCount2);
inline void* operator new(unsigned int, void* p) { return p; }
struct Router_e3a1 {
    int unk00, unk04, unk08, unk0C;
    void* m_pStreamAllocator;
};
Router_e3a1* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* mem, void* array, int sizeOfElement);
struct __declspec(align(16)) Key_e3a1 {
    float m_ax, m_ay, m_az, m_aw;
    float m_bx, m_by, m_bz, m_bw;
    Key_e3a1* FUN_00e39e50();
};
template <class T> struct hkArray_e3a1 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        Router_e3a1* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
};
struct Track_e3a1 {
    int unk00, unk04;
    int m_numKeys;
    int m_pRayCursor;
    hkArray_e3a1<Key_e3a1> m_keys;
    void FUN_00e3a1e0(int numKeys);
};
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern int DAT_010dbacc, DAT_010dbad8, DAT_010dbae4, DAT_010dbaf8;
extern int DAT_010ccfac, DAT_010ccfa0, DAT_010ccf8c, DAT_010c3bb8;
extern void* DAT_011b3830[];
void __cdecl FUN_00d1bb50(void*, void*, void*, void*, void*, void*, void*, void*, void*, int) throw();
void __cdecl FUN_00d1d490(void*, void*, int, void*, void*, void*) throw();
typedef __m128 FourFloatVector;
__forceinline FourFloatVector packFractions(float x,float y,float z,float w) { FourFloatVector v; v.m128_f32[0]=x; v.m128_f32[1]=y; v.m128_f32[2]=z; v.m128_f32[3]=w; return v; }
struct RaySource {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
};
struct RayBatch {
    RaySource rays[4];
    unsigned type;
    unsigned char flag; unsigned char unkc5; unsigned short unkc6;
    void* filters[4];
    unsigned unkd8, unkdc;
    void* hits[4];
};
struct LocalRay {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
    void* userFilter;
    int one; void* zero;
    unsigned char hit, flag; unsigned short unk3e;
    __forceinline void assign(const RaySource& s) { from=s.from; to=s.to; enable=s.enable; filter=s.filter; }
};
struct RayCollectorBase {
    void* vtable;
    int mode;
    float fraction;
    unsigned char hit; unsigned char unk0d; unsigned short unk0e;
};
struct Collector {
    void* vt0; void* vt1; void* vt2;
    RayCollectorBase ray;
    LocalRay* input; LocalRay* input2;
    void* filter; void* filter2;
    unsigned unk2c;
    FourFloatVector normal;
    FourFloatVector point;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    __forceinline LocalRay* setup(LocalRay* r, const RaySource& source, void* f, int m, unsigned char flag) {
        r->userFilter=f; filter=f; filter2=f;
        r->from=source.from; r->to=source.to;
        r->enable=source.enable; r->filter=source.filter;
        r->flag=flag; r->one=1; r->zero=0;
        input2=r; input=r;
ray.mode=m;         return r;
    }
    __forceinline void init() {
        ray.fraction = 1.0f; vt0 = &DAT_010dbaf8; vt1 = &DAT_010dbae4; vt2 = &DAT_010dbad8; ray.vtable = &DAT_010dbacc;
        unk50 = 0; unk54 = 0; unk60 = 0; ray.hit = 0;
    }
};
struct Bundle {
    FourFloatVector fromX, fromY, fromZ, toX, toY, toZ;
    void* dispatch;
};
struct FractionValues { float x,y,z,w; };
struct FractionArg { FourFloatVector* ptr; };
struct Owner { unsigned unk00, unk04, unk08, unk0c; void* context; };
void __cdecl FUN_00e2b510(Owner* owner, RayBatch* input, int mode, FourFloatVector& fractions);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};
struct ProfRec2
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
};
struct ProfBuf
{
    DWORD unk00;
    char* m_pCur;
    DWORD unk08;
    char* m_pRecordEnd;
};
class ScrapAllocator
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* Alloc(int& aiSize);
    virtual void Free(void* p, unsigned int size);
};
struct ScrapHolder
{
    DWORD unk00, unk04, unk08, unk0C;
    ScrapAllocator* m_pAllocationContext;
};
template <class T> struct ScrapArr
{
    T* m_pData;
    int m_uiLogicalSize;
    unsigned int m_uiCap;
};
class JobTarget
{
public:
    void FUN_00d04380();
};
struct __declspec(align(16)) AutoJob
{
    unsigned char m_cType;
    unsigned char m_c01;
    unsigned char m_c02;
    unsigned char m_c03;
    unsigned short m_sSize;
    short m_s06;
    int unk08;
    int unk0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int unk1C;
    int* m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    float m_f38;
    float m_f3C;
    int m_i40;
    int m_i44;
    int unk48;
    int m_i4C;
    int unk50;
    int m_i54;
    int m_i58;
    JobTarget* m_p5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
};
__forceinline void InitJob(AutoJob& j)
{
    j.m_cType = 7;
    j.m_c01 = 3;
    j.m_c02 = 2;
    j.m_sSize = 0x70;
    j.m_s06 = -1;
    j.m_i10 = 0;
    j.m_i18 = 0;
    j.m_c02 = 1;
    j.m_i14 = 0;
    j.m_i64 = 0;
    j.m_i68 = 0;
}
struct JobSource
{
    DWORD unk00, unk04, unk08, unk0C;
    JobTarget* m_p10;
    int m_i14;
    int unk18;
    int m_i1C;
    int unk20;
    int m_i24;
    int unk28;
    int m_i2C;
    int unk30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
};
class JobQueue
{
public:
    void AddObjectCopy(AutoJob* pJob, int iFlag);
};
class JobWaiter
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Start(JobQueue* m_pPrimaryTaskProcessor, int iType);
    virtual void Wait();
};
struct SplitOut
{
    int unk00, unk04, unk08, unk0C;
};
struct SplitResult
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};
void __cdecl FUN_00e29b80(int a, int b, int n, void* p1, void* p2, void* p3, SplitResult* pOut);
__forceinline void ProfMark(const char* pName)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
        pRec->m_pName = pName;
        { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
pRec->m_iTick = ticks; }
        pBuf->m_pCur = (char*)(pRec + 1);
    }
}
__forceinline void ProfMark2(const char* pName, const char* pName2)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec2* pRec = (ProfRec2*)pBuf->m_pCur;
        pRec->m_pName = pName;
        pRec->m_pName2 = pName2;
        { unsigned int ticks;
__asm {
    rdtsc
    mov dword ptr[ticks], eax
}
pRec->m_iTick = ticks; }
        pBuf->m_pCur = (char*)(pRec + 1);
    }
}
template <class T> __forceinline T* BufAlloc(ScrapAllocator* pAlloc, int& n)
{
    int bytes = n * sizeof(T);
    T* p = (T*)pAlloc->Alloc(bytes);
    n = bytes / (int)sizeof(T);
    return p;
}
template <class T> __forceinline void ArrInit(T*& rData, unsigned int& rCap, int n)
{
    ScrapHolder* pHolder = ((ScrapHolder*)FUN_00c85750());
    ScrapAllocator* pAlloc = pHolder->m_pAllocationContext;
    int cap = n;
    rData = cap ? BufAlloc<T>(pAlloc, cap) : 0;
    rCap = cap ? cap : 0x80000000;
}
template <class T> __forceinline void ArrFree(T* pData, unsigned int uiCap)
{
    ScrapHolder* pHolder = ((ScrapHolder*)FUN_00c85750());
    ScrapAllocator* pAlloc = pHolder->m_pAllocationContext;
    if ((uiCap & 0x80000000) == 0)
        pAlloc->Free(pData, (uiCap & 0x3fffffff) * sizeof(T));
}
template <class T> __forceinline void ArrClearFree(ScrapArr<T>& arr)
{
    ScrapHolder* pHolder = ((ScrapHolder*)FUN_00c85750());
    ScrapAllocator* pAlloc = pHolder->m_pAllocationContext;
    unsigned int cap = arr.m_uiCap;
    arr.m_uiLogicalSize = 0;
    if ((cap & 0x80000000) == 0)
        pAlloc->Free(arr.m_pData, (cap & 0x3fffffff) * sizeof(T));
    arr.m_pData = 0;
    arr.m_uiCap = 0x80000000;
}
void __cdecl FUN_00e2a390(int a, int b, int n, float f1, float f2, JobSource* pSrc, JobQueue* m_pPrimaryTaskProcessor, JobWaiter* pWaiter, int iParam, bool bAuto);
extern "C" __m128 _mm_max_ps(__m128, __m128);
namespace SplineMax {
struct Vec { __m128 value; };
struct Points { Vec* data; int count; int capacity; };
}

typedef ::__m128 S2d6c0_Simd;
namespace S2d6c0_Intrinsics {
using ::_mm_load_ss;
using ::_mm_mul_ps;
using ::_mm_mul_ss;
using ::_mm_add_ss;
using ::_mm_sub_ss;
using ::_mm_shuffle_ps;
using ::_mm_rsqrt_ss;
using ::_mm_set_ss;
using ::_mm_cmpeq_ss;
using ::_mm_andnot_ps;
using ::_mm_store_ss;
extern "C" {
::__m128 (_mm_add_ps)(::__m128, ::__m128);
::__m128 (_mm_load_ps1)(const float*);
}
}

extern "C" double __cdecl sqrt(double) throw();

using ::DAT_01016248;
extern float DAT_0104da48;
extern const float DAT_0104da4c;
extern float DAT_0102295c;
extern double DAT_01012060;

struct S2d6c0_Vector
{
    S2d6c0_Simd m_vComponents;

    __forceinline float dot3(const S2d6c0_Vector& o) const
    {
        S2d6c0_Simd x = (S2d6c0_Intrinsics::_mm_mul_ps)(m_vComponents, o.m_vComponents);
        S2d6c0_Simd r = (S2d6c0_Intrinsics::_mm_add_ss)((S2d6c0_Intrinsics::_mm_shuffle_ps)(x, x, 0xaa), (S2d6c0_Intrinsics::_mm_add_ss)((S2d6c0_Intrinsics::_mm_shuffle_ps)(x, x, 0x55), x));
        float f;
        (S2d6c0_Intrinsics::_mm_store_ss)(&f, r);
        return f;
    }
    __forceinline void setMul4(float s, const S2d6c0_Vector& v)
    {
        m_vComponents = (S2d6c0_Intrinsics::_mm_mul_ps)((S2d6c0_Intrinsics::_mm_load_ps1)(&s), v.m_vComponents);
    }
    __forceinline void addMul4(float s, const S2d6c0_Vector& v)
    {
        m_vComponents = (S2d6c0_Intrinsics::_mm_add_ps)((S2d6c0_Intrinsics::_mm_mul_ps)((S2d6c0_Intrinsics::_mm_shuffle_ps)((S2d6c0_Intrinsics::_mm_load_ss)(&s),(S2d6c0_Intrinsics::_mm_load_ss)(&s),0), v.m_vComponents), m_vComponents);
    }
    __forceinline void normalize3()
    {
        S2d6c0_Simd x = (S2d6c0_Intrinsics::_mm_mul_ps)(m_vComponents, m_vComponents);
        S2d6c0_Simd r = (S2d6c0_Intrinsics::_mm_add_ss)((S2d6c0_Intrinsics::_mm_shuffle_ps)(x, x, 0xaa), (S2d6c0_Intrinsics::_mm_add_ss)((S2d6c0_Intrinsics::_mm_shuffle_ps)(x, x, 0x55), x));
        S2d6c0_Simd e = (S2d6c0_Intrinsics::_mm_rsqrt_ss)(r);
        S2d6c0_Simd ret = (S2d6c0_Intrinsics::_mm_mul_ss)((S2d6c0_Intrinsics::_mm_mul_ss)((S2d6c0_Intrinsics::_mm_set_ss)(0.5f), e),
                                (S2d6c0_Intrinsics::_mm_sub_ss)((S2d6c0_Intrinsics::_mm_set_ss)(3.0f), (S2d6c0_Intrinsics::_mm_mul_ss)((S2d6c0_Intrinsics::_mm_mul_ss)(r, e), e)));
        S2d6c0_Simd inv = (S2d6c0_Intrinsics::_mm_andnot_ps)((S2d6c0_Intrinsics::_mm_cmpeq_ss)(r, (S2d6c0_Intrinsics::_mm_set_ss)(0.0f)), ret);
        m_vComponents = (S2d6c0_Intrinsics::_mm_mul_ps)((S2d6c0_Intrinsics::_mm_shuffle_ps)(inv, inv, 0), m_vComponents);
    }
};

struct S2d6c0_ScalarResult { float value; };
static inline S2d6c0_ScalarResult S2d6c0_sqrt(float x) { S2d6c0_ScalarResult r; r.value=(float)sqrt(x); return r; }



// @fnv 0x00e2d6c0
extern "C" void __cdecl FUN_00e2d6c0(::Hull* a, ::Hull* b, S2d6c0_Vector* out,
                          ::Face** pa, ::Face** pb)
{
    float best = DAT_0104da48;
    float eb = 0.0f;
    float t;
    t = 0.0f;
    for (int i = a->faceCount - 1; i >= 0; i--)
    {
        ::Face* v;
        v = &a->faces[i];
        if (v->distance * v->distance > best)
            continue;
        for (int j = b->faceCount - 1; 1 <= j; j--)
        {
            ::Face* bestS = &b->faces[j];
            if (bestS->distance * bestS->distance > best)
                continue;
            float dot = ((const S2d6c0_Vector&)bestS->normal).dot3((const S2d6c0_Vector&)v->normal);
            if (DAT_0102295c > dot)
                continue;
            float ra = v->distance;
            float rb = bestS->distance;
            float u;
            u = ra - dot * rb;
            float b;
            b = rb - dot * ra;
            float q;
            float d;
            float s;
            if (u > 1.192092896e-07f)
            {
                if (b > 1.192092896e-07f)
                {
                    float x;
                    float y;
                    if (b < u)
                    {
                        float ea = b / u;
                        q = 1.0f / (1.0f + ea * dot);
                        s = q * ea;
                        y = ra / (1.0f + ea * dot);
                        x = ea * y;
                    }
                    else
                    {
                        float ea = u / b;
                        s = 1.0f / (1.0f + ea * dot);
                        q = ea * s;
                        x = rb / (1.0f + ea * dot);
                        y = ea * x;
                    }
                    y = y + dot * x;
                    d = y * y + (1.0f - dot * dot) * x * x;
                }
                else if (rb > 0.0f)
                {
                    q = 1.0f;
                    s = 0.0f;
                    d = ra * ra;
                }
                else
                {
                    goto parallel;
                }
            }
            else if (ra > 1.192092896e-07f)
            {
                q = 0.0f;
                s = 1.0f;
                d = rb * rb;
            }
            else
            {
            parallel:
                q = 0.5f;
                s = 0.5f;
                d = -dot * dot;
            }
            if (d < best)
            {
                eb = q;
                *pa = v;
                t = s;
                *pb = bestS;
                best = d;
            }
        }
    }
    out->setMul4(eb, (const S2d6c0_Vector&)(*pa)->normal);
    out->addMul4(t, (const S2d6c0_Vector&)(*pb)->normal);
    out->normalize3();
    float dd = (0.0 > best) ? 0.0f : best;
    out->m_vComponents.m128_f32[3] = S2d6c0_sqrt(dd).value;
}
