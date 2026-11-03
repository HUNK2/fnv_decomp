// src/havok/common/base/system/io/ostream/hkostream_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/system/io/ostream/hkostream.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkOstream.h"
extern int DAT_01268108;
extern "C" __declspec(dllimport) void __stdcall free(void*);
void __cdecl FUN_00c85750();
extern char _DAT_010c9314;
extern char _DAT_0102e388;
struct Old
{
    void ReleaseReference();
};
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    ~FUN_00cc00e0();
};
struct hkReferencedObjectStandIn
{
    void RetainReference();
    void removeReference();
};
struct DDCC60WorldStandIn
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    hkReferencedObjectStandIn* m_ref;
    void FUN_00cc0480(hkReferencedObjectStandIn* pNew);
};
struct FUN_00cc0680
{
    int tell();
};
struct FUN_00cc07f0_Router
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Free(void*, unsigned short);
};
struct FUN_00cc07f0_MemoryRouter
{
    unsigned char padding[0x10];
    FUN_00cc07f0_Router* pRouter;
};
extern FUN_00cc07f0_MemoryRouter* _D1A0E0GetMemoryRouter();
struct FUN_00cc07f0_StandIn
{
    // Virtual destructor for the stand-in type; does nothing.
// @fnv 0x00cc07f0
    virtual ~FUN_00cc07f0_StandIn()
    {}
    void FUN_00cc0780();
    unsigned short m_nSize;

    FUN_00cc07f0_StandIn* FUN_00cc07f0(unsigned int deletingFlag);
};
struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuInterface* target;
    void FUN_00cc0460();
};
// FUN_00cc0470 : the stub family - load a sub-object out of `this` and tail-jump to
// one of its virtuals (vtable offset 0x10).
struct Sub_00cc0470
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a);
};
struct Own_00cc0470
{
    int u00;
    int u04;
    Sub_00cc0470* m_sub;
    void __thiscall FUN_00cc0470(void* a);
};
extern int g_unk01268560;
int* __cdecl hkOstream_getClassType();
extern int DAT_01268ad8;
int __cdecl hkArrayStreamWriter_getClassType();
void __stdcall FUN_00e3b490(bool* p);
struct FUN_00cc04a0_Slots
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C(const char* name, void* value, int flags);
};
struct FUN_00cc04a0_Cls
{
    int unk00;
    int unk04;
    void* unk08;
    void RegisterWriter(FUN_00cc04a0_Slots* target, int unused);
};
class hkMemoryAllocatorCC06
{
  public:
    virtual ~hkMemoryAllocatorCC06() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCC06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCC06* m_pStreamAllocator;

    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750() throw();
}
class hkRefObjCC06
{
  public:
    virtual ~hkRefObjCC06() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjCC06()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes) throw()
    {
        hkRefObjCC06* b = static_cast<hkRefObjCC06*>(hkRouterCC06::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class FUN_00cc06f0 : public hkRefObjCC06
{
  public:
    int unk08;
    int unk0C;
    int unk10;

    FUN_00cc06f0(void* owner, int flag) throw();
};
class FUN_00cc0630 : public hkRefObjCC06
{
  public:
    FUN_00cc06f0* m_pChildAtom;

    FUN_00cc0630(void* owner);
    virtual ~FUN_00cc0630();
};
class hkMemoryAllocatorCC07
{
  public:
    virtual ~hkMemoryAllocatorCC07() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCC07
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCC07* m_pStreamAllocator;
    hkMemoryAllocatorCC07& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC07 {
extern "C" hkMemoryRouterCC07& __cdecl FUN_00c85750() throw();
}
template <class T> class hkArrayCC07
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterCC07::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
    ~hkArrayCC07() throw()
    {
        hkMemoryAllocatorCC07& kAlloc = hkRouterCC07::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkBaseObjectCC07
{
  public:
    virtual ~hkBaseObjectCC07() throw()
    {}
};
class FUN_00cc0780 : public hkBaseObjectCC07
{
  public:
    int unk04;
    hkArrayCC07<unsigned char>* m_buffer;
    int unk0C;
    int m_external;

    virtual ~FUN_00cc0780() throw();
};
struct GlobalObject_0045cfe0
{
    ~GlobalObject_0045cfe0();
    int unk00;
};
class FUN_00cbf430 : public GlobalObject_0045cfe0
{
  public:
    ~FUN_00cbf430();
    void FUN_00cbf2f0();
};
class hkMemoryAllocatorD60B
{
  public:
    virtual ~hkMemoryAllocatorD60B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD60B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD60B* m_pStreamAllocator;

    hkMemoryAllocatorD60B& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD60B {
extern "C" hkMemoryRouterD60B& __cdecl FUN_00c85750() throw();
}
class hkRefObjD60B
{
  public:
    virtual ~hkRefObjD60B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjD60B()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjD60B* b = static_cast<hkRefObjD60B*>(hkRouterD60B::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
class FUN_00d60b40 : public hkRefObjD60B
{
  public:
    FUN_00cc06f0* m_pChildAtom;
    char m_flag;

    FUN_00d60b40(void* owner, char flag) throw();
    virtual ~FUN_00d60b40();
};
struct NiBinaryStream;
typedef unsigned int(__cdecl* NiBinaryReadFn)(NiBinaryStream* stream, void* buffer, unsigned int bytes,
                                              unsigned int* componentSizes, unsigned int numComponents);
struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    NiBinaryReadFn m_pfnRead;
};
struct NiStream
{
    void* vtbl;
    unsigned int m_uiFormatVersion;
    char m_author[0xd8];
    char m_fileName[0x105];
    char m_bLittleEndian;
    short unk1e6;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_binaryStream;
};
struct HavokError
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Warning(int type, int id, const char* desc, const char* file, int line);
};
extern HavokError* DAT_01268360;
struct BoolType
{
    char m_cBooleanValue;
    BoolType(bool b) : m_cBooleanValue(b)
    {}
    BoolType(const BoolType& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};
namespace MoppLoadStream {
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    __declspec(noinline) ~FUN_00cc00e0();
};
}
struct OStream : public MoppLoadStream::FUN_00cc00e0
{
    OStream(void* mem, int GetAllocationSize, BoolType isArray);
    OStream& operator<<(const char* s);
};
struct MoppCodeHeader
{
    int unk00;
    int unk04;
    int unk08;
    unsigned long m_data;
};
struct bhkMoppBvTreeShape
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual unsigned int slotA8();
    virtual void v2b();
    virtual void v2c();
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void bhkSerializable_LoadCInfo(NiStream& stream);

    unsigned int bhkMoppBvTreeShape_LoadCInfo(NiStream& stream);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C"
{
    extern __m128 _mm_add_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_sub_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_mul_ps(__m128 _A, __m128 _B);
    extern __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
    extern __m128 _mm_set_ps1(float _A);
    extern __m128 _mm_setr_ps(float _A, float _B, float _C, float _D);
    extern __m128 _mm_load_ss(float const* _A);
};
typedef float hkReal_X;
typedef signed char hkInt8_X;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8_X;
typedef unsigned short hkUint16_X;
typedef unsigned int hkUint32_X;
typedef unsigned long __w64 hkUlong_X;
typedef unsigned __w64 hk_size_t;
class FinishingFlag
{
  public:
    FinishingFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool_X
{
  public:
    typedef char CompileTimeTrueType;
    inline hkBool_X(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }

  private:
    char m_cBooleanValue;
};
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    hkEnum(ENUM e)
    {
        m_kStorage = static_cast<STORAGE>(e);
    }
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }

  private:
    STORAGE m_kStorage;
};
template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline TYPE operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};
class hkMemoryAllocator
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t, void* p)
    {
        return p;
    }
    virtual void* AllocateMemoryBlock(int numBytes) = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;

  public:
    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };
};
struct StringPointerTriple
{
  public:
    __forceinline StringPointerTriple();

  protected:
    ValueWrapper<void*> m_next;
};
class NineIntegerRecord
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t, void* p)
    {
        return p;
    }
    typedef hkMemoryAllocator Allocator;
    static NineIntegerRecord& __cdecl GetMonitorStream();
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    StringPointerTriple m_aiEntries;
    Allocator* m_pStreamAllocator;
    Allocator* m_pDebugAllocator;
};
class hkBaseObject_X
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    __forceinline hkBaseObject_X()
    {}
};
class hkStatisticsCollector;
class hkReferencedObject_X : public hkBaseObject_X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t, void* p)
    {
        return p;
    }
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject_X* b = static_cast<hkReferencedObject_X*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16_X>(nbytes);
        ;
        return b;
    }
    __forceinline hkReferencedObject_X();
    virtual ~hkReferencedObject_X()
    {}
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    hkUint16_X m_usMemSizeAndFlags;

  public:
    hkReferencedObject_X(class FinishingFlag flag)
    {}
};
template <typename T> class hkSingleton
{
  public:
    static T* s_instance;
    static __forceinline T& __cdecl GetMonitorStream()
    {
        return *s_instance;
    }

  protected:
    hkSingleton()
    {}
};
class hkStreamWriter;
struct RouterHeapAllocatorProvider;
class hkOstream_X : public hkReferencedObject_X
{
  public:
    static const struct ClassMemberDescriptor Members[];
    ~hkOstream_X() throw();
    hkOstream_X& operator<<(const char* s) throw();

  protected:
    hkStreamWriter* m_pStreamWriter;
};
class hkError : public hkReferencedObject_X, public hkSingleton<hkError>
{
  public:
    enum Message
    {
        MESSAGE_REPORT,
        MESSAGE_WARNING,
        MESSAGE_ASSERT,
        MESSAGE_ERROR
    };
    virtual int message(Message m, int id, const char* description, const char* file, int line) throw() = 0;
};
struct ErrStreamLite
{
    void* vtbl;
    unsigned short memFlags;
    short ref;
    void* writer;
    void FUN_00cb1600(void*, int) throw();
    void FUN_00cc01c0(const char*) throw();
    void FUN_00cc00e0() throw();
};
class hkErrStream : public hkOstream_X
{
  public:
    hkErrStream(void* buf, int bufSize) throw();
    ~hkErrStream() throw();
};
template <bool N> struct BooleanTypeConstant
{
    typedef BooleanTypeConstant<N> type;
    enum
    {
        result = N
    };
};
typedef BooleanTypeConstant<true> hkTypeIsPod;
template <typename T> class HavokElementArray
{
  public:
    typedef HavokElementArray<T> ThisType;
    __forceinline HavokElementArray();

  protected:
    __forceinline HavokElementArray(const HavokElementArray& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);
    typedef const T* const_iterator;
    __forceinline const_iterator begin() const;

  protected:
    __forceinline HavokElementArray<T>& copyFromArray(hkMemoryAllocator&, const HavokElementArray<T>& src, hkTypeIsPod);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };

  protected:
    friend class hkStatisticsCollector;
    T* m_data;

  public:
    HavokElementArray(FinishingFlag f)
    {}
};
template <typename T, typename Allocator = RouterHeapAllocatorProvider> class hkArray_X : public HavokElementArray<T>
{
  public:
    typedef Allocator AllocatorType;
    __forceinline hkArray_X() : HavokElementArray<T>()
    {}

  protected:
    __forceinline hkArray_X(const hkArray_X& a);

  public:
    __forceinline hkArray_X& operator=(const HavokElementArray<T>& a);
};
template <typename T> typename HavokElementArray<T>::const_iterator HavokElementArray<T>::begin() const
{
    return m_data;
}
typedef __m128 hkQuadReal;
class hkVector4_X;
typedef const hkVector4_X& hkVector4Parameter;
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue(hkReal_X x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;
class hkVector4_X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void operator=(const hkVector4_X& v);
    __forceinline void set(hkReal_X x, hkReal_X y, hkReal_X z, hkReal_X w = 0);
    __forceinline void setAll3(hkReal_X x);
    __forceinline void setZero4();
    __forceinline void setAdd4(const hkVector4_X& a, const hkVector4_X& b);
    __forceinline void sub4(const hkVector4_X& a);
    __forceinline void setSub4(const hkVector4_X& a, const hkVector4_X& b);
    __forceinline void mul4(const hkVector4_X& a);
    __forceinline void setMul4(hkVector4Parameter a, hkVector4Parameter b);
    __forceinline void mul4(hkSimdRealParameter a);
    __forceinline void setInterpolate4(const hkVector4_X& a, const hkVector4_X& b, hkSimdRealParameter t);
    __forceinline hkReal_X& operator()(int i);
    __forceinline const hkReal_X& operator()(int i) const;

  private:
    hkQuadReal m_vComponents;

  public:
    operator hkQuadReal() const
    {
        return m_vComponents;
    }
};
class hkMatrix3_X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  protected:
    hkVector4_X m_kColumn0;
};
class __declspec(align(16)) hkRotation_X : public hkMatrix3_X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
class hkTransform_X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  private:
    hkRotation_X m_rotation;
};
inline void hkVector4_X::operator=(const hkVector4_X& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4_X::set(hkReal_X a, hkReal_X b, hkReal_X c, hkReal_X d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
inline void hkVector4_X::setAll3(hkReal_X a)
{
    m_vComponents = _mm_set_ps1(a);
}
inline void hkVector4_X::setAdd4(const hkVector4_X& v0, const hkVector4_X& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4_X::sub4(const hkVector4_X& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4_X::setSub4(const hkVector4_X& v0, const hkVector4_X& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4_X::mul4(const hkVector4_X& v)
{
    m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4_X::setMul4(const hkVector4_X& a, const hkVector4_X& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4_X::mul4(hkSimdRealParameter s)
{
    m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
}
inline void hkVector4_X::setInterpolate4(const hkVector4_X& v0, const hkVector4_X& v1, hkSimdRealParameter _t)
{
    static __declspec(align(16)) const float cw[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    hkQuadReal t = _t.broadcast();
    hkQuadReal s = _mm_sub_ps(*(const hkQuadReal*)&cw, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
inline hkReal_X& hkVector4_X::operator()(int a)
{
    return reinterpret_cast<hkReal_X*>(&m_vComponents)[a];
}
inline const hkReal_X& hkVector4_X::operator()(int a) const
{
    return reinterpret_cast<const hkReal_X*>(&m_vComponents)[a];
}
enum CollisionShapeType
{
    HK_SHAPE_INVALID = 0,
    HK_SHAPE_SPHERE,
    HK_FIRST_SHAPE_TYPE = HK_SHAPE_SPHERE,
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
    HK_SHAPE_MAX_ID_SPU = HK_SHAPE_COMPRESSED_MESH + 1,
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
    HK_SHAPE_ALL = -1
};
class hkpCollisionDispatcher;
enum hkpBufferSize
{
    HK_SHAPE_BUFFER_SIZE = 512
};
struct __declspec(align(16)) hkpShapeBuffer
{
    unsigned int w[HK_SHAPE_BUFFER_SIZE / 4];
};
class hkAabb;
typedef hkUint32_X hkpShapeKey;
class hkpShape : public hkReferencedObject_X
{
  public:
    static const struct ClassMemberDescriptor Members[];
    __forceinline CollisionShapeType getType() const;

  protected:
    virtual void CalculateAabb(const hkTransform_X& localToWorld, hkReal_X tolerance, hkAabb& out) const = 0;

  public:
    static void __cdecl resetShapeFunctions();

  public:
  public:
    hkUlong_X m_ulUserData;

  public:
    hkEnum<CollisionShapeType, hkUint32_X> m_type;

  public:
    hkpShape(class FinishingFlag flag) : hkReferencedObject_X(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = HK_SHAPE_INVALID;
        }
    }
};
__declspec(align(16)) class AlignedHkpShape : public hkpShape
{
    AlignedHkpShape();
};
CollisionShapeType hkpShape::getType() const
{
    return static_cast<const AlignedHkpShape*>(this)->m_type;
}
class hkpCdBody
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline const hkpShape* getShape() const;

  public:
    explicit __forceinline hkpCdBody(const hkpCdBody* parent);
    __forceinline void SetCollisionShapeAndKey(const hkpShape* shape, hkpShapeKey key);

  public:
    const hkpShape* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
};
const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
hkpCdBody::hkpCdBody(const hkpCdBody* parent)
{
    m_parent = parent;
    m_pMotionState = parent->m_pMotionState;
}
void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, hkpShapeKey key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}
class hkpContactMgr;
class hkpCollisionAgent;
class hkpCollisionFilter;
struct CollisionAgentContext
{
  public:
    hkReal_X getTolerance() const
    {
        return m_fScalar;
    }

  public:
    ValueWrapper<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    ValueWrapper<hkBool32> m_collisionQuality;
    ValueWrapper<hkReal_X> m_fScalar;
    ValueWrapper<const hkpCollisionFilter*> m_iFilter;
};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
class hkpCollisionDispatcher : public hkReferencedObject_X
{
  public:
    enum
    {
        HK_MAX_RESPONSE_TYPE = 8,
        HK_MAX_SHAPE_TYPE = 32,
        HK_MAX_AGENT2_TYPES = 64,
        HK_MAX_AGENT3_TYPES = 16,
        HK_MAX_COLLISION_QUALITIES = 8
    };

  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject_X* b = static_cast<hkReferencedObject_X*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16_X>(nbytes);
        ;
        return b;
    }
    typedef hkpCollisionAgent*(__cdecl* CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB,
                                                    const CollisionAgentContext& env, hkpContactMgr* mgr);
    typedef void(__cdecl* GetPenetrationsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                               const CollisionAgentContext& input, hkpCdBodyPairCollector& collector);
    typedef void(__cdecl* GetClosestPointsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                                const CollisionAgentContext& input, hkpCdPointCollector& output);
    typedef void(__cdecl* LinearCastFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                          const ShapeSweepParameters& input, hkpCdPointCollector& castCollector,
                                          hkpCdPointCollector* startCollector);
    struct CollisionAgentFunctionTable
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(CollisionAgentFunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        CreateFunc m_pCreateFunc;
        GetPenetrationsFunc m_pQueryPenetrationsFunc;
        GetClosestPointsFunc m_pGetPenetrationsFunc;
        LinearCastFunc m_pLinearCastFunc;
        hkBool_X m_bIsFlipped;
        hkBool_X m_bIsPredictive;
        CollisionAgentFunctionTable() : m_bIsFlipped(false), m_bIsPredictive(false)
        {}
    };

  public:
    hkpCollisionDispatcher(CreateFunc defaultCreationFunction, hkpContactMgrFactory* defaultContactMgrFactory);
    __forceinline LinearCastFunc getLinearCastFunc(CollisionShapeType typeA, CollisionShapeType typeB) const;

  public:
    struct IntegerPair
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(IntegerPair));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        CollisionShapeType m_iSecond;
        CollisionShapeType m_iFirst;
    };
    struct AgentTypePairPriority
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(AgentTypePairPriority));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        char m_iAgentTypeA;
        char m_iAgentTypeB;
        char m_priority;
    };
    typedef AgentTypePairPriority DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];

  protected:
    void internalRegisterCollisionAgent(hkUchar agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE], int agentType,
                                        CollisionShapeType typeA, CollisionShapeType typeB, CollisionShapeType origA,
                                        CollisionShapeType origB, DebugTable* debugTable, int recursionDepth);

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
    hkpContactMgrFactory* m_apContactMgrFactoriesByResponsePair[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
    __declspec(align(16)) hkUint32_X m_auiAlternateTypeFlags[HK_MAX_SHAPE_TYPE];
    int m_iEntryCount;
    __declspec(align(16)) hkUchar m_agent2TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    hkUchar m_agent3TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    CollisionAgentFunctionTable m_agent2Funcs[HK_MAX_AGENT2_TYPES];

  public:
    hkReal_X m_fExpectedMaxLinearVelocity;
};
hkpCollisionDispatcher::LinearCastFunc hkpCollisionDispatcher::getLinearCastFunc(CollisionShapeType typeA,
                                                                                 CollisionShapeType typeB) const
{
    ;
    ;
    int idx = m_agent2TypeMap[typeA][typeB];
    return m_agent2Funcs[idx].m_pLinearCastFunc;
}
class hkpCdPointCollector
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    inline virtual ~hkpCdPointCollector();
    inline hkReal_X getEarlyOutDistance() const;

  protected:
    hkReal_X m_fEarlyOutDistance;
};
hkReal_X hkpCdPointCollector::getEarlyOutDistance() const
{
    return m_fEarlyOutDistance;
}
struct ShapeSweepParameters : public CollisionAgentContext
{
};
class hkpMoppCode : public hkReferencedObject_X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject_X* b = static_cast<hkReferencedObject_X*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16_X>(nbytes);
        ;
        return b;
    }
    enum BuildType
    {
        BUILT_WITH_CHUNK_SUBDIVISION,
        BUILT_WITHOUT_CHUNK_SUBDIVISION,
        BUILD_NOT_SET
    };
    struct CodeInfo
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(hkpMoppCode::CodeInfo));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        static const struct ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        inline hkReal_X getScale() const;
        inline void setScale(hkReal_X inVal);
        hkVector4_X m_offset;
    };

  public:
    hkpMoppCode()
    {
        m_info.m_offset.setZero4();
        m_eBuildType = BUILD_NOT_SET;
    }

  public:
    struct CodeInfo m_info;
    hkArray_X<hkUint8_X> m_data;
    hkEnum<BuildType, hkInt8_X> m_eBuildType;
};
class hkpShapeContainer
{
  public:
    static const struct ClassMemberDescriptor Members[];
    virtual ~hkpShapeContainer()
    {}
    virtual int GetNumChildShapes() const;
    virtual hkpShapeKey GetFirstKey() const = 0;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const = 0;
    virtual hkUint32_X GetFilterInfoForKey(hkpShapeKey key) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const = 0;
};
class hkpSingleShapeContainer : public hkpShapeContainer
{
  public:
    static const struct ClassMemberDescriptor Members[];
    virtual hkpShapeKey GetFirstKey() const
    {
        return 0;
    }
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const
    {
        return 0xffffffff;
    }
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;
    inline const hkpShape* getChild() const
    {
        return m_pContainedShape;
    }

  protected:
    const hkpShape* m_pContainedShape;
};
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    hkBool_X m_bDisableWelding;
};
class hkpBvTreeShape : public hkpShape
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
    hkEnum<BvTreeType, hkUint8_X> m_uiUserData;
};
class hkMoppBvTreeShapeBase : public hkpBvTreeShape
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    const class hkpMoppCode* m_pMoppCode;
    hkVector4_X m_kMoppCodeInfo;
};
class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
  public:
    static const struct ClassMemberDescriptor Members[];
    inline const hkpShapeCollection* getShapeCollection() const;

  protected:
    class hkpSingleShapeContainer m_pChildAtom;

  public:
    mutable int m_iChildSize;
};
inline const hkpShapeCollection* hkpMoppBvTreeShape::getShapeCollection() const
{
    return static_cast<const hkpShapeCollection*>(m_pChildAtom.getChild());
}
class hkpCollidableCollidableFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];
    virtual ~hkpCollidableCollidableFilter()
    {}
};
class hkpRayCollidableFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];
};
class hkpShapeCollectionFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];
    virtual hkBool_X IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& bodyA,
                                        const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB,
                                        hkpShapeKey keyB) const = 0;
    virtual hkBool_X IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& collectionBodyA,
                                        const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA,
                                        const hkpShapeContainer& containerShapeB, hkpShapeKey keyA,
                                        hkpShapeKey keyB) const = 0;
};
class hkpRayShapeCollectionFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];
};
class hkpCollisionFilter : public hkReferencedObject_X,
                           public hkpCollidableCollidableFilter,
                           public hkpShapeCollectionFilter,
                           public hkpRayShapeCollectionFilter,
                           public hkpRayCollidableFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    hkpCollisionFilter();
    virtual hkBool_X IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& a, const hkpCdBody& b,
                                        const hkpShapeContainer& bContainer, hkpShapeKey bKey) const = 0;

  public:
    hkUint32_X m_prepad0;
    hkUint32_X m_prepad1;

  public:
    hkpCollisionFilter(FinishingFlag flag) : hkReferencedObject_X(flag)
    {}
};
enum hkpMoppCommands
{
    HK_MOPP_RETURN = 0,
    HK_MOPP_SCALE1 = 1,
    HK_MOPP_SCALE2,
    HK_MOPP_SCALE3,
    HK_MOPP_SCALE4,
    HK_MOPP_JUMP8 = 5,
    HK_MOPP_JUMP16,
    HK_MOPP_JUMP24,
    HK_MOPP_JUMP_CHUNK = 0xc,
    HK_MOPP_JUMP_CHUNK32 = 0x70
};
class MoppPrimitiveQueryContext
{
  public:
    static int __cdecl read24(const unsigned char* pc)
    {
        return (pc[0] << 16) + (pc[1] << 8) + pc[2];
    }
    void* m_pPrimitiveInfoArray;
    int unk04;
    int unk08;
    int unk0C;
};
struct VectorPropertyRecord
{
    hkVector4_X m_kVectorBeforeIndex;
    hkVector4_X SetCenterPosition;
    float m_fValueAtOffset20;
    int m_iIndex;
    float m_kVectorAfterIndex;
    hkUint32_X m_uiPropertyCount;
    hkUint32_X m_kProperties[1];
    __declspec(noinline) VectorPropertyRecord& operator=(
        const VectorPropertyRecord& o)
    {
        m_kVectorBeforeIndex = o.m_kVectorBeforeIndex;
        SetCenterPosition = o.SetCenterPosition;
        m_fValueAtOffset20 = o.m_fValueAtOffset20;
        m_iIndex = o.m_iIndex;
        m_kVectorAfterIndex = o.m_kVectorAfterIndex;
        m_uiPropertyCount = o.m_uiPropertyCount;
        m_kProperties[0] = o.m_kProperties[0];
        return *this;
    }
};
struct TwoPointVectorBundles
{
    hkVector4_X m_kPointBundles[2];
};
class MoppCastMachine : public MoppPrimitiveQueryContext
{
  public:
    struct MoppCastQueryData
    {
        hkVector4_X m_vFrom;
        hkVector4_X m_vTo;
        hkVector4_X SetCenterPosition;
        const ShapeSweepParameters* m_pCollisionInput;
        const hkpCdBody* m_pFirstCastBody;
        const hkpCdBody* m_pSecondCastBody;
    };
    const hkpMoppCode* m_pMoppCode;
    float m_vRayDirectionVector;
    CollisionShapeType m_iRayDirectionIndex;
    float m_fFirstRayCastValue;
    float m_fSecondRayCastValue;
    hkpCdPointCollector* m_pPointCollector;
    hkpCdPointCollector* m_pClosestPointCollector;
    const MoppCastQueryData* m_pRayCastInput;
    int m_iCurrentChunkId;

  protected:
    void AddHit(hkUint32_X id, const hkUint32_X properties[1], unsigned long extra);
    void FUN_00da71c0(const VectorPropertyRecord* query, const unsigned char* PC,
                      TwoPointVectorBundles fQuery[1], int chunkOffset);
};
__forceinline void MoppCastMachine::AddHit(hkUint32_X key, const hkUint32_X properties[1],
                                           unsigned long chunkOffset_unused)
{
    const hkpShapeContainer* shapeContainer = 0;
    const hkpMoppBvTreeShape* moppBvTree =
        static_cast<const hkpMoppBvTreeShape*>(m_pRayCastInput->m_pSecondCastBody->getShape());
    shapeContainer = moppBvTree->getShapeCollection();
    hkpShapeBuffer shapeBuffer;
    const hkpShape* childShape = shapeContainer->GetShapeForKey(key, shapeBuffer);
    if (!m_pRayCastInput->m_pCollisionInput->m_iFilter->IsCollisionEnabled(
            *m_pRayCastInput->m_pCollisionInput, *m_pRayCastInput->m_pFirstCastBody,
            *m_pRayCastInput->m_pSecondCastBody, *shapeContainer, key))
    {
        return;
    }
    hkpCdBody childBodyB(m_pRayCastInput->m_pSecondCastBody);
    childBodyB.SetCollisionShapeAndKey(childShape, key);
    CollisionShapeType typeB = childShape->getType();
    hkpCollisionDispatcher::LinearCastFunc linCastFunc =
        m_pRayCastInput->m_pCollisionInput->m_pCollisionDispatcher->getLinearCastFunc(m_iRayDirectionIndex, typeB);
    linCastFunc(*m_pRayCastInput->m_pFirstCastBody, childBodyB, *m_pRayCastInput->m_pCollisionInput, *m_pPointCollector,
                m_pClosestPointCollector);
    m_fFirstRayCastValue = m_pPointCollector->getEarlyOutDistance();
}
// @fnv 0x00da71c0
void MoppCastMachine::FUN_00da71c0(const VectorPropertyRecord* query, const unsigned char* PC,
                                   TwoPointVectorBundles fQuery[1], int chunkOffset)
{
    VectorPropertyRecord scaledQuery;
    do
    {
        const hkpMoppCommands command = hkpMoppCommands(PC[0]);
        int tdir = 999;
        int offsetLB;
        int offsetRB;
        hkReal_X positionl;
        hkReal_X positionh;
        hkReal_X foffsetl;
        hkReal_X foffseth;
        int offsetl;
        int offseth;
        switch (command)
        {
        case 0x13: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x14: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2));
            positionh = (fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2));
            goto do_compareN4;
        }
        case 0x15: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](2));
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x16: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x17: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x18: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x19: {
            foffseth = hkReal_X(PC[1] * 3);
            foffsetl = hkReal_X(PC[2] * 3);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1a: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1b: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1c: {
            foffseth = hkReal_X(PC[1] * 3 - 510);
            foffsetl = hkReal_X(PC[2] * 3 - 510);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x20:
        case 0x21:
        case 0x22:
            tdir = command - 0x20;
            foffsetl = hkReal_X(PC[1]);
            foffseth = foffsetl + 1.0;
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            PC += 3;
            offsetLB = 0;
            offsetRB = PC[-1];
            goto do_compare;
        case 0x23:
        case 0x24:
        case 0x25:
            tdir = command - 0x23;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            offsetLB = (PC[3] << 8) + PC[4];
            PC += 7;
            offsetRB = (PC[-2] << 8) + PC[-1];
            goto do_compare;
        case 0x10:
        case 0x11:
        case 0x12:
            tdir = command - 0x10;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
        do_compareN4:
            PC += 4;
            offsetLB = 0;
            offsetRB = PC[-1];
        do_compare:
            if (positionh < foffsetl && positionl < foffsetl)
            {
                PC += offsetLB;
                continue;
            }
            PC += offsetRB;
            if (positionl > foffseth && positionh > foffseth)
            {
                continue;
            }
            {
                const hkReal_X la = positionl - foffseth;
                const hkReal_X ha = positionl - foffsetl;
                const hkReal_X lb = positionh - foffseth;
                const hkReal_X hb = positionh - foffsetl;
                TwoPointVectorBundles leftFloat;
                leftFloat.m_kPointBundles[0] = fQuery->m_kPointBundles[0];
                leftFloat.m_kPointBundles[1] = fQuery->m_kPointBundles[1];
                if (la < lb)
                {
                    if (la * lb < 0.0)
                    {
                        const hkReal_X ratio = la / (la - lb);
                        leftFloat.m_kPointBundles[1].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], ratio);
                    }
                    FUN_00da71c0(query, PC - offsetRB + offsetLB, &leftFloat, chunkOffset);
                    if (ha * hb < 0.0)
                    {
                        const hkReal_X ratio = ha / (ha - hb);
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], ratio);
                    }
                    if (m_fFirstRayCastValue < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = m_fFirstRayCastValue;
                        const hkReal_X fraction = m_fFirstRayCastValue;
                        hkVector4_X hitpoint;
                        hitpoint.setInterpolate4(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, fraction);
                        fQuery->m_kPointBundles[1].setSub4(hitpoint, m_pMoppCode->m_info.m_offset);
                        fQuery->m_kPointBundles[1].mul4(query->m_kVectorAfterIndex);
                        fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] < foffsetl)
                        {
                            goto end_of_function;
                        }
                    }
                    continue;
                }
                else
                {
                    if (ha * hb < 0.0)
                    {
                        const hkReal_X ratio = ha / (ha - hb);
                        leftFloat.m_kPointBundles[1].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], ratio);
                    }
                    FUN_00da71c0(query, PC, &leftFloat, chunkOffset);
                    if (la * lb < 0.0)
                    {
                        const hkReal_X ratio = la / (la - lb);
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], ratio);
                    }
                    if (m_fFirstRayCastValue < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = m_fFirstRayCastValue;
                        const hkReal_X fraction = m_fFirstRayCastValue;
                        hkVector4_X hitpoint;
                        hitpoint.setInterpolate4(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, fraction);
                        fQuery->m_kPointBundles[1].setSub4(hitpoint, m_pMoppCode->m_info.m_offset);
                        fQuery->m_kPointBundles[1].mul4(query->m_kVectorAfterIndex);
                        fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] > foffseth)
                        {
                            goto end_of_function;
                        }
                    }
                    PC = PC - offsetRB + offsetLB;
                    continue;
                }
            }
        case 0x29:
        case 0x2a:
        case 0x2b:
            tdir = command - 0x29;
            {
                foffsetl = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 1)) * m_vRayDirectionVector;
                foffseth = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 4)) * m_vRayDirectionVector;
                foffsetl *= query->m_kVectorAfterIndex;
                foffseth *= query->m_kVectorAfterIndex;
                foffsetl -= query->m_kVectorBeforeIndex(tdir);
                foffseth -= query->m_kVectorBeforeIndex(tdir);
                foffsetl -= query->SetCenterPosition(tdir);
                foffseth += query->SetCenterPosition(tdir);
                PC += 7;
            }
            goto doCut;
        case 0x26:
        case 0x27:
        case 0x28:
            tdir = command - 0x26;
            foffsetl = hkReal_X(PC[1]);
            foffseth = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            PC += 3;
        doCut:
            positionl = fQuery->m_kPointBundles[0](tdir);
            positionh = fQuery->m_kPointBundles[1](tdir);
            {
                int sign;
                if (positionl < positionh)
                {
                    if (positionh < foffsetl || positionl > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 0;
                }
                else
                {
                    if (positionl < foffsetl || positionh > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 1;
                }
                const hkVector4_X rayStartPoint = fQuery->m_kPointBundles[0];
                const hkVector4_X rayEndPoint = fQuery->m_kPointBundles[1];
                {
                    const hkReal_X R0 = positionl - foffseth;
                    const hkReal_X R1 = positionh - foffseth;
                    if (R0 * R1 < 0.0)
                    {
                        const hkReal_X ratio = R0 / (R0 - R1);
                        fQuery->m_kPointBundles[1 - sign].setInterpolate4(rayStartPoint, rayEndPoint, ratio);
                    }
                }
                {
                    const hkReal_X L0 = positionl - foffsetl;
                    const hkReal_X L1 = positionh - foffsetl;
                    if (L0 * L1 < 0.0)
                    {
                        const hkReal_X ratio = L0 / (L0 - L1);
                        fQuery->m_kPointBundles[sign].setInterpolate4(rayStartPoint, rayEndPoint, ratio);
                    }
                }
            }
            continue;
        case 5:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            continue;
        case 6:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            continue;
        case 7: {
            offseth = PC[1];
            const hkUint32_X offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
        }
            continue;
        case 0xc: {
            const int chunkId = (PC[1] << 8) | PC[2];
            chunkOffset = chunkId << 9;
            goto jumpRecheckCache;
        }
        case 0x70:
            chunkOffset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
        jumpRecheckCache: {
            const unsigned char* jumpAddress = m_pMoppCode->m_data.begin() + chunkOffset;
            PC = jumpAddress;
        }
            continue;
        case 0xd:
            PC += 5;
            continue;
        case 1:
        case 2:
        case 3:
        case 4: {
            const hkUint32_X shift = command;
            hkVector4_X extraOffset;
            extraOffset.set(hkReal_X(PC[1]), hkReal_X(PC[2]), hkReal_X(PC[3]), 0.0f);
            hkVector4_X f4;
            const hkReal_X f = hkReal_X(1 << shift);
            f4.setAll3(f);
            fQuery->m_kPointBundles[0].sub4(extraOffset);
            fQuery->m_kPointBundles[1].sub4(extraOffset);
            fQuery->m_kPointBundles[0].mul4(f4);
            fQuery->m_kPointBundles[1].mul4(f4);
            scaledQuery.m_kVectorBeforeIndex.setAdd4(query->m_kVectorBeforeIndex, extraOffset);
            scaledQuery.m_kVectorBeforeIndex.mul4(f4);
            scaledQuery.m_iIndex = query->m_iIndex + shift;
            scaledQuery.m_kVectorAfterIndex = query->m_kVectorAfterIndex * f;
            scaledQuery.SetCenterPosition.setMul4(f4, query->SetCenterPosition);
            scaledQuery.m_fValueAtOffset20 = query->m_fValueAtOffset20 * f;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_kProperties[p] = query->m_kProperties[p];
            }
            scaledQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &scaledQuery;
            PC += 4;
        }
            continue;
        case 0:
            goto end_of_function;
        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;
        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;
        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;
        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_uiPropertyCount;
            {
                hkUint32_X chunkId = chunkOffset >> 9;
                hkUint32_X keyRemap = ((chunkId << 8) & m_iCurrentChunkId) | offsetl;
                AddHit(keyRemap, query->m_kProperties, 0);
            }
            goto end_of_function;
        case 9: {
            const hkUint32_X offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 2;
        }
            continue;
        case 0xa: {
            const hkUint32_X offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 3;
        }
            continue;
        case 0xb: {
            const hkUint32_X offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount = offset;
            PC += 5;
        }
            continue;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            hkUint32_X property;
            hkUint32_X value;
            property = PC[0] - 0x60;
            value = PC[1];
            PC += 2;
            scaledQuery.m_kProperties[property] = value;
        propertyCopy:
            const hkUint32_X v = scaledQuery.m_kProperties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_kProperties[0] = v;
        }
            continue;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67: {
            const hkUint32_X property = PC[0] - 0x64;
            const hkUint32_X value = (PC[1] << 8) + PC[2];
            scaledQuery.m_kProperties[property] = value;
            PC += 3;
            goto propertyCopy;
        }
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b: {
            const hkUint32_X property = PC[0] - 0x68;
            const hkUint32_X value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_kProperties[property] = value;
            PC += 5;
            goto propertyCopy;
        }
        default:
            do
            {
                unsigned int assertBuf[128];
                ErrStreamLite ostr;
                ostr.FUN_00cb1600(assertBuf, 512);
                ostr.FUN_00cc01c0(
                    "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
                if (hkError::GetMonitorStream().message(hkError::MESSAGE_ERROR, 0x1298fedd, (const char*)assertBuf,
                                                        ".\\Collide\\Mopp\\Machine\\hkpMoppAabbCastVirtualMachine.cpp",
                                                        521))
                {
                    __debugbreak();
                    ostr.FUN_00cc00e0();
                }
                else
                {
                    ostr.FUN_00cc00e0();
                }
            } while (0);
            continue;
        }
    } while (1);
end_of_function:;
}
