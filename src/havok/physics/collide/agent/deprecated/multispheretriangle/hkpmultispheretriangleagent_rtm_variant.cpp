// src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00d37e60_Allocator {
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};
struct S_00d37e60_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d37e60_Allocator* m_pStreamAllocator;
    S_00d37e60_Allocator& heap() { return *m_pStreamAllocator; }
};
S_00d37e60_Router* FUN_00c85750();
struct S_00d37e60_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d37e60_RefObj() { m_sReferenceCount = 1; }
    virtual ~S_00d37e60_RefObj() throw() {}
    void* operator new(unsigned int nbytes)
    {
        S_00d37e60_RefObj* b = static_cast<S_00d37e60_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*) {}
};
struct S_00d37e60_Agent : S_00d37e60_RefObj {
    void* m_pContactManager;
    S_00d37e60_Agent(void* mgr) : m_pContactManager(mgr) {}
    virtual void getPenetrations();
};
struct S_00d37e60_Shape {
    int unk0[8];
};
struct S_00d37e60_CdBody {
    char* m_pCollisionShape;
};
struct S_00d37e60_Plane {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};
void FUN_00cd7160(const void* verts, S_00d37e60_Plane* out) throw();
struct S_00d37e60_TriAgent : S_00d37e60_Agent {
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
struct S_00d37e60_TriAgent2 : S_00d37e60_TriAgent {
    __forceinline S_00d37e60_TriAgent2(const S_00d37e60_CdBody& bodyA, void* mgr) : S_00d37e60_TriAgent(bodyA, mgr) {}
    virtual void getPenetrations();
};
S_00d37e60_Agent* CreateTriAgent2(const S_00d37e60_CdBody& bodyA, const S_00d37e60_CdBody& bodyB, const void* input, void* mgr);
void __cdecl FUN_00d38130(void*, void*, void*, void*);
struct D38AC0Data {
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
};
void __cdecl FUN_00d38ac0(void* first, void* second, void* third, int fourth);
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject {
    void FUN_00d38390(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d38e90(void*, void*, unsigned int, unsigned int);
};
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
struct CallbackState {
    const void* type;
    bool completed;
    unsigned context;
};
extern const unsigned vtable_010ce81c[];
struct Operation {
    void FUN_00d37ed0(unsigned second, unsigned first,
                      unsigned third, CallbackState* callback);
    void FUN_00d38a80(unsigned first, unsigned second,
                      unsigned third, unsigned context);
};
// Stand-in for the 12-byte record the callee receives by pointer.
// Field order/offsets come from the target frame layout:
//   +0 : pointer, +4 : float, +8 : dword
struct FUN_00d38ed0_Local
{
    const char* unk00;
    float       unk04;
    int         unk08;
};
// Global float loaded with `fld dword ptr [0x104da48]`.
extern float unk_104da48;
// Global object whose address (0x10ce7fc) is stored into the record.
extern char unk_10ce7fc[];
// Callee at 0x00d386c0: __cdecl, four arguments,
// the last one being a pointer to the record built on the stack.
void __cdecl FUN_00d386c0(int unk04, int unk08, int unk0c, FUN_00d38ed0_Local* unk10);
void __cdecl FUN_00d38ed0(int aiArg1, int aiArg2, int aiArg3, int aiArg4);
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
    void FUN_00d38b00(int a, int b, int c, Simplex* s);
};
struct Agent : AgentBase
{
    void FUN_00d38f10(int a, int b, int c, Simplex* s);
};
struct hkVector4f { float x; float y; float z; float w; };
struct hkVector4 { __m128 m_vComponents; float getW() const { return m_vComponents.m128_f32[3]; } };
union hkQuadVector { hkVector4f v; __m128 q; };
struct hkTransformf {
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;
};
struct hkpConvexShapeHeader {
    void* m_ppVirtualMethodTable;
    int m_ulUserData;
    int m_type;
    int unk0C;
};
struct hkpTriangleShape : hkpConvexShapeHeader {
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kVertices[3];
    float getRadius() const { return m_fSphereRadius; }
};
struct hkpMultiSphereShape : hkpConvexShapeHeader {
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kSpheres[8];
};
struct hkpCdBody {
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransformf* m_pMotionState;
    const hkpCdBody* m_parent;
};
struct hkpCdBodyPairCollector {
    virtual void dtor();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};
struct CollisionDistanceInfo {
    hkVector4 m_kNearestPoint;
    float distance;
    int unk14;
    int unk18;
    int unk1C;
};
void __cdecl FUN_00cd7850(const hkVector4& position, const hkVector4* triangle, const S_00d37e60_Plane& cache,
                          CollisionDistanceInfo& result, void* featureOut);
static __forceinline __m128 SetTransformedPoint(const __m128& c0, const __m128& c1, const __m128& c2, const __m128& t, const __m128& b)
{
    const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t));
}
static __forceinline void TransformPointArray(const hkTransformf& t, const hkVector4* vectorsIn, int numVectors, hkVector4* vectorsOut)
{
    hkQuadVector c0; c0.v = t.m_kColumn0;
    hkQuadVector c1; c1.v = t.m_kColumn1;
    hkQuadVector c2; c2.v = t.m_kColumn2;
    hkQuadVector c3; c3.v = t.m_vTranslation;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i].m_vComponents = SetTransformedPoint(c0.q, c1.q, c2.q, c3.q, vectorsIn[i].m_vComponents);
    }
    while (--i >= 0);
}
struct hkpMultiSphereTriangleAgent : S_00d37e60_TriAgent {
    void FUN_00d37ed0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input, hkpCdBodyPairCollector& collector);
};
void __cdecl FUN_00cd7850(const hkVector4& position, const hkVector4* triangle, const S_00d37e60_Plane& cache,
                          CollisionDistanceInfo& result, void* featureOut);
void __cdecl FUN_00d38130(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input, hkpCdBodyPairCollector& collector);

extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
void _ReadWriteBarrier(void);
unsigned __int64 __rdtsc(void);
__m128 _mm_load_ss(const float*);
}
struct VectorWords { unsigned int x, y, z, w; };
struct FloatWords { float x, y, z, w; };
union FourFloatVector { __m128 q; VectorWords bits; FloatWords values; };
struct TransformStorage { VectorWords x, y, z, translation; };
struct Shape {
    virtual ~Shape();
    unsigned short allocationSize;
    short referenceCount;
    unsigned int userData, type;
};
struct TriangleShape : Shape {
    float radius;
    unsigned int unknown14, unknown18, unknown1C;
    FourFloatVector vertices[3];
};
struct MultiSphereShape : Shape {
    int count;
    unsigned int unknown14, unknown18, unknown1C;
    FourFloatVector spheres[8];
};
struct CollisionBody { void* shape; unsigned int key; const TransformStorage* transform; const CollisionBody* parent; };
struct CollisionInput { unsigned int flags, quality; float tolerance; };
struct TriangleCache { float edge0, edge1, edge2, inverseArea; };
struct ClosestPointUtilities { FourFloatVector normal; float distance; };
struct Contact {
    FourFloatVector position, normal;
    const CollisionBody* bodyA;
    const CollisionBody* bodyB;
};
struct ContactCollector {
    virtual void destructor();
    virtual void AddContact(const Contact&);
};
struct TimerRecord { const char* name; unsigned int ticks; unsigned int extra; };
struct Monitor { TimerRecord* start; TimerRecord* next; TimerRecord* capacity; TimerRecord* limit; };
extern unsigned long DAT_0126835c;
void __cdecl FUN_00cd7850(const FourFloatVector*, const FourFloatVector*, TriangleCache*, ClosestPointUtilities*, unsigned char*);
static __forceinline __m128 TransformPoint(const __m128& tx, const __m128& ty, const __m128& tz, const __m128& tt, const __m128& v)
{
    return _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), tx),
                   _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), ty)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), tz),
                   tt));
}
static __forceinline VectorWords CopyWords(const VectorWords& from) {return from;}
static __forceinline VectorWords CopyOther(const VectorWords& from) { VectorWords r = {from.x,from.y,from.z,from.w}; return r; }
struct SphereTriangleAgent {
    unsigned int state, flags, key;
    TriangleCache plane;
    void FUN_00d38390(const CollisionBody*, const CollisionBody*, const CollisionInput*, ContactCollector*);
};
// @fnv 0x00d38390
void SphereTriangleAgent::FUN_00d38390(const CollisionBody* bodyA, const CollisionBody* bodyB, const CollisionInput* input, ContactCollector* collector)
{
    volatile unsigned int timerTicks;
    ClosestPointUtilities closest;
    {
        Monitor* timerMonitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
        TimerRecord* timerRecord = timerMonitor->next;
        if (timerRecord < timerMonitor->limit) {
            timerRecord->name = "TtMultiSphereTriangle";
            _ReadWriteBarrier();
            timerTicks = static_cast<unsigned int>(__rdtsc());
            timerRecord->ticks = timerTicks;
            timerMonitor->next = timerRecord + 1;
        }
    }
    MultiSphereShape* __restrict spheres = static_cast<MultiSphereShape*>(bodyA->shape);
    TriangleShape* triangle = static_cast<TriangleShape*>(bodyB->shape);
    FourFloatVector triangleWorld[3];
    {
    const TransformStorage* __restrict tb = bodyB->transform;
    FourFloatVector bxv; bxv.bits = CopyOther(tb->x); __m128 bx = bxv.q;
    FourFloatVector byv; byv.bits = CopyWords(tb->y); __m128 by = byv.q;
    FourFloatVector bzv; bzv.bits = CopyOther(tb->z); __m128 bz = bzv.q;
    closest.normal.bits = CopyWords(tb->translation); __m128 bt = closest.normal.q;
    const FourFloatVector* triVerts = triangle->vertices;
    for (int i = 2; i >= 0; --i) {
        triangleWorld[i].q = TransformPoint(bx, by, bz, bt, triVerts[i].q);
    }
    }
    FourFloatVector spheresWorld[8];
    const FourFloatVector* sourceSphere = spheres->spheres;
    const int count = spheres->count;
    {
    const TransformStorage* __restrict ta = bodyA->transform;
    closest.normal.bits = CopyWords(ta->x); __m128 ax = closest.normal.q;
    FourFloatVector ayv; ayv.bits = CopyWords(ta->y); __m128 ay = ayv.q;
    FourFloatVector azv; azv.bits = CopyWords(ta->z); __m128 az = azv.q;
    FourFloatVector atv; atv.bits = CopyWords(ta->translation); __m128 at = atv.q;
    int sphereIndex = count - 1;
    do {
        spheresWorld[sphereIndex].q = TransformPoint(ax, ay, az, at, sourceSphere[sphereIndex].q);
    } while (--sphereIndex >= 0);
    }
    const FourFloatVector* originalSource=sourceSphere;
    Contact contact;
    contact.bodyA = bodyA;
    contact.bodyB = bodyB;
    {
        for (int index = 0; index < count; ++index) {
        TriangleCache* triPlane = &plane;
            const FourFloatVector* current = &spheresWorld[index];
            float radiusSum=*static_cast<const volatile float*>(&triangle->radius)+sourceSphere[index].values.w;
            FUN_00cd7850(current, triangleWorld, triPlane, &closest, 0);
const float& distance = closest.distance;
float threshold = input->tolerance + radiusSum;
            if (distance < threshold) {
                float offset = triangle->radius - distance;
                __m128 off = _mm_load_ss(&offset);
                contact.position.q = _mm_add_ps(current->q, _mm_mul_ps(_mm_shuffle_ps(off, off, 0), closest.normal.q));
                contact.normal.q = closest.normal.q;
                contact.normal.values.w = distance - radiusSum;
                collector->AddContact(contact);
            }


        }
    }
    {
        Monitor* timerMonitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
        TimerRecord* timerRecord = timerMonitor->next;
        if (timerRecord < timerMonitor->limit) {
            timerRecord->name = "Et";
            _ReadWriteBarrier();
            timerTicks = static_cast<unsigned int>(__rdtsc());
            timerRecord->ticks = timerTicks;
            timerMonitor->next = timerRecord + 1;
        }
    }
}

namespace SphereTriangleProcessSimd {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_load_ss(const float*);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
}
}
extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}
extern unsigned long DAT_0126835c;

template<class T> class ProcessValue {
    T value;
public:
    __forceinline ProcessValue() {}
    __forceinline ProcessValue(T x) : value(x) {}
    __forceinline operator T() const { return value; }
    __forceinline T val() const { return value; }
};

class ProcessTransform;
class ProcessScalar {
    SphereTriangleProcessSimd::__m128 value;
public:
    ProcessScalar(float x) { value = SphereTriangleProcessSimd::_mm_load_ss(&x); }
    __forceinline SphereTriangleProcessSimd::__m128 broadcast() const { return SphereTriangleProcessSimd::_mm_shuffle_ps(value, value, 0); }
};
class ProcessVector {
    SphereTriangleProcessSimd::__m128 value;
public:
    __forceinline void operator=(const ProcessVector& x) { value = x.value; }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&value)[i]; }
    __forceinline const float& operator()(int i) const { return reinterpret_cast<const float*>(&value)[i]; }
    __forceinline void addScaled(const ProcessVector& a, const ProcessVector& b, const ProcessScalar& scale) {
        value = SphereTriangleProcessSimd::_mm_add_ps(a.value, SphereTriangleProcessSimd::_mm_mul_ps(scale.broadcast(), b.value));
    }
    __forceinline void transform(const ProcessTransform&, const ProcessVector&);
};
class ProcessMatrix {
    ProcessVector x, y, z;
public:
    __forceinline ProcessVector& column(int i) { return (&x)[i]; }
    __forceinline const ProcessVector& column(int i) const { return (&x)[i]; }
};
class __declspec(align(16)) ProcessRotation : public ProcessMatrix {};
class ProcessTransform {
    ProcessRotation rotation;
    ProcessVector translation;
public:
    __forceinline ProcessTransform(const ProcessTransform& t) {
        const ProcessVector x = t.rotation.column(0);
        const ProcessVector y = t.rotation.column(1);
        const ProcessVector z = t.rotation.column(2);
        const ProcessVector w = t.rotation.column(3);
        rotation.column(0) = x;
        rotation.column(1) = y;
        rotation.column(2) = z;
        rotation.column(3) = w;
    }
    __forceinline const ProcessRotation& getRotation() const { return rotation; }
    __forceinline const ProcessVector& getTranslation() const { return translation; }
};
void ProcessVector::transform(const ProcessTransform& t, const ProcessVector& b) {
    const ProcessRotation& r = t.getRotation();
    SphereTriangleProcessSimd::__m128 x = SphereTriangleProcessSimd::_mm_shuffle_ps(b.value, b.value, 0);
    SphereTriangleProcessSimd::__m128 rx = SphereTriangleProcessSimd::_mm_mul_ps(r.column(0).value, x);
    SphereTriangleProcessSimd::__m128 y = SphereTriangleProcessSimd::_mm_shuffle_ps(b.value, b.value, 0x55);
    SphereTriangleProcessSimd::__m128 ry = SphereTriangleProcessSimd::_mm_mul_ps(r.column(1).value, y);
    SphereTriangleProcessSimd::__m128 z = SphereTriangleProcessSimd::_mm_shuffle_ps(b.value, b.value, 0xaa);
    SphereTriangleProcessSimd::__m128 rz = SphereTriangleProcessSimd::_mm_mul_ps(r.column(2).value, z);
    value = SphereTriangleProcessSimd::_mm_add_ps(SphereTriangleProcessSimd::_mm_add_ps(rx, ry), SphereTriangleProcessSimd::_mm_add_ps(rz, t.getTranslation().value));
}
static __forceinline void processPoints(const ProcessTransform& t, const ProcessVector* src, int count, ProcessVector* dst) {
    ProcessTransform copy = t;
    int i = count - 1;
    do { dst[i].transform(copy, src[i]); } while (--i >= 0);
}

struct ProcessTimerRecord {
    const char* name;
    unsigned ticks, extra;
    __forceinline void setTime() {
        unsigned ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        this->ticks = ticks;
    }
};
struct ProcessMonitor {
    ProcessValue<char*> start, end, capacity, limit;
    static __forceinline ProcessMonitor& instance() {
        return *static_cast<ProcessMonitor*>(TlsGetValue(DAT_0126835c));
    }
    __forceinline bool available() { return end.val() < limit.val(); }
};
struct ProcessBody : hkpCdBody {
    __forceinline const void* getShape() const { return m_pCollisionShape; }
    __forceinline const ProcessTransform& getTransform() const { return reinterpret_cast<const ProcessTransform&>(*m_pMotionState); }
};
struct ProcessTriangle : hkpTriangleShape {
    __forceinline const ProcessVector* GetIndexedVertices() const { return reinterpret_cast<const ProcessVector*>(m_kVertices); }
};
struct ProcessSpheres : hkpMultiSphereShape {
    __forceinline const ProcessVector* getSpheres() const { return reinterpret_cast<const ProcessVector*>(m_kSpheres); }
    __forceinline int getNumSpheres() const { return m_iSphereCount; }
};
struct ProcessContact {
    ProcessVector position, normal;
    __forceinline ProcessVector& getPosition() { return position; }
    __forceinline void setNormal(const ProcessVector& v) { normal = v; }
    __forceinline void setDistance(float distance) { normal(3) = distance; }
};
struct ProcessPoint {
    ProcessContact contact;
    ProcessValue<unsigned> id;
};
struct ProcessOutput {
    ProcessValue<ProcessPoint*> first;
    ProcessValue<void*> owner;
    ProcessPoint* reserve(int = 1) { return first; }
    void commit(int count = 1) { first = first + count; }
    void abort(int = 1) {}
};
struct ProcessInput {
    ProcessValue<void*> dispatcher;
    ProcessValue<int> weld;
    ProcessValue<float> tolerance;
    float getTolerance() const { return tolerance; }
};
struct ProcessClosest {
    ProcessVector direction;
    ProcessValue<float> distance;
};
struct ProcessManager {
    virtual void destroy();
    virtual void classType();
    virtual void statistics();
    virtual unsigned short addImpl(const ProcessBody&, const ProcessBody&, const ProcessInput&, ProcessOutput&, const void*, ProcessContact&) = 0;
    virtual int reserveImpl(int) = 0;
    virtual void removeImpl(unsigned short, void*) = 0;
    __forceinline unsigned short add(const ProcessBody& a, const ProcessBody& b, const ProcessInput& i, ProcessOutput& o, const void* cache, ProcessContact& p) {
        return addImpl(a, b, i, o, cache, p);
    }
    __forceinline void remove(unsigned short id, void* owner) { removeImpl(id, owner); }
};
extern "C" int __cdecl FUN_00cd7850(const ProcessVector&, const ProcessVector*, const S_00d37e60_Plane&, ProcessClosest&, void* = 0);
struct SphereTriangleProcessReceiver : hkpMultiSphereTriangleAgent {
    void FUN_00d38b00(const ProcessBody&, const ProcessBody&, const ProcessInput&, ProcessOutput&);
};
// @fnv 0x00d38b00
void SphereTriangleProcessReceiver::FUN_00d38b00(const ProcessBody& a, const ProcessBody& b, const ProcessInput& input, ProcessOutput& output) {
    {
        ProcessMonitor& monitor = ProcessMonitor::instance();
        if (monitor.available()) {
            ProcessTimerRecord* record = reinterpret_cast<ProcessTimerRecord*>(monitor.end.val());
            record->name = "TtMultiSphereTri";
            record->setTime();
            monitor.end = reinterpret_cast<char*>(record + 1);
        }
    }
    const ProcessSpheres* spheres = static_cast<const ProcessSpheres*>(a.getShape());
    const ProcessTriangle* triangle = static_cast<const ProcessTriangle*>(b.getShape());
    const ProcessVector* vertices = triangle->GetIndexedVertices();
    ProcessVector triangleWorld[3];
    processPoints(b.getTransform(), vertices, 3, triangleWorld);
    const ProcessVector* localSpheres = spheres->getSpheres();
    const int count = spheres->getNumSpheres();
    ProcessVector sphereWorld[8];
    processPoints(a.getTransform(), localSpheres, count, sphereWorld);
    const ProcessVector* current = sphereWorld;
    const ProcessVector* local = localSpheres;
    for (int j = count - 1; j >= 0; ++current, ++local, --j) {
        const float sphereRadius = (*local)(3);
        const float radiusSum = sphereRadius + triangle->getRadius();
        {
            ProcessClosest closest;
            FUN_00cd7850(*current, triangleWorld, m_kTriangleNormal, closest);
            if (closest.distance < radiusSum + input.getTolerance()) {
                ProcessPoint* point = output.reserve(1);
                point->contact.getPosition().addScaled(*current, closest.direction, triangle->getRadius() - closest.distance);
                point->contact.setNormal(closest.direction);
                point->contact.setDistance(closest.distance - radiusSum);
                if (m_ids[j] == 0xffff) {
                    m_ids[j] = static_cast<ProcessManager*>(m_pContactManager)->add(a, b, input, output, 0, point->contact);
                }
                if (m_ids[j] != 0xffff) {
                    output.commit(1);
                    point->id = m_ids[j];
                } else {
                    output.abort(1);
                }
                continue;
            }
        }
        if (m_ids[j] != 0xffff) {
            static_cast<ProcessManager*>(m_pContactManager)->remove(m_ids[j], output.owner.val());
            m_ids[j] = 0xffff;
        }
    }
    {
        ProcessMonitor& monitor = ProcessMonitor::instance();
        if (monitor.available()) {
            ProcessTimerRecord* record = reinterpret_cast<ProcessTimerRecord*>(monitor.end.val());
            record->name = "Et";
            record->setTime();
            monitor.end = reinterpret_cast<char*>(record + 1);
        }
    }
}
