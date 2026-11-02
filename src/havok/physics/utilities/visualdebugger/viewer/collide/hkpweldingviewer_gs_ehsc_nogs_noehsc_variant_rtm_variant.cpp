// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpweldingviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00dd9380_class { void* FUN_00dd9380(const char* name, void* factory); };
extern int DAT_01269cd0;
extern int DAT_01268fbc;
void* __cdecl FUN_00d62e20();
void __cdecl RegisterWeldingViewer();
struct S_00d62650_B1 {
    virtual void vfn1();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct S_00d62650_B3 {
    virtual void vfn3();
};
struct S_00d62650_Arg {
    void __thiscall FUN_00c93920(S_00d62650_B3* p);
};
struct S_00d62650_B2 {
    virtual void DispatchToArg(S_00d62650_Arg* arg);
    int unk04;
};
struct S_00d62650_D : S_00d62650_B1, S_00d62650_B2, S_00d62650_B3 {
    virtual void DispatchToArg(S_00d62650_Arg* arg);
};
// hkpWeldingViewer - virtual slot 2 of the base subobject at +0x20.
// Removes the entity pointer held by this subobject from the world's list.
//   this  -> the base subobject (complete object + 0x20)
//   -0x20 -> the complete object
//   +0x08 -> the pointer that is handed to the list (complete object + 0x28)
struct HKWorldList {
    void IsEntityAdded(void* entity);
};
struct HKConstraint {
    int unk00;
    int unk04;
    void* unk08;
    void FUN_00d62680(HKWorldList* list);
};
struct S_00d626b0_Item {
    void FUN_00c93920(void* apSub);
};
struct S_00d626b0_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
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
    S_00d626b0_Item** m_6c;
    int m_70;
};
struct S_00d626b0_A {
    virtual void a0();
    int unk04;
};
struct S_00d626b0_B {
    virtual void b0();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_00d626b0_C {
    virtual void c0();
    S_00d626b0_Owner* m_24;
};
struct S_00d626b0_R : S_00d626b0_A, S_00d626b0_B, S_00d626b0_C {
    S_00d626b0_R(int a) throw();
};
struct S_00d626b0_S {
    virtual void s0();
    S_00d626b0_S() throw() {}
};
struct FUN_00d626b0 : S_00d626b0_R, S_00d626b0_S {
    FUN_00d626b0(int a) throw();
    virtual void a0();
    virtual void b0();
    virtual void c0();
    virtual void s0();
};
class D62720Listener {
public:
    virtual ~D62720Listener() throw() {}
};
class D62720Island {
public:
    void removeListener(D62720Listener* listener);
};
struct D62720World {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    D62720Island** m_islands;
    int m_iIslandCount;
};
class D62720BaseA {
public:
    virtual ~D62720BaseA();

    int unk04;
};
class D62720BaseB {
public:
    virtual void unk00();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class D62720BaseC {
public:
    virtual void unk00();
};
class D62720Base : public D62720BaseA, public D62720BaseB, public D62720BaseC {
public:
    virtual ~D62720Base();

    D62720World* m_pOwningWorld;
};
class FUN_00d62720 : public D62720Base, public D62720Listener {
public:
    virtual ~FUN_00d62720() throw();
};
// The factory that creates one hkpWeldingViewer-like record for the physics
// world: it asks the world manager's pool for a 0x2c byte block, stamps the
// block size into the record header and then runs the record's constructor.
struct Viewer;
struct Pool {
    virtual void dummy0();
    virtual Viewer* alloc0x2c(int n);
};
struct Manager {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Pool* unk10;
};
struct Viewer {
    int unk00;
    unsigned short unk04;
    void* ctor0d626b0(void* arg);
};
extern "C" void* __cdecl FUN_00c85750();
void* __cdecl FUN_00d62e20_impl(void* arg);
extern int g_D62E80Value;
int __cdecl FUN_00d62e80();
// FUN_00d62e90 : MSVC this-adjusting thunk  (sub ecx, 0x20 ; jmp <impl>)
struct A1_00d62e90 {
    A1_00d62e90();
    virtual void FUN_00d62e90();
    char pad[0x1c];
};
struct A2_00d62e90 {
    A2_00d62e90();
    virtual void FUN_00d62e90();
};
struct Own_00d62e90 : A1_00d62e90, A2_00d62e90 {
    Own_00d62e90();
    virtual void key_fn();
// @fnv 0x00d62e90
    void FUN_00d62e90();
};
Own_00d62e90::Own_00d62e90() { }
void Own_00d62e90::key_fn() { }
Own_00d62e90* make_00d62e90() { static Own_00d62e90 o; return &o; }
struct D62EA0Primary {
    virtual void vfunc00();
    virtual void FUN_00d62ea0();

    int unk04;
};
struct D62EA0Secondary {
    virtual void FUN_00d62ea0();
};
struct D62EA0Object : D62EA0Primary, D62EA0Secondary {
    D62EA0Object();

// @fnv 0x00d62ea0
    virtual void FUN_00d62ea0();
};
D62EA0Object::D62EA0Object()
{
}
// FUN_00d62eb0 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
struct A1_00d62eb0 {
    A1_00d62eb0();
    virtual void FUN_00d62eb0();
    char pad[0x24];
};
struct A2_00d62eb0 {
    A2_00d62eb0();
    virtual void FUN_00d62eb0();
};
struct Own_00d62eb0 : A1_00d62eb0, A2_00d62eb0 {
    Own_00d62eb0();
    virtual void key_fn();
// @fnv 0x00d62eb0
    void FUN_00d62eb0();
};
Own_00d62eb0::Own_00d62eb0() { }
void Own_00d62eb0::key_fn() { }
Own_00d62eb0* make_00d62eb0() { static Own_00d62eb0 o; return &o; }

extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;class FinishingFlag
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
char m_cBooleanValue;};
class hkHalf
{
public:
inline hkHalf(){}
inline hkHalf(const float&f)
{
int t=((const int*)&f)[0];
m_uiFilterValue=hkInt16(t>>16);
}
private:
hkInt16 m_uiFilterValue;};template<typename ENUM,typename STORAGE>
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
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
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
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
__forceinline hkReferencedObject();
virtual ~hkReferencedObject(){}
void removeReference()const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};template<class TYPE>
class ReferenceCountedPointer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
TYPE*m_pRetainedObject;};template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
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
__forceinline HavokElementArray();
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline const T&operator[](int i)const;
__forceinline int GetLogicalSize()const;
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
typedef Allocator AllocatorType;
__forceinline hkArray():HavokElementArray<T>(){}
hkArray(FinishingFlag f):HavokElementArray<T>(f){}
protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};template<typename T>
__forceinline const T&HavokElementArray<T>::operator[](int i)const
{
;
return m_data[i];
}
template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
class ResizableArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
enum
{
CAPACITY_MASK=hkUint16(0x3fff),
FLAG_MASK=hkUint16(0xC000),
DONT_DEALLOCATE_FLAG=hkUint16(0x8000),
LOCKED_FLAG=hkUint16(0x4000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
hkUint16 m_iElementCount;
public:
ResizableArray(FinishingFlag f){}
};
typedef union __declspec(intrin_type)__declspec(align(16))__m128{
unsigned __int16 m128_u16[8];}__m128;
extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ss(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ss(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_rsqrt_ss(__m128 _A);
extern __m128 _mm_andnot_ps(__m128 _A,__m128 _B);
extern __m128 _mm_xor_ps(__m128 _A,__m128 _B);
extern __m128 _mm_cmpeq_ss(__m128 _A,__m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
extern __m128 _mm_set_ss(float _A);
extern __m128 _mm_load_ss(float const*_A);
extern void _mm_store_ss(float*_V,__m128 _A);};
extern "C" __m128 _mm_set_ps1 (float);
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
class hkTransform;
class hkQsTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setZero4();
__forceinline void add4(const hkVector4&a);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void setMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void setCross(const hkVector4&a,const hkVector4&b);
__forceinline void setInterpolate4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter t);
__forceinline void interpolateBroadcast(const hkVector4& a,const hkVector4& b,hkQuadReal t);
__forceinline void setNeg3(const hkVector4&v);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
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
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setNeg3(const hkVector4&v)
{
extern const hkQuadReal DAT_010c4c00;
m_vComponents=_mm_xor_ps(v.m_vComponents,DAT_010c4c00);
}
inline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
inline void hkVector4::setCross(const hkVector4&v0,const hkVector4&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
inline void hkVector4::interpolateBroadcast(const hkVector4& a,const hkVector4& b,hkQuadReal t) { extern const hkQuadReal DAT_010ec7f0;  hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t); t=_mm_mul_ps(t,b.m_vComponents); m_vComponents=_mm_add_ps(_mm_mul_ps(s,a.m_vComponents),t); }
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
inline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
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
class hkStringPtr
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkStringPtr(FinishingFlag f);
private:
const char*m_pcText;};
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
hkUint32 m_uiThreadId;
protected:
hkUint16 m_usMarkCount;
public:
static class PhysicsSimulationContext*m_pWorldLock;};enum CollisionShapeType
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
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum hkpBufferSize
{
HK_SHAPE_BUFFER_SIZE=512
};
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
class hkAabb;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
__forceinline CollisionShapeType getType()const;
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
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;
const hkpCdBody*m_parent;};class hkpBroadPhaseHandle
{
public:
static const struct ClassMemberDescriptor Members[];public:
hkpBroadPhaseHandle(class FinishingFlag flag){}
};
class hkpTypedBroadPhaseHandle:public hkpBroadPhaseHandle
{
public:
static const struct ClassMemberDescriptor Members[];protected:
enum{OFFSET_INVALID=127};
public:
hkInt8 m_ucObjectQualityType;
hkUint32 m_uiCollisionFilterData;};
struct hkAabbUint32;
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
class hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
public:
struct BoundingVolumeData m_kBoundingVolumeData;
hkReal m_fAllowedPenetrationDepth;};__forceinline const hkpShape*hkpCollidable::getShape()const
{
return m_pCollisionShape;
}
struct NarrowPhaseAgentEntry;
class hkpLinkedCollidable:public hkpCollidable
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
struct CollisionKeyEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpLinkedCollidable::CollisionKeyEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
NarrowPhaseAgentEntry*m_pAgentEntry;
hkpLinkedCollidable*m_pCollidable;
};
protected:
hkArray<struct CollisionKeyEntry>m_kCollisionEntries;};
class hkpRigidBody;class hkpWorldObject:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkpCollidable*getCollidable()const;
public:
enum BroadPhaseType
{
BROAD_PHASE_INVALID,
BROAD_PHASE_ENTITY,
BROAD_PHASE_PHANTOM,
BROAD_PHASE_BORDER,
BROAD_PHASE_MAX_ID
};
protected:
friend class hkpWorld;
public:
virtual class hkMotionState*GetMotionState()=0;
protected:
hkpWorld*m_pOwningWorld;
hkUlong m_ulUserData;
protected:
class hkpLinkedCollidable m_kCollidable;
protected:
class hkMultiThreadCheck m_kMultiThreadCheck;
hkStringPtr m_name;
hkArray<class hkpProperty>m_kProperties;
private:
class hkReferencedObject*m_kNextStreamField;
void*m_pWorldObjectOwner;
public:
hkpWorldObject(class FinishingFlag flag);};inline const hkpCollidable*hkpWorldObject::getCollidable()const
{
return&m_kCollidable;
}
class hkpMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum ResponseType
{
RESPONSE_INVALID,
RESPONSE_SIMPLE_CONTACT,
RESPONSE_REPORTING,
RESPONSE_NONE,
RESPONSE_MAX_ID
};
private:
hkEnum<ResponseType,hkInt8>m_eResponseType;
hkReal m_fSlipAngle;
hkReal m_fElasticity;
public:
hkpMaterial(class FinishingFlag flag){}
};
struct ConstraintInstanceBuffer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum{CAPACITY=128};void reset(){m_uiConstraintCount=0;}
public:
hkUint32 m_uiConstraintCount;
class hkpConstraintInstance*m_ppConstraints[CAPACITY];};class hkMotionState
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkTransform&getTransform()const;
protected:
hkTransform m_kMotionTransform;
public:
hkVector4 m_kDeltaAngle;};const hkTransform&hkMotionState::getTransform()const
{
return m_kMotionTransform;
}
class hkpMotion:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
enum MotionType
{
MOTION_INVALID,
MOTION_DYNAMIC,
MOTION_SPHERE_INERTIA,
MOTION_BOX_INERTIA,
MOTION_KEYFRAMED,
MOTION_FIXED,
MOTION_THIN_BOX_INERTIA,
MOTION_CHARACTER,
MOTION_MAX_ID
};
public:
inline MotionType getType()const{return m_type;}
inline const hkTransform&getTransform()const;
public:
hkpMotion(class FinishingFlag flag):hkReferencedObject(flag){if(flag.m_bFinishing){m_fGravityFactor=1.f;}}
public:
enum{NUM_INACTIVE_FRAMES_TO_DEACTIVATE=5};
public:
hkEnum<MotionType,hkUint8>m_type;
class hkMotionState m_kMotionState;
class hkpMaxSizeMotion*m_pSavedMotion;
hkHalf m_fGravityFactor;};const hkTransform&hkpMotion::getTransform()const
{
return m_kMotionState.getTransform();
}
class hkpKeyframedRigidMotion:public hkpMotion
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
hkpKeyframedRigidMotion():hkpMotion(FinishingFlag()){m_pSavedMotion=0;}
public:
public:
virtual void SetStepPosition(hkReal position,hkReal timestep);
public:
hkpKeyframedRigidMotion(class FinishingFlag flag):hkpMotion(flag){}
};
class hkpMaxSizeMotion:public hkpKeyframedRigidMotion
{
public:
static const struct ClassMemberDescriptor Members[];private:
void operator=(const hkpMaxSizeMotion&other);};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;
class hkLocalFrame;
class hkpEntity:public hkpWorldObject
{
public:
static const struct ClassMemberDescriptor Members[];
enum SpuCollisionCallbackEventFilter
{
SPU_SEND_NONE=0x00,
SPU_SEND_CONTACT_POINT_ADDED=0x01,
SPU_SEND_CONTACT_POINT_PROCESS=0x02,
SPU_SEND_CONTACT_POINT_REMOVED=0x04,
SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS=SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
};
public:
virtual ~hkpEntity();
protected:
const ResizableArray<struct ConstraintRuntimeInfo>&getConstraintMastersImpl()const;
public:
hkpEntity(class FinishingFlag flag);protected:
class hkpMaterial m_iMaterialIndex;
protected:
friend class ConstraintInstanceOwner;
public:
public:
class SmallArraySerializeOverrideType
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpEntity::SmallArraySerializeOverrideType));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
void*m_data;
hkUint16 m_iElementCount;
hkUint16 m_iCapacityState;
};
public:void*m_pEntityUserData;
hkReal m_fBulletSpread;
public:hkUint32 m_uiFilterInfo;
public:hkObjectIndex m_usStorageIndex;
protected:hkUint16 m_usNextProcessCallbackDelay;
protected:ResizableArray<struct ConstraintRuntimeInfo>m_eSmallArraySerializeOverrideType;
protected:hkArray<hkpConstraintInstance*>m_kSlaveConstraints;
protected:
hkArray<hkUint8>m_pByteBuffer;
public:
hkInt8 m_iAutoRemoveLevel;
hkUint32 m_uiUniqueId;
public:
struct SpuCollisionCallback
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpEntity::SpuCollisionCallback));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
SpuCollisionCallback():
m_pCallbackData(0),
m_pRayCursor(0),
m_uiCallbackType(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
m_bCallbackEnabled(0x01)
{
}
hkSpuCollisionCallbackUtil*m_pCallbackData;
hkUint16 m_pRayCursor;
hkUint8 m_uiCallbackType;
hkUint8 m_bCallbackEnabled;
SpuCollisionCallback(FinishingFlag flag){}
};
struct ExtendedListeners
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpEntity::ExtendedListeners));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
ResizableArray<hkpEntityActivationListener*>m_kContactListenerArray;
ResizableArray<hkpEntityListener*>m_kEntityListenerArray;
};
public:
struct SpuCollisionCallback m_kSpuCollisionCallback;
public:class hkpMaxSizeMotion m_pMotionState;
protected:
friend class PhysicsEntity;
protected:
ResizableArray<hkpAction*>m_ppActions;
public:
ReferenceCountedPointer<hkLocalFrame>m_pLocalFrame;
protected:mutable ExtendedListeners*m_pExtendedListeners;};
class hkpWorldDeletionListener
{
public:
virtual ~hkpWorldDeletionListener(){}
virtual void WorldDeletedCallback(hkpWorld*world)=0;
virtual void worldRemoveAllCallback(hkpWorld*world){}
};
class hkVisualDebugger;
class hkProcessContext
{
public:
hkProcessContext():m_pOwnerObject(0){}
public:
hkVisualDebugger*m_pOwnerObject;};
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
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};
class hkpActionListener
{
public:
virtual ~hkpActionListener(){}
virtual void ActionAddedCallback(hkpAction*action){}
virtual void ActionRemovedCallback(hkpAction*action){}
};
class hkpConstraintListener
{
public:
virtual ~hkpConstraintListener(){}
};class hkpPhantomListener
{
public:
virtual ~hkpPhantomListener(){}
};
class hkpEntityListener
{
public:
virtual ~hkpEntityListener(){}
};
class hkpPhysicsContextWorldListener
{
public:
virtual ~hkpPhysicsContextWorldListener(){}
virtual void WorldAddedCallback(hkpWorld*newWorld)=0;
virtual void WorldRemovedCallback(hkpWorld*newWorld)=0;
};
class hkpPhysicsContext:
public hkReferencedObject,public hkProcessContext,
public hkpWorldDeletionListener,
public hkpEntityListener,
public hkpPhantomListener,
public hkpConstraintListener,
public hkpActionListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void SetOwnerPointer(hkVisualDebugger*vdb);
protected:
virtual ~hkpPhysicsContext();};
class hkDisplayGeometry;
class hkDebugDisplayHandler;
class hkProcessHandler;
class hkProcess
{
public:
hkProcess(hkBool selectable)
:m_bSelectionEnabled(selectable){}
hkBool m_bSelectionEnabled;
hkDebugDisplayHandler*m_pDisplayHandler;
hkProcessHandler*m_pProcessHandler;
virtual void CollectProcessCommands(hkUint8*&commands,int&numCommands){commands=0;numCommands=0;}
};
class hkpWorldViewerBase:public hkReferencedObject,
public hkProcess,
protected hkpPhysicsContextWorldListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}protected:
hkpPhysicsContext*m_iValueAtOffset0C;};
class hkpWorldPostSimulationListener
{
public:
virtual ~hkpWorldPostSimulationListener(){}
virtual void FUN_00d62780(hkpWorld*world)=0;
virtual void EntityRemovalCallback(hkpEntity*entity){}
};
class hkpWeldingViewer:public hkpWorldViewerBase,public hkpWorldPostSimulationListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
static hkProcess*__cdecl create(const hkArray<hkProcessContext*>&contexts);
static void __cdecl RegisterViewer(void);
static inline const char*__cdecl getName(void){return "WeldingViewer";}
virtual int GetOperationType(void){return m_ucOperationType;}
void FUN_00d62780(hkpWorld*world);
protected:
hkpWeldingViewer(const hkArray<hkProcessContext*>&contexts);
virtual ~hkpWeldingViewer();
virtual void WorldAddedCallback(hkpWorld*world);
virtual void WorldRemovedCallback(hkpWorld*world);
static int m_ucOperationType;
};
class hkpPhysicsSystem;
class hkpSimulation;
struct EmptyPayload
{};
class hkpWorld:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
void lock();
void unlock();
hkpPhysicsSystem*getWorldAsOneSystem()const;
public:
__forceinline void lockCriticalOperations();
private:
void ExecutePendingOperations();
public:
__forceinline void allowCriticalOperations(hkBool allow);
public:
hkpSimulation*m_pSimulation;
public:
hkUint32 m_uiLastEntityUid;
public:
hkUint32 m_uiLastConstraintUid;
public:
struct EmptyPayload m_kDynamicsStepInfo;};
class hkpPhysicsSystem:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
inline const hkArray<hkpRigidBody*>&getRigidBodies()const;
protected:
hkArray<class hkpRigidBody*>m_ppRigidBodies;
hkArray<class hkpConstraintInstance*>m_ppConstraints;
hkArray<class hkpAction*>m_ppActions;
hkArray<class hkpPhantom*>m_kPhantoms;
hkStringPtr m_name;
public:
hkpPhysicsSystem(FinishingFlag f):
hkReferencedObject(f),m_ppRigidBodies(f),m_ppConstraints(f),m_ppActions(f),m_kPhantoms(f),m_name(f){}
};
inline const hkArray<hkpRigidBody*>&hkpPhysicsSystem::getRigidBodies()const
{
return m_ppRigidBodies;
}
class hkpRigidBody:public hkpEntity
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkTransform&getTransform()const;
public:
inline hkpMotion*getRigidMotion()const;
public:
static void __cdecl createDynamicRigidMotion(hkpMotion::MotionType motionType,
const hkVector4&position,const hkQuaternion&rotation,
hkReal mass,const hkMatrix3&inertiaLocal,const hkVector4&centreOfMassLocal,
hkReal maxLinearVelocity,hkReal maxAngularVelocity,
hkpMaxSizeMotion*motionBufferOut);
protected:
virtual hkMotionState*GetMotionState();
public:
hkpRigidBody(class FinishingFlag flag):hkpEntity(flag){}
};inline hkpMotion*hkpRigidBody::getRigidMotion()const
{
return const_cast<hkpMaxSizeMotion*>(&m_pMotionState);
}
inline const hkTransform&hkpRigidBody::getTransform()const
{
return getRigidMotion()->getTransform();
}
class hkpShapeContainer
{
public:
static const struct ClassMemberDescriptor Members[];
virtual ~hkpShapeContainer(){}
virtual int GetNumChildShapes()const;
virtual hkpShapeKey GetFirstKey()const=0;
virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey)const=0;
virtual hkUint32 GetFilterInfoForKey(hkpShapeKey key)const;
virtual const hkpShape*GetShapeForKey(hkpShapeKey key,hkpShapeBuffer&buffer)const=0;};
class hkpSingleShapeContainer:public hkpShapeContainer
{
public:
static const struct ClassMemberDescriptor Members[];virtual hkpShapeKey GetFirstKey()const{return 0;}
virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey)const{return 0xffffffff;}
virtual const hkpShape*GetShapeForKey(hkpShapeKey key,hkpShapeBuffer&buffer)const;
inline const hkpShape*getChild()const{return m_pContainedShape;}
protected:
const hkpShape*m_pContainedShape;};
class hkpWeldingUtility
{
public:
static const struct ClassMemberDescriptor Members[];
enum WeldingType
{
WELDING_TYPE_ANTICLOCKWISE=0,
WELDING_TYPE_CLOCKWISE=4,
WELDING_TYPE_TWO_SIDED=5,
WELDING_TYPE_NONE=6
};
enum SectorType
{
ACCEPT_0=1,
SNAP_0=0,
REJECT=2,
SNAP_1=4,
ACCEPT_1=3
};
static __forceinline void calcSnapVector(const hkVector4&triangleNormal,const hkVector4&edge,int edgeBitcode,SectorType sector,hkVector4&snapVectorOut);
static __forceinline void calcSnapVectorOneSided(const hkVector4&triangleNormal,const hkVector4&edge,int edgeBitcode,hkpWeldingUtility::WeldingType weldingType,hkVector4&snapVectorOut);
enum NumAngles
{
NUM_ANGLES=31
};
public:
struct FloatArray6
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpWeldingUtility::FloatArray6));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_fValue0;
hkReal m_fValue1;
hkReal m_fValue2;
hkReal m_fValue3;
hkReal m_fValue4;
hkReal m_fValue5;
};
static __declspec(align(16))FloatArray6 ms_akEdgeAngleTable[NUM_ANGLES+1];};void hkpWeldingUtility::calcSnapVector(const hkVector4&triangleNormal,const hkVector4&edge,int edgeBitcode,SectorType sector,hkVector4&snapVectorOut)
{
hkVector4 orthNormalEdge;orthNormalEdge.setCross(edge,triangleNormal);
hkReal*sinCosTableEntry=&ms_akEdgeAngleTable[edgeBitcode].m_fValue0;
hkVector4 hVec0;hVec0.setMul4(sinCosTableEntry[sector+0],triangleNormal);
hkVector4 hVec1;hVec1.setMul4(sinCosTableEntry[sector+1],orthNormalEdge);
snapVectorOut.setAdd4(hVec0,hVec1);
snapVectorOut.normalize3();}
void hkpWeldingUtility::calcSnapVectorOneSided(const hkVector4&triangleNormal,const hkVector4&edge,int edgeBitcode,hkpWeldingUtility::WeldingType weldingType,hkVector4&snapVectorOut)
{
calcSnapVector(triangleNormal,edge,edgeBitcode,(SectorType)weldingType,snapVectorOut);
}
class hkpShapeCollection:public hkpShape,public hkpShapeContainer
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkBool m_bDisableWelding;};
class hkpBvTreeShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
enum BvTreeType
{
BVTREE_MOPP,
BVTREE_TRISAMPLED_HEIGHTFIELD,
BVTREE_USER,
BVTREE_MAX
};
public:
hkEnum<BvTreeType,hkUint8>m_uiUserData;};
class hkMoppBvTreeShapeBase:public hkpBvTreeShape
{
public:
static const struct ClassMemberDescriptor Members[];
public:
const class hkpMoppCode*m_pMoppCode;
hkVector4 m_kMoppCodeInfo;};
class hkpMoppBvTreeShape:public hkMoppBvTreeShapeBase
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkpShapeCollection*getShapeCollection()const;
protected:
class hkpSingleShapeContainer m_pChildAtom;
public:
mutable int m_iChildSize;};inline const hkpShapeCollection*hkpMoppBvTreeShape::getShapeCollection()const
{
return static_cast<const hkpShapeCollection*>(m_pChildAtom.getChild());
}
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
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};
class hkpTriangleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline const hkVector4&getVertex(int i)const;
__forceinline hkUint16 getWeldingInfo()const;
__forceinline hkpWeldingUtility::WeldingType getWeldingType()const;
protected:
hkUint16 m_kWeldingInfo;
hkEnum<hkpWeldingUtility::WeldingType,hkUint8>m_eWeldingType;
hkVector4 m_kVertexA;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
};
hkUint16 hkpTriangleShape::getWeldingInfo()const
{
return m_kWeldingInfo;
}
__forceinline hkpWeldingUtility::WeldingType hkpTriangleShape::getWeldingType()const
{
return m_eWeldingType;
}
const hkVector4&hkpTriangleShape::getVertex(int i)const
{
;
return(&m_kVertexA)[i];
}
class hkpMeshWeldingUtility
{
public:
enum WindingConsistency
{
WINDING_IGNORE_CONSISTENCY,
WINDING_TEST_CONSISTENCY,
};
public:
static int __cdecl calcSingleEdgeBitcode(hkUint16 triangleEdgesBitcode,int edgeIndex);
static void __cdecl calcAntiClockwiseTriangleNormal(const hkVector4&vertex0,const hkVector4&vertex1,const hkVector4&vertex2,hkVector4&normal);
public:
static hkResult __cdecl calcWeldingInfoForTriangle(hkpShapeKey shapeKey,const hkpBvTreeShape*bvTreeShape,WindingConsistency testConsistency,hkUint16&info);};
class hkDebugDisplayHandler
{
public:
enum Command
{
HK_STEP=0x00,
HK_ADD_GEOMETRY,
HK_UPDATE_GEOMETRY,
HK_SET_COLOR_GEOMETRY,
HK_REMOVE_GEOMETRY,
HK_DISPLAY_GEOMETRY_WITH_TRANSFORM,
HK_DISPLAY_GEOMETRY,
HK_DISPLAY_POINT,
HK_DISPLAY_LINE,
HK_DISPLAY_TEXT,
HK_SEND_STATISTICS_DUMP_DEPRICATED,
HK_HOLD_IMMEDIATE,
HK_ADD_CAMERA,
HK_UPDATE_CAMERA,
HK_REMOVE_CAMERA,
HK_SEND_MEMSTATS_DUMP,
HK_ADD_GEOMETRY_INSTANCE,
HK_DISPLAY_TEXT_3D,
HK_UPDATE_BEHAVIOR,
HK_LIST_BEHAVIORS,
HK_DISPLAY_ANNOTATION,
};
virtual ~hkDebugDisplayHandler(){}
virtual hkResult AddDisplayGeometry(const HavokElementArray<hkDisplayGeometry*>&geometries,const hkTransform&transform,hkUlong id,int tag,hkUlong shapeIdHint)=0;
virtual hkResult ReplaceGeometry(hkUlong origianalGeomId,const hkTransform&transform,hkUlong id,int tag,hkUlong shapeIdHint)=0;
virtual hkResult SetGeometryColor(int color,hkUlong id,int tag)=0;
virtual hkResult m_bUpdateGeometry(const hkTransform&transform,hkUlong id,int tag)=0;
virtual hkResult RemoveGeometry(hkUlong id,int tag,hkUlong shapeIdHint)=0;
virtual hkResult DisplayCamera(const hkVector4&from,const hkVector4&to,const hkVector4&up,hkReal nearPlane,hkReal farPlane,hkReal fov,const char*name)=0;
virtual hkResult DisplayBehaviorGraph(const HavokElementArray<int>&wordVarIdx,const HavokElementArray<int>&wordStack,const HavokElementArray<int>&quadVarIdx,const HavokElementArray<hkVector4>&quadStack,
const HavokElementArray<char*>&activeNodes,const HavokElementArray<int>&activeStateIds,const HavokElementArray<int>&activeTransitions,const HavokElementArray<hkQsTransform>&transforms)=0;
virtual hkResult DisplayPoint(const hkVector4&position,int colour,int id,int tag)=0;
virtual hkResult DisplayLine(const hkVector4&start,const hkVector4&end,int color,int id,int tag)=0;};
class hkColor
{
public:
static int __cdecl rgbFromChars(unsigned char red,unsigned char green,unsigned char blue,unsigned char alpha=0xff);public:
enum ExtendedColors
{
MAROON=0xFF800000,
DARKRED=0xFF8B0000,
RED=0xFFFF0000,
LIGHTPINK=0xFFFFB6C1,
CRIMSON=0xFFDC143C,
PALEVIOLETRED=0xFFDB7093,
HOTPINK=0xFFFF69B4,
DEEPPINK=0xFFFF1493,
MEDIUMVIOLETRED=0xFFC71585,
PURPLE=0xFF800080,
DARKMAGENTA=0xFF8B008B,
ORCHID=0xFFDA70D6,
THISTLE=0xFFD8BFD8,
PLUM=0xFFDDA0DD,
VIOLET=0xFFEE82EE,
FUCHSIA=0xFFFF00FF,
MAGENTA=0xFFFF00FF,
MEDIUMORCHID=0xFFBA55D3,
DARKVIOLET=0xFF9400D3,
DARKORCHID=0xFF9932CC,
BLUEVIOLET=0xFF8A2BE2,
INDIGO=0xFF4B0082,
MEDIUMPURPLE=0xFF9370DB,
SLATEBLUE=0xFF6A5ACD,
MEDIUMSLATEBLUE=0xFF7B68EE,
DARKBLUE=0xFF00008B,
MEDIUMBLUE=0xFF0000CD,
BLUE=0xFF0000FF,
NAVY=0xFF000080,
MIDNIGHTBLUE=0xFF191970,
DARKSLATEBLUE=0xFF483D8B,
ROYALBLUE=0xFF4169E1,
CORNFLOWERBLUE=0xFF6495ED,
LIGHTSTEELBLUE=0xFFB0C4DE,
ALICEBLUE=0xFFF0F8FF,
GHOSTWHITE=0xFFF8F8FF,
LAVENDER=0xFFE6E6FA,
DODGERBLUE=0xFF1E90FF,
STEELBLUE=0xFF4682B4,
DEEPSKYBLUE=0xFF00BFFF,
SLATEGRAY=0xFF708090,
LIGHTSLATEGRAY=0xFF778899,
LIGHTSKYBLUE=0xFF87CEFA,
SKYBLUE=0xFF87CEEB,
LIGHTBLUE=0xFFADD8E6,
TEAL=0xFF008080,
DARKCYAN=0xFF008B8B,
DARKTURQUOISE=0xFF00CED1,
CYAN=0xFF00FFFF,
MEDIUMTURQUOISE=0xFF48D1CC,
CADETBLUE=0xFF5F9EA0,
PALETURQUOISE=0xFFAFEEEE,
LIGHTCYAN=0xFFE0FFFF,
AZURE=0xFFF0FFFF,
LIGHTSEAGREEN=0xFF20B2AA,
TURQUOISE=0xFF40E0D0,
POWDERBLUE=0xFFB0E0E6,
DARKSLATEGRAY=0xFF2F4F4F,
AQUAMARINE=0xFF7FFFD4,
MEDIUMSPRINGGREEN=0xFF00FA9A,
MEDIUMAQUAMARINE=0xFF66CDAA,
SPRINGGREEN=0xFF00FF7F,
MEDIUMSEAGREEN=0xFF3CB371,
SEAGREEN=0xFF2E8B57,
LIMEGREEN=0xFF32CD32,
DARKGREEN=0xFF006400,
GREEN=0xFF008000,
LIME=0xFF00FF00,
FORESTGREEN=0xFF228B22,
DARKSEAGREEN=0xFF8FBC8F,
LIGHTGREEN=0xFF90EE90,
PALEGREEN=0xFF98FB98,
MINTCREAM=0xFFF5FFFA,
HONEYDEW=0xFFF0FFF0,
CHARTREUSE=0xFF7FFF00,
LAWNGREEN=0xFF7CFC00,
OLIVEDRAB=0xFF6B8E23,
DARKOLIVEGREEN=0xFF556B2F,
YELLOWGREEN=0xFF9ACD32,
GREENYELLOW=0xFFADFF2F,
BEIGE=0xFFF5F5DC,
LINEN=0xFFFAF0E6,
LIGHTGOLDENRODYELLOW=0xFFFAFAD2,
OLIVE=0xFF808000,
YELLOW=0xFFFFFF00,
LIGHTYELLOW=0xFFFFFFE0,
IVORY=0xFFFFFFF0,
DARKKHAKI=0xFFBDB76B,
KHAKI=0xFFF0E68C,
PALEGOLDENROD=0xFFEEE8AA,
WHEAT=0xFFF5DEB3,
GOLD=0xFFFFD700,
LEMONCHIFFON=0xFFFFFACD,
PAPAYAWHIP=0xFFFFEFD5,
DARKGOLDENROD=0xFFB8860B,
GOLDENROD=0xFFDAA520,
ANTIQUEWHITE=0xFFFAEBD7,
CORNSILK=0xFFFFF8DC,
OLDLACE=0xFFFDF5E6,
MOCCASIN=0xFFFFE4B5,
NAVAJOWHITE=0xFFFFDEAD,
ORANGE=0xFFFFA500,
BISQUE=0xFFFFE4C4,
TAN=0xFFD2B48C,
DARKORANGE=0xFFFF8C00,
BURLYWOOD=0xFFDEB887,
SADDLEBROWN=0xFF8B4513,
SANDYBROWN=0xFFF4A460,
BLANCHEDALMOND=0xFFFFEBCD,
LAVENDERBLUSH=0xFFFFF0F5,
SEASHELL=0xFFFFF5EE,
FLORALWHITE=0xFFFFFAF0,
SNOW=0xFFFFFAFA,
PERU=0xFFCD853F,
PEACHPUFF=0xFFFFDAB9,
CHOCOLATE=0xFFD2691E,
SIENNA=0xFFA0522D,
LIGHTSALMON=0xFFFFA07A,
CORAL=0xFFFF7F50,
DARKSALMON=0xFFE9967A,
MISTYROSE=0xFFFFE4E1,
ORANGERED=0xFFFF4500,
SALMON=0xFFFA8072,
TOMATO=0xFFFF6347,
ROSYBROWN=0xFFBC8F8F,
PINK=0xFFFFC0CB,
INDIANRED=0xFFCD5C5C,
LIGHTCORAL=0xFFF08080,
BROWN=0xFFA52A2A,
FIREBRICK=0xFFB22222,
BLACK=0xFF000000,
DIMGRAY=0xFF696969,
GRAY=0xFF808080,
DARKGRAY=0xFFA9A9A9,
SILVER=0xFFC0C0C0,
LIGHTGREY=0xFFD3D3D3,
GAINSBORO=0xFFDCDCDC,
WHITESMOKE=0xFFF5F5F5,
WHITE=0xFFFFFFFF,
GREY=0xff888888,
GREY25=0xff404040,
GREY50=0xff808080,
GREY75=0xffc0c0c0,
};};

extern const float DAT_010d1648;
extern const double DAT_010d1640;
// @fnv 0x00d62780
void hkpWeldingViewer::FUN_00d62780(hkpWorld*world)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "hkpActiveContactPointViewer::postSimulationCallback";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock18;
world->lock();
hkpPhysicsSystem*system=world->getWorldAsOneSystem();
const hkArray<hkpRigidBody*>&rigidBodies=system->getRigidBodies();
for(int i=0;i<rigidBodies.GetLogicalSize();i++)
{
const hkpRigidBody*body=rigidBodies[i];
const int collidableId=(int)(hkUlong)(body->getCollidable());
const hkTransform&bodyTransform=body->getTransform();
const hkpShape*rootShape=body->getCollidable()->getShape();
if(rootShape->getType()==HK_SHAPE_MOPP)
{
const hkpMoppBvTreeShape*mopp=static_cast<const hkpMoppBvTreeShape*>(rootShape);
const hkpShapeCollection*coll=mopp->getShapeCollection();
for(hkpShapeKey key=coll->GetFirstKey();key !=0xffffffff;key=coll->GetNextShapeKey(key))
{
hkpShapeBuffer buffer;
const hkpShape*childShape=coll->GetShapeForKey(key,buffer);
if(childShape->getType()==HK_SHAPE_TRIANGLE)
{
const hkpTriangleShape*triangle=static_cast<const hkpTriangleShape*>(childShape);
if(triangle->getWeldingType()!=hkpWeldingUtility::WELDING_TYPE_TWO_SIDED&&triangle->getWeldingType()!=hkpWeldingUtility::WELDING_TYPE_NONE)
{
hkUint16 weldingInfo=triangle->getWeldingInfo();
hkVector4 vertices[3];
vertices[0]._setTransformedPos(bodyTransform,triangle->getVertex(0));
vertices[1]._setTransformedPos(bodyTransform,triangle->getVertex(1));
vertices[2]._setTransformedPos(bodyTransform,triangle->getVertex(2));
m_pDisplayHandler->DisplayLine(vertices[0],vertices[1],hkColor::RED,collidableId,m_ucOperationType);
m_pDisplayHandler->DisplayLine(vertices[1],vertices[2],hkColor::RED,collidableId,m_ucOperationType);
m_pDisplayHandler->DisplayLine(vertices[2],vertices[0],hkColor::RED,collidableId,m_ucOperationType);
hkVector4 triangleCenter;
triangleCenter.setAdd4(vertices[0],vertices[1]);
triangleCenter.add4(vertices[2]);
triangleCenter.mul4(1.0f / 3.0f);
hkVector4 triangleNormal;
hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(vertices[0],vertices[1],vertices[2],triangleNormal);
for(int k=0;k<3;k++)
{
int edgeIndex0=k;
int edgeIndex1=(k+1)% 3;
hkVector4 edge;
edge.setSub4(vertices[edgeIndex1],vertices[edgeIndex0]);
edge.normalize3();
int edgeCode=hkpMeshWeldingUtility::calcSingleEdgeBitcode(weldingInfo,k);
hkVector4 edgeCenter;
edgeCenter.interpolateBroadcast(vertices[edgeIndex0],vertices[edgeIndex1],_mm_set_ps1(DAT_010d1648));
hkVector4 snapVector0;
hkpWeldingUtility::calcSnapVectorOneSided(triangleNormal,edge,edgeCode,triangle->getWeldingType(),snapVector0);
if(triangle->getWeldingType()==hkpWeldingUtility::WELDING_TYPE_CLOCKWISE)
{
triangleNormal.setNeg3(triangleNormal);
}
if(snapVector0.dot3(triangleNormal)<DAT_010d1640)
{
continue;
}
hkVector4 p0,p1;
p0.setAdd4(edgeCenter,snapVector0);
p1.setAdd4(edgeCenter,triangleNormal);
m_pDisplayHandler->DisplayLine(edgeCenter,p0,hkColor::ORANGE,collidableId,m_ucOperationType);
m_pDisplayHandler->DisplayLine(edgeCenter,p1,hkColor::ORANGE,collidableId,m_ucOperationType);
m_pDisplayHandler->DisplayLine(edgeCenter,triangleCenter,hkColor::GREEN,collidableId,m_ucOperationType);
hkVector4 start;start=snapVector0;
const int kSteps=10;
for(int s=0;s<kSteps;s++)
{
hkVector4 interp;
interp.setInterpolate4(snapVector0,triangleNormal,(s+1)/ 10.0);
interp.normalize3();
hkVector4 ep0,ep1;
ep0.setAdd4(edgeCenter,start);
ep1.setAdd4(edgeCenter,interp);
m_pDisplayHandler->DisplayLine(ep0,ep1,hkColor::ORANGE,collidableId,m_ucOperationType);
start=interp;
}
}
}
}
}
}
}
system->removeReference();
world->unlock();
}
