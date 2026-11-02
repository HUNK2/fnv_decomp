// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskbaseagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct hkpGskBaseAgent {
    virtual void FUN_00dabe90(bool);
};
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
} __m128;
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern float DAT_01012054;
class FUN_00dabeb0_cls {
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
extern float DAT_01012054;
class FUN_00dabed0_cls {
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
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
struct hkpCdBody {
    const void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const void* m_pMotionState;
};
struct GskAgentInput {
    int unk00;
    int unk04;
    float m_fScalar;
};
struct hkTransform {
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
    void FUN_00cb22f0(const void* a, const void* b);
};
struct GskInput {
    const hkTransform* m_kTransform;
    const void* m_pTransformB;
    const void* m_pShapeA;
    const void* m_pShapeB;
    float m_fScalar;
};
struct GskOutput {
    __m128 m_pos;
    __m128 m_vHitNormal;
};
struct hkContactPoint {
    __m128 m_vContactPosition;
    __m128 m_vSeparatingNormal;
};
struct ContactPointPair {
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
};
struct hkpCdPointCollector {
    virtual void vfunc00();
    virtual void AddCdPoint(const ContactPointPair& point);
};
int FUN_00dabca0(const GskInput* input, void* status, __m128* out1, __m128* out2);
class FUN_00dac9e0_cls {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    void ProcessGskContact(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const GskAgentInput* input, hkpCdPointCollector* collector);
};
struct StringCursor {
    void* m_kRayStart;
    char* m_cur;
    void* m_auiShapeKeys;
    char* m_kRayEnd;
};
void __stdcall FUN_00dabe80(int, int, int, int);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
struct hkVector4DAC0 {
    __m128 m_vComponents;

    float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    __forceinline void _setRotatedDir(const struct hkMatrix3DAC0& r, const hkVector4DAC0& b);
};
struct hkMatrix3DAC0 {
    hkVector4DAC0 m_kColumn0;
    hkVector4DAC0 m_kColumn1;
    hkVector4DAC0 m_kColumn2;
};
struct hkTransformDAC0 {
    hkMatrix3DAC0 m_rotation;
    hkVector4DAC0 m_vTranslation;

    void FUN_00cb22f0(const hkTransformDAC0& kA, const hkTransformDAC0& kB);

    const hkMatrix3DAC0& getRotation() const { return m_rotation; }
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
class hkpConvexShapeDAC0 {
public:
    virtual ~hkpConvexShapeDAC0();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned long m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
};
struct hkpCdBodyDAC0 {
    const hkpConvexShapeDAC0* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransformDAC0* m_pMotionState;
};
struct hkpCollisionInputDAC0;
struct FUN_00daad40_solver {
    void FUN_00daad40(const hkpConvexShapeDAC0* pkShapeA, const hkpConvexShapeDAC0* pkShapeB, const hkTransformDAC0& kAtB, hkVector4DAC0& kPointOut);
};
void __cdecl FUN_00dac020(const hkpCdBodyDAC0& kBodyA, const hkpCdBodyDAC0& kBodyB, const hkpCollisionInputDAC0& kInput, FUN_00daad40_solver* pkSolver, hkVector4DAC0& kSeparatingNormal);
extern char g_gskBaseAgentVtbl;
struct GskNode;
__declspec(align(16)) struct GskTmp {
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
struct GskSub {
    int m_00;
    int m_04;
    int m_08;
    void Init(GskNode* a, GskNode* b, GskTmp* t);
    void Init2(GskNode* a, GskNode* b, GskTmp* t);
};
struct GskNode {
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
struct FUN_00dabf10_cls {
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
struct hkBool {
    char m_cBooleanValue;
    hkBool() {}
    hkBool(bool b) : m_cBooleanValue(b) {}
    hkBool(char b) : m_cBooleanValue(b) {}
    operator bool() const { return m_cBooleanValue != 0; }
};
struct CollisionAgentContext {
    void* m_pCollisionDispatcher;
    float m_weldTolerance;
    float m_fScalar;
};
struct ContactData {
    __m128 m_vHitNormal;
    __m128 m_vContactPosition;
    float m_fClosestPointDistanceSquared;
    __m128 m_data30;
    __m128 m_data40;
};
struct Shape {
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
struct GskCache { short m_kVertices[4]; unsigned char m_ucDimensionA,m_ucDimensionB,m_features,unk17; };
struct GskStatus {
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
extern "C" {
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
static __forceinline short* unpackCache(GskCache& c,int& b,unsigned& f,int& a) { b=c.m_ucDimensionB;f=c.m_features;a=c.m_ucDimensionA; return c.m_kVertices; }
struct GskAgentStandin : public hkpGskBaseAgent {
    int unk04;
    int unk08;
    GskCache m_pAccessManager;

    hkBool FUN_00dac7f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, hkContactPoint& pointOut);
};
#include <windows.h>
struct S_00dac2b0_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};
struct S_00dac2b0_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dac2b0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dac2b0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    void timer(const char* name)
    {
        if (memoryAvailable()) {
            S_00dac2b0_TimerCommand* h = (S_00dac2b0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};
struct __declspec(align(16)) S_00dac2b0_Transform {
    float m[16];
    void FUN_00cb22f0(const S_00dac2b0_Transform* a, const S_00dac2b0_Transform* b);
};
struct __declspec(align(16)) S_00dac2b0_Vec {
    float x, y, z, w;
};
struct S_00dac2b0_Shape;
struct S_00dac2b0_Cache {
    unsigned short id0, id1, id2, id3;
    unsigned char dimA, dimB, dims;
    void FUN_00dafe70(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t);
    void FUN_00dafcd0(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t);
};
struct S_00dac2b0_Shape {
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
struct __declspec(align(16)) S_00dac2b0_Gsk {
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
    int FUN_00daad40(const S_00dac2b0_Shape* a, const S_00dac2b0_Shape* b, const S_00dac2b0_Transform* t, S_00dac2b0_Vec* out);
};
struct S_00dac2b0_Body {
    const S_00dac2b0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00dac2b0_Transform* m_pMotionState;
};
struct S_00dac2b0_Collector {
    virtual void v0();
    virtual void AddCdBodyPair(const S_00dac2b0_Body& a, const S_00dac2b0_Body& b);
};
void __cdecl TestGsk(const S_00dac2b0_Body& bodyA, const S_00dac2b0_Body& bodyB, const void* input, S_00dac2b0_Collector& collector);
union EarlyScratch { volatile unsigned int ticks; int result; float distance; };
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern unsigned long hkMonitorStreamTls;
struct S_00dac0b0_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};
struct S_00dac0b0_TimerBeginListCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    const char* m_pFirst;
};
struct S_00dac0b0_MonitorStream {
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
        struct Tk { unsigned int v; };
        Tk t; *(volatile unsigned int*)&t.v = (unsigned int)__rdtsc();
        *(Tk*)&h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
}
struct S_00dac0b0_Vertex { float x, y, z, w; };
struct S_00dac0b0_Transform {
    S_00dac0b0_Vertex col0;
    S_00dac0b0_Vertex col1;
    S_00dac0b0_Vertex col2;
    S_00dac0b0_Vertex trans;
    void FUN_00cb22f0(const S_00dac0b0_Transform* a, const S_00dac0b0_Transform* b);
};
struct S_00dac0b0_Shape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void GetVerticesForIds(const unsigned short* ids, int numIds, S_00dac0b0_Vertex* out) const;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
};
struct S_00dac0b0_Body {
    S_00dac0b0_Shape* m_pCollisionShape;
    int unk04;
    const S_00dac0b0_Transform* m_kMotionTransform;
};
struct S_00dac0b0_PackedCache {
    unsigned short id0, id1, id2, id3;
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flags;
};
struct S_00dac0b0_Gsk {
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
template <class T> struct S_00dac0b0_Pad {
    T* m_p;
    T* val() const { return m_p; }
};
struct S_00dac0b0_Out {
    virtual void v00();
    virtual void v04(const S_00dac0b0_Body& a, const S_00dac0b0_Body& b);
};
struct S_00dac0b0_Agent : hkpGskBaseAgent {
    int unk04;
    int unk08;
    S_00dac0b0_PackedCache m_pAccessManager;
    int unk18;
    int unk1C;
    S_00dac0b0_Vertex m_sepNormal;
    void FUN_00dac0b0(S_00dac0b0_Pad<const S_00dac0b0_Body> pA, S_00dac0b0_Pad<const S_00dac0b0_Body> pB, const void* input, S_00dac0b0_Pad<S_00dac0b0_Out> pOut);
};

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool_S
{
public:
typedef char CompileTimeTrueType;inline hkBool_S(bool b)
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
operator ENUM()const
{
return static_cast<ENUM>(m_kStorage);
}
void operator=(ENUM e)
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
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
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
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
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

extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);


extern __m128 _mm_unpackhi_ps(__m128 _A,__m128 _B);
extern __m128 _mm_unpacklo_ps(__m128 _A,__m128 _B);
extern __m128 _mm_movehl_ps(__m128,__m128);
extern __m128 _mm_movelh_ps(__m128,__m128);
extern __m128 _mm_load_ss(float const*_A);};
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
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class hkRotation;
class hkTransform_S;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r);
void SetRotatedDirection(const hkRotation&a,const hkVector4&b);
__forceinline void _setRotatedInverseDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setTransformedPos(const hkTransform_S&a,const hkVector4&b);
__forceinline void _setTransformedInversePos(const hkTransform_S&a,const hkVector4&b);
__forceinline hkReal&operator()(int i);
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
class hkTransform_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
void SetMulInverse(const hkTransform_S&bTa,const hkTransform_S&bTc);
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVector4::_setRotatedInverseDir(const hkRotation&r,const hkVector4&b)
{
hkQuadReal c0=r.getColumn(0).m_vComponents;
hkQuadReal c1=r.getColumn(1).m_vComponents;
hkQuadReal c2=r.getColumn(2).m_vComponents;
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(c0,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(c1,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(c2,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
inline void hkVector4::_setTransformedPos(const hkTransform_S&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline void hkVector4::_setTransformedInversePos(const hkTransform_S&a,const hkVector4&b)
{
hkVector4 t0;t0.setSub4(b,a.getTranslation());
_setRotatedInverseDir(a.getRotation(),t0);
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform_S::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform_S::getRotation()const
{
return m_rotation;
}
class hkMonitorStream_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static hkMonitorStream_S&GetMonitorStream()
{
extern hkThreadLocalData<hkMonitorStream_S*>g_pMonitorStream;
return*g_pMonitorStream.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool_S __cdecl memoryAvailable()
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
hkBool_S m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkMonitorStream_S::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public hkMonitorStream_S::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkMonitorStream_S::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void hkMonitorStream_S::CommandTimingEntry::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class hkContactPoint_S
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4&getPosition();
inline void setSeparatingNormal(const hkVector4&normal,hkReal dist);
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};inline hkVector4&hkContactPoint_S::getPosition()
{
return m_vContactPosition;
}
inline void hkContactPoint_S::setSeparatingNormal(const hkVector4&normal,hkReal dist)
{
m_vSeparatingNormal=normal;
m_vSeparatingNormal(3)=dist;
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
class hkAabb;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody_S;
class hkpShapeContainer;
class hkSphere;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
__forceinline CollisionShapeType getType()const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape::PhysicsShape));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform_S&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBool_S IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody_S&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
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
};__declspec(align(16))class AlignedHkpShape:public hkpShape{
AlignedHkpShape();
};
CollisionShapeType hkpShape::getType()const
{
return static_cast<const AlignedHkpShape*>(this)->m_type;
}
class hkpCdBody_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform_S&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody_S(const hkpCdBody_S*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform_S&hkpCdBody_S::getTransform()const
{
;
return*static_cast<const hkTransform_S*>(m_pMotionState);
}
const hkpShape*hkpCdBody_S::getShape()const
{
return m_pCollisionShape;
}
struct hkpProcessCollisionInput_S;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct hkpCollisionInput_S
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
class hkpCdBodyPairCollector;
struct hkpCdPoint_S
{
hkpCdPoint_S(const hkpCdBody_S&a,const hkpCdBody_S&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint_S m_kPoint;
const hkpCdBody_S&m_pBodyA;
const hkpCdBody_S&m_pBodyB;};
class hkpCdPointCollector_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector_S();
virtual void AddCdPoint(const hkpCdPoint_S&point)=0;
protected:
hkReal m_fEarlyOutDistance;};
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody_S&a,const hkpCdBody_S&b,const hkpProcessCollisionInput_S&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
inline hkpCollisionAgent(hkpContactMgr*contactMgr);
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};
class hkpTriangleShape;
class ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkUint16 m_kVertices[4];
hkUint8 m_ucDimensionA;
hkUint8 m_ucDimensionB;
hkUint8 m_ucFeatureTypeA:4;
hkUint8 m_ucFeatureTypeB:4;
public:
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform_S&btoa);
void InitForTriangle(const hkpConvexShape*shapeA,const hkpTriangleShape*shapeB,const hkTransform_S&btoa);};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
hkpIterativeLinearCastAgent(hkpContactMgr*contactMgr):hkpCollisionAgent(contactMgr){}
};
struct GskAgentData;
class ConvexShapePairCache;
class hkpGskBaseAgent_S:public hkpIterativeLinearCastAgent
{
public:
virtual void ProcessAgent(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpProcessCollisionInput_S&input,WorldOperationEntry&result);
virtual void getPenetrations(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,class hkpCdPointCollector_S&collector);
static void __cdecl FUN_00dac450(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,class hkpCdPointCollector_S&collector);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
public:
hkpGskBaseAgent_S(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,hkpContactMgr*mgr);
private:
friend class hkpConvexListAgent;
hkpGskBaseAgent_S(hkpContactMgr*mgr):hkpIterativeLinearCastAgent(mgr){}
protected:
__forceinline hkBool_S _getClosestPoint(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,GskAgentData&output);
static void __cdecl ComputeClosestPoint(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,hkReal earlyOutTolerance,ConvexShapePairCache&gsk,hkVector4&separatingNormalOut);
hkBool_S ComputeClosestPoints(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,GskAgentData&output);
static __forceinline hkBool_S staticGetClosestPoint(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkTransform_S&aTb,const hkpCollisionInput_S&input,ConvexFeaturePairCache&cache,struct GskAgentData&output);
virtual void RemovePoint(const hkpCollisionInput_S&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const hkpCollisionInput_S&input);
~hkpGskBaseAgent_S(){}
protected:
ConvexFeaturePairCache m_pAccessManager;
hkTime m_fFloatValue;
hkReal m_fSeparationDistance;
hkVector4 m_vSeparatingNormal;
};
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
virtual const hkSphere*GetCollisionSpheres(hkSphere*sphereBuffer)const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline void GetVerticesForIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const;
virtual void GetFirstVertex(hkVector4&v)const=0;
inline hkReal getRadius()const;enum WeldResult
{
WELD_RESULT_REJECT_CONTACT_POINT,
WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
};
__forceinline hkpConvexShape::WeldResult weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVector4&contactPointWs,const hkTransform_S*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform_S*collidingTransform,hkVector4&separatingNormalInOut)const;
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const=0;
virtual int WeldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,hkVector4&contactPointWs,const hkTransform_S*thisObjTransform,const hkpConvexShape*collidingShape,const hkTransform_S*collidingTransform,hkVector4&separatingNormalInOut)const;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
void hkpConvexShape::GetVerticesForIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const
{
this->GetVerticesFromIds(ids,numIds,vertixArrayOut);
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVector4&contactPointWs,const hkTransform_S*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform_S*collidingTransform,hkVector4&separatingNormalInOut)const
{
return(WeldResult)this->WeldContactPoint(featurePoints,numFeaturePoints,
contactPointWs,thisObjTransform,
collidingShape,collidingTransform,separatingNormalInOut);}
class hkpTriangleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
hkUint16 m_kWeldingInfo;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
};class SegmentSegmentClosestPoint
{
public:
enum
{
CLSLS_POINTA_START=1,
CLSLS_POINTA_END=2,
CLSLS_POINTB_START=4,
CLSLS_POINTB_END=8
};
struct VectorPairResult
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(SegmentSegmentClosestPoint::VectorPairResult));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kFirstVector;
hkVector4 m_kClosestPointOnSecond;
ValueWrapper<hkReal>m_fValue;
};};
enum hkpGskStatus
{
HK_GSK_OK
};
struct ShapePairDistanceData
{
hkVector4 m_vPointOnShapeA;
hkVector4 m_vPointOnShapeB;
ValueWrapper<hkReal>m_fClosestPointDistanceSquared;
};
struct GskAgentData:public ShapePairDistanceData
{
hkVector4 m_kLeadingVector;
hkVector4 m_kSecondVector;
};
class ConvexShapePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
ConvexShapePairCache():m_uiCacheFlags(0){}
__forceinline void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache);
hkpGskStatus GetClosestPoint(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform_S&aTb,hkVector4&separatingNormalOut);
void GetClosestPointBinB(const hkVector4&separatingNormal,ShapePairDistanceData&out);
__forceinline void checkForChangesAndUpdateCache(ConvexFeaturePairCache&cache)const;
void WriteContactFeatureCache(ConvexFeaturePairCache&cache)const;
protected:
__forceinline void setFeatureChange(int f){m_iFeatureChange=f;}
public:
ValueWrapper<int>m_ucDimensionA;
ValueWrapper<int>m_ucDimensionB;
ValueWrapper<int>m_ucFeatureTypeA;
ValueWrapper<int>m_ucFeatureTypeB;
ValueWrapper<hkUint32>m_uiCacheFlags;
ValueWrapper<int>m_iFeatureChange;
Vector4WithInt24W m_akPackedVerticesA[4];
hkVector4 unk60;hkVector4 unk70;hkVector4 unk80;hkVector4 unk90;
hkVector4 m_akCachedVectors[4];
Vector4WithInt24W m_akPackedVerticesB[4];
hkVector4 m_pSupport;
SegmentSegmentClosestPoint::VectorPairResult m_kVectorPairResult;
hkVector4 m_pCachedPoint;
ValueWrapper<int>m_iCacheState;};
__forceinline void ConvexShapePairCache::init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache)
{
m_ucDimensionA=cache.m_ucDimensionA;
m_ucDimensionB=cache.m_ucDimensionB;
m_ucFeatureTypeA=cache.m_ucFeatureTypeA;
m_ucFeatureTypeB=cache.m_ucFeatureTypeB;
setFeatureChange(0);
shapeA->GetVerticesForIds(&cache.m_kVertices[0],m_ucDimensionA,&m_akPackedVerticesA[0]);
shapeB->GetVerticesForIds(&cache.m_kVertices[m_ucDimensionA],m_ucDimensionB,&m_akPackedVerticesB[0]);}
__forceinline void ConvexShapePairCache::checkForChangesAndUpdateCache(ConvexFeaturePairCache&cache)const
{
if(!m_iFeatureChange)
{
return;
}
WriteContactFeatureCache(cache);
}
__forceinline hkBool_S __cdecl hkpGskBaseAgent_S::staticGetClosestPoint(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkTransform_S&aTb,const hkpCollisionInput_S&input,ConvexFeaturePairCache&cache,struct GskAgentData&output)
{
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(bodyA.getShape());
const hkpConvexShape*shapeB=static_cast<const hkpConvexShape*>(bodyB.getShape());
{
hkVector4 separatingNormal;
ConvexShapePairCache gsk;
gsk.init(shapeA,shapeB,cache);
const hkpGskStatus gskStatus=gsk.GetClosestPoint(shapeA,shapeB,aTb,separatingNormal);
if(gskStatus==HK_GSK_OK)
{
gsk.GetClosestPointBinB(separatingNormal,output);
output.m_kSecondVector.SetRotatedDirection(bodyA.getTransform().getRotation(),output.m_vPointOnShapeA);
const hkReal dist=output.m_fClosestPointDistanceSquared-shapeA->getRadius()-shapeB->getRadius();
output.m_fClosestPointDistanceSquared=dist;
if(output.m_fClosestPointDistanceSquared<input.getTolerance())
{
output.m_vPointOnShapeB.addMul4(-shapeA->getRadius(),output.m_vPointOnShapeA);
hkVector4 pointBinA;pointBinA.setAddMul4(output.m_vPointOnShapeB,output.m_vPointOnShapeA,-dist);
output.m_kLeadingVector._setTransformedInversePos(aTb,pointBinA);
if(shapeB->getType()==HK_SHAPE_TRIANGLE&&input.m_collisionQuality.val())
{
gsk.checkForChangesAndUpdateCache(cache);
hkVector4 weldedNormal=output.m_kSecondVector;
hkpConvexShape::WeldResult weldResult=shapeB->weldContactPoint(&cache.m_kVertices[cache.m_ucDimensionA],cache.m_ucDimensionB,output.m_kLeadingVector,&bodyB.getTransform(),shapeA,&bodyA.getTransform(),weldedNormal);
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return false;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
output.m_kSecondVector=weldedNormal;
}
}
return true;
}
}
}
return false;}
// @fnv 0x00dac450
void __cdecl hkpGskBaseAgent_S::FUN_00dac450(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const hkpCollisionInput_S&input,class hkpCdPointCollector_S&collector)
{
{hkMonitorStream_S&mStream=hkMonitorStream_S::GetMonitorStream();if(mStream.memoryAvailable()){hkMonitorStream_S::CommandTimingEntry*h=reinterpret_cast<hkMonitorStream_S::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "Gsk";h->setTime();mStream.setEnd((char*)(h+1));}};
GskAgentData output;
ConvexFeaturePairCache cache;
hkTransform_S aTb;
{
const hkpConvexShape*sA=static_cast<const hkpConvexShape*>(bodyA.getShape());
const hkpConvexShape*sB=static_cast<const hkpConvexShape*>(bodyB.getShape());
aTb.SetMulInverse(bodyA.getTransform(),bodyB.getTransform());
if(sB->getType()==HK_SHAPE_TRIANGLE)
{
cache.InitForTriangle(sA,static_cast<const hkpTriangleShape*>(sB),aTb);
}
else
{
cache.init(sA,sB,aTb);
}
}
if(staticGetClosestPoint(bodyA,bodyB,aTb,input,cache,output))
{
hkpCdPoint_S event(bodyA,bodyB);
event.m_kPoint.getPosition()._setTransformedPos(bodyB.getTransform(),output.m_kLeadingVector);
event.m_kPoint.setSeparatingNormal(output.m_kSecondVector,output.m_fClosestPointDistanceSquared);
collector.AddCdPoint(event);
}
{hkMonitorStream_S&mStream=hkMonitorStream_S::GetMonitorStream();if(mStream.memoryAvailable()){hkMonitorStream_S::CommandTimingEntry*h=reinterpret_cast<hkMonitorStream_S::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
