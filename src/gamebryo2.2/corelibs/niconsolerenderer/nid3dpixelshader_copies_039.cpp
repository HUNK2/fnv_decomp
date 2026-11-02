
// Provisional build file (plan B2): exact copies of the nid3dpixelshader recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
//
// Compile form of nid3dpixelshader.inl: MSVC 2008 cl does not accept the
// .inl extension as a source file, so this identical unit is compiled as .cpp
// by the matcher. Content is the authored body of the .inl source of record.

// The standalone build carries the shader base chain with the real member
// names and offsets of the MSVC 2008 build: NiD3DPixelShader is 48 bytes
// and its D3D pixel shader handle lives at offset 44.

// Direct3D9 pixel shader object; referenced by pointer only.
class GeometryRelatedType;

// Forward declarations of the renderer types named by the base chain.
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;

typedef unsigned int NiUInt32;

// Base of the engine allocation tracking; empty in this build.
class NiMemObject
{
};

// Reference counted engine object.
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

// Nivid3D pixel shader program.
class NiD3DPixelShader : public NiD3DShaderProgram
{
  public:
    void SetD3DPixelShader(GeometryRelatedType* pixelShader);

  protected:
    GeometryRelatedType* m_pD3DPixelShader;
};

struct Twin_0086cf00 : public NiD3DPixelShader
{
    void SetD3DPixelShader(GeometryRelatedType* const pixelShader);
};
// @fnv 0x0086cf00
void Twin_0086cf00::SetD3DPixelShader(GeometryRelatedType* const pixelShader)
{
    m_pD3DPixelShader = pixelShader;
}

struct Twin_00c3cf40 : public NiD3DPixelShader
{
    void SetD3DPixelShader(GeometryRelatedType* const pixelShader);
};
// @fnv 0x00c3cf40
void Twin_00c3cf40::SetD3DPixelShader(GeometryRelatedType* const pixelShader)
{
    m_pD3DPixelShader = pixelShader;
}
