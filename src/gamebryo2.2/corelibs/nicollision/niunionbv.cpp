
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

// @fnv 0x0DBBC10
NiUInt32 NiD3DShaderProgram::GetCodeSize() const
{
    return m_uiProgramCodeSize;
}

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
// @fnv 0x00e9efb0
S* __fastcall FUN_00e9efb0(void* self)
{
    S* p = (S*)g_memoryManager.Allocate(0x18);
    if (p)
        return p->FUN_00e9ee60(self);
    return 0;
}

// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;

// @fnv 0x00e9ecc0
int FUN_00e9ecc0()
{
    return (int)(&g_fnv_00e9ecc0_value_anchor) + 4;
}

#pragma optimize("gty", on)
class S00e9e860_Item
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void Delete(unsigned char acFlags);
};

class S00e9e860_Obj
{
  public:
    int unk00;
    int unk04;
    S00e9e860_Item** m_ppItems;
    unsigned short unk0c;
    unsigned short m_uCount;
    unsigned short m_u10;
    void FUN_00e9e860();
};

// Deletes each item in m_ppItems, nulls the pointers, and resets m_uCount and m_u10 to zero.
// @fnv 0x00e9e860
void S00e9e860_Obj::FUN_00e9e860()
{
    {
        unsigned int iIndex = 0;
        if (iIndex < m_uCount)
        {
            do
            {
                S00e9e860_Item* p = m_ppItems[iIndex];
                if (p != 0)
                {
                    p->Delete(1);
                }
            } while (++iIndex < m_uCount);
        }
    }
    {
        unsigned short n = 0;
        if (n < m_uCount)
        {
            do
            {
                *(volatile unsigned int*)&m_ppItems[n++] = 0;
            } while (n < m_uCount);
        }
    }
    m_uCount = 0;
    m_u10 = 0;
}
