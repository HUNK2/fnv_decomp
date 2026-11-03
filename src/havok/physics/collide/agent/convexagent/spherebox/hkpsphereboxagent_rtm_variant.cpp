// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern void __cdecl FUN_00d3c440(int a, int b, int c, int d);
void __stdcall ForwardToD3C440(int a, int b, int c, int d);
struct Conversion {
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry { void FUN_00cfbbe0(Conversion*, int, int); };
void FUN_00d3c400();
void FUN_00d3cfc0();
void FlipAndDispatchCollector();
void FUN_00d3ac80();
void CreateD3C380Obj();
void FUN_00d3c440();
void FUN_00d3cc00();
void FUN_00daf8e0();
void __cdecl FUN_00d3cef0(Registry* registry);
extern float DAT_0104da48;
extern void __cdecl FUN_00d3cc00(void*, void*, int, void*);
struct hkpSymmetricAgentFlipCollector {
    virtual void unk00();
    float unk04;
    int unk08;
};
void __cdecl FlipAndDispatchCollector(void* arg1, void* arg2, int arg3, int arg4);
struct S_00d3c3c0_Holder {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void v14(unsigned int idx, int arg);
};
struct S_00d3c3c0_Obj {
    virtual void v00(int flag);
    int unk04;
    S_00d3c3c0_Holder* unk08;
    unsigned short unk0c;
    void hkpSphereBoxAgent_cleanup(int arg);
};
struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct ObjAllocator {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};
struct SmallRecord {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};
extern char DAT_010cf018[];
AllocHolder* FUN_00c85750();
void __cdecl FUN_00d3c400(int aiUnused1, int aiUnused2, int aiUnused3, int d);
class D3CF80CollectorBase {
public:
    D3CF80CollectorBase() : m_bHit(false) {}
    virtual void AddCdPoint(const void* pkEvent) = 0;

    bool m_bHit;
};
class D3CF80Collector : public D3CF80CollectorBase {
public:
    D3CF80Collector(int iFilter) : m_iFilter(iFilter) {}
    virtual void AddCdPoint(const void* pkEvent);

    int m_iFilter;
};
class D3CF80Agent {
public:
    void ForwardToD3C440(void* pkA, void* pkB, void* pkInput, D3CF80Collector* pkCollector);
    void CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter);
};
extern void __cdecl FUN_00d3c440(int a, int b, int c, int d);
extern char DAT_010ce81c[];
struct FlipCollectorLocal {
    void* unk00;
    unsigned char unk04;
    int unk08;
};
void __cdecl FUN_00d3cfc0(int aiArg1, int aiArg2, int aiArg3, int a4);
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject {
    void FUN_00d3c910(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d3d000(void*, void*, unsigned int, unsigned int);
};
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
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
    void hkpSphereBoxAgent_processCollision(int a, int b, int c, Simplex* s);
};
struct Agent : AgentBase
{
    void FUN_00d3d080(int a, int b, int c, Simplex* s);
};

#include <windows.h>
extern "C" {
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_mul_ss(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_and_ps(__m128, __m128);
__m128 _mm_cmpeq_ss(__m128, __m128);
__m128 _mm_cmplt_ps(__m128, __m128);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_set_ss(float);
__m128 _mm_load_ss(float const*);
void _mm_store_ss(float*, __m128);
__m128 _mm_setzero_ps(void);
int _mm_movemask_ps(__m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
}

extern DWORD DAT_0126835c;
extern const char str_010cf050[];
extern const char str_010c41f8[];
class S3c5_Transform;

struct S3c5_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    __forceinline void setTime()
    {
        _ReadWriteBarrier();
        unsigned int ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&ticks;
    }
};

struct S3c5_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static __forceinline S3c5_MonitorStream& GetMonitorStream() { return *(S3c5_MonitorStream*)TlsGetValue(DAT_0126835c); }
    __forceinline bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    __forceinline char* GetStreamEnd() { return m_kRayEnd; }
    __forceinline void setEnd(char* e) { m_kRayEnd = e; }
};

__forceinline void S3c5_timer(const char* name)
{
    S3c5_MonitorStream& mStream = S3c5_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S3c5_TimerCommand* h = reinterpret_cast<S3c5_TimerCommand*>(mStream.GetStreamEnd());
        h->m_pCommandName = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}

class S3c5_SimdReal {
public:
    __forceinline S3c5_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline S3c5_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
private:
    __m128 m_vValue;
};
typedef const S3c5_SimdReal& S3c5_SimdRealParameter;

class S3c5_Comparison {
public:
    __forceinline int anyIsSet(int m) const { return _mm_movemask_ps(m_uiMask) & m; }
    __m128 m_uiMask;
};

class S3c5_Rotation;

class __declspec(align(16)) S3c5_Vector4 {
public:
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setSub4(const S3c5_Vector4& v0, const S3c5_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void setAbs4(const S3c5_Vector4& v)
    {
        static __declspec(align(16)) const unsigned int absMask[4] = { 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff };
        m_vComponents = _mm_and_ps(v.m_vComponents, *(const __m128*)&absMask);
    }
    __forceinline void setNeg4(const S3c5_Vector4& v)
    {
        static __declspec(align(16)) const unsigned int negateMask[4] = { 0x80000000, 0x80000000, 0x80000000, 0x80000000 };
        m_vComponents = _mm_xor_ps(v.m_vComponents, *(const __m128*)&negateMask);
    }
    __forceinline void setMin4(const S3c5_Vector4& a, const S3c5_Vector4& b) { m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad()); }
    __forceinline void setAddMul4(const S3c5_Vector4& a, const S3c5_Vector4& b, S3c5_SimdRealParameter r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline S3c5_Comparison compareLessThanZero4() const
    {
        S3c5_Vector4 zero; zero.setZero4();
        S3c5_Comparison m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
        return m;
    }
    __forceinline S3c5_SimdReal dot3(const S3c5_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S3c5_SimdReal lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined = _mm_mul_ss(
            _mm_mul_ss(half, approx),
            _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline S3c5_SimdReal normalizeWithLength3()
    {
        __m128 len2 = this->dot3(*this).getQuad();
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
        return _mm_mul_ss(len2, lenInv);
    }
    __forceinline void setXYZ(const S3c5_Vector4& xyz)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, m_vComponents), 0xc4);
    }
    __forceinline void _setRotatedDir(const S3c5_Rotation& r, const S3c5_Vector4& v);
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __forceinline __m128& getQuad() { return m_vComponents; }
    __forceinline const __m128& getQuad() const { return m_vComponents; }

    void FUN_00c7f690(const S3c5_Transform& t, const S3c5_Vector4& v);

__forceinline void negateSelf() { static const __declspec(align(16)) unsigned int sign[4] = {0x80000000,0x80000000,0x80000000,0x80000000}; m_vComponents = _mm_xor_ps(m_vComponents, *(const __m128*)sign); }
    __m128 m_vComponents;
};

class S3c5_Rotation {
public:
    __forceinline const S3c5_Vector4& getColumn(int i) const { return (&m_kColumn0)[i]; }
    S3c5_Vector4 m_kColumn0;
    S3c5_Vector4 m_kColumn1;
    S3c5_Vector4 m_kColumn2;
};

class S3c5_Transform {
public:
    __forceinline const S3c5_Rotation& getRotation() const { return m_rotation; }
    __forceinline const S3c5_Vector4& getTranslation() const { return m_vTranslation; }
    __forceinline const S3c5_Vector4& getColumn(int i) const { return m_rotation.getColumn(i); }
    S3c5_Rotation m_rotation;
    S3c5_Vector4 m_vTranslation;
};

__forceinline void S3c5_Vector4::_setRotatedDir(const S3c5_Rotation& a, const S3c5_Vector4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void S3c5_mulSigns4(S3c5_Vector4& inout, const S3c5_Vector4& signs)
{
    static __declspec(align(16)) const unsigned int signmask[4] = { 0x80000000, 0x80000000, 0x80000000, 0x80000000 };
    inout.getQuad() = _mm_xor_ps(inout.getQuad(), _mm_and_ps(signs.getQuad(), *(const __m128*)&signmask));
}

struct S3c5_Shape {
    void* vfptr;
    int unk04;
    int unk08;
    int unk0C;
};

struct S3c5_ConvexShape : S3c5_Shape {
    float m_fSphereRadius;
    __forceinline float getRadius() const { return m_fSphereRadius; }
};

struct S3c5_BoxShape : S3c5_ConvexShape {
    int unk14;
    int unk18;
    int unk1C;
    S3c5_Vector4 m_vHalfExtents;
    __forceinline const S3c5_Vector4& getHalfExtents() const { return m_vHalfExtents; }
};

struct S3c5_CdBody {
    const S3c5_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S3c5_CdBody* m_parent;
    __forceinline const S3c5_Shape* getShape() const { return m_pCollisionShape; }
    __forceinline const S3c5_Transform& getTransform() const { return *(const S3c5_Transform*)m_pMotionState; }
};

struct S3c5_CollisionInput {
    void* m_pCollisionDispatcher;
    int m_collisionQuality;
    float m_fScalar;
    __forceinline float getTolerance() const { return m_fScalar; }
};

class S3c5_ContactPoint {
public:
    __forceinline S3c5_Vector4& getPosition() { return m_vContactPosition; }
    __forceinline const S3c5_Vector4& getNormal() const { return m_vSeparatingNormal; }
    __forceinline S3c5_Vector4& getSeparatingNormal() { return m_vSeparatingNormal; }
    __forceinline void setNormal(const S3c5_Vector4& normal) { m_vSeparatingNormal.setXYZ(normal); }
    __forceinline void setDistance(float d) { m_vSeparatingNormal(3) = d; }
    S3c5_Vector4 m_vContactPosition;
    S3c5_Vector4 m_vSeparatingNormal;
};

struct S3c5_ProcessCdPoint {
    S3c5_ContactPoint m_kPoint;
    unsigned int m_usContactPointId;
};

struct S3c5_ConstraintOwner;

struct S3c5_ProcessCollisionOutput {
    S3c5_ProcessCdPoint* m_pAlignedPairData;
    S3c5_ConstraintOwner* m_pConstraintOwner;
    __forceinline S3c5_ProcessCdPoint* reserveContactPoints(int numPoints) { return m_pAlignedPairData; }
    __forceinline void commitContactPoints(int numPoints) { m_pAlignedPairData = m_pAlignedPairData + numPoints; }
    __forceinline void abortContactPoints(int numPoints) {}
};

class S3c5_ContactMgr {
public:
    __forceinline unsigned short addContactPoint(const S3c5_CdBody& a, const S3c5_CdBody& b, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& output, const void* contactCache, S3c5_ContactPoint& cp)
    {
        return CreateContactPoint(a, b, input, output, contactCache, cp);
    }
    __forceinline void removeContactPoint(unsigned short cpId, S3c5_ConstraintOwner& constraintOwner)
    {
        removeContactPointImpl(cpId, constraintOwner);
    }
    virtual ~S3c5_ContactMgr();
    virtual void v04();
    virtual void v08();
    virtual unsigned short CreateContactPoint(const S3c5_CdBody& a, const S3c5_CdBody& b, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& output, const void* contactCache, S3c5_ContactPoint& cp);
    virtual void v10();
    virtual void removeContactPointImpl(unsigned short cpId, S3c5_ConstraintOwner& constraintOwner);
};

class S3c5_SphereBoxAgent {
public:
    virtual ~S3c5_SphereBoxAgent();
    int m_usMemSizeAndFlags;
    S3c5_ContactMgr* m_pContactManager;
    unsigned short m_usContactPointId;

    void processContact(const S3c5_CdBody& bodyA, const S3c5_CdBody& bodyB, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& result);
    static __forceinline bool ComputeClosestPoints(const S3c5_CdBody& bodyA, const S3c5_CdBody& bodyB, const S3c5_CollisionInput& input, S3c5_ContactPoint& contactOut);
};

__forceinline bool S3c5_SphereBoxAgent::ComputeClosestPoints(const S3c5_CdBody& bodyA, const S3c5_CdBody& bodyB, const S3c5_CollisionInput& input, S3c5_ContactPoint& contactOut)
{
    const S3c5_Vector4& posA = bodyA.getTransform().getTranslation();
    S3c5_Vector4 posLocal;
    posLocal.FUN_00c7f690(bodyB.getTransform(), posA);

    const S3c5_BoxShape* boxB = static_cast<const S3c5_BoxShape*>(bodyB.getShape());
    const S3c5_ConvexShape* sphereA = static_cast<const S3c5_ConvexShape*>(bodyA.getShape());

    S3c5_Vector4 absPos; absPos.setAbs4(posLocal);
    S3c5_Vector4 clippedAbsPos; clippedAbsPos.setMin4(absPos, boxB->getHalfExtents());
    S3c5_Vector4 delta; delta.setSub4(clippedAbsPos, absPos);

    float distance;
    if (delta.compareLessThanZero4().anyIsSet(7))
    {
        distance = delta.normalizeWithLength3();
        distance -= sphereA->getRadius() + boxB->getRadius();
        if (distance > input.getTolerance())
        {
            return false;
        }
        S3c5_mulSigns4(delta, posLocal);
        delta.setNeg4(delta);
        contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        float dx = absPos(0) - boxB->getHalfExtents()(0);
        float dy = absPos(1) - boxB->getHalfExtents()(1);
        float dz = absPos(2) - boxB->getHalfExtents()(2);
        int axis;
        if (dx > dy)
        {
            if (dx > dz)
            {
                axis = 0;
                contactOut.setNormal(bodyB.getTransform().getColumn(0));
                distance = dx;
            }
            else
            {
                axis = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        else
        {
            if (dy > dz)
            {
                axis = 1;
                contactOut.setNormal(bodyB.getTransform().getColumn(1));
                distance = dy;
            }
            else
            {
                axis = 2;
                contactOut.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        if (posLocal(axis) < 0.0f)
        {
            contactOut.getSeparatingNormal().negateSelf();
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }
    contactOut.getPosition().setAddMul4(posA, contactOut.getNormal(), -distance - sphereA->getRadius());
    contactOut.setDistance(distance);
    contactOut.getPosition()(3) = 1.0f;
    return true;
}


__forceinline void S3c5_endTimer(const char* name, unsigned int& ticks)
{
    S3c5_MonitorStream& stream = S3c5_MonitorStream::GetMonitorStream();
    if (stream.memoryAvailable()) {
        S3c5_TimerCommand* h = (S3c5_TimerCommand*)stream.GetStreamEnd();
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&ticks;
        stream.setEnd((char*)(h + 1));
    }
}
__forceinline void S3c5_SphereBoxAgent::processContact(const S3c5_CdBody& bodyA, const S3c5_CdBody& bodyB, const S3c5_CollisionInput& input, S3c5_ProcessCollisionOutput& result)
{
    union Saved { S3c5_SphereBoxAgent* self; unsigned int ticks; } saved;
    saved.self = this;
    S3c5_timer(str_010cf050);

    S3c5_ProcessCdPoint* point = result.reserveContactPoints(1);

    if (ComputeClosestPoints(bodyA, bodyB, input, point->m_kPoint))
    {
        S3c5_SphereBoxAgent* agent = *(S3c5_SphereBoxAgent* volatile*)&saved.self;
        if (agent->m_usContactPointId == 0xffff)
        {
            agent->m_usContactPointId = agent->m_pContactManager->addContactPoint(bodyA, bodyB, input, result, 0, point->m_kPoint);
        }

        if (agent->m_usContactPointId != 0xffff)
        {
            point->m_usContactPointId = agent->m_usContactPointId;
            result.commitContactPoints(1);
        }
        else
        {
            result.abortContactPoints(1);
        }
    }
    else
    {
        result.abortContactPoints(1);
        S3c5_SphereBoxAgent* agent = *(S3c5_SphereBoxAgent* volatile*)&saved.self;
        if (agent->m_usContactPointId != 0xffff)
        {
            agent->m_pContactManager->removeContactPoint(agent->m_usContactPointId, *result.m_pConstraintOwner);
            agent->m_usContactPointId = 0xffff;
        }
    }

    S3c5_endTimer(str_010c41f8, saved.ticks);
}

// @fnv 0x00d3c5b0
void AgentBase::hkpSphereBoxAgent_processCollision(int a, int b, int c, Simplex* s)
{
    ((S3c5_SphereBoxAgent*)this)->processContact(*(const S3c5_CdBody*)a, *(const S3c5_CdBody*)b, *(const S3c5_CollisionInput*)c, *(S3c5_ProcessCollisionOutput*)s);
}

extern "C" {
__m128 _mm_and_ps(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_cmplt_ps(__m128, __m128);
__m128 _mm_cmpeq_ss(__m128, __m128);
__m128 _mm_setzero_ps(void);
__m128 _mm_set_ss(float);
__m128 _mm_load_ss(const float*);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_mul_ss(__m128, __m128);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_unpackhi_ps(__m128, __m128);
int _mm_movemask_ps(__m128);
void _mm_store_ss(float*, __m128);
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}

extern unsigned long DAT_0126835c;
extern const char str_010cf050[];
extern const char str_010c41f8[];
extern const unsigned int DAT_01017d10[4];
extern const unsigned int DAT_010c44d0[4];

struct S00d3c910_TimerCommand
{
    const char* m_kStringBuffer;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime()
    {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};

struct S00d3c910_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;

    static S00d3c910_MonitorStream& GetMonitorStream() { return *(S00d3c910_MonitorStream*)TlsGetValue(DAT_0126835c); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    char* GetStreamEnd() { return m_kRayEnd; }
    void setEnd(char* e) { m_kRayEnd = e; }
};

static __forceinline void S00d3c910_timerBegin(const char* name)
{
    S00d3c910_MonitorStream& mStream = S00d3c910_MonitorStream::GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        S00d3c910_TimerCommand* h = (S00d3c910_TimerCommand*)mStream.GetStreamEnd();
        h->m_kStringBuffer = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}

struct S00d3c910_SimdReal
{
    __m128 m_vValue;
    __forceinline S00d3c910_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline S00d3c910_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    const __m128& getQuad() const { return m_vValue; }
};

struct S00d3c910_Comparison
{
    __m128 m_uiMask;
    int anyIsSet(int m) const { return _mm_movemask_ps(m_uiMask) & m; }
};

struct S00d3c910_Matrix3;

struct __declspec(align(16)) S00d3c910_Vector4
{
    __m128 m_vComponents;

    float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __m128& getQuad() { return m_vComponents; }
    const __m128& getQuad() const { return m_vComponents; }

    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    void FUN_00c7f690(const struct S00d3c910_Transform& a, const S00d3c910_Vector4& b);
    void setAbs4(const S00d3c910_Vector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, *(const __m128*)&DAT_01017d10);
    }
    void setMin4(const S00d3c910_Vector4& a, const S00d3c910_Vector4& b) { m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad()); }
    void setSub4(const S00d3c910_Vector4& a, const S00d3c910_Vector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void setNeg4(const S00d3c910_Vector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, *(const __m128*)&DAT_010c44d0);
    }
    __forceinline void setXYZ(const S00d3c910_Vector4& xyz)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, m_vComponents), 0xc4);
    }
    __forceinline void setAddMul4(const S00d3c910_Vector4& a, const S00d3c910_Vector4& b, const S00d3c910_SimdReal& r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline S00d3c910_Comparison compareLessThanZero4() const
    {
        S00d3c910_Vector4 zero; zero.setZero4();
        S00d3c910_Comparison m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
        return m;
    }
    __forceinline S00d3c910_SimdReal dot3(const S00d3c910_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d3c910_SimdReal lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined = _mm_mul_ss(
            _mm_mul_ss(half, approx),
            _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline S00d3c910_SimdReal normalizeWithLength3()
    {
        __m128 len2 = this->dot3(*this).getQuad();
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
        return _mm_mul_ss(len2, lenInv);
    }
    void _setMul3(const S00d3c910_Matrix3& a, const S00d3c910_Vector4& b);
    __forceinline void _setRotatedDir(const S00d3c910_Matrix3& r, const S00d3c910_Vector4& v) { _setMul3(r, v); }
};

struct S00d3c910_Matrix3
{
    S00d3c910_Vector4 m_kColumn0;
    S00d3c910_Vector4 m_kColumn1;
    S00d3c910_Vector4 m_kColumn2;
    const S00d3c910_Vector4& getColumn(int i) const { return (&m_kColumn0)[i]; }
};

struct S00d3c910_Transform
{
    S00d3c910_Matrix3 m_rotation;
    S00d3c910_Vector4 m_vTranslation;
    const S00d3c910_Matrix3& getRotation() const { return m_rotation; }
    const S00d3c910_Vector4& getTranslation() const { return m_vTranslation; }
    const S00d3c910_Vector4& getColumn(int i) const { return m_rotation.getColumn(i); }
};

__forceinline void S00d3c910_Vector4::_setMul3(const S00d3c910_Matrix3& a, const S00d3c910_Vector4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

namespace S00d3c910_Util
{
    extern const unsigned int DAT_010c44d0[4];

    __forceinline void mulSigns4(S00d3c910_Vector4& inout, const S00d3c910_Vector4& signs)
    {
        inout.getQuad() = _mm_xor_ps(inout.getQuad(),
            _mm_and_ps(signs.getQuad(), *(const __m128*)&DAT_010c44d0));
    }
}

struct S00d3c910_Shape
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

struct S00d3c910_ConvexShape : S00d3c910_Shape
{
    float m_fSphereRadius;
    float getRadius() const { return m_fSphereRadius; }
};

struct S00d3c910_BoxShape : S00d3c910_ConvexShape
{
    int unk14;
    int unk18;
    int unk1c;
    S00d3c910_Vector4 m_vHalfExtents;
    const S00d3c910_Vector4& getHalfExtents() const { return m_vHalfExtents; }
};

struct S00d3c910_CdBody
{
    const S00d3c910_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S00d3c910_CdBody* m_parent;
    const S00d3c910_Shape* getShape() const { return m_pCollisionShape; }
    const S00d3c910_Transform& getTransform() const { return *static_cast<const S00d3c910_Transform*>(m_pMotionState); }
};

struct S00d3c910_CollisionInput
{
    void* m_pCollisionDispatcher;
    int m_collisionQuality;
    float m_fScalar;
    float getTolerance() const { return m_fScalar; }
};

struct S00d3c910_ContactPoint
{
    S00d3c910_Vector4 m_vContactPosition;
    S00d3c910_Vector4 m_vSeparatingNormal;

    S00d3c910_Vector4& getPosition() { return m_vContactPosition; }
    const S00d3c910_Vector4& getNormal() const { return m_vSeparatingNormal; }
    S00d3c910_Vector4& getSeparatingNormal() { return m_vSeparatingNormal; }
    void setNormal(const S00d3c910_Vector4& normal) { m_vSeparatingNormal.setXYZ(normal); }
    void setDistance(float d) { m_vSeparatingNormal(3) = d; }
};

struct S00d3c910_CdPoint
{
    S00d3c910_ContactPoint m_kPoint;
    const S00d3c910_CdBody& m_pBodyA;
    const S00d3c910_CdBody& m_pBodyB;
    S00d3c910_CdPoint(const S00d3c910_CdBody& a, const S00d3c910_CdBody& b) : m_pBodyA(a), m_pBodyB(b) {}
};

struct S00d3c910_CdPointCollector
{
    virtual ~S00d3c910_CdPointCollector();
    virtual void AddCdPoint(const S00d3c910_CdPoint& event);
};

struct S00d3c910_Bool
{
    char m_cBooleanValue;
    S00d3c910_Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct S00d3c910_SphereBoxAgent
{
    static bool ComputeClosestPoints(const S00d3c910_CdBody& bodyA, const S00d3c910_CdBody& bodyB,
        const S00d3c910_CollisionInput& input, S00d3c910_ContactPoint& contact);
    void FUN_00d3c910(const S00d3c910_CdBody& bodyA, const S00d3c910_CdBody& bodyB,
        const S00d3c910_CollisionInput& input, S00d3c910_CdPointCollector& collector);
};

__forceinline bool S00d3c910_SphereBoxAgent::ComputeClosestPoints(const S00d3c910_CdBody& bodyA, const S00d3c910_CdBody& bodyB,
    const S00d3c910_CollisionInput& input, S00d3c910_ContactPoint& contact)
{
    const S00d3c910_Vector4& posA = bodyA.getTransform().getTranslation();
    S00d3c910_Vector4 posLocal;
    posLocal.FUN_00c7f690(bodyB.getTransform(), posA);

    const S00d3c910_BoxShape* boxB = static_cast<const S00d3c910_BoxShape*>(bodyB.getShape());
    const S00d3c910_ConvexShape* sphereA = static_cast<const S00d3c910_ConvexShape*>(bodyA.getShape());

    S00d3c910_Vector4 absPos; absPos.setAbs4(posLocal);
    S00d3c910_Vector4 clipped; clipped.setMin4(absPos, boxB->getHalfExtents());
    S00d3c910_Vector4 delta; delta.setSub4(clipped, absPos);

    float distance;
    if (delta.compareLessThanZero4().anyIsSet(7))
    {
        distance = delta.normalizeWithLength3();
        distance = distance - (sphereA->getRadius() + boxB->getRadius());
        if (distance > input.getTolerance())
        {
            return false;
        }
        S00d3c910_Util::mulSigns4(delta, posLocal);
        delta.setNeg4(delta);
        contact.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(), delta);
    }
    else
    {
        float dx = absPos(0) - boxB->getHalfExtents()(0);
        float dy = absPos(1) - boxB->getHalfExtents()(1);
        float dz = absPos(2) - boxB->getHalfExtents()(2);
        int axis;
        if (dx > dy)
        {
            if (dx > dz)
            {
                axis = 0;
                contact.setNormal(bodyB.getTransform().getColumn(0));
                distance = dx;
            }
            else
            {
                axis = 2;
                contact.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        else
        {
            if (dy > dz)
            {
                axis = 1;
                contact.setNormal(bodyB.getTransform().getColumn(1));
                distance = dy;
            }
            else
            {
                axis = 2;
                contact.setNormal(bodyB.getTransform().getColumn(2));
                distance = dz;
            }
        }
        if (posLocal(axis) < 0.0f)
        {
            contact.getSeparatingNormal().setNeg4(contact.getSeparatingNormal());
        }
        distance = distance - boxB->getRadius() - sphereA->getRadius();
    }
    contact.getPosition().setAddMul4(posA, contact.getNormal(), -distance - sphereA->getRadius());
    contact.setDistance(distance);
    contact.getPosition()(3) = 1.0f;
    return true;
}

// @fnv 0x00d3c910
void S00d3c910_SphereBoxAgent::FUN_00d3c910(const S00d3c910_CdBody& bodyA, const S00d3c910_CdBody& bodyB,
    const S00d3c910_CollisionInput& input, S00d3c910_CdPointCollector& collector)
{
    S00d3c910_timerBegin(str_010cf050);

    S00d3c910_CdPoint event(bodyA, bodyB);
    if (ComputeClosestPoints(bodyA, bodyB, input, event.m_kPoint))
    {
        collector.AddCdPoint(event);
    }

    S00d3c910_timerBegin(str_010c41f8);
}

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
extern "C"{
__declspec(dllimport)void*_stdcall TlsGetValue(unsigned long dwTlsIndex);}
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
class hkMemoryAllocator
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pStreamAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};

extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ss(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ss(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_rsqrt_ss(__m128 _A);
extern __m128 _mm_min_ps(__m128 _A,__m128 _B);
extern __m128 _mm_and_ps(__m128 _A,__m128 _B);
extern __m128 _mm_andnot_ps(__m128 _A,__m128 _B);
extern __m128 _mm_xor_ps(__m128 _A,__m128 _B);
extern __m128 _mm_cmpeq_ss(__m128 _A,__m128 _B);
extern __m128 _mm_cmplt_ps(__m128 _A,__m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
extern __m128 _mm_unpackhi_ps(__m128 _A,__m128 _B);
extern int _mm_movemask_ps(__m128 _A);
extern __m128 _mm_set_ss(float _A);
extern __m128 _mm_setzero_ps(void);
extern __m128 _mm_load_ss(float const*_A);
extern void _mm_store_ss(float*_V,__m128 _A);};
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
operator hkReal()const
{
hkReal s;
_mm_store_ss(&s,m_vValue);
return s;
}
hkReal storeInto(hkReal& scalar) const { _mm_store_ss(&scalar,m_vValue); return scalar; }
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};__forceinline hkBool32 anyIsSet(Mask m)const{return _mm_movemask_ps(m_uiMask)&m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4;};
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void setZero4();
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r);
__forceinline Vector4Comparison compareLessThanZero4()const;
__forceinline void setNeg4(const hkVector4&v);
__forceinline void setAbs4(const hkVector4&v);
__forceinline void setMin4(const hkVector4&a,const hkVector4&b);
void SetTransformedPosition(const hkTransform&a,const hkVector4&b);
__forceinline void _setMul3(const hkMatrix3&a,const hkVector4&b);
__forceinline void _setRotatedDir(const hkRotation&a,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline VectorComponentValue normalizeWithLength3();
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
__forceinline void setXYZ(const hkVector4&v);
__forceinline hkQuadReal&getQuad();
__forceinline const hkQuadReal&getQuad()const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
__forceinline const hkVector4&getColumn(int i)const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
inline hkQuadReal&hkVector4::getQuad()
{
return m_vComponents;
}
inline const hkQuadReal&hkVector4::getQuad()const
{
return m_vComponents;
}
inline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline Vector4Comparison hkVector4::compareLessThanZero4()const
{
hkVector4 zero;zero.setZero4();
Vector4Comparison m;m.m_uiMask=_mm_cmplt_ps(m_vComponents,zero);
return m;
}
inline void hkVector4::setNeg4(const hkVector4&v)
{
static __declspec(align(16))const hkUint32 negateMask[4]={0x80000000,0x80000000,0x80000000,0x80000000};
m_vComponents=_mm_xor_ps(v.m_vComponents,*(const hkQuadReal*)&negateMask);
}
inline void hkVector4::setAbs4(const hkVector4&v)
{
static __declspec(align(16))const hkUint32 absMask[4]={0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff};
m_vComponents=_mm_and_ps(v.m_vComponents,*(const hkQuadReal*)&absMask);
}
inline void hkVector4::setMin4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_min_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::_setMul3(const hkMatrix3&a,const hkVector4&b)
{
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(a.getColumn(0).m_vComponents,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(a.getColumn(1).m_vComponents,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(a.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
inline void hkVector4::_setRotatedDir(const hkRotation&r,const hkVector4&v)
{
_setMul3(r,v);
}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline VectorComponentValue hkVector4::normalizeWithLength3()
{
hkQuadReal len2=this->dot3(*this).getQuad();
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
return _mm_mul_ss(len2,lenInv);
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline void hkVector4::setXYZ(const hkVector4&xyz)
{
m_vComponents=_mm_shuffle_ps(xyz.m_vComponents,_mm_unpackhi_ps(xyz.m_vComponents,m_vComponents),(((3)<<6)|((0)<<4)|((1)<<2)|((0))));
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getColumn(int x)const
{
return m_rotation.getColumn(x);
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>g_pMonitorStream;
return*g_pMonitorStream.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime(hkUint32& ticks);
};};
void StringCursor::CommandTimingEntry::setTime(hkUint32& ticks)
{
_ReadWriteBarrier();
ticks = (hkUint32)__rdtsc();
m_uiStartTicks = *(volatile hkUint32*)&ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;};typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4&getPosition();
inline const hkVector4&getNormal()const;
inline hkVector4&getSeparatingNormal();
inline void setNormal(const hkVector4&normal);
inline void setDistance(hkReal d);
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};inline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
inline void hkContactPoint::setNormal(const hkVector4&normal)
{
m_vSeparatingNormal.setXYZ(normal);
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
class hkpCollisionDispatcher;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector();
virtual void AddCdPoint(const ContactPointPair&point)=0;
protected:
hkReal m_fEarlyOutDistance;};
struct WorldOperationEntry;
class hkpCdBodyPairCollector;
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
inline hkpCollisionAgent(hkpContactMgr*contactMgr);
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
hkpIterativeLinearCastAgent(hkpContactMgr*contactMgr):hkpCollisionAgent(contactMgr){}
};
class hkpSphereBoxAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);

virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
static hkpCollisionAgent*__cdecl createSphereBoxAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBoxSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
__forceinline hkpSphereBoxAgent(hkpContactMgr*mgr):hkpIterativeLinearCastAgent(mgr){m_usContactPointId=(0xffff);}
public:
static __forceinline hkBool ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&contactOut,hkReal& scalarScratch);
protected:
hkContactPointId m_usContactPointId;
};
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkReal getRadius()const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
class hkpBoxShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4&getHalfExtents()const;
protected:
hkVector4 m_vHalfExtents;
public:
~hkpBoxShape();};
inline const hkVector4&hkpBoxShape::getHalfExtents()const
{
return m_vHalfExtents;
}
class hkpSphereShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkpSphereShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_SPHERE;}
};
namespace hkVector4Util_S
{
__forceinline void __cdecl mulSigns4(hkVector4&inout,const hkVector4&signsSource);}
inline void __cdecl hkVector4Util_S::mulSigns4(hkVector4&inout,const hkVector4&signs)
{
static __declspec(align(16))const hkUint32 signmask[4]=
{0x80000000,0x80000000,0x80000000,0x80000000};
inout.getQuad()=_mm_xor_ps(inout.getQuad(),
_mm_and_ps(signs.getQuad(),*(const hkQuadReal*)&signmask));}
__forceinline hkBool hkpSphereBoxAgent::ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&contactOut,hkReal& scalarScratch)
{
const hkVector4&posA=bodyA.getTransform().getTranslation();
hkVector4 posLocalB;posLocalB.SetTransformedPosition(bodyB.getTransform(),posA);
const hkpBoxShape*boxB=static_cast<const hkpBoxShape*>(bodyB.getShape());
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
hkVector4 absPosB;absPosB.setAbs4(posLocalB);
hkVector4 clippedAbsPos;clippedAbsPos.setMin4(absPosB,boxB->getHalfExtents());
hkVector4 delta;delta.setSub4(clippedAbsPos,absPosB);
hkReal distance;
if(delta.compareLessThanZero4().anyIsSet(Vector4Comparison::MASK_XYZ))
{
distance=delta.normalizeWithLength3().storeInto(scalarScratch);
distance=distance-(sphereA->getRadius()+boxB->getRadius());
if(distance>input.getTolerance())
{
return false;
}
hkVector4Util_S::mulSigns4(delta,posLocalB);
delta.setNeg4(delta);
contactOut.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(),delta);
}
else
{
hkReal d0=absPosB(0)-boxB->getHalfExtents()(0);
hkReal d1=absPosB(1)-boxB->getHalfExtents()(1);
hkReal d2=absPosB(2)-boxB->getHalfExtents()(2);
int i;
if(d0>d1)
{
if(d0>d2)
{
i=0;
contactOut.setNormal(bodyB.getTransform().getColumn(0));
distance=d0;
}
else
{
i=2;
contactOut.setNormal(bodyB.getTransform().getColumn(2));
distance=d2;
}
}
else
{
if(d1>d2)
{
i=1;
contactOut.setNormal(bodyB.getTransform().getColumn(1));
distance=d1;
}
else
{
i=2;
contactOut.setNormal(bodyB.getTransform().getColumn(2));
distance=d2;
}
}
if(posLocalB(i)<0)
{
contactOut.getSeparatingNormal().setNeg4(contactOut.getSeparatingNormal());
}
distance=distance-boxB->getRadius()-sphereA->getRadius();
}
contactOut.getPosition().setAddMul4(posA,contactOut.getNormal(),-distance-sphereA->getRadius());
contactOut.setDistance(distance);
contactOut.getPosition()(3)=1.0f;
return true;}
// @fnv 0x00d3cc00
void __cdecl FUN_00d3cc00(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
hkUint32 ticks;
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "SphereBox";h->setTime(ticks);mStream.setEnd((char*)(h+1));}};
ContactPointPair event(bodyA,bodyB);
if(hkpSphereBoxAgent::ComputeClosestPoints(bodyA,bodyB,input,event.m_kPoint,reinterpret_cast<hkReal&>(ticks)))
{
collector.AddCdPoint(event);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime(ticks);mStream.setEnd((char*)(h+1));}};
}
