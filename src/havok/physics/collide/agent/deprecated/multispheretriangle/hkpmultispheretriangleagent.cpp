
// src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d37e60_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00d37e60_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d37e60_Allocator* m_pStreamAllocator;
    S_00d37e60_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00d37e60_Router* FUN_00c85750();

struct S_00d37e60_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d37e60_RefObj()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00d37e60_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00d37e60_RefObj* b = static_cast<S_00d37e60_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};

struct S_00d37e60_Agent : S_00d37e60_RefObj
{
    void* m_pContactManager;
    S_00d37e60_Agent(void* mgr) : m_pContactManager(mgr)
    {}
    virtual void getPenetrations();
};

struct S_00d37e60_Shape
{
    int unk0[8];
};

struct S_00d37e60_CdBody
{
    char* m_pCollisionShape;
};

struct S_00d37e60_Plane
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

void FUN_00cd7160(const void* verts, S_00d37e60_Plane* out) throw();

struct S_00d37e60_TriAgent : S_00d37e60_Agent
{
    S_00d37e60_Plane m_kTriangleNormal;
    unsigned short m_ids[8];
    virtual void getPenetrations();
    __forceinline S_00d37e60_TriAgent(const S_00d37e60_CdBody& bodyA, void* mgr) : S_00d37e60_Agent(mgr)
    {
        for (int i = 0; i < 8; i++)
            m_ids[i] = 0xffff;
        FUN_00cd7160(bodyA.m_pCollisionShape + 0x20, &m_kTriangleNormal);
    }
};

struct S_00d37e60_TriAgent2 : S_00d37e60_TriAgent
{
    __forceinline S_00d37e60_TriAgent2(const S_00d37e60_CdBody& bodyA, void* mgr) : S_00d37e60_TriAgent(bodyA, mgr)
    {}
    virtual void getPenetrations();
};

// Allocates and constructs a TriAgent2 from bodyA and mgr, returning it as an Agent pointer.
// @fnv 0x00d37e60
S_00d37e60_Agent* CreateTriAgent2(const S_00d37e60_CdBody& bodyA, const S_00d37e60_CdBody& bodyB, const void* input,
                                  void* mgr)
{
    return new S_00d37e60_TriAgent2(bodyA, mgr);
}

void __cdecl FUN_00d38130(void*, void*, void*, void*);
struct D38AC0Data
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
};
// @fnv 0x00d38ac0
void __cdecl FUN_00d38ac0(void* first, void* second, void* third, int fourth)
{
    D38AC0Data data;
    data.unk08 = fourth;
    data.unk04 = 0;
    data.unk00 = 0x10ce81c;
    FUN_00d38130(second, first, third, &data);
}

struct CpuCallData
{
    void* descriptor;
    float bound;
    unsigned int value;
};
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void FUN_00d38390(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d38e90(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first and third to FUN_00d38390.
// @fnv 0x00d38e90
void CpuObject::FUN_00d38e90(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d38390(second, first, third, &data);
}

struct FUN_00d37e10_sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(unsigned short w, int arg);
};

class FUN_00d37e10_cls
{
  public:
    virtual void vDtor(int flags);
    unsigned int unk04;
    FUN_00d37e10_sub* m_pSub;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short m_w1C[8];

    void FUN_00d37e10(int arg);
};

// Calls m_pSub->v14 for each non-0xffff entry in m_w1C, then destroys this with vDtor(1).
// @fnv 0x00d37e10
void FUN_00d37e10_cls::FUN_00d37e10(int arg)
{
    unsigned short* p = m_w1C;
    int n = 8;
    do
    {
        unsigned short w = *p;
        if (w != 0xffff)
        {
            m_pSub->v14(w, arg);
        }
        ++p;
        --n;
    } while (n != 0);

    if (this != 0)
    {
        this->vDtor(1);
    }
}

struct CallbackState
{
    const void* type;
    bool completed;
    unsigned context;
};

extern const unsigned vtable_010ce81c[];

struct Operation
{
    void FUN_00d37ed0(unsigned second, unsigned first, unsigned third, CallbackState* callback);
    void FUN_00d38a80(unsigned first, unsigned second, unsigned third, unsigned context);
};

// Initialises a CallbackState with the given context and vtable, then calls FUN_00d37ed0 with the reordered arguments and the callback.
// @fnv 0x00d38a80
void Operation::FUN_00d38a80(unsigned first, unsigned second, unsigned third, unsigned context)
{
    CallbackState callback;
    callback.context = context;
    callback.completed = false;
    callback.type = vtable_010ce81c;
    FUN_00d37ed0(second, first, third, &callback);
}

// Stand-in for the 12-byte record the callee receives by pointer.
// Field order/offsets come from the target frame layout:
//   +0 : pointer, +4 : float, +8 : dword
struct FUN_00d38ed0_Local
{
    const char* unk00;
    float unk04;
    int unk08;
};

// Global float loaded with `fld dword ptr [0x104da48]`.
extern float unk_104da48;

// Global object whose address (0x10ce7fc) is stored into the record.
extern char unk_10ce7fc[];

// Callee at 0x00d386c0: __cdecl, four arguments,
// the last one being a pointer to the record built on the stack.
void __cdecl FUN_00d386c0(int unk04, int unk08, int unk0c, FUN_00d38ed0_Local* unk10);

// @fnv 0x00d38ed0
void __cdecl FUN_00d38ed0(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_00d38ed0_Local local;

    local.unk04 = unk_104da48;
    local.unk08 = aiArg4;
    local.unk00 = unk_10ce7fc;

    FUN_00d386c0(aiArg2, aiArg1, aiArg3, &local);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d38b00(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d38f10(int a, int b, int c, Simplex* s);
};

// @fnv 0x00d38f10
void Agent::FUN_00d38f10(int a, int b, int c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    AgentBase::FUN_00d38b00(b, a, c, s);
    for (; v < s->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        __m128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}

struct hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};
struct hkVector4
{
    __m128 m_vComponents;
    float getW() const
    {
        return m_vComponents.m128_f32[3];
    }
};
union hkQuadVector
{
    hkVector4f v;
    __m128 q;
};

struct hkTransformf
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;
};

struct hkpConvexShapeHeader
{
    void* m_ppVirtualMethodTable;
    int m_ulUserData;
    int m_type;
    int unk0C;
};
struct hkpTriangleShape : hkpConvexShapeHeader
{
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kVertices[3];
    float getRadius() const
    {
        return m_fSphereRadius;
    }
};
struct hkpMultiSphereShape : hkpConvexShapeHeader
{
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kSpheres[8];
};
struct hkpCdBody
{
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransformf* m_pMotionState;
    const hkpCdBody* m_parent;
};
struct hkpCdBodyPairCollector
{
    virtual void dtor();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};
struct CollisionDistanceInfo
{
    hkVector4 m_kNearestPoint;
    float distance;
    int unk14;
    int unk18;
    int unk1C;
};
void __cdecl FUN_00cd7850(const hkVector4& position, const hkVector4* triangle, const S_00d37e60_Plane& cache,
                          CollisionDistanceInfo& result, void* featureOut);

static __forceinline __m128 SetTransformedPoint(const __m128& c0, const __m128& c1, const __m128& c2, const __m128& t,
                                                const __m128& b)
{
    const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t));
}

static __forceinline void TransformPointArray(const hkTransformf& t, const hkVector4* vectorsIn, int numVectors,
                                              hkVector4* vectorsOut)
{
    hkQuadVector c0;
    c0.v = t.m_kColumn0;
    hkQuadVector c1;
    c1.v = t.m_kColumn1;
    hkQuadVector c2;
    c2.v = t.m_kColumn2;
    hkQuadVector c3;
    c3.v = t.m_vTranslation;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i].m_vComponents = SetTransformedPoint(c0.q, c1.q, c2.q, c3.q, vectorsIn[i].m_vComponents);
    } while (--i >= 0);
}

struct hkpMultiSphereTriangleAgent : S_00d37e60_TriAgent
{
    void FUN_00d37ed0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                      hkpCdBodyPairCollector& collector);
};

// @fnv 0x00d37ed0
void hkpMultiSphereTriangleAgent::FUN_00d37ed0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                                               hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.m_pCollisionShape);
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.m_pCollisionShape);

    const hkVector4* localVertices = &triB->m_kVertices[0];
    hkVector4 triVertices[3];
    TransformPointArray(*bodyB.m_pMotionState, localVertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = &msA->m_kSpheres[0];
    hkVector4 worldSpheres[8];
    const int nsphere = msA->m_iSphereCount;
    TransformPointArray(*bodyA.m_pMotionState, localSpheres, nsphere, &worldSpheres[0]);

    for (int i = 0; i < nsphere; ++i)
    {
        float radiusSum = triB->getRadius() + localSpheres[i].m_vComponents.m128_f32[3];
        CollisionDistanceInfo cpr;
        FUN_00cd7850(worldSpheres[i], &triVertices[0], m_kTriangleNormal, cpr, 0);
        if (cpr.distance < radiusSum)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
            break;
        }
    }
}

void __cdecl FUN_00cd7850(const hkVector4& position, const hkVector4* triangle, const S_00d37e60_Plane& cache,
                          CollisionDistanceInfo& result, void* featureOut);
// @fnv 0x00d38130
void __cdecl FUN_00d38130(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                          hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = static_cast<const hkpMultiSphereShape*>(bodyA.m_pCollisionShape);
    const hkpTriangleShape* triB = static_cast<const hkpTriangleShape*>(bodyB.m_pCollisionShape);

    const hkVector4* localVertices = &triB->m_kVertices[0];
    hkVector4 triVertices[3];
    TransformPointArray(*bodyB.m_pMotionState, localVertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = &msA->m_kSpheres[0];
    hkVector4 worldSpheres[8];
    const int nsphere = msA->m_iSphereCount;
    TransformPointArray(*bodyA.m_pMotionState, localSpheres, nsphere, &worldSpheres[0]);

    S_00d37e60_Plane cache;
    FUN_00cd7160(localVertices, &cache);

    for (int i = 0; i < nsphere; ++i)
    {
        float radiusSum = triB->m_fSphereRadius + localSpheres[i].m_vComponents.m128_f32[3];
        CollisionDistanceInfo cpr;
        FUN_00cd7850(worldSpheres[i], &triVertices[0], cache, cpr, 0);
        if (cpr.distance < radiusSum)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
            break;
        }
    }
}
