
// src/havok/physics/collide/shape/deprecated/multisphere/hkpmultisphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/multisphere/hkpmultisphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMultiSphereShape.h"

class FnvShapeGetter : public hkpSphereRepShape
{
  public:
    hkInt32 unk10;
    hkInt32 FUN_00d2a5f0();
};

// @fnv 0x00d2a5f0
hkInt32 FnvShapeGetter::FUN_00d2a5f0()
{
    return unk10;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01268910;

class hkStatisticsCollectorD2A6;

class hkReferencedObjectD2A6
{
  public:
    virtual ~hkReferencedObjectD2A6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90360(hkStatisticsCollectorD2A6* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const;
};

class hkObjectD2A6 : public hkReferencedObjectD2A6
{
  public:
    void FUN_00d2a600(hkStatisticsCollectorD2A6* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const;
};

// @fnv 0x00d2a600
void hkObjectD2A6::FUN_00d2a600(hkStatisticsCollectorD2A6* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const
{
    FUN_00c90360(pkCollector, &g_01268910);
}

extern int DAT_010ce4bc;

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

struct FUN_00d2a760
{
    void* m_ppVirtualMethodTable;
    short unk04;
    short m_iObjectReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kSpheres[8];

    FUN_00d2a760(const hkVector4* spheres, int count);
};

// @fnv 0x00d2a760
FUN_00d2a760::FUN_00d2a760(const hkVector4* spheres, int count)
{
    m_iObjectReferenceCount = 1;
    m_ulUserData = 0;
    m_type = 0x15;
    m_ppVirtualMethodTable = &DAT_010ce4bc;
    for (int i = 0; i < count; ++i)
        *(__m128*)&m_kSpheres[i] = *(const __m128*)&spheres[i];
    m_iSphereCount = count;
}

extern "C" __m128 _mm_set_ps(float, float, float, float);

extern "C" __m128 _mm_setr_ps(float, float, float, float);

extern "C" __m128 _mm_load_ps1(const float*);

extern "C" __m128 _mm_move_ss(__m128, __m128);

extern "C" __m128 _mm_load_ss(const float*);

extern "C" __m128 _mm_set_ps1(float);

extern "C" __m128 _mm_set_ss(float);

extern "C" __m128 _mm_load_ps(const float*);

extern "C" __m128 _mm_add_ps(__m128, __m128);

extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C" __m128 _mm_mul_ps(__m128, __m128);

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) Ray
{

    __m128 from;

    __m128 to;
};

struct __declspec(align(16)) Out
{

    __m128 normal;

    float fraction;

    int sphereId;

    int unk18;

    int unk1C;

    int keys[8];

    int keyIndex;
};

struct __declspec(align(16)) Sph
{

    float x, y, z, w;
};

extern __m128 DAT_010ec7f0;

// Finds the smallest fraction in fracs, writes the interpolated and scaled normal and sphere id into out, and returns the best index or -1.
// @fnv 0x00d2a610
static __declspec(noinline) int FUN_00d2a610(Out* out, const Sph* spheres, const float* fracs, const int* ids,
                                             int count, const Ray* ray)

{

    float best = out->fraction;

    int bestIdx = -1;

    int i = 0;

    for (; i < count; ++i)
    {

        if (fracs[i] < best)
        {

            best = fracs[i];

            bestIdx = i;
        }
    }

    if (bestIdx != -1)
    {

        out->keys[out->keyIndex] = -1;

        int id = ids[bestIdx];

        out->fraction = best;

        const Sph* base = spheres;

        __m128 t = _mm_load_ss(&best);
        t = _mm_shuffle_ps(t, t, 0);

        __m128 one = DAT_010ec7f0;

        __m128 center = _mm_load_ps(&base[id].x);

        __m128 n = _mm_add_ps(

            _mm_mul_ps(_mm_sub_ps(ray->from, center), _mm_sub_ps(one, t)),

            _mm_mul_ps(_mm_sub_ps(ray->to, center), t));

        out->normal = n;

        float invR = 1.0f / base[id].w;

        __m128 inv = _mm_load_ss(&invR);

        __m128 scaled = _mm_mul_ps(n, _mm_shuffle_ps(inv, inv, 0));

        out->normal = scaled;

        out->sphereId = id;

        return bestIdx;
    }

    return bestIdx;
}

extern "C" Out* d2a610_out();

extern "C" Sph* d2a610_sph();

extern "C" float* d2a610_fracs();

extern "C" int* d2a610_ids();

extern "C" int d2a610_count();

extern "C" Ray* d2a610_ray();

extern "C" void d2a610_sink(int);

void d2a610_caller()

{

    int r = FUN_00d2a610(d2a610_out(), d2a610_sph(), d2a610_fracs(), d2a610_ids(), d2a610_count(), d2a610_ray());

    d2a610_sink(r);
}

struct FUN_00d2a920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iSphereCount;
    char pad14[0xC];
    hkVector4 m_kSpheres[8];
    hkVector4* CopySpheres(hkVector4* dst);
};

// Copies m_iSphereCount hkVector4 entries from m_kSpheres into dst using 128-bit moves and returns dst.
// @fnv 0x00d2a920
hkVector4* FUN_00d2a920::CopySpheres(hkVector4* dst)
{

    for (int i = 0; i < m_iSphereCount; ++i)
    {
        *reinterpret_cast<__m128*>(dst + i) = *reinterpret_cast<__m128*>(m_kSpheres + i);
    }
    return dst;
}

struct RayCtx
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

class S00d2ab90_Shape : public hkpSphereRepShape
{
  public:
    void* m_disp;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kSpheres[8];
    char* FUN_00d2ab90(char* ok, RayCtx* in, void* p3);
};

static void* s00d2ab90_addr[10];
static void* s00d2ab90_sink;
void D2abExternCall();

static __declspec(noinline) void* FUN_00d2a960(RayCtx* outB, RayCtx* in, hkVector4* spheres, void* owner, RayCtx* outA)
{
    s00d2ab90_sink = outB;
    s00d2ab90_addr[0] = (void*)&in;
    s00d2ab90_addr[1] = (void*)&spheres;
    s00d2ab90_addr[2] = (void*)&owner;
    s00d2ab90_addr[3] = (void*)&outA;
    return outB;
}

static __declspec(noinline) int FUN_00d2a610(hkVector4* spheres, RayCtx* keyB, RayCtx* keyA, void* r, RayCtx* in,
                                             void* extra)
{
    s00d2ab90_addr[4] = (void*)&spheres;
    s00d2ab90_addr[5] = (void*)&keyB;
    s00d2ab90_addr[6] = (void*)&keyA;
    s00d2ab90_addr[7] = (void*)&r;
    s00d2ab90_sink = in;
    for (int i = 0; i < 4; i++)
    {
        D2abExternCall();
        ((int*)extra)[i] = i;
    }
    return (int)r;
}

// Performs a raycast against m_kSpheres using in and p3, storing whether a hit was found in *ok and returning ok.
// @fnv 0x00d2ab90
char* S00d2ab90_Shape::FUN_00d2ab90(char* ok, RayCtx* in, void* p3)
{
    RayCtx keys[2];
    void* r = FUN_00d2a960(&keys[0], in, m_kSpheres, m_disp, &keys[1]);
    int v = FUN_00d2a610(m_kSpheres, &keys[1], &keys[0], r, in, p3);
    *ok = (v != -1);
    return ok;
}

#include <math.h>

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010ce4f0[];
extern const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

struct Sph_Mon
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct Sph_V
{
    float x, y, z, w;
};
struct Sph_Seg
{
    Sph_V a;
    Sph_V b;
};
union Sph_U
{
    Sph_V v;
    __m128 q;
};

static inline __m128 Sph_sum3(__m128 t)
{
    return _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
}

// Finds all spheres in an array that the segment intersects, storing their indices and normalized hit parameters, and returns the count.
// @fnv 0x00d2a960
static __declspec(noinline) int FUN_00d2a960(const Sph_Seg* seg, const Sph_V* spheres, int n, int* apHitIndices,
                                             float* apHitParams)
{
    union
    {
        int count;
        volatile unsigned int tick;
    } hitCounter;
    {
        Sph_Mon* m = (Sph_Mon*)TlsGetValue(DAT_0126835c);
        char* p = m->cur;
        if (p < m->end)
        {
            *(const char**)p = str_010ce4f0;
            _ReadWriteBarrier();
            hitCounter.tick = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = hitCounter.tick;
            m->cur = p + 12;
        }
    }
    union
    {
        float A;
        volatile unsigned int tick;
    } scratch;
    hitCounter.count = 0;
    for (int i = 0; i < n; i++)
    {
        Sph_U e, s, c;
        e.v = seg->b;
        s.v = seg->a;
        c.q = *(const __m128*)&spheres[i];
        __m128 d2 = _mm_sub_ps(e.q, c.q);
        s.q = _mm_sub_ps(s.q, c.q);
        c.q = _mm_mul_ps(s.q, s.q);
        __m128 d1 = _mm_sub_ps(d2, s.q);
        float C;
        _mm_store_ss(&C, Sph_sum3(c.q));
        float B;
        _mm_store_ss(&B, Sph_sum3(_mm_mul_ps(d1, s.q)));
        float B2 = B + B;
        if (B2 >= 0.0f)
            continue;
        _mm_store_ss(&scratch.A, Sph_sum3(_mm_mul_ps(d1, d1)));
        float q = spheres[i].w * spheres[i].w;
        float cc = C - q;
        float disc = B2 * B2 - cc * (scratch.A * 4.0f);
        if (disc <= 0.0f)
            continue;
        float sq = (float)sqrt(disc);
        float tn = -B2 - sq;
        float t = tn * 0.5f;
        if (t >= scratch.A)
            continue;
        if (t < 0.0f)
            continue;
        apHitParams[hitCounter.count] = t / scratch.A;
        apHitIndices[hitCounter.count] = i;
        hitCounter.count++;
    }
    {
        Sph_Mon* m = (Sph_Mon*)TlsGetValue(DAT_0126835c);
        char* p = m->cur;
        if (p < m->end)
        {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            scratch.tick = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = scratch.tick;
            m->cur = p + 12;
        }
    }
    return hitCounter.count;
}

int Sph_caller(const Sph_Seg* seg, const Sph_V* spheres, int n, int* a, float* b)
{
    return FUN_00d2a960(seg, spheres, n, a, b);
}

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkReal m_rayEnforcement;
    hkUint32 m_uiFilterInfo;
};

struct hkMotionState
{
    hkTransform m_kMotionTransform;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    hkUint32 m_uiCollisionShapeKey;
    const hkMotionState* m_kMotionState;
    const hkpCdBody* m_parent;
};

struct ShapeRayCastOutput
{
    union
    {
        hkVector4 m_vHitNormal;
        __m128 m_vComponents;
    };
    hkReal m_fHitFraction;
    int m_iExtraInfo;
    int unk18[2];
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    ShapeRayCastOutput()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeyIndex = 0;
        m_uiShapeKeys[0] = 0xFFFFFFFFu;
    }

    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xFFFFFFFFu;
        m_uiShapeKeyIndex = 0;
    }
};

class hkpRayHitCollector
{
  public:
    virtual void CollectRayHit(const hkpCdBody& cdBody, const ShapeRayCastOutput& hitInfo) = 0;
};

// Pack unit supplies static noinline overloads for both helpers:
// a960 Sph_Seg form puts the hitKeys (int*) param in EAX;
// a610 Out-first form puts the out param in EDI.

struct DummyMultiSphere : hkpMultiSphereShape
{
    void FUN_00d2abe0(const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Ray-casts against the multi-sphere shape, transforms each hit normal into world space, and reports hits to the collector.
// @fnv 0x00d2abe0
void DummyMultiSphere::FUN_00d2abe0(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                    hkpRayHitCollector& collector) const
{
    hkReal hitFractions[8];
    hkUint32 hitKeys[8];
    const hkVector4* spheres = m_kSpheres;

    int numHits =
        FUN_00d2a960((const Sph_Seg*)&input, (const Sph_V*)spheres, m_iSphereCount, (int*)hitKeys, hitFractions);

    ShapeRayCastOutput output;
    if (numHits == 0)
    {
        return;
    }

    do
    {
        output.reset();

        int hitIndex = FUN_00d2a610((Out*)&output, (const Sph*)spheres, hitFractions, (const int*)hitKeys, numHits,
                                    (const Ray*)&input);

        const hkRotation& rot = cdBody.m_kMotionState->m_kMotionTransform.m_rotation;

        __m128 v = output.m_vComponents;
        __m128 v0 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), *(const __m128*)&rot.m_kColumn1);
        __m128 v1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), *(const __m128*)&rot.m_kColumn0);
        __m128 v2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), *(const __m128*)&rot.m_kColumn2);
        v0 = _mm_add_ps(v0, v1);
        output.m_vComponents = _mm_add_ps(v0, v2);

        collector.CollectRayHit(cdBody, output);

        numHits--;
        hitFractions[hitIndex] = hitFractions[numHits];
        hitKeys[hitIndex] = hitKeys[numHits];
    } while (numHits != 0);
}

extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

struct Vec4
{
    __m128 m_vComponents;
    __m128 get() const
    {
        return m_vComponents;
    }
    void set(__m128 v)
    {
        m_vComponents = v;
    }
};

struct hkTransformSimd
{
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
    Vec4 m_vTranslation;
};

struct hkAabbSimd
{
    Vec4 m_kMinimumCorner;
    Vec4 m_kMaximumCorner;
};

static __forceinline void TransformPointArray(const hkTransformSimd& t, const Vec4* vin, int num, Vec4* vout)
{
    Vec4 c0 = t.m_kColumn0;
    Vec4 c1 = t.m_kColumn1;
    Vec4 c2 = t.m_kColumn2;
    Vec4 c3 = t.m_vTranslation;
    __m128 q0 = c0.get();
    __m128 q1 = c1.get();
    __m128 q2 = c2.get();
    __m128 RunFourthVirtual = c3.get();
    int i = num - 1;
    do
    {
        __m128 b = vin[i].get();
        __m128 xb = _mm_shuffle_ps(b, b, 0);
        __m128 yb = _mm_shuffle_ps(b, b, 0x55);
        __m128 zb = _mm_shuffle_ps(b, b, 0xAA);
        __m128 t0 = _mm_mul_ps(xb, q0);
        __m128 t1 = _mm_mul_ps(yb, q1);
        __m128 t2 = _mm_mul_ps(zb, q2);
        vout[i].set(_mm_add_ps(_mm_add_ps(t0, t1), _mm_add_ps(t2, RunFourthVirtual)));
    } while (--i >= 0);
}

extern float DAT_0104da48;
extern float DAT_0104e148;

struct MultiSphereShape
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kSpheres[8];

    void FUN_00d2a7c0(const hkTransformSimd& localToWorld, float tolerance, hkAabbSimd& out) const;
};

// Transforms the sphere centers by localToWorld, expands by each radius, and writes the min/max corners, widened by tolerance, into out.
// @fnv 0x00d2a7c0
void MultiSphereShape::FUN_00d2a7c0(const hkTransformSimd& localToWorld, float tolerance, hkAabbSimd& out) const
{
    Vec4 tmp[8];
    TransformPointArray(localToWorld, m_kSpheres, m_iSphereCount, tmp);

    __m128 absMin = _mm_set_ps1(DAT_0104da48);
    __m128 absMax = _mm_set_ps1(DAT_0104e148);

    for (int i = 0; i < m_iSphereCount; i++)
    {
        __m128 r = _mm_shuffle_ps(m_kSpheres[i].get(), m_kSpheres[i].get(), 0xFF);
        __m128 mn = _mm_sub_ps(tmp[i].get(), r);
        __m128 mx = _mm_add_ps(tmp[i].get(), r);
        absMin = _mm_min_ps(absMin, mn);
        absMax = _mm_max_ps(absMax, mx);
    }
    __m128 tol4 = _mm_set_ps1(tolerance);
    out.m_kMinimumCorner.set(_mm_sub_ps(absMin, tol4));
    out.m_kMaximumCorner.set(_mm_add_ps(tol4, absMax));
}
