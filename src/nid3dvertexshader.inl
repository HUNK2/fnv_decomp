
//
// Definitions for NiD3DVertexShader, the Nivid3D vertex shader program.
//
// The standalone build carries the shader base chain with the real member
// names and offsets of the MSVC 2008 build: NiD3DVertexShader is 60 bytes and
// its D3D handles live at offset 52 (shader) and 56 (declaration).

// Direct3D9 vertex shader object; referenced by pointer only.
class RenderableGeometry;

// Direct3D9 vertex declaration object; referenced by pointer only.
class COMUnknownInterface;

// Forward declarations of the renderer types named by the base chain.
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;

typedef unsigned int NiUInt32;

// Run time type descriptor handed out by GetRTTI.
class NiRTTI
{
public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

// Base of the engine allocation tracking; empty in this build.
class NiMemObject
{
};

// Reference counted engine object.
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

// GPU program base of the Nivid3D shader programs.
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

// Nivid3D shader program with its compiled D3D program state.
class NiD3DShaderProgram : public NiGPUProgram
{
public:
    NiD3DShaderProgram(GraphicsRenderer* pkRenderer, bool bIsVertexShader);

protected:
    char* m_pcProgramName;
    char* m_pcProfile;
    NiUInt32 m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};

// Nivid3D vertex shader program.
class NiD3DVertexShader : public NiD3DShaderProgram
{
public:
    NiD3DVertexShader(GraphicsRenderer* pkRenderer);

    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;

    void SetD3DPixelShader(RenderableGeometry* hShader);
    COMUnknownInterface* GetShaderDeclaration() const;

protected:
    bool m_bIsInitialized;
    NiUInt32 m_uiShaderUsage;
    RenderableGeometry* m_pD3DPixelShader;
    COMUnknownInterface* m_pD3DVertexShader;
};

// @fnv 0x00be0b30
NiD3DVertexShader::NiD3DVertexShader(GraphicsRenderer *const pkRenderer) :
    NiD3DShaderProgram(pkRenderer, false)
{
    m_bIsInitialized = false;
    m_uiShaderUsage = 0;
    m_pD3DPixelShader = 0;
    m_pD3DVertexShader = 0;
}

// @fnv 0x00be0b60
const NiRTTI* NiD3DVertexShader::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x00be0bb0
void NiD3DVertexShader::SetD3DPixelShader(RenderableGeometry *const hShader)
{
    m_pD3DPixelShader = hShader;
}

// @fnv 0x00be0bc0
COMUnknownInterface* NiD3DVertexShader::GetShaderDeclaration() const
{
    return m_pD3DVertexShader;
}