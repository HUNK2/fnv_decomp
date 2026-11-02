// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimationctor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
extern "C" __m128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, __m128 a);
struct __declspec(align(16)) FUN_005611c0_t
{
    float x, y, z, w;
    FUN_005611c0_t(const FUN_005611c0_t& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
    void FUN_005611c0();
};
struct Buffer
{
    char* m_data;
    int m_iElementCount;
};
void __cdecl FUN_00e318a0(int type, Buffer* buf);
void __cdecl FUN_00e31800(int size, Buffer* buf);
void __cdecl CallHandlerByIndex(int, int, int);
extern int DAT_010eb3d0[];
struct VecArray
{
    FUN_005611c0_t* m_data;
};
struct Writer
{
    char pad[0x74];
    Buffer m_buf;

    void FUN_00e319e0(unsigned char flags, int type, const FUN_005611c0_t* v, int last, const VecArray* arr);
};
struct S_00e31ca0_Heap;
struct S_00e31ca0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00e31ca0_Heap* m_pStreamAllocator;
    S_00e31ca0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00e31ca0_Router* FUN_00c85750();
void ResizeAudioStream(S_00e31ca0_Heap& alloc, void* arr, int elemSize);
template <typename T> inline void S_00e31ca0_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct S_00e31ca0_ByteArray
{
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _pushBack(S_00e31ca0_Heap& alloc, const unsigned char& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(unsigned char));
        S_00e31ca0_constructWithCopy<unsigned char>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(const unsigned char& t)
    {
        _pushBack(FUN_00c85750()->heap(), t);
    }
};
struct S_00e31ca0_FloatArray
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
void WriteUInt16ToBuffer(int v, S_00e31ca0_ByteArray& out);
void AppendChar(int v, S_00e31ca0_ByteArray& out);
struct S_00e31ca0
{
    int unk0;
    int unk4;
    int unk8;
    float unkC;
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
    int unk6C;
    int unk70;
    S_00e31ca0_ByteArray m_out;
    void AppendScaledValues(int a, int b, S_00e31ca0_FloatArray& values);
};
struct E317C0Allocator;
struct E317C0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E317C0Allocator* m_pStreamAllocator;

    E317C0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" E317C0MemoryRouter& __cdecl FUN_00c85750();
}
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct E317C0CharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void construct(char* p, int n, char const& e)
    {
        for (int i = 0; i < n; i++)
            p[i] = e;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void AddBack(char const& e)
    {
        E317C0Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(char));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};
void __cdecl AppendChar(char acChar, E317C0CharArray& arOut);
extern void __cdecl FUN_00e31800(int amount, struct MemWriter* writer);
struct MemWriter
{
    int used;
    char* data;
};
void __cdecl WriteFloatToMemWriter(float value, MemWriter* writer);
struct E32C80Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    E32C80Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class E32C80Base
{
  public:
    E32C80Base(void* info);
    virtual void unk00();

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
};
class FUN_00e32c80 : public E32C80Base
{
  public:
    FUN_00e32c80(void* info, void* arg1, void* arg2);
    virtual void unk00();

    void init(void* info, void* arg1, void* arg2);

    E32C80Array m_array44;
    E32C80Array m_array50;
    E32C80Array m_array5C;
    E32C80Array m_array68;
    E32C80Array m_array74;
};
struct hkMemory
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void deallocateChunk(void* p, int nbytes) throw();
};
struct hkThreadMemory
{
    char pad[0x10];
    hkMemory* m_pMemoryAllocator;
};
template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArray() throw()
    {
        hkThreadMemory* tm = (hkThreadMemory*)FUN_00c85750();
        hkMemory* mem = tm->m_pMemoryAllocator;
        m_iElementCount = 0;
        if (!(m_iCapacityState & (int)0x80000000))
        {
            mem->deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = (int)0x80000000;
    }
};
struct Struct28
{
    char data[28];
};
struct FUN_00e32cf0_Class
{
    hkArray<Struct28> arr1;
    hkArray<int> arr2;
    hkArray<int> arr3;

    ~FUN_00e32cf0_Class() throw();
};
void __cdecl FUN_00e31740(unsigned char a, unsigned int b, char** pp);
void __cdecl FUN_00e31780(unsigned char a, unsigned int b, char** pp);
union e319Rec
{
    unsigned char raw;
    struct
    {
        unsigned char lo : 2;
        unsigned char mid : 4;
        unsigned char hi : 2;
    } f;
};
union e319Tail
{
    unsigned char raw;
    struct
    {
        unsigned char b0 : 1;
        unsigned char sel : 2;
        unsigned char rest : 5;
    } f;
};
struct e319Cls
{
    char pad[0x10];
    int m_10;
    int m_14;
    char padCur[0x14];
    int m_2c;
    char kad[4];
    char* m_34;
    char pNewad[0xc];
    int* m_44;
    char pTmpad[0x2c];
    int m_74;
    char pad78[8];
    int m_80;
    void FUN_00e31900();
};
// Havok-style constructor: base init from a1, five empty hkArray members, then a temporary set of
// arrays (one 28-byte element from a2, two int arrays sized from a1 and zero-filled) handed to a
// member initialiser together with a3.
struct HeapL;
struct RouterL
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HeapL* m_pStreamAllocator;
    HeapL& heap()
    {
        return *m_pStreamAllocator;
    }
};
RouterL* GetRouterL() throw();
void ReserveMoreL(HeapL& alloc, void* arr, int elemSize) throw();
void ReserveL(HeapL& alloc, void* arr, int numElem, int elemSize) throw();
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
template <class T> struct ArrL
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ArrL() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void _pushBack(HeapL& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ReserveMoreL(alloc, this, sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
    void AddBack(const T& t)
    {
        _pushBack(GetRouterL()->heap(), t);
    }
    void GrowArrayCapacity(HeapL& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            ReserveL(alloc, this, newSize, sizeof(T));
        }
    }
    void _setSize(HeapL& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(GetRouterL()->heap(), n);
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};
struct SrcL
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_numA;
    int m_numB;
};
struct Elem28L
{
    int v00, v04, v08, v0c, v10, v14, v18;
};
struct LocalArraysL
{
    ArrL<Elem28L> m_pElements;
    ArrL<int> m_kPointA;
    ArrL<int> m_kPointB;
    ~LocalArraysL() throw();
};
struct BaseL
{
    BaseL(SrcL* src) throw();
    virtual void vf0();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
};
struct FUN_00e32af0 : BaseL
{
    ArrL<int> m_arr44;
    ArrL<int> m_arr50;
    ArrL<int> m_arr5c;
    ArrL<int> m_arr68;
    ArrL<int> m_arr74;
    FUN_00e32af0(SrcL* src, const Elem28L* elem, void* arg3) throw();
    void InitL(SrcL* src, LocalArraysL* arrays, void* arg3) throw();
};
#include <stdlib.h>
extern "C"
{
    void __cdecl FUN_00e31850(int alignment, void* stream);
    void __cdecl WriteFloatToMemWriter(float val, void* stream);
    void __cdecl AppendChar(unsigned int val, void* stream);
    void __cdecl WriteUInt16ToBuffer(unsigned int val, void* stream);
    unsigned char __cdecl ScaleToByte(float minVal, float maxVal, float val);
    unsigned short __cdecl NormalizeToUShort(float minVal, float maxVal, float val);
}
struct Vector4Array
{
    const float* m_data;
};
struct AnimationCompressor
{
    char pad[0x74];
    char m_stream;

    void WriteCompressedAnimation(unsigned char mask, int quantType, const float* staticValues, const float* minValues,
                                  const float* maxValues, int numFrames, const Vector4Array* data);
};

extern "C" const char str_010eb400[];  // "Compression Ratio: "
extern "C" const char str_010eb414[];  // ":1."
extern "C" const char str_010eb418[];  // "Original Size: "
extern "C" const char str_010eb428[];  // " bytes. Compressed Size: "
extern "C" const char str_010eb444[];  // "Size of largest block (PS3 SPU): "
extern "C" const char str_010eb468[];  // " bytes."
extern "C" const char str_010eb470[];  // .\Animation\SplineCompressed\hkaSplineCompressedAnimationCtor.cpp
extern "C" const char str_010eb4b4[];  // "Number of blocks: "
extern "C" const char str_010eb4c8[];  // "Compression"
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

struct Se31d50_Alloc
{
    virtual ~Se31d50_Alloc();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE> __forceinline TYPE* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = sizeof(TYPE);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<TYPE*>(p);
    }
    template <typename TYPE> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
struct Se31d50_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Se31d50_Alloc* m_pStreamAllocator;
    __forceinline Se31d50_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
    static Se31d50_Router& FUN_00c85750();
};
void ResizeAudioStream(Se31d50_Alloc& a, void* array, int sizeElem);
void FUN_00c908c0(Se31d50_Alloc& a, void* array, int reqElem, int sizeElem);

struct Se31d50_ContainerHeap
{
    __forceinline Se31d50_Alloc& get(const void*)
    {
        return Se31d50_Router::FUN_00c85750().heap();
    }
};
template <bool B> struct Se31d50_Trait
{
};
typedef Se31d50_Trait<true> Se31d50_IsPod;
typedef Se31d50_Trait<false> Se31d50_IsClass;
struct Se31d50_ArrayUtil
{
    template <typename T> static __forceinline void construct(T*, int, Se31d50_IsPod)
    {}
    template <typename T> static __forceinline void destruct(T*, int, Se31d50_IsPod)
    {}
    template <typename T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, Se31d50_IsPod)
    {
        for (int i = 0; i < n; ++i)
            t[i] = tcopy;
    }
};
template <typename T> struct Se31d50_ArrayBase
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline Se31d50_ArrayBase()
    {}
    __forceinline ~Se31d50_ArrayBase()
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline const T* begin() const
    {
        return m_data;
    }
    __forceinline void clear()
    {
        Se31d50_ArrayUtil::destruct(m_data, m_iElementCount, Se31d50_IsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(Se31d50_Alloc& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(Se31d50_Alloc& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(Se31d50_Alloc& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        Se31d50_ArrayUtil::destruct(m_data + n, m_iElementCount - n, Se31d50_IsPod());
        Se31d50_ArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, Se31d50_IsPod());
        m_iElementCount = n;
    }
    __forceinline void _pushBack(Se31d50_Alloc& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(T));
        }
        Se31d50_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, Se31d50_IsPod());
        m_iElementCount++;
    }
    __forceinline void setOwnedData(T* ptr, int size, int capacity)
    {
        m_data = ptr;
        m_iElementCount = size;
        m_iCapacityState = capacity;
    }
};
template <typename T> struct Se31d50_Array : Se31d50_ArrayBase<T>
{
    __forceinline Se31d50_Array()
    {}
    __forceinline void init()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = Se31d50_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
    }
    __forceinline Se31d50_Array(int n)
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = Se31d50_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
        Se31d50_Alloc& a = Se31d50_ContainerHeap().get(this);
        T* p = n ? a._bufAlloc<T>(n) : 0;
        int cap = n ? n : (int)0x80000000;
        this->setOwnedData(p, n, cap);
        Se31d50_ArrayUtil::construct(this->m_data, n, Se31d50_IsPod());
    }
    __forceinline ~Se31d50_Array()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        this->_clearAndDeallocate(Se31d50_ContainerHeap().get(this));
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(Se31d50_ContainerHeap().get(this), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(Se31d50_ContainerHeap().get(this), t);
    }
};
struct Se31d50_SimdReal
{
    __m128 m_vValue;
    __forceinline Se31d50_SimdReal(const __m128& x) : m_vValue(x)
    {}
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }
};
class __declspec(align(16)) Se31d50_Vector4
{
  public:
    __m128 m_vComponents;
    __forceinline Se31d50_Vector4()
    {}
    __forceinline Se31d50_Vector4(const Se31d50_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const Se31d50_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const Se31d50_Vector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(float a, const Se31d50_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(_mm_set_ss(a), _mm_set_ss(a), 0), b.m_vComponents);
    }
    __forceinline void setMin4(const Se31d50_Vector4& a, const Se31d50_Vector4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const Se31d50_Vector4& a, const Se31d50_Vector4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
    __forceinline Se31d50_SimdReal dot4(const Se31d50_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
        __m128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    __forceinline Se31d50_SimdReal lengthInverse4() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot4(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize4()
    {
        __m128 lenInv = lengthInverse4().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
};
struct Se31d50_Bool
{
    char m_cBooleanValue;
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
enum Se31d50_RotQ
{
    Se31d50_POLAR32 = 0
};
enum Se31d50_ScalQ
{
    Se31d50_BITS8 = 0
};
enum Se31d50_AnimType
{
    Se31d50_SPLINE = 5
};
template <typename E, typename S> struct Se31d50_Enum
{
    S m_kStorage;
    __forceinline operator E() const
    {
        return (E)m_kStorage;
    }
    __forceinline void operator=(E e)
    {
        m_kStorage = (S)e;
    }
};
struct Se31d50_TrackParams
{
    float m_fRotationTolerance;
    float m_fTranslationTolerance;
    float m_fScaleTolerance;
    float m_fFloatingTolerance;
    unsigned short m_iRotationDegree;
    unsigned short m_iTranslationDegree;
    unsigned short m_iScaleDegree;
    unsigned short m_iFloatingDegree;
    Se31d50_Enum<Se31d50_RotQ, unsigned char> m_eRotationQuantizationType;
    Se31d50_Enum<Se31d50_ScalQ, unsigned char> m_eTranslationQuantizationType;
    Se31d50_Enum<Se31d50_ScalQ, unsigned char> m_eScaleQuantizationType;
    Se31d50_Enum<Se31d50_ScalQ, unsigned char> m_eFloatQuantizationType;
};
struct Se31d50_PerTrack
{
    Se31d50_Array<Se31d50_TrackParams> m_kTrackParams;
    Se31d50_Array<int> m_kFirstIntArray;
    Se31d50_Array<int> m_kSecondIntArray;
};
struct Se31d50_AnimParams
{
    unsigned short m_iMaxFramesPerBlock;
    Se31d50_Bool m_bEnableSampleSingleTracks;
};
struct __declspec(align(16)) Se31d50_Qs
{
    Se31d50_Vector4 m_vTranslation;
    Se31d50_Vector4 m_rotation;
    Se31d50_Vector4 m_vScale;
};
struct Se31d50_Raw
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetIntegerValue() const;
    int unk04;
    int unk08;
    float unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Se31d50_Array<Se31d50_Qs> m_kTransforms;
    Se31d50_Array<float> m_kFloats;
};
struct Se31d50_Error
{
    virtual ~Se31d50_Error();
    virtual void v04();
    virtual void v08();
    virtual int message(int msg, int id, const char* description, const char* file, int line);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void BeginSection(int id, const char* name);
    virtual void EndSection();
};
extern Se31d50_Error* DAT_01268360;
struct Se31d50_ErrStream
{
    void* unk00;
    int unk04;
    void* unk08;
    void FUN_00cb1600(void* buf, int bufSize);
    void FUN_00cc00e0();
    Se31d50_ErrStream& FUN_00cc01c0(const char* s);
    Se31d50_ErrStream& WriteInt(int i);
    Se31d50_ErrStream& FUN_00cc02d0(unsigned int u);
    Se31d50_ErrStream& WriteFloat(float f);
    __forceinline Se31d50_ErrStream(void* buf, int bufSize)
    {
        FUN_00cb1600(buf, bufSize);
    }
    __forceinline ~Se31d50_ErrStream()
    {
        FUN_00cc00e0();
    }
    __forceinline Se31d50_ErrStream& operator<<(const char* s)
    {
        return FUN_00cc01c0(s);
    }
    __forceinline Se31d50_ErrStream& operator<<(int i)
    {
        return WriteInt(i);
    }
    __forceinline Se31d50_ErrStream& operator<<(unsigned int i)
    {
        return FUN_00cc02d0(i);
    }
    __forceinline Se31d50_ErrStream& operator<<(float f)
    {
        return WriteFloat(f);
    }
};
typedef Se31d50_Array<Se31d50_Vector4> Se31d50_VecArr;
typedef Se31d50_Array<float> Se31d50_FltArr;
typedef Se31d50_Array<unsigned char> Se31d50_ByteArr;
void FUN_00e58740(int numPoints, const float* U, const Se31d50_Vector4* P, int degree, float tolerance, int* numKnots,
                  float* knots, int* numCP, Se31d50_Vector4* cp);

struct Se31d50_Anim
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int GetValueAt2C() const;
    int unk04;
    Se31d50_Enum<Se31d50_AnimType, int> m_type;
    float m_fAnimationDuration;
    int m_iNumTransformTracks;
    int m_iNumberOfFloatTracks;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iFrameCount;
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int m_iMaskAndQuantizationSize;
    float m_fBlockDuration;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;
    Se31d50_Array<unsigned int> m_kFirstUInt32Array;
    Se31d50_Array<unsigned int> m_kFloatBlockOffsets;
    Se31d50_Array<unsigned int> m_kTransformOffsets;
    Se31d50_Array<unsigned int> m_kFloatOffsets;
    Se31d50_ByteArr m_kCompressedData;
    int m_iEndian;
    int FUN_00e33330() const;
    void AppendScaledValues(int n, int p, const Se31d50_FltArr& U);
    void FUN_00e319e0(unsigned char mask, Se31d50_RotQ q, const Se31d50_Vector4& s, int n, const Se31d50_VecArr& p);
    void WriteCompressedAnimation(unsigned char mask, Se31d50_ScalQ q, const Se31d50_Vector4& s,
                                  const Se31d50_Vector4& mn, const Se31d50_Vector4& mx, int n, const Se31d50_VecArr& p);
    void FUN_00e31d50(const Se31d50_Raw& raw, const Se31d50_PerTrack& trackParams,
                      const Se31d50_AnimParams& animationParams);
    static Se31d50_Vector4 FUN_00e31410(const Se31d50_VecArr& d);
    static Se31d50_Vector4 FUN_00e31470(const Se31d50_VecArr& d);
    static Se31d50_Vector4 FUN_00e314c0(const Se31d50_VecArr& d);
    static unsigned char FUN_00e311f0(const Se31d50_Vector4& mean, const Se31d50_Vector4& mn, const Se31d50_Vector4& mx,
                                      float tol, const Se31d50_Vector4& id);
    static unsigned char PackBitFields(Se31d50_ScalQ t, Se31d50_RotQ r, Se31d50_ScalQ s);
    static unsigned char FUN_00e30f40(unsigned char mask, Se31d50_ScalQ f);
    static void FUN_00e31800(int n, Se31d50_ByteArr& out);
    static void FUN_00e31850(int align, Se31d50_ByteArr& out);
    static void FillInterpolatedValues(int n, Se31d50_FltArr& U, float a, float b);
    static void FUN_00e310c0(const Se31d50_Qs* t, int numTracks, int numFrames, int first, int track, Se31d50_VecArr& a,
                             Se31d50_VecArr& b, Se31d50_VecArr& c);
    static void FUN_00e31180(const float* f, int numTracks, int numFrames, int first, int track, Se31d50_VecArr& a);
};

extern "C" double __cdecl fabs(double);
__declspec(noinline) Se31d50_Vector4 Se31d50_Anim::FUN_00e31410(const Se31d50_VecArr& data)
{
    Se31d50_Vector4 mean;
    mean.setZero4();
    const int n = data.GetLogicalSize();
    for (int i = 0; i < n; i++)
    {
        mean.add4(data[i]);
    }
    mean.setMul4(1.0f / n, mean);
    return mean;
}
__declspec(noinline) Se31d50_Vector4 Se31d50_Anim::FUN_00e31470(const Se31d50_VecArr& data)
{
    Se31d50_Vector4 m = data[0];
    const int n = data.GetLogicalSize();
    for (int i = 1; i < n; i++)
    {
        m.setMin4(m, data[i]);
    }
    return m;
}
__declspec(noinline) Se31d50_Vector4 Se31d50_Anim::FUN_00e314c0(const Se31d50_VecArr& data)
{
    Se31d50_Vector4 m = data[0];
    const int n = data.GetLogicalSize();
    for (int i = 1; i < n; i++)
    {
        m.setMax4(m, data[i]);
    }
    return m;
}
__declspec(noinline) unsigned char Se31d50_Anim::FUN_00e311f0(const Se31d50_Vector4& mean, const Se31d50_Vector4& mn,
                                                              const Se31d50_Vector4& mx, float tol,
                                                              const Se31d50_Vector4& id)
{
    unsigned char mask = 0;
    for (int i = 0; i < 4; i++)
    {
        if ((float)fabs(mean(i) - mn(i)) > tol || (float)fabs(mean(i) - mx(i)) > tol)
        {
            mask |= (1 << (i + 4));
        }
        else if ((float)fabs(mean(i) - id(i)) > tol)
        {
            mask |= (1 << i);
        }
    }
    return mask;
}
__declspec(noinline) unsigned char Se31d50_Anim::PackBitFields(Se31d50_ScalQ t, Se31d50_RotQ r, Se31d50_ScalQ s)
{
    return (unsigned char)(t | (r << 2) | (s << 6));
}
__declspec(noinline) unsigned char Se31d50_Anim::FUN_00e30f40(unsigned char mask, Se31d50_ScalQ f)
{
    return (unsigned char)(mask | (f << 1));
}
__declspec(noinline) void Se31d50_Anim::FillInterpolatedValues(int n, Se31d50_FltArr& U, float a, float b)
{
    U[0] = a;
    U[n] = b;
    for (int i = 1; i < n; i++)
    {
        U[i] = (float)i / n * (b - a) + a;
    }
}
__declspec(noinline) void Se31d50_Anim::FUN_00e310c0(const Se31d50_Qs* src, int numTracks, int numFrames, int first,
                                                     int track, Se31d50_VecArr& a, Se31d50_VecArr& b, Se31d50_VecArr& c)
{
    for (int i = 0; i < numFrames; i++)
    {
        const Se31d50_Qs& t = src[(i + first) * numTracks + track];
        a[i].set(t.m_vTranslation(0), t.m_vTranslation(1), t.m_vTranslation(2), 0.0f);
        b[i].set(t.m_rotation(0), t.m_rotation(1), t.m_rotation(2), t.m_rotation(3));
        c[i].set(t.m_vScale(0), t.m_vScale(1), t.m_vScale(2), 0.0f);
    }
}
__declspec(noinline) void Se31d50_Anim::FUN_00e31180(const float* f, int numTracks, int numFrames, int first, int track,
                                                     Se31d50_VecArr& a)
{
    for (int i = 0; i < numFrames; i++)
    {
        a[i].set(f[(i + first) * numTracks + track], 0.0f, 0.0f, 0.0f);
    }
}
__forceinline int Se31d50_max2(int x, int y)
{
    return x > y ? x : y;
}
__forceinline int Se31d50_min2(int x, int y)
{
    return x < y ? x : y;
}

// @fnv 0x00e31d50
void Se31d50_Anim::FUN_00e31d50(const Se31d50_Raw& raw, const Se31d50_PerTrack& trackParams,
                                const Se31d50_AnimParams& animationParams)
{
    m_iEndian = 0;
    m_type = Se31d50_SPLINE;
    m_iMaxFramesPerBlock = animationParams.m_iMaxFramesPerBlock;
    Se31d50_Bool enableSampleSingleTracks = animationParams.m_bEnableSampleSingleTracks;
    m_iFrameCount = raw.GetIntegerValue();
    m_iBlockCount = Se31d50_max2(1, (m_iFrameCount + m_iMaxFramesPerBlock - 3) / (m_iMaxFramesPerBlock - 1));
    m_fBlockDuration = m_fAnimationDuration / (m_iFrameCount - 1) * (m_iMaxFramesPerBlock - 1);
    m_fBlockInverseDuration = 1.0f / m_fBlockDuration;
    m_fPerFrameDuration = m_fAnimationDuration / (m_iFrameCount - 1);
    int f = 0;
    m_iMaskAndQuantizationSize = (4 * m_iNumTransformTracks + m_iNumberOfFloatTracks + 3) & ~3;
    for (int i = 0; i < m_iBlockCount; i++)
    {
        m_kFirstUInt32Array.AddBack(m_kCompressedData.GetLogicalSize());
        const int nf = Se31d50_min2(m_iMaxFramesPerBlock, m_iFrameCount - f);
        const float blockDuration = m_fAnimationDuration / (m_iFrameCount - 1) * (nf - 1);
        int maskPos = m_kCompressedData.GetLogicalSize();
        FUN_00e31800(m_iMaskAndQuantizationSize, m_kCompressedData);
        for (int isFloat = 0; isFloat < 2; isFloat++)
        {
            const int numTracks = (isFloat == 0) ? m_iNumTransformTracks : m_iNumberOfFloatTracks;
            const int numComponents = (isFloat == 0) ? 3 : 1;
            if (isFloat == 1)
            {
                m_kFloatBlockOffsets.AddBack(m_kCompressedData.GetLogicalSize() - m_kFirstUInt32Array[i]);
            }
            for (int t = 0; t < numTracks; t++)
            {
                if (enableSampleSingleTracks)
                {
                    if (isFloat == 0)
                    {
                        m_kTransformOffsets.AddBack(m_kCompressedData.GetLogicalSize() - m_kFirstUInt32Array[i]);
                    }
                    else
                    {
                        m_kFloatOffsets.AddBack(m_kCompressedData.GetLogicalSize() - m_kFirstUInt32Array[i]);
                    }
                }
                const Se31d50_TrackParams& params =
                    trackParams.m_kTrackParams[(isFloat == 0) ? trackParams.m_kFirstIntArray[t]
                                                              : trackParams.m_kSecondIntArray[t]];
                Se31d50_VecArr data[3];
                Se31d50_VecArr* pData = data;
                int n = 2;
                do
                {
                    pData->init();
                    ++pData;
                } while (--n >= 0);
                Se31d50_FltArr U[3];
                Se31d50_FltArr* pU = U;
                n = 2;
                do
                {
                    pU->init();
                    ++pU;
                } while (--n >= 0);
                for (int c = 0; c < numComponents; c++)
                {
                    data[c].SetSizeAndGrow(nf);
                    U[c].SetSizeAndGrow(nf);
                    FillInterpolatedValues(nf - 1, U[c], 0.0f, blockDuration);
                }
                int degree[3];
                float tolerance[3];
                if (isFloat == 0)
                {
                    degree[0] = params.m_iTranslationDegree;
                    degree[1] = params.m_iRotationDegree;
                    degree[2] = params.m_iScaleDegree;
                    tolerance[0] = params.m_fTranslationTolerance;
                    tolerance[1] = params.m_fRotationTolerance;
                    tolerance[2] = params.m_fScaleTolerance;
                }
                else
                {
                    degree[0] = params.m_iFloatingDegree;
                    tolerance[0] = params.m_fFloatingTolerance;
                }
                if (isFloat == 0)
                {
                    FUN_00e310c0(raw.m_kTransforms.begin(), m_iNumTransformTracks, nf, f, t, data[0], data[1], data[2]);
                }
                else
                {
                    FUN_00e31180(raw.m_kFloats.begin(), m_iNumberOfFloatTracks, nf, f, t, data[0]);
                }
                for (int c = 0; c < numComponents; c++)
                {
                    Se31d50_Vector4 mean = FUN_00e31410(data[c]);
                    Se31d50_Vector4 minV = FUN_00e31470(data[c]);
                    Se31d50_Vector4 maxV = FUN_00e314c0(data[c]);
                    if (c == 1)
                    {
                        mean.normalize4();
                    }
                    Se31d50_Vector4 identity[3];
                    identity[0].set(0.0f, 0.0f, 0.0f, 0.0f);
                    identity[1].set(0.0f, 0.0f, 0.0f, 1.0f);
                    identity[2].set(1.0f, 1.0f, 1.0f, 0.0f);
                    unsigned char mask = FUN_00e311f0(mean, minV, maxV, tolerance[c], identity[c]);
                    if (isFloat == 1 && mask == 0)
                    {
                        mask = 1;
                    }
                    if (isFloat == 0)
                    {
                        if (c == 0)
                        {
                            m_kCompressedData[maskPos] =
                                PackBitFields(params.m_eTranslationQuantizationType, params.m_eRotationQuantizationType,
                                             params.m_eScaleQuantizationType);
                            maskPos++;
                        }
                        m_kCompressedData[maskPos] = mask;
                        maskPos++;
                    }
                    else
                    {
                        m_kCompressedData[maskPos] = FUN_00e30f40(mask, params.m_eFloatQuantizationType);
                        maskPos++;
                    }
                    Se31d50_VecArr controlPoints(nf * 3);
                    Se31d50_FltArr knots(nf * 3 + 2);
                    if (mask & 0xf0)
                    {
                        int numKnots;
                        int numControlPoints;
                        FUN_00e58740(nf, U[c].begin(), data[c].begin(), degree[c], tolerance[c], &numKnots,
                                     knots.begin(), &numControlPoints, controlPoints.begin());
                        knots.SetSizeAndGrow(numKnots);
                        controlPoints.SetSizeAndGrow(numControlPoints);
                        if (controlPoints.GetLogicalSize() > nf)
                        {
                            degree[c] = 1;
                            FUN_00e58740(nf, U[c].begin(), data[c].begin(), degree[c], tolerance[c], &numKnots,
                                         knots.begin(), &numControlPoints, controlPoints.begin());
                            knots.SetSizeAndGrow(numKnots);
                            controlPoints.SetSizeAndGrow(numControlPoints);
                        }
                        AppendScaledValues(controlPoints.GetLogicalSize() - 1,
                                     knots.GetLogicalSize() - controlPoints.GetLogicalSize() - 1, knots);
                    }
                    if (c == 1)
                    {
                        FUN_00e319e0(mask, params.m_eRotationQuantizationType, mean, controlPoints.GetLogicalSize() - 1,
                                     controlPoints);
                    }
                    else
                    {
                        if (mask & 0xf0)
                        {
                            minV = FUN_00e31470(controlPoints);
                            maxV = FUN_00e314c0(controlPoints);
                        }
                        WriteCompressedAnimation(mask,
                                                 (isFloat == 0)
                                                     ? (Se31d50_ScalQ)((c == 0) ? params.m_eTranslationQuantizationType
                                                                                : params.m_eScaleQuantizationType)
                                                     : (Se31d50_ScalQ)params.m_eFloatQuantizationType,
                                                 mean, minV, maxV, controlPoints.GetLogicalSize() - 1, controlPoints);
                    }
                    FUN_00e31850(4, m_kCompressedData);
                }
            }
        }
        f += nf - 1;
        FUN_00e31850(16, m_kCompressedData);
    }
    DAT_01268360->BeginSection(0x36118e94, str_010eb4c8);
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.FUN_00cc01c0(str_010eb4b4).WriteInt(m_iBlockCount);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 366);
    }
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.FUN_00cc01c0(str_010eb444).WriteInt(GetValueAt2C()).FUN_00cc01c0(str_010eb468);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 367);
    }
    const unsigned int originalSize =
        raw.m_kTransforms.GetLogicalSize() * sizeof(float) * 16 + raw.m_kFloats.GetLogicalSize() * sizeof(float);
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.FUN_00cc01c0(str_010eb418)
            .FUN_00cc02d0(originalSize)
            .FUN_00cc01c0(str_010eb428)
            .WriteInt(FUN_00e33330())
            .FUN_00cc01c0(str_010eb468);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 372);
    }
    {
        char reportBuf[512];
        Se31d50_ErrStream ostr(reportBuf, sizeof(reportBuf));
        ostr.FUN_00cc01c0(str_010eb400).WriteFloat((float)originalSize / FUN_00e33330()).FUN_00cc01c0(str_010eb414);
        DAT_01268360->message(0, -1, reportBuf, str_010eb470, 373);
    }
    DAT_01268360->EndSection();
}
