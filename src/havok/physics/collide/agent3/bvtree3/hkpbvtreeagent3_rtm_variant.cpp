// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/bvtree3/hkpbvtreeagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void* __cdecl InitAndReturnTail(void*, void*, void*);
void __fastcall FUN_00d2d890(void* self, int, void*, int);
void __fastcall CallWithValueSource(void* self, int, int, int);
void __fastcall FUN_00d2d430(void* self, int, int, int);
void __fastcall FUN_00d2d480(void* self, int, int, int);
void FUN_00d2d9d0(void* pObject);
extern "C" void __cdecl FUN_00da35f0(void*, float, float, int);
void __cdecl FUN_00d2d480(void*, void* target, float first, float second, int flags);
struct Interface
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
void FUN_00d2d4b0(Interface** a);
struct LessU32
{
    int pad;
    bool operator()(unsigned a, unsigned b) const
    {
        return a < b;
    }
};
// Partitions pArr[d..h] around a middle pivot using cmpLess, swapping out-of-order elements, then recurses on the left part and loops on the right.
// @fnv 0x00d2da70
extern "C" void __cdecl QuickSortRange(unsigned* auiArray, int aiLow, int aiHigh, LessU32 aComparator)
{
setpoint:
    int iRight = aiHigh;
    int iLeft = aiLow;
    __declspec(align(16)) unsigned pivot = auiArray[(aiLow + aiHigh) >> 1];
    do
    {
        while (aComparator(auiArray[iLeft], pivot))
            iLeft++;
        while (aComparator(pivot, auiArray[iRight]))
            iRight--;
        if (iRight >= iLeft)
        {
            if (iRight != iLeft)
            {
                unsigned t = auiArray[iRight];
                auiArray[iRight] = auiArray[iLeft];
                auiArray[iLeft] = t;
            }
            iRight--;
            iLeft++;
        }
    } while (iLeft <= iRight);
    if (aiLow < iRight)
        QuickSortRange(auiArray, aiLow, iRight, aComparator);
    if (iLeft < aiHigh)
    {
        aiLow = iLeft;
        goto setpoint;
    }
}
struct ValueSource
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};
struct CallBuf
{
    int unk00;
    ValueSource** unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
void __cdecl FUN_00da48e0(void* a, void* b);
void __cdecl CallWithValueSource(void* apUnused, void* p2, int aiArg0, ValueSource** apValueSource, int aiArg1,
                                 int aiArg2, int aiArg3);
struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int m_kind;            // 0x0c
    unsigned char m_flag;  // 0x10
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    void* m_ptr18;  // 0x18
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_ptr34;  // 0x34
};
void* __cdecl GetSpawnedObjectPointer(void** holder);
struct Agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char* typeName);
    virtual void f7();
};
extern "C" void __cdecl FUN_00d97250(int, int, void*);
extern "C" void __cdecl FUN_00da3510(int, int);
void __cdecl FUN_00d2d430(int a1, int a2, int a3, Agent* p);
void __cdecl FUN_00d2d460(int a, int b, int c)
{
    FUN_00da3510(b, c);
}
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" const char str_010ce7ec[];
extern "C" const char str_010ce7e0[];
extern "C" const char str_010ce7d4[];
extern "C" const char str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct S00d2d890_Rec
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
    const char* tag;
};
struct S00d2d890_Buf
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct __declspec(align(16)) S00d2d890_Local
{
    int b00;
    int b01;
    int b02;
    int b03;
    int b04;
    int b05;
    int b06;
    int b07;
    int b08;
    int b09;
    int b0a;
    int b0b;
    int b0c;
    int b0d;
    int b0e;
    int b0f;
    S00d2d890_Local()
    {}
    void FUN_00cb21e0(void* a);
};
struct S00d2d890_Hits
{
    int q000;
    int q001;
    int q002;
    int q003;
    int q004;
    int q005;
    int q006;
    int q007;
    int q008;
    int q009;
    int q00a;
    int q00b;
    int q00c;
    int q00d;
    int q00e;
    int q00f;
    int q010;
    int q011;
    int q012;
    int q013;
    int q014;
    int q015;
    int q016;
    int q017;
    int q018;
    int q019;
    int q01a;
    int q01b;
    int q01c;
    int q01d;
    int q01e;
    int q01f;
    int q020;
    int q021;
    int q022;
    int q023;
    int q024;
    int q025;
    int q026;
    int q027;
    int q028;
    int q029;
    int q02a;
    int q02b;
    int q02c;
    int q02d;
    int q02e;
    int q02f;
    int q030;
    int q031;
    int q032;
    int q033;
    int q034;
    int q035;
    int q036;
    int q037;
    int q038;
    int q039;
    int q03a;
    int q03b;
    int q03c;
    int q03d;
    int q03e;
    int q03f;
    int q040;
    int q041;
    int q042;
    int q043;
    int q044;
    int q045;
    int q046;
    int q047;
    int q048;
    int q049;
    int q04a;
    int q04b;
    int q04c;
    int q04d;
    int q04e;
    int q04f;
    int q050;
    int q051;
    int q052;
    int q053;
    int q054;
    int q055;
    int q056;
    int q057;
    int q058;
    int q059;
    int q05a;
    int q05b;
    int q05c;
    int q05d;
    int q05e;
    int q05f;
    int q060;
    int q061;
    int q062;
    int q063;
    int q064;
    int q065;
    int q066;
    int q067;
    int q068;
    int q069;
    int q06a;
    int q06b;
    int q06c;
    int q06d;
    int q06e;
    int q06f;
    int q070;
    int q071;
    int q072;
    int q073;
    int q074;
    int q075;
    int q076;
    int q077;
    int q078;
    int q079;
    int q07a;
    int q07b;
    int q07c;
    int q07d;
    int q07e;
    int q07f;
};
struct S00d2d890_Rec3
{
    const char* name;
    unsigned int stamp;
    unsigned int unk08;
};
struct S00d2d890_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
char** FUN_00c85750();
int FUN_00d2d4f0(int a, int b, S00d2d890_Local* l, void* c, int d, int e, char* f, int g);
int FUN_00d2d4b0(int a, S00d2d890_Hits* h);
int FUN_00da4aa0(int a, void* b, int c, char* d, int e);
char* __cdecl FUN_00d2d890(char* self, int a1, char* child, int a3, int a4);
struct FUN_00cfbd60_Obj
{
    void AddEntry(void* a1, int a2, int a3);
};
__declspec(noinline) void FUN_00d2d9d0(void* pObject);
struct __declspec(align(16)) S_00d2da20_AgentFuncs
{
    void* m_pCreateFunc;
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
    void* unk2C;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
    bool unk32;
    S_00d2da20_AgentFuncs()
    {
        m_bIsFlipped = false;
        m_bIsPredictive = false;
        unk32 = false;
        unk18 = 0;
        unk1C = 0;
        unk20 = 0;
        unk24 = 0;
        unk28 = 0;
    }
};
void FUN_00d2da20(FUN_00cfbd60_Obj* target);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
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
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    hkEnum(ENUM e)
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
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
    Allocator* m_pDebugAllocator;
    Allocator* m_pSolver;
};
class hkBaseObject
{
  public:
    static const struct ClassMemberDescriptor Members[];
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
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
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
struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get(const void*)
    {
        return NineIntegerRecord::GetMonitorStream().heap();
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
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmple_ps(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
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
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;
class Vector4Comparison;
typedef const Vector4Comparison& hkVector4ComparisonParameter;
class Vector4Comparison
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_X = 1,
        MASK_Y = 2,
        MASK_XY = 3,
        MASK_Z = 4,
        MASK_XZ = 5,
        MASK_YZ = 6,
        MASK_XYZ = 7,
        MASK_W = 8,
        MASK_XW = 9,
        MASK_YW = 10,
        MASK_XYW = 11,
        MASK_ZW = 12,
        MASK_XZW = 13,
        MASK_YZW = 14,
        MASK_XYZW = 15
    };
    __forceinline void setAnd(hkVector4ComparisonParameter a, hkVector4ComparisonParameter b)
    {
        m_uiMask = _mm_and_ps(a.m_uiMask, b.m_uiMask);
    }
    __forceinline hkBool32 allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(m_uiMask) & m) == m;
    }

  private:
    hkQuadReal m_uiMask;
    friend class hkVector4;
};
namespace MathUtilities {
template <typename T> inline T __cdecl min2(T x, T y)
{
    return x < y ? x : y;
}
}
class hkRotation;
class hkTransform;
class hkVector4
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void operator=(const hkVector4& v);
    __forceinline void setAll3(hkReal x);
    __forceinline void setZero4();
    __forceinline void add4(const hkVector4& a);
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b);
    __forceinline void sub4(const hkVector4& a);
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b);
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
    __forceinline void setCross(const hkVector4& a, const hkVector4& b);
    __forceinline Vector4Comparison compareLessThanEqual4(hkVector4Parameter a) const;
    __forceinline void setNeg4(const hkVector4& v);
    __forceinline void setMin4(const hkVector4& a, const hkVector4& b);
    __forceinline void setMax4(const hkVector4& a, const hkVector4& b);
    __forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4& b);
    __forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline const hkQuadReal& getQuad() const;

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
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
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
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline const hkVector4& getColumn(int i) const;

  protected:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
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
class hkTransform
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline const hkVector4& getTranslation() const;
    __forceinline const hkRotation& getRotation() const;

  private:
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};
class hkSweptTransform
{
  public:
    static const struct ClassMemberDescriptor Members[];

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
inline const hkQuadReal& hkVector4::getQuad() const
{
    return m_vComponents;
}
inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::setAll3(hkReal a)
{
    m_vComponents = _mm_set_ps1(a);
}
inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4::sub4(const hkVector4& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    hkQuadReal cross0;
    cross0 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))));
    hkQuadReal cross1;
    cross1 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
inline Vector4Comparison hkVector4::compareLessThanEqual4(const hkVector4& a) const
{
    Vector4Comparison m;
    m.m_uiMask = _mm_cmple_ps(m_vComponents, a.m_vComponents);
    return m;
}
extern __declspec(align(16)) const hkUint32 DAT_010c44d0[4];
inline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&DAT_010c44d0);
}
inline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad());
}
inline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_max_ps(a.getQuad(), b.getQuad());
}
inline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, (((3) << 6) | ((2) << 4) | ((1) << 2) | ((0))));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, (((3) << 6) | ((1) << 4) | ((1) << 2) | ((0))));
        c2 = _ctmp;
    };
    const hkQuadReal b0 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
inline void hkVector4::_setTransformedInversePos(const hkTransform& a, const hkVector4& b)
{
    hkVector4 t0;
    t0.setSub4(b, a.getTranslation());
    _setRotatedInverseDir(a.getRotation(), t0);
}
inline const hkReal& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
const hkVector4& hkTransform::getTranslation() const
{
    return m_vTranslation;
}
const hkRotation& hkTransform::getRotation() const
{
    return m_rotation;
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}
class hkMotionState
{
  public:
    static const struct ClassMemberDescriptor Members[];
    inline const hkSweptTransform& getSweptTransform() const;

  protected:
    hkTransform m_kMotionTransform;
    class hkSweptTransform m_kSweptTransform;

  public:
    hkVector4 m_kDeltaAngle;
    hkReal m_fObjectRadius;
};
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}
class hkAabb
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline hkBool contains(const hkAabb& other) const;

  public:
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
hkBool hkAabb::contains(const hkAabb& other) const
{
    Vector4Comparison mincomp = m_kMinimumCorner.compareLessThanEqual4(other.m_kMinimumCorner);
    Vector4Comparison maxcomp = other.m_kMaximumCorner.compareLessThanEqual4(m_kMaximumCorner);
    Vector4Comparison both;
    both.setAnd(mincomp, maxcomp);
    return both.allAreSet(Vector4Comparison::MASK_XYZ) != 0;
}
typedef hkUint16 hkContactPointId;
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
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class hkpShape : public hkReferencedObject
{
  public:
    static const struct ClassMemberDescriptor Members[];
    __forceinline void getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
    virtual hkReal getMaximumProjection(const hkVector4& direction) const;
    virtual const hkpShapeContainer* GetShapeContainer() const
    {
        return 0;
    }
    virtual bool isConvex() const
    {
        return false;
    }
    struct PhysicsShape
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
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(hkpShape::PhysicsShape));
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
        bool m_bIsConvex;
        bool m_bIsConvexPiece;
        bool m_bIsComposite;
    };
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;

  protected:
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const = 0;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const = 0;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const = 0;
    virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& output,
                                            hkVector4ComparisonParameter mask) const;

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
void hkpShape::getAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    CalculateAabb(localToWorld, tolerance, out);
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
    __forceinline const hkTransform& getTransform() const;
    __forceinline const hkpShape* getShape() const;

  public:
    explicit __forceinline hkpCdBody(const hkpCdBody* parent);
    __forceinline const hkMotionState* GetMotionState() const;

  public:
    const hkpShape* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
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
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct CollisionAgentContext;
class hkpCollisionAgent;
struct FourByteState
{
};
typedef void hkpAgentData;
struct AgentProcessingInput
{
};
struct AgentSubtypeMarker : public AgentProcessingInput
{
};
namespace hkAgent3 {
typedef hkpAgentData*(__cdecl* CreateFunc)(const AgentProcessingInput& input, FourByteState* entry,
                                           hkpAgentData* agentData);
typedef void(__cdecl* DestroyFunc)(FourByteState* entry, hkpAgentData* agentData, hkpContactMgr* mgr,
                                   hkpConstraintOwner& constraintOwner, hkpCollisionDispatcher* dispatcher);
typedef hkpAgentData*(__cdecl* ProcessFunc)(const AgentSubtypeMarker& input, FourByteState* entry,
                                            hkpAgentData* agentData, hkVector4* separatingNormalOut,
                                            WorldOperationEntry& result);
typedef void(__cdecl* SepNormalFunc)(const AgentProcessingInput& input, FourByteState* entry, hkpAgentData* agentData,
                                     hkVector4& separatingNormalOut);
typedef hkpAgentData*(__cdecl* CleanupFunc)(FourByteState* entry, hkpAgentData* agentData, hkpContactMgr* mgr,
                                            hkpConstraintOwner& constraintOwner);
typedef void(__cdecl* RemovePointFunc)(FourByteState* entry, hkpAgentData* agentData, hkContactPointId idToRemove);
typedef void(__cdecl* CommitPotentialFunc)(FourByteState* entry, hkpAgentData* agentData,
                                           hkContactPointId iContactPointId);
typedef void(__cdecl* CreateZombieFunc)(FourByteState* entry, hkpAgentData* agentData,
                                        hkContactPointId idTobecomeZombie);
typedef void(__cdecl* UpdateFilterFunc)(FourByteState* entry, hkpAgentData* agentData, const hkpCdBody& bodyA,
                                        const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpContactMgr* mgr,
                                        hkpConstraintOwner& constraintOwner);
typedef void(__cdecl* CalcStatisticsFunc)(FourByteState* entry, hkpAgentData* agentData,
                                          const CollisionAgentContext& input, hkStatisticsCollector* collector);
typedef void(__cdecl* InvalidateTimFunc)(FourByteState* entry, hkpAgentData* agentData,
                                         const CollisionAgentContext& input);
typedef void(__cdecl* WarpTimeFunc)(FourByteState* entry, hkpAgentData* agentData, hkTime oldTime, hkTime newTime,
                                    const CollisionAgentContext& input);
}
struct CollisionQualityInfo
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal m_fTimeOfImpactSeparation;
    ValueWrapper<hkBool32> m_iQualityInfoValue10;
};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
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
    struct AabbBoundsAndScale
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
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(
                    p, sizeof(CollisionAgentContext::AabbBoundsAndScale));
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
        hkVector4 m_kAabbMin;
        hkVector4 m_kAabbMaximum;
        hkVector4 m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
class hkpContactMgrFactory;
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
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    typedef hkpCollisionAgent*(__cdecl* CreateFunc)(const hkpCdBody& collA, const hkpCdBody& collB,
                                                    const CollisionAgentContext& env, hkpContactMgr* mgr);
    struct Agent3FunctionTable
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
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(Agent3FunctionTable));
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
    struct DebugTable;

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

  public:
    hkReal m_fExpectedMaxLinearVelocity;
};
class hkStepInfo
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    __declspec(align(16)) ValueWrapper<hkTime> m_uiStartTime;
    ValueWrapper<hkTime> m_fEndTime;
    ValueWrapper<hkReal> m_fTimeStep;
};
struct hkpAgent1nSector;
struct GskAgentInput : public CollisionAgentContext
{
  public:
    GskAgentInput() : m_pAgent1nSector(0)
    {}

  public:
    hkStepInfo m_pStepInfo;
    mutable ValueWrapper<CollisionQualityInfo*> m_pCollisionQualityInfo;
    mutable hkpAgent1nSector* m_pAgent1nSector;
};
class hkpShapeContainer
{
  public:
    static const struct ClassMemberDescriptor Members[];
};
class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    hkBool m_bDisableWelding;
};
namespace hkBvTreeAgent3 {
hkpAgentData* __cdecl process(const AgentSubtypeMarker& input, FourByteState* entry, hkpAgentData* agentData,
                              hkVector4* separatingNormal, WorldOperationEntry& result);
void __cdecl RegisterAgentFunctions(hkpCollisionDispatcher* dispatcher);
void __cdecl InitAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable& f);
void __cdecl CleanupAgent(FourByteState* entry, hkpAgentData* agentData, const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                          const CollisionAgentContext& input, hkpContactMgr* mgr, hkpConstraintOwner& constraintOwner);
void __cdecl AddStat(FourByteState* entry, hkpAgentData* agentData, const CollisionAgentContext& input,
                     hkStatisticsCollector* collector);
void __cdecl RemovePoint(FourByteState* entry, hkpAgentData* agentData, const CollisionAgentContext& input);
void __cdecl WarpTime(FourByteState* entry, hkpAgentData* agentData, hkTime oldTime, hkTime newTime,
                      const CollisionAgentContext& input);

const hkpShapeContainer* __cdecl GetContainerFromBody(const hkpCdBody* body, hkpShapeBuffer& buffer);
const hkpShapeCollection* __cdecl GetCollectionFromBody(const hkpCdBody* body,
                                                                                hkpShapeBuffer& buffer);
}
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
    virtual void GetObbHits(const hkTransform& obbTransform, const hkVector4& obbExtent, hkReal tolerance,
                            hkArray<hkpShapeKey>& hits) const = 0;
    virtual void GetAabbHits(const hkAabb& aabb, hkArray<hkpShapeKey>& hits) const = 0;
    __forceinline hkUint32 GetAabbHits(const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys) const;
    virtual hkUint32 GetAabbHitsToBuffer(const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys) const = 0;

  public:
    hkEnum<BvTreeType, hkUint8> m_uiUserData;
};
inline hkUint32 hkpBvTreeShape::GetAabbHits(const hkAabb& aabb, hkpShapeKey* hits, int maxNumKeys) const
{
    return GetAabbHitsToBuffer(aabb, hits, maxNumKeys);
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
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& bodyA,
                                      const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB,
                                      hkpShapeKey keyB) const = 0;
    virtual hkBool IsCollisionEnabled(const CollisionAgentContext& input, const hkpCdBody& collectionBodyA,
                                      const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA,
                                      const hkpShapeContainer& containerShapeB, hkpShapeKey keyA,
                                      hkpShapeKey keyB) const = 0;
    virtual int FilterAabb(const CollisionAgentContext& input, const hkpCdBody& bodyA,
                                             const hkpCdBody& bodyB, const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb,
                                             hkpShapeKey* shapeKeysInOut, int shapeKeysCapacity) const = 0;
};
class hkpRayShapeCollectionFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];
};
class hkpCollisionFilter : public hkReferencedObject,
                           public hkpCollidableCollidableFilter,
                           public hkpShapeCollectionFilter,
                           public hkpRayShapeCollectionFilter,
                           public hkpRayCollidableFilter
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    hkpCollisionFilter();

  public:
    hkUint32 m_prepad0;
    hkUint32 m_prepad1;

  public:
    hkpCollisionFilter(FinishingFlag flag) : hkReferencedObject(flag)
    {}
};
namespace AlgorithmUtilities {
template <typename T> class less
{
  public:
    __forceinline hkBool32 operator()(const T& a, const T& b)
    {
        return (a < b);
    }
};
template <typename T> __forceinline void __cdecl quickSort(T* pArr, int iSize)
{
    quickSort(pArr, iSize, less<T>());
}
template <typename T, typename L> void __cdecl QuickSortSubrange(T* pArr, int d, int h, L cmpLess);
}
namespace AlgorithmUtilities {
template <typename T, typename L> void __cdecl quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1)
    {
        int low = 0;
        int high = iSize - 1;
        QuickSortSubrange(pArr, low, high, cmpLess);
    }
}
}
// @fnv 0x00d2d4f0
int __cdecl FUN_00d2d4f0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const hkTransform& bTa,
                         const hkVector4& linearTimInfo, const GskAgentInput& input, hkAabb* cachedAabb,
                         hkpShapeKey* hitListOut, int hitListCapacity)
{
    hkAabb aabb;
    int numHits;
    {
        const hkMotionState* msA = bodyA.GetMotionState();
        const hkMotionState* msB = bodyB.GetMotionState();
        hkVector4 timInfo;
        timInfo._setRotatedInverseDir(bodyB.getTransform().getRotation(), linearTimInfo);
        hkVector4 aabbExtents;
        if (input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
        {
            const hkReal secOrdErrA = (msA->m_kDeltaAngle(3) + msB->m_kDeltaAngle(3)) * msA->m_fObjectRadius;
            const hkReal secOrdErrB = msB->m_kDeltaAngle(3) * msB->m_kDeltaAngle(3) * msB->m_fObjectRadius;
            const hkReal checkEpsilon = input.m_fScalar * 0.5f + (secOrdErrA + secOrdErrB);
            bodyA.getShape()->getAabb(bTa, checkEpsilon, aabb);
            hkVector4 massCenterAinB;
            {
                hkVector4 radius4;
                radius4.setAll3(input.m_fScalar * 0.5f + msA->m_fObjectRadius + secOrdErrB);
                massCenterAinB._setTransformedInversePos(bodyB.getTransform(),
                                                         msA->getSweptTransform().m_vCenterOfMass1);
                hkVector4 maxR;
                maxR.setAdd4(massCenterAinB, radius4);
                hkVector4 minR;
                minR.setSub4(massCenterAinB, radius4);
                aabb.m_kMinimumCorner.setMax4(aabb.m_kMinimumCorner, minR);
                aabb.m_kMaximumCorner.setMin4(aabb.m_kMaximumCorner, maxR);
            }
            aabbExtents.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
            {
                if (msB->m_kDeltaAngle(3) > 0.0f)
                {
                    hkVector4 relPos;
                    relPos.setSub4(massCenterAinB, msB->getSweptTransform().m_vCenterOfMassLocal);
                    hkVector4 offsetOut;
                    offsetOut.setCross(relPos, msB->m_kDeltaAngle);
                    hkReal f = input.m_pStepInfo.m_fTimeStep * msB->getSweptTransform().getInvDeltaTime();
                    timInfo.addMul4(f, offsetOut);
                }
                hkVector4 zero;
                zero.setZero4();
                hkVector4 minPath;
                minPath.setMin4(zero, timInfo);
                hkVector4 maxPath;
                maxPath.setMax4(zero, timInfo);
                aabb.m_kMinimumCorner.add4(minPath);
                aabb.m_kMaximumCorner.add4(maxPath);
            }
        }
        else
        {
            const hkReal checkEpsilon = input.m_fScalar * 0.5f;
            bodyA.getShape()->getAabb(bTa, checkEpsilon, aabb);
            aabbExtents.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
        }
        if (cachedAabb)
        {
            if (cachedAabb->contains(aabb))
            {
                return -1;
            }
            {
                hkVector4 zero;
                zero.setZero4();
                hkVector4 minPath;
                minPath.setMin4(zero, timInfo);
                hkVector4 maxPath;
                maxPath.setMax4(zero, timInfo);
                hkVector4 expand4;
                expand4.setAll3(input.m_fScalar * 0.5f);
                aabb.m_kMinimumCorner.sub4(expand4);
                aabb.m_kMaximumCorner.add4(expand4);
                const hkReal maxExpand = 0.4f;
                const hkReal framesLookAhead = -2.0f;
                hkVector4 minExtentPath;
                minExtentPath.setMul4(framesLookAhead, maxPath);
                hkVector4 maxExtentPath;
                maxExtentPath.setMul4(framesLookAhead, minPath);
                hkVector4 maxExpand4;
                maxExpand4.setMul4(maxExpand, aabbExtents);
                maxExtentPath.setMin4(maxExtentPath, maxExpand4);
                hkVector4 minExpand4;
                minExpand4.setNeg4(maxExpand4);
                minExtentPath.setMax4(minExtentPath, minExpand4);
                aabb.m_kMinimumCorner.add4(minExtentPath);
                aabb.m_kMaximumCorner.add4(maxExtentPath);
                *cachedAabb = aabb;
            }
        }
    }
    {
        const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>(bodyB.getShape());
        numHits = bvB->GetAabbHits(aabb, hitListOut, hitListCapacity);
    }
    if (numHits >= hitListCapacity)
    {
        const hkpBvTreeShape* bvB = static_cast<const hkpBvTreeShape*>(bodyB.getShape());
        numHits =
            input.m_iFilter->FilterAabb(input, bodyA, bodyB, bvB, aabb, hitListOut, hitListCapacity);
        numHits = MathUtilities::min2(numHits, hitListCapacity - 1);
    }
    AlgorithmUtilities::quickSort(hitListOut, numHits);
    hitListOut[numHits] = 0xffffffff;
    return numHits;
}
