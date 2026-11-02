// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00df6a30_Inner { int unk0; float unk4; };
struct S_00df6a30 {
    int unk0;
    int unk4;
    S_00df6a30_Inner* unk8;
    float FUN_00df6a30();
};
struct DF6B10Event {
    int unk00;
    int unk04;
    int unk08;
    void* m_kCollisionBody;
};
struct DF6B10Primary {
    virtual void vfunc00();
};
struct DF6B10Listener {
    virtual int HandleEvent(DF6B10Event* event);
};
struct DF6B10Object : DF6B10Primary, DF6B10Listener {
    int handleBody(void* body);

    virtual int HandleEvent(DF6B10Event* event);
};
struct FUN_00df6a40_inner
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
class FUN_00df6a40_cls
{
public:
    int m_00;
    int m_04;
    FUN_00df6a40_inner* m_08;

    bool* FUN_00df6a40(bool* out);
};
struct DF6A60Bool {
    char m_cBooleanValue;

    DF6A60Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};
struct DF6A60Shape {
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct DF6A60Collidable {
    const DF6A60Shape* m_pCollisionShape;
};
struct DF6A60CdPointCollector {
    int unk00;
    float m_fEarlyOutDistance;
};
struct DF6A60LinearCastInput;
typedef void (__cdecl* DF6A60LinearCastFunc)(const DF6A60Collidable& bodyA, const DF6A60Collidable& bodyB, const DF6A60LinearCastInput& input, DF6A60CdPointCollector& collector);
struct DF6A60AgentFuncs {
    DF6A60LinearCastFunc m_pLinearCastFunc;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};
struct DF6A60Dispatcher {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    unsigned char m_agent2TypeMap[64][32];
    int unk9A0;
    int unk9A4;
    DF6A60AgentFuncs m_agent2Funcs[1];

    DF6A60LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pLinearCastFunc;
    }
};
struct DF6A60LinearCastInput {
    const DF6A60Dispatcher* m_pCollisionDispatcher;
};
struct DF6A60CollidableCollidableFilter {
    virtual void unk00();
    virtual DF6A60Bool IsCollisionEnabled(const DF6A60Collidable& a, const DF6A60Collidable& b) const;
};
struct DF6A60Filter {
    int unk00;
    int unk04;
    DF6A60CollidableCollidableFilter m_collidableFilter;
};
struct DF6A60CastCollector {
    int unk00;
    int unk04;
    int unk08;
    const DF6A60Filter* m_iFilter;
    DF6A60CdPointCollector* m_pPointCollector;
    const DF6A60Collidable* m_pCollidableA;
    int m_shapeTypeA;
    int unk1C;
    DF6A60LinearCastInput m_pRayCastInput;

    float LinearCastAgainst(const DF6A60Collidable* collidableB);
};
// GetHelperResultForOffset: thiscall member that forwards a byte-adjusted pointer to a
// sibling thiscall helper (the helper receives `this` in ecx and pops its
// single stack argument).
struct FUN_00df6af0_cls {
    float Helper(int value);
    float GetHelperResultForOffset(int a1, int a2);
};
struct SiblingCls_df6a60 {
    float Call(int a);
};
struct FUN_00df6b30_cls {
    unsigned char* FUN_00df6b30(unsigned char* out, int a);
};
extern float DAT_0104da48;
extern int DAT_0108f288;
extern "C" __declspec(dllimport) long __stdcall DAT_00fdf1ec(long volatile*, long);
struct CopyQuad { int x; int y; int z; int w; };
struct __declspec(align(16)) QueryPoint { CopyQuad parts[7]; };
struct QueryInput {
    const DF6A60Dispatcher* dispatcher;
    int unk04;
    float tolerance;
    int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
};
struct QueryCollector {
    int* table;
    float earlyOut;
    QueryPoint* base;
    QueryPoint* next;
    int capacity;
    int count;
    QueryCollector(QueryPoint* b, int c) : earlyOut(DAT_0104da48), base(b), next(b), capacity(c), count(0), table(&DAT_0108f288) {}
};
struct QueryJob {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    float tolerance;
};
struct PairCommand {
    const DF6A60Collidable* a;
    const DF6A60Collidable* b;
    QueryPoint* results;
    int capacity;
    int numResults;
    long volatile* sharedIndex;
    int unk18; int unk1C;
};
typedef void (__cdecl* QueryFunction)(const DF6A60Collidable&, const DF6A60Collidable&, const QueryInput&, QueryCollector&);
inline QueryPoint* allocateResults(PairCommand* command, const QueryCollector& collector)
{
    {
        int hits = collector.count;
        int start = DAT_00fdf1ec(command->sharedIndex, hits);
        if (start + hits <= command->capacity)
            return command->results + start;
        DAT_00fdf1ec(command->sharedIndex, -hits);
        return 0;
    }
}
void FUN_00df6e00(const QueryJob* job, const QueryInput* source, PairCommand* commands, int count);
// FUN_00df6db0 - base-class adjustment thunk (8 bytes):
//
//     sub ecx, 4
//     jmp  <the derived class' implementation of the overridden virtual>
//
// The secondary base sub-object starts four bytes into the derived object, so
// the vtable slot that the base contributes to the derived class holds an
// adjustor thunk: it moves `this` back to the derived object and tail-calls
// the derived implementation.  The implementation itself lives in another
// translation unit, so it is only declared here.
struct PrimaryBase {
    PrimaryBase();
    virtual void FUN_00df6db0(int flag);
};
struct SecondaryBase {
    SecondaryBase();
    virtual void FUN_00df6db0(int flag);
};
struct Derived : public PrimaryBase, public SecondaryBase {
    Derived();
// @fnv 0x00df6db0
    virtual void FUN_00df6db0(int flag);
};
PrimaryBase::PrimaryBase() {}
SecondaryBase::SecondaryBase() {}
Derived::Derived() : PrimaryBase(), SecondaryBase() {}
struct DF6DC0Primary {
    virtual void vfunc00();
    virtual void FUN_00df6dc0();

    int unk04;
};
struct DF6DC0Secondary {
    virtual void FUN_00df6dc0();
};
struct DF6DC0Object : DF6DC0Primary, DF6DC0Secondary {
    DF6DC0Object();

// @fnv 0x00df6dc0
    virtual void FUN_00df6dc0();
};
DF6DC0Object::DF6DC0Object()
{
}
struct S_00df6dd0_A { virtual ~S_00df6dd0_A() {} };
struct S_00df6dd0_B { virtual void Func(); ~S_00df6dd0_B() {} };
struct S_00df6dd0_C { virtual void Func2(); ~S_00df6dd0_C() {} };
struct FUN_00df6dd0 : S_00df6dd0_A, S_00df6dd0_B, S_00df6dd0_C {
    FUN_00df6dd0();
    virtual ~FUN_00df6dd0();
};
FUN_00df6dd0::~FUN_00df6dd0() {}

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUchar;
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
class hkBool
{
public:
typedef char CompileTimeTrueType;
inline hkBool()
{
}
inline hkBool(bool b)
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
operator ENUM()const
{
return static_cast<ENUM>(m_kStorage);
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
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};template<typename T>
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
unsigned long m_slotID;};class hkMemoryAllocator
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
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&temp(){return*m_pTemp;}
inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;
Allocator*m_pDebugAllocator;};
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
};template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;struct TemporaryAllocatorProvider
{
hkMemoryAllocator&get(void*){return NineIntegerRecord::GetMonitorStream().temp();}
};
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator&get(const void*){return NineIntegerRecord::GetMonitorStream().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator&,const HavokElementArray<T>&src,hkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator=RouterHeapAllocatorProvider>
class hkArray:public HavokElementArray<T>
{
public:
typedef Allocator AllocatorType;
typedef hkArray<T,TemporaryAllocatorProvider>Temp;protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};
typedef union __declspec(intrin_type)__declspec(align(16))__m128{
unsigned __int16 m128_u16[8];}__m128;
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
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
protected:
hkVector4 m_kColumn0;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
hkRotation m_rotation;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
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
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;
hkVector4 m_kMaximumCorner;};
__declspec(align(16))struct hkAabbUint32
{};
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
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline CollisionShapeType getType()const;
__forceinline void getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const;
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
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
};__declspec(align(16))class AlignedHkpShape:public hkpShape{
AlignedHkpShape();
};
CollisionShapeType hkpShape::getType()const
{
return static_cast<const AlignedHkpShape*>(this)->m_type;
}
void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
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
struct CollisionQualityInfo
{};
class hkpCollisionDispatcher;
class hkpCollisionFilter;
class hkpConvexListFilter;
struct RealIntegerData;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
void setTolerance(hkReal t){m_fScalar=t;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;
ValueWrapper<const hkpCollisionFilter*>m_iFilter;
ValueWrapper<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
mutable ValueWrapper<hkBool32>m_bCreatePredictiveAgents;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};class hkpBroadPhaseHandle
{
public:
static const struct ClassMemberDescriptor Members[];public:
hkpBroadPhaseHandle(class FinishingFlag flag){}
};
class hkpCollidable:public hkpCdBody
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkpShape*getShape()const;
public:
__forceinline hkUint32 GetFilterInfoForKey()const;
public:
struct BoundingVolumeData
{
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpCollidable::BoundingVolumeData));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
BoundingVolumeData();
BoundingVolumeData(class FinishingFlag flag);
__forceinline bool hasAllocations()const;
void deallocate();
void allocate(int numChildShapes);
__forceinline void invalidate(){m_kMinimumCorner[0]=1;m_kMaximumCorner[0]=0;}
__forceinline bool isValid()const{return m_kMinimumCorner[0]<=m_kMaximumCorner[0];}
public:
hkUint32 m_kMinimumCorner[3];
hkUint8 m_ucExpansionMin[3];
hkUint8 m_ucExpansionShift;
hkUint32 m_kMaximumCorner[3];
hkUint8 m_ucExpansionMax[3];
hkUint8 m_ucUnknownByte;
hkUint16 m_uiNumChildShapeAabbs;
hkUint16 m_uiCapacityChildShapeAabbs;
hkAabbUint32*m_pChildShapeAabbs;
hkpShapeKey*m_pChildShapeKeys;
};
protected:
hkInt8 m_iOwnerOffset;
public:
hkUint8 m_uiForceCollideOntoPpu;
public:
struct BoundingVolumeData m_kBoundingVolumeData;};__forceinline const hkpShape*hkpCollidable::getShape()const
{
return m_pCollisionShape;
}
struct ContactPointPair;
class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline hkpCdPointCollector();
inline virtual ~hkpCdPointCollector();
virtual inline void reset();
protected:
hkReal m_fEarlyOutDistance;};
void hkpCdPointCollector::reset()
{
m_fEarlyOutDistance=3.40282e+38f;
}
hkpCdPointCollector::hkpCdPointCollector()
{
reset();
}
hkpCdPointCollector::~hkpCdPointCollector()
{
}
class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable ValueWrapper<CollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;
void*m_pCollisionFilter;
hkBool m_bEnableDeprecatedWelding;
RealIntegerData*m_pConfiguration;};struct ShapeSweepParameters:public CollisionAgentContext
{
inline ShapeSweepParameters();
hkVector4 m_path;
hkReal m_fMaxExtraPenetration;
hkReal m_fStartPointTolerance;
RealIntegerData*m_pConfiguration;};
ShapeSweepParameters::ShapeSweepParameters()
{
m_fMaxExtraPenetration=1.192092896e-07F;
}
extern "C"{
typedef unsigned long ULONG;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef void*LPVOID;
extern "C"{
extern "C"{}
extern "C"{}
typedef void*PVOID;
typedef char CHAR;
typedef long LONG;
typedef wchar_t WCHAR;
typedef const WCHAR*LPCWSTR,*PCWSTR;
typedef unsigned __int64 ULONGLONG;
typedef union _ULARGE_INTEGER{
struct{
DWORD LowPart;
DWORD HighPart;
};
struct{
DWORD LowPart;
DWORD HighPart;
}u;
ULONGLONG QuadPart;
}ULARGE_INTEGER;
typedef struct _LUID{
DWORD LowPart;
LONG HighPart;
}LUID,*PLUID;
typedef struct _LIST_ENTRY{
struct _LIST_ENTRY*Flink;
struct _LIST_ENTRY*Blink;
}LIST_ENTRY,*PLIST_ENTRY,*PRLIST_ENTRY;
typedef struct LIST_ENTRY32{
DWORD Flink;
DWORD Blink;
}LIST_ENTRY32;
typedef struct LIST_ENTRY64{
ULONGLONG Flink;
ULONGLONG Blink;
}LIST_ENTRY64;
typedef struct _GUID{
unsigned long Data1;
unsigned short Data2;
unsigned short Data3;
unsigned char Data4[8];
}GUID;
extern "C"{
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
}
extern "C"{}
typedef struct _WOW64_FLOATING_SAVE_AREA{
DWORD ControlWord;
DWORD StatusWord;
DWORD TagWord;
DWORD ErrorOffset;
DWORD ErrorSelector;
DWORD DataOffset;
DWORD DataSelector;
BYTE RegisterArea[80];
DWORD Cr0NpxState;
}WOW64_FLOATING_SAVE_AREA;
typedef struct _WOW64_CONTEXT{
DWORD ContextFlags;
DWORD Dr0;
DWORD Dr1;
DWORD Dr2;
DWORD Dr3;
DWORD Dr6;
DWORD Dr7;
WOW64_FLOATING_SAVE_AREA FloatSave;
DWORD SegGs;
DWORD SegFs;
DWORD SegEs;
DWORD SegDs;
DWORD Edi;
DWORD Esi;
DWORD Ebx;
DWORD Edx;
DWORD Ecx;
DWORD Eax;
DWORD Ebp;
DWORD Eip;
DWORD SegCs;
DWORD EFlags;
DWORD Esp;
DWORD SegSs;
BYTE ExtendedRegisters[512];
}WOW64_CONTEXT;
typedef DWORD ACCESS_MASK;
typedef struct _GENERIC_MAPPING{
ACCESS_MASK GenericRead;
ACCESS_MASK GenericWrite;
ACCESS_MASK GenericExecute;
ACCESS_MASK GenericAll;
}GENERIC_MAPPING;
typedef struct _LUID_AND_ATTRIBUTES{
LUID Luid;
DWORD Attributes;
}SID_AND_ATTRIBUTES,*PSID_AND_ATTRIBUTES;
typedef enum{
LT_DONT_CARE,
LT_LOWEST_LATENCY
}BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;
typedef struct _IMAGE_THUNK_DATA64{
union{
ULONGLONG ForwarderString;
ULONGLONG Function;
ULONGLONG Ordinal;
ULONGLONG AddressOfData;
}u1;
}IMAGE_THUNK_DATA64;
typedef struct _IMAGE_THUNK_DATA32{
union{
DWORD ForwarderString;
DWORD Function;
DWORD Ordinal;
DWORD AddressOfData;
}u1;
}IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;
typedef struct _OSVERSIONINFOA{
DWORD dwOSVersionInfoSize;
DWORD dwMajorVersion;
DWORD dwMinorVersion;
DWORD dwBuildNumber;
DWORD dwPlatformId;
CHAR szCSDVersion[128];
}OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;
typedef struct _OSVERSIONINFOEXA{
DWORD dwOSVersionInfoSize;
DWORD dwMajorVersion;
DWORD dwMinorVersion;
DWORD dwBuildNumber;
DWORD dwPlatformId;
CHAR szCSDVersion[128];
WORD wServicePackMajor;
WORD wServicePackMinor;
WORD wSuiteMask;
BYTE wProductType;
BYTE wReserved;
}OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;
typedef struct _OSVERSIONINFOEXW{
DWORD dwOSVersionInfoSize;
DWORD dwMajorVersion;
DWORD dwMinorVersion;
DWORD dwBuildNumber;
DWORD dwPlatformId;
WCHAR szCSDVersion[128];
WORD wServicePackMajor;
WORD wServicePackMinor;
WORD wSuiteMask;
BYTE wProductType;
BYTE wReserved;
}OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
typedef struct _RTL_CRITICAL_SECTION_DEBUG{
WORD Type;
WORD CreatorBackTraceIndex;
struct _RTL_CRITICAL_SECTION*CriticalSection;
LIST_ENTRY ProcessLocksList;
DWORD EntryCount;
DWORD ContentionCount;
DWORD Flags;
WORD CreatorBackTraceIndexHigh;
WORD SpareWORD;
}RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;
typedef struct _RTL_SRWLOCK{
PVOID Ptr;
}RTL_CONDITION_VARIABLE,*PRTL_CONDITION_VARIABLE;
typedef struct _ASSEMBLY_FILE_DETAILED_INFORMATION{
DWORD ulFlags;
DWORD ulFilenameLength;
DWORD ulPathLength;
PCWSTR lpFileName;
PCWSTR lpFilePath;
}TAPE_DRIVE_PROBLEM_TYPE;
extern "C"{
extern "C"{
typedef ULONG SAVEPOINT_ID,*PSAVEPOINT_ID;
typedef struct _TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT{
SAVEPOINT_ID SavepointId;
}TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT,*PTRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT;
typedef struct _TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT{
ULONG MarshalCookie;
GUID UOW;
}TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT,*PTRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT;}
}
}
typedef struct _RECTL
{
LONG left;
LONG top;
LONG right;
LONG bottom;
}RECTL,*PRECTL,*LPRECTL;
typedef struct tagPOINT
{
LONG x;
LONG y;
}FILETIME,*PFILETIME,*LPFILETIME;}
extern "C"{
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef struct _DCB{
DWORD DCBlength;
DWORD BaudRate;
DWORD fBinary:1;
DWORD fParity:1;
DWORD fOutxCtsFlow:1;
DWORD fOutxDsrFlow:1;
DWORD fDtrControl:2;
DWORD fDsrSensitivity:1;
DWORD fTXContinueOnXoff:1;
DWORD fOutX:1;
DWORD fInX:1;
DWORD fErrorChar:1;
DWORD fNull:1;
DWORD fRtsControl:2;
DWORD fAbortOnError:1;
DWORD fDummy2:17;
WORD wReserved;
WORD XonLim;
WORD XoffLim;
BYTE ByteSize;
BYTE Parity;
BYTE StopBits;
char XonChar;
char XoffChar;
char ErrorChar;
char EofChar;
char EvtChar;
WORD wReserved1;
}JIT_DEBUG_INFO,*LPJIT_DEBUG_INFO;
__declspec(dllimport)
LPVOID
__stdcall
TlsGetValue(
DWORD dwTlsIndex
);}
class PhysicsSimulationContext
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
CRITICAL_SECTION m_kCriticalSection;};
class BusyWaitingSemaphore
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
protected:void*m_pCompletionSemaphore;};
typedef BusyWaitingSemaphore hkSemaphoreBusyWait;
template<typename T>
class CapacityGrowingArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
inline void increaseCapacity();};
typedef hkUint8 hkJobSubType;
enum JobCategory
{
HK_JOB_TYPE_DYNAMICS,
HK_JOB_TYPE_COLLIDE,
HK_JOB_TYPE_COLLISION_QUERY,
HK_JOB_TYPE_RAYCAST_QUERY,
HK_JOB_TYPE_ANIMATION,
HK_JOB_TYPE_BEHAVIOR,
HK_JOB_TYPE_CLOTH,
HK_JOB_TYPE_PATHFINDING,
HK_JOB_TYPE_UNIT_TEST,
HK_JOB_TYPE_CHARACTER_PROXY,
HK_JOB_TYPE_HAVOK_MAX,
HK_JOB_TYPE_USER_0=HK_JOB_TYPE_HAVOK_MAX,
HK_JOB_TYPE_MAX
};
struct JobDescriptor
{__declspec(align(16))hkJobSubType m_ucSubType;};
struct JobQueueConstructionInfo
{};
class JobDispatcher
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum{JOB_QUEUE_ENTRY_SIZE=128};
struct JobQueueSlot:public JobDescriptor
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(JobQueueSlot));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
JobQueueSlot(){}
hkUchar m_data[JOB_QUEUE_ENTRY_SIZE-sizeof(JobDescriptor)];
};
struct Queue:public CapacityGrowingArray<JobQueueSlot>
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Queue));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
};
enum WaitPolicy
{
WAIT_UNTIL_ALL_WORK_COMPLETE,
WAIT_INDEFINITELY
};
struct JobQueueWaitState
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(JobQueueWaitState));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__declspec(align(16))hkInt16 m_sQueueCounts[HK_JOB_TYPE_MAX];
int m_iWaitCount;
WaitPolicy m_eWaitPolicy;
hkBool m_bWaiting;
hkUint16 m_auiThreadIds[2+2+1];
Queue m_kQueues[2+2+1+HK_JOB_TYPE_MAX];
};
enum JobPopFuncResult
{
POP_QUEUE_ENTRY,
DO_NOT_POP_QUEUE_ENTRY
};
enum NextJobWaitMode
{
WAIT_FOR_NEXT_JOB,
DO_NOT_WAIT_FOR_NEXT_JOB
};
enum JobStatus
{
JOB_INVALID=-1,
GOT_NEXT_JOB,
NO_JOBS_AVAILABLE,
ALL_JOBS_FINISHED,
JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
};
public:
JobDispatcher(const JobQueueConstructionInfo&cinfo);
JobStatus GetNextJob(const JobQueueSlot*oldJob,JobQueueSlot&jobOut,NextJobWaitMode waitStatus=WAIT_FOR_NEXT_JOB);
public:
void releaseOneWaitingThread(JobQueueWaitState*data);
public:
__declspec(align(64))PhysicsSimulationContext m_pWorldLock;
public:
int iFirstInteger;};
class hkpBroadPhaseCastCollector
{
public:
virtual ~hkpBroadPhaseCastCollector(){}
virtual hkReal ReleaseCollector(const hkpBroadPhaseHandle*broadphaseHandle,int castIndex)=0;
};
class hkAabbTreeData
{
public:
struct Ray
{
__forceinline void setRay(const hkVector4&start,const hkVector4&end);
hkVector4 m_kRayStart;
hkVector4 m_vInverseDirection;
};
struct QuantizedAabb
{
struct Metric
{
hkVector4 m_kCenterPosition;
__forceinline int select(const QuantizedAabb&a,const QuantizedAabb&b)const;
};
typedef Metric METRIC;
__forceinline Metric getMetric()const;
__forceinline QuantizedAabb(){}
__forceinline void center(hkVector4&centerOut)const;
__forceinline static void combine(const QuantizedAabb&a,const QuantizedAabb&b,QuantizedAabb&out);
__forceinline hkBool32 equals(const QuantizedAabb&aabb)const;
__forceinline hkBool contains(const QuantizedAabb&other)const;
__forceinline void includeAabb(const QuantizedAabb&aabb);
__forceinline hkBool isValid()const;
__forceinline void setEmpty();
__forceinline hkBool32 overlaps(const QuantizedAabb&testAabb)const;
__forceinline hkReal distanceSquared(const hkVector4&point)const;
__forceinline static void __cdecl convertAabbToTreeSpace(const hkAabb&volume,const hkVector4&bitOffsetLow,const hkVector4&bitOffsetHigh,const hkVector4&bitScale,QuantizedAabb&volumeOut);
__forceinline static void __cdecl convertAabbToTreeSpace(const hkAabbUint32&volumeIn,const hkVector4&bitOffsetLow,const hkVector4&bitOffsetHigh,const hkVector4&bitScale,QuantizedAabb&volumeOut);
__forceinline static void __cdecl restoreAabb(const QuantizedAabb&in,const hkVector4&bitScaleInv,const hkVector4&bitOffsetLow,hkAabb&out);
__forceinline hkBool32 overlaps(const hkAabb&testAabb)const;
hkUint16 m_kMaximumCorner[3];
hkUint16 m_kMinimumCorner[3];
};};template<typename BOUNDING_VOLUME,typename hkIdxType=hkUint16>
class hkAabbTree
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
struct Node
{
static const hkIdxType s_leafMask=hkIdxType(~0)>>1;
static const hkIdxType s_leafFlag=hkIdxType(~s_leafMask);
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Node));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
Node():m_usNodeValue(0){}
BOUNDING_VOLUME m_iBufferSize;
private:
union
{
struct
{
hkIdxType m_ausChildIndices[2];
}m_kChildIndices;
struct
{
void*m_ulUserData;
}m_kLeafData;
};
hkIdxType m_usNodeValue;
hkIdxType m_iSkipNodeIndex;
public:
hkIdxType getParentIdx()const{return m_usNodeValue&s_leafMask;}
hkIdxType getSkipNodeIdx()const{return m_iSkipNodeIndex;}
hkIdxType getChildIdx(int i)const{return m_kChildIndices.m_ausChildIndices[i];}
void setSkipNodeIdx(hkIdxType idx){m_iSkipNodeIndex=idx;}
void setParentNodeIdx(hkIdxType idx){m_usNodeValue=idx |(m_usNodeValue&s_leafFlag);}
void setChildIdx(int iChild,hkIdxType idx){m_kChildIndices.m_ausChildIndices[iChild]=idx;}
hkBool32 isLeaf()const{return m_usNodeValue&s_leafFlag;}
template<typename T>
__forceinline T getLeafData()const{;return(T)m_kLeafData.m_ulUserData;}
__forceinline void setLeafData(void*userData){m_kLeafData.m_ulUserData=userData;m_usNodeValue |=s_leafFlag;}
friend class hkAabbTree<BOUNDING_VOLUME,hkIdxType>;
};
private:
void BuildTreeFromLeafVolumes(BOUNDING_VOLUME*leafVolumes,void**userDatas,int numLeaves,Node*root,hkArray<hkIdxType>&leavesOut,
bool leavesAreAllocated=false);
private:
Node*m_pAabbRootNode;
public:
hkVector4 m_kAabbMin;};typedef void**voidWriteIterator;
template<typename BOUNDING_VOLUME,typename hkIdxType=hkUint16>
class hkAabbTreeQueryUtils
{
public:
struct AabbTreeNodePair
{
AabbTreeNodePair(){}
AabbTreeNodePair(typename hkAabbTree<BOUNDING_VOLUME,hkIdxType>::Node*a,typename hkAabbTree<BOUNDING_VOLUME,hkIdxType>::Node*b){m_kPointA=a;m_kPointB=b;}
typename hkAabbTree<BOUNDING_VOLUME,hkIdxType>::Node*m_kPointA;
typename hkAabbTree<BOUNDING_VOLUME,hkIdxType>::Node*m_kPointB;
};
struct Collector
{
virtual ~Collector(){}
virtual hkReal GetHitDistance(const typename hkAabbTree<BOUNDING_VOLUME,hkIdxType>::Node*leaf)=0;
};
static int __cdecl GetAabbHits(const hkAabbTree<BOUNDING_VOLUME,hkIdxType>*tree,const hkAabb&aabb,Collector*collector);
private:
static int __cdecl CollectAabbHitsIntoBuffers(const hkAabbTree<BOUNDING_VOLUME,hkIdxType>*tree,const hkAabb&aabb,
Collector*collector,hkArray<void*>*ptrArray,voidWriteIterator*hitArray,int hitCapacity);};
typedef hkUlong hkPrimitiveId;
class KdTreeNode
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
struct Pair3Pool
{
__declspec(align(8))hkInt32 m_iPrimitiveStartIndex;
hkUint32 m_iNumPrimitives;
};};
struct FieldlessRecord
{};
class KdTree
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
void AllocateNodes(int numNodes);};class hkKdTreeCastCollector
{
public:
virtual ~hkKdTreeCastCollector(){}
virtual hkBool ReportHit(hkPrimitiveId primId)=0;
virtual hkBool DidHit()=0;
virtual hkReal GetHitFraction()=0;
};
class hkpGroupFilter;
class hkpFixedBufferCdPointCollector;
class hkCpuWorldGetClosestPointsCollector:public hkpBroadPhaseCastCollector,
public hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::Collector,
public hkKdTreeCastCollector
{
protected:
hkReal ReleaseCollector(const hkpBroadPhaseHandle*broadphaseHandle,int castIndex);
virtual hkReal GetHitDistance(const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>::Node*leaf);
virtual hkBool ReportHit(hkPrimitiveId primId);
virtual hkBool DidHit();
virtual hkReal GetHitFraction();
public:
const hkpGroupFilter*m_iFilter;
hkpFixedBufferCdPointCollector*m_pPointCollector;
const hkpCollidable*m_kCollidable;
CollisionShapeType m_iType;
ShapeSweepParameters m_pRayCastInput;};struct RootContactPoint;
class hkpBroadPhase;
struct CollisionQueryJobHeader
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
struct CollisionQueryJobBase:public JobDescriptor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum JobSubType
{
COLLISION_QUERY_MOPP_AABB,
COLLISION_QUERY_PAIR_GET_CLOSEST_POINTS,
COLLISION_QUERY_WORLD_GET_CLOSEST_POINTS,
COLLISION_QUERY_PAIR_LINEAR_CAST,
COLLISION_QUERY_WORLD_LINEAR_CAST,
COLLISION_QUERY_KD_TREE_AABB_QUERY_JOB,
COLLISION_QUERY_AABB_TREE_AABB_QUERY_JOB,
COLLISION_QUERY_JOB_END
};
protected:
__forceinline CollisionQueryJobBase(JobSubType subType,hkUint16 size);
public:
hkSemaphoreBusyWait*m_pCompletionSemaphore;
CollisionQueryJobHeader*m_pCollisionQueryJobHeader;
const GskAgentInput*m_pCollisionInput;};
struct ContactPointResultBuffer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
const hkpCollidable*m_kCollidable;
RootContactPoint*m_pResultBuffer;
int m_iResultCount;
hkUint32 m_iResultCapacity;};
struct ContactPointQueryJob:public CollisionQueryJobBase
{
public:
friend struct GskAgentTaskHelper;
enum{MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK=64};
public:
__forceinline ContactPointQueryJob(const GskAgentInput*input,CollisionQueryJobHeader*jobHeader,const ContactPointResultBuffer*commandArray,int numCommands,const hkpBroadPhase*broadphase,hkReal tolerance,hkSemaphoreBusyWait*semaphore,int numCommandsPerTask=MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK);
protected:
__forceinline JobDispatcher::JobPopFuncResult popJobTask(ContactPointQueryJob&out);
public:
const hkpBroadPhase*m_pBroadPhaseRecord;
const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>*m_pQuantizedAabbTree;
const KdTree*m_pKdTree;
hkReal m_fScalar;
int m_iCommandCapacity;
const ContactPointResultBuffer*m_pCommands;
int m_iCommandCount;};class hkpFixedBufferCdPointCollector:public hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}
public:
__forceinline hkpFixedBufferCdPointCollector(RootContactPoint*buffer,int capacity);
public:
static void __cdecl addCdPointImplementation(const ContactPointPair&event,hkpFixedBufferCdPointCollector*collector);
protected:
virtual __forceinline void AddCdPoint(const ContactPointPair&event);
public:
ValueWrapper<RootContactPoint*>m_pPointBuffer;
ValueWrapper<RootContactPoint*>m_pPointBufferEnd;
ValueWrapper<int>m_pRayCursor;
ValueWrapper<int>m_iPointCount;};hkpFixedBufferCdPointCollector::hkpFixedBufferCdPointCollector(RootContactPoint*buffer,int capacity):hkpCdPointCollector()
{
m_pPointBuffer=buffer;
m_pPointBufferEnd=buffer;
m_pRayCursor=capacity;
m_iPointCount=0;
}
class hkMultiThreadCheck
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum ReadMode
{
THIS_OBJECT_ONLY,
RECURSIVE
};
protected:
void markForReadImpl(ReadMode mode);
public:
enum
{
MARKED_RO=0xffffffe1,
MARKED_RO_SELF_ONLY=0xffffffc1,
UNMARKED=0xfffffff1
};
protected:
hkUint16 m_usMarkCount;
public:
static class PhysicsSimulationContext*m_pWorldLock;};
class BroadPhaseCastCollector;
hkpBroadPhase*__cdecl hk3AxisSweep32CreateBroadPhase(const hkVector4&worldMin,const hkVector4&worldMax,int numMarkers);
typedef char hkpBroadPhaseAabbCache;
class hkpBroadPhase:public hkReferencedObject
{
public:
hkpBroadPhase();
enum BroadPhaseType
{
BROADPHASE_16BIT,
BROADPHASE_32BIT
};
virtual BroadPhaseType getType()const=0;
virtual void addObject(hkpBroadPhaseHandle*object,const hkAabbUint32&aabb,hkArray<BroadPhaseCastCollector>&pairsOut)=0;
virtual void addObject(hkpBroadPhaseHandle*object,const hkAabb&aabb,hkArray<BroadPhaseCastCollector>&pairsOut)=0;
virtual void UpdatePairs(const HavokElementArray<hkpBroadPhaseHandle*>&addObjectList,const HavokElementArray<hkAabb>&addAabbList,hkArray<BroadPhaseCastCollector>&newPairs)=0;
virtual void RemoveBroadPhaseObject(hkpBroadPhaseHandle*object,hkArray<BroadPhaseCastCollector>&pairsOut)=0;
virtual void RemoveObjectBatch(const HavokElementArray<hkpBroadPhaseHandle*>&removeObjectList,hkArray<BroadPhaseCastCollector>&delPairsOut)=0;
virtual int GetBroadphaseType()const=0;
virtual void UpdateAabbs(hkpBroadPhaseHandle*objects[],const hkAabb*aabbs,int numObjects,hkArray<BroadPhaseCastCollector>&addedPairs,hkArray<BroadPhaseCastCollector>&removedPairs)=0;
virtual void UpdateAabbsUint32(hkpBroadPhaseHandle*objects[],const hkAabbUint32*aabbs,int numObjects,hkArray<BroadPhaseCastCollector>&addedPairs,hkArray<BroadPhaseCastCollector>&removedPairs)=0;
virtual void Defragment()=0;
virtual void ClearBroadPhase(){}
virtual void GetAllAabbs(hkArray<hkAabb>&allAabbs)const=0;
virtual void getAabb(const hkpBroadPhaseHandle*object,hkAabb&aabb)const=0;
virtual void GetWorldExtents(hkVector4&worldMinOut,hkVector4&worldMaxOut)const=0;
virtual void FindOverlappingPairs(const hkAabb&aabb,hkArray<BroadPhaseCastCollector>&pairs_out)const=0;
virtual void ReQuerySingleObject(const hkpBroadPhaseHandle*object,hkArray<BroadPhaseCastCollector>&pairs_out)const=0;
virtual bool AreAabbsOverlapping(const hkpBroadPhaseHandle*bhA,const hkpBroadPhaseHandle*bhB)const=0;
virtual void ShiftAllObjects(const hkVector4&shiftDistance,hkVector4&effectiveShiftDistanceOut,hkArray<BroadPhaseCastCollector>&newCollisionPairs)=0;
virtual void ShiftBroadPhase(const hkVector4&shiftDistance,hkVector4&effectiveShiftDistanceOut,hkArray<BroadPhaseCastCollector>&newCollisionPairs)=0;
virtual void GetOffsetLowHigh32Bit(hkVector4&offsetLow32bit,hkVector4&offsetHigh32bit)const=0;
struct RayCastBatchInput
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpBroadPhase::RayCastBatchInput));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_vFrom;
int m_iCastCount;
const hkVector4*m_pCastEndpoints;
int m_iEndpointStrideBytes;
const hkpBroadPhaseAabbCache*m_pBroadPhaseAabbCache;
RayCastBatchInput():m_iCastCount(1),m_iEndpointStrideBytes(int(sizeof(hkVector4))),m_pBroadPhaseAabbCache(0){}
};
virtual void RayCast(const RayCastBatchInput&input,hkpBroadPhaseCastCollector*collectorBase,int collectorStriding)const=0;
virtual int GetAabbCacheSize()const=0;
virtual void CalcAabbCache(const hkAabb&aabb,hkpBroadPhaseAabbCache*aabbCacheOut)const=0;
virtual void CalcAabbCache(const HavokElementArray<class hkpCollidable*>&overlappingCollidables,hkpBroadPhaseAabbCache*aabbCacheOut)const=0;
struct AabbSweepInput
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpBroadPhase::AabbSweepInput));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkVector4 m_vHalfExtents;
const hkpBroadPhaseAabbCache*m_pBroadPhaseAabbCache;
AabbSweepInput():m_pBroadPhaseAabbCache(0){}
};
virtual void CastSweptAabb(const AabbSweepInput&input,hkpBroadPhaseCastCollector&collector)const=0;
virtual void Set32BitOffsetAndScale(const hkVector4&offsetLow,const hkVector4&offsetHigh,const hkVector4&scale)=0;
typedef hkpBroadPhase*(__cdecl*createBroadPhaseFunc)(const hkVector4&worldMin,const hkVector4&worldMax,int numMarkers);
static createBroadPhaseFunc ms_pDefaultCreationFunction;
protected:
void lockImplementation();
protected:
mutable hkMultiThreadCheck m_kMultiThreadCheck;
public:
class ScopedBroadPhaseFactoryOverride
{
public:
ScopedBroadPhaseFactoryOverride()
{
pfnOriginalBroadPhaseCreator=hkpBroadPhase::ms_pDefaultCreationFunction;
hkpBroadPhase::ms_pDefaultCreationFunction=hk3AxisSweep32CreateBroadPhase;
}
~ScopedBroadPhaseFactoryOverride()
{
hkpBroadPhase::ms_pDefaultCreationFunction=pfnOriginalBroadPhaseCreator;
}
public:
createBroadPhaseFunc pfnOriginalBroadPhaseCreator;
private:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpBroadPhase::ScopedBroadPhaseFactoryOverride));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
};};
class hkpCollidableCollidableFilter
{
public:
static const struct ClassMemberDescriptor Members[];};
class hkpRayCollidableFilter
{
public:
static const struct ClassMemberDescriptor Members[];};
class hkpShapeCollectionFilter
{
public:
static const struct ClassMemberDescriptor Members[];};
class hkpRayShapeCollectionFilter
{
public:
static const struct ClassMemberDescriptor Members[];};
class hkpCollisionFilter:public hkReferencedObject,
public hkpCollidableCollidableFilter,
public hkpShapeCollectionFilter,
public hkpRayShapeCollectionFilter,
public hkpRayCollidableFilter
{
public:
static const struct ClassMemberDescriptor Members[];
enum hkpFilterType
{
HK_FILTER_UNKNOWN=0,
HK_FILTER_NULL=1,
HK_FILTER_GROUP=2,
HK_FILTER_LIST=3,
HK_FILTER_CUSTOM=4,
HK_FILTER_PAIR=5,
HK_FILTER_CONSTRAINT=6,
};
public:
hkpCollisionFilter();
public:
hkUint32 m_uiPreTypePadding[2];
hkEnum<hkpFilterType,hkUint32>m_type;
public:
hkpCollisionFilter(FinishingFlag flag):hkReferencedObject(flag){}
};
class hkpGroupFilter:public hkpCollisionFilter
{
public:
enum{USE_COLLIDABLE_FILTER_INFO=0xffffffff};
public:
static const struct ClassMemberDescriptor Members[];
public:
int m_iNextFreeSystemGroup;
public:
hkpGroupFilter(class FinishingFlag flag):hkpCollisionFilter(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_FILTER_GROUP;
}
}
};typedef hkPrimitiveId*hkPrimitiveIdIterator;
class KdTreeAabbQuery
{
public:
enum{DEFAULT_STACK_SIZE=128};
static void __cdecl queryAabbIterative(const KdTree*root,const hkAabb&aabb,hkKdTreeCastCollector*collector);
private:
static hkUint32 __cdecl CollectAabbHitsIntoBuffers(const KdTreeNode*root,const FieldlessRecord*projectedEntries,hkVector4Parameter scale,hkVector4Parameter offset,const hkAabb&aabb,int treeDepth,
hkArray<hkPrimitiveId>::Temp*hitArray,hkKdTreeCastCollector*collector,hkPrimitiveIdIterator*hitsOut,int maxHits);};
class hkp3AxisSweep:public hkpBroadPhase
{
public:
virtual void CollectAabbCastResults(const hkAabb&aabb,hkpBroadPhaseCastCollector*collector)const;
};
// @fnv 0x00df6b50
JobDispatcher::JobStatus __cdecl FUN_00df6b50(JobDispatcher&jobQueue,JobDispatcher::JobQueueSlot&nextJobOut)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "CollQueryWorldGetClosestPoints";h->setTime();mStream.setEnd((char*)(h+1));}};
const ContactPointQueryJob&worldGetClosestPointsJob=reinterpret_cast<ContactPointQueryJob&>(nextJobOut);
hkpFixedBufferCdPointCollector castCollector(0,1);
hkCpuWorldGetClosestPointsCollector broadPhaseCollector;
broadPhaseCollector.m_pRayCastInput.m_collisionQuality=false;
{
broadPhaseCollector.m_iFilter=static_cast<const hkpGroupFilter*>(worldGetClosestPointsJob.m_pCollisionInput->m_iFilter.val());
broadPhaseCollector.m_pPointCollector=&castCollector;
static_cast<CollisionAgentContext&>(broadPhaseCollector.m_pRayCastInput)=*worldGetClosestPointsJob.m_pCollisionInput;
broadPhaseCollector.m_pRayCastInput.m_pConfiguration=worldGetClosestPointsJob.m_pCollisionInput->m_pConfiguration;
}
const hkp3AxisSweep*broadphase=static_cast<const hkp3AxisSweep*>(worldGetClosestPointsJob.m_pBroadPhaseRecord);
const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>*aabbTreeInt=worldGetClosestPointsJob.m_pQuantizedAabbTree;
const KdTree*kdTree=worldGetClosestPointsJob.m_pKdTree;
;
for(int i=0;i<worldGetClosestPointsJob.m_iCommandCount;i++)
{
ContactPointResultBuffer*command=const_cast<ContactPointResultBuffer*>(&worldGetClosestPointsJob.m_pCommands[i]);
new(&castCollector)hkpFixedBufferCdPointCollector(command->m_pResultBuffer,command->m_iResultCount);
{
hkAabb aabb;
const hkpShape*shape=command->m_kCollidable->getShape();
const hkTransform&transform=command->m_kCollidable->getTransform();
hkReal restTolerance=worldGetClosestPointsJob.m_fScalar-worldGetClosestPointsJob.m_pCollisionInput->getTolerance()*0.5f;
shape->getAabb(transform,restTolerance,aabb);
broadPhaseCollector.m_kCollidable=command->m_kCollidable;
broadPhaseCollector.m_iType=shape->getType();
broadPhaseCollector.m_pRayCastInput.setTolerance(worldGetClosestPointsJob.m_fScalar);
if(broadphase)
{
broadphase->CollectAabbCastResults(aabb,&broadPhaseCollector);
}
if(aabbTreeInt)
{
hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::GetAabbHits(aabbTreeInt,aabb,&broadPhaseCollector);
}
if(kdTree)
{
KdTreeAabbQuery::queryAabbIterative(kdTree,aabb,&broadPhaseCollector);
}
}
command->m_iResultCapacity=castCollector.m_iPointCount;
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return jobQueue.GetNextJob(&nextJobOut,nextJobOut);
}
