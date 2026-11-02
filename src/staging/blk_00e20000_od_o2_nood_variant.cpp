// staging/blk_00e20000_od_o2_nood_variant.cpp: Face, Hull (8 functions)
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
// @fnv 0x00e2d440
void Hull::FUN_00e2d440() {
    faceCount = 4;
    InitEntry* init = DAT_010ed0f0;
    Face* end = faces + 4;
    for (Face* face = faces; face != end; ++face) {
        face->edges[0].next = &face->edges[1];
        face->edges[1].next = &face->edges[2];
        face->flags = 0;
        face->edges[2].next = &face->edges[0];
        for (Edge* edge = face->edges; edge < face->edges + 3; ++edge) {
            edge->face = face;
            edge->vertex = (Vertex*)((char*)vertices + init->vertexOffset);
            edge->opposite = (Edge*)((char*)&faces[0].edges[0] + init->faceOffset + init->edgeOffset);
            ++init;
        }
    }
    Face* begin = faces;
    Face* last = &faces[3];
    last->ComputePlane();
    float d;
    _mm_store_ss(&d,dot3(_mm_sub_ps(vertices[0].position,vertices[1].position),last->normal));
    if (d > 0.0f) {
        faces[2].edges[0].vertex = &vertices[1];
        faces[1].edges[0].vertex = &vertices[1];
        begin->edges[0].vertex = &vertices[1];
        last->edges[0].vertex = &vertices[0];
        faces[1].edges[1].vertex = &vertices[0];
        begin->edges[2].vertex = &vertices[0];
    }
    Face* face = begin;
    int i = 3;
    do { face->ComputePlane(); ++face; } while (--i >= 0);
}

struct E29Src { int idx[4]; int n; };
struct E29SrcList { E29Src* data; int count; };
struct E29Item { __m128 a; __m128 b; char flag20; int val24; };
struct E29Out1 { E29Item item; void* ptr30; int one34; int zero38; char unk3c; char flag3d; };
struct E29Out2 { E29Item items[4]; int count; char flagC4; void* ptrs[4]; int unkD8; int unkDC; int zeros[4]; int unkF0; };

// @fnv 0x00e29a10
void FUN_00e29a10(E29SrcList* src, const __m128* posA, const __m128* posB, char* base, E29Out1* out1, int* outCount1, E29Out2* out2, int* outCount2)
{
    int n1 = 0;
    int n2 = 0;
    int count = src->count;
    E29Out2* o2 = out2;
    E29Out1* o1 = out1;
    for (int i = 0; i < count; ++i) {
        E29Src* s = &src->data[i];
        int n = s->n;
        if (n == 1) {
            int k = s->idx[0];
            o1->item.a = posA[k];
            o1->item.b = posB[k];
            o1->item.val24 = 0;
            o1->item.flag20 = 0;
            o1->ptr30 = base + k * 0x60;
            o1->one34 = 1;
            o1->zero38 = 0;
            o1->flag3d = 0;
            o1++;
            n1++;
        } else {
            for (int j = 0; j < n; ++j) {
                int k = s->idx[j];
                o2->items[j].a = posA[k];
                o2->items[j].b = posB[k];
                o2->items[j].val24 = 0;
                o2->items[j].flag20 = 0;
                o2->ptrs[j] = base + k * 0x60;
                o2->zeros[j] = 0;
            }
            o2->count = n;
            o2->flagC4 = 0;
            o2++;
            n2++;
        }
    }
    *outCount1 = n1;
    *outCount2 = n2;
}

namespace fnv_00e2ab00 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; } __m128;
extern "C" { __m128 _mm_load_ps(const __m128*); void _mm_store_ps(__m128*,__m128); __m128 _mm_shuffle_ps(__m128,__m128,int); void _ReadWriteBarrier(); }

// @fnv 0x00e2ab00
__m128* FUN_00e2ab00(__m128* src, __m128* out1, __m128* out2) {
    out1[0] = src[0];
    out2[0] = src[1];
    out1[1] = src[3];
    out2[1] = src[4];
    out1[2] = src[6];
    out2[2] = src[7];

    __m128 d0 = src[9];
    _ReadWriteBarrier();
    __m128 a2 = out1[2];
    __m128 a0 = out1[0];
    __m128 d1 = src[10];
    __m128 a1 = out1[1];
    __m128 t2 = _mm_shuffle_ps(a2, d0, 0x44);
    __m128 t1 = _mm_shuffle_ps(a0, a1, 0xEE);
    __m128 t3 = _mm_shuffle_ps(a2, d0, 0xEE);
    __m128 t0 = _mm_shuffle_ps(a0, a1, 0x44);
    out1[0] = _mm_shuffle_ps(t0, t2, 0x88);
    out1[2] = _mm_shuffle_ps(t1, t3, 0x88);
    out1[1] = _mm_shuffle_ps(t0, t2, 0xDD);

    __m128 b0 = out2[0];
    __m128 b1 = out2[1];
    __m128 b2 = out2[2];
    __m128 u0 = _mm_shuffle_ps(b0, b1, 0x44);
    __m128 u1 = _mm_shuffle_ps(b0, b1, 0xEE);
    __m128 u2 = _mm_shuffle_ps(b2, d1, 0x44);
    __m128 u3 = _mm_shuffle_ps(b2, d1, 0xEE);
    out2[0] = _mm_shuffle_ps(u0, u2, 0x88);
    out2[1] = _mm_shuffle_ps(u0, u2, 0xDD);
    out2[2] = _mm_shuffle_ps(u1, u3, 0x88);
    return out1;
}
}  // namespace fnv_00e2ab00

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

// @fnv 0x00e3a1e0
void Track_e3a1::FUN_00e3a1e0(int numKeys)
{
    m_pRayCursor = numKeys;
    m_numKeys = 0;
    for (int i = 0; i < m_pRayCursor; i++) {
        Key_e3a1 key;
        key.FUN_00e39e50();
        m_keys.AddBack(key);
    }
}

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
// @fnv 0x00e2b510
void __cdecl FUN_00e2b510(Owner* owner, RayBatch* input, int mode, FourFloatVector& fractions) {
    if (!owner) return;
    Bundle bundle;
    FUN_00d1bb50(&bundle, &input->rays[0].from, &input->rays[0].to,
        &input->rays[1].from, &input->rays[1].to, &input->rays[2].from,
        &input->rays[2].to, &input->rays[3].from, &input->rays[3].to, 15);
    LocalRay rays[4];
    rays[0].hit=0; rays[1].hit=0; rays[2].hit=0; rays[3].hit=0;
    Collector collectors[4];
    collectors[0].init(); collectors[1].init(); collectors[2].init(); collectors[3].init();
    float values[4];
    RayCollectorBase* pointers[4];
    for (int i = 0; i < 4; i++) {
        rays[i].userFilter = input->filters[i];
        collectors[i].filter = rays[i].userFilter;
        collectors[i].filter2 = rays[i].userFilter;
        rays[i].assign(input->rays[i]);
        rays[i].flag = input->flag;
        rays[i].one = 1;
        rays[i].zero = 0;
        collectors[i].ray.mode = mode;
        collectors[i].input2 = &rays[i];
        collectors[i].input = &rays[i];
        values[i] = fractions.m128_f32[i];
        pointers[i] = &collectors[i].ray;
    }
    bundle.dispatch = DAT_011b3830[input->type];
    FUN_00d1d490(owner, owner->context, 0, &bundle, pointers, values);
    for (int i = 0; i < 4; i++) input->hits[i] = rays[i].zero;
    fractions = _mm_setr_ps(values[0], values[1], values[2], values[3]);
    volatile Collector* p = collectors + 4;
    int n = 3;
    do {
        --p;
        p->ray.vtable = &DAT_010ccfac; p->vt2 = &DAT_010ccfa0;
        p->vt1 = &DAT_010ccf8c; p->vt0 = &DAT_010c3bb8;
    } while (--n >= 0);
}

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

// @fnv 0x00e2a390
void __cdecl FUN_00e2a390(int a, int b, int n, float f1, float f2, JobSource* pSrc,
                          JobQueue* m_pPrimaryTaskProcessor, JobWaiter* pWaiter, int iParam, bool bAuto)
{
    if (bAuto)
    {
        ProfMark2("LtAutoJob", "StAddJobs");
        int off1 = pSrc->m_i24;
        int off2 = pSrc->m_i2C;
        for (int i = 0; i < 8; i++)
        {
            AutoJob job;
            job.m_cType = 7;
            job.m_c01 = 3;
            job.m_sSize = 0x70;
            job.m_s06 = -1;
            job.m_i10 = 0;
            job.m_i18 = 0;
            job.m_c02 = 1;
            job.m_i14 = 0;
            job.m_i20 = (int*)0;
            job.m_i24 = i;
            job.m_i28 = 0;
            job.m_i2C = a;
            job.m_i30 = b;
            job.m_i34 = n;
            job.m_f38 = f1;
            job.m_f3C = f2;
            job.m_i40 = iParam;
            job.m_i44 = off1;
            job.m_i4C = off2;
            job.m_i54 = pSrc->m_i1C;
            job.m_i58 = pSrc->m_i14;
            job.m_p5C = pSrc->m_p10;
            job.m_i60 = pSrc->m_i34;
            job.m_i64 = pSrc->m_i38;
            job.m_i68 = pSrc->m_i3C;
            job.m_i6C = pSrc->m_i40;
            m_pPrimaryTaskProcessor->AddObjectCopy(&job, 1);
            off1 += n << 6;
            off2 += n << 8;
        }
        pWaiter->Start(m_pPrimaryTaskProcessor, 0xb);
        ProfMark("StWaitThreads");
        pWaiter->Wait();
        ProfMark("lt");
        pSrc->m_p10->FUN_00d04380();
        return;
    }

    ProfMark("TtCPUSplit");
    SplitOut* pData1;
    unsigned int uiCap1;
    SplitOut* pData2;
    unsigned int uiCap2;
    ScrapArr<int>* pData3;
    int iSize3;
    unsigned int uiCap3;
    int* pData4;
    unsigned int uiCap4;
    int* pData5;
    unsigned int uiCap5;
    {
    ArrInit(pData1, uiCap1, n);
    ArrInit(pData2, uiCap2, n);
    {
        ScrapHolder* pHolder = ((ScrapHolder*)FUN_00c85750());
        int cap = 8;
        pData3 = cap ? BufAlloc<ScrapArr<int> >(pHolder->m_pAllocationContext, cap) : 0;
        iSize3 = cap;
        uiCap3 = cap ? cap : 0x80000000;
    }
    for (int k = 0; k < iSize3; k++)
    {
        ScrapArr<int>* pElem = &pData3[k];
        if (pElem != 0)
        {
            pElem->m_pData = 0;
            pElem->m_uiLogicalSize = 0;
            pElem->m_uiCap = 0x80000000;
        }
    }
    SplitResult out;
    FUN_00e29b80(a, b, n, pData1, pData2, pData3, &out);
    ArrInit(pData4, uiCap4, 8);
    ArrInit(pData5, uiCap5, 8);

    int off1 = pSrc->m_i24;
    int off2 = pSrc->m_i2C;
    for (int j = 0; j < 8; j++)
    {
        if (pData3[j].m_uiLogicalSize == 0)
            continue;
        {
            AutoJob job;
            InitJob(job);
            job.m_i20 = pData3[j].m_pData;
            job.m_i28 = pData3[j].m_uiLogicalSize;
            job.m_i2C = a;
            job.m_i30 = b;
            job.m_i34 = n;
            job.m_f38 = f1;
            job.m_f3C = f2;
            job.m_i40 = iParam;
            job.m_i44 = off1;
            job.m_i4C = off2;
            job.m_i54 = pSrc->m_i1C;
            job.m_i58 = pSrc->m_i14;
            job.m_p5C = pSrc->m_p10;
            job.m_i60 = pSrc->m_i34;
            job.m_i64 = pSrc->m_i38;
            job.m_i68 = pSrc->m_i3C;
            job.m_i6C = pSrc->m_i40;
            m_pPrimaryTaskProcessor->AddObjectCopy(&job, 1);
            off1 += n << 6;
            off2 += n << 8;
        }
    }
    }
    ProfMark("Et");
    ProfMark("TtAutoBundleJobs");
    pWaiter->Start(m_pPrimaryTaskProcessor, 0xb);
    pWaiter->Wait();
    pSrc->m_p10->FUN_00d04380();
    ProfMark("Et");

    ArrFree(pData5, uiCap5);
    ArrFree(pData4, uiCap4);
    {
        ScrapAllocator* pAlloc = ((ScrapHolder*)FUN_00c85750())->m_pAllocationContext;
        for (int k = 0; k < iSize3; k++)
            ArrClearFree(pData3[k]);
        if ((uiCap3 & 0x80000000) == 0)
            pAlloc->Free(pData3, (uiCap3 & 0x3fffffff) * sizeof(ScrapArr<int>));
    }
    ArrFree(pData2, uiCap2);
    ArrFree(pData1, uiCap1);
}

extern "C" __m128 _mm_max_ps(__m128, __m128);
namespace SplineMax {
struct Vec { __m128 value; };
struct Points { Vec* data; int count; int capacity; };
}
// @fnv 0x00e314c0
SplineMax::Vec __cdecl FUN_00e314c0(const SplineMax::Points& input)
{
    SplineMax::Vec result = input.data[0];
    const int count = input.count;
    for (int i = 1; i < count; ++i)
        result.value = _mm_max_ps(result.value, input.data[i].value);
    return result;
}

namespace S31470_Intrinsics {
extern "C" ::__m128 (_mm_min_ps)(::__m128, ::__m128);
}

struct MinVec4 {
    __m128 m_vComponents;
    void setMin4(const MinVec4& a, const MinVec4& b) { m_vComponents = (S31470_Intrinsics::_mm_min_ps)(a.m_vComponents, b.m_vComponents); }
};
struct MinVec4Array {
    MinVec4* m_data;
    int m_iElementCount;
};
// @fnv 0x00e31470
MinVec4 __cdecl FUN_00e31470(const MinVec4Array& arr)
{
    MinVec4 r = arr.m_data[0];
    for (int i = 1; i < arr.m_iElementCount; i++)
        r.setMin4(r, arr.m_data[i]);
    return r;
}
