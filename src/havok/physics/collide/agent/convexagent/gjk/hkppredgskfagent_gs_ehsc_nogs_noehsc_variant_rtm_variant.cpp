// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct __declspec(align(16)) FUN_00d41f00_Local
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
};
void __cdecl FUN_00d41ec0(FUN_00d41f00_Local* p);
class SpawnedObject
{
public:
    void AddEntry(FUN_00d41f00_Local* p, int a, int b);
};
void __cdecl FUN_00d41f00(SpawnedObject* self, int aiArg1, int aiArg2);

extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
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
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline TYPE operator->()const
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
ValueWrapper<void*>m_next;};class hkOstream;
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
__forceinline hkReferencedObject();
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
};template<typename T>
class hkSingleton
{
public:
static T*s_instance;
static __forceinline T&__cdecl GetMonitorStream()
{
return*s_instance;
}
protected:
hkSingleton(){}
};
typedef union __declspec(intrin_type)__declspec(align(16))__m128{
unsigned __int16 m128_u16[8];}__m128;
extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
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
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;namespace MathUtilities
{template<typename T>
inline T __cdecl min2(T x,T y)
{
return x<y ? x:y;
}
}
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkQuaternion
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_vec;
protected:
void setFlippedRotation(const hkVector4&from);};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkVector4&getColumn(int i);
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
__forceinline hkTransform(){}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
class hkSweptTransform
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline void _approxTransformAt(hkTime time,hkTransform&transformOut)const;
__forceinline hkReal getInvDeltaTime()const;
public:
hkVector4 m_vCenterOfMass0;
hkVector4 m_vCenterOfMass1;
hkQuaternion m_qRotation0;
hkQuaternion m_qRotation1;
hkVector4 m_vCenterOfMassLocal;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline hkVector4&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
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
hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4 r0=t.m_rotation.getColumn(0);
const hkVector4 r1=t.m_rotation.getColumn(1);
const hkVector4 r2=t.m_rotation.getColumn(2);
const hkVector4 r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}
hkReal hkSweptTransform::getInvDeltaTime()const
{
return m_vCenterOfMass1(3);
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
};
class hkMotionState
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkSweptTransform&getSweptTransform()const;
protected:
hkTransform m_kMotionTransform;
class hkSweptTransform m_kSweptTransform;
public:
hkVector4 m_kDeltaAngle;
hkReal m_fObjectRadius;};const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;};class hkSphere
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
hkVector4 m_pos;};typedef hkUint16 hkContactPointId;class Vector4WithInt24W:public hkVector4
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
class hkpConvexShape;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
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
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
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
};
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
__forceinline hkpShapeKey getShapeKey()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
__forceinline hkpCdBody(const hkpCdBody*parent,const hkTransform*t);
__forceinline void SetCollisionShapeAndKey(const hkpShape*shape,hkpShapeKey key);
__forceinline const hkMotionState*GetMotionState()const;
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;
const hkpCdBody*m_parent;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState*hkpCdBody::GetMotionState()const
{
return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
hkpCdBody::hkpCdBody(const hkpCdBody*parent,const hkTransform*t)
{
m_parent=parent;
m_pMotionState=t;
}
hkpShapeKey hkpCdBody::getShapeKey()const
{
return m_uiCollisionShapeKey;
}
void hkpCdBody::SetCollisionShapeAndKey(const hkpShape*shape,hkpShapeKey key)
{
m_pCollisionShape=shape;
m_uiCollisionShapeKey=key;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
class hkpCollisionAgent;
struct FourByteState
{};
struct AgentProcessingInput
{
AgentProcessingInput():m_pAdditionalCollidableBody(0){}
ValueWrapper<const hkpCdBody*>m_pBodyA;
ValueWrapper<const hkpCdBody*>m_pBodyB;
ValueWrapper<const hkpCdBody*>m_pAdditionalCollidableBody;
ValueWrapper<const GskAgentInput*>m_pRayCastInput;
ValueWrapper<hkpContactMgr*>m_pContactManager;
hkTransform m_kTransform;};
struct AgentSubtypeMarker:public AgentProcessingInput
{
ValueWrapper<hkReal>m_fSubtypeValue;
hkVector4 m_vSubtypePosition;};
struct CollisionQualityInfo
{
__declspec(align(16))hkReal m_fMinimumCollisionSeparation;
hkReal m_fMinimumExtraSeparation;
hkReal m_fMaximumExtraSeparation;
hkReal m_fTimeOfImpactSeparation;
ValueWrapper<hkBool32>m_iQualityInfoValue10;
hkBool m_bUseContinuousPhysics;
hkReal m_fCreateContactThreshold;
hkReal m_fManifoldTimeDistance;
hkReal m_fMinimumSafeDeltaTime;
hkReal m_fMinimumAbsoluteTimeOfImpact;
hkReal m_fMinimumTimeOfImpactDelta;
hkReal m_fMaximumTimeOfImpactDelta;};
class hkpCollisionFilter;
class hkpConvexListFilter;
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
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
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
hkReal m_fExpectedMaxLinearVelocity;};struct ContactPointWithId
{};
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector)=0;
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector)=0;
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector)=0;
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
virtual void cleanup(hkpConstraintOwner&info)=0;
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner){}
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
virtual void removePoint(hkContactPointId idToRemove);
virtual void CommitPotentialContactPoint(hkContactPointId iContactPointId);
virtual void MarkContactPointAsZombie(hkContactPointId idTobecomeZombie);
protected:
inline virtual ~hkpCollisionAgent();
inline hkpCollisionAgent(hkpContactMgr*contactMgr);
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();
};class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;
ValueWrapper<hkTime>m_fEndTime;
ValueWrapper<hkReal>m_fTimeStep;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable ValueWrapper<CollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
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
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);};enum{HK_MAX_CONTACT_POINT=256};
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
ValueWrapper<ContactPointWithId*>m_pAlignedPairData;
ValueWrapper<hkpConstraintOwner*>m_pConstraintOwner;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
ValueWrapper<ContactPointBuffer*>m_akContactRecords;};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
hkpIterativeLinearCastAgent(hkpContactMgr*contactMgr):hkpCollisionAgent(contactMgr){}
};
struct GskAgentData;
class ConvexShapePairCache;
class hkpGskBaseAgent:public hkpIterativeLinearCastAgent
{
public:
virtual void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
public:
hkpGskBaseAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,hkpContactMgr*mgr);
private:
friend class hkpConvexListAgent;
hkpGskBaseAgent(hkpContactMgr*mgr):hkpIterativeLinearCastAgent(mgr){}
protected:
__forceinline hkBool _getClosestPoint(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,GskAgentData&output);
static void __cdecl ComputeClosestPoint(const hkpCdBody&bodyA,const hkpCdBody&bodyB,hkReal earlyOutTolerance,ConvexShapePairCache&gsk,hkVector4&separatingNormalOut);
hkBool ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,GskAgentData&output);
static __forceinline hkBool staticGetClosestPoint(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&aTb,const CollisionAgentContext&input,ConvexFeaturePairCache&cache,struct GskAgentData&output);
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
~hkpGskBaseAgent(){}
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
inline hkReal getRadius()const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const=0;
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
class SegmentSegmentClosestPoint
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
struct ConvexContactManifold
{
struct AlignedPairData
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(ConvexContactManifold::AlignedPairData));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUchar m_ucDimensionA;
hkUchar m_ucDimensionB;
hkContactPointId m_iOwnerObjectOffset;
union
{
hkUchar m_vert[4];
hkUint32 m_uiVertexIndices;
};
void zeroVerts(){m_uiVertexIndices=0;}
};
typedef hkUint16 VertexId;
enum{MAX_POINTS=4};
enum{MAX_VERTICES=MAX_POINTS*4};
__forceinline const VertexId*getVertexIds()const;
hkUchar m_ucNumVerticesA;
hkUchar m_ucNumVerticesB;
hkUchar m_usNumContactPoints;
AlignedPairData m_akContactPoints[MAX_POINTS];};const ConvexContactManifold::VertexId*ConvexContactManifold::getVertexIds()const
{
return reinterpret_cast<const VertexId*>(reinterpret_cast<const char*>(&m_akContactPoints)+m_usNumContactPoints*sizeof(AlignedPairData));
}
class hkpGskfAgent:public hkpGskBaseAgent
{
public:
static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
virtual void removePoint(hkContactPointId idToRemove);
virtual void CommitPotentialContactPoint(hkContactPointId iContactPointId);
virtual void MarkContactPointAsZombie(hkContactPointId idTobecomeZombie);
protected:
friend class hkpConvexConvexWelderAgent;
hkpGskfAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,hkpContactMgr*mgr);
~hkpGskfAgent(){}
void ProcessGskCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
public:
static hkpCollisionAgent*__cdecl m_pVirtualFunction0(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
public:
ConvexContactManifold m_kContactManifold;
};
class hkpPredGskfAgent:public hkpGskfAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void FUN_00d42020(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result);
public:
static hkpCollisionAgent*__cdecl CreateCollisionAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
public:
__forceinline hkpPredGskfAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
};
namespace MotionUtilities
{
void __cdecl ComputeTransformAtTime(const hkSweptTransform&sweptTrans,hkTime time,hkTransform&transformOut);
__forceinline void __cdecl calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut);}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut)
{
const hkSweptTransform&st0=ms0.getSweptTransform();
const hkSweptTransform&st1=ms1.getSweptTransform();
hkVector4 diff0;diff0.setSub4(st0.m_vCenterOfMass0,st0.m_vCenterOfMass1);
hkVector4 diff1;diff1.setSub4(st1.m_vCenterOfMass1,st1.m_vCenterOfMass0);
hkReal f0=deltaTime*st0.getInvDeltaTime();
hkReal f1=deltaTime*st1.getInvDeltaTime();
timOut.setMul4(f0,diff0);
timOut.addMul4(f1,diff1);
timOut(3)=f0*ms0.m_kDeltaAngle(3)*ms0.m_fObjectRadius+f1*ms1.m_kDeltaAngle(3)*ms1.m_fObjectRadius;}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
class hkTraceStream:public hkReferencedObject,public hkSingleton<hkTraceStream>
{
public:
static const struct ClassMemberDescriptor Members[];
void dontPrintf(const char*title,const char*fmt,...);
public:
hkTraceStream(){m_stream=0;m_iFirstInteger=0;}
public:
hkOstream*m_stream;
int m_iFirstInteger;};
class ConvexShapePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
ConvexShapePairCache():m_uiCacheFlags(0){}
__forceinline void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const ConvexFeaturePairCache&cache);
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
hkVector4 unk60;
hkVector4 unk70;
hkVector4 unk80;
hkVector4 unk90;
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
struct MeshVertexBasisData
{
Vector4WithInt24W m_kVertices[ConvexContactManifold::MAX_VERTICES];
hkVector4 m_kFirstBasisVector;
ValueWrapper<hkReal>m_kBoxBasisVector;
ValueWrapper<hkReal>m_kThirdBasisVector;
ValueWrapper<hkReal>m_fMinimumCollisionSeparation;
ValueWrapper<hkReal>m_fMaximumSeparation;};
extern "C"
{
void __cdecl RemoveManifoldContacts(ConvexContactManifold&manifold,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
int __cdecl BuildManifoldOperation(ConvexContactManifold&manifold,const MeshVertexBasisData&work,int firstPointIndex,WorldOperationEntry&out,hkpContactMgr*contactMgr);
void __cdecl BuildContactPointOperation(const AgentSubtypeMarker&in3,const hkReal allowedPenetration,const hkReal minSeparation,const hkReal toiSeparation,ConvexFeaturePairCache&gskCache,hkVector4&separatingNormal,WorldOperationEntry&output);
__forceinline void __cdecl hkGskManifold_init(const ConvexContactManifold&manifold,const hkVector4&masterNormal,const hkpCdBody&cA,const hkpCdBody&m_ucPackageByte,hkReal keepContactMaxDist,MeshVertexBasisData&work)
{
work.m_fMinimumCollisionSeparation=keepContactMaxDist;
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(cA.getShape());
const hkpConvexShape*shapeB=static_cast<const hkpConvexShape*>(m_ucPackageByte.getShape());
work.m_kBoxBasisVector=shapeA->getRadius();
work.m_kThirdBasisVector=shapeB->getRadius();
hkReal maxDist=work.m_fMinimumCollisionSeparation+work.m_kBoxBasisVector+work.m_kThirdBasisVector;
work.m_fMaximumSeparation=maxDist*maxDist;
work.m_kFirstBasisVector=masterNormal;
if(!manifold.m_usNumContactPoints)
{
return;
}
const ConvexContactManifold::VertexId*vertexIds=manifold.getVertexIds();
shapeA->GetVerticesForIds(vertexIds,manifold.m_ucNumVerticesA,&work.m_kVertices[0]);
hkVector4Util_S::TransformPointArray(cA.getTransform(),&work.m_kVertices[0],manifold.m_ucNumVerticesA,&work.m_kVertices[0]);
int b=manifold.m_ucNumVerticesA;
Vector4WithInt24W*verts=&work.m_kVertices[b];
shapeB->GetVerticesForIds(vertexIds+b,manifold.m_ucNumVerticesB,verts);
hkVector4Util_S::TransformPointArray(m_ucPackageByte.getTransform(),verts,manifold.m_ucNumVerticesB,verts);
}
}
// @fnv 0x00d42020
void hkpPredGskfAgent::FUN_00d42020(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&output)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "Gsk";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock155;
char names[2][128];
{
if(m_fFloatValue !=input.m_pStepInfo.m_uiStartTime)
{
if(!input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
m_fFloatValue=input.m_pStepInfo.m_fEndTime;
goto PROCESS_AT_T1;
}
hkTransform tA;
hkTransform tB;
hkpCdBody bA(&bodyA,&tA);bA.SetCollisionShapeAndKey(bodyA.getShape(),bodyA.getShapeKey());
hkpCdBody bB(&bodyB,&tB);bB.SetCollisionShapeAndKey(bodyB.getShape(),bodyB.getShapeKey());
MotionUtilities::ComputeTransformAtTime(bodyA.GetMotionState()->getSweptTransform(),input.m_pStepInfo.m_uiStartTime,tA);
MotionUtilities::ComputeTransformAtTime(bodyB.GetMotionState()->getSweptTransform(),input.m_pStepInfo.m_uiStartTime,tB);
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(bodyA.getShape());
const hkpConvexShape*shapeB=static_cast<const hkpConvexShape*>(bodyB.getShape());
ConvexShapePairCache gsk;
gsk.init(shapeA,shapeB,m_pAccessManager);
ComputeClosestPoint(bA,bB,input.m_pCollisionQualityInfo->m_fMinimumCollisionSeparation,gsk,m_vSeparatingNormal);
gsk.checkForChangesAndUpdateCache(m_pAccessManager);
}
m_fFloatValue=input.m_pStepInfo.m_fEndTime;
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
hkVector4 timInfo;
MotionUtilities::calcTimInfo(*msA,*msB,input.m_pStepInfo.m_fTimeStep,timInfo);
hkReal realProjectedLinearDelta=timInfo.dot3(m_vSeparatingNormal);
hkReal distAtT1=m_vSeparatingNormal(3)-realProjectedLinearDelta-timInfo(3);
if(distAtT1>input.m_pCollisionQualityInfo->m_fMinimumCollisionSeparation&&m_fSeparationDistance*0.5<distAtT1)
{
if(0)hkTraceStream::GetMonitorStream().dontPrintf("Tim","# Tim %-6s %-6s dist:%2.4f \n",names[0],names[1],distAtT1);
m_vSeparatingNormal(3)=distAtT1;
if(m_kContactManifold.m_usNumContactPoints)
{
RemoveManifoldContacts(m_kContactManifold,m_pContactManager,*output.m_pConstraintOwner.val());
}
goto END_OF_FUNCTION;
}
if(input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
AgentSubtypeMarker in3;
in3.m_pBodyA=&bodyA;
in3.m_pBodyB=&bodyB;
in3.m_pRayCastInput=&input;
in3.m_pContactManager=m_pContactManager;
in3.m_fSubtypeValue=distAtT1;
in3.m_vSubtypePosition=timInfo;
CollisionQualityInfo*qi=input.m_pCollisionQualityInfo;
const hkReal distance=m_vSeparatingNormal(3);
const hkReal minSeparation=MathUtilities::min2(qi->m_fCreateContactThreshold*m_fSeparationDistance,distance+qi->m_fManifoldTimeDistance*m_fSeparationDistance);
if(distAtT1>=minSeparation)
{
goto QUICK_VERIFY_MANIFOLD;
}
const hkReal toiSeparation=MathUtilities::min2(qi->m_fMinimumTimeOfImpactDelta*m_fSeparationDistance,distance+qi->m_fMaximumTimeOfImpactDelta*m_fSeparationDistance);
BuildContactPointOperation(in3,m_fSeparationDistance,minSeparation,toiSeparation,m_pAccessManager,m_vSeparatingNormal,output);
goto PROCESS_AT_T1;
}
QUICK_VERIFY_MANIFOLD:
if(distAtT1>input.m_pCollisionQualityInfo->m_fTimeOfImpactSeparation)
{
if(0)hkTraceStream::GetMonitorStream().dontPrintf("Pts","# Pts %-6s %-6s dist:%2.4f \n",names[0],names[1],distAtT1);
m_vSeparatingNormal(3)=distAtT1;
MeshVertexBasisData work;
hkGskManifold_init(m_kContactManifold,m_vSeparatingNormal,bodyA,bodyB,input.getTolerance(),work);
BuildManifoldOperation(m_kContactManifold,work,0,output,m_pContactManager);
goto END_OF_FUNCTION;
}
}
PROCESS_AT_T1:
ProcessGskCollision(bodyA,bodyB,input,output);
END_OF_FUNCTION:;
}
