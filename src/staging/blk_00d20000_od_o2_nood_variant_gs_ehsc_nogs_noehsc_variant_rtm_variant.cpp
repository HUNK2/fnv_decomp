// src/staging/blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/staging/blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/staging/blk_00d20000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
float _mm_cvtss_f32(__m128);
void _mm_store_ss(float*, __m128);
}
struct hkVector4
{
    __m128 m_vComponents;

    __forceinline float lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 z = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), y);
        float r;
        _mm_store_ss(&r, z);
        return r;
    }
};
struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};
bool FUN_00d28560(void* unused, char** items, int count, int offset);
inline void* operator new(unsigned int, void* p) throw() { return p; }
inline void operator delete(void*, void*) throw() {}
struct FinishingFlag
{
    int m_bFinishing;
};
static inline FinishingFlag NotFinishing()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    return flag;
}
class S00d2c8a0_Base
{
public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class S00d2c8a0_Derived : public S00d2c8a0_Base
{
public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag) {}
    virtual void vf04();
    __m128 m_kScaleFactors;
};
const void* __cdecl FUN_00d2c8a0();
struct SortPair {
    unsigned int key;
    unsigned int val;
};
// @fnv 0x00d36520
extern "C" void FUN_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;) {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val)) {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val)) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j) {
            FUN_00d36520(arr, lo, j, extra);
        }
        if (i >= hi) {
            break;
        }
        lo = i;
    }
}
struct hkpAgent3FuncsD367 {
    hkpAgent3FuncsD367()
    {
        m_bIsPredictive = false;
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction7 = 0;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};
void __cdecl FUN_00d367b0(hkpAgent3FuncsD367& kFuncs);
class hkpCollisionDispatcherD367 {
public:
    void AddEntry(const hkpAgent3FuncsD367& kFuncs, int iTypeA, int iTypeB);
};
void __cdecl FUN_00d367d0(hkpCollisionDispatcherD367* pkDispatcher);
struct hkpAgent3FuncsD398 {
    hkpAgent3FuncsD398()
    {
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
        m_pAgentFunction7 = 0;
        m_bIsPredictive = false;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};
class hkpCollisionDispatcherD398 {
public:
    void AddEntry(const hkpAgent3FuncsD398& kFuncs, int iTypeA, int iTypeB);
};
void InitOutputDefaults();
void FUN_00d39130();
void ReleaseHandles();
void RemoveKeyFromTable();
void InsertIntoSlotArray();
void FUN_00d39090();
void FUN_00d39150();
void FUN_00d39390();
void __cdecl FUN_00d39840(hkpCollisionDispatcherD398* pkDispatcher);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;class hkClass;
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
hkReferencedObject(struct FinishingFlag flag){}
};
extern "C"{
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
extern __m128 _mm_load_ss(float const*_A);};
typedef __m128 hkQuadReal;
struct hkVec4X;
typedef const hkVec4X&hkVector4Parameter;
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
class hkTransform;
struct hkVec4X
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVec4X&v);
__forceinline void setAddMul4(const hkVec4X&a,const hkVec4X&b,hkSimdRealParameter r);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVec4X&b);
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
__forceinline hkVec4X&getColumn(int i);
__forceinline const hkVec4X&getColumn(int i)const;
protected:
hkVec4X m_kColumn0;
hkVec4X m_kColumn1;
hkVec4X m_kColumn2;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVec4X&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVec4X m_vTranslation;};inline void hkVec4X::operator=(const hkVec4X&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVec4X::setAddMul4(const hkVec4X&a,const hkVec4X&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVec4X::_setTransformedPos(const hkTransform&t,const hkVec4X&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline hkReal&hkVec4X::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline hkVec4X&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
inline const hkVec4X&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVec4X&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVec4X r0=t.m_rotation.getColumn(0);
const hkVec4X r1=t.m_rotation.getColumn(1);
const hkVec4X r2=t.m_rotation.getColumn(2);
const hkVec4X r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}
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
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVec4X m_kMinimumCorner;};class hkSphere
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
hkVec4X m_pos;};typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVec4X&getPosition();
inline hkVec4X&getSeparatingNormal();
inline void setSeparatingNormal(const hkVec4X&normal,hkReal dist);
inline void setNormal(const hkVec4X&normal);
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVec4X m_vContactPosition;
hkVec4X m_vSeparatingNormal;};inline hkVec4X&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVec4X&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setSeparatingNormal(const hkVec4X&normal,hkReal dist)
{
m_vSeparatingNormal=normal;
m_vSeparatingNormal(3)=dist;
}
class Vector4WithInt24W:public hkVec4X
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
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
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
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape(struct FinishingFlag flag):hkReferencedObject(flag)
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
struct WorldOperationEntry;
class hkpConstraintOwner;
class hkpCollisionAgent;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
class hkpCollisionDispatcher:public hkReferencedObject
{
public:
enum{
HK_MAX_RESPONSE_TYPE=8,
HK_MAX_SHAPE_TYPE=32,
HK_MAX_AGENT2_TYPES=64,
HK_MAX_AGENT3_TYPES=16,
HK_MAX_COLLISION_QUALITIES=8
};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
typedef hkpCollisionAgent*(__cdecl*CreateFunc)(const hkpCdBody&collA,const hkpCdBody&collB,const CollisionAgentContext&env,hkpContactMgr*mgr);
typedef void(__cdecl*GetPenetrationsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
typedef void(__cdecl*GetClosestPointsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&output);
typedef void(__cdecl*LinearCastFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector);
struct CollisionAgentFunctionTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionAgentFunctionTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CreateFunc m_pCreateFunc;
GetPenetrationsFunc m_pQueryPenetrationsFunc;
GetClosestPointsFunc m_pGetPenetrationsFunc;
LinearCastFunc m_pLinearCastFunc;
hkBool m_bIsFlipped;
hkBool m_bIsPredictive;
CollisionAgentFunctionTable():m_bIsFlipped(false),m_bIsPredictive(false){}
};
public:
hkpCollisionDispatcher(CreateFunc defaultCreationFunction,hkpContactMgrFactory*defaultContactMgrFactory);
public:
struct IntegerPair
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(IntegerPair));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CollisionShapeType m_iSecond;
CollisionShapeType m_iFirst;
};
struct AgentTypePairPriority
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(AgentTypePairPriority));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
char m_iAgentTypeA;
char m_iAgentTypeB;
char m_priority;
};
typedef AgentTypePairPriority DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
protected:
void internalRegisterCollisionAgent(hkUchar agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE],int agentType,CollisionShapeType typeA,CollisionShapeType typeB,CollisionShapeType origA,CollisionShapeType origB,DebugTable*debugTable,int recursionDepth);
public:
enum CollisionQualityLevel
{
COLLISION_QUALITY_INVALID,
COLLISION_QUALITY_PSI,
COLLISION_QUALITY_SIMPLIFIED_TOI,
COLLISION_QUALITY_TOI,
COLLISION_QUALITY_TOI_HIGHER,
COLLISION_QUALITY_TOI_FORCED,
COLLISION_QUALITY_CHARACTER,
COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
};
public:
hkReal m_fExpectedMaxLinearVelocity;};
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
inline hkpContactMgr*getContactMgr();};
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVec4X*vectorsIn,int numVectors,hkVec4X*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVec4X*vectorsIn,int numVectors,hkVec4X*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
struct MaterialIndexedTriangle
{
hkUint8 m_uiMaterialIndex;
hkpVertexId m_auiVertexIds[3];
};
class TriangleDistanceUtility
{
public:
static void __cdecl calcBarycentricCoordinates(hkVector4Parameter pos,hkVector4Parameter t0,hkVector4Parameter t1,hkVector4Parameter t2,ValueWrapper<hkReal>result[3]);
struct FourRealValueRecord
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(TriangleDistanceUtility::FourRealValueRecord));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_fFirstValue;
hkReal m_fSecondValue;
hkReal m_fThirdValue;
hkReal m_fFourthValue;
};
struct CollisionDistanceInfo
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(TriangleDistanceUtility::CollisionDistanceInfo));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVec4X m_kNearestPoint;
ValueWrapper<hkReal>distance;
void calcClosestPoint(hkVector4Parameter point,hkVec4X&closestPoint)
{
closestPoint.setAddMul4(point,m_kNearestPoint,distance.val());
}
};
static void __cdecl setupClosestPointTriangleCache(const hkVec4X*triangle,FourRealValueRecord&cache);
enum ClosestPointTriangleStatus
{
HIT_TRIANGLE_FACE=0,
HIT_TRIANGLE_EDGE
};
static ClosestPointTriangleStatus __cdecl GetClosestPointOnTriangle(hkVector4Parameter position,const hkVec4X*tri,const FourRealValueRecord&cache,CollisionDistanceInfo&result,MaterialIndexedTriangle*featureOutput=0);protected:
TriangleDistanceUtility();};
class hkpSphereTriangleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl initAgentFuncInverse(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerAgent2(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpSphereTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl CreateSphereTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createTriangleSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_FACE,
ST_CP_EDGE
};
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&m_pAccessManager,hkContactPoint&cpoint);
static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&m_pAccessManager,hkContactPoint&cpoint,MaterialIndexedTriangle*featureOutput=0);
hkContactPointId m_usContactPointId;
TriangleDistanceUtility::FourRealValueRecord m_kTriangleAccessData;
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
virtual void GetFirstVertex(hkVec4X&v)const=0;
inline hkReal getRadius()const;enum WeldResult
{
WELD_RESULT_REJECT_CONTACT_POINT,
WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
};
__forceinline hkpConvexShape::WeldResult weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVec4X&contactPointWs,const hkTransform*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVec4X&separatingNormalInOut)const;
virtual hkReal getMaximumProjection(const hkVec4X&direction)const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const=0;
virtual int WeldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,hkVec4X&contactPointWs,const hkTransform*thisObjTransform,const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVec4X&separatingNormalInOut)const;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVec4X&contactPointWs,const hkTransform*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVec4X&separatingNormalInOut)const
{
return(WeldResult)this->WeldContactPoint(featurePoints,numFeaturePoints,
contactPointWs,thisObjTransform,
collidingShape,collidingTransform,separatingNormalInOut);}
class hkpTriangleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline const hkVec4X*GetIndexedVertices()const;
protected:
hkUint16 m_kWeldingInfo;
hkVec4X m_kVertexA;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
};const hkVec4X*hkpTriangleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}
class hkpSphereShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkpSphereShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_SPHERE;}
};
hkpSphereTriangleAgent::ClosestPointResult __cdecl hkpSphereTriangleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&cache,hkContactPoint&cpoint,MaterialIndexedTriangle*featureOutput)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
const hkVec4X&posA=bodyA.getTransform().getTranslation();
hkVec4X triVertices[3];
hkVector4Util_S::TransformPointArray(bodyB.getTransform(),triB->GetIndexedVertices(),3,triVertices);
TriangleDistanceUtility::CollisionDistanceInfo cptr;
TriangleDistanceUtility::ClosestPointTriangleStatus res=TriangleDistanceUtility::GetClosestPointOnTriangle(posA,triVertices,cache,cptr,featureOutput);
const hkReal radiusSum=sphereA->getRadius()+triB->getRadius();
if(cptr.distance<radiusSum+input.getTolerance())
{
cpoint.getPosition().setAddMul4(posA,cptr.m_kNearestPoint,triB->getRadius()-cptr.distance);
cpoint.setSeparatingNormal(cptr.m_kNearestPoint,cptr.distance-radiusSum);
if(res==TriangleDistanceUtility::HIT_TRIANGLE_FACE)
{
return ST_CP_FACE;
}
else
{
return ST_CP_EDGE;
}
}
return ST_CP_MISS;}
// @fnv 0x00d3d8c0
void __cdecl FUN_00d3d8c0(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "SphereTri";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock47;
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
TriangleDistanceUtility::FourRealValueRecord cache;
TriangleDistanceUtility::setupClosestPointTriangleCache(triB->GetIndexedVertices(),cache);
ContactPointPair event(bodyA,bodyB);
MaterialIndexedTriangle featureOutput;
if(hkpSphereTriangleAgent::getClosestPointInl(bodyA,bodyB,input,cache,event.m_kPoint,&featureOutput))
{
hkUchar m_uiMaterialIndex=featureOutput.m_uiMaterialIndex;
if(input.m_collisionQuality.val()&&m_uiMaterialIndex>0)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
hkVec4X weldedNormal=event.m_kPoint.getSeparatingNormal();
hkVec4X pointPos=event.m_kPoint.getPosition();
hkpConvexShape::WeldResult weldResult=triB->weldContactPoint(&featureOutput.m_auiVertexIds[0],m_uiMaterialIndex,pointPos,&bodyB.getTransform(),sphereA,&bodyA.getTransform(),weldedNormal);
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
event.m_kPoint.setNormal(weldedNormal);
}
}
collector.AddCdPoint(event);
}
}
