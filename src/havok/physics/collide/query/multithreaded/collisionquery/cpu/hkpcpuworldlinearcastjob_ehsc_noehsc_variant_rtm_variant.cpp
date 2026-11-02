// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldlinearcastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00df71c0_Value {
    int unk00;
    float value;
};
struct FUN_00df71c0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df71c0_Value* unk10;
    float FUN_00df71c0();
};
struct Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    volatile Data *value;
};
struct TargetBase { void CastAgainstCollidable(volatile Data *value); };
struct FUN_00df72c0_class {
    int unk00;
    int unk04;
    void ForwardToBase(volatile Data *value);
};
struct Param { unsigned int unk00; unsigned int unk04; unsigned int unk08; Param* next0c; };
struct This { int CastAgainstCollidable(Param*); int FUN_00df72e0(Param*); };
struct DF7230Bool {
    char m_cBooleanValue;

    DF7230Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};
struct DF7230Shape {
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct DF7230Collidable {
    const DF7230Shape* m_pCollisionShape;
};
struct DF7230CdPointCollector {
    int unk00;
    float m_fEarlyOutDistance;
};
struct DF7230LinearCastInput;
typedef void (__cdecl* DF7230LinearCastFunc)(const DF7230Collidable& bodyA, const DF7230Collidable& bodyB, const DF7230LinearCastInput& input, DF7230CdPointCollector& collector, DF7230CdPointCollector* startCollector);
struct DF7230AgentFuncs {
    void* unk00;
    DF7230LinearCastFunc m_pLinearCastFunc;
    void* unk08;
    void* unk0C;
    void* unk10;
};
struct DF7230Dispatcher {
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
    DF7230AgentFuncs m_agent2Funcs[1];

    DF7230LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pLinearCastFunc;
    }
};
struct DF7230LinearCastInput {
    const DF7230Dispatcher* m_pCollisionDispatcher;
};
struct DF7230CollidableCollidableFilter {
    virtual void unk00();
    virtual DF7230Bool IsCollisionEnabled(const DF7230Collidable& a, const DF7230Collidable& b) const;
};
struct DF7230Filter {
    int unk00;
    int unk04;
    DF7230CollidableCollidableFilter m_collidableFilter;
};
struct DF7230CastCollector {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const DF7230Filter* m_iFilter;
    DF7230CdPointCollector* m_pPointCollector;
    const DF7230Collidable* m_pCollidableA;
    int m_shapeTypeA;
    DF7230LinearCastInput m_pRayCastInput;

    float CastAgainstCollidable(const DF7230Collidable* collidableB);
};
// FUN_00df7320 - 0x00df7320, 19 bytes
//
//   mov edx, dword ptr [esp + 4]      ; the first stack argument
//   movsx eax, byte ptr [edx + 5]     ; signed byte at +5 of that object
//   add eax, edx                      ; object + offset
//   push eax
//   call 0xdf7230                     ; same class, this (ECX) forwarded
//   ret 8
//
// CastAgainstCollidable is a __thiscall member of the same class with one 4-byte
// stack argument; it ends with `ret 4`, so it pops the pushed pointer
// itself and our own epilogue only has to drop the two incoming arguments.
//
// The function is a virtual of hkCpuWorldLinearCastCollector (its vftable
// entry sits at 0x010db9e8); `this` is never touched here, it is simply
// passed on to CastAgainstCollidable.
// The object the collector is asked about.  The signed byte at +0x05 is the
// offset of the sub-object that has to be evaluated.
struct FUN_00df7320_Shape {
    int unk00;          // +0x00
    signed char unk04;  // +0x04
    signed char unk05;  // +0x05
};
struct FUN_00df7320_Collector {
    float CastAgainstCollidable(FUN_00df7320_Shape* value);
    float FUN_00df7320(FUN_00df7320_Shape* shape, FUN_00df7320_Shape* other);
};
struct Base1 { virtual void FUN_00df7190(); };
struct Base2 { virtual void FUN_00df7190(); };
struct Derived : Base1, Base2 { Derived(); virtual void FUN_00df7190(); };
struct DF71B0Primary {
    virtual void vfunc00();
    virtual void FUN_00df71b0();

    int unk04;
    int unk08;
};
struct DF71B0Secondary {
    virtual void FUN_00df71b0();
};
struct DF71B0Object : DF71B0Primary, DF71B0Secondary {
    DF71B0Object();

// @fnv 0x00df71b0
    virtual void FUN_00df71b0();
};
DF71B0Object::DF71B0Object()
{
}
struct S_00df71d0_Heap {
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, unsigned int n);
};
struct S_00df71d0_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00df71d0_Heap* unk10;
    S_00df71d0_Heap& heap() { return *unk10; }
};
S_00df71d0_Router* FUN_00c85750();
struct S_00df71d0_B0 {
    virtual ~S_00df71d0_B0() {}
};
struct S_00df71d0_B1 {
    virtual void f1() {}
    ~S_00df71d0_B1() {}
};
struct S_00df71d0_B2 {
    virtual void f2() {}
    ~S_00df71d0_B2() {}
};
struct S_00df71d0_B3 {
    virtual void f3() {}
    ~S_00df71d0_B3() {}
};
struct FUN_00df71d0 : S_00df71d0_B0, S_00df71d0_B1, S_00df71d0_B2, S_00df71d0_B3 {
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    FUN_00df71d0();
// @fnv 0x00df71d0
    virtual ~FUN_00df71d0() {}
    static void operator delete(void* p, unsigned int n) { FUN_00c85750()->heap().ReleaseBlock(p, n); }
};
FUN_00df71d0::FUN_00df71d0() {}

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
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
};template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
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
typedef Allocator AllocatorType;protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};
typedef union __declspec(intrin_type)__declspec(align(16))__m128{
float x;}__m128;
extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sqrt_ss(__m128 _A);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
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
};private:
hkQuadReal m_uiMask;};
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void setInterpolate4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter t);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue length3()const;
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
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4::length3()const
{
return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
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
class hkpCollisionDispatcher;
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
hkEnum<CollisionShapeType,hkUint32>m_type;
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
struct CollisionQualityInfo;
class hkpCollisionFilter;
class hkpConvexListFilter;
struct RealIntegerData;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
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
__forceinline void invalidate(){m_min0=1;m_max0=0;}
__forceinline bool isValid()const{return m_min0<=m_max0;}
public:
hkUint32 m_min0;
hkUint32 m_min1;
hkUint32 m_min2;
hkUint8 m_expansionMin0;
hkUint8 m_expansionMin1;
hkUint8 m_expansionMin2;
hkUint8 m_ucExpansionShift;
hkUint32 m_max0;
hkUint32 m_max1;
hkUint32 m_max2;
hkUint8 m_expansionMax0;
hkUint8 m_expansionMax1;
hkUint8 m_expansionMax2;
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
struct ContactPointPair
{};
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
inline void setPathAndTolerance(const hkVector4&path,hkReal tolerance);
hkVector4 m_path;
hkReal m_fMaxExtraPenetration;
hkReal m_fStartPointTolerance;
RealIntegerData*m_pConfiguration;};
ShapeSweepParameters::ShapeSweepParameters()
{
m_fMaxExtraPenetration=1.192092896e-07F;
}
void ShapeSweepParameters::setPathAndTolerance(const hkVector4&path,hkReal tolerance)
{
m_path=path;
m_fStartPointTolerance=path.length3();
m_fScalar=tolerance;
}
extern "C" __declspec(dllimport) unsigned long __stdcall TlsAlloc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
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
class JobDispatcher {
public:
    struct JobQueueSlot {};
    enum JobPopFuncResult { POP_QUEUE_ENTRY, DO_NOT_POP_QUEUE_ENTRY };
    enum NextJobWaitMode { WAIT_FOR_NEXT_JOB, DO_NOT_WAIT_FOR_NEXT_JOB };
    enum JobStatus { JOB_INVALID=-1, GOT_NEXT_JOB, NO_JOBS_AVAILABLE, ALL_JOBS_FINISHED, JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF };
    JobStatus GetNextJob(const JobQueueSlot* oldJob, JobQueueSlot& jobOut, NextJobWaitMode waitStatus=WAIT_FOR_NEXT_JOB);
};
struct LinearCastParameters
{
hkVector4 m_vTo;
hkReal m_fMaxExtraPenetration;
hkReal m_fMaxExtraPenetrationAgainstFixed;};typedef hkUlong hkPrimitiveId;
class KdTree
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
void AllocateNodes(int numNodes);};
class hkAabbTreeData
{
public:
struct Ray
{
__forceinline void setRay(const hkVector4&start,const hkVector4&end);
hkVector4 m_kRayStart;
hkVector4 m_vInverseDirection;
};
struct Bundle
{
hkVector4 m_data0;
hkVector4 m_data1;
hkVector4 m_data2;
};
struct RayQuerySet
{
__forceinline RayQuerySet(){}
__forceinline RayQuerySet(const Bundle&from,const Bundle&to,Vector4Comparison::Mask mask=Vector4Comparison::MASK_XYZW);
Bundle m_vFrom;
Bundle m_vInverseDirection;
Vector4Comparison::Mask m_uiMask;
};
struct SweptBoxQuery
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(SweptBoxQuery));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkVector4 m_vHalfExtents;
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
hkUint16 m_max0;
hkUint16 m_max1;
hkUint16 m_max2;
hkUint16 m_min0;
hkUint16 m_min1;
hkUint16 m_min2;
};
struct RayQueryAabb:public hkAabb
{
struct Metric
{
hkVector4 m_kCenterPosition;
__forceinline int select(const RayQueryAabb&a,const RayQueryAabb&b)const;
};
typedef Metric METRIC;
__forceinline Metric getMetric()const;
__forceinline void center(hkVector4&centerOut)const;
__forceinline static void combine(const RayQueryAabb&a,const RayQueryAabb&b,RayQueryAabb&out);
__forceinline hkBool32 overlaps(const Ray&r,const hkVector4&earlyOutHitFraction)const;
__forceinline hkBool32 overlaps(const RayQuerySet&ray,const hkVector4&ealyOutFractions,Vector4Comparison&hitOut)const;
__forceinline hkBool32 overlaps(const hkAabb&aabb)const;
__forceinline void expand(hkVector4Parameter velocity,hkReal margin);
__forceinline hkReal distanceSquared(const hkVector4&point)const;
__forceinline static void __cdecl convertAabbToTreeSpace(const hkAabb&volume,const hkVector4&bitOffsetLow,const hkVector4&bitOffsetHigh,const hkVector4&bitScale,RayQueryAabb&volumeOut);
__forceinline static void __cdecl convertAabbToTreeSpace(const hkAabbUint32&volumeIn,const hkVector4&bitOffsetLow,const hkVector4&bitOffsetHigh,const hkVector4&bitScale,RayQueryAabb&volumeOut);
__forceinline static void __cdecl restoreAabb(const RayQueryAabb&in,const hkVector4&bitScaleInv,const hkVector4&bitOffsetLow,hkAabb&out);
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
hkIdxType m_childIdx0;
hkIdxType m_childIdx1;
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
hkIdxType getChildIdx(int i)const{return i ? m_kChildIndices.m_childIdx1 : m_kChildIndices.m_childIdx0;}
void setSkipNodeIdx(hkIdxType idx){m_iSkipNodeIndex=idx;}
void setParentNodeIdx(hkIdxType idx){m_usNodeValue=idx |(m_usNodeValue&s_leafFlag);}
void setChildIdx(int iChild,hkIdxType idx){if(iChild)m_kChildIndices.m_childIdx1=idx;else m_kChildIndices.m_childIdx0=idx;}
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
hkVector4 m_kAabbMin;};struct RootContactPoint;
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
struct LinearCastRequest
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
LinearCastParameters m_pRayCastInput;
const hkpCollidable*m_kCollidable;
RootContactPoint*m_pResultBuffer;
int m_iResultCount;
int m_iResultCapacity;};
struct RayCastCommandJob:public CollisionQueryJobBase
{
public:
friend struct GskAgentTaskHelper;
enum{MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK=64};
public:
__forceinline RayCastCommandJob(const GskAgentInput*input,CollisionQueryJobHeader*jobHeader,const LinearCastRequest*commandArray,int numCommands,const hkpBroadPhase*broadphase,hkSemaphoreBusyWait*semaphore,int numCommandsPerTask=MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK);
protected:
__forceinline JobDispatcher::JobPopFuncResult popJobTask(RayCastCommandJob&out);
public:
int m_iCommandCapacity;
const LinearCastRequest*m_pCommands;
int m_iCommandCount;
const hkpBroadPhase*m_pBroadPhaseRecord;
const hkAabbTree<hkAabbTreeData::RayQueryAabb,hkUint16>*m_pRayQueryAabbTree;
const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>*m_pQuantizedAabbTree;
const KdTree*m_pKdTree;};class hkpFixedBufferCdPointCollector:public hkpCdPointCollector
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
class hkpBroadPhaseCastCollector;
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
class hkpBroadPhaseCastCollector
{
public:
virtual ~hkpBroadPhaseCastCollector(){}
virtual hkReal ReleaseCollector(const hkpBroadPhaseHandle*broadphaseHandle,int castIndex)=0;
};
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
hkUint32 m_prepad0;
hkUint32 m_prepad1;
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
};typedef void**voidWriteIterator;
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
static int __cdecl CastSweptAabb(const hkAabbTree<BOUNDING_VOLUME,hkIdxType>*tree,const hkAabb&queryVolume,typename hkAabbTreeData::SweptBoxQuery&input,
Collector*collector,hkReal aabbCheckTolerance=0.0f,void**hitArray=0,int hitCapacity=0);
private:
static int __cdecl CollectAabbHitsIntoBuffers(const hkAabbTree<BOUNDING_VOLUME,hkIdxType>*tree,const hkAabb&aabb,
Collector*collector,hkArray<void*>*ptrArray,voidWriteIterator*hitArray,int hitCapacity);};
class hkKdTreeCastCollector
{
public:
virtual ~hkKdTreeCastCollector(){}
virtual hkBool ReportHit(hkPrimitiveId primId)=0;
virtual hkBool DidHit()=0;
virtual hkReal GetHitFraction()=0;
};
class KdTreeAabbCast
{
public:
enum{DEFAULT_STACK_SIZE=128};
struct BoxSweepInput
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(KdTreeAabbCast::BoxSweepInput));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkVector4 m_vHalfExtents;
BoxSweepInput(){}
};
static hkBool __cdecl CastSweptAabb(const KdTree*root,KdTreeAabbCast::BoxSweepInput&castInput,class hkKdTreeCastCollector*collector,hkReal aabbCheckTolerance);};
class hkCpuWorldLinearCastCollector:public hkpBroadPhaseCastCollector,
public hkKdTreeCastCollector,
public hkAabbTreeQueryUtils<hkAabbTreeData::RayQueryAabb,hkUint16>::Collector,
public hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::Collector
{
protected:
hkReal ReleaseCollector(const hkpBroadPhaseHandle*broadphaseHandle,int castIndex);
virtual hkBool ReportHit(hkPrimitiveId primId);
virtual hkBool DidHit();
virtual hkReal GetHitFraction();
virtual hkReal GetHitDistance(const hkAabbTree<hkAabbTreeData::RayQueryAabb,hkUint16>::Node*leaf);
virtual hkReal GetHitDistance(const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>::Node*leaf);
public:
const hkpGroupFilter*m_iFilter;
hkpFixedBufferCdPointCollector*m_pPointCollector;
const hkpCollidable*m_kCollidable;
CollisionShapeType m_iType;
ShapeSweepParameters m_pRayCastInput;};
// @fnv 0x00df7340
int __cdecl FUN_00df7340(JobDispatcher&jobQueue,JobDispatcher::JobQueueSlot&nextJobOut)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "CollQueryWorldLinearCast";h->setTime();mStream.setEnd((char*)(h+1));}};
const RayCastCommandJob&worldLinearCastJob=reinterpret_cast<RayCastCommandJob&>(nextJobOut);
hkpFixedBufferCdPointCollector castCollector(0,1);
hkCpuWorldLinearCastCollector broadPhaseCollector;
broadPhaseCollector.m_pRayCastInput.m_collisionQuality=false;
{
broadPhaseCollector.m_iFilter=static_cast<const hkpGroupFilter*>(worldLinearCastJob.m_pCollisionInput->m_iFilter.val());
broadPhaseCollector.m_pPointCollector=&castCollector;
static_cast<CollisionAgentContext&>(broadPhaseCollector.m_pRayCastInput)=*worldLinearCastJob.m_pCollisionInput;
broadPhaseCollector.m_pRayCastInput.m_pConfiguration=worldLinearCastJob.m_pCollisionInput->m_pConfiguration;
}
for(int i=0;i<worldLinearCastJob.m_iCommandCount;i++)
{
LinearCastRequest*command=const_cast<LinearCastRequest*>(&worldLinearCastJob.m_pCommands[i]);
new(&castCollector)hkpFixedBufferCdPointCollector(command->m_pResultBuffer,command->m_iResultCount);
hkVector4 castPath;castPath.setSub4(command->m_pRayCastInput.m_vTo,command->m_kCollidable->getTransform().getTranslation());
broadPhaseCollector.m_kCollidable=command->m_kCollidable;
broadPhaseCollector.m_iType=command->m_kCollidable->getShape()->getType();
broadPhaseCollector.m_pRayCastInput.m_fMaxExtraPenetration=command->m_pRayCastInput.m_fMaxExtraPenetration;
broadPhaseCollector.m_pRayCastInput.setPathAndTolerance(castPath,command->m_pRayCastInput.m_fMaxExtraPenetrationAgainstFixed);
if(!worldLinearCastJob.m_pBroadPhaseRecord)
{
hkAabb CastSweptAabb;
command->m_kCollidable->getShape()->getAabb(command->m_kCollidable->getTransform(),command->m_pRayCastInput.m_fMaxExtraPenetrationAgainstFixed,CastSweptAabb);
hkVector4 from;from.setAdd4(CastSweptAabb.m_kMaximumCorner,CastSweptAabb.m_kMinimumCorner);
from.mul4(0.5f);
hkVector4 to;to.setAdd4(from,castPath);
hkVector4 halfExtents;halfExtents.setSub4(CastSweptAabb.m_kMaximumCorner,CastSweptAabb.m_kMinimumCorner);
halfExtents.mul4(0.5f);
if(worldLinearCastJob.m_pRayQueryAabbTree || worldLinearCastJob.m_pQuantizedAabbTree)
{
hkAabbTreeData::SweptBoxQuery aabbTreeInput;
aabbTreeInput.m_vFrom=from;
aabbTreeInput.m_vTo=to;
aabbTreeInput.m_vHalfExtents=halfExtents;
hkAabbTreeQueryUtils<hkAabbTreeData::RayQueryAabb,hkUint16>::CastSweptAabb(worldLinearCastJob.m_pRayQueryAabbTree,CastSweptAabb,aabbTreeInput,&broadPhaseCollector);
hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::CastSweptAabb(worldLinearCastJob.m_pQuantizedAabbTree,CastSweptAabb,aabbTreeInput,&broadPhaseCollector);
}
if(worldLinearCastJob.m_pKdTree)
{
KdTreeAabbCast::BoxSweepInput kdTreeInput;
kdTreeInput.m_vFrom=from;
kdTreeInput.m_vTo=to;
kdTreeInput.m_vHalfExtents=halfExtents;
KdTreeAabbCast::CastSweptAabb(worldLinearCastJob.m_pKdTree,kdTreeInput,&broadPhaseCollector,0.0f);
}
}
else
{
hkpBroadPhase::AabbSweepInput castInput;
{
hkAabb aabb;
command->m_kCollidable->getShape()->getAabb(command->m_kCollidable->getTransform(),command->m_pRayCastInput.m_fMaxExtraPenetrationAgainstFixed,aabb);
castInput.m_vFrom.setInterpolate4(aabb.m_kMinimumCorner,aabb.m_kMaximumCorner,0.5f);
castInput.m_vTo.setAdd4(castInput.m_vFrom,castPath);
castInput.m_vHalfExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
castInput.m_vHalfExtents.mul4(0.5f);
castInput.m_pBroadPhaseAabbCache=0;
}
worldLinearCastJob.m_pBroadPhaseRecord->CastSweptAabb(castInput,broadPhaseCollector);
}
command->m_iResultCapacity=castCollector.m_iPointCount;
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return jobQueue.GetNextJob(&nextJobOut,nextJobOut);
}
