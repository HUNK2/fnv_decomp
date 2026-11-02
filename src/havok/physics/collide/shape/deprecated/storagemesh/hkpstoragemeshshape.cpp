
// src/havok/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStorageMeshShape.h"

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

class hkVector4D4B
{
  public:
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4D4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkMemoryAllocatorD4B
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4B
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4B* m_pStreamAllocator;
    hkMemoryAllocatorD4B& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4B& __cdecl FUN_00c85750();

template <class T> __forceinline void copyD4B(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> class hkArrayD4B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD4B() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }

    __forceinline hkArrayD4B& operator=(const hkArrayD4B& a)
    {
        hkMemoryAllocatorD4B& kHeap = FUN_00c85750().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kHeap.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kHeap.AllocateBufferWithSize(iNumBytes));
            m_iCapacityState = iNumBytes / static_cast<int>(sizeof(T));
        }
        m_iElementCount = a.m_iElementCount;
        copyD4B<T>(m_data, a.m_data, m_iElementCount);
        return *this;
    }
};

class hkpShapeD4B
{
  public:
    virtual ~hkpShapeD4B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
};

class hkpShapeContainerD4B
{
  public:
    virtual ~hkpShapeContainerD4B() throw();
};

struct hkpMeshShapeSubpartD4B
{
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
};

class FUN_00dcd310 : public hkpShapeD4B, public hkpShapeContainerD4B
{
  public:
    FUN_00dcd310(float fRadius, int iNumBitsForSubpartIndex) throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
    int unk18;
    int unk1C;
    hkVector4D4B m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArrayD4B<hkpMeshShapeSubpartD4B> m_kSubparts;
    hkArrayD4B<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
    int unk54;
    int unk58;
    int unk5C;

    void FUN_00d4b480(const hkpMeshShapeSubpartD4B& kSubpart) throw();
};

class FUN_00d4bab0 : public FUN_00dcd310
{
  public:
    FUN_00d4bab0(const FUN_00dcd310& kOther) throw();
    virtual ~FUN_00d4bab0() throw();

    hkArrayD4B<int> m_60;
};

// @fnv 0x00d4bab0
FUN_00d4bab0::FUN_00d4bab0(const FUN_00dcd310& kOther) throw()
    : FUN_00dcd310(kOther.m_fSphereRadius, kOther.m_iNumBitsForSubpartIndex)
{
    m_kScaling = kOther.m_kScaling;
    m_ulUserData = kOther.m_ulUserData;
    m_bDisableWelding = kOther.m_bDisableWelding;
    for (int i = 0; i < kOther.m_kSubparts.GetLogicalSize(); i++)
        FUN_00d4b480(kOther.m_kSubparts[i]);
    m_kWeldingInfo = kOther.m_kWeldingInfo;
    m_eWeldingType = kOther.m_eWeldingType;
}

namespace fnv_00d4bc00 {
struct hkAllocatorD4BC
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD4BC
{
    void* m_apvUnk00[4];
    hkAllocatorD4BC* m_pkHeap;
    hkAllocatorD4BC& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterD4BC* __cdecl FUN_00c85750() throw();

template <typename T> struct hkArrayD4BC
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(hkAllocatorD4BC& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD4BC() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
};

class hkReferencedObjectD4BC
{
  public:
    virtual ~hkReferencedObjectD4BC() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00d4bc00 : public hkReferencedObjectD4BC
{
  public:
    hkArrayD4BC<hkReal> m_kVertices;
    hkArrayD4BC<hkUint16> m_kIndices16;
    hkArrayD4BC<hkUint32> m_kIndices32;
    hkArrayD4BC<hkUint8> m_kMaterialIndices8;
    hkArrayD4BC<hkUint32> m_kMaterials;
    hkArrayD4BC<hkUint16> m_kMaterialIndices16;

    virtual ~FUN_00d4bc00() throw();
};

// Destructor that releases the six hkArray members of the object via their own destructors.
// @fnv 0x00d4bc00
FUN_00d4bc00::~FUN_00d4bc00() throw()
{}
}  // namespace fnv_00d4bc00

namespace fnv_00d4bd30 {
class hkMemoryAllocatorD4BD
{
  public:
    virtual ~hkMemoryAllocatorD4BD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4BD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD4BD* m_pStreamAllocator;
    hkMemoryAllocatorD4BD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD4BD& __cdecl FUN_00c85750();

class FUN_00d4bc00
{
  public:
    virtual ~FUN_00d4bc00() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00d4bc00*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d4bc00* DestroyAndFree(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object through operator delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00d4bd30
FUN_00d4bc00* FUN_00d4bc00::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->FUN_00d4bc00::~FUN_00d4bc00();
    if (uiFlags & 1)
        FUN_00d4bc00::operator delete(this);
    return this;
}
}  // namespace fnv_00d4bd30

namespace fnv_00d4be00 {
void* __cdecl FUN_00c85750(void);

struct FUN_00d4b400_Obj
{
    void FUN_00d4b400();
};

struct FUN_00d4be00_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, unsigned short nbytes);
};

struct FUN_00c85750_Ret
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d4be00_Allocator* allocator;
};

class FUN_00d4be00_cls : public hkpStorageMeshShape
{
  public:
    FUN_00d4be00_cls* FUN_00d4be00(int flags);
};

// @fnv 0x00d4be00
FUN_00d4be00_cls* FUN_00d4be00_cls::FUN_00d4be00(int flags)
{
    ((FUN_00d4b400_Obj*)this)->FUN_00d4b400();
    if (flags & 1)
    {
        FUN_00c85750_Ret* mem = (FUN_00c85750_Ret*)FUN_00c85750();
        FUN_00d4be00_Allocator* alloc = mem->allocator;
        alloc->ReleaseBlock(this, m_usMemSizeAndFlags);
    }
    return this;
}
}  // namespace fnv_00d4be00

struct hkAllocatorD4B4
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4B4
{
    int unk00, unk04, unk08, unk0C;
    hkAllocatorD4B4* m_pkHeap;
    hkAllocatorD4B4& heap()
    {
        return *m_pkHeap;
    }
};

namespace hkRouterD4B4 {
extern "C" hkMemoryRouterD4B4* __cdecl FUN_00c85750() throw();
}

template <typename T> struct hkArrayD4B4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void _clearAndDeallocate(hkAllocatorD4B4& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD4B4() throw()
    {
        _clearAndDeallocate(hkRouterD4B4::FUN_00c85750()->heap());
    }
};

class hkRefD4B4
{
  public:
    void FUN_00c905b0() throw();
};

class hkBaseAD4B4
{
  public:
    virtual ~hkBaseAD4B4() throw();
    int unk04, unk08, unk0C;
};

class hkBaseBD4B4
{
  public:
    virtual void V0() throw();
};

class FUN_00d4bd60 : public hkBaseAD4B4, public hkBaseBD4B4
{
  public:
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;

    virtual ~FUN_00d4bd60() throw();
};

class FUN_00d4b400 : public FUN_00d4bd60
{
  public:
    hkArrayD4B4<hkRefD4B4*> m_children;

    virtual ~FUN_00d4b400() throw();
    virtual void V0() throw();
};

// Destructor that calls FUN_00c905b0 on each element of m_children.
// @fnv 0x00d4b400
FUN_00d4b400::~FUN_00d4b400() throw()
{
    for (int i = 0; i < m_children.GetLogicalSize(); i++)
    {
        m_children.m_data[i]->FUN_00c905b0();
    }
}

class hkRefObjD4BB
{
  public:
    hkRefObjD4BB()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjD4BB();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class hkArrayD4BB
{
  public:
    hkArrayD4BB() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class FUN_00d4bbb0 : public hkRefObjD4BB
{
  public:
    hkArrayD4BB<int> m_array08;
    hkArrayD4BB<int> m_array14;
    hkArrayD4BB<int> m_array20;
    hkArrayD4BB<int> m_array2C;
    hkArrayD4BB<int> m_array38;
    hkArrayD4BB<int> m_array44;

    FUN_00d4bbb0();
    virtual ~FUN_00d4bbb0();
};

// Default constructor for FUN_00d4bbb0 that leaves the inherited hkRefObjD4BB and the six hkArrayD4BB<int> members at their default-initialized state.
// @fnv 0x00d4bbb0
FUN_00d4bbb0::FUN_00d4bbb0()
{}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual inherited through a second base.
struct PrimaryBase
{
    virtual void FUN_00d4bdf0();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d4bdf0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d4bdf0
    virtual void FUN_00d4bdf0();
};

Derived::Derived()
{}

extern "C" void _ReadWriteBarrier();

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct Alloc480
{
    virtual void V0() throw();
    virtual void* V1(int) throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
void __cdecl FUN_00c908c0(void* heap, void* arr, int newCap, int elemSize);
extern float DAT_01267e30;
struct SubpartFlags480
{
    int vertices, stride, numVertices, indices;
    unsigned char indexType, materialIndexType;
    unsigned short flags;
};

static __declspec(noinline) int __cdecl FUN_00d4b390(int a, int n)
{
    switch (a)
    {
    case 1:
        return n + 2;
    case 2:
        return 2 * n + 1;
    default:
        return 3 * n;
    }
}

struct Trivial480
{
};
struct Complex480
{
};
struct CopyOps480
{
    template <class T> static __forceinline void initialize(T*, int, Trivial480)
    {}
    template <class T> static __forceinline void fill(T* dest, int count, const T& value, Trivial480)
    {
        for (int j = 0; j < count; ++j)
            dest[j] = value;
    }
    template <class T> static __forceinline void fill(T* dest, int count, const T& value, Complex480)
    {
        for (int j = 0; j < count; ++j)
        {
            T* slot = dest + j;
            __assume(slot != 0);
            new (slot) T(value);
        }
    }
};
struct HeapPolicy480
{
    __forceinline Alloc480& get(const void*)
    {
        return (Alloc480&)FUN_00c85750().heap();
    }
};
template <class T> struct CoreArray480
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* data480()
    {
        return m_data;
    }
    T& back480()
    {
        return m_data[m_iElementCount - 1];
    }
    T* last480()
    {
        return m_data + m_iElementCount - 1;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int n)
    {
        return m_data[n];
    }
    const T& operator[](int n) const
    {
        return m_data[n];
    }
    __forceinline void reserveHeap480(Alloc480& heap, int needed)
    {
        int capacity = getCapacity();
        if (capacity < needed)
        {
            int doubled = 2 * capacity;
            int result = needed < doubled ? doubled : needed;
            FUN_00c908c0(&heap, this, result, sizeof(T));
        }
    }
    __forceinline T* appendHeap480(Alloc480& heap, int count)
    {
        int oldSize = m_iElementCount;
        reserveHeap480(heap, m_iElementCount + count);
        CopyOps480::initialize(m_data + m_iElementCount, count, Trivial480());
        m_iElementCount += count;
        return m_data + oldSize;
    }
    __forceinline void pushHeap480(Alloc480& heap, const T& value)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
        CopyOps480::fill(m_data + m_iElementCount, 1, value, Trivial480());
        m_iElementCount++;
    }
};
template <class T> struct Arr480 : CoreArray480<T>
{
    __forceinline void growIfFull()
    {
        Alloc480& heap = HeapPolicy480().get(this);
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
    }
    __forceinline void growIfFull2()
    {
        growIfFull();
    }
    __forceinline void AddBack(const T& value)
    {
        pushHeap480(HeapPolicy480().get(this), value);
    }
    __forceinline void pushBack2(const T& value)
    {
        AddBack(value);
    }
    __forceinline T* appendRange(int count)
    {
        return appendHeap480(HeapPolicy480().get(this), count);
    }
    __forceinline T* appendRange2(int count)
    {
        return appendRange(count);
    }
    __forceinline T* appendRangeP(int count)
    {
        return appendRange(count);
    }
};
template <class Arr> __forceinline void GrowIfFull480(Arr& arr, int elemSize)
{
    hkMemoryRouterD4B& router = FUN_00c85750();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router.m_pStreamAllocator, &arr, elemSize);
}
template <class Arr> __forceinline void ReserveCount480(Arr& arr, int count, int elemSize)
{
    Alloc480* heap = (Alloc480*)&FUN_00c85750().heap();
    int cap = arr.m_iCapacityState & 0x3fffffff;
    int need = arr.m_iElementCount + count;
    if (cap < need)
    {
        int newCap = cap + cap;
        if (newCap < need)
            newCap = need;
        FUN_00c908c0(heap, &arr, newCap, elemSize);
    }
}

__forceinline hkpMeshShapeSubpartD4B* ExpandInit480(hkArrayD4B<hkpMeshShapeSubpartD4B>& arr)
{
    GrowIfFull480(arr, 0x38);
    hkpMeshShapeSubpartD4B* e = &arr.m_data[arr.m_iElementCount];
    if (e)
    {
        ((SubpartFlags480*)e)->materialIndexType = 1;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk30 = 1;
        e->unk28 = 0;
        e->unk20 = 0;
        e->unk34 = -1;
        e->unk18 = 0;
    }
    return &arr.m_data[arr.m_iElementCount++];
}

struct Storage480
{
    int vptr;
    unsigned short GetAllocationSize;
    unsigned short refCount;
    Arr480<float> verts;
    Arr480<unsigned short> idx16;
    Arr480<int> idx32;
    Arr480<unsigned char> mat8;
    Arr480<int> extra;
    Arr480<unsigned short> mat16;
    Storage480* FUN_00d4bbb0();
};

// Copies a mesh subpart's vertex, index, material, and extra data into owned storage arrays and updates the subpart's pointers and strides.
// @fnv 0x00d4b480
void FUN_00dcd310::FUN_00d4b480(const hkpMeshShapeSubpartD4B& kSubpart) throw()
{
    hkpMeshShapeSubpartD4B* pSubpart = ExpandInit480(m_kSubparts);

    Storage480* storage = (Storage480*)((Alloc480*)&FUN_00c85750().heap())->V1(0x50);
    storage->GetAllocationSize = 0x50;
    storage = storage->FUN_00d4bbb0();

    Arr480<Storage480*>& arr60 = (Arr480<Storage480*>&)static_cast<FUN_00d4bab0*>(this)->m_60;
    arr60.AddBack(storage);
    storage = arr60.m_data[arr60.m_iElementCount - 1];
    int numFloats = kSubpart.unk08 * 3;

    {
        Arr480<float>& verts = storage->verts;
        float* dst = verts.appendRange(numFloats);
        const float* src = (const float*)kSubpart.unk00;
        for (int i = 0; i < kSubpart.unk08; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst += 3;
            src = (const float*)((const char*)src + kSubpart.unk04);
        }
        pSubpart->unk00 = (int)verts.m_data;
        pSubpart->unk04 = 12;
        pSubpart->unk08 = kSubpart.unk08;
    }

    int idxDst;
    if (((const SubpartFlags480*)&kSubpart)->indexType == 1)
    {
        int a = (int)((unsigned int)kSubpart.unk14 >> 1);
        int iClamped = a;
        if (iClamped > 2)
            iClamped = 3;
        pSubpart->unk14 = iClamped + iClamped;
        int numIndices = FUN_00d4b390(a, kSubpart.unk1C);
        Arr480<unsigned short>& arr = storage->idx16;
        unsigned short* dst = arr.appendRange(numIndices);
        idxDst = (int)dst;
        const unsigned short* src = (const unsigned short*)kSubpart.unk0C;
        for (int i = 0; i < kSubpart.unk1C; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = (unsigned short*)((char*)dst + pSubpart->unk14);
            src = (const unsigned short*)((const char*)src + kSubpart.unk14);
        }
    }
    else
    {
        int a = (int)((unsigned int)kSubpart.unk14 >> 2);
        int iClamped = a;
        if (iClamped > 2)
            iClamped = 3;
        pSubpart->unk14 = (iClamped << 2);
        int numIndices = FUN_00d4b390(a, kSubpart.unk1C);
        Arr480<int>& arr = storage->idx32;
        int* dst = arr.appendRange2(numIndices);
        idxDst = (int)dst;
        const int* src = (const int*)kSubpart.unk0C;
        for (int i = 0; i < kSubpart.unk1C; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = (int*)((char*)dst + pSubpart->unk14);
            src = (const int*)((const char*)src + kSubpart.unk14);
        }
    }

    ((SubpartFlags480*)pSubpart)->indexType = ((const SubpartFlags480*)&kSubpart)->indexType;
    pSubpart->unk1C = kSubpart.unk1C;
    pSubpart->unk18 = kSubpart.unk18;
    pSubpart->unk0C = idxDst;
    ((SubpartFlags480*)pSubpart)->materialIndexType = ((const SubpartFlags480*)&kSubpart)->materialIndexType;

    const void* materialIndices = (const void*)kSubpart.unk20;
    if (materialIndices != 0)
    {
        if (((const SubpartFlags480*)&kSubpart)->materialIndexType == 1)
        {

            if (kSubpart.unk24 == 0)
            {
                storage->mat8.pushBack2(*(const unsigned char*)materialIndices);
                pSubpart->unk20 = (int)&storage->mat8.back480();
            }
            else
            {
                unsigned char* dst = storage->mat8.appendRange(kSubpart.unk1C);
                pSubpart->unk20 = (int)dst;
                const unsigned char* src = (const unsigned char*)kSubpart.unk20;
                for (int i = 0; i < kSubpart.unk1C; i++)
                {
                    dst[i] = src[0];
                    src += kSubpart.unk24;
                }
            }
        }
        else
        {
            Arr480<unsigned short>& arr = storage->mat16;
            if (kSubpart.unk24 == 0)
            {
                arr.pushBack2(*(const unsigned short*)materialIndices);
                pSubpart->unk20 = (int)(arr.m_data + arr.m_iElementCount - 1);
            }
            else
            {
                unsigned short* dst = arr.appendRange(kSubpart.unk1C);
                pSubpart->unk20 = (int)dst;
                const unsigned short* src = (const unsigned short*)kSubpart.unk20;
                for (int i = 0; i < kSubpart.unk1C; i++)
                {
                    dst[i] = src[0];
                    src = (const unsigned short*)((const char*)src + kSubpart.unk24);
                }
            }
        }
        int matStride = kSubpart.unk24;
        pSubpart->unk24 = matStride;
        if (matStride != 0)
        {
            switch ((signed char)((SubpartFlags480*)pSubpart)->materialIndexType)
            {
            case 1:
                pSubpart->unk24 = 1;
                break;
            case 2:
                pSubpart->unk24 = 2;
                break;
            }
        }
    }
    else
    {
        pSubpart->unk20 = 0;
        pSubpart->unk24 = 0;
    }

    if (pSubpart->unk20 != 0)
    {
        Arr480<int>& arr = storage->extra;
        if (kSubpart.unk2C == 0)
        {
            const int* pExtraSrc = (const int*)kSubpart.unk28;
            arr.pushBack2(*pExtraSrc);
            pSubpart->unk2C = 0;
            pSubpart->unk30 = 1;
        }
        else
        {
            int* dst = arr.appendRange(kSubpart.unk30);
            const int* pExtraSrc = (const int*)kSubpart.unk28;
            for (int i = 0; i < kSubpart.unk30; i++)
            {
                dst[i] = pExtraSrc[0];
                pExtraSrc = (const int*)((const char*)pExtraSrc + kSubpart.unk2C);
            }
            pSubpart->unk2C = 4;
            pSubpart->unk30 = kSubpart.unk30;
        }
        pSubpart->unk28 = (int)arr.m_data;
    }
    else
    {
        pSubpart->unk30 = 1;
        pSubpart->unk28 = (int)&DAT_01267e30;
        pSubpart->unk2C = 0;
        pSubpart->unk20 = (int)&DAT_01267e30;
    }
    pSubpart->unk34 = kSubpart.unk34;
}

namespace fnv_00d4ba30 {
struct FinishingFlag
{
    int m_bFinishing;
};

template <class T> struct hkArrayD4B
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* begin()
    {
        return m_data;
    }
};

class hkpShapeContainerD4B
{
  public:
    virtual ~hkpShapeContainerD4B();
};

struct hkpMeshSubpartD4B
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    unsigned char m_ucIndexStridingType;
    unsigned char m_iMaterialIndexType;
    short unk12;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iNumTriangles;
    int m_iIndexStriding;
    int m_iTriangleOffset;
};

class hkpShapeD4B
{
  public:
    virtual ~hkpShapeD4B();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};

class FUN_00dcd380 : public hkpShapeD4B, public hkpShapeContainerD4B
{
  public:
    virtual ~FUN_00dcd380();
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    hkArrayD4B<hkpMeshSubpartD4B> m_kSubparts;

    FUN_00dcd380(FinishingFlag flag);
};

struct hkpSubpartStorageD4B
{
    void* vtbl;
    int m_memSizeAndRefCount;
    hkArrayD4B<float> m_kVertices;
    hkArrayD4B<unsigned short> m_kIndices16;
    hkArrayD4B<unsigned int> m_kIndices32;
    hkArrayD4B<unsigned char> m_kMaterialIndices8;
    hkArrayD4B<unsigned int> m_kMaterials;
    hkArrayD4B<unsigned short> m_kMaterialIndices16;
};

class FUN_00d4ba30 : public FUN_00dcd380
{
  public:
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkArrayD4B<hkpSubpartStorageD4B*> m_kStorage;

    FUN_00d4ba30(FinishingFlag flag);
    virtual ~FUN_00d4ba30();
};

// Constructor: calls the base constructor and, if flag.m_bFinishing is set, points each subpart's data fields at the begin of the matching storage arrays.
// @fnv 0x00d4ba30
FUN_00d4ba30::FUN_00d4ba30(FinishingFlag flag) : FUN_00dcd380(flag)
{
    if (flag.m_bFinishing)
    {
        for (int i = 0; i < m_kSubparts.GetLogicalSize(); i++)
        {
            hkpMeshSubpartD4B& part = m_kSubparts[i];
            hkpSubpartStorageD4B& storage = *m_kStorage[i];
            part.m_pMaterialIndexBase = storage.m_kVertices.begin();
            if (part.m_ucIndexStridingType == 1)
                part.m_pMaterialDataBase = storage.m_kIndices16.begin();
            else
                part.m_pMaterialDataBase = storage.m_kIndices32.begin();
            if (part.m_iMaterialIndexType == 1)
                part.m_pVertexBase = storage.m_kMaterialIndices8.begin();
            else
                part.m_pVertexBase = storage.m_kMaterialIndices16.begin();
            part.m_pIndexBase = storage.m_kMaterials.begin();
        }
    }
}
}  // namespace fnv_00d4ba30

namespace fnv_00d4bd60 {
class hkMemoryAllocatorD4BD
{
  public:
    virtual ~hkMemoryAllocatorD4BD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD4BD
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD4BD* m_pStreamAllocator;

    hkMemoryAllocatorD4BD& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD4BD& __cdecl FUN_00c85750() throw();

template <class T> class hkArrayD4BD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD4BD() throw()
    {
        hkMemoryAllocatorD4BD& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD4BD {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShape : public hkReferencedObject
{
  public:
    unsigned long m_ulUserData;
    int m_type;
};

class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer() throw()
    {}
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
  public:
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct TriangleD4BD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34;
};
}

class FUN_00d4bd60
{
  public:
    ~FUN_00d4bd60();

    hkD4BD::hkpShapeCollection m_kCollection;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    hkArrayD4BD<hkD4BD::TriangleD4BD> m_kTriangles;
    hkArrayD4BD<unsigned short> m_kMaterialIndices;
};

// Destructor for a triangle collection object that owns a shape collection, a triangle array, and a material index array.
// @fnv 0x00d4bd60
FUN_00d4bd60::~FUN_00d4bd60()
{}
}  // namespace fnv_00d4bd60

namespace fnv_00dcebd0 {
template <typename T> static __forceinline void CopyElements(T* dest, const T* src, int count)
{
    for (int index = 0; index < count; ++index)
        dest[index] = src[index];
}
struct FUN_00dcebd0_Allocator
{
    virtual ~FUN_00dcebd0_Allocator();
    virtual void unknown04();
    virtual void unknown08();
    virtual void* AllocateBufferWithSize(int& requestedBytes);
    virtual void ReturnMemory(void* buffer, int byteCount);
};
struct FUN_00dcebd0_Router
{
    void* m_unknown00;
    void* m_unknown04;
    void* m_unknown08;
    void* m_unknown0c;
    FUN_00dcebd0_Allocator* m_pThreadAllocator;
};
FUN_00dcebd0_Router* __cdecl FUN_00c85750();

struct FUN_00dcebd0_Class
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    int m_reserved10;
    unsigned char m_bDisableWelding;
    unsigned char m_eCollectionType;
    unsigned short m_reserved16;
    int m_reserved18;
    int m_reserved1c;
    float m_scalingX, m_scalingY, m_scalingZ, m_scalingW;
    int m_iNumBitsForSubpartIndex;
    void* m_subpartsData;
    int m_subpartsSize;
    int m_subpartsCapacity;
    void* m_weldingInfoData;
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void FUN_00d06290(const FUN_00dcebd0_Class& source);
    void FUN_00dcebd0(const FUN_00dcebd0_Class& source);
};
// Calls FUN_00d06290(source), then copies source's int array into this, reallocating through the thread allocator when capacity is smaller.
// @fnv 0x00dcebd0
void FUN_00dcebd0_Class::FUN_00dcebd0(const FUN_00dcebd0_Class& source)
{
    FUN_00d06290(source);
    FUN_00dcebd0_Allocator* allocator = FUN_00c85750()->m_pThreadAllocator;
    int capacity = m_iCapacityState & 0x3fffffff;
    if (capacity < source.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000u) == 0)
        {
            allocator->ReturnMemory(m_data, capacity * sizeof(int));
        }
        int bytes = source.m_iElementCount * sizeof(int);
        m_data = static_cast<int*>(allocator->AllocateBufferWithSize(bytes));
        m_iCapacityState = bytes / 4;
    }
    m_iElementCount = source.m_iElementCount;
    CopyElements(m_data, source.m_data, m_iElementCount);
}
}  // namespace fnv_00dcebd0
