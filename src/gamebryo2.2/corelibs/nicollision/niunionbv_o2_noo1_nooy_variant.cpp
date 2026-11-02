
// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_nooy_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// MSVC 2008 cl does not accept the .inl extension as a source file, so this identical unit is compiled as .cpp by the matcher; the .inl is the source of record.
//
//
// gamebryo2.2/corelibs/nicollision/niunionbv.inl
//
// Inline definitions for NiD3DShaderProgram: Nivid3D shader program
// wrappers over D3D9 GPU programs. A program object owns the compiled
// code block and the creator/device handles that produced it; the
// accessors below read out the stored descriptors.
//
// Standalone build: base chain sizes taken from the MSVC 2008 layout
// evidence - NiGPUProgram is 12 bytes and NiD3DShaderProgram is 44
// bytes, with m_uiProgramCodeSize at offset 20.
//
typedef unsigned int NiUInt32;
class NiMemObject
{
};
class NiRefObject : public NiMemObject
{
  public:
    NiRefObject() : m_uiRefCount(0)
    {}

    virtual ~NiRefObject()
    {}

    virtual void DeleteThis()
    {
        delete this;
    }

  protected:
    NiUInt32 m_uiRefCount;
};
class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType
    {
        PROGRAMTYPE_INVALID,
        PROGRAMTYPE_VERTEX,
        PROGRAMTYPE_PIXEL
    };

    ProgramType GetProgramType()
    {
        return m_iProgramType;
    }

  protected:
    ProgramType m_iProgramType;
};
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class NiD3DRenderer;
class NiD3DRenderState;
class NiD3DShaderProgram : public NiGPUProgram
{
  public:
    NiUInt32 GetCodeSize() const;

  protected:
    char* m_pcProgramName;
    char* m_pcProfile;
    NiUInt32 m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    NiD3DRenderer* m_pShaderObject;
    NiD3DRenderState* m_pRenderState;
};
struct P03MM
{
    void* Allocate(unsigned int);
};
typedef P03MM MemoryManager;
extern MemoryManager g_memoryManager;
struct S
{
    S* FUN_00e9ee60(void*);
};
S* __fastcall FUN_00e9efb0(void* self);
// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;
int FUN_00e9ecc0();

class A64330Obj
{
  public:
    int unk00;
    int** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, int* const& value);

    unsigned int FUN_00a64330(int* const& value);
};

// @fnv 0x00a64330
unsigned int A64330Obj::FUN_00a64330(int* const& value)
{
    int* element = value;

    if (element == 0)
        return 0xffffffffu;

    unsigned short i;
    for (i = 0; i < m_usSize; ++i)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = element;
            ++m_usESize;
            return i;
        }
    }

    unsigned int uiSize = m_usSize;
    if (uiSize >= m_usMaxSize)
        SetSize(uiSize + m_usGrowBy);

    SetAt(uiSize, value);
    return uiSize;
}

struct ShaderObj
{
    virtual void SetSomething(unsigned int a1);
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    ShaderObj() throw();
    void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};

// @fnv 0x00e9efe0
ShaderObj* __cdecl FUN_00e9efe0(unsigned int a1)
{
    ShaderObj* p = new ShaderObj;
    p->SetSomething(a1);
    return p;
}

struct Items
{
    void FUN_00a64330(unsigned int*);
};
typedef unsigned int(__cdecl* ReadFn)(void*, unsigned int*, unsigned int, unsigned int*, unsigned int);
struct Stream
{
    unsigned int unused;
    unsigned int nread;
    ReadFn read;
};
struct Obj
{
    unsigned int unused;
    Items items;
    unsigned int* ptrs;
    unsigned short cap, n;
    void FUN_00a89af0(void*);
    void FUN_00e9f020(char* stream);
};
unsigned int FUN_00e9cab0(void*);
// @fnv 0x00e9f020
void Obj::FUN_00e9f020(char* stream)
{
    unsigned int num;
    FUN_00a89af0(stream);
    Stream* in = *(Stream**)(stream + 0x24c);
    {
        unsigned int sz = 4;
        in->nread += in->read(in, &num, 4, &sz, 1);
    }
    for (unsigned int i = 0; i < num; ++i)
    {
        unsigned int item = FUN_00e9cab0(stream);
        if (item)
        {
            unsigned int max = n;
            for (unsigned int j = 0; j < max; ++j)
            {
                if (item == ptrs[j])
                    goto found;
            }
            items.FUN_00a64330(&item);
        found:;
        }
    }
}

struct E9E8C0Item
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual bool IsDifferent(E9E8C0Item* pkOther);
};

struct E9E8C0ItemList
{
    E9E8C0Item** m_ppkBase;
    unsigned short m_usUnk04;
    unsigned short m_usSize;

    E9E8C0Item*& GetAt(unsigned int ui)
    {
        return m_ppkBase[ui];
    }
    unsigned short GetSize() const
    {
        return m_usSize;
    }
};

class E9E8C0Array
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int GetType();

    bool FUN_00e9e8c0(E9E8C0Array* pkOther);

  protected:
    int m_unk04;
    E9E8C0ItemList m_kUnsortedGeometryList;
};

// @fnv 0x00e9e8c0
bool E9E8C0Array::FUN_00e9e8c0(E9E8C0Array* pkOther)
{
    if (pkOther->GetType() != 4)
        return false;
    if (m_kUnsortedGeometryList.GetSize() != pkOther->m_kUnsortedGeometryList.GetSize())
        return false;
    for (unsigned int ui = 0; ui < m_kUnsortedGeometryList.GetSize(); ui++)
    {
        if (m_kUnsortedGeometryList.GetAt(ui)->IsDifferent(pkOther->m_kUnsortedGeometryList.GetAt(ui)))
            return false;
    }
    return true;
}

struct S_00e9e930_X
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* a, void* b);
};
struct S_00e9e930_A
{
    int unk00;
    int unk04;
    void** m08;
};
struct S_00e9e930
{
    int unk00;
    int unk04;
    S_00e9e930_X** m08;
    unsigned short unk0C;
    unsigned short m0E;
    void FUN_00e9e930(S_00e9e930_A* a1, void* a2);
};
// @fnv 0x00e9e930
void S_00e9e930::FUN_00e9e930(S_00e9e930_A* a1, void* a2)
{
    for (unsigned int i = 0; i < m0E; i++)
    {
        S_00e9e930_X* obj = m08[i];
        void* arg = a1->m08[i];
        obj->v5(arg, a2);
    }
}

class NiBinaryStream
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NIBINARYSTREAM_WRITEFN m_pfnWrite;
};

class NiStream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
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
    int unk24c;
    NiBinaryStream* m_pBackingStream;
};

template <class T> __forceinline void SerializeValue(NiBinaryStream& kStream, const T& tValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&tValue, sizeof(T), &uiSize, 1);
}

class NiSavable
{
  public:
    virtual void v0();
    virtual void SaveBinary(NiStream& kStream);
};

class FUN_00e9ed50_cls
{
  public:
    void* m_pvVtbl;
    int unk04;
    NiSavable** m_ppSavableObjects;
    unsigned short unk0c;
    unsigned short m_usElementCount;

    void SaveValueToStream(NiStream& kStream);
    void FUN_00e9ed50(NiStream& kStream);
};

// @fnv 0x00e9ed50
void FUN_00e9ed50_cls::FUN_00e9ed50(NiStream& kStream)
{
    SaveValueToStream(kStream);

    unsigned int ItemUpdateArray = m_usElementCount;
    SerializeValue(*kStream.m_pBackingStream, ItemUpdateArray);

    for (unsigned int i = 0; i < m_usElementCount; i++)
    {
        NiSavable* pkObj = m_ppSavableObjects[i];
        if (pkObj)
            pkObj->SaveBinary(kStream);
    }
}

typedef unsigned int u32;
typedef unsigned short u16;

extern "C" unsigned int __cdecl strlen(const char* s);
void* __cdecl FUN_00aa1070(unsigned int size);
int __cdecl FUN_00a305b0(char* buf, unsigned int count, const char* fmt, ...);

template <class T> class NiTPrimitiveArray
{
  public:
    virtual ~NiTPrimitiveArray();

    u32 GetSize() const
    {
        return m_usSize;
    }
    T GetAt(u32 uiIndex) const
    {
        return (uiIndex < m_usSize) ? m_pBase[uiIndex] : 0;
    }
    void SetSize(u32 uiMaxSize);
    void SetAt(u32 uiIndex, T& element);

    u32 Add(T& element)
    {
        u32 uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
        {
            SetSize(uiIndex + m_usGrowBy);
        }
        SetAt(uiIndex, element);
        return uiIndex;
    }

    T* m_pBase;
    u16 m_usMaxSize;
    u16 m_usSize;
    u16 m_usESize;
    u16 m_usGrowBy;
};

class NiBoundingVolume
{
  public:
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
    virtual void AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);
};

class NiUnionBV
{
  public:
    void FUN_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);

    u32 unk00;
    NiTPrimitiveArray<NiBoundingVolume*> m_kBoundingVolumes;
};

// @fnv 0x00e9f0b0
void NiUnionBV::FUN_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings)
{
    u32 uiLen = strlen(pcPrefix) + 12;
    char* pcString = (char*)FUN_00aa1070(uiLen);
    FUN_00a305b0(pcString, uiLen, "%s = UNION_BV", pcPrefix);
    pkStrings->Add(pcString);

    for (u32 i = 0; i < m_kBoundingVolumes.GetSize(); i++)
    {
        char* pcChild = (char*)FUN_00aa1070(13);
        FUN_00a305b0(pcChild, 13, "   child %i", i);
        m_kBoundingVolumes.GetAt(i)->AddViewerStrings(pcChild, pkStrings);
    }
}

namespace fnv_00e9edd0 {
void* NiMalloc(unsigned int stSizeInBytes);

template <class T_Data> class NiTMallocInterface
{
  public:
    static T_Data* Allocate(unsigned int auiCount)
    {
        return (T_Data*)NiMalloc(sizeof(T_Data) * auiCount);
    }
};

template <class T_Data, class TAlloc> class NiTArray
{
  public:
    NiTArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;

        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~NiTArray();

  protected:
    T_Data* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    NiTPrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
    {}
    virtual ~NiTPrimitiveArray();
};

class NiShaderArrayOwner
{
  public:
    NiShaderArrayOwner();
    virtual ~NiShaderArrayOwner();

  protected:
    NiTPrimitiveArray<void*> m_kArray;
    void* m_pkEntry;
};

// @fnv 0x00e9edd0
NiShaderArrayOwner::NiShaderArrayOwner() : m_kArray(2, 1), m_pkEntry(0)
{}
}  // namespace fnv_00e9edd0
