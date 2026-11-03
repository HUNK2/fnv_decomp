
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00d3ef70_CdBody;
struct S_00d3ef70_Input;
struct S_00d3ef70_Agent;
struct S_00d3ef70_Collector;
typedef S_00d3ef70_Agent* (*S_00d3ef70_CreateFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&,
                                                   const S_00d3ef70_Input&, void*);
typedef void (*S_00d3ef70_GetPenetrationsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&,
                                               const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_GetClosestPointsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&,
                                                const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_LinearCastFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&,
                                          S_00d3ef70_Collector&, S_00d3ef70_Collector*);
struct S_00d3ef70_AgentFuncs
{
    S_00d3ef70_CreateFunc m_pCreateFunc;
    S_00d3ef70_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d3ef70_GetClosestPointsFunc m_getClosestPointsFunc;
    S_00d3ef70_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d3ef70_Dispatcher
{
    void registerCollisionAgent(S_00d3ef70_AgentFuncs& f, int typeA, int typeB);
};
S_00d3ef70_Agent* FUN_00d3e2f0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
void FUN_00d3f040(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3f4c0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3ac80(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&,
                  S_00d3ef70_Collector*);
S_00d3ef70_Agent* FUN_00d3e270(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
void FUN_00d3e330(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00d3ebe0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
void FUN_00daf8e0(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&,
                  S_00d3ef70_Collector*);
void FUN_00d3ef70(S_00d3ef70_Dispatcher* dispatcher);
class InnerCls
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned short a, int b);
};
inline void InnerCls::v0()
{}
inline void InnerCls::v1()
{}
inline void InnerCls::v2()
{}
inline void InnerCls::v3()
{}
inline void InnerCls::v4()
{}
inline void InnerCls::v5(unsigned short a, int b)
{
    a;
    b;
}
class FUN_00d3e2b0_cls
{
  public:
    virtual void v0(int a);
    int m_i04;
    InnerCls* m_pInner;
    unsigned short m_w0c;
    void hkpSphereCapsuleAgent_cleanup(int a1);
};
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct SmallRecord
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};
extern char DAT_010cf018[];
AllocHolder* FUN_00c85750();
void __cdecl FUN_00d3e2f0(int a, int b, int c, int d);
void __cdecl FUN_00d3e330(int a, int b, int c, int d);
void __stdcall FUN_00d3e510(int a, int b, int c, int d);
extern char DAT_010ce81c;
struct FUN_00d3f040_tmp
{
    const char* str;
    unsigned char flag;
    unsigned int value;
};
void __cdecl FUN_00d3e330(unsigned int a, unsigned int b, unsigned int c, FUN_00d3f040_tmp* p);
void __cdecl FUN_00d3f040(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3);

#include <xmmintrin.h>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl fabs(double);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned long g_hkMonitorStreamTls;

static inline float hkMathSqrt(float r)
{
    volatile float v = (float)sqrt(r);
    return v;
}

static inline float hkMathFabs(float r, volatile float& v)
{
    v = (float)fabs(r);
    return v;
}

struct StringCursor
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

struct hkMonitorTimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct hkVector4
{
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __m128 m_vComponents;
};

struct hkMatrix3
{
    inline void operator=(const hkMatrix3& m)
    {
        m_kColumn0 = m.m_kColumn0;
        m_kColumn1 = m.m_kColumn1;
        m_kColumn2 = m.m_kColumn2;
    }
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

struct hkRotation : hkMatrix3
{
    inline void operator=(const hkRotation& m)
    {
        hkMatrix3::operator=(m);
    }
};

struct hkTransform
{
    inline hkTransform(const hkTransform& t)
    {
        m_rotation.m_kColumn0 = t.m_rotation.m_kColumn0;
        m_rotation.m_kColumn1 = t.m_rotation.m_kColumn1;
        m_rotation.m_kColumn2 = t.m_rotation.m_kColumn2;
        m_vTranslation = t.m_vTranslation;
    }
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

struct hkpShape
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkpConvexShape : hkpShape
{
    float m_fSphereRadius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpCapsuleShape : hkpConvexShape
{
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    const hkpCdBody* m_parent;
};

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    void* m_iFilter;
    float m_fScalar;
};

struct hkContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};

struct ContactPointPair
{
    ContactPointPair(const hkpCdBody& a, const hkpCdBody& b) : m_pBodyA(a), m_pBodyB(b)
    {}
    hkContactPoint m_kPoint;
    const hkpCdBody& m_pBodyA;
    const hkpCdBody& m_pBodyB;
};

struct hkpCdPointCollector
{
    virtual void unk00();
    virtual void AddCdPoint(const ContactPointPair& event);
};

struct Vector4Wrapper
{
    hkVector4 m_kClosestPoint;
};

int GetClosestPointOnLineSegment(const hkVector4& A, const hkVector4& B0, const hkVector4& B1, Vector4Wrapper& result);

static inline void timerCommand(const char* name, volatile unsigned int& ticks)
{
    StringCursor* s = (StringCursor*)TlsGetValue(g_hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        hkMonitorTimerCommand* h = (hkMonitorTimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

// @fnv 0x00d3e850
void __stdcall FUN_00d3e850(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                            hkpCdPointCollector& collector)
{
    union
    {
        unsigned int startTicks;
        float distanceSquared;
        float minimumAbs;
    } scal0;
    struct
    {
        union
        {
            float radiusSum;
            unsigned int endTicks;
        };
        float absZ;
    } scal2;
    float absY;
    timerCommand("TtSphereCapsule", scal0.startTicks);

    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.m_pCollisionShape);
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.m_pCollisionShape);
    const hkVector4& posA = bodyA.m_pMotionState->m_vTranslation;
    union
    {
        hkVector4 column0;
        hkVector4 edge;
    } first;
    union
    {
        hkVector4 column2;
        hkVector4 separation;
    } second;
    union
    {
        hkVector4 translation;
        Vector4Wrapper result;
    } third;
    union
    {
        hkVector4 column1;
        hkVector4 endpoints[2];
    } fourth;
    ContactPointPair event(bodyA, bodyB);
    const hkTransform& tB = *bodyB.m_pMotionState;
    first.column0 = tB.m_rotation.m_kColumn0;
    fourth.column1.m_vComponents.m128_i32[0] = tB.m_rotation.m_kColumn1.m_vComponents.m128_i32[0];
    fourth.column1.m_vComponents.m128_i32[1] = tB.m_rotation.m_kColumn1.m_vComponents.m128_i32[1];
    fourth.column1.m_vComponents.m128_i32[2] = tB.m_rotation.m_kColumn1.m_vComponents.m128_i32[2];
    __m128 c0 = _mm_load_ps(first.column0.m_vComponents.m128_f32);
    fourth.column1.m_vComponents.m128_i32[3] = tB.m_rotation.m_kColumn1.m_vComponents.m128_i32[3];
    second.column2 = tB.m_rotation.m_kColumn2;
    __m128 c1 = _mm_load_ps(fourth.column1.m_vComponents.m128_f32);
    third.translation.m_vComponents.m128_i32[0] = tB.m_vTranslation.m_vComponents.m128_i32[0];
    __m128 c2 = _mm_load_ps(second.column2.m_vComponents.m128_f32);
    third.translation.m_vComponents.m128_i32[1] = tB.m_vTranslation.m_vComponents.m128_i32[1];
    third.translation.m_vComponents.m128_i32[2] = tB.m_vTranslation.m_vComponents.m128_i32[2];
    third.translation.m_vComponents.m128_i32[3] = tB.m_vTranslation.m_vComponents.m128_i32[3];
    __m128 tr = _mm_load_ps(third.translation.m_vComponents.m128_f32);
    const hkVector4* in = &capsuleB->m_kVertexA;
    int i = 1;
    do
    {
        __m128 v = in[i].m_vComponents;
        __m128 xb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 yb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 zb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
        __m128 r0 = _mm_mul_ps(c0, xb);
        __m128 r1 = _mm_mul_ps(c1, yb);
        __m128 r2 = _mm_mul_ps(c2, zb);
        fourth.endpoints[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, tr));
    } while (--i >= 0);

    GetClosestPointOnLineSegment(posA, fourth.endpoints[0], fourth.endpoints[1], third.result);

    scal2.radiusSum = sphereA->m_fSphereRadius + capsuleB->m_fSphereRadius;
    float refDist = scal2.radiusSum + input.m_fScalar;

    second.separation.m_vComponents = _mm_sub_ps(posA.m_vComponents, third.result.m_kClosestPoint.m_vComponents);
    {
        __m128 len = _mm_mul_ps(second.separation.m_vComponents, second.separation.m_vComponents);
        __m128 s0 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 s1 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(2, 2, 2, 2));
        _mm_store_ss(&scal0.distanceSquared, _mm_add_ss(s1, _mm_add_ss(s0, len)));
    }

    float refDist2 = refDist * refDist;
    if (!(scal0.distanceSquared >= refDist2))
    {
        float distance;
        hkVector4& normal = event.m_kPoint.m_vSeparatingNormal;
        if (scal0.distanceSquared > 0.0f)
        {
            distance = hkMathSqrt(scal0.distanceSquared);
            normal.m_vComponents = second.separation.m_vComponents;
        }
        else
        {
            distance = 0.0f;
            first.edge.m_vComponents = _mm_sub_ps(fourth.endpoints[1].m_vComponents, fourth.endpoints[0].m_vComponents);

            int min = 0;
            int ok1 = 1;
            int ok2 = 2;
            scal0.minimumAbs = hkMathFabs(first.edge(0), scal0.minimumAbs);
            absY = hkMathFabs(first.edge(1), scal2.absZ);
            scal2.absZ = hkMathFabs(first.edge(2), scal2.absZ);
            if (absY < scal0.minimumAbs)
            {
                ok1 = 0;
                min = 1;
                scal0.minimumAbs = absY;
            }
            if (scal2.absZ < scal0.minimumAbs)
            {
                ok2 = min;
                min = 2;
            }
            normal.m_vComponents = _mm_setzero_ps();
            normal(ok1) = first.edge(ok2);
            normal(ok2) = -first.edge(ok1);
        }

        {
            __m128 len = _mm_mul_ps(normal.m_vComponents, normal.m_vComponents);
            __m128 s0 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(1, 1, 1, 1));
            __m128 s1 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(2, 2, 2, 2));
            __m128 len2 = _mm_add_ss(s1, _mm_add_ss(s0, len));
            __m128 e = _mm_rsqrt_ss(len2);
            __m128 eq = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
            __m128 he = _mm_mul_ss(_mm_set_ss(0.5f), e);
            __m128 ee = _mm_mul_ss(_mm_mul_ss(len2, e), e);
            __m128 r = _mm_mul_ss(he, _mm_sub_ss(_mm_set_ss(3.0f), ee));
            r = _mm_andnot_ps(eq, r);
            hkVector4 broadcast;
            broadcast.m_vComponents = r;
            normal.m_vComponents =
                _mm_mul_ps(_mm_shuffle_ps(broadcast.m_vComponents, broadcast.m_vComponents, 0), normal.m_vComponents);
        }

        absY = capsuleB->m_fSphereRadius - distance;
        event.m_kPoint.m_vContactPosition.m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&absY), _mm_load_ss(&absY), 0), normal.m_vComponents),
                       posA.m_vComponents);
        normal(3) = distance - scal2.radiusSum;
        collector.AddCdPoint(event);
    }

    timerCommand("Et", scal2.endTicks);
}
