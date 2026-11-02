
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

// @fnv 0x00e319e0
void Writer::FUN_00e319e0(unsigned char flags, int type, const FUN_005611c0_t* apVec, int last,
                          const VecArray* apVecArray)
{
    if (flags & 0xf0)
    {
        FUN_00e318a0(type, &m_buf);
        int size = DAT_010eb3d0[type];
        for (int i = 0; i <= last; i++)
        {
            FUN_005611c0_t t = apVecArray->m_data[i];
            t.FUN_005611c0();
            FUN_00e31800(size, &m_buf);
            CallHandlerByIndex(type, (int)&t, (int)(m_buf.m_data + m_buf.m_iElementCount - size));
        }
    }
    else if (flags & 0x0f)
    {
        FUN_00e318a0(type, &m_buf);
        int size = DAT_010eb3d0[type];
        FUN_005611c0_t t = *apVec;
        t.FUN_005611c0();
        FUN_00e31800(size, &m_buf);
        CallHandlerByIndex(type, (int)&t, (int)(m_buf.m_data + m_buf.m_iElementCount - size));
    }
}

namespace fnv_00e31ad0 {
struct Buffer
{
    unsigned short* data;
    unsigned int byteSize;
};
void __cdecl FUN_00e31800(unsigned int, Buffer*);
// @fnv 0x00e31ad0
void __cdecl WriteUInt16ToBuffer(unsigned short value, Buffer* buffer)
{
    FUN_00e31800(2, buffer);
    *(unsigned short*)((char*)buffer->data + buffer->byteSize - 2) = value;
}
}  // namespace fnv_00e31ad0

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
// @fnv 0x00e31ca0
void S_00e31ca0::AppendScaledValues(int aiFirst, int aiSecond, S_00e31ca0_FloatArray& arValues)
{
    int last = aiFirst + aiSecond + 1;
    WriteUInt16ToBuffer(aiFirst, m_out);
    AppendChar(aiSecond, m_out);
    for (int i = 0; i <= last; i++)
    {
        unsigned char ucScaled = (unsigned char)(int)(arValues.m_data[i] / unkC * (unk28 - 1) + 0.5);
        m_out.AddBack(ucScaled);
    }
}

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

// Appends the character c to the E317C0CharArray out via its push-back method.
// @fnv 0x00e317c0
void __cdecl AppendChar(char acChar, E317C0CharArray& arOut)
{
    arOut.AddBack(acChar);
}

extern void __cdecl FUN_00e31800(int amount, struct MemWriter* writer);

struct MemWriter
{
    int used;
    char* data;
};

// @fnv 0x00e31b00
void __cdecl WriteFloatToMemWriter(float value, MemWriter* writer)
{
    FUN_00e31800(4, writer);
    *(float*)(writer->data + writer->used - 4) = value;
}

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

// Constructs the object by forwarding info, arg1 and arg2 to init after initializing the E32C80Base base with info.
// @fnv 0x00e32c80
FUN_00e32c80::FUN_00e32c80(void* info, void* arg1, void* arg2) : E32C80Base(info)
{
    init(info, arg1, arg2);
}

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

// Destructor for a container holding three hkArray members; the arrays are destroyed by their own destructors.
// @fnv 0x00e32cf0
FUN_00e32cf0_Class::~FUN_00e32cf0_Class() throw()
{}

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

// @fnv 0x00e31900
void e319Cls::FUN_00e31900()
{
    if (m_80 == 0)
        return;
    for (int i = 0; i < m_2c; i++)
    {
        unsigned char* pSrc = (unsigned char*)(m_44[i] + m_74);
        char* p = m_34 + (unsigned int)pSrc;
        for (int n = 0; n < m_10; n++)
        {
            e319Rec rec;
            rec.raw = *pSrc++;
            FUN_00e31740(*pSrc++, rec.f.lo, &p);
            FUN_00e31780(*pSrc++, rec.f.mid, &p);
            FUN_00e31740(*pSrc++, rec.f.hi, &p);
        }
        for (int iTail = 0; iTail < m_14; iTail++)
        {
            unsigned char ucTail = *pSrc++;
            FUN_00e31740((unsigned char)(ucTail & 0xf9), (ucTail >> 1) & 3, &p);
        }
    }
}

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

// Builds temporary arrays from src counts and elem, zero-fills them, then calls InitL to initialize the object.
// @fnv 0x00e32af0
FUN_00e32af0::FUN_00e32af0(SrcL* pSource, const Elem28L* elem, void* arg3) throw() : BaseL(pSource)
{
    LocalArraysL arrays;
    arrays.m_pElements.AddBack(*elem);
    arrays.m_kPointA.SetSizeAndGrow(pSource->m_numA);
    arrays.m_kPointB.SetSizeAndGrow(pSource->m_numB);
    for (int i = 0; i < pSource->m_numA; i++)
        arrays.m_kPointA[i] = 0;
    for (int i = 0; i < pSource->m_numB; i++)
        arrays.m_kPointB[i] = 0;
    InitL(pSource, &arrays, arg3);
}

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

// Writes animation header and per-frame quantized values to m_stream based on mask and quantType.
// @fnv 0x00e31b20
void AnimationCompressor::WriteCompressedAnimation(unsigned char mask, int quantType, const float* staticValues,
                                                   const float* minValues, const float* maxValues, int numFrames,
                                                   const Vector4Array* data)
{
    void* stream = &m_stream;
    FUN_00e31850(4, stream);

    unsigned int bit = 1;
    for (int i = 0; i < 3; ++i, bit = _rotl(bit, 1))
    {
        if (mask & _rotl(bit, 4))
        {
            WriteFloatToMemWriter(minValues[i], stream);
            WriteFloatToMemWriter(maxValues[i], stream);
        }
        else if (mask & bit)
        {
            WriteFloatToMemWriter(staticValues[i], stream);
        }
    }

    if (mask & 0xf0)
    {
        for (int frame = 0; frame <= numFrames; ++frame)
        {
            int comp = 0;
            unsigned int b = 1;
            for (; comp < 3; ++comp, b = _rotl(b, 1))
            {
                if (mask & _rotl(b, 4))
                {
                    if (quantType == 0)
                    {
                        AppendChar(ScaleToByte(minValues[comp], maxValues[comp], data->m_data[frame * 4 + comp]),
                                   stream);
                    }
                    else
                    {
                        WriteUInt16ToBuffer(
                            NormalizeToUShort(minValues[comp], maxValues[comp], data->m_data[frame * 4 + comp]),
                            stream);
                    }
                }
            }
        }
    }
}

namespace fnv_00e31800 {
struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct Buf
{
    char* m_data;
    unsigned int m_len;
    unsigned int m_cap;
};

extern "C" void _ReadWriteBarrier(void);

Holder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, Buf* buf, int n);

// Appends count zero bytes to buf, calling FUN_00c90940 when its length equals the masked capacity.
// @fnv 0x00e31800
void __cdecl FUN_00e31800(int count, Buf* buf)
{
    if (count > 0)
    {
        do
        {
            Holder* h = FUN_00c85750();
            if (buf->m_len == (buf->m_cap & 0x3fffffff))
            {
                ResizeAudioStream(h->m_pAllocator, buf, 1);
            }
            char* slot = buf->m_data + buf->m_len;
            _ReadWriteBarrier();
            *slot = 0;
            buf->m_len++;
        } while (--count);
    }
}
}  // namespace fnv_00e31800

namespace fnv_00e31850 {
#include <string.h>

struct BufferInfo
{
    char* volatile data;
    unsigned int length;
    unsigned int capacity;
};
struct FourIntegerPointerRecord
{
    int unk00, unk04, unk08, unk0C;
    void* unk10;
};
extern FourIntegerPointerRecord* __cdecl FUN_00c85750();
extern void __cdecl ResizeAudioStream(void*, BufferInfo*, int);
// Appends zero bytes until no bits selected by alignment minus one remain set in the buffer length.
// @fnv 0x00e31850
void __cdecl FUN_00e31850(unsigned int alignment, BufferInfo* buffer)
{
    unsigned int mask = alignment - 1;
    while (buffer->length & mask)
    {
        FourIntegerPointerRecord* alloc = FUN_00c85750();
        if (buffer->length == (buffer->capacity & 0x3fffffff))
            ResizeAudioStream(alloc->unk10, buffer, 1);
        memset(buffer->data + buffer->length, 0, 1);
        ++buffer->length;
    }
}
}  // namespace fnv_00e31850

namespace fnv_00e318a0 {
extern unsigned int DAT_010eb3e8[];

struct FUN_00e318a0_buf
{
    char* m_pData;
    unsigned int m_uLength;
    unsigned int m_uCapacityFlags;
};

struct FUN_00e318a0_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

extern FUN_00e318a0_holder* __cdecl FUN_00c85750();
extern void __cdecl ResizeAudioStream(void* apAllocator, FUN_00e318a0_buf* apBuf, int aiFlag);

// @fnv 0x00e318a0
void __cdecl FUN_00e318a0(unsigned int auBit, FUN_00e318a0_buf* apBuf)
{
    unsigned int mask = DAT_010eb3e8[auBit];
    if ((apBuf->m_uLength & mask) != 0)
    {
        do
        {
            FUN_00e318a0_holder* holder = FUN_00c85750();
            if (apBuf->m_uLength == (apBuf->m_uCapacityFlags & 0x3fffffff))
            {
                ResizeAudioStream(holder->m_pAllocator, apBuf, 1);
            }
            char* volatile* pp = &apBuf->m_pData;
            char* p = (char*)((unsigned int)*pp + apBuf->m_uLength);
            *p = 0;
            apBuf->m_uLength++;
            mask = *(volatile unsigned int*)&DAT_010eb3e8[auBit];
        } while ((apBuf->m_uLength & mask) != 0);
    }
}
}  // namespace fnv_00e318a0
