
// src/havok/common/scenedata/mesh/hkxvertexbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxvertexbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxVertexBuffer.h"

struct FUN_00e3e220_Class
{
    void ClearFields();
};

// @fnv 0x00e3e220
void FUN_00e3e220_Class::ClearFields()
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x1c) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x44) = 0;
    *(int*)((char*)this + 0x48) = 0;
    *(int*)((char*)this + 0x4c) = 0;
    *(int*)((char*)this + 0x50) = 0;
}

struct hkAllocatorE3E2
{
    virtual void V0() throw();
};

struct hkMemoryRouterE3E2
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    hkAllocatorE3E2* m_pkHeap;
    hkAllocatorE3E2& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterE3E2* __cdecl FUN_00c85750() throw();

void __cdecl FUN_00c908c0(hkAllocatorE3E2& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> struct hkArrayE3E2
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkAllocatorE3E2& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(FUN_00c85750()->heap(), n);
        m_iElementCount = n;
    }
};

class hkxVertexBufferVertexDataE3E2
{
  public:
    hkArrayE3E2<hkVector4> m_kVectorData;
    hkArrayE3E2<hkReal> m_kFloatData;
    hkArrayE3E2<hkUint32> m_kUInt32Data;
    hkArrayE3E2<hkUint16> m_kUInt16Data;
    hkArrayE3E2<hkUint8> m_kUInt8Data;
    hkUint32 m_uiVertexCount;
    hkUint32 m_uiVectorDataStride;
    hkUint32 m_uiFloatDataStride;
    hkUint32 m_uiUInt32DataStride;
    hkUint32 m_uiUInt16DataStride;
    hkUint32 m_uiUInt8DataStride;

    void ResizeVertexData(int iTotalVertexCount) throw();
};

// @fnv 0x00e3e250
void hkxVertexBufferVertexDataE3E2::ResizeVertexData(int aiVertexCount) throw()
{
    m_uiVertexCount = aiVertexCount;
    m_kUInt8Data.SetSizeAndGrow(m_uiUInt8DataStride * aiVertexCount);
    m_kUInt16Data.SetSizeAndGrow(m_uiUInt16DataStride * aiVertexCount / sizeof(hkUint16));
    m_kUInt32Data.SetSizeAndGrow(m_uiUInt32DataStride * aiVertexCount / sizeof(hkUint32));
    m_kFloatData.SetSizeAndGrow(m_uiFloatDataStride * aiVertexCount / sizeof(hkReal));
    m_kVectorData.SetSizeAndGrow(m_uiVectorDataStride * aiVertexCount / sizeof(hkVector4));
}

struct hkFinishLoadedObjectFlagE3E3
{
    int m_bFinishing;
};

template <class T> class hkArrayE3E3
{
  public:
    hkArrayE3E3(hkFinishLoadedObjectFlagE3E3 flag)
    {}

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkReferencedObjectE3E3
{
  public:
    hkReferencedObjectE3E3(hkFinishLoadedObjectFlagE3E3 flag)
    {}
    virtual ~hkReferencedObjectE3E3();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct hkxVertexBufferVertexDataE3E3
{
    hkxVertexBufferVertexDataE3E3(hkFinishLoadedObjectFlagE3E3 flag)
        : m_kVectorData(flag), m_kFloatData(flag), m_kUInt32Data(flag), m_kUInt16Data(flag), m_kUInt8Data(flag)
    {}

    hkArrayE3E3<float> m_kVectorData;
    hkArrayE3E3<float> m_kFloatData;
    hkArrayE3E3<unsigned int> m_kUInt32Data;
    hkArrayE3E3<unsigned short> m_kUInt16Data;
    hkArrayE3E3<unsigned char> m_kUInt8Data;
    unsigned int m_uiVertexCount;
    unsigned int m_uiVectorDataStride;
    unsigned int m_uiFloatDataStride;
    unsigned int m_uiUInt32DataStride;
    unsigned int m_uiUInt16DataStride;
    unsigned int m_uiUInt8DataStride;
};

class FUN_00e3df50
{
  public:
    FUN_00e3df50(hkFinishLoadedObjectFlagE3E3 flag) throw();

    int unk00;
    int unk04;
    int unk08;
};

class FUN_00e3e380 : public hkReferencedObjectE3E3
{
  public:
    FUN_00e3e380(hkFinishLoadedObjectFlagE3E3 flag) throw();
    virtual ~FUN_00e3e380();

    hkxVertexBufferVertexDataE3E3 m_data;
    FUN_00e3df50 m_kCreateDesc;
};

// @fnv 0x00e3e380
FUN_00e3e380::FUN_00e3e380(hkFinishLoadedObjectFlagE3E3 flag) throw()
    : hkReferencedObjectE3E3(flag), m_data(flag), m_kCreateDesc(flag)
{}

template <class T> class hkArrayE3E6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T* begin() const
    {
        return m_data;
    }
};

template <typename T> inline T min2E3E6(T a, T b)
{
    return a < b ? a : b;
}

void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

class hkxVertexDescriptionE3E6
{
  public:
    int unk00;
    int unk04;
    int unk08;

    bool Equals(const hkxVertexDescriptionE3E6& kOther) const throw();
    bool operator==(const hkxVertexDescriptionE3E6& kOther) const
    {
        return Equals(kOther);
    }
};

struct hkxVertexBufferDataE3E6
{
    hkArrayE3E6<unsigned int> m_kVectorData;
    hkArrayE3E6<float> m_kFloatData;
    hkArrayE3E6<unsigned int> m_kUInt32Data;
    hkArrayE3E6<unsigned short> m_kUInt16Data;
    hkArrayE3E6<unsigned char> m_kUInt8Data;
    unsigned int m_uiVertexCount;
    unsigned int m_uiVectorDataStride;
    unsigned int m_uiFloatDataStride;
    unsigned int m_uiUInt32DataStride;
    unsigned int m_uiUInt16DataStride;
    unsigned int m_uiUInt8DataStride;
};

class hkxVertexBufferE3E6
{
  public:
    int unk00;
    int unk04;
    hkxVertexBufferDataE3E6 m_data;
    hkxVertexDescriptionE3E6 m_kCreateDesc;

    void FUN_00e3e3a0(int iTotalVertexCount, const hkxVertexDescriptionE3E6& kDesc) throw();
    void FUN_00e3e030(const hkxVertexBufferE3E6& kOther, int iSrc, int iDst) throw();
    void CopyFrom(const hkxVertexBufferE3E6& kOther, bool bResizeToMatch) throw();
};

// @fnv 0x00e3e670
void hkxVertexBufferE3E6::CopyFrom(const hkxVertexBufferE3E6& kOther, bool bResizeToMatch) throw()
{
    bool bSameDesc = m_kCreateDesc == kOther.m_kCreateDesc;
    if (bResizeToMatch)
        FUN_00e3e3a0(kOther.m_data.m_uiVertexCount, m_kCreateDesc);

    if (bSameDesc)
    {
        unsigned int numVerts = min2E3E6(kOther.m_data.m_uiVertexCount, m_data.m_uiVertexCount);
        if (m_data.m_uiUInt8DataStride > 0)
            FUN_00cb1260(m_data.m_kUInt8Data.begin(), kOther.m_data.m_kUInt8Data.begin(),
                         m_data.m_uiUInt8DataStride * numVerts);
        if (m_data.m_uiUInt16DataStride > 0)
            FUN_00cb1260(m_data.m_kUInt16Data.begin(), kOther.m_data.m_kUInt16Data.begin(),
                         m_data.m_uiUInt16DataStride * numVerts);
        if (m_data.m_uiUInt32DataStride > 0)
            FUN_00cb1260(m_data.m_kUInt32Data.begin(), kOther.m_data.m_kUInt32Data.begin(),
                         m_data.m_uiUInt32DataStride * numVerts);
        if (m_data.m_uiFloatDataStride > 0)
            FUN_00cb1260(m_data.m_kFloatData.begin(), kOther.m_data.m_kFloatData.begin(),
                         m_data.m_uiFloatDataStride * numVerts);
        if (m_data.m_uiVectorDataStride > 0)
            FUN_00cb1260(m_data.m_kVectorData.begin(), kOther.m_data.m_kVectorData.begin(),
                         m_data.m_uiVectorDataStride * numVerts);
    }
    else
    {
        for (unsigned int i = 0; i < kOther.m_data.m_uiVertexCount; i++)
            FUN_00e3e030(kOther, i, i);
    }
}

namespace fnv_00e3e760 {
extern int DAT_0102e388;

struct FUN_00e3e760_VirtualTarget
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(void* data, unsigned int size);
};

struct FUN_00e3e760_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e3e760_VirtualTarget* unk10;
};

void* __cdecl FUN_00c85750();

struct FUN_00e3e760_Base
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    void FUN_00dfd680();
};

struct FUN_00e3e760_Class
{
    int unk00;
    int unk04;
    FUN_00e3e760_Base unk08;
    int unk5C;
    int unk60;
    int unk64;

    void FUN_00e3e760();
};

// @fnv 0x00e3e760
void FUN_00e3e760_Class::FUN_00e3e760()
{
    FUN_00e3e760_Holder* holder = (FUN_00e3e760_Holder*)FUN_00c85750();
    FUN_00e3e760_VirtualTarget* target = holder->unk10;

    int count = unk64;
    unk60 = 0;

    if (count & 0x80000000)
    {
        goto skip;
    }
    else
    {
        unsigned int size = (unsigned int)(count & 0x3FFFFFFF) * 12;
        target->vf10((void*)unk5C, size);
    }

skip:
    unk5C = 0;
    unk64 = 0x80000000;
    unk08.FUN_00dfd680();
    unk00 = (int)(unsigned int)&DAT_0102e388;
}
}  // namespace fnv_00e3e760

namespace fnv_00e3e7b0 {
class FUN_00e3e760
{
  public:
    ~FUN_00e3e760() throw();
};

class hkMemoryAllocatorXe3e7b0
{
  public:
    virtual ~hkMemoryAllocatorXe3e7b0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXe3e7b0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe3e7b0* m_pStreamAllocator;

    hkMemoryAllocatorXe3e7b0& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXe3e7b0& __cdecl FUN_00c85750() throw();

class hkObje3e7b0 : public FUN_00e3e760
{
  public:
    hkObje3e7b0* FUN_00e3e7b0(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObje3e7b0*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Runs the base destructor, frees this via operator delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00e3e7b0
hkObje3e7b0* hkObje3e7b0::FUN_00e3e7b0(unsigned int uiFlags) throw()
{
    this->FUN_00e3e760::~FUN_00e3e760();
    if (uiFlags & 1)
        hkObje3e7b0::operator delete(this);
    return this;
}
}  // namespace fnv_00e3e7b0

class MemoryUtils
{
  public:
    static void* CopyRegion(void* dst, const void* src, int size);
    static void* SetMemory(void* dst, int val, int size);
};

struct hkxVertexDescriptionElementDecl
{
    hkUint32 m_uiByteOffset;
    hkUint16 m_type;
    hkUint16 m_eDataUsage;
    hkUint32 m_uiByteStride;
};

struct DescHelper : hkxVertexDescription
{
    bool operator==(const hkxVertexDescription& other) const;
    const hkxVertexDescriptionElementDecl* getElementDecl(hkxVertexDescription::DataUsage usage,
                                                          int m_ucUsageIndex) const;
};

struct BufferHelper : hkxVertexBuffer
{
    void* getVertexDataPtr(const hkxVertexDescriptionElementDecl& decl);
    const void* getVertexDataPtr(const hkxVertexDescriptionElementDecl& decl) const;
    void FUN_00e3e030(const hkxVertexBuffer* src, int srcIndex, int dstIndex);
};

// Copies data between buffers, using stride-sized array copies for matching descriptions and per-element copies otherwise.
// @fnv 0x00e3e030
void BufferHelper::FUN_00e3e030(const hkxVertexBuffer* src, int srcIndex, int dstIndex)
{
    bool bSameDesc = (*(const DescHelper*)&m_kCreateDesc == src->m_kCreateDesc);
    unsigned int aiUsageCounts[257];
    MemoryUtils::SetMemory(aiUsageCounts, 0, sizeof(aiUsageCounts));

    if (dstIndex >= (int)m_data.m_uiVertexCount || srcIndex >= (int)src->m_data.m_uiVertexCount)
    {
        return;
    }

    if (bSameDesc)
    {
        if (m_data.m_uiUInt8DataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kUInt8Data.m_data, src->m_data.m_kUInt8Data.m_data,
                                    m_data.m_uiUInt8DataStride);
        }
        if (m_data.m_uiUInt16DataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kUInt16Data.m_data, src->m_data.m_kUInt16Data.m_data,
                                    m_data.m_uiUInt16DataStride);
        }
        if (m_data.m_uiUInt32DataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kUInt32Data.m_data, src->m_data.m_kUInt32Data.m_data,
                                    m_data.m_uiUInt32DataStride);
        }
        if (m_data.m_uiFloatDataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kFloatData.m_data, src->m_data.m_kFloatData.m_data,
                                    m_data.m_uiFloatDataStride);
        }
        if (m_data.m_uiVectorDataStride > 0)
        {
            MemoryUtils::CopyRegion(m_data.m_kVectorData.m_data, src->m_data.m_kVectorData.m_data,
                                    m_data.m_uiVectorDataStride);
        }
        return;
    }

    const DescHelper& srcDesc = *(const DescHelper*)&src->m_kCreateDesc;
    const BufferHelper* srcBuf = (const BufferHelper*)src;

    for (int i = 0; i < m_kCreateDesc.m_kElementDeclarations.m_iElementCount; ++i)
    {
        const hkxVertexDescriptionElementDecl& decl = m_kCreateDesc.m_kElementDeclarations.m_data[i];
        const hkxVertexDescriptionElementDecl* srcDecl = srcDesc.getElementDecl(
            (hkxVertexDescription::DataUsage)decl.m_eDataUsage, aiUsageCounts[decl.m_eDataUsage]);
        if (!srcDecl)
        {
            continue;
        }
        if (decl.m_type != srcDecl->m_type)
        {
            continue;
        }
        aiUsageCounts[decl.m_eDataUsage]++;
        void* dstData = getVertexDataPtr(decl);
        const void* srcData = srcBuf->getVertexDataPtr(*srcDecl);

        int size = 0;
        switch (decl.m_type)
        {
        case hkxVertexDescription::HKX_DT_UINT8:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_INT16:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_UINT32:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT:
            size = 4;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT2:
            size = 8;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT3:
            size = 16;
            break;
        case hkxVertexDescription::HKX_DT_FLOAT4:
            size = 16;
            break;
        }

        MemoryUtils::CopyRegion((char*)dstData + decl.m_uiByteStride * dstIndex,
                                (const char*)srcData + srcDecl->m_uiByteStride * srcIndex, size);
    }
}

extern "C" void _ReadWriteBarrier();

inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}
inline void __cdecl operator delete(void*, void*) throw()
{}
struct VertexDeclMatch
{
    unsigned int offset;
    unsigned short type;
    unsigned short usage;
    unsigned int stride;
    VertexDeclMatch()
    {
        offset = 0;
        type = 0;
        _ReadWriteBarrier();
        usage = 0;
        stride = 0;
    }
};
extern "C" void __cdecl ResizeAudioStream(hkAllocatorE3E2*, void*, int) throw();
struct DescriptionMatch
{
    VertexDeclMatch* data;
    int size;
    int capacity;
    void clear()
    {
        for (int i = 0; i < size; ++i)
            data[i].~VertexDeclMatch();
        size = 0;
    }
    VertexDeclMatch& AllocatePair()
    {
        hkAllocatorE3E2* alloc = &FUN_00c85750()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(alloc, this, sizeof(VertexDeclMatch));
        new (data + size) VertexDeclMatch;
        return data[size++];
    }
    bool Equals(const DescriptionMatch& other) const throw();
};
extern "C" void __cdecl ResizeAudioStream(hkAllocatorE3E2*, void*, int) throw();
struct VertexDataMatch
{
    hkArrayE3E2<hkVector4> vectors;
    hkArrayE3E2<float> floats;
    hkArrayE3E2<unsigned int> uint32s;
    hkArrayE3E2<unsigned short> uint16s;
    hkArrayE3E2<unsigned char> uint8s;
    unsigned int count;
    unsigned int vectorStride;
    unsigned int floatStride;
    unsigned int uint32Stride;
    unsigned int uint16Stride;
    unsigned int uint8Stride;
    __declspec(noinline) void ClearFields();
};
__declspec(noinline) void VertexDataMatch::ClearFields()
{
    vectors.m_iElementCount = 0;
    floats.m_iElementCount = 0;
    uint32s.m_iElementCount = 0;
    uint16s.m_iElementCount = 0;
    uint8s.m_iElementCount = 0;
    count = 0;
    vectorStride = 0;
    floatStride = 0;
    uint32Stride = 0;
    uint16Stride = 0;
    uint8Stride = 0;
}
struct VertexBufferMatch
{
    int unk00;
    int unk04;
    VertexDataMatch data;
    DescriptionMatch desc;
    void FUN_00e3e3a0(int n, const DescriptionMatch& input) throw();
};
// Rebuilds desc from input, computes offsets and strides, then sizes each data array for n vertices.
// @fnv 0x00e3e3a0
void VertexBufferMatch::FUN_00e3e3a0(int aiCount, const DescriptionMatch& input) throw()
{
    if (aiCount == data.count && input.Equals(desc))
        return;
    desc.clear();
    data.ClearFields();
    for (int i = 0; i < input.size; ++i)
    {
        const VertexDeclMatch& src = input.data[i];
        VertexDeclMatch& dst = desc.AllocatePair();
        dst.type = src.type;
        dst.usage = src.usage;
        switch (src.type)
        {
        case 1:
            dst.offset = data.uint8Stride;
            data.uint8Stride += 4;
            break;
        case 2:
            dst.offset = data.uint16Stride;
            data.uint16Stride += 4;
            break;
        case 3:
            dst.offset = data.uint32Stride;
            data.uint32Stride += 4;
            break;
        case 4:
            dst.offset = data.floatStride;
            data.floatStride += 4;
            break;
        case 5:
            dst.offset = data.floatStride;
            data.floatStride += 8;
            break;
        case 6:
        case 7:
            dst.offset = data.vectorStride;
            data.vectorStride += 16;
            break;
        }
    }
    for (int i = 0; i < desc.size; ++i)
    {
        VertexDeclMatch& dst = desc.data[i];
        switch (dst.type)
        {
        case 1:
            dst.stride = data.uint8Stride;
            break;
        case 2:
            dst.stride = data.uint16Stride;
            break;
        case 3:
            dst.stride = data.uint32Stride;
            break;
        case 4:
        case 5:
            dst.stride = data.floatStride;
            break;
        case 6:
        case 7:
            dst.stride = data.vectorStride;
            break;
        }
    }
    data.count = aiCount;
    data.uint8s.SetSizeAndGrow(data.uint8Stride * aiCount);
    data.uint16s.SetSizeAndGrow((data.uint16Stride * aiCount) / 2);
    data.uint32s.SetSizeAndGrow((data.uint32Stride * aiCount) / 4);
    data.floats.SetSizeAndGrow((data.floatStride * aiCount) / 4);
    data.vectors.SetSizeAndGrow((data.vectorStride * aiCount) / 16);
}
