// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void FUN_00d374f0(int a, int b, int c, int d);
struct FUN_00d37690_Class {
    void __thiscall ForwardToFunction(int a, int b, int c, int d);
};
void FUN_00d37740(int a, int b, int c, int d);
void FUN_00d37780(int a, int b, int c, int d);
void FUN_00d37860(int a, int b, int c, int d);
void FUN_00d378a0(int a, int b, int c, int d);
void FUN_00d37280(int a, int b, int c, int d);
void FUN_00daf8e0();
void FUN_00d3ac80();
struct FUN_00cfbbe0_Arg {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    char f4;
    char f5;
};
struct FUN_00cfbbe0_Class {
    void __thiscall FUN_00cfbbe0(FUN_00cfbbe0_Arg* a, int b, int c);
};
void FUN_00d377d0(int pClass);
struct Handler {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void process(unsigned short index, int argument);
};
struct Owner {
    virtual ~Owner();
    int unk04;
    Handler* handler;
    unsigned short* values;
    int count;
    void ProcessValuesAndDelete(int argument);
};
struct S_00d37860_Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    bool m_bHit;
    S_00d37860_Base() : m_bHit(false) {}
};
struct S_00d37860_Collector : S_00d37860_Base {
    int m_iFilter;
    S_00d37860_Collector(int filter) : m_iFilter(filter) {}
    virtual void f1();
};
void FUN_00d374f0(void* b, void* a, void* c, S_00d37860_Collector* collector);
void FUN_00d37860(void* a, void* b, void* c, int filter);
struct Payload { const char* name; float value; int id; };
extern float DAT_0104da48;
extern const char DAT_010ce7fc[];
void FUN_00d37280(int, int, int, Payload*);
void FUN_00d378a0(int aiArg1, int aiArg2, int aiArg3, int aiId);
struct D376B0Allocator;
struct D376B0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D376B0Allocator* m_pStreamAllocator;

    D376B0Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D376B0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(D376B0Allocator* alloc, void* array, int numElements, int sizeElem);
class D376B0ReferencedObject {
public:
    D376B0ReferencedObject() : m_sReferenceCount(1) {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
// hkInplaceArray<hkUint16, 4> without a destructor (Havok was built without EH).
struct D376B0IndexArray {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned short m_kStorage[4];

    D376B0IndexArray() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000004) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void SetSizeAndGrow(int n)
    {
        D376B0Allocator& alloc = FUN_00c85750().heap();
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(unsigned short));
        }
        m_iElementCount = n;
    }
};
struct D376B0Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_numChildren;
};
struct D376B0ShapeRef {
    D376B0Shape* m_pCollisionShape;
};
class D376B0Filter : public D376B0ReferencedObject {
public:
    D376B0Filter(void* userData) : m_ulUserData(userData) {}

    void* m_ulUserData;
};
class FUN_00d376b0 : public D376B0Filter {
public:
    FUN_00d376b0(const D376B0ShapeRef& shape, void* ReportDiagnostic, void* unused1, void* userData);
    virtual void unk00();

    D376B0IndexArray m_ppIndices;
};

namespace RaySimd {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
};
extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_load_ss(const float*);
}
}

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
class hkClass;
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
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
__forceinline TYPE val()const
{
return m_kStorage;
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
__forceinline int GetLogicalSize()const;
typedef const T*const_iterator;
__forceinline const_iterator begin()const;
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
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator=RouterHeapAllocatorProvider>
class hkArray:public HavokElementArray<T>
{
public:
typedef Allocator AllocatorType;hkArray(FinishingFlag f):HavokElementArray<T>(f){}
protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};
template<typename T,unsigned N,typename Allocator=RouterHeapAllocatorProvider>
class hkInplaceArray:public hkArray<T,Allocator>
{
public:
typedef hkInplaceArray<T,N,Allocator>mytype;
public:
T m_kStorage[N];
public:
hkInplaceArray(FinishingFlag f):hkArray<T,Allocator>(f){}
};template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
typename HavokElementArray<T>::const_iterator HavokElementArray<T>::begin()const
{
return m_data;
}

typedef RaySimd::__m128 hkQuadReal;
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
m_vValue=(RaySimd::_mm_load_ss)(&x);
}
__forceinline hkQuadReal broadcast()const
{
return (RaySimd::_mm_shuffle_ps)(m_vValue,m_vValue,0);
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void setInterpolate4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter t);
__forceinline void _setMul3(const hkMatrix3&a,const hkVector4&b);
__forceinline void _setRotatedDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
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
void SetMulInverse(const hkTransform&bTa,const hkTransform&bTc);
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};inline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=(RaySimd::_mm_sub_ps)(DAT_010ec7f0,t);
m_vComponents=(RaySimd::_mm_add_ps)(
(RaySimd::_mm_mul_ps)(s,v0.m_vComponents),
(RaySimd::_mm_mul_ps)(t,v1.m_vComponents));}
inline void hkVector4::_setMul3(const hkMatrix3&a,const hkVector4&b)
{
const hkQuadReal b0=(RaySimd::_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=(RaySimd::_mm_mul_ps)(a.getColumn(0).m_vComponents,b0);
const hkQuadReal b1=(RaySimd::_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=(RaySimd::_mm_mul_ps)(a.getColumn(1).m_vComponents,b1);
const hkQuadReal b2=(RaySimd::_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=(RaySimd::_mm_mul_ps)(a.getColumn(2).m_vComponents,b2);
m_vComponents=(RaySimd::_mm_add_ps)((RaySimd::_mm_add_ps)(r0,r1),r2);}
inline void hkVector4::_setRotatedDir(const hkRotation&r,const hkVector4&v)
{
_setMul3(r,v);
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=(RaySimd::_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=(RaySimd::_mm_mul_ps)(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=(RaySimd::_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=(RaySimd::_mm_mul_ps)(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=(RaySimd::_mm_shuffle_ps)(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=(RaySimd::_mm_mul_ps)(r.getColumn(2).m_vComponents,b2);
m_vComponents=(RaySimd::_mm_add_ps)((RaySimd::_mm_add_ps)(r0,r1),(RaySimd::_mm_add_ps)(r2,t.getTranslation().m_vComponents));}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
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
hkBool m_bFlag;
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
__asm {
rdtsc
mov dword ptr[ticks], eax
}
m_uiStartTicks=ticks;
}
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4&getPosition();
inline hkVector4&getSeparatingNormal();
inline void setDistance(hkReal d);
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};inline hkVector4&hkContactPoint::getPosition()
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
class hkAabb;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
__forceinline hkBool RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const;
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
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
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
};hkBool hkpShape::RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const
{
return IntersectRayWithShape(input,output);
}
struct RayCastHitResult
{
inline RayCastHitResult();
inline void reset();
hkVector4 m_vHitNormal;
hkReal m_fHitFraction;
int m_iExtraInfo;};
void RayCastHitResult::reset()
{
m_fHitFraction=1.0f;
m_iExtraInfo=-1;
}
RayCastHitResult::RayCastHitResult()
{
reset();
}
struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline ShapeRayCastOutput();
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};
void ShapeRayCastOutput::_reset()
{
m_uiShapeKeyIndex=0;
m_uiShapeKeys[0]=0xffffffff;
}
ShapeRayCastOutput::ShapeRayCastOutput()
{
_reset();
}
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
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct CollisionAgentContext;
struct GskAgentInput;
struct WorldOperationEntry;
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
class hkpCdBodyPairCollector;
class hkpContactMgr;
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
class hkpMultiRayConvexAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);

virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
hkpMultiRayConvexAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createMultiRayConvexAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createConvexMultiRayAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
struct ContactPointIdEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpMultiRayConvexAgent::ContactPointIdEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkContactPointId m_usContactPointId;
};
hkInplaceArray<ContactPointIdEntry,4>m_kContactPointIds;
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
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};
class hkpMultiRayShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
struct Ray
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpMultiRayShape::Ray));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
hkVector4 m_kRayStart;
hkVector4 m_kRayEnd;
};
public:
hkpMultiRayShape(const Ray*rays,int nRays,hkReal rayPenetrationDistance=0.0f);
inline const hkArray<Ray>&getRays()const{return m_kRays;}
inline hkReal getRayPenetrationDistance()const{return m_fRayRadius;}
protected:
hkArray<struct Ray>m_kRays;
hkReal m_fRayRadius;
public:
hkpMultiRayShape(FinishingFlag flag):hkpShape(flag),m_kRays(flag){m_type=HK_SHAPE_MULTI_RAY;}
};
class hkpRayShapeCollectionFilter;
struct ShapeRayCastQuery
{
inline ShapeRayCastQuery();
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkUint32 m_uiFilterInfo;
const hkpRayShapeCollectionFilter*m_pRayShapeCollectionFilter;};
inline ShapeRayCastQuery::ShapeRayCastQuery()
:m_uiFilterInfo(0),
m_pRayShapeCollectionFilter(0)
{
}
extern const char DAT_010ceda8[];
extern const char DAT_010c41f8[];

// @fnv 0x00d37280
void __cdecl FUN_00d37280(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName=DAT_010ceda8;h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpMultiRayShape*msA=static_cast<const hkpMultiRayShape*>(bodyA.getShape());
const hkpConvexShape*convexB=static_cast<const hkpConvexShape*>(bodyB.getShape());
hkTransform bTa;bTa.SetMulInverse(bodyB.getTransform(),bodyA.getTransform());
const hkArray<hkpMultiRayShape::Ray>&RaysA=msA->getRays();
int nRays=RaysA.GetLogicalSize();
const hkpMultiRayShape::Ray*rayA=RaysA.begin();
ContactPointPair event(bodyA,bodyB);
ShapeRayCastQuery rayInput;
for(int i=0;i<nRays;i++)
{
ShapeRayCastOutput rayResults;
rayInput.m_vFrom._setTransformedPos(bTa,rayA->m_kRayStart);
rayInput.m_vTo._setTransformedPos(bTa,rayA->m_kRayEnd);
hkBool rayHit=convexB->RayCast(rayInput,rayResults);
if(rayHit)
{
const hkVector4&normal=rayResults.m_vHitNormal;
const hkReal dist=rayResults.m_fHitFraction;
hkVector4 hitpoint;hitpoint.setInterpolate4(rayInput.m_vFrom,rayInput.m_vTo,dist);
event.m_kPoint.getPosition()._setTransformedPos(bodyB.getTransform(),hitpoint);
event.m_kPoint.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(),normal);
event.m_kPoint.setDistance((dist-1.0f)*rayA->m_kRayStart(3)+msA->getRayPenetrationDistance());
collector.AddCdPoint(event);
}
rayA++;
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName=DAT_010c41f8;h->setTime();mStream.setEnd((char*)(h+1));}};
}
