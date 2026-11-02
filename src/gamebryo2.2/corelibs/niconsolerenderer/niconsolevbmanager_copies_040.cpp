
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
//
// Compile form of the FNV 2.2 vertex-buffer-manager translation unit for the
// MSVC 2008 (Windows, x86) matcher. This unit defines
// NiD3DHLSLVertexShader::GetEntryPoint (0x00E8BF90, 4 bytes:
// "mov eax,[ecx+0x3c]; ret"). The getter returns the HLSL entry-point string
// held in m_pcShaderEntryPoint, which sits at offset 0x3C (60) inside
// NiD3DHLSLVertexShader, i.e. immediately after the 60-byte NiD3DVertexShader
// base object.

typedef unsigned int NiUInt32;

// A D3DX constant table is referenced by pointer only in this build.
class ID3DXConstantTable;

// Nivid3D vertex shader base. Reconstructed to exactly 60 bytes: a 4-byte
// vtable pointer (the class owns a 41-slot vtable) plus 56 bytes of data.
// and GetSoftwareVertexProcessing/SetSoftwareVertexProcessing; the matching
// data members are named after them. The remaining data is unattested, so it
// is carried as a clearly marked 10-pointer reconstruction block whose only
// job is to bring the base object to exactly 60 bytes. Only the base total
// size (60) and the derived-class offsets matter for the matched span.
class NiD3DVertexShader
{
  public:
    virtual ~NiD3DVertexShader()
    {}

    virtual void UnloadShader()
    {}

    virtual void BuildVertexShader()
    {}

  protected:
    NiUInt32 m_uiShaderUsage;
    void* m_pShaderHandle;
    void* m_pkVertexDeclaration;            // GetVertexDeclaration / SetVertexDeclaration
    NiUInt32 m_uiSoftwareVertexProcessing;  // GetSoftwareVertexProcessing / SetSoftwareVertexProcessing
    // Unattested base data members (reconstruction): ten pointer slots that
    // bring the base object to exactly 60 bytes. Their real names are unknown.
    void* m_unattested[10];
};

// Nivid3D HLSL vertex shader program.
class NiD3DHLSLVertexShader : public NiD3DVertexShader
{
  public:
    const char* GetEntryPoint();

  protected:
    char* m_pcShaderEntryPoint;
    char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

struct Twin_00639b40 : public NiD3DHLSLVertexShader
{
    const char* GetEntryPoint();
};
// @fnv 0x00639b40
const char* Twin_00639b40::GetEntryPoint()
{
    return m_pcShaderEntryPoint;
}
