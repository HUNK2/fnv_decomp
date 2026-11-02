
// src/havok/physics/dynamics/constraint/constraintkit/hkpconstraintconstructionkit.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/constraintkit/hkpconstraintconstructionkit.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    double m128_f64[2];
} __m128;

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
extern "C" void _mm_store_ps(float* p, __m128 v);

struct FUN_00d522b0_Ctx
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_10;
};

struct FUN_00d522b0_Vec
{
    void* m_ptr;
    int m_uiItemCount;
    int m_cap;
};

struct FUN_00d522b0_P
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00d522b0_Vec m_verts;
    FUN_00d522b0_Vec m_cmds;
};

extern void* __cdecl FUN_00c85750(void);
extern void __cdecl ResizeAudioStream(void* apCtx, void* apVec, int aElemSize);

struct FUN_00d522b0_cls
{
    int m_00;
    FUN_00d522b0_P* m_04;
    int AddVertexCommand(unsigned char aFlag, float aX, float aY);
};

// @fnv 0x00d522b0
int FUN_00d522b0_cls::AddVertexCommand(unsigned char aFlag, float aX, float aY)
{
    FUN_00d522b0_Vec* pCmds = &m_04->m_cmds;
    FUN_00d522b0_Ctx* ctx = (FUN_00d522b0_Ctx*)FUN_00c85750();
    if (pCmds->m_uiItemCount == (pCmds->m_cap & 0x3fffffff))
        ResizeAudioStream(ctx->m_10, pCmds, 4);
    int* piSlot = (int*)pCmds->m_ptr + pCmds->m_uiItemCount;
    *piSlot = 0x11;
    *piSlot = 0x11;
    ++pCmds->m_uiItemCount;

    int flag = aFlag;

    pCmds = &m_04->m_cmds;
    ctx = (FUN_00d522b0_Ctx*)FUN_00c85750();
    if (pCmds->m_uiItemCount == (pCmds->m_cap & 0x3fffffff))
        ResizeAudioStream(ctx->m_10, pCmds, 4);
    int* piFlagSlot = (int*)pCmds->m_ptr + pCmds->m_uiItemCount;
    *piFlagSlot = flag;
    *piFlagSlot = flag;
    ++pCmds->m_uiItemCount;

    __m128 v = _mm_setr_ps(aX, aY, 0.0f, 0.0f);
    int iOldVertexCount = m_04->m_verts.m_uiItemCount;

    FUN_00d522b0_Vec* vert = &m_04->m_verts;
    ctx = (FUN_00d522b0_Ctx*)FUN_00c85750();
    if (vert->m_uiItemCount == (vert->m_cap & 0x3fffffff))
        ResizeAudioStream(ctx->m_10, vert, 16);
    _mm_store_ps((float*)((char*)vert->m_ptr + (vert->m_uiItemCount << 4)), v);
    ++vert->m_uiItemCount;

    FUN_00d522b0_P* p = m_04;
    p->m_04 += 0x30;
    p->m_08 += 1;
    p->m_0c += 1;
    return iOldVertexCount;
}

struct __declspec(align(16)) FUN_00c7f690_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00c7f690(const __m128* m, const __m128* v);
};

struct FUN_00d52140_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_18;
    unsigned char m_19;
    int FUN_00d52000(FUN_00c7f690_cls* t);
    void FUN_00d520a0(FUN_00c7f690_cls* t);
    int FUN_00d52140(char* a1, char* a2, const __m128* a3);
};

// @fnv 0x00d52140
int FUN_00d52140_cls::FUN_00d52140(char* a1, char* a2, const __m128* a3)
{
    FUN_00c7f690_cls t1;
    FUN_00c7f690_cls t2;
    t1.FUN_00c7f690((const __m128*)(a1 + 0xf0), a3);
    t2.FUN_00c7f690((const __m128*)(a2 + 0xf0), a3);
    int iResult = this->FUN_00d52000(&t1);
    this->FUN_00d520a0(&t2);
    this->m_18 = 1;
    this->m_19 = 1;
    return iResult;
}

struct hkMemoryAllocatorD;

struct hkMemoryRouterD
{
    unsigned int unk, unkCur, unkValue, unk0C;
    hkMemoryAllocatorD* m_pStreamAllocator;

    hkMemoryAllocatorD& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(hkMemoryAllocatorD* pkAlloc, void* pkArray, int iElemSize);

struct hkVector4D521
{
    __m128 m_vComponents;

    void operator=(const hkVector4D521& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
};

template <class T> __forceinline void constructWithCopyD(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T> struct hkArrayD
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorD& kAlloc = static_cast<hkMemoryRouterD*>(FUN_00c85750())->heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        }
        constructWithCopyD<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct hkGeometryBufferD
{
    unsigned int unk;
    int m_iNumBytes;
    int m_iNumCommands;
    int m_iNumParams;
    hkArrayD<hkVector4D521> m_params;
    hkArrayD<int> m_commands;
};

class hkCommandWriterD
{
  public:
    int FUN_00d521b0(unsigned char ucKind, float fX, float fY);

    unsigned int unk;
    hkGeometryBufferD* m_pBuffer;
};

// Appends a command and a 2D vector parameter to the geometry buffer, updates byte/command/param counts, and returns the parameter index.
// @fnv 0x00d521b0
int hkCommandWriterD::FUN_00d521b0(unsigned char ucKind, float fX, float fY)
{
    m_pBuffer->m_commands.AddBack(0x10);
    m_pBuffer->m_commands.AddBack(ucKind);
    const int iIndex = m_pBuffer->m_params.GetLogicalSize();
    hkVector4D521 kParam;
    kParam.set(fX, fY, 0.0f, 0.0f);
    m_pBuffer->m_params.AddBack(kParam);
    hkGeometryBufferD* pkBuffer = m_pBuffer;
    pkBuffer->m_iNumBytes += 0x40;
    pkBuffer->m_iNumCommands += 1;
    pkBuffer->m_iNumParams += 1;
    return iIndex;
}

#include <math.h>
inline void FillWords328(int* dest, int n, const int& value)
{
    for (int i = 0; i < n; ++i)
        dest[i] = value;
}

extern float DAT_01011d78;
extern float DAT_01016410;

struct Draw328_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

struct Draw328_intarr
{
    int* data;
    int count;
    unsigned int capFlags;
};

struct Draw328_vecarr
{
    __m128* data;
    int count;
    unsigned int capFlags;
};

struct Draw328_mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Draw328_vecarr m_vec;
    Draw328_intarr m_auiHeaderValues;
};

struct Draw328_cls
{
    int unk00;
    Draw328_mgr* m_pMgr;

    unsigned int AppendHeaderAndVector(unsigned char a1, float a2);
};

// Appends 0x12 and a1 to m_auiHeaderValues, appends a cosf(a2) vector to m_vec, and returns the previous m_vec count.
// @fnv 0x00d523b0
unsigned int Draw328_cls::AppendHeaderAndVector(unsigned char a1, float a2)
{
    Draw328_intarr* ints = &m_pMgr->m_auiHeaderValues;
    Draw328_Holder* holder = (Draw328_Holder*)FUN_00c85750();
    if (ints->count == (int)(ints->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, ints, 4);
    }
    FillWords328(ints->data + ints->count, 1, 0x12);
    ++ints->count;

    int tag = a1;
    ints = &m_pMgr->m_auiHeaderValues;
    holder = (Draw328_Holder*)FUN_00c85750();
    if (ints->count == (int)(ints->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, ints, 4);
    }
    FillWords328(ints->data + ints->count, 1, tag);
    ++ints->count;

    float x = cosf(a2);
    __m128 v = _mm_setr_ps(x, DAT_01016410, DAT_01011d78, DAT_01011d78);

    Draw328_mgr* mgr = m_pMgr;
    unsigned int uiIndex = (unsigned int)mgr->m_vec.count;

    Draw328_vecarr* vec = &mgr->m_vec;
    holder = (Draw328_Holder*)FUN_00c85750();
    if (vec->count == (int)(vec->capFlags & 0x3fffffffu))
    {
        ResizeAudioStream(holder->m_pAllocator, vec, 0x10);
    }
    vec->data[vec->count] = v;
    vec->count++;

    mgr = m_pMgr;
    mgr->unk04 += 0x30;
    mgr->unk08++;
    mgr->unk0c++;
    return uiIndex;
}

struct hkMemAlloc;

struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAlloc* m_pStreamAllocator;
    hkMemAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline MemRouter* getRouter()
{
    return (MemRouter*)FUN_00c85750();
}

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _pushBack(hkMemAlloc& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void AddBack(const T& t)
    {
        _pushBack(getRouter()->heap(), t);
    }
};

struct hkVec4
{
    __m128 m_vComponents;
    __forceinline hkVec4()
    {}
    __forceinline hkVec4(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct GeomBuffer
{
    int m_00;
    int m_iVertexCount;
    int m_uiVertexCount;
    int m_numPrims;
    hkArr<hkVec4> m_verts;
    hkArr<int> m_cmds;
};

struct GeomWriter
{
    int m_00;
    GeomBuffer* m_buffer;
    int FUN_00d524d0(unsigned char a1, unsigned char a2, float a3, float a4);
};

// Appends command 0x13 with a1 and a2, then a vector (sin(a3), sin(a4), 0, 0) to the buffer, updates its counters, and returns the vector's index.
// @fnv 0x00d524d0
int GeomWriter::FUN_00d524d0(unsigned char a1, unsigned char a2, float a3, float a4)
{
    m_buffer->m_cmds.AddBack(0x13);
    m_buffer->m_cmds.AddBack(a1);
    m_buffer->m_cmds.AddBack(a2);
    hkVec4 v;
    v.set(sin(a3), sin(a4), 0.0f, 0.0f);
    int index = m_buffer->m_verts.m_iElementCount;
    m_buffer->m_verts.AddBack(v);
    GeomBuffer* b = m_buffer;
    b->m_uiVertexCount++;
    b->m_iVertexCount += 0x30;
    b->m_numPrims++;
    return index;
}
