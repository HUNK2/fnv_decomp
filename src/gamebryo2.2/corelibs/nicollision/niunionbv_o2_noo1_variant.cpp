
// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_noo1_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /Oy /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
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

extern void* DAT_010f1778[];
extern void* DAT_010f17ac[];

struct NiCloneableQ
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual NiCloneableQ* Clone();
};

struct CloneArrayQ
{
    void** vtbl;
    NiCloneableQ** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00a90180(unsigned int);
    void FUN_00ba3aa0(unsigned int, NiCloneableQ* const&);
};

struct SViewQ
{
    void** vtbl;
    CloneArrayQ m_kArray;
};

// @fnv 0x00e9ee60
S* S::FUN_00e9ee60(void* pkOtherRaw)
{
    SViewQ* pkOther = (SViewQ*)pkOtherRaw;
    SViewQ* pkSelf = (SViewQ*)this;
    pkSelf->vtbl = DAT_010f1778;
    CloneArrayQ* pkArray = &pkSelf->m_kArray;
    pkArray->m_usMaxSize = 0;
    pkArray->m_usGrowBy = 1;
    pkArray->m_usSize = 0;
    pkArray->m_usESize = 0;
    pkArray->m_pBase = 0;
    pkArray->vtbl = DAT_010f17ac;
    pkArray->FUN_00a90180(pkOther->m_kArray.m_usSize);
    for (unsigned int i = 0; i < pkOther->m_kArray.m_usSize; i++)
    {
        NiCloneableQ* p = pkOther->m_kArray.m_pBase[i];
        if (p)
        {
            NiCloneableQ* q = p->Clone();
            pkArray->FUN_00ba3aa0(i, q);
        }
    }
    return this;
}
