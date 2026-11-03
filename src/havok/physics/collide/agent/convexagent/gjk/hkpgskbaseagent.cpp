
// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpGskBaseAgent
{
    virtual void FUN_00dabe90(bool);
};
// @fnv 0x00dabe90
void hkpGskBaseAgent::FUN_00dabe90(bool)
{
    if (this)
        FUN_00dabe90(true);
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_xor_ps(__m128, __m128);

extern float DAT_01012054;

class FUN_00dabeb0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
    int unk1C;

    void Reset(bool flag);
};

// @fnv 0x00dabeb0
void FUN_00dabeb0_cls::Reset(bool flag)
{
    m_f18 = DAT_01012054;
    *(__m128*)((char*)this + 0x20) = _mm_setzero_ps();
}

extern float DAT_01012054;

class FUN_00dabed0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_18;
    int unk1c;
    __m128 m_20;

    void SetValueIfExpected(float expected, float value, int unused);
};

// If m_18 equals expected, stores value into m_18; otherwise sets m_18 to DAT_01012054 and zeroes m_20.
// @fnv 0x00dabed0
void FUN_00dabed0_cls::SetValueIfExpected(float expected, float value, int unused)
{
    if (m_18 == expected)
    {
        m_18 = value;
    }
    else
    {
        m_18 = DAT_01012054;
        m_20 = _mm_setzero_ps();
    }
}

extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct hkpCdBody
{
    const void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const void* m_pMotionState;
};

struct GskAgentInput
{
    int unk00;
    int unk04;
    float m_fScalar;
};

struct hkTransform
{
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
    void FUN_00cb22f0(const void* a, const void* b);
};

struct GskInput
{
    const hkTransform* m_kTransform;
    const void* m_pTransformB;
    const void* m_pShapeA;
    const void* m_pShapeB;
    float m_fScalar;
};

struct GskOutput
{
    __m128 m_pos;
    __m128 m_vHitNormal;
};

struct hkContactPoint
{
    __m128 m_vContactPosition;
    __m128 m_vSeparatingNormal;
};

struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
};

struct hkpCdPointCollector
{
    virtual void vfunc00();
    virtual void AddCdPoint(const ContactPointPair& point);
};

int FUN_00dabca0(const GskInput* input, void* status, __m128* out1, __m128* out2);

class FUN_00dac9e0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void ProcessGskContact(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const GskAgentInput* input,
                           hkpCdPointCollector* collector);
};

struct StringCursor
{
    void* m_kRayStart;
    char* m_cur;
    void* m_auiShapeKeys;
    char* m_kRayEnd;
};

// @fnv 0x00dac9e0
void FUN_00dac9e0_cls::ProcessGskContact(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const GskAgentInput* input,
                                         hkpCdPointCollector* collector)
{
    StringCursor* pProfilerBuffer = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* pWriteCursor = pProfilerBuffer->m_cur;
    if (pWriteCursor < pProfilerBuffer->m_kRayEnd)
    {
        *(const char**)pWriteCursor = "TtGsk";
        _ReadWriteBarrier();
        volatile unsigned int uiTimestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(pWriteCursor + 4) = uiTimestamp;
        pWriteCursor += 12;
        pProfilerBuffer->m_cur = pWriteCursor;
    }

    hkTransform aTb;
    aTb.FUN_00cb22f0(bodyA->m_pMotionState, bodyB->m_pMotionState);

    GskInput queryInput;
    queryInput.m_pShapeA = bodyA->m_pCollisionShape;
    queryInput.m_pShapeB = bodyB->m_pCollisionShape;
    queryInput.m_kTransform = &aTb;
    queryInput.m_pTransformB = bodyA->m_pMotionState;
    queryInput.m_fScalar = input->m_fScalar;

    GskOutput out;
    if (FUN_00dabca0(&queryInput, &this->unk0c, &out.m_vHitNormal, &out.m_pos) == 0)
    {
        ContactPointPair point;
        point.m_kPoint.m_vContactPosition = out.m_pos;
        point.m_pBodyA = bodyA;
        point.m_pBodyB = bodyB;
        point.m_kPoint.m_vSeparatingNormal = out.m_vHitNormal;
        collector->AddCdPoint(point);
    }

    pProfilerBuffer = (StringCursor*)TlsGetValue(DAT_0126835c);
    pWriteCursor = pProfilerBuffer->m_cur;
    if (pWriteCursor < pProfilerBuffer->m_kRayEnd)
    {
        *(const char**)pWriteCursor = "Et";
        _ReadWriteBarrier();
        volatile unsigned int uiTimestamp = (unsigned int)__rdtsc();
        *(unsigned int*)(pWriteCursor + 4) = uiTimestamp;
        pWriteCursor += 12;
        pProfilerBuffer->m_cur = pWriteCursor;
    }
}

// @fnv 0x00dabe80
void __stdcall FUN_00dabe80(int, int, int, int)
{}

extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct hkVector4DAC0
{
    __m128 m_vComponents;

    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
    __forceinline void _setRotatedDir(const struct hkMatrix3DAC0& r, const hkVector4DAC0& b);
};

struct hkMatrix3DAC0
{
    hkVector4DAC0 m_kColumn0;
    hkVector4DAC0 m_kColumn1;
    hkVector4DAC0 m_kColumn2;
};

struct hkTransformDAC0
{
    hkMatrix3DAC0 m_rotation;
    hkVector4DAC0 m_vTranslation;

    void FUN_00cb22f0(const hkTransformDAC0& kA, const hkTransformDAC0& kB);

    const hkMatrix3DAC0& getRotation() const
    {
        return m_rotation;
    }
};

__forceinline void hkVector4DAC0::_setRotatedDir(const hkMatrix3DAC0& r, const hkVector4DAC0& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class hkpConvexShapeDAC0
{
  public:
    virtual ~hkpConvexShapeDAC0();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned long m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
};

struct hkpCdBodyDAC0
{
    const hkpConvexShapeDAC0* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransformDAC0* m_pMotionState;
};

struct hkpCollisionInputDAC0;

struct FUN_00daad40_solver
{
    void FUN_00daad40(const hkpConvexShapeDAC0* pkShapeA, const hkpConvexShapeDAC0* pkShapeB,
                      const hkTransformDAC0& kAtB, hkVector4DAC0& kPointOut);
};

// Builds kAtB, calls the solver, rotates its result by body A's rotation into kSeparatingNormal, and sets w to the solver's w minus both sphere radii.
// @fnv 0x00dac020
void __cdecl FUN_00dac020(const hkpCdBodyDAC0& kBodyA, const hkpCdBodyDAC0& kBodyB, const hkpCollisionInputDAC0& kInput,
                          FUN_00daad40_solver* pkSolver, hkVector4DAC0& kSeparatingNormal)
{
    const hkpConvexShapeDAC0* pkShapeA = kBodyA.m_pCollisionShape;
    const hkpConvexShapeDAC0* pkShapeB = kBodyB.m_pCollisionShape;

    hkTransformDAC0 kAtB;
    kAtB.FUN_00cb22f0(*kBodyA.m_pMotionState, *kBodyB.m_pMotionState);

    hkVector4DAC0 kNormal;
    pkSolver->FUN_00daad40(pkShapeA, pkShapeB, kAtB, kNormal);

    kSeparatingNormal._setRotatedDir(kBodyA.m_pMotionState->getRotation(), kNormal);
    kSeparatingNormal(3) = kNormal(3) - pkShapeA->m_fSphereRadius - pkShapeB->m_fSphereRadius;
}

extern char g_gskBaseAgentVtbl;

struct GskNode;

__declspec(align(16)) struct GskTmp
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
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
    void Setup(int a, int b);
};

struct GskSub
{
    int m_00;
    int m_04;
    int m_08;
    void Init(GskNode* a, GskNode* b, GskTmp* t);
    void Init2(GskNode* a, GskNode* b, GskTmp* t);
};

struct GskNode
{
    GskNode* m_00;
    int unk04;
    int m_08;
    GskNode* m_0c;
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
    float m_4c;
};

struct FUN_00dabf10_cls
{
    void* m_00;
    short unk04;
    short m_06;
    int m_08;
    GskSub m_0c;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;

    FUN_00dabf10_cls* FUN_00dabf10(GskNode* a1, GskNode* a2, int a3);
};

// Initializes the GskSub at m_0c from the two nodes, sets m_06, m_08 and the vtable, and stores the smaller of the two chain-end nodes' m_4c in m_1c.
// @fnv 0x00dabf10
FUN_00dabf10_cls* FUN_00dabf10_cls::FUN_00dabf10(GskNode* apNodeA, GskNode* apNodeB, int a3)
{
    m_06 = 1;
    m_08 = a3;
    m_00 = &g_gskBaseAgentVtbl;

    GskNode* ebx = apNodeB->m_00;
    int a2k = apNodeB->m_08;
    int a1k = apNodeA->m_08;
    GskNode* a1base = apNodeA->m_00;
    GskTmp tmp;
    tmp.Setup(a1k, a2k);

    if ((int)ebx->m_0c == 3)
    {
        m_0c.Init(a1base, ebx, &tmp);
    }
    else
    {
        m_0c.Init2(a1base, ebx, &tmp);
    }

    *(__m128*)&m_20 = _mm_setzero_ps();
    m_2c = -1.0f;
    m_18 = -1.0f;

    GskNode* p = apNodeA;
    while (p->m_0c != 0)
    {
        p = p->m_0c;
    }
    float fa = p->m_4c;

    GskNode* r = apNodeB;
    while (r->m_0c != 0)
    {
        r = r->m_0c;
    }
    float fb = r->m_4c;

    m_1c = (fa < fb) ? fa : fb;
    return this;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
    hkBool(char b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    float m_weldTolerance;
    float m_fScalar;
};

struct ContactData
{
    __m128 m_vHitNormal;
    __m128 m_vContactPosition;
    float m_fClosestPointDistanceSquared;
    __m128 m_data30;
    __m128 m_data40;
};

struct Shape
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void GetVerticesForIds(const short* ids, int numIds, __m128* vertsOut);
    int pad04;
    int pad08;
    int pad0c;
    float m_fSphereRadius;
};

struct GskCache
{
    short m_kVertices[4];
    unsigned char m_ucDimensionA, m_ucDimensionB, m_features, unk17;
};
struct GskStatus
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_featureA;
    int m_featureB;
    int unk10;
    int unk14;
    int pad18;
    int pad1c;
    __m128 m_vertsA[12];
    __m128 m_vertsB[10];

    void FUN_00daad40(const void* shapeA, const void* shapeB, const hkTransform* bTa, void* out10);
    void FUN_00da9790(void* cache);
    void FUN_00da9880(void* out10, hkContactPoint* pointOut);
};

extern "C"
{
    void _mm_store_ps(float*, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
}

static __forceinline short* unpackCache(GskCache& c, int& b, unsigned& f, int& a)
{
    b = c.m_ucDimensionB;
    f = c.m_features;
    a = c.m_ucDimensionA;
    return c.m_kVertices;
}

struct GskAgentStandin : public hkpGskBaseAgent
{
    int unk04;
    int unk08;
    GskCache m_pAccessManager;

    hkBool FUN_00dac7f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                        hkContactPoint& pointOut);
};

// Runs the GSK solver on the two shapes, writes the contact point to pointOut, and returns true if the separation minus radii is below input.m_fScalar.
// @fnv 0x00dac7f0
hkBool GskAgentStandin::FUN_00dac7f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                                     hkContactPoint& pointOut)
{
    Shape* pShapeB = (Shape*)bodyB.m_pCollisionShape;
    Shape* shapeA = (Shape*)bodyA.m_pCollisionShape;

    hkTransform tRelativeTransform;
    tRelativeTransform.FUN_00cb22f0(bodyA.m_pMotionState, bodyB.m_pMotionState);

    Shape* __restrict convertShapeA = shapeA;
    int dimB, r1;
    unsigned uiFeatures;
    short* i = unpackCache(this->m_pAccessManager, dimB, uiFeatures, r1);
    GskStatus gskStatus;
    gskStatus.m_ucDimensionB = dimB;
    gskStatus.unk10 = 0;
    gskStatus.m_featureA = uiFeatures & 0x0f;
    gskStatus.m_ucDimensionA = r1;
    gskStatus.m_featureB = uiFeatures >> 4;
    gskStatus.unk14 = 0;

    convertShapeA->GetVerticesForIds(i, r1, gskStatus.m_vertsA);
    pShapeB->GetVerticesForIds(&i[gskStatus.m_ucDimensionA], gskStatus.m_ucDimensionB, gskStatus.m_vertsB);

    __m128 c1;
    gskStatus.FUN_00daad40(shapeA, pShapeB, &tRelativeTransform, &c1);

    if (gskStatus.unk14 != 0)
    {
        gskStatus.FUN_00da9790(i);
    }

    gskStatus.FUN_00da9880(&c1, &pointOut);

    const hkTransform* b = (const hkTransform*)bodyA.m_pMotionState;
    ContactData* pContactData = (ContactData*)&pointOut;
    __m128 verts = pContactData->m_vHitNormal;

    __m128 feat = _mm_mul_ps(_mm_shuffle_ps(verts, verts, 0x55), b->m_kColumn1);
    __m128 aTransform = _mm_mul_ps(_mm_shuffle_ps(verts, verts, 0), b->m_kColumn0);
    __m128 v3 = _mm_mul_ps(_mm_shuffle_ps(verts, verts, 0xaa), b->m_kColumn2);
    pContactData->m_data40 = _mm_add_ps(_mm_add_ps(feat, aTransform), v3);

    float dimA;
    dimA = pContactData->m_fClosestPointDistanceSquared - shapeA->m_fSphereRadius - pShapeB->m_fSphereRadius;
    pContactData->m_fClosestPointDistanceSquared = dimA;

    if (dimA < input.m_fScalar)
    {
        float fRadiusA = shapeA->m_fSphereRadius;
        __m128 vRadiusA = _mm_load_ss(&fRadiusA);
        __m128 vRadiusASplatted = _mm_shuffle_ps(vRadiusA, vRadiusA, 0);
        _mm_store_ps(pContactData->m_vContactPosition.m128_f32,
                     _mm_sub_ps(pContactData->m_vContactPosition, _mm_mul_ps(vRadiusASplatted, verts)));

        float negDist = -dimA;
        __m128 negV = _mm_load_ss(&negDist);
        __m128 cnt = _mm_shuffle_ps(negV, negV, 0);
        __m128 r0 = _mm_sub_ps(_mm_add_ps(pContactData->m_vContactPosition, _mm_mul_ps(cnt, pContactData->m_vHitNormal)),
                               tRelativeTransform.m_kColumn3);

        struct Rows
        {
            __m128 a, c;
        } rows;

        __m128 vColumn0 = tRelativeTransform.m_kColumn0, kIter = tRelativeTransform.m_kColumn1,
               s = tRelativeTransform.m_kColumn2;
        __m128 v2 = _mm_unpacklo_ps(vColumn0, kIter);
        rows.a = _mm_unpackhi_ps(vColumn0, kIter);
        __m128 v4 = _mm_movelh_ps(v2, s);
        rows.c = _mm_shuffle_ps(_mm_movehl_ps(v4, v2), s, 0xd4);
        __m128 tmp = _mm_shuffle_ps(rows.a, s, 0xe4);
        __m128 bTa = _mm_mul_ps(_mm_shuffle_ps(r0, r0, 0x55), rows.c);
        __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(r0, r0, 0), v4);
        __m128 m3 = _mm_mul_ps(_mm_shuffle_ps(r0, r0, 0xaa), tmp);
        pContactData->m_data30 = _mm_add_ps(_mm_add_ps(bTa, r2), m3);

        return true;
    }

    return false;
}

#include <windows.h>

struct S_00dac2b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00dac2b0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dac2b0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dac2b0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dac2b0_TimerCommand* h = (S_00dac2b0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

struct __declspec(align(16)) S_00dac2b0_Transform
{
    float m[16];
    void FUN_00cb22f0(const S_00dac2b0_Transform* a, const S_00dac2b0_Transform* b);
};

struct __declspec(align(16)) S_00dac2b0_Vec
{
    float x, y, z, w;
};

struct S_00dac2b0_Shape;

struct S_00dac2b0_Cache
{
    unsigned short id0, id1, id2, id3;
    unsigned char dimA, dimB, dims;
    void FUN_00dafe70(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t);
    void FUN_00dafcd0(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t);
};

struct S_00dac2b0_Shape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac2b0_Vec* out) const;
    int unk04;
    int unk08;
    int m_type;
    float m_fSphereRadius;
};

struct __declspec(align(16)) S_00dac2b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_maxA;
    int m_maxB;
    int m_iCachedVertexCount;
    int m_zero;
    int unk18;
    int unk1C;
    S_00dac2b0_Vec m_vertsA[12];
    S_00dac2b0_Vec m_vertsB[10];
    int FUN_00daad40(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t,
                     S_00dac2b0_Vec* out);
};

struct S_00dac2b0_Body
{
    const S_00dac2b0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00dac2b0_Transform* m_pMotionState;
};

struct S_00dac2b0_Collector
{
    virtual void v0();
    virtual void AddCdBodyPair(const S_00dac2b0_Body& a, const S_00dac2b0_Body& b);
};

// Runs the GSK step (timed as TtGsk) on the two bodies' shapes and adds the pair to the collector if the result is nonzero or the distance is below the radii.
// @fnv 0x00dac2b0
void __cdecl TestGsk(const S_00dac2b0_Body& bodyA, const S_00dac2b0_Body& bodyB, const void* input,
                     S_00dac2b0_Collector& collector)
{
    S_00dac2b0_MonitorStream::GetMonitorStream().timer("TtGsk");

    const S_00dac2b0_Shape* shapeA = bodyA.m_pCollisionShape;
    const S_00dac2b0_Shape* shapeB = bodyB.m_pCollisionShape;

    S_00dac2b0_Transform aTb;
    aTb.FUN_00cb22f0(bodyA.m_pMotionState, bodyB.m_pMotionState);

    S_00dac2b0_Cache cache;
    if (shapeB->m_type == 3)
    {
        cache.FUN_00dafe70(shapeA, shapeB, &aTb);
    }
    else
    {
        cache.FUN_00dafcd0(shapeA, shapeB, &aTb);
    }

    S_00dac2b0_Gsk gsk;
    gsk.m_ucDimensionA = cache.dimA;
    gsk.m_ucDimensionB = cache.dimB;
    gsk.m_maxA = cache.dims & 0xf;
    gsk.m_iCachedVertexCount = 1;
    gsk.m_maxB = cache.dims >> 4;
    gsk.m_zero = 0;
    shapeA->GetVerticesForIds(&cache.id0, cache.dimA, gsk.m_vertsA);
    shapeB->GetVerticesForIds(&cache.id0 + gsk.m_ucDimensionA, gsk.m_ucDimensionB, gsk.m_vertsB);

    S_00dac2b0_Vec out;
    int iResult = gsk.FUN_00daad40(shapeA, shapeB, &aTb, &out);

    S_00dac2b0_MonitorStream::GetMonitorStream().timer("Et");

    if (iResult == 0)
    {
        float d = out.w - shapeA->m_fSphereRadius - shapeB->m_fSphereRadius;
        if (d < 0.0f)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
        }
    }
    else
    {
        collector.AddCdBodyPair(bodyA, bodyB);
    }
}

union EarlyScratch
{
    volatile unsigned int ticks;
    int result;
    float distance;
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern unsigned long hkMonitorStreamTls;

struct S_00dac0b0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00dac0b0_TimerBeginListCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    const char* m_pFirst;
};

struct S_00dac0b0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00dac0b0_TimerBeginList(const char* name, const char* firstSplit, EarlyScratch& scratch)
{
    S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00dac0b0_TimerBeginListCommand* h = (S_00dac0b0_TimerBeginListCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        h->m_pFirst = firstSplit;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00dac0b0_Timer(const char* name, EarlyScratch& scratch)
{
    S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        scratch.ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = scratch.ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

static inline void S_00dac0b0_TimerEnd()
{
    {
        S_00dac0b0_MonitorStream* s = (S_00dac0b0_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
        if (s->m_kRayEnd < s->m_pCurrentCommand)
        {
            S_00dac0b0_TimerCommand* h = (S_00dac0b0_TimerCommand*)s->m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            struct Tk
            {
                unsigned int v;
            };
            Tk t;
            *(volatile unsigned int*)&t.v = (unsigned int)__rdtsc();
            *(Tk*)&h->m_uiStartTicks = t;
            s->m_kRayEnd = (char*)(h + 1);
        }
    }
}

struct S_00dac0b0_Vertex
{
    float x, y, z, w;
};

struct S_00dac0b0_Transform
{
    S_00dac0b0_Vertex col0;
    S_00dac0b0_Vertex col1;
    S_00dac0b0_Vertex col2;
    S_00dac0b0_Vertex trans;
    void FUN_00cb22f0(const S_00dac0b0_Transform* a, const S_00dac0b0_Transform* b);
};

struct S_00dac0b0_Shape
{
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
    virtual void v38();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac0b0_Vertex* out) const;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
};

struct S_00dac0b0_Body
{
    S_00dac0b0_Shape* m_pCollisionShape;
    int unk04;
    const S_00dac0b0_Transform* m_kMotionTransform;
};

struct S_00dac0b0_PackedCache
{
    unsigned short id0, id1, id2, id3;
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flags;
};

struct S_00dac0b0_Gsk
{
    int m_ucDimensionA;
    int m_ucDimensionB;
    int m_ucLowNibble;
    int m_ucHighNibble;
    int m_iCachedVertexCount;
    int m_changed;
    int unk18;
    int unk1C;
    S_00dac0b0_Vertex a00;
    S_00dac0b0_Vertex a01;
    S_00dac0b0_Vertex a02;
    S_00dac0b0_Vertex a03;
    S_00dac0b0_Vertex a04;
    S_00dac0b0_Vertex a05;
    S_00dac0b0_Vertex a06;
    S_00dac0b0_Vertex a07;
    S_00dac0b0_Vertex a08;
    S_00dac0b0_Vertex a09;
    S_00dac0b0_Vertex a10;
    S_00dac0b0_Vertex a11;
    S_00dac0b0_Vertex b00;
    S_00dac0b0_Vertex b01;
    S_00dac0b0_Vertex b02;
    S_00dac0b0_Vertex b03;
    S_00dac0b0_Vertex b04;
    S_00dac0b0_Vertex b05;
    S_00dac0b0_Vertex b06;
    S_00dac0b0_Vertex b07;
    S_00dac0b0_Vertex b08;
    S_00dac0b0_Vertex b09;
    S_00dac0b0_Transform aTb;
    int FUN_00daad40(S_00dac0b0_Shape* a, S_00dac0b0_Shape* b, const S_00dac0b0_Transform& aTb, S_00dac0b0_Vertex* out);
    void FUN_00da9790(S_00dac0b0_PackedCache* dst);
};

template <class T> struct S_00dac0b0_Pad
{
    T* m_p;
    T* val() const
    {
        return m_p;
    }
};

struct S_00dac0b0_Out
{
    virtual void v00();
    virtual void v04(const S_00dac0b0_Body& a, const S_00dac0b0_Body& b);
};

struct S_00dac0b0_Agent : hkpGskBaseAgent
{
    int unk04;
    int unk08;
    S_00dac0b0_PackedCache m_pAccessManager;
    int unk18;
    int unk1C;
    S_00dac0b0_Vertex m_sepNormal;
    void hkpGskBaseAgent_getPenetrations(S_00dac0b0_Pad<const S_00dac0b0_Body> pA, S_00dac0b0_Pad<const S_00dac0b0_Body> pB,
                      const void* input, S_00dac0b0_Pad<S_00dac0b0_Out> pOut);
};

// @fnv 0x00dac0b0
void S_00dac0b0_Agent::hkpGskBaseAgent_getPenetrations(S_00dac0b0_Pad<const S_00dac0b0_Body> pA, S_00dac0b0_Pad<const S_00dac0b0_Body> pB,
                                    const void* input, S_00dac0b0_Pad<S_00dac0b0_Out> pOut)
{
    EarlyScratch scratch;
    S_00dac0b0_TimerBeginList("LtGsk", "Sttim", scratch);
    S_00dac0b0_Timer("StSepNormal", scratch);

    S_00dac0b0_Shape* shapeA = pA.val()->m_pCollisionShape;
    S_00dac0b0_Shape* shapeB = pB.val()->m_pCollisionShape;
    S_00dac0b0_Gsk gsk;
    gsk.aTb.FUN_00cb22f0(pA.val()->m_kMotionTransform, pB.val()->m_kMotionTransform);

    S_00dac0b0_PackedCache* c = &m_pAccessManager;
    gsk.m_ucDimensionA = c->m_ucDimensionA;
    gsk.m_ucDimensionB = c->m_ucDimensionB;
    gsk.m_ucLowNibble = c->m_flags & 0xf;
    gsk.m_ucHighNibble = c->m_flags >> 4;
    gsk.m_iCachedVertexCount = 1;
    gsk.m_changed = 0;
    shapeA->GetVerticesForIds(&c->id0, gsk.m_ucDimensionA, &gsk.a00);
    shapeB->GetVerticesForIds(&c->id0 + gsk.m_ucDimensionA, gsk.m_ucDimensionB, &gsk.b00);

    S_00dac0b0_Vertex normal;
    scratch.result = gsk.FUN_00daad40(shapeA, shapeB, gsk.aTb, &normal);
    if (gsk.m_changed)
        gsk.FUN_00da9790(c);

    if (scratch.result == 0)
    {
        __m128 n = *(__m128*)&normal;
        scratch.distance = normal.w - shapeA->m_fSphereRadius - shapeB->m_fSphereRadius;
        const S_00dac0b0_Transform* ta = pA.val()->m_kMotionTransform;
        __m128 r0 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(n, n, 0x55), *(const __m128*)&ta->col1),
                                          _mm_mul_ps(_mm_shuffle_ps(n, n, 0x00), *(const __m128*)&ta->col0)),
                               _mm_mul_ps(_mm_shuffle_ps(n, n, 0xaa), *(const __m128*)&ta->col2));
        *(__m128*)&m_sepNormal = r0;
        m_sepNormal.w = scratch.distance;
        if (scratch.distance < 0.0f)
            pOut.val()->v04(*pA.val(), *pB.val());
    }
    else
    {
        *(__m128*)&m_sepNormal = _mm_setzero_ps();
        pOut.val()->v04(*pA.val(), *pB.val());
    }
    S_00dac0b0_TimerEnd();
}
