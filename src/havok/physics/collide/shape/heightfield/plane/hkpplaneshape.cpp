
// src/havok/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPlaneShape.h"

void __cdecl FUN_00d26230(void*, void*, void*, float, int);

struct FUN_00d552c0_StandIn
{
    void FUN_00d552c0(void*, float, int);
};

// Forwards param1, the objects at offsets 0x30 and 0x20 of this, param2 and param3 to FUN_00d26230.
// @fnv 0x00d552c0
void FUN_00d552c0_StandIn::FUN_00d552c0(void* param1, float param2, int param3)
{
    FUN_00d26230(param1, (void*)((char*)this + 0x30), (void*)((char*)this + 0x20), param2, param3);
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269b84;

class hkStatisticsCollectorD54F;

class hkReferencedObjectD54F
{
  public:
    virtual ~hkReferencedObjectD54F() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c90360(hkStatisticsCollectorD54F* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const;
};

class hkObjectD54F : public hkReferencedObjectD54F
{
  public:
    void FUN_00d54f80(hkStatisticsCollectorD54F* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const;
};

// @fnv 0x00d54f80
void hkObjectD54F::FUN_00d54f80(hkStatisticsCollectorD54F* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const
{
    FUN_00c90360(pkCollector, &g_01269b84);
}

struct __declspec(align(16)) Vector4D54F90
{
    float x;
    float y;
    float z;
    float w;
};
struct RayCastOutputD54F90
{
    RayCastOutputD54F90() : m_iExtraInfo(-1), m_uiShapeKeyIndex(0)
    {
        m_uiShapeKeys[0] = -1;
    }
    Vector4D54F90 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1C;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
struct BoolD54F90
{
    char m_cBooleanValue;
};
struct RayCastInputD54F90;
struct CdBodyD54F90
{
    int unk00;
    int unk04;
    const void* m_pMotionState;
};
struct CollectorD54F90
{
    virtual void CollectRayHit(const CdBodyD54F90& kBody, const RayCastOutputD54F90& kOutput);
    float m_fEarlyOutHitFraction;
};
void __stdcall FUN_00c7f750(const void* pkTransform, Vector4D54F90& kNormal);
struct ShapeD54F90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual BoolD54F90 RayCast(const RayCastInputD54F90& kInput, RayCastOutputD54F90& kOutput) const;
    void FUN_00d54f90(const RayCastInputD54F90& kInput, const CdBodyD54F90& kBody, CollectorD54F90& kCollector) const;
};

// Performs a ray cast against the shape, and if a hit is found, transforms the hit normal and forwards the result to the collector.
// @fnv 0x00d54f90
void ShapeD54F90::FUN_00d54f90(const RayCastInputD54F90& kInput, const CdBodyD54F90& kBody,
                               CollectorD54F90& kCollector) const
{
    RayCastOutputD54F90 kOutput;
    kOutput.m_fHitFraction = kCollector.m_fEarlyOutHitFraction;
    BoolD54F90 kHit = RayCast(kInput, kOutput);
    if (kHit.m_cBooleanValue)
    {
        FUN_00c7f750(kBody.m_pMotionState, kOutput.m_vHitNormal);
        kCollector.CollectRayHit(kBody, kOutput);
    }
}

#include <xmmintrin.h>
extern char DAT_010d0e18;
extern __m128 DAT_010c71d0;

struct PlaneShape_00d551d0 : hkpPlaneShape
{
    PlaneShape_00d551d0* FUN_00d551d0(const hkVector4& p, const hkVector4* box);
};

// Sets type 0x1c, stores p in m_kTriangleNormal, and sets the AABB center and half-extents from the two corner vectors in box.
// @fnv 0x00d551d0
PlaneShape_00d551d0* PlaneShape_00d551d0::FUN_00d551d0(const hkVector4& p, const hkVector4* box)
{
    m_ulUserData = 0;
    m_type = 0x1c;
    *(void**)this = &DAT_010d0e18;
    m_sReferenceCount = 1;
    *(__m128*)&m_kTriangleNormal = *(const __m128*)&p;
    *(__m128*)&m_kAabbCenter = _mm_mul_ps(_mm_add_ps(*(const __m128*)&box[1], *(const __m128*)&box[0]), DAT_010c71d0);
    *(__m128*)&m_kAabbHalfExtents =
        _mm_mul_ps(_mm_sub_ps(*(const __m128*)&box[1], *(const __m128*)&box[0]), DAT_010c71d0);
    return this;
}

struct __declspec(align(16)) PlaneVector
{
    __m128 value;
    __forceinline float Dot3(const PlaneVector& other) const
    {
        __m128 product = _mm_mul_ps(value, other.value);
        __m128 y = _mm_shuffle_ps(product, product, 0x55);
        __m128 z = _mm_shuffle_ps(product, product, 0xaa);
        __m128 sum = _mm_add_ss(y, product);
        __m128 total = _mm_add_ss(z, sum);
        return _mm_cvtss_f32(total);
    }
};
struct PlaneReference
{
    unsigned short memoryFlags;
    short referenceCount;
    PlaneReference() : referenceCount(1)
    {}
    virtual ~PlaneReference();
};
struct PlaneShapeBase : PlaneReference
{
    unsigned int userData;
    unsigned int type;
    PlaneShapeBase(unsigned int shapeType) : userData(0), type(shapeType)
    {}
};
struct FUN_00d55240 : PlaneShapeBase
{
    PlaneVector plane, centerVector, extentVector;
    FUN_00d55240(const PlaneVector& normal, const PlaneVector& center, const PlaneVector& extents);
    virtual ~FUN_00d55240();
};
// Initialises a plane shape with the given normal, center and extents, computing the plane offset as the negative dot of normal and center.
// @fnv 0x00d55240
FUN_00d55240::FUN_00d55240(const PlaneVector& normal, const PlaneVector& center, const PlaneVector& extents)
    : PlaneShapeBase(28)
{
    plane.value = normal.value;
    plane.value.m128_f32[3] = -normal.Dot3(center);
    centerVector.value = center.value;
    extentVector.value = extents.value;
}

namespace fnv_00d552f0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" __m128 _mm_and_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_cmple_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern "C" __m128 _mm_set_ps1(float _A);
extern "C" void _mm_store_ss(float* _V, __m128 _A);
extern "C" int _mm_movemask_ps(__m128 _A);
extern "C" const __m128 DAT_010ec7f0;
extern "C" const __m128 DAT_01017d10;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;
extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};

static const char s_kEndTimer[] = "Et";
static __forceinline void TimerMark(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct TimerScopeD55
{
    volatile unsigned int& m_t;
    __forceinline TimerScopeD55(const char* name, volatile unsigned int& t) : m_t(t)
    {
        TimerMark(name, m_t);
    }
    __forceinline ~TimerScopeD55()
    {
        TimerMark("Et", m_t);
    }
};

class HkBoolD55
{
  public:
    char m_cBooleanValue;
    HkBoolD55(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class Vec4D55
{
  public:
    __m128 m_vComponents;
    Vec4D55& operator=(const Vec4D55& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    float dot4xyz1(const Vec4D55& p) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, p.m_vComponents);
        __m128 w = _mm_shuffle_ps(p.m_vComponents, p.m_vComponents, 0xff);
        __m128 z = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), w);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        float r;
        _mm_store_ss(&r, _mm_add_ps(z, y));
        return r;
    }
};

struct RayInputD55
{
    Vec4D55 m_vFrom;
    Vec4D55 m_vTo;
};

struct RayOutputD55
{
    Vec4D55 m_vHitNormal;
    float m_fromDist;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

static inline void Dot4xyz1(float* out, const Vec4D55& p, const Vec4D55& a)
{
    __m128 x2 = _mm_mul_ps(a.m_vComponents, p.m_vComponents);
    __m128 w = _mm_shuffle_ps(p.m_vComponents, p.m_vComponents, 0xff);
    __m128 z = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), w);
    __m128 y = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    _mm_store_ss(out, _mm_add_ps(z, y));
}

class PlaneShapeD55
{
  public:
    int pad[4];
    Vec4D55 m_kTriangleNormal;
    Vec4D55 m_kAabbCenter;
    Vec4D55 m_kAabbHalfExtents;
    HkBoolD55 FUN_00d552f0(const RayInputD55& input, RayOutputD55& results) const;
};

// @fnv 0x00d552f0
HkBoolD55 PlaneShapeD55::FUN_00d552f0(const RayInputD55& input, RayOutputD55& results) const
{
    union
    {
        volatile unsigned int t;
        float d;
    } u;
    TimerScopeD55 timer("TtrcPlane", u.t);
    float& fromDist = u.d;
    Dot4xyz1(&fromDist, m_kTriangleNormal, input.m_vFrom);
    float toDist;
    Dot4xyz1(&toDist, m_kTriangleNormal, input.m_vTo);
    if (fromDist >= 0.0f && toDist < 0.0f)
    {
        fromDist = fromDist / (fromDist - toDist);
        __m128 t = _mm_set_ps1(fromDist);
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t);
        __m128 hit = _mm_add_ps(_mm_mul_ps(s, input.m_vFrom.m_vComponents), _mm_mul_ps(input.m_vTo.m_vComponents, t));
        __m128 diff = _mm_and_ps(_mm_sub_ps(hit, m_kAabbCenter.m_vComponents), DAT_01017d10);
        if ((_mm_movemask_ps(_mm_cmple_ps(diff, m_kAabbHalfExtents.m_vComponents)) & 7) == 7)
        {
            results.m_fromDist = fromDist;
            results.m_vHitNormal = m_kTriangleNormal;
            results.setKey(0xffffffff);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00d552f0
