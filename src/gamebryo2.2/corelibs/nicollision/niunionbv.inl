
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
    {
    }

    virtual ~NiRefObject()
    {
    }

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
