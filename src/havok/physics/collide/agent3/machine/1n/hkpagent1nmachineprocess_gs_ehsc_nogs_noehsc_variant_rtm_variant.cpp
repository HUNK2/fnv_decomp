
// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachineprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Pair
{
    int a;
    int b;
};
struct Out
{
    int res;
    int val;
};
struct Updater
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int update(int x, int y);
};
static void FUN_00da4a50(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1);
void S00da4a50_Wrap(Updater* self, int flag, Pair* dest, Pair* src, Updater* other, int y, Out* out2, Out* out1);
#include <xmmintrin.h>
struct S00da4920_Sub
{
    void FUN_00cb21e0(void* arg);
};
struct S00da4920_Blob
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    __m128 m_v70;
};
extern char DAT_010c4c00;
static void FUN_00da4920(S00da4920_Blob* src, S00da4920_Blob* dst);
void S00da4920_entry(S00da4920_Blob* src, S00da4920_Blob* dst);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
typedef unsigned __w64 Y2;
typedef hkReal hkTime;
__forceinline hkLong __cdecl hkGetByteOffset(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
template <typename TYPE> __forceinline TYPE* __cdecl hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}
class FinishingFlag
{
  public:
    FinishingFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
  public:
    typedef char CompileTimeTrueType;
    inline hkBool(bool b)
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
extern "C"
{
    extern const hkReal g_afRealLookupTable[256];
}
class QuantizedFloat8
{
  public:
    enum
    {
        MAX_VALUE = 256
    };
    inline QuantizedFloat8()
    {}
    QuantizedFloat8& operator=(const float& fv);
    inline QuantizedFloat8(const float f)
    {
        *this = f;
    }
    inline operator float() const
    {
        return g_afRealLookupTable[m_uiFilterValue];
    }

  public:
    hkUint8 m_uiFilterValue;
};
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }
    void operator=(ENUM e)
    {
        m_kStorage = static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};
template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}
    __forceinline ValueWrapper(TYPE e) : m_kStorage(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        m_kStorage = e;
    }
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
extern "C"
{
    __declspec(dllimport) void* _stdcall TlsGetValue(unsigned long dwTlsIndex);
}
template <typename T> class hkThreadLocalData
{
  public:
    hkThreadLocalData()
    {
        m_slotID = TlsAlloc();
    }
    __forceinline T getData() const
    {
        return (T)(hkUlong)TlsGetValue(m_slotID);
    }
    unsigned long m_slotID;
};
class hkMemoryAllocator
{
  public:
    __forceinline void* __cdecl operator new(Y2, void* p)
    {
        return p;
    }
    virtual ~hkMemoryAllocator();
    virtual void* Y4(int numBytes) = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;

  public:
    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };
};
namespace MemoryUtilities {
void __cdecl CopyByteRange(void* dst, const void* src, int Y6);
}
struct StringPointerTriple
{
  public:
    __forceinline StringPointerTriple();

  protected:
    ValueWrapper<void*> m_next;
    ValueWrapper<void*> m_kRayStart;
    ValueWrapper<void*> m_kRayEnd;
};
class Y1
{
  public:
    __forceinline void* __cdecl operator new(Y2, void* p)
    {
        return p;
    }
    typedef hkMemoryAllocator Allocator;
    static Y1& __cdecl GetMonitorStream();
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    StringPointerTriple m_aiEntries;
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
};
class hkBaseObject
{
  public:
    static const struct Y7 Members[];
    __forceinline virtual ~hkBaseObject()
    {}

  public:
    __forceinline hkBaseObject()
    {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        hkReferencedObject* b =
            static_cast<hkReferencedObject*>(Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(Y6);
        ;
        return b;
    }
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    hkUint16 m_usMemSizeAndFlags;

  public:
    hkReferencedObject(class FinishingFlag flag)
    {}
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
class HavokArrayUtilities
{
  public:
    template <typename T> static __forceinline void construct(T* t, int n, hkTypeIsPod);
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& a, void*, int reqElem, int sizeElem);
};
struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get(const void*)
    {
        return Y1::GetMonitorStream().heap();
    }
};
template <typename T> class HavokElementArray
{
  public:
    typedef HavokElementArray<T> ThisType;

  protected:
    __forceinline HavokElementArray(const HavokElementArray& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);
    __forceinline T& operator[](int i);
    __forceinline int GetLogicalSize() const;
    __forceinline int getCapacity() const;
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n);
    __forceinline void _setSize(hkMemoryAllocator& alloc, int size);
    __forceinline T* _expandAt(hkMemoryAllocator& alloc, int index, int numToInsert);
    typedef T* iterator;
    __forceinline iterator begin();

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
    int m_iElementCount;
    int m_iCapacityState;

  public:
    HavokElementArray(FinishingFlag f)
    {}
};
template <typename T, typename Allocator = RouterHeapAllocatorProvider> class hkArray : public HavokElementArray<T>
{
  public:
    typedef Allocator AllocatorType;

  protected:
    __forceinline hkArray(const hkArray& a);

  public:
    __forceinline hkArray& operator=(const HavokElementArray<T>& a);
    __forceinline void SetSizeAndGrow(int size)
    {
        HavokElementArray<T>::_setSize(AllocatorType().get(this), size);
    }
    __forceinline T* expandAt(int i, int n)
    {
        return HavokElementArray<T>::_expandAt(AllocatorType().get(this), i, n);
    }
};
template <typename T> __forceinline T& HavokElementArray<T>::operator[](int i)
{
    ;
    return m_data[i];
}
template <typename T> __forceinline int HavokElementArray<T>::GetLogicalSize() const
{
    return m_iElementCount;
}
template <typename T> __forceinline int HavokElementArray<T>::getCapacity() const
{
    return (m_iCapacityState & static_cast<int>(CAPACITY_MASK));
}
template <typename T> __forceinline void HavokElementArray<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        HavokArrayUtilities::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
    }
}
template <typename T> __forceinline void HavokElementArray<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline T* HavokElementArray<T>::_expandAt(hkMemoryAllocator& alloc, int index, int numtoinsert)
{
    const int newsize = numtoinsert + m_iElementCount;
    const int numtomove = m_iElementCount - index;
    if (newsize > getCapacity())
    {
        GrowArrayCapacity(alloc, newsize);
    }
    MemoryUtilities::CopyByteRange(m_data + index + numtoinsert, m_data + index, numtomove * sizeof(T));
    m_iElementCount = newsize;
    return m_data + index;
}
template <typename T> typename HavokElementArray<T>::iterator HavokElementArray<T>::begin()
{
    return m_data;
}
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4& hkVector4Parameter;
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;
namespace MathUtilities {
inline void prefetch128(const void* p)
{
    _mm_prefetch((const char*)p, 0);
}
template <int SIZE> inline void forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}
}
class hkVector4
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    __forceinline void operator=(const hkVector4& v);
    __forceinline void setZero4();
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b);
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y);
    __forceinline void setNeg3(const hkVector4& v);
    __forceinline VectorComponentValue dot3(const hkVector4& a) const;
    __forceinline VectorComponentValue dot4xyz1(const hkVector4& a) const;
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline void setBroadcast(hkVector4Parameter v, int i);

  private:
    hkQuadReal m_vComponents;

  public:
    operator hkQuadReal() const
    {
        return m_vComponents;
    }
};
class hkQuaternion
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    hkVector4 m_vec;

  protected:
    void setFlippedRotation(const hkVector4& from);
};
class hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    __forceinline hkMatrix3()
    {}
    __forceinline const hkVector4& getColumn(int i) const;
    inline void operator=(const hkMatrix3& a);

  protected:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
};
class hkTransform
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    __forceinline hkTransform()
    {}
    void SetConjugate(const hkTransform& t);
    void SetMulInverse(const hkTransform& bTa, const hkTransform& bTc);

  private:
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};
class hkSweptTransform
{
  public:
    static const struct Y7 Members[];

  public:
    __forceinline void _approxTransformAt(hkTime time, hkTransform& transformOut) const;
    __forceinline hkReal getInvDeltaTime() const;

  public:
    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    hkQuaternion m_qRotation0;
    hkQuaternion m_qRotation1;
    hkVector4 m_vCenterOfMassLocal;
};
inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4::setNeg3(const hkVector4& v)
{
    static __declspec(align(16)) const hkUint32 negateMask[4] = {0x80000000, 0x80000000, 0x80000000, 0x00000000};
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&negateMask);
}
inline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}
inline VectorComponentValue hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline VectorComponentValue hkVector4::dot4xyz1(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    hkQuadReal zwSum =
        _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))),
                   _mm_shuffle_ps(m_vComponents, m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3)))));
    return _mm_add_ps(xySum, zwSum);
}
inline hkReal& hkVector4::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    }
    else if (i == 3)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
inline void hkMatrix3::operator=(const hkMatrix3& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}
class MemoryUtils
{
  public:
    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);

  private:
    static void copyAndReplace(char* dest, const char* orig, int origLen, const MemoryUtils& from,
                               const MemoryUtils& to, const hkArray<int>& indices);
};
void __cdecl MemoryUtils::memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    {
        do
        {
            dst32[0] = src32[0];
            dst32[1] = src32[1];
            dst32[2] = src32[2];
            dst32[3] = src32[3];
            dst32 += 4;
            src32 += 4;
        } while (--numQuads > 0);
    }
}
class StringCursor
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    static StringCursor& GetMonitorStream()
    {
        extern hkThreadLocalData<StringCursor*> g_pMonitorStream;
        return *g_pMonitorStream.getData();
    }

  public:
    __forceinline char* __cdecl GetStreamStart()
    {
        return m_kRayStart.val();
    }
    __forceinline char* __cdecl GetStreamEnd()
    {
        return m_kRayEnd.val();
    }
    __forceinline char* __cdecl getCapacityMinus16()
    {
        return m_pCurrentCommand.val();
    }
    __forceinline hkBool __cdecl memoryAvailable()
    {
        return GetStreamEnd() < getCapacityMinus16();
    }
    __forceinline void __cdecl setEnd(char* ptr)
    {
        m_kRayEnd = ptr;
    }

  public:
    static void __cdecl init();

  public:
    ValueWrapper<char*> m_kRayStart;
    ValueWrapper<char*> m_kRayEnd;
    ValueWrapper<char*> m_pRayCursor;
    ValueWrapper<char*> m_pCurrentCommand;
    hkBool m_bFlag;

  public:
    struct Command
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(StringCursor::Command));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        const char* m_pCommandName;
    };
    struct CommandFilterEntry : public StringCursor::Command
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(StringCursor::CommandFilterEntry));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        float m_uiFilterValue;
    };
};
class hkMotionState
{
  public:
    static const struct Y7 Members[];
    inline hkMotionState();
    inline const hkSweptTransform& getSweptTransform() const;

  protected:
    hkTransform m_kMotionTransform;
    class hkSweptTransform m_kSweptTransform;

  public:
    hkVector4 m_kDeltaAngle;
    hkReal m_fObjectRadius;
};
hkMotionState::hkMotionState()
{}
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}
class hkAabb
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    hkVector4 m_kMinimumCorner;
};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
  public:
    static const struct Y7 Members[];
    inline hkVector4& getSeparatingNormal();
    inline void setFlipped(const hkContactPoint& point);
    inline void flip();

  protected:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};
inline hkVector4& hkContactPoint::getSeparatingNormal()
{
    return m_vSeparatingNormal;
}
inline void hkContactPoint::setFlipped(const hkContactPoint& point)
{
    hkVector4 dist;
    dist.setBroadcast(point.m_vSeparatingNormal, 3);
    m_vContactPosition.setAddMul4(point.m_vContactPosition, point.m_vSeparatingNormal, dist);
    m_vSeparatingNormal.setNeg3(point.m_vSeparatingNormal);
}
inline void hkContactPoint::flip()
{
    setFlipped(*this);
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
typedef __declspec(align(16)) char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class ShapeKeyCombination
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    hkpShapeKey m_uiShapeKeyA;
    hkpShapeKey m_uiShapeKeyB;
};
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
  public:
    static const struct Y7 Members[];
    __forceinline CollisionShapeType getType() const;

  protected:
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const = 0;

  public:
    static void __cdecl resetShapeFunctions();

  public:
  public:
    hkUlong m_ulUserData;

  public:
    hkEnum<CollisionShapeType, hkUint32> m_type;

  public:
    hkpShape(class FinishingFlag flag) : hkReferencedObject(flag)
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
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    __forceinline hkpCdBody()
    {}
    __forceinline const hkTransform& getTransform() const;
    __forceinline const hkpShape* getShape() const;

  public:
    explicit __forceinline hkpCdBody(const hkpCdBody* parent);
    __forceinline void SetCollisionShapeAndKey(const hkpShape* shape, hkpShapeKey key);
    __forceinline const hkMotionState* GetMotionState() const;

  public:
    const hkpShape* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
};
const hkTransform& hkpCdBody::getTransform() const
{
    ;
    return *static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState* hkpCdBody::GetMotionState() const
{
    return static_cast<const hkMotionState*>(m_pMotionState);
}
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
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct Y5;
class hkpCollisionAgent;
struct FourByteState
{
    hkUchar m_ucAgentType;
    hkUchar m_ucNnTrackType;
    hkUchar m_usNumContactPoints;
    hkUchar m_iElementCount;
};
typedef void Y3;
struct AgentProcessingInput
{
    AgentProcessingInput() : m_pAdditionalCollidableBody(0)
    {}
    ValueWrapper<const hkpCdBody*> m_pBodyA;
    ValueWrapper<const hkpCdBody*> m_pBodyB;
    ValueWrapper<const hkpCdBody*> m_pAdditionalCollidableBody;
    ValueWrapper<const GskAgentInput*> m_pRayCastInput;
    ValueWrapper<hkpContactMgr*> m_pContactManager;
    hkTransform m_kTransform;
};
struct AgentSubtypeMarker : public AgentProcessingInput
{
    ValueWrapper<hkReal> m_fSubtypeValue;
    hkVector4 m_vSubtypePosition;
};
namespace hkAgent3 {
typedef int AgentType;
enum
{
    MIN_TOTAL_SIZE = 16,
    MAX_MEMORY_INCREASE = 80,
    MAX_TOTAL_SIZE = 128
};
enum StreamCommand
{
    STREAM_NULL = 0,
    STREAM_END = 1,
    STREAM_CALL = 2,
    STREAM_CALL_FLIPPED = 3,
    STREAM_CALL_WITH_TIM = 4,
    STREAM_CALL_WITH_TIM_FLIPPED = 5,
    STREAM_CALL_AGENT = 6,
    TRANSFORM_FLAG = 0x08,
    STREAM_CALL_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL,
    STREAM_CALL_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_FLIPPED,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM,
    STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM_FLIPPED,
    STREAM_CALL_AGENT_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_AGENT,
};
typedef Y3*(__cdecl* CreateFunc)(const AgentProcessingInput& input, FourByteState* entry, Y3* agentData);
typedef void(__cdecl* DestroyFunc)(FourByteState* entry, Y3* agentData, hkpContactMgr* mgr,
                                   hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher);
typedef Y3*(__cdecl* ProcessFunc)(const AgentSubtypeMarker& input, FourByteState* entry, Y3* agentData,
                                  hkVector4* separatingNormalOut, WorldOperationEntry& result);
enum Symmetric
{
    IS_SYMMETRIC,
    IS_NOT_SYMMETRIC,
    IS_NOT_SYMMETRIC_AND_FLIPPED
};
typedef void(__cdecl* SepNormalFunc)(const AgentProcessingInput& input, FourByteState* entry, Y3* agentData,
                                     hkVector4& separatingNormalOut);
typedef Y3*(__cdecl* CleanupFunc)(FourByteState* entry, Y3* agentData, hkpContactMgr* mgr,
                                  hkpConstraintOwner& constraintOwner);
typedef void(__cdecl* RemovePointFunc)(FourByteState* entry, Y3* agentData, hkContactPointId idToRemove);
typedef void(__cdecl* CommitPotentialFunc)(FourByteState* entry, Y3* agentData, hkContactPointId iContactPointId);
typedef void(__cdecl* CreateZombieFunc)(FourByteState* entry, Y3* agentData, hkContactPointId idTobecomeZombie);
typedef void(__cdecl* UpdateFilterFunc)(FourByteState* entry, Y3* agentData, const hkpCdBody& bodyA,
                                        const hkpCdBody& bodyB, const Y5& input, hkpContactMgr* mgr,
                                        hkpConstraintOwner& constraintOwner);
typedef void(__cdecl* CalcStatisticsFunc)(FourByteState* entry, Y3* agentData, const Y5& input,
                                          hkStatisticsCollector* collector);
typedef void(__cdecl* InvalidateTimFunc)(FourByteState* entry, Y3* agentData, const Y5& input);
typedef void(__cdecl* WarpTimeFunc)(FourByteState* entry, Y3* agentData, hkTime oldTime, hkTime newTime,
                                    const Y5& input);
}
struct CollisionQualityInfo
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal m_fTimeOfImpactSeparation;
    ValueWrapper<hkBool32> m_iQualityInfoValue10;
    hkBool m_bUseContinuousPhysics;
    hkReal m_fCreateContactThreshold;
};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct Y5
{
  public:
    hkReal getTolerance() const
    {
        return m_fScalar;
    }

  public:
    ValueWrapper<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    ValueWrapper<hkBool32> m_collisionQuality;
    ValueWrapper<hkReal> m_fScalar;
    ValueWrapper<const hkpCollisionFilter*> m_iFilter;
    ValueWrapper<const hkpConvexListFilter*> m_pConvexListCollisionFilter;
    mutable ValueWrapper<hkBool32> m_bCreatePredictiveAgents;
    struct AabbBoundsAndScale
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Y5::AabbBoundsAndScale));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        hkVector4 m_kAabbMin;
        hkVector4 m_kAabbMaximum;
        hkVector4 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
class hkpCollisionDispatcher : public hkReferencedObject
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
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        hkReferencedObject* b =
            static_cast<hkReferencedObject*>(Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(Y6);
        ;
        return b;
    }
    typedef hkpCollisionAgent*(__cdecl* CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB, const Y5& env,
                                                    hkpContactMgr* mgr);
    typedef void(__cdecl* GetPenetrationsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const Y5& input,
                                               hkpCdBodyPairCollector& collector);
    typedef void(__cdecl* GetClosestPointsFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const Y5& input,
                                                hkpCdPointCollector& output);
    typedef void(__cdecl* LinearCastFunc)(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                          const ShapeSweepParameters& input, hkpCdPointCollector& castCollector,
                                          hkpCdPointCollector* startCollector);
    struct CollisionAgentFunctionTable
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(CollisionAgentFunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
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
        hkBool m_bIsFlipped;
        hkBool m_bIsPredictive;
        CollisionAgentFunctionTable() : m_bIsFlipped(false), m_bIsPredictive(false)
        {}
    };
    struct Agent3FunctionTable
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Agent3FunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Agent3FunctionTable() : m_bIsPredictive(false), m_bAgentFlag1(false), m_bAgentFlag2(false)
        {
            m_pUpdateFilterFunc = 0;
            m_pCalcStats = 0;
            m_pAgentFunction10 = 0;
            m_pAgentFunction11 = 0;
            m_pAgentFunction7 = 0;
        }
        __declspec(align(16)) hkAgent3::CreateFunc m_pCreateFunc;
        hkAgent3::DestroyFunc m_pAgent3DestroyFuncs;
        hkAgent3::CleanupFunc m_pAgentFunction3;
        hkAgent3::RemovePointFunc m_pAgentFunction4;
        hkAgent3::CommitPotentialFunc m_pAgentFunction5;
        hkAgent3::CreateZombieFunc m_pCreateZombieFunc;
        hkAgent3::UpdateFilterFunc m_pUpdateFilterFunc;
        hkAgent3::CalcStatisticsFunc m_pCalcStats;
        hkAgent3::InvalidateTimFunc m_pAgentFunction10;
        hkAgent3::WarpTimeFunc m_pAgentFunction11;
        hkAgent3::SepNormalFunc m_pAgentFunction7;
        hkAgent3::ProcessFunc m_pAgentFunction8;
        hkBool m_bIsPredictive;
        hkBool m_bAgentFlag1;
        hkBool m_bAgentFlag2;
    };

  public:
    hkpCollisionDispatcher(CreateFunc defaultCreationFunction, hkpContactMgrFactory* defaultContactMgrFactory);
    __forceinline hkAgent3::AgentType getAgent3Type(CollisionShapeType typeA, CollisionShapeType typeB,
                                                    hkBool32 predicitve) const;
    __forceinline hkAgent3::CreateFunc getAgent3CreateFunc(hkAgent3::AgentType type);
    __forceinline hkAgent3::DestroyFunc getAgent3DestroyFunc(hkAgent3::AgentType type);
    __forceinline hkAgent3::CleanupFunc getAgent3CleanupFunc(hkAgent3::AgentType type);
    __forceinline hkAgent3::ProcessFunc getAgent3ProcessFunc(hkAgent3::AgentType type);
    __forceinline hkAgent3::SepNormalFunc getAgent3SepNormalFunc(hkAgent3::AgentType type);
    __forceinline hkAgent3::Symmetric getAgent3Symmetric(hkAgent3::AgentType type);

  public:
    struct IntegerPair
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(IntegerPair));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
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
    struct SymmetricAgent3FunctionTable : public Agent3FunctionTable
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(SymmetricAgent3FunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        hkAgent3::Symmetric m_eSymmetric;
    };
    struct AgentTypePairPriority
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(AgentTypePairPriority));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
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
    __declspec(align(16)) hkUint32 m_auiAlternateTypeFlags[HK_MAX_SHAPE_TYPE];
    int m_iEntryCount;
    __declspec(align(16)) hkUchar m_agent2TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    hkUchar m_agent3TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    CollisionAgentFunctionTable m_agent2Funcs[HK_MAX_AGENT2_TYPES];
    int m_iAgent2FunctionCount;
    __declspec(align(16)) hkUchar m_ucAgent2TypeTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    __declspec(align(16)) hkUchar m_ucAgent3TypeTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    SymmetricAgent3FunctionTable m_kAgent3FunctionTable[HK_MAX_AGENT3_TYPES];

  public:
    hkReal m_fExpectedMaxLinearVelocity;
};
hkAgent3::CreateFunc hkpCollisionDispatcher::getAgent3CreateFunc(hkAgent3::AgentType type)
{
    return m_kAgent3FunctionTable[type].m_pCreateFunc;
}
hkAgent3::DestroyFunc hkpCollisionDispatcher::getAgent3DestroyFunc(hkAgent3::AgentType type)
{
    return m_kAgent3FunctionTable[type].m_pAgent3DestroyFuncs;
}
hkAgent3::CleanupFunc hkpCollisionDispatcher::getAgent3CleanupFunc(hkAgent3::AgentType type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction3;
}
hkAgent3::ProcessFunc hkpCollisionDispatcher::getAgent3ProcessFunc(hkAgent3::AgentType type)
{
    ;
    return m_kAgent3FunctionTable[type].m_pAgentFunction8;
}
hkAgent3::SepNormalFunc hkpCollisionDispatcher::getAgent3SepNormalFunc(hkAgent3::AgentType type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction7;
}
hkAgent3::Symmetric hkpCollisionDispatcher::getAgent3Symmetric(hkAgent3::AgentType type)
{
    return m_kAgent3FunctionTable[type].m_eSymmetric;
}
hkAgent3::AgentType hkpCollisionDispatcher::getAgent3Type(CollisionShapeType typeA, CollisionShapeType typeB,
                                                          hkBool32 predictive) const
{
    ;
    ;
    if (predictive)
    {
        return m_ucAgent3TypeTable[typeA][typeB];
    }
    return m_ucAgent2TypeTable[typeA][typeB];
}
class ContactImpulseInfo
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    hkReal m_fAccumulatedImpulse;
};
class hkContactPointMaterial
{
  public:
    static const struct Y7 Members[];

  protected:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    QuantizedFloat8 m_fSlipAngle;
    hkUint8 m_fElasticity;

  public:
    QuantizedFloat8 m_usFlags;

  public:
    void reset()
    {
        m_fSlipAngle.m_uiFilterValue = 0;
        m_usFlags.m_uiFilterValue = 0;
        m_fElasticity = 0;
        m_flags = CONTACT_IS_NEW;
    }
    enum FlagEnum
    {
        CONTACT_IS_NEW = 1,
        CONTACT_USES_SOLVER_PATH2 = 2,
        CONTACT_BREAKOFF_OBJECT_ID = 4,
        CONTACT_IS_DISABLED = 8
    };
    hkUint8 m_flags;
};
class PhysicsMaterial : public ContactImpulseInfo, public hkContactPointMaterial
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    hkReal m_uiUserData;
};
__declspec(align(16)) class ContactDataPhysicsMaterial : public PhysicsMaterial
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
};
struct ContactPointWithId
{
    hkContactPoint m_kPoint;
    ValueWrapper<hkUint32> m_usContactPointId;
};
class hkpCollisionAgent : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        hkReferencedObject* b =
            static_cast<hkReferencedObject*>(Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(Y6);
        ;
        return b;
    }
    virtual void getPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const Y5& input,
                                 hkpCdBodyPairCollector& collector) = 0;
    virtual void getClosestPoints(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const Y5& input,
                                  hkpCdPointCollector& collector) = 0;
    virtual void linearCast(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                            hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector) = 0;

  public:
    virtual void ProcessAgent(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input,
                                  WorldOperationEntry& result) = 0;

  protected:
    inline virtual ~hkpCollisionAgent();

  protected:
    hkpContactMgr* m_pContactManager;

  public:
    inline hkpContactMgr* getContactMgr();
};
class hkStepInfo
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    __declspec(align(16)) ValueWrapper<hkTime> m_uiStartTime;
    ValueWrapper<hkTime> m_fEndTime;
};
struct hkpAgent1nSector;
struct GskAgentInput : public Y5
{
  public:
    GskAgentInput() : m_pAgent1nSector(0)
    {}

  public:
    hkStepInfo m_pStepInfo;
    mutable ValueWrapper<CollisionQualityInfo*> m_pCollisionQualityInfo;
    mutable hkpAgent1nSector* m_pAgent1nSector;
};
class ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    void init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa);
    inline void flip();
};
__declspec(align(16)) class HeapContactFeatureCache : public ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
};
enum
{
    HK_MAX_CONTACT_POINT = 256
};
struct CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    ValueWrapper<ContactPointWithId*> m_pAlignedPairData;
    ValueWrapper<hkpConstraintOwner*> m_pConstraintOwner;
    ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
    struct CollisionCacheState
    {
      public:
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(CollisionContactResults::CollisionCacheState));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        inline CollisionCacheState();
        inline void flip();

      public:
        hkContactPoint m_vContactPoint;
        ValueWrapper<hkReal> m_uiCommandId;
        ValueWrapper<hkReal> m_fSeparation;
        HeapContactFeatureCache m_kGskCache;
        ContactDataPhysicsMaterial m_kProperties;
    };
    struct CollisionCacheState m_fTimeOfImpact;
};
void CollisionContactResults::CollisionCacheState::flip()
{
    hkVector4& norm = m_vContactPoint.getSeparatingNormal();
    norm.setNeg3(norm);
    m_kGskCache.flip();
}
struct WorldOperationEntry : public CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }

  public:
    struct ContactPointAgentEntry
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(WorldOperationEntry::ContactPointAgentEntry));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        ContactPointWithId* m_vContactPoint;
        FourByteState* m_pAgentEntry;
        void* m_pUserData;
    };
    struct ContactPointBuffer
    {
        __forceinline void* __cdecl operator new(Y2 Y6)
        {
            ;
            void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(WorldOperationEntry::ContactPointBuffer));
            }
        }
        __forceinline void* __cdecl operator new(Y2 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Y2, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        void reset()
        {
            m_pFirstFreeContactPoint = &m_akContactRecords[0];
            m_ppFirstFreeContactPointer = &m_apContactPointPointers[0];
        }
        ContactPointAgentEntry* m_pFirstFreeContactPoint;
        ContactPointWithId** m_ppFirstFreeContactPointer;
        ContactPointWithId* m_apContactPointPointers[HK_MAX_CONTACT_POINT];
        ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
    };

  public:
    ValueWrapper<ContactPointBuffer*> m_akContactRecords;
};
extern hkMemoryAllocator::MemoryState g_eOutOfMemoryState;
__forceinline hkMemoryAllocator::MemoryState hkGetOutOfMemoryState()
{
    return g_eOutOfMemoryState;
}
__forceinline bool hkMemoryStateIsOutOfMemory(int id)
{
    bool lowOnMem = hkGetOutOfMemoryState() == hkMemoryAllocator::MEMORY_STATE_OUT_OF_MEMORY;
    return lowOnMem;
}
namespace MotionUtilities {
void __cdecl ComputeTransformAtTime(const hkSweptTransform& sweptTrans, hkTime time, hkTransform& transformOut);
__forceinline void __cdecl calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                       hkVector4& timOut);
}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                          hkVector4& timOut)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    hkVector4 diff0;
    diff0.setSub4(st0.m_vCenterOfMass0, st0.m_vCenterOfMass1);
    hkVector4 diff1;
    diff1.setSub4(st1.m_vCenterOfMass1, st1.m_vCenterOfMass0);
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.m_kDeltaAngle(3) * ms0.m_fObjectRadius + f1 * ms1.m_kDeltaAngle(3) * ms1.m_fObjectRadius;
}
struct AgentSectorPointerArray;
struct ShapeKeyAgentEntry : FourByteState
{
    ShapeKeyCombination m_kShapeKeyPair;
};
struct ByteStateWithThreeIntegers : ShapeKeyAgentEntry
{
    hkUint32 m_uiEntryValue;
};
struct ByteStateWithMixedNumericData : ShapeKeyAgentEntry
{
    hkTime m_fFloatValue;
    hkVector4 m_vSeparatingNormal;
};
struct EmptyMarker
{
};
typedef Y3* (*hkAgent1nMachine_VisitorCallback)(EmptyMarker& vin, ShapeKeyAgentEntry* entry, Y3* agentData);
extern "C"
{
    void __cdecl ResetAgentTrack(AgentSectorPointerArray& agentTrack);
    enum hkpAgentMachineMode
    {
        HKP_AGENT_MACHINE_MODE_1N = 1,
        HKP_AGENT_MACHINE_MODE_NM = 2
    };
    void __cdecl BuildShapeCollectionBWorldOperations(AgentSectorPointerArray& agentTrack,
                                                      const AgentSubtypeMarker& input,
                                                      const hkpShapeContainer* shapeContainterB,
                                                      const hkpShapeKey* hitList, WorldOperationEntry& output);
    void __cdecl UpdateAgentTrackShapeFilter(AgentSectorPointerArray& agentTrack, EmptyMarker& vin);
    void __cdecl hkAgentNmMachine_UpdateShapeCollectionFilter(AgentSectorPointerArray& agentTrack, EmptyMarker& vin);
    void __cdecl VisitTrackedAgents(AgentSectorPointerArray& agentTrack, EmptyMarker& vin, hkpContactMgr* mgr,
                                    hkAgent1nMachine_VisitorCallback visitor);
    void __cdecl DestroyAgentTrack(AgentSectorPointerArray& agentTrack, hkpCollisionDispatcher* dispatch,
                                   hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner);
    void __cdecl CollideTrackedAgents(AgentSectorPointerArray& track, const Y5& input);
    void __cdecl UpdateTrackedAgentTimes(AgentSectorPointerArray& track, hkTime oldTime, hkTime newTime,
                                         const Y5& input);
    void __cdecl ProcessShapeCollection(AgentProcessingInput& input, const hkpShapeContainer* shapeCollection,
                                        WorldOperationEntry& output);
    ShapeKeyAgentEntry* hkAgent1nMachine_FindAgent(AgentSectorPointerArray& agentTrack, ShapeKeyCombination keyPair,
                                                   Y3** agentDataOut);
}
struct hkpAgent1nSector
{
    __forceinline void* __cdecl operator new(Y2 Y6)
    {
        ;
        void* obj = Y1::GetMonitorStream().heap().Y4(static_cast<int>(Y6));
        ;
        return obj;
    }
    __forceinline void __cdecl operator delete(void* p)
    {
        if (p)
        {
            ;
            Y1::GetMonitorStream().heap().ReleaseBlock(p, sizeof(hkpAgent1nSector));
        }
    }
    enum
    {
        SECTOR_SIZE = 512,
        NET_SECTOR_SIZE = SECTOR_SIZE - 16
    };
    hkUint32 m_uiAgentCount;
    hkUint32 m_uiStandInValue;
    hkUint32 m_iValueAfterStandIn;
    hkUint32 m_pAuxiliaryObject;
    hkUint8 m_data[512 - 16];
    __forceinline Y3* getBegin()
    {
        return reinterpret_cast<Y3*>(&m_data[0]);
    }
    Y3* GetStreamEnd()
    {
        ;
        return reinterpret_cast<Y3*>(&m_data[m_uiAgentCount]);
    }
    Y3* getEndOfCapacity()
    {
        return reinterpret_cast<Y3*>(&m_data[NET_SECTOR_SIZE]);
    }
    int getCapacity()
    {
        return NET_SECTOR_SIZE;
    }
    inline hkpAgent1nSector() : m_uiAgentCount(0)
    {}
};
struct AgentSectorPointerArray
{
    hkArray<hkpAgent1nSector*> m_kSectors;
};
namespace AgentSectorUtilities {
__forceinline hkpCollisionAgent*& __cdecl getChildAgent(Y3* agentData)
{
    return *reinterpret_cast<hkpCollisionAgent**>(agentData);
}
__forceinline Y3* __cdecl getAgentDataEnd(Y3* agentData)
{
    return hkAddByteOffset(agentData, (((sizeof(getChildAgent(agentData))) + ((16) - 1)) & (~((16) - 1))));
}
}
extern "C"
{
    const hkpCdBody* __cdecl GetTransformedCdBody(const hkpCdBody* cdBody, hkpCdBody* newCdBodies,
                                                  class hkMotionState* newMotionStates, int numSlots,
                                                  ValueWrapper<hkUchar>& cdBodyHasTransformFlag);
}
class hkpCollidableCollidableFilter
{
  public:
    static const struct Y7 Members[];
    virtual ~hkpCollidableCollidableFilter()
    {}
};
class hkpRayCollidableFilter
{
  public:
    static const struct Y7 Members[];
};
class hkpShapeCollectionFilter
{
  public:
    static const struct Y7 Members[];
    virtual hkBool IsCollisionEnabled(const Y5& input, const hkpCdBody& collectionBodyA,
                                      const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA,
                                      const hkpShapeContainer& containerShapeB, hkpShapeKey keyA,
                                      hkpShapeKey keyB) const = 0;
};
class hkpRayShapeCollectionFilter
{
  public:
    static const struct Y7 Members[];
};
class hkpCollisionFilter : public hkReferencedObject,
                           public hkpCollidableCollidableFilter,
                           public hkpShapeCollectionFilter,
                           public hkpRayShapeCollectionFilter,
                           public hkpRayCollidableFilter
{
  public:
    static const struct Y7 Members[];

  public:
    hkpCollisionFilter();
    virtual hkBool IsCollisionEnabled(const Y5& input, const hkpCdBody& collectionBodyA,
                                      const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA,
                                      const hkpShapeContainer& containerShapeB, hkpShapeKey keyA,
                                      hkpShapeKey keyB) const = 0;

  public:
    hkUint32 m_prepad0;
    hkUint32 m_prepad1;

  public:
    hkpCollisionFilter(FinishingFlag flag) : hkReferencedObject(flag)
    {}
};
class hkpShapeContainer
{
  public:
    static const struct Y7 Members[];
    virtual ~hkpShapeContainer()
    {}
    virtual int GetNumChildShapes() const;
    virtual hkpShapeKey GetFirstKey() const = 0;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const = 0;
    virtual hkUint32 GetFilterInfoForKey(hkpShapeKey key) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const = 0;
};
struct AgentProcessingBodyTemp
{
    hkpCdBody m_pBodyA;
    hkpCdBody m_pBodyB;
    hkTransform m_kTransformA;
    hkTransform m_kTransformB;
};
__declspec(noinline) static void CreateAgentInputWithTemporaryBodies(AgentProcessingInput& in,
                                                                     AgentProcessingBodyTemp& bodyTemp,
                                                                     AgentProcessingInput& out)
{
    MotionUtilities::ComputeTransformAtTime(in.m_pBodyA->GetMotionState()->getSweptTransform(),
                           in.m_pRayCastInput->m_pStepInfo.m_uiStartTime, bodyTemp.m_kTransformA);
    MotionUtilities::ComputeTransformAtTime(in.m_pBodyB->GetMotionState()->getSweptTransform(),
                           in.m_pRayCastInput->m_pStepInfo.m_uiStartTime, bodyTemp.m_kTransformB);
    out.m_pBodyA = &bodyTemp.m_pBodyA;
}
__declspec(noinline) static void InvertAgentSubtypeMarker(AgentSubtypeMarker& in, AgentSubtypeMarker& out)
{
    out.m_vSubtypePosition.setNeg3(in.m_vSubtypePosition);
    out.m_kTransform.SetConjugate(in.m_kTransform);
}
class WrappedShapeKeys
{
  public:
    __forceinline bool operator==(const ShapeKeyCombination& p)
    {
        return m_uiShapeKeyB == p.m_uiShapeKeyB && m_uiShapeKeyA == p.m_uiShapeKeyA;
    }
    __forceinline bool operator>(const ShapeKeyCombination& p)
    {
        return m_uiShapeKeyB > p.m_uiShapeKeyB || (m_uiShapeKeyB == p.m_uiShapeKeyB && m_uiShapeKeyA > p.m_uiShapeKeyA);
    }
    __forceinline void operator=(const ShapeKeyCombination& p)
    {
        m_uiShapeKeyA = p.m_uiShapeKeyA;
        m_uiShapeKeyB = p.m_uiShapeKeyB;
    }
    __forceinline void writeTo(ShapeKeyCombination& p)
    {
        p.m_uiShapeKeyB = m_uiShapeKeyB;
        p.m_uiShapeKeyA = m_uiShapeKeyA;
    }
    ValueWrapper<hkpShapeKey> m_uiShapeKeyA;
    ValueWrapper<hkpShapeKey> m_uiShapeKeyB;
};
static __forceinline void extractChildShapes(const WrappedShapeKeys& shapeKeyPair,
                                             WrappedShapeKeys& extractedShapeKeys,
                                             const hkpShapeContainer* shapeContainerA,
                                             const hkpShapeContainer* shapeContainerB, hkpShapeBuffer& shapeBufferA,
                                             hkpShapeBuffer& shapeBufferB, hkpCdBody& modifiedBodyA,
                                             hkpCdBody& modifiedBodyB)
{
    {
        hkpShapeKey key = shapeKeyPair.m_uiShapeKeyB;
        if (extractedShapeKeys.m_uiShapeKeyB != key)
        {
            extractedShapeKeys.m_uiShapeKeyB = key;
            const hkpShape* shapeB = shapeContainerB->GetShapeForKey(key, shapeBufferB);
            modifiedBodyB.SetCollisionShapeAndKey(shapeB, key);
        }
    }
    {
        hkpShapeKey key = shapeKeyPair.m_uiShapeKeyA;
        if (extractedShapeKeys.m_uiShapeKeyA != key)
        {
            extractedShapeKeys.m_uiShapeKeyA = key;
            const hkpShape* shapeA = shapeContainerA->GetShapeForKey(key, shapeBufferA);
            modifiedBodyA.SetCollisionShapeAndKey(shapeA, key);
        }
    }
}
// @fnv 0x00da5b80
void __cdecl FUN_00da5b80(AgentSectorPointerArray& agentTrack, const AgentSubtypeMarker& inputIn,
                          const hkpShapeContainer* shapeContainerA, const hkpShapeContainer* shapeContainerB,
                          const ShapeKeyCombination* newKeys, WorldOperationEntry& output)
{
    MathUtilities::prefetch128(agentTrack.m_kSectors.begin());
    AgentSubtypeMarker input;
    MemoryUtils::memCpy16NonEmpty(&input, &inputIn, sizeof(AgentSubtypeMarker) / 16);
    WrappedShapeKeys extractedShapeKeys;
    extractedShapeKeys.m_uiShapeKeyA = 0xffffffff;
    extractedShapeKeys.m_uiShapeKeyB = 0xffffffff;
    hkpCollisionDispatcher* dispatcher = input.m_pRayCastInput->m_pCollisionDispatcher;
    const int numSlotsForTransformedCdBodies = 4;
    hkMotionState transformForTransformedShapeB[numSlotsForTransformedCdBodies];
    hkMotionState transformForTransformedShapeA[numSlotsForTransformedCdBodies];
    hkpCdBody cdBodyForTransformedShapeB[numSlotsForTransformedCdBodies];
    hkpCdBody cdBodyForTransformedShapeA[numSlotsForTransformedCdBodies];
    ValueWrapper<const hkpCdBody*>* modifiedBodyBPtr = &input.m_pBodyB;
    ValueWrapper<const hkpCdBody*>* modifiedBodyAPtr = &input.m_pBodyA;
    hkpCdBody childBodyB(inputIn.m_pBodyB);
    *modifiedBodyBPtr = &childBodyB;
    hkpCdBody childBodyA(inputIn.m_pBodyA);
    *modifiedBodyAPtr = &childBodyA;
    int numTim = 0;
    hkpAgent1nSector* readSector = agentTrack.m_kSectors[0];
    MathUtilities::forcePrefetch<512>(readSector);
    hkpAgent1nSector* currentSector =
        (input.m_pRayCastInput->m_pAgent1nSector) ? input.m_pRayCastInput->m_pAgent1nSector : new hkpAgent1nSector;
    input.m_pRayCastInput->m_pAgent1nSector = 0;
    int currentSectorIndex = 0;
    bool prevInputInitialized = false;
    bool prevFlippedInputInitialized = false;
    AgentProcessingInput prevInput;
    AgentProcessingInput prevFlippedInput;
    AgentProcessingBodyTemp prevTemp;
    AgentProcessingBodyTemp prevFlippedTemp;
    __declspec(align(16)) hkUchar extensionBuffer[hkAgent3::MAX_TOTAL_SIZE];
    bool inExtensionBuffer = false;
    int nextReadSectorIndex = 1;
    void* readData = readSector->getBegin();
    void* readEnd = readSector->GetStreamEnd();
    void* currentData = currentSector->getBegin();
    void* currentDataEnd = currentSector->getEndOfCapacity();
    int bytesUsedInCurrentSector = 0;
    hkpShapeBuffer shapeBufferA;
    hkpShapeBuffer shapeBufferB;
    while (1)
    {
        WrappedShapeKeys shapeKeyPair;
        *modifiedBodyBPtr = &childBodyB;
        *modifiedBodyAPtr = &childBodyA;
        input.m_kTransform = inputIn.m_kTransform;
        if (!newKeys)
        {
            ShapeKeyAgentEntry* entry = reinterpret_cast<ShapeKeyAgentEntry*>(readData);
            int entrySize = entry->m_iElementCount;
            MemoryUtils::memCpy16NonEmpty(currentData, readData, entrySize >> 4);
            readData = hkAddByteOffset(readData, entrySize);
            shapeKeyPair = entry->m_kShapeKeyPair;
        }
        else
        {
            ShapeKeyAgentEntry* readHeader = reinterpret_cast<ShapeKeyAgentEntry*>(readData);
            shapeKeyPair = *newKeys;
            if (shapeKeyPair == readHeader->m_kShapeKeyPair)
            {
                int size = readHeader->m_iElementCount;
                MemoryUtils::memCpy16NonEmpty(currentData, readData, size >> 4);
                readData = hkAddByteOffset(readData, size);
                newKeys++;
            }
            else if (shapeKeyPair > readHeader->m_kShapeKeyPair)
            {
                void* agentData = ((readHeader->m_ucAgentType & 6) == hkAgent3::STREAM_CALL_WITH_TIM)
                                      ? (void*)hkAddByteOffset(readHeader, sizeof(ByteStateWithMixedNumericData))
                                      : (void*)hkAddByteOffset(readHeader, sizeof(ByteStateWithThreeIntegers));
                readData = hkAddByteOffset(readData, readHeader->m_iElementCount);
                dispatcher->getAgent3DestroyFunc(readHeader->m_ucNnTrackType)(
                    readHeader, agentData, input.m_pContactManager, *output.m_pConstraintOwner.val(), dispatcher);
                goto checkReadSector;
            }
            else
            {
                if (input.m_pRayCastInput->m_iFilter->IsCollisionEnabled(
                        *input.m_pRayCastInput, *inputIn.m_pBodyA, *inputIn.m_pBodyB, *shapeContainerA,
                        *shapeContainerB, shapeKeyPair.m_uiShapeKeyA, shapeKeyPair.m_uiShapeKeyB))
                {
                    if (hkMemoryStateIsOutOfMemory(18))
                    {
                        newKeys++;
                        goto checkReadSector;
                    }
                    extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                       shapeBufferB, childBodyA, childBodyB);
                    const hkpShape* shapeB = (*modifiedBodyBPtr)->m_pCollisionShape;
                    const hkpShape* shapeA = (*modifiedBodyAPtr)->m_pCollisionShape;
                    ValueWrapper<hkUchar> cdBodyHasTransformFlag = 0;
                    *modifiedBodyBPtr = GetTransformedCdBody(*modifiedBodyBPtr, cdBodyForTransformedShapeB,
                                                             transformForTransformedShapeB,
                                                             numSlotsForTransformedCdBodies, cdBodyHasTransformFlag);
                    shapeB = (*modifiedBodyBPtr)->m_pCollisionShape;
                    *modifiedBodyAPtr = GetTransformedCdBody(*modifiedBodyAPtr, cdBodyForTransformedShapeA,
                                                             transformForTransformedShapeA,
                                                             numSlotsForTransformedCdBodies, cdBodyHasTransformFlag);
                    shapeA = (*modifiedBodyAPtr)->m_pCollisionShape;
                    input.m_kTransform.SetMulInverse((*modifiedBodyAPtr)->getTransform(),
                                                     (*modifiedBodyBPtr)->getTransform());
                    ShapeKeyAgentEntry* h = reinterpret_cast<ShapeKeyAgentEntry*>(currentData);
                    shapeKeyPair.writeTo(h->m_kShapeKeyPair);
                    h->m_ucNnTrackType = hkUchar(dispatcher->getAgent3Type(
                        shapeA->getType(), shapeB->getType(), input.m_pRayCastInput->m_bCreatePredictiveAgents));
                    h->m_usNumContactPoints = 0;
                    AgentSubtypeMarker flippedInput;
                    AgentSubtypeMarker* in = &input;
                    int isFlipped = 0;
                    if (dispatcher->getAgent3Symmetric(h->m_ucNnTrackType) == hkAgent3::IS_NOT_SYMMETRIC_AND_FLIPPED)
                    {
                        isFlipped = 1;
                        in = &flippedInput;
                        InvertAgentSubtypeMarker(input, flippedInput);
                    }
                    if (dispatcher->getAgent3SepNormalFunc(h->m_ucNnTrackType))
                    {
                        ByteStateWithMixedNumericData* entry =
                            reinterpret_cast<ByteStateWithMixedNumericData*>(currentData);
                        entry->m_ucAgentType =
                            hkUchar(hkAgent3::STREAM_CALL_WITH_TIM + isFlipped) | cdBodyHasTransformFlag;
                        entry->m_fFloatValue = -1.0f;
                        entry->m_vSeparatingNormal.setZero4();
                        void* agentData = entry + 1;
                        void* agentEnd = dispatcher->getAgent3CreateFunc(entry->m_ucNnTrackType)(*in, entry, agentData);
                        hkUlong size = hkGetByteOffset(entry, agentEnd);
                        entry->m_iElementCount = hkUchar(size);
                        ;
                    }
                    else
                    {
                        ByteStateWithThreeIntegers* entry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                        entry->m_ucAgentType = hkUchar(hkAgent3::STREAM_CALL + isFlipped) | cdBodyHasTransformFlag;
                        void* agentData = entry + 1;
                        void* agentEnd = dispatcher->getAgent3CreateFunc(entry->m_ucNnTrackType)(*in, entry, agentData);
                        hkUlong size = hkGetByteOffset(entry, agentEnd);
                        entry->m_iElementCount = hkUchar(size);
                        ;
                    }
                }
                else
                {
                    ByteStateWithThreeIntegers* h = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                    *reinterpret_cast<hkUint32*>(h) = 0;
                    shapeKeyPair.writeTo(h->m_kShapeKeyPair);
                    h->m_iElementCount = sizeof(ByteStateWithThreeIntegers);
                }
                newKeys++;
            }
        }
        {
            bool thisChildHasTransformApplied = false;
            hkAgent3::StreamCommand command =
                hkAgent3::StreamCommand(reinterpret_cast<FourByteState*>(currentData)->m_ucAgentType);
        commandSwitch:
            switch (command)
            {
            case hkAgent3::STREAM_CALL_WITH_TRANSFORM:
            case hkAgent3::STREAM_CALL_FLIPPED_WITH_TRANSFORM:
            case hkAgent3::STREAM_CALL_WITH_TIM_WITH_TRANSFORM:
            case hkAgent3::STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM:
            case hkAgent3::STREAM_CALL_AGENT_WITH_TRANSFORM: {
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                ValueWrapper<hkUchar> dummyCdBodyHasTransformFlag = 0;
                *modifiedBodyBPtr =
                    GetTransformedCdBody(*modifiedBodyBPtr, cdBodyForTransformedShapeB, transformForTransformedShapeB,
                                         numSlotsForTransformedCdBodies, dummyCdBodyHasTransformFlag);
                *modifiedBodyAPtr =
                    GetTransformedCdBody(*modifiedBodyAPtr, cdBodyForTransformedShapeA, transformForTransformedShapeA,
                                         numSlotsForTransformedCdBodies, dummyCdBodyHasTransformFlag);
                input.m_kTransform.SetMulInverse((*modifiedBodyAPtr)->getTransform(),
                                                 (*modifiedBodyBPtr)->getTransform());
                command = hkAgent3::StreamCommand(hkUchar(command) & hkUchar(~hkAgent3::TRANSFORM_FLAG));
                thisChildHasTransformApplied = true;
                prevFlippedInputInitialized = false;
                prevInputInitialized = false;
                goto commandSwitch;
            }
            case hkAgent3::STREAM_CALL_AGENT: {
                ByteStateWithThreeIntegers* paddedEntry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                void* agentData = paddedEntry + 1;
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                hkpCollisionAgent* agent = AgentSectorUtilities::getChildAgent(agentData);
                agent->ProcessAgent(**modifiedBodyAPtr, **modifiedBodyBPtr, *input.m_pRayCastInput, output);
                currentData = AgentSectorUtilities::getAgentDataEnd(agentData);
                break;
            }
            case hkAgent3::STREAM_CALL: {
                ByteStateWithThreeIntegers* entry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                void* agentData = entry + 1;
                currentData =
                    dispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(input, entry, agentData, 0, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                break;
            }
            case hkAgent3::STREAM_CALL_FLIPPED: {
                AgentSubtypeMarker flippedInput;
                InvertAgentSubtypeMarker(input, flippedInput);
                ByteStateWithThreeIntegers* entry = reinterpret_cast<ByteStateWithThreeIntegers*>(currentData);
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                ContactPointWithId* oldResultBegin = output.m_pAlignedPairData;
                currentData =
                    dispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(flippedInput, entry, agentData, 0, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                while (oldResultBegin < output.m_pAlignedPairData)
                {
                    oldResultBegin->m_kPoint.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case hkAgent3::STREAM_CALL_WITH_TIM_FLIPPED: {
                AgentSubtypeMarker flippedInput;
                InvertAgentSubtypeMarker(input, flippedInput);
                ByteStateWithMixedNumericData* entry = reinterpret_cast<ByteStateWithMixedNumericData*>(currentData);
                hkReal distAtT1;
                if (entry->m_fFloatValue != flippedInput.m_pRayCastInput->m_pStepInfo.m_uiStartTime)
                {
                    const CollisionQualityInfo* ci = flippedInput.m_pRayCastInput->m_pCollisionQualityInfo;
                    if (!ci->m_iQualityInfoValue10.val())
                    {
                        entry->m_fFloatValue = flippedInput.m_pRayCastInput->m_pStepInfo.m_fEndTime;
                        distAtT1 = ci->m_fCreateContactThreshold * 0.5f;
                        entry->m_vSeparatingNormal.setZero4();
                        entry->m_vSeparatingNormal(3) = distAtT1;
                        goto PROCESS_AT_T1_FLIPPED;
                    }
                    if (!prevFlippedInputInitialized)
                    {
                        prevFlippedInputInitialized = !thisChildHasTransformApplied;
                        CreateAgentInputWithTemporaryBodies(flippedInput, prevFlippedTemp, prevFlippedInput);
                        prevFlippedTemp.m_pBodyB.SetCollisionShapeAndKey(flippedInput.m_pBodyB->getShape(),
                                                                         flippedInput.m_pBodyB->m_uiCollisionShapeKey);
                    }
                    extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                       shapeBufferB, childBodyA, childBodyB);
                    prevFlippedTemp.m_pBodyA.SetCollisionShapeAndKey((*modifiedBodyBPtr)->m_pCollisionShape,
                                                                     (*modifiedBodyBPtr)->m_uiCollisionShapeKey);
                    prevFlippedTemp.m_pBodyB.SetCollisionShapeAndKey((*modifiedBodyAPtr)->m_pCollisionShape,
                                                                     (*modifiedBodyAPtr)->m_uiCollisionShapeKey);
                    void* agentData = entry + 1;
                    dispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)(prevFlippedInput, entry, agentData,
                                                                               entry->m_vSeparatingNormal);
                }
                entry->m_fFloatValue = flippedInput.m_pRayCastInput->m_pStepInfo.m_fEndTime;
                {
                    hkReal worstCaseDeltaDist = flippedInput.m_vSubtypePosition.dot4xyz1(entry->m_vSeparatingNormal);
                    distAtT1 = entry->m_vSeparatingNormal(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= flippedInput.m_pRayCastInput->getTolerance())
                {
                    entry->m_vSeparatingNormal(3) = distAtT1;
                    if (!entry->m_usNumContactPoints)
                    {
                        currentData = hkAddByteOffset(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = dispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)(
                            entry, agentData, flippedInput.m_pContactManager, *output.m_pConstraintOwner.val());
                        entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1_FLIPPED:
                flippedInput.m_fSubtypeValue = distAtT1;
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                ContactPointWithId* oldResultBegin = output.m_pAlignedPairData;
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                currentData = dispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(
                    flippedInput, entry, agentData, &entry->m_vSeparatingNormal, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                while (oldResultBegin < output.m_pAlignedPairData)
                {
                    oldResultBegin->m_kPoint.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case hkAgent3::STREAM_CALL_WITH_TIM: {
                ByteStateWithMixedNumericData* entry = reinterpret_cast<ByteStateWithMixedNumericData*>(currentData);
                hkReal distAtT1;
                if (entry->m_fFloatValue != input.m_pRayCastInput->m_pStepInfo.m_uiStartTime)
                {
                    if (entry->m_fFloatValue >= input.m_pRayCastInput->m_pStepInfo.m_fEndTime)
                    {
                        hkReal backDt = entry->m_fFloatValue - input.m_pRayCastInput->m_pStepInfo.m_fEndTime;
                        hkVector4 backTim;
                        MotionUtilities::calcTimInfo(*input.m_pBodyA->GetMotionState(),
                                                     *input.m_pBodyB->GetMotionState(), backDt, backTim);
                        hkReal backLinear = backTim.dot3(entry->m_vSeparatingNormal);
                        hkReal backAng = backTim(3);
                        distAtT1 = entry->m_vSeparatingNormal(3) + backLinear - backAng;
                    }
                    else
                    {
                        const CollisionQualityInfo* ci = input.m_pRayCastInput->m_pCollisionQualityInfo;
                        if (!ci->m_iQualityInfoValue10.val())
                        {
                            entry->m_fFloatValue = input.m_pRayCastInput->m_pStepInfo.m_fEndTime;
                            distAtT1 = ci->m_fCreateContactThreshold * 0.1f;
                            entry->m_vSeparatingNormal.setZero4();
                            entry->m_vSeparatingNormal(3) = distAtT1;
                            goto PROCESS_AT_T1;
                        }
                        if (!prevInputInitialized)
                        {
                            prevInputInitialized = !thisChildHasTransformApplied;
                            CreateAgentInputWithTemporaryBodies(input, prevTemp, prevInput);
                        }
                        extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB,
                                           shapeBufferA, shapeBufferB, childBodyA, childBodyB);
                        prevTemp.m_pBodyB.SetCollisionShapeAndKey((*modifiedBodyBPtr)->m_pCollisionShape,
                                                                  (*modifiedBodyBPtr)->m_uiCollisionShapeKey);
                        prevTemp.m_pBodyA.SetCollisionShapeAndKey((*modifiedBodyAPtr)->m_pCollisionShape,
                                                                  (*modifiedBodyAPtr)->m_uiCollisionShapeKey);
                        void* agentData = entry + 1;
                        dispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)(prevInput, entry, agentData,
                                                                                   entry->m_vSeparatingNormal);
                    }
                }
                entry->m_fFloatValue = input.m_pRayCastInput->m_pStepInfo.m_fEndTime;
                {
                    hkReal worstCaseDeltaDist = input.m_vSubtypePosition.dot4xyz1(entry->m_vSeparatingNormal);
                    distAtT1 = entry->m_vSeparatingNormal(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= input.m_pRayCastInput->getTolerance())
                {
                    entry->m_vSeparatingNormal(3) = distAtT1;
                    if (!entry->m_usNumContactPoints)
                    {
                        currentData = hkAddByteOffset(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = dispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)(
                            entry, agentData, input.m_pContactManager, *output.m_pConstraintOwner.val());
                        entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1:
                input.m_fSubtypeValue = distAtT1;
                extractChildShapes(shapeKeyPair, extractedShapeKeys, shapeContainerA, shapeContainerB, shapeBufferA,
                                   shapeBufferB, childBodyA, childBodyB);
                void* agentData = entry + 1;
                currentData = dispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)(
                    input, entry, agentData, &entry->m_vSeparatingNormal, output);
                entry->m_iElementCount = hkUchar(hkGetByteOffset(entry, currentData));
                break;
            }
            case hkAgent3::STREAM_NULL: {
                currentData = hkAddByteOffset(currentData, sizeof(ByteStateWithThreeIntegers));
                break;
            }
            case hkAgent3::STREAM_END: {
                currentData = hkAddByteOffset(currentData, sizeof(ByteStateWithThreeIntegers));
                break;
            }
            default:;
            }
        }
    checkReadSector:;
        if (readData == readEnd)
        {
            if (input.m_pRayCastInput->m_pAgent1nSector)
            {
                delete readSector;
            }
            else
            {
                input.m_pRayCastInput->m_pAgent1nSector = readSector;
            }
            if (nextReadSectorIndex < agentTrack.m_kSectors.GetLogicalSize())
            {
                readSector = agentTrack.m_kSectors[nextReadSectorIndex];
                readData = readSector->getBegin();
                readEnd = readSector->GetStreamEnd();
                nextReadSectorIndex++;
            }
            else
            {
                break;
            };
        }
        if (hkAddByteOffset(currentData, hkAgent3::MAX_TOTAL_SIZE) <= currentDataEnd)
        {
            continue;
        }
        if (!inExtensionBuffer)
        {
            inExtensionBuffer = true;
            bytesUsedInCurrentSector = hkGetByteOffset(currentSector->getBegin(), currentData);
            ;
            currentData = extensionBuffer;
            currentDataEnd = hkAddByteOffset(extensionBuffer, hkAgent3::MAX_TOTAL_SIZE);
            continue;
        }
        int bytesUsedInExtensionBuffer;
        bytesUsedInExtensionBuffer = hkGetByteOffset(extensionBuffer, currentData);
        {
            int freeBytes = currentSector->getCapacity() - bytesUsedInCurrentSector;
            if (bytesUsedInExtensionBuffer <= freeBytes)
            {
                void* dst = hkAddByteOffset(currentSector->getBegin(), bytesUsedInCurrentSector);
                MemoryUtils::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
                bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
                if (bytesUsedInCurrentSector < currentSector->getCapacity())
                {
                    currentData = extensionBuffer;
                    continue;
                }
                inExtensionBuffer = false;
                currentData = 0;
                currentDataEnd = 0;
            }
        }
        currentSector->m_uiAgentCount = bytesUsedInCurrentSector;
        if (currentSectorIndex >= nextReadSectorIndex)
        {
            agentTrack.m_kSectors.expandAt(nextReadSectorIndex, 1);
            nextReadSectorIndex++;
        }
        agentTrack.m_kSectors[currentSectorIndex] = currentSector;
        ;
        currentSectorIndex++;
        currentSector = (input.m_pRayCastInput->m_pAgent1nSector) ? input.m_pRayCastInput->m_pAgent1nSector
                                                                    : new hkpAgent1nSector;
        input.m_pRayCastInput->m_pAgent1nSector = 0;
        currentData = currentSector->getBegin();
        currentDataEnd = currentSector->getEndOfCapacity();
        if (inExtensionBuffer)
        {
            MemoryUtils::memCpy16NonEmpty(currentData, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
            currentData = hkAddByteOffset(currentData, bytesUsedInExtensionBuffer);
            inExtensionBuffer = false;
        }
    }
    if (!inExtensionBuffer)
    {
        bytesUsedInCurrentSector = hkGetByteOffset(currentSector->getBegin(), currentData);
    }
    else
    {
        int bytesUsedInExtensionBuffer = hkGetByteOffset(extensionBuffer, currentData);
        ;
        void* dst = hkAddByteOffset(currentSector->getBegin(), bytesUsedInCurrentSector);
        MemoryUtils::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
        bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
    };
    currentSector->m_uiAgentCount = bytesUsedInCurrentSector;
    agentTrack.m_kSectors.SetSizeAndGrow(currentSectorIndex + 1);
    agentTrack.m_kSectors[currentSectorIndex] = currentSector;
    ;
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            StringCursor::CommandFilterEntry* h =
                reinterpret_cast<StringCursor::CommandFilterEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "M"
                                "i"
                                "numTim";
            h->m_uiFilterValue = float(numTim);
            mStream.setEnd((char*)(h + 1));
        }
    };
}

#include <xmmintrin.h>
namespace fnv_00da4aa0 {
typedef float hkReal;
typedef unsigned char Q42;
typedef unsigned char Q150;
typedef unsigned short Q133;
typedef unsigned int Q49;
typedef unsigned long __w64 Q165;
typedef signed long __w64 hkLong;
typedef unsigned __w64 Q3;
typedef hkReal hkTime;
__forceinline hkLong __cdecl Q19(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
template <typename TYPE> __forceinline TYPE* __cdecl Q11(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}
class Q35
{
  public:
    Q35() : q151(0)
    {}
    int q151;
};
class hkClass;
typedef int Q134;
class hkBool
{
  public:
    typedef char CompileTimeTrueType;
    inline hkBool(bool b)
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
extern "C"
{
    extern const hkReal Q128[256];
}
class Q113
{
  public:
    enum
    {
        MAX_VALUE = 256
    };
    inline Q113()
    {}
    Q113& operator=(const float& fv);
    inline Q113(const float f)
    {
        *this = f;
    }
    inline operator float() const
    {
        return Q128[q152];
    }

  public:
    Q150 q152;
};
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    hkEnum(ENUM e)
    {
        q89 = static_cast<STORAGE>(e);
    }
    operator ENUM() const
    {
        return static_cast<ENUM>(q89);
    }

  private:
    STORAGE q89;
};
template <typename TYPE> class Q20
{
  public:
    __forceinline Q20()
    {}
    __forceinline Q20(TYPE e) : q89(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        q89 = e;
    }
    __forceinline TYPE val() const
    {
        return q89;
    }
    __forceinline TYPE operator->() const
    {
        return q89;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE q89;
};
extern "C"
{
    __declspec(dllimport) void* _stdcall TlsGetValue(unsigned long dwTlsIndex);
}
template <typename T> class Q98
{
  public:
    Q98()
    {
        q195 = TlsAlloc();
    }
    __forceinline T getData() const
    {
        return (T)(Q165)TlsGetValue(q195);
    }
    unsigned long q195;
};
class Q15
{
  public:
    __forceinline void* __cdecl operator new(Q3, void* p)
    {
        return p;
    }
    virtual ~Q15();
    virtual void* AllocateMemoryBlock(int numBytes) = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;

  public:
    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };
};
namespace MemoryUtilities {
void __cdecl CopyByteRange(void* dst, const void* src, int nbytes);
}
struct Q135
{
  public:
    __forceinline Q135();

  protected:
    Q20<void*> m_next;
    Q20<void*> m_kRayStart;
    Q20<void*> m_kRayEnd;
};
class Q0
{
  public:
    __forceinline void* __cdecl operator new(Q3, void* p)
    {
        return p;
    }
    typedef Q15 Allocator;
    static Q0& __cdecl GetMonitorStream();
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    Q135 m_aiEntries;
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
};
class Q114
{
  public:
    static const struct Q13 Members[];
    __forceinline virtual ~Q114()
    {}

  public:
    __forceinline Q114()
    {}
};
class Q67;
class Q16 : public Q114
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        Q16* b = static_cast<Q16*>(Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->q82 = static_cast<Q133>(nbytes);
        ;
        return b;
    }
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(Q67* collector, const hkClass* cls) const;

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    Q133 q82;

  public:
    Q16(class Q35 flag)
    {}
};
template <bool N> struct Q153
{
    typedef Q153<N> type;
    enum
    {
        result = N
    };
};
typedef Q153<true> Q154;
class Q184
{
  public:
    template <typename T> static __forceinline void construct(T* t, int n, Q154);
    static void __cdecl GrowArrayCapacity(Q15& a, void*, int reqElem, int sizeElem);
};
struct Q99
{
    Q15& get(const void*)
    {
        return Q0::GetMonitorStream().heap();
    }
};
template <typename T> class Q25
{
  public:
    typedef Q25<T> ThisType;

  protected:
    __forceinline Q25(const Q25& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);
    __forceinline T& operator[](int i);
    __forceinline int GetLogicalSize() const;
    __forceinline int getCapacity() const;
    __forceinline void GrowArrayCapacity(Q15& alloc, int n);
    __forceinline void _setSize(Q15& alloc, int size);
    __forceinline T* _expandAt(Q15& alloc, int index, int numToInsert);
    typedef T* iterator;
    __forceinline iterator begin();

  protected:
    __forceinline Q25<T>& copyFromArray(Q15&, const Q25<T>& src, Q154);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };

  protected:
    friend class Q67;
    T* m_data;
    int m_iElementCount;
    int q136;

  public:
    Q25(Q35 f)
    {}
};
template <typename T, typename Allocator = Q99> class Q155 : public Q25<T>
{
  public:
    typedef Allocator AllocatorType;

  protected:
    __forceinline Q155(const Q155& a);

  public:
    __forceinline Q155& operator=(const Q25<T>& a);
    __forceinline void SetSizeAndGrow(int size)
    {
        Q25<T>::_setSize(AllocatorType().get(this), size);
    }
    __forceinline T* expandAt(int i, int n)
    {
        return Q25<T>::_expandAt(AllocatorType().get(this), i, n);
    }
};
template <typename T> __forceinline T& Q25<T>::operator[](int i)
{
    ;
    return m_data[i];
}
template <typename T> __forceinline int Q25<T>::GetLogicalSize() const
{
    return m_iElementCount;
}
template <typename T> __forceinline int Q25<T>::getCapacity() const
{
    return (q136 & static_cast<int>(CAPACITY_MASK));
}
template <typename T> __forceinline void Q25<T>::GrowArrayCapacity(Q15& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        Q184::GrowArrayCapacity(alloc, this, newSize, sizeof(T));
    }
}
template <typename T> __forceinline void Q25<T>::_setSize(Q15& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <typename T> __forceinline T* Q25<T>::_expandAt(Q15& alloc, int index, int numtoinsert)
{
    const int newsize = numtoinsert + m_iElementCount;
    const int numtomove = m_iElementCount - index;
    if (newsize > getCapacity())
    {
        GrowArrayCapacity(alloc, newsize);
    }
    MemoryUtilities::CopyByteRange(m_data + index + numtoinsert, m_data + index, numtomove * sizeof(T));
    m_iElementCount = newsize;
    return m_data + index;
}
template <typename T> typename Q25<T>::iterator Q25<T>::begin()
{
    return m_data;
}
typedef __m128 Q57;
class Q1;
typedef const Q1& Q137;
class Q83
{
  public:
    Q83(const Q57& x) : m_vValue(x)
    {}
    Q83(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline Q57 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    Q57 m_vValue;
};
typedef const Q83& Q60;
namespace MathUtilities {
inline void prefetch128(const void* p)
{
    _mm_prefetch((const char*)p, 0);
}
template <int SIZE> inline void forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}
}
class Q1
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void operator=(const Q1& v);
    __forceinline void setZero4();
    __forceinline void setSub4(const Q1& a, const Q1& b);
    __forceinline void setMul4(Q60 r, const Q1& a);
    __forceinline void addMul4(Q60 r, const Q1& a);
    __forceinline void setAddMul4(const Q1& a, const Q1& x, const Q1& y);
    __forceinline void setNeg3(const Q1& v);
    __forceinline Q83 dot3(const Q1& a) const;
    __forceinline Q83 dot4xyz1(const Q1& a) const;
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline void setBroadcast(Q137 v, int i);

  private:
    Q57 m_vComponents;

  public:
    operator Q57() const
    {
        return m_vComponents;
    }
};
class Q144
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    Q1 m_vec;

  protected:
    void setFlippedRotation(const Q1& from);
};
class Q100
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline Q100()
    {}
    __forceinline const Q1& getColumn(int i) const;
    inline void operator=(const Q100& a);

  protected:
    Q1 m_kColumn0;
    Q1 m_kColumn1;
    Q1 m_kColumn2;
};
class __declspec(align(16)) hkRotation : public Q100
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
class Q28
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline Q28()
    {}
    void SetConjugate(const Q28& t);
    void SetMulInverse(const Q28& bTa, const Q28& bTc);

  private:
    hkRotation m_rotation;
    Q1 m_vTranslation;
};
class Q45
{
  public:
    static const struct Q13 Members[];

  public:
    __forceinline void _approxTransformAt(hkTime time, Q28& transformOut) const;
    __forceinline hkReal getInvDeltaTime() const;

  public:
    Q1 q115;
    Q1 q90;
    Q144 m_qRotation0;
    Q144 m_qRotation1;
    Q1 q185;
};
inline void Q1::operator=(const Q1& v)
{
    m_vComponents = v.m_vComponents;
}
inline void Q1::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void Q1::setSub4(const Q1& v0, const Q1& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void Q1::setNeg3(const Q1& v)
{
    static __declspec(align(16)) const Q49 negateMask[4] = {0x80000000, 0x80000000, 0x80000000, 0x00000000};
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const Q57*)&negateMask);
}
inline void Q1::setMul4(Q60 r, const Q1& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void Q1::addMul4(Q60 r, const Q1& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline void Q1::setAddMul4(const Q1& a, const Q1& x, const Q1& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}
inline Q83 Q1::dot3(const Q1& a) const
{
    Q57 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    Q57 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline Q83 Q1::dot4xyz1(const Q1& a) const
{
    Q57 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    Q57 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    Q57 zwSum =
        _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))),
                   _mm_shuffle_ps(m_vComponents, m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3)))));
    return _mm_add_ps(xySum, zwSum);
}
inline hkReal& Q1::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal& Q1::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline void Q1::setBroadcast(const Q1& v, int i)
{
    if (i == 0)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    }
    else if (i == 1)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    }
    else if (i == 2)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    }
    else if (i == 3)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}
inline const Q1& Q100::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
inline void Q100::operator=(const Q100& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}
hkReal Q45::getInvDeltaTime() const
{
    return q90(3);
}
class Q88
{
  public:
    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads);

  private:
    static void copyAndReplace(char* dest, const char* orig, int origLen, const Q88& from, const Q88& to,
                               const Q155<int>& indices);
};
void __cdecl Q88::memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const Q49* src32 = reinterpret_cast<const Q49*>(src);
    Q49* dst32 = reinterpret_cast<Q49*>(dst);
    {
        do
        {
            dst32[0] = src32[0];
            dst32[1] = src32[1];
            dst32[2] = src32[2];
            dst32[3] = src32[3];
            dst32 += 4;
            src32 += 4;
        } while (--numQuads > 0);
    }
}
class Q37
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    static Q37& GetMonitorStream()
    {
        extern Q98<Q37*> Q91;
        return *Q91.getData();
    }

  public:
    __forceinline char* __cdecl GetStreamStart()
    {
        return m_kRayStart.val();
    }
    __forceinline char* __cdecl GetStreamEnd()
    {
        return m_kRayEnd.val();
    }
    __forceinline char* __cdecl getCapacityMinus16()
    {
        return q141.val();
    }
    __forceinline hkBool __cdecl memoryAvailable()
    {
        return GetStreamEnd() < getCapacityMinus16();
    }
    __forceinline void __cdecl setEnd(char* ptr)
    {
        m_kRayEnd = ptr;
    }

  public:
    static void __cdecl init();

  public:
    Q20<char*> m_kRayStart;
    Q20<char*> m_kRayEnd;
    Q20<char*> m_pRayCursor;
    Q20<char*> q141;

  public:
    struct Command
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q37::Command));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        const char* q129;
    };
    struct CommandFilterEntry : public Q37::Command
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q37::CommandFilterEntry));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        float q152;
    };
};
class Q31
{
  public:
    static const struct Q13 Members[];
    inline Q31();
    inline const Q45& getSweptTransform() const;

  protected:
    Q28 m_kMotionTransform;
    class Q45 q148;

  public:
    Q1 q145;
    hkReal q123;
};
Q31::Q31()
{}
const Q45& Q31::getSweptTransform() const
{
    return q148;
}
class hkAabb
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    Q1 m_kMinimumCorner;
};
typedef Q133 Q86;
class Q52
{
  public:
    static const struct Q13 Members[];
    inline Q1& getSeparatingNormal();
    inline void setFlipped(const Q52& point);
    inline void flip();

  protected:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    Q1 q161;
    Q1 InvokeFifthVirtualFunction;
};
inline Q1& Q52::getSeparatingNormal()
{
    return InvokeFifthVirtualFunction;
}
inline void Q52::setFlipped(const Q52& point)
{
    Q1 dist;
    dist.setBroadcast(point.InvokeFifthVirtualFunction, 3);
    q161.setAddMul4(point.q161, point.InvokeFifthVirtualFunction, dist);
    InvokeFifthVirtualFunction.setNeg3(point.InvokeFifthVirtualFunction);
}
inline void Q52::flip()
{
    setFlipped(*this);
}
enum Q36
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
class Q8;
enum hkpBufferSize
{
    HK_SHAPE_BUFFER_SIZE = 512
};
typedef __declspec(align(16)) char Q95[HK_SHAPE_BUFFER_SIZE];
class Q24;
typedef Q49 Q26;
class Q53
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    Q26 q186;
    Q26 q23;
};
class Q124;
class Q70 : public Q16
{
  public:
    static const struct Q13 Members[];
    __forceinline Q36 getType() const;

  protected:
    virtual void CalculateAabb(const Q28& localToWorld, hkReal tolerance, hkAabb& out) const = 0;

  public:
    static void __cdecl resetShapeFunctions();

  public:
  public:
    Q165 m_ulUserData;

  public:
    hkEnum<Q36, Q49> m_type;

  public:
    Q70(class Q35 flag) : Q16(flag)
    {
        if (flag.q151)
        {
            m_type = HK_SHAPE_INVALID;
        }
    }
};
__declspec(align(16)) class Q125 : public Q70
{
    Q125();
};
Q36 Q70::getType() const
{
    return static_cast<const Q125*>(this)->m_type;
}
class Q5
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void* __cdecl operator new(Q3 n, void* p)
    {
        ;
        return p;
    }
    __forceinline Q5()
    {}
    __forceinline const Q28& getTransform() const;
    __forceinline const Q70* getShape() const;
    __forceinline Q26 getShapeKey() const;

  public:
    explicit __forceinline Q5(const Q5* parent);
    __forceinline Q5(const Q5* parent, const Q28* t);
    __forceinline void SetCollisionShapeAndKey(const Q70* shape, Q26 key);
    __forceinline const Q31* GetMotionState() const;

  public:
    const Q70* q130;
    Q26 q101;
    const void* q138;
    const Q5* q196;
};
const Q28& Q5::getTransform() const
{
    ;
    return *static_cast<const Q28*>(q138);
}
const Q31* Q5::GetMotionState() const
{
    return static_cast<const Q31*>(q138);
}
const Q70* Q5::getShape() const
{
    return q130;
}
Q5::Q5(const Q5* parent)
{
    q196 = parent;
    q138 = parent->q138;
}
Q5::Q5(const Q5* parent, const Q28* t)
{
    q196 = parent;
    q138 = t;
}
Q26 Q5::getShapeKey() const
{
    return q101;
}
void Q5::SetCollisionShapeAndKey(const Q70* shape, Q26 key)
{
    q130 = shape;
    q101 = key;
}
struct Q44;
class Q46;
struct Q6;
class Q51;
struct Q12;
class Q48;
struct Q21
{
    Q42 q74;
    Q42 q38;
    Q42 q75;
    Q42 m_iElementCount;
};
typedef void Q10;
struct Q41
{
    Q41() : q156(0)
    {}
    Q20<const Q5*> q72;
    Q20<const Q5*> q65;
    Q20<const Q5*> q156;
    Q20<const Q44*> q34;
    Q20<Q46*> q59;
    Q28 m_kTransform;
};
struct Q14 : public Q41
{
    Q20<hkReal> q162;
    Q1 q76;
};
namespace Q7 {
typedef int AgentType;
enum
{
    MIN_TOTAL_SIZE = 16,
    MAX_MEMORY_INCREASE = 80,
    MAX_TOTAL_SIZE = 128
};
enum StreamCommand
{
    STREAM_NULL = 0,
    STREAM_END = 1,
    STREAM_CALL = 2,
    STREAM_CALL_FLIPPED = 3,
    STREAM_CALL_WITH_TIM = 4,
    STREAM_CALL_WITH_TIM_FLIPPED = 5,
    STREAM_CALL_AGENT = 6,
    TRANSFORM_FLAG = 0x08,
    STREAM_CALL_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL,
    STREAM_CALL_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_FLIPPED,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM,
    STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_WITH_TIM_FLIPPED,
    STREAM_CALL_AGENT_WITH_TRANSFORM = TRANSFORM_FLAG | STREAM_CALL_AGENT,
};
typedef Q10*(__cdecl* CreateFunc)(const Q41& input, Q21* entry, Q10* agentData);
typedef void(__cdecl* DestroyFunc)(Q21* entry, Q10* agentData, Q46* mgr, Q51& constraintOwner, Q8* dispatcher);
typedef Q10*(__cdecl* ProcessFunc)(const Q14& input, Q21* entry, Q10* agentData, Q1* separatingNormalOut, Q6& result);
enum Symmetric
{
    IS_SYMMETRIC,
    IS_NOT_SYMMETRIC,
    IS_NOT_SYMMETRIC_AND_FLIPPED
};
typedef void(__cdecl* SepNormalFunc)(const Q41& input, Q21* entry, Q10* agentData, Q1& separatingNormalOut);
typedef Q10*(__cdecl* CleanupFunc)(Q21* entry, Q10* agentData, Q46* mgr, Q51& constraintOwner);
typedef void(__cdecl* RemovePointFunc)(Q21* entry, Q10* agentData, Q86 idToRemove);
typedef void(__cdecl* CommitPotentialFunc)(Q21* entry, Q10* agentData, Q86 iContactPointId);
typedef void(__cdecl* CreateZombieFunc)(Q21* entry, Q10* agentData, Q86 idTobecomeZombie);
typedef void(__cdecl* UpdateFilterFunc)(Q21* entry, Q10* agentData, const Q5& bodyA, const Q5& bodyB, const Q12& input,
                                        Q46* mgr, Q51& constraintOwner);
typedef void(__cdecl* CalcStatisticsFunc)(Q21* entry, Q10* agentData, const Q12& input, Q67* collector);
typedef void(__cdecl* InvalidateTimFunc)(Q21* entry, Q10* agentData, const Q12& input);
typedef void(__cdecl* WarpTimeFunc)(Q21* entry, Q10* agentData, hkTime oldTime, hkTime newTime, const Q12& input);
}
struct Q61
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal q175;
    Q20<Q134> q79;
    hkBool q174;
    hkReal q116;
};
class Q66;
class Q131;
struct Q12
{
  public:
    hkReal getTolerance() const
    {
        return q187;
    }

  public:
    Q20<Q8*> q176;
    Q20<Q134> q188;
    Q20<hkReal> q187;
    Q20<const Q66*> m_iFilter;
    Q20<const Q131*> q197;
    mutable Q20<Q134> q102;
    struct AabbBoundsAndScale
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q12::AabbBoundsAndScale));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Q1 m_kAabbMin;
        Q1 m_kAabbMaximum;
        Q1 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
class Q87;
class Q39;
class Q80;
struct Q68;
class Q8 : public Q16
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
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        Q16* b = static_cast<Q16*>(Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->q82 = static_cast<Q133>(nbytes);
        ;
        return b;
    }
    typedef Q48*(__cdecl* CreateFunc)(const Q5& collA, const Q5& collB, const Q12& env, Q46* mgr);
    typedef void(__cdecl* GetPenetrationsFunc)(const Q5& bodyA, const Q5& bodyB, const Q12& input, Q80& collector);
    typedef void(__cdecl* GetClosestPointsFunc)(const Q5& bodyA, const Q5& bodyB, const Q12& input, Q39& output);
    typedef void(__cdecl* LinearCastFunc)(const Q5& bodyA, const Q5& bodyB, const Q68& input, Q39& castCollector,
                                          Q39* startCollector);
    struct CollisionAgentFunctionTable
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(CollisionAgentFunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        CreateFunc q146;
        GetPenetrationsFunc q177;
        GetClosestPointsFunc q178;
        LinearCastFunc m_pLinearCastFunc;
        hkBool q189;
        hkBool q96;
        CollisionAgentFunctionTable() : q189(false), q96(false)
        {}
    };
    struct Agent3FunctionTable
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Agent3FunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Agent3FunctionTable() : q96(false), q103(false), q121(false)
        {
            q139 = 0;
            q122 = 0;
            q132 = 0;
            q159 = 0;
            q117 = 0;
        }
        __declspec(align(16)) Q7::CreateFunc q146;
        Q7::DestroyFunc q166;
        Q7::CleanupFunc q167;
        Q7::RemovePointFunc m_pAgentFunction4;
        Q7::CommitPotentialFunc q179;
        Q7::CreateZombieFunc q198;
        Q7::UpdateFilterFunc q139;
        Q7::CalcStatisticsFunc q122;
        Q7::InvalidateTimFunc q132;
        Q7::WarpTimeFunc q159;
        Q7::SepNormalFunc q117;
        Q7::ProcessFunc q168;
        hkBool q96;
        hkBool q103;
        hkBool q121;
    };

  public:
    Q8(CreateFunc defaultCreationFunction, Q87* defaultContactMgrFactory);
    __forceinline Q7::AgentType getAgent3Type(Q36 typeA, Q36 typeB, Q134 predicitve) const;
    __forceinline Q7::CreateFunc getAgent3CreateFunc(Q7::AgentType type);
    __forceinline Q7::DestroyFunc getAgent3DestroyFunc(Q7::AgentType type);
    __forceinline Q7::CleanupFunc getAgent3CleanupFunc(Q7::AgentType type);
    __forceinline Q7::ProcessFunc getAgent3ProcessFunc(Q7::AgentType type);
    __forceinline Q7::SepNormalFunc getAgent3SepNormalFunc(Q7::AgentType type);
    __forceinline Q7::Symmetric getAgent3Symmetric(Q7::AgentType type);

  public:
    struct IntegerPair
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(IntegerPair));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Q36 m_iSecond;
        Q36 m_iFirst;
    };
    struct SymmetricAgent3FunctionTable : public Agent3FunctionTable
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(SymmetricAgent3FunctionTable));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Q7::Symmetric q190;
    };
    struct AgentTypePairPriority
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(AgentTypePairPriority));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
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
    void internalRegisterCollisionAgent(Q42 agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE], int agentType,
                                        Q36 typeA, Q36 typeB, Q36 origA, Q36 origB, DebugTable* debugTable,
                                        int recursionDepth);

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
    Q87* q191[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
    __declspec(align(16)) Q49 q199[HK_MAX_SHAPE_TYPE];
    int m_iEntryCount;
    __declspec(align(16)) Q42 m_agent2TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    Q42 m_agent3TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    CollisionAgentFunctionTable m_agent2Funcs[HK_MAX_AGENT2_TYPES];
    int m_iAgent2FunctionCount;
    __declspec(align(16)) Q42 q169[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    __declspec(align(16)) Q42 q142[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
    SymmetricAgent3FunctionTable q73[HK_MAX_AGENT3_TYPES];

  public:
    hkReal q157;
};
Q7::CreateFunc Q8::getAgent3CreateFunc(Q7::AgentType type)
{
    return q73[type].q146;
}
Q7::DestroyFunc Q8::getAgent3DestroyFunc(Q7::AgentType type)
{
    return q73[type].q166;
}
Q7::CleanupFunc Q8::getAgent3CleanupFunc(Q7::AgentType type)
{
    return q73[type].q167;
}
Q7::ProcessFunc Q8::getAgent3ProcessFunc(Q7::AgentType type)
{
    ;
    return q73[type].q168;
}
Q7::SepNormalFunc Q8::getAgent3SepNormalFunc(Q7::AgentType type)
{
    return q73[type].q117;
}
Q7::Symmetric Q8::getAgent3Symmetric(Q7::AgentType type)
{
    return q73[type].q190;
}
Q7::AgentType Q8::getAgent3Type(Q36 typeA, Q36 typeB, Q134 predictive) const
{
    ;
    ;
    if (predictive)
    {
        return q142[typeA][typeB];
    }
    return q169[typeA][typeB];
}
class Q149
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_fAccumulatedImpulse;
};
class Q111
{
  public:
    static const struct Q13 Members[];

  protected:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    Q113 m_fSlipAngle;
    Q150 q170;

  public:
    Q113 q180;

  public:
    void reset()
    {
        m_fSlipAngle.q152 = 0;
        q180.q152 = 0;
        q170 = 0;
        m_flags = CONTACT_IS_NEW;
    }
    enum FlagEnum
    {
        CONTACT_IS_NEW = 1,
        CONTACT_USES_SOLVER_PATH2 = 2,
        CONTACT_BREAKOFF_OBJECT_ID = 4,
        CONTACT_IS_DISABLED = 8
    };
    Q150 m_flags;
};
class Q97 : public Q149, public Q111
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_uiUserData;
    typedef Q49 UserData;
};
__declspec(align(16)) class Q55 : public Q97
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    UserData q192[7];
};
struct Q40
{
    Q52 q181;
    Q20<Q49> m_usContactPointId;
};
class Q48 : public Q16
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        Q16* b = static_cast<Q16*>(Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->q82 = static_cast<Q133>(nbytes);
        ;
        return b;
    }
    virtual void getPenetrations(const Q5& bodyA, const Q5& bodyB, const Q12& input, Q80& collector) = 0;
    virtual void getClosestPoints(const Q5& bodyA, const Q5& bodyB, const Q12& input, Q39& collector) = 0;
    virtual void linearCast(const Q5& bodyA, const Q5& bodyB, const Q68& input, Q39& castCollector,
                            Q39* startCollector) = 0;

  public:
    virtual void ProcessAgent(const Q5& a, const Q5& b, const Q44& input, Q6& result) = 0;

  protected:
    inline virtual ~Q48();

  protected:
    Q46* q59;

  public:
    inline Q46* getContactMgr();
};
class hkStepInfo
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    __declspec(align(16)) Q20<hkTime> q109;
    Q20<hkTime> q104;
};
struct Q33;
struct Q44 : public Q12
{
  public:
    Q44() : q27(0)
    {}

  public:
    hkStepInfo q64;
    mutable Q20<Q61*> q81;
    mutable Q33* q27;
};
class Q193
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    void init(const Q124* shapeA, const Q124* shapeB, const Q28& btoa);
    inline void flip();
};
__declspec(align(16)) class Q182 : public Q193
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
enum
{
    HK_MAX_CONTACT_POINT = 256
};
struct Q62
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    Q20<Q40*> q47;
    Q20<Q51*> q84;
    Q40 m_akContactPoints[HK_MAX_CONTACT_POINT];
    struct CollisionCacheState
    {
      public:
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q62::CollisionCacheState));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        inline CollisionCacheState();
        inline void flip();

      public:
        Q52 q126;
        Q20<hkReal> m_uiCommandId;
        Q20<hkReal> q183;
        Q182 m_kGskCache;
        Q55 m_kProperties;
    };
    struct CollisionCacheState m_fTimeOfImpact;
};
void Q62::CollisionCacheState::flip()
{
    Q1& norm = q126.getSeparatingNormal();
    norm.setNeg3(norm);
    m_kGskCache.flip();
}
struct Q6 : public Q62
{
  public:
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    struct ContactPointAgentEntry
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q6::ContactPointAgentEntry));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        Q40* q126;
        Q21* q94;
        void* q110;
    };
    struct ContactPointBuffer
    {
        __forceinline void* __cdecl operator new(Q3 nbytes)
        {
            ;
            void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q6::ContactPointBuffer));
            }
        }
        __forceinline void* __cdecl operator new(Q3 n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](Q3, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        void reset()
        {
            q29 = &q9[0];
            q77 = &q105[0];
        }
        ContactPointAgentEntry* q29;
        Q40** q77;
        Q40* q105[HK_MAX_CONTACT_POINT];
        ContactPointAgentEntry q9[HK_MAX_CONTACT_POINT];
    };

  public:
    Q20<ContactPointBuffer*> q9;
};
extern Q15::MemoryState Q140;
__forceinline Q15::MemoryState Q118()
{
    return Q140;
}
__forceinline bool Q93(int id)
{
    bool lowOnMem = Q118() == Q15::MEMORY_STATE_OUT_OF_MEMORY;
    return lowOnMem;
}
namespace Q56 {
void __cdecl ComputeTransformAtTime(const Q45& sweptTrans, hkTime time, Q28& transformOut);
__forceinline void __cdecl calcTimInfo(const Q31& ms0, const Q31& ms1, hkReal deltaTime, Q1& timOut);
}
void __cdecl Q56::calcTimInfo(const Q31& ms0, const Q31& ms1, hkReal deltaTime, Q1& timOut)
{
    const Q45& st0 = ms0.getSweptTransform();
    const Q45& st1 = ms1.getSweptTransform();
    Q1 diff0;
    diff0.setSub4(st0.q115, st0.q90);
    Q1 diff1;
    diff1.setSub4(st1.q90, st1.q115);
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.q145(3) * ms0.q123 + f1 * ms1.q145(3) * ms1.q123;
}
struct Q30;
struct Q18 : Q21
{
    Q53 q69;
};
struct Q2 : Q18
{
    Q49 m_uiEntryValue;
};
struct Q22 : Q18
{
    hkTime q17;
    Q1 InvokeFifthVirtualFunction;
};
struct Q32
{
};
typedef Q10* (*Q78)(Q32& vin, Q18* entry, Q10* agentData);
extern "C"
{
    void __cdecl Q171(Q30& agentTrack);
    enum Q194
    {
        HKP_AGENT_MACHINE_MODE_1N = 1,
        HKP_AGENT_MACHINE_MODE_NM = 2
    };
    void __cdecl Q163(Q30& agentTrack, const Q14& input, const Q24* shapeContainerA, const Q24* shapeCollectionB,
                      const Q53* hitList, Q6& output);
    void __cdecl Q107(Q30& agentTrack, Q32& vin);
    void __cdecl Q108(Q30& agentTrack, Q32& vin);
    void __cdecl Q143(Q30& agentTrack, Q32& vin, Q46* mgr, Q78 visitor);
    void __cdecl Q164(Q30& agentTrack, Q8* dispatch, Q46* mgr, Q51& constraintOwner);
    void __cdecl Q147(Q30& track, const Q12& input);
    void __cdecl Q160(Q30& track, hkTime oldTime, hkTime newTime, const Q12& input);
    void __cdecl Q119(Q41& input, const Q24* shapeCollection, Q6& output);
    Q18* Q158(Q30& agentTrack, Q53 keyPair, Q10** agentDataOut);
}
struct Q33
{
    __forceinline void* __cdecl operator new(Q3 nbytes)
    {
        ;
        void* obj = Q0::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void __cdecl operator delete(void* p)
    {
        if (p)
        {
            ;
            Q0::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Q33));
        }
    }
    enum
    {
        SECTOR_SIZE = 512,
        NET_SECTOR_SIZE = SECTOR_SIZE - 16
    };
    Q49 q71;
    Q49 m_uiStandInValue;
    Q49 m_iValueAfterStandIn;
    Q49 m_pAuxiliaryObject;
    Q150 m_data[512 - 16];
    __forceinline Q10* getBegin()
    {
        return reinterpret_cast<Q10*>(&m_data[0]);
    }
    Q10* GetStreamEnd()
    {
        ;
        return reinterpret_cast<Q10*>(&m_data[q71]);
    }
    Q10* getEndOfCapacity()
    {
        return reinterpret_cast<Q10*>(&m_data[NET_SECTOR_SIZE]);
    }
    int getCapacity()
    {
        return NET_SECTOR_SIZE;
    }
    inline Q33() : q71(0)
    {}
};
struct Q30
{
    Q155<Q33*> q85;
};
namespace Q127 {
__forceinline Q48*& __cdecl getChildAgent(Q10* agentData)
{
    return *reinterpret_cast<Q48**>(agentData);
}
__forceinline Q10* __cdecl getAgentDataEnd(Q10* agentData)
{
    return Q11(agentData, (((sizeof(getChildAgent(agentData))) + ((16) - 1)) & (~((16) - 1))));
}
}
extern "C"
{
    const Q5* __cdecl Q43(const Q5* cdBody, Q5* newCdBodies, class Q31* newMotionStates, int numSlots,
                          Q20<Q42>& cdBodyHasTransformFlag);
}
class Q63
{
  public:
    static const struct Q13 Members[];
    virtual ~Q63()
    {}
};
class Q112
{
  public:
    static const struct Q13 Members[];
};
class Q106
{
  public:
    static const struct Q13 Members[];
    virtual hkBool IsCollisionEnabled(const Q12& input, const Q5& bodyA, const Q5& collectionBodyB,
                                      const Q24& containerShapeB, Q26 keyB) const = 0;
    virtual hkBool IsCollisionEnabled(const Q12& input, const Q5& collectionBodyA, const Q5& collectionBodyB,
                                      const Q24& containerShapeA, const Q24& containerShapeB, Q26 keyA,
                                      Q26 keyB) const = 0;
};
class Q92
{
  public:
    static const struct Q13 Members[];
};
class Q66 : public Q16, public Q63, public Q106, public Q92, public Q112
{
  public:
    static const struct Q13 Members[];

  public:
    Q66();

  public:
    Q49 m_prepad0;
    Q49 m_prepad1;

  public:
    Q66(Q35 flag) : Q16(flag)
    {}
};
class Q24
{
  public:
    static const struct Q13 Members[];
    virtual ~Q24()
    {}
    virtual int GetNumChildShapes() const;
    virtual Q26 GetFirstKey() const = 0;
    virtual Q26 GetNextShapeKey(Q26 oldKey) const = 0;
    virtual Q49 GetFilterInfoForKey(Q26 key) const;
    virtual const Q70* GetShapeForKey(Q26 key, Q95& buffer) const = 0;
    virtual bool isWeldingEnabled() const
    {
        return true;
    }
};
struct Q58
{
    Q5 q72;
    Q5 q65;
    Q28 q172;
    Q28 q173;
};
static __declspec(noinline) void Q54(Q41& in, Q58& bodyTemp, Q41& out)
{
    Q56::ComputeTransformAtTime(in.q72->GetMotionState()->getSweptTransform(), in.q34->q64.q109, bodyTemp.q172);
    Q56::ComputeTransformAtTime(in.q65->GetMotionState()->getSweptTransform(), in.q34->q64.q109, bodyTemp.q173);
    out.q72 = &bodyTemp.q72;
    out.q65 = &bodyTemp.q65;
    out.q59 = in.q59;
    out.q34 = in.q34;
    bodyTemp.q72.SetCollisionShapeAndKey(in.q72->getShape(), in.q72->getShapeKey());
    new (&bodyTemp.q72) Q5(in.q72, &bodyTemp.q172);
    new (&bodyTemp.q65) Q5(in.q65, &bodyTemp.q173);
    out.m_kTransform.SetMulInverse(bodyTemp.q172, bodyTemp.q173);
}
static __declspec(noinline) void Q50(Q14& in, Q14& out)
{
    out.q72 = in.q65;
    out.q65 = in.q72;
    out.q34 = in.q34;
    out.q59 = in.q59;
    out.q76.setNeg3(in.q76);
    out.m_kTransform.SetConjugate(in.m_kTransform);
}
class Q120
{
  public:
    __forceinline bool operator==(const Q53& p)
    {
        return q23 == p.q23;
    }
    __forceinline bool operator>(const Q53& p)
    {
        return q23 > p.q23;
    }
    __forceinline void operator=(const Q53& p)
    {
        q23 = p.q23;
    }
    __forceinline void writeTo(Q53& p)
    {
        p.q186 = 0xffffffff;
        p.q23 = q23;
    }
    Q20<Q26> q23;
};
static __forceinline void extractChildShapes(Q26 key, const Q24* container, Q95& buffer, Q5& childBody)
{
    const Q70* childShape = container->GetShapeForKey(key, buffer);
    childBody.SetCollisionShapeAndKey(childShape, key);
}
static __forceinline void fixupPotentialContactPointers(const Q150* bufferIn, void* bufferOut, int size,
                                                        Q6::ContactPointBuffer* potentialInfo)
{
    if (potentialInfo)
    {
        for (Q6::ContactPointAgentEntry* ref = &potentialInfo->q9[0]; ref < potentialInfo->q29; ref++)
        {
            long offset = Q19(bufferIn, ref->q94);
            if (offset >= 0 && offset < size)
            {
                ref->q94 = reinterpret_cast<Q21*>(Q11(bufferOut, offset));
                ref->q110 = Q11(bufferOut, Q19(bufferIn, ref->q110));
            }
        }
    }
}
// @fnv 0x00da4aa0
void __cdecl FUN_00da4aa0(Q30& agentTrack, const Q14& inputIn, const Q24* shapeContainerB, const Q26* newKeys,
                          Q6& output)
{
    MathUtilities::prefetch128(agentTrack.q85.begin());
    Q6::ContactPointBuffer potentialContacts;
    Q6::ContactPointBuffer* oldPotentialInfo = output.q9;
    if (!oldPotentialInfo && shapeContainerB->isWeldingEnabled())
    {
        potentialContacts.reset();
        output.q9 = &potentialContacts;
    }
    else
    {
        output.q9 = 0;
    }
    Q14 input;
    Q88::memCpy16NonEmpty(&input, &inputIn, sizeof(Q14) / 16);
    Q8* dispatcher = input.q34->q176;
    const int numSlotsForTransformedCdBodies = 4;
    Q31 transformForTransformedShapeB[numSlotsForTransformedCdBodies];
    Q5 cdBodyForTransformedShapeB[numSlotsForTransformedCdBodies];
    Q20<const Q5*>* modifiedBodyBPtr = &input.q65;
    Q20<const Q5*>* modifiedBodyAPtr = &input.q72;
    Q5 childBodyB(inputIn.q65);
    *modifiedBodyBPtr = &childBodyB;
    ;
    int numTim = 0;
    Q33* readSector = agentTrack.q85[0];
    MathUtilities::forcePrefetch<512>(readSector);
    Q33* currentSector = (input.q34->q27) ? input.q34->q27 : new Q33;
    input.q34->q27 = 0;
    int currentSectorIndex = 0;
    bool prevInputInitialized = false;
    bool prevFlippedInputInitialized = false;
    Q41 prevInput;
    Q41 prevFlippedInput;
    Q58 prevTemp;
    Q58 prevFlippedTemp;
    __declspec(align(16)) Q42 extensionBuffer[Q7::MAX_TOTAL_SIZE];
    bool inExtensionBuffer = false;
    int nextReadSectorIndex = 1;
    void* readData = readSector->getBegin();
    void* readEnd = readSector->GetStreamEnd();
    void* currentData = currentSector->getBegin();
    void* currentDataEnd = currentSector->getEndOfCapacity();
    int bytesUsedInCurrentSector = 0;
    Q95 shapeBufferB;
    while (1)
    {
        Q120 shapeKeyPair;
        *modifiedBodyBPtr = &childBodyB;
        input.m_kTransform = inputIn.m_kTransform;
        if (!newKeys)
        {
            Q18* entry = reinterpret_cast<Q18*>(readData);
            int entrySize = entry->m_iElementCount;
            Q88::memCpy16NonEmpty(currentData, readData, entrySize >> 4);
            readData = Q11(readData, entrySize);
            shapeKeyPair = entry->q69;
        }
        else
        {
            Q18* readHeader = reinterpret_cast<Q18*>(readData);
            shapeKeyPair.q23 = *newKeys;
            if (shapeKeyPair == readHeader->q69)
            {
                int size = readHeader->m_iElementCount;
                Q88::memCpy16NonEmpty(currentData, readData, size >> 4);
                readData = Q11(readData, size);
                newKeys++;
            }
            else if (shapeKeyPair > readHeader->q69)
            {
                void* agentData = ((readHeader->q74 & 6) == Q7::STREAM_CALL_WITH_TIM)
                                      ? (void*)Q11(readHeader, sizeof(Q22))
                                      : (void*)Q11(readHeader, sizeof(Q2));
                readData = Q11(readData, readHeader->m_iElementCount);
                dispatcher->getAgent3DestroyFunc(readHeader->q38)(readHeader, agentData, input.q59, *output.q84.val(),
                                                                  dispatcher);
                goto checkReadSector;
            }
            else
            {
                if (input.q34->m_iFilter->IsCollisionEnabled(*input.q34, *inputIn.q72, *inputIn.q65, *shapeContainerB,
                                                             shapeKeyPair.q23))
                {
                    if (Q93(18))
                    {
                        newKeys++;
                        goto checkReadSector;
                    }
                    extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                    const Q70* shapeB = (*modifiedBodyBPtr)->q130;
                    const Q70* shapeA = (*modifiedBodyAPtr)->q130;
                    Q20<Q42> cdBodyHasTransformFlag = 0;
                    *modifiedBodyBPtr =
                        Q43(*modifiedBodyBPtr, cdBodyForTransformedShapeB, transformForTransformedShapeB,
                            numSlotsForTransformedCdBodies, cdBodyHasTransformFlag);
                    shapeB = (*modifiedBodyBPtr)->q130;
                    input.m_kTransform.SetMulInverse((*modifiedBodyAPtr)->getTransform(),
                                                     (*modifiedBodyBPtr)->getTransform());
                    Q18* h = reinterpret_cast<Q18*>(currentData);
                    shapeKeyPair.writeTo(h->q69);
                    h->q38 = Q42(dispatcher->getAgent3Type(shapeA->getType(), shapeB->getType(), input.q34->q102));
                    h->q75 = 0;
                    Q14 flippedInput;
                    Q14* in = &input;
                    int isFlipped = 0;
                    if (dispatcher->getAgent3Symmetric(h->q38) == Q7::IS_NOT_SYMMETRIC_AND_FLIPPED)
                    {
                        isFlipped = 1;
                        in = &flippedInput;
                        Q50(input, flippedInput);
                    }
                    if (dispatcher->getAgent3SepNormalFunc(h->q38))
                    {
                        Q22* entry = reinterpret_cast<Q22*>(currentData);
                        entry->q74 = Q42(Q7::STREAM_CALL_WITH_TIM + isFlipped) | cdBodyHasTransformFlag;
                        entry->q17 = -1.0f;
                        entry->InvokeFifthVirtualFunction.setZero4();
                        void* agentData = entry + 1;
                        void* agentEnd = dispatcher->getAgent3CreateFunc(entry->q38)(*in, entry, agentData);
                        Q165 size = Q19(entry, agentEnd);
                        entry->m_iElementCount = Q42(size);
                        ;
                    }
                    else
                    {
                        Q2* entry = reinterpret_cast<Q2*>(currentData);
                        entry->q74 = Q42(Q7::STREAM_CALL + isFlipped) | cdBodyHasTransformFlag;
                        void* agentData = entry + 1;
                        void* agentEnd = dispatcher->getAgent3CreateFunc(entry->q38)(*in, entry, agentData);
                        Q165 size = Q19(entry, agentEnd);
                        entry->m_iElementCount = Q42(size);
                        ;
                    }
                }
                else
                {
                    Q2* h = reinterpret_cast<Q2*>(currentData);
                    *reinterpret_cast<Q49*>(h) = 0;
                    shapeKeyPair.writeTo(h->q69);
                    h->m_iElementCount = sizeof(Q2);
                }
                newKeys++;
            }
        }
        {
            bool thisChildHasTransformApplied = false;
            Q7::StreamCommand command = Q7::StreamCommand(reinterpret_cast<Q21*>(currentData)->q74);
        commandSwitch:
            switch (command)
            {
            case Q7::STREAM_CALL_WITH_TRANSFORM:
            case Q7::STREAM_CALL_FLIPPED_WITH_TRANSFORM:
            case Q7::STREAM_CALL_WITH_TIM_WITH_TRANSFORM:
            case Q7::STREAM_CALL_WITH_TIM_FLIPPED_WITH_TRANSFORM:
            case Q7::STREAM_CALL_AGENT_WITH_TRANSFORM: {
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                Q20<Q42> dummyCdBodyHasTransformFlag = 0;
                *modifiedBodyBPtr = Q43(*modifiedBodyBPtr, cdBodyForTransformedShapeB, transformForTransformedShapeB,
                                        numSlotsForTransformedCdBodies, dummyCdBodyHasTransformFlag);
                input.m_kTransform.SetMulInverse((*modifiedBodyAPtr)->getTransform(),
                                                 (*modifiedBodyBPtr)->getTransform());
                command = Q7::StreamCommand(Q42(command) & Q42(~Q7::TRANSFORM_FLAG));
                thisChildHasTransformApplied = true;
                prevFlippedInputInitialized = false;
                prevInputInitialized = false;
                goto commandSwitch;
            }
            case Q7::STREAM_CALL_AGENT: {
                Q2* paddedEntry = reinterpret_cast<Q2*>(currentData);
                void* agentData = paddedEntry + 1;
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                Q48* agent = Q127::getChildAgent(agentData);
                agent->ProcessAgent(**modifiedBodyAPtr, **modifiedBodyBPtr, *input.q34, output);
                currentData = Q127::getAgentDataEnd(agentData);
                break;
            }
            case Q7::STREAM_CALL: {
                Q2* entry = reinterpret_cast<Q2*>(currentData);
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                void* agentData = entry + 1;
                currentData = dispatcher->getAgent3ProcessFunc(entry->q38)(input, entry, agentData, 0, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                break;
            }
            case Q7::STREAM_CALL_FLIPPED: {
                Q14 flippedInput;
                Q50(input, flippedInput);
                Q2* entry = reinterpret_cast<Q2*>(currentData);
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                Q40* oldResultBegin = output.q47;
                currentData = dispatcher->getAgent3ProcessFunc(entry->q38)(flippedInput, entry, agentData, 0, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                while (oldResultBegin < output.q47)
                {
                    oldResultBegin->q181.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case Q7::STREAM_CALL_WITH_TIM_FLIPPED: {
                Q14 flippedInput;
                Q50(input, flippedInput);
                Q22* entry = reinterpret_cast<Q22*>(currentData);
                hkReal distAtT1;
                if (entry->q17 != flippedInput.q34->q64.q109)
                {
                    const Q61* ci = flippedInput.q34->q81;
                    if (!ci->q79.val())
                    {
                        entry->q17 = flippedInput.q34->q64.q104;
                        distAtT1 = ci->q116 * 0.5f;
                        entry->InvokeFifthVirtualFunction.setZero4();
                        entry->InvokeFifthVirtualFunction(3) = distAtT1;
                        goto PROCESS_AT_T1_FLIPPED;
                    }
                    if (!prevFlippedInputInitialized)
                    {
                        prevFlippedInputInitialized = !thisChildHasTransformApplied;
                        Q54(flippedInput, prevFlippedTemp, prevFlippedInput);
                        prevFlippedTemp.q65.SetCollisionShapeAndKey(flippedInput.q65->getShape(),
                                                                    flippedInput.q65->q101);
                    }
                    extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                    prevFlippedTemp.q72.SetCollisionShapeAndKey((*modifiedBodyBPtr)->q130, (*modifiedBodyBPtr)->q101);
                    void* agentData = entry + 1;
                    dispatcher->getAgent3SepNormalFunc(entry->q38)(prevFlippedInput, entry, agentData,
                                                                   entry->InvokeFifthVirtualFunction);
                }
                entry->q17 = flippedInput.q34->q64.q104;
                {
                    hkReal worstCaseDeltaDist = flippedInput.q76.dot4xyz1(entry->InvokeFifthVirtualFunction);
                    distAtT1 = entry->InvokeFifthVirtualFunction(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= flippedInput.q34->getTolerance())
                {
                    entry->InvokeFifthVirtualFunction(3) = distAtT1;
                    if (!entry->q75)
                    {
                        currentData = Q11(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = dispatcher->getAgent3CleanupFunc(entry->q38)(entry, agentData, flippedInput.q59,
                                                                                   *output.q84.val());
                        entry->m_iElementCount = Q42(Q19(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1_FLIPPED:
                flippedInput.q162 = distAtT1;
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                Q40* oldResultBegin = output.q47;
                hkReal oldToi = output.m_fTimeOfImpact.m_uiCommandId;
                void* agentData = entry + 1;
                currentData = dispatcher->getAgent3ProcessFunc(entry->q38)(flippedInput, entry, agentData,
                                                                           &entry->InvokeFifthVirtualFunction, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                while (oldResultBegin < output.q47)
                {
                    oldResultBegin->q181.flip();
                    oldResultBegin++;
                }
                if (oldToi != output.m_fTimeOfImpact.m_uiCommandId)
                {
                    output.m_fTimeOfImpact.flip();
                }
                break;
            }
            case Q7::STREAM_CALL_WITH_TIM: {
                Q22* entry = reinterpret_cast<Q22*>(currentData);
                hkReal distAtT1;
                if (entry->q17 != input.q34->q64.q109)
                {
                    if (entry->q17 >= input.q34->q64.q104)
                    {
                        hkReal backDt = entry->q17 - input.q34->q64.q104;
                        Q1 backTim;
                        Q56::calcTimInfo(*input.q72->GetMotionState(), *input.q65->GetMotionState(), backDt, backTim);
                        hkReal backLinear = backTim.dot3(entry->InvokeFifthVirtualFunction);
                        hkReal backAng = backTim(3);
                        distAtT1 = entry->InvokeFifthVirtualFunction(3) + backLinear - backAng;
                    }
                    else
                    {
                        const Q61* ci = input.q34->q81;
                        if (!ci->q79.val())
                        {
                            entry->q17 = input.q34->q64.q104;
                            distAtT1 = ci->q116 * 0.1f;
                            entry->InvokeFifthVirtualFunction.setZero4();
                            entry->InvokeFifthVirtualFunction(3) = distAtT1;
                            goto PROCESS_AT_T1;
                        }
                        if (!prevInputInitialized)
                        {
                            prevInputInitialized = !thisChildHasTransformApplied;
                            Q54(input, prevTemp, prevInput);
                        }
                        extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                        prevTemp.q65.SetCollisionShapeAndKey((*modifiedBodyBPtr)->q130, (*modifiedBodyBPtr)->q101);
                        void* agentData = entry + 1;
                        dispatcher->getAgent3SepNormalFunc(entry->q38)(prevInput, entry, agentData,
                                                                       entry->InvokeFifthVirtualFunction);
                    }
                }
                entry->q17 = input.q34->q64.q104;
                {
                    hkReal worstCaseDeltaDist = input.q76.dot4xyz1(entry->InvokeFifthVirtualFunction);
                    distAtT1 = entry->InvokeFifthVirtualFunction(3) - worstCaseDeltaDist;
                }
                if (distAtT1 >= input.q34->getTolerance())
                {
                    entry->InvokeFifthVirtualFunction(3) = distAtT1;
                    if (!entry->q75)
                    {
                        currentData = Q11(currentData, entry->m_iElementCount);
                    }
                    else
                    {
                        void* agentData = entry + 1;
                        currentData = dispatcher->getAgent3CleanupFunc(entry->q38)(entry, agentData, input.q59,
                                                                                   *output.q84.val());
                        entry->m_iElementCount = Q42(Q19(entry, currentData));
                    }
                    numTim++;
                    break;
                }
            PROCESS_AT_T1:
                input.q162 = distAtT1;
                extractChildShapes(shapeKeyPair.q23, shapeContainerB, shapeBufferB, childBodyB);
                void* agentData = entry + 1;
                currentData = dispatcher->getAgent3ProcessFunc(entry->q38)(input, entry, agentData,
                                                                           &entry->InvokeFifthVirtualFunction, output);
                entry->m_iElementCount = Q42(Q19(entry, currentData));
                break;
            }
            case Q7::STREAM_NULL: {
                currentData = Q11(currentData, sizeof(Q2));
                break;
            }
            case Q7::STREAM_END: {
                currentData = Q11(currentData, sizeof(Q2));
                break;
            }
            default:;
            }
        }
    checkReadSector:;
        if (readData == readEnd)
        {
            if (input.q34->q27)
            {
                delete readSector;
            }
            else
            {
                input.q34->q27 = readSector;
            }
            if (nextReadSectorIndex < agentTrack.q85.GetLogicalSize())
            {
                readSector = agentTrack.q85[nextReadSectorIndex];
                readData = readSector->getBegin();
                readEnd = readSector->GetStreamEnd();
                nextReadSectorIndex++;
            }
            else
            {
                break;
            };
        }
        if (Q11(currentData, Q7::MAX_TOTAL_SIZE) <= currentDataEnd)
        {
            continue;
        }
        if (!inExtensionBuffer)
        {
            inExtensionBuffer = true;
            bytesUsedInCurrentSector = Q19(currentSector->getBegin(), currentData);
            ;
            currentData = extensionBuffer;
            currentDataEnd = Q11(extensionBuffer, Q7::MAX_TOTAL_SIZE);
            continue;
        }
        int bytesUsedInExtensionBuffer;
        bytesUsedInExtensionBuffer = Q19(extensionBuffer, currentData);
        {
            int freeBytes = currentSector->getCapacity() - bytesUsedInCurrentSector;
            if (bytesUsedInExtensionBuffer <= freeBytes)
            {
                void* dst = Q11(currentSector->getBegin(), bytesUsedInCurrentSector);
                Q88::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
                bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
                fixupPotentialContactPointers(extensionBuffer, dst, bytesUsedInExtensionBuffer, output.q9);
                if (bytesUsedInCurrentSector < currentSector->getCapacity())
                {
                    currentData = extensionBuffer;
                    continue;
                }
                inExtensionBuffer = false;
                currentData = 0;
                currentDataEnd = 0;
            }
        }
        currentSector->q71 = bytesUsedInCurrentSector;
        if (currentSectorIndex >= nextReadSectorIndex)
        {
            agentTrack.q85.expandAt(nextReadSectorIndex, 1);
            nextReadSectorIndex++;
        }
        agentTrack.q85[currentSectorIndex] = currentSector;
        ;
        currentSectorIndex++;
        currentSector = (input.q34->q27) ? input.q34->q27 : new Q33;
        input.q34->q27 = 0;
        currentData = currentSector->getBegin();
        currentDataEnd = currentSector->getEndOfCapacity();
        if (inExtensionBuffer)
        {
            Q88::memCpy16NonEmpty(currentData, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
            fixupPotentialContactPointers(extensionBuffer, currentData, bytesUsedInExtensionBuffer, output.q9);
            currentData = Q11(currentData, bytesUsedInExtensionBuffer);
            inExtensionBuffer = false;
        }
    }
    if (!inExtensionBuffer)
    {
        bytesUsedInCurrentSector = Q19(currentSector->getBegin(), currentData);
    }
    else
    {
        int bytesUsedInExtensionBuffer = Q19(extensionBuffer, currentData);
        ;
        void* dst = Q11(currentSector->getBegin(), bytesUsedInCurrentSector);
        Q88::memCpy16NonEmpty(dst, extensionBuffer, bytesUsedInExtensionBuffer >> 4);
        Q6::ContactPointBuffer* potentialInfo = output.q9;
        if (potentialInfo)
        {
            if (potentialInfo->q29 > &potentialInfo->q9[0])
            {
                Q6::ContactPointAgentEntry* lastContactRef = potentialInfo->q29 - 1;
                long offsetInExtensionBuffer = Q19(extensionBuffer, lastContactRef->q94);
                if (offsetInExtensionBuffer >= 0 && offsetInExtensionBuffer < bytesUsedInExtensionBuffer)
                {
                    ;
                    lastContactRef->q94 = reinterpret_cast<Q21*>(Q11(dst, offsetInExtensionBuffer));
                    lastContactRef->q110 = Q11(dst, Q19(extensionBuffer, lastContactRef->q110));
                }
            }
        }
        bytesUsedInCurrentSector += bytesUsedInExtensionBuffer;
    };
    currentSector->q71 = bytesUsedInCurrentSector;
    agentTrack.q85.SetSizeAndGrow(currentSectorIndex + 1);
    agentTrack.q85[currentSectorIndex] = currentSector;
    ;
    {
        Q37& mStream = Q37::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            Q37::CommandFilterEntry* h = reinterpret_cast<Q37::CommandFilterEntry*>(mStream.GetStreamEnd());
            h->q129 = "M"
                      "i"
                      "numTim";
            h->q152 = float(numTim);
            mStream.setEnd((char*)(h + 1));
        }
    };
    ;
    input.q65 = inputIn.q65;
    input.m_kTransform = inputIn.m_kTransform;
    if (output.q9)
    {
        if (output.q9->q29 > &output.q9->q9[0])
        {
            Q119(input, shapeContainerB, output);
        }
    }
    output.q9 = oldPotentialInfo;
}
}  // namespace fnv_00da4aa0
