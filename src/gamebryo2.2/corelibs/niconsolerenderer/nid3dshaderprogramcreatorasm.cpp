
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GeometryRelatedType;
struct NiD3DPixelShader
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual GeometryRelatedType* f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32(void*);
};
struct NiD3DShaderProgramCreatorAsm
{
    void* FUN_00e988d0(GeometryRelatedType*);
    bool FUN_00e97940(NiD3DPixelShader* pkPixelShader);
};
// Gets the shader handle from pkPixelShader, retrieves its code, and if both exist passes the code to pkPixelShader->f32 and returns true.
// @fnv 0x00e97940
bool NiD3DShaderProgramCreatorAsm::FUN_00e97940(NiD3DPixelShader* pkPixelShader)
{
    GeometryRelatedType* hShader;
    void* pvCode;
    hShader = pkPixelShader->f25();
    if (!hShader)
        return false;
    pvCode = FUN_00e988d0(hShader);
    if (!pvCode)
        return false;
    pkPixelShader->f32(pvCode);
    return true;
}

struct GeometryRelatedType;
struct PixelShaderInterface
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual GeometryRelatedType* GetPixelShader();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void* GetShaderData();
    virtual void Slot32();
    virtual void Slot33();
    virtual void SetShaderProgram(void*);
    virtual void* GetShaderProgram();
};
struct PixelShaderCreator
{
    void* CreateVertexShaderChecked(GeometryRelatedType*, void**, void*, int, int, int);
    bool CreateShaderProgram(PixelShaderInterface*);
};
// Gets the pixel shader, creates a program from its data, stores it on the interface and returns whether creation succeeded.
// @fnv 0x00e978d0
bool PixelShaderCreator::CreateShaderProgram(PixelShaderInterface* shader)
{
    GeometryRelatedType* pixel = shader->GetPixelShader();
    if (!pixel)
        return false;
    void* program = shader->GetShaderProgram();
    void* created = CreateVertexShaderChecked(pixel, &program, shader->GetShaderData(), 0, 0, 0);
    if (!created)
        return false;
    shader->SetShaderProgram(created);
    return true;
}

extern void* DAT_0126fa2c;

int FUN_00aa0020(int, int, const char*, long);

struct NiD3DShaderProgramStub
{
    NiD3DShaderProgramStub(void* pkRenderer, int eType) throw();
    virtual ~NiD3DShaderProgramStub();
    static void* operator new(unsigned int uiSize);
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
};

struct NiD3DVertexShader : NiD3DShaderProgramStub
{
    NiD3DVertexShader(void* pkRenderer) : NiD3DShaderProgramStub(pkRenderer, 0)
    {
        m_bIsInitialized = false;
        m_uiShaderUsage = 0;
        m_pD3DPixelShader = 0;
        m_pD3DVertexShader = 0;
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetFileName(const char* pcFileName);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShaderUsage(unsigned int uiUsage);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void SetVertexDeclaration(void* hDecl);
    virtual void v37();
    virtual void SetSoftwareVertexProcessing(bool bSoftwareVP);

    bool m_bIsInitialized;
    unsigned int m_uiShaderUsage;
    void* m_pD3DPixelShader;
    void* m_pD3DVertexShader;
};

struct VertexShaderCreatorAsm
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual bool LoadShaderCode(const char* pcFileName, void*& pvCode, unsigned int& uiCodeSize, void*& pvConstants,
                                void*& pvConstantsExtra, int bRecoverable);

    void* CreateVertexShaderChecked(void* pvCode, void** phDecl, unsigned int uiUsage, void* pvConstants,
                                    void* pvConstantsExtra, bool bSoftwareVP);
    NiD3DVertexShader* FUN_00e97980(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                                    int iArg, void* hDecl, unsigned int uiUsage, bool bSoftwareVP, int bRecoverable);
};

// @fnv 0x00e97980
NiD3DVertexShader* VertexShaderCreatorAsm::FUN_00e97980(const char* pcFileName, const char* pcShaderName,
                                                        const char* pcEntryPoint, int iArg, void* hDecl,
                                                        unsigned int uiUsage, bool bSoftwareVP, int bRecoverable)
{
    NiD3DVertexShader* pkVertexShader = new NiD3DVertexShader(DAT_0126fa2c);
    if (!pkVertexShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    void* pvConstantsExtra = 0;
    void* pvConstants = 0;
    if (!LoadShaderCode(pcFileName, pvCode, uiCodeSize, pvConstants, pvConstantsExtra, bRecoverable))
    {
        delete pkVertexShader;
        return 0;
    }

    void* hShader = CreateVertexShaderChecked(pvCode, &hDecl, uiUsage, pvConstants, pvConstantsExtra, bSoftwareVP);
    if (!hShader)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", (long)pcShaderName);
        delete pkVertexShader;
        return 0;
    }

    pkVertexShader->SetName(pcShaderName);
    pkVertexShader->SetFileName(pcFileName);
    pkVertexShader->SetProgramCode(uiCodeSize, pvCode);
    pkVertexShader->SetCreator(this);
    pkVertexShader->SetD3DPixelShader(hShader);
    pkVertexShader->SetShaderUsage(uiUsage);
    pkVertexShader->SetVertexDeclaration(hDecl);
    pkVertexShader->SetSoftwareVertexProcessing(bSoftwareVP);
    return pkVertexShader;
}

namespace fnv_00e97c60 {
struct GeometryRelatedType;
struct ShaderCreatorAsmStub;

extern void* DAT_0126fa2c;
int FUN_00aa0020(int, int, const char*, long);

struct NiMemObjectStub
{
    static void* operator new(unsigned int uiSize);
};

struct NiD3DShaderProgramStub : NiMemObjectStub
{
    NiD3DShaderProgramStub(void* pkRenderer, int eType) throw();
    virtual ~NiD3DShaderProgramStub();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void SetName(const char* pcName);
    virtual void f22();
    virtual void SetFileName(const char* pcFileName);
    virtual void f24();
    virtual void f25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void f27();
    virtual void SetCreator(ShaderCreatorAsmStub* pkCreator);
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void SetD3DPixelShader(GeometryRelatedType* hShader);

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
};

struct NiD3DPixelShaderStub : NiD3DShaderProgramStub
{
    NiD3DPixelShaderStub(void* pkRenderer) throw() : NiD3DShaderProgramStub(pkRenderer, 2), m_pD3DPixelShader(0)
    {}
    virtual ~NiD3DPixelShaderStub();
    GeometryRelatedType* m_pD3DPixelShader;
};

struct ShaderCreatorAsmStub
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual bool LoadShaderCode(const char* pcFileName, void*& pvCode, unsigned int& uiCodeSize, void*& pvA, void*& pvB,
                                int iFlags);

    GeometryRelatedType* CreateHandle(void* pvCode);
    NiD3DPixelShaderStub* FUN_00e97c60(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                                       const char* pcShaderTarget, int iFlags);
};

// Creates a NiD3DPixelShaderStub, loads its shader code, creates the handle, sets name/file/code/creator/handle, and returns it or 0 on failure.
// @fnv 0x00e97c60
NiD3DPixelShaderStub* ShaderCreatorAsmStub::FUN_00e97c60(const char* pcFileName, const char* pcShaderName,
                                                         const char* pcEntryPoint, const char* pcShaderTarget,
                                                         int iFlags)
{
    NiD3DPixelShaderStub* pkShader = new NiD3DPixelShaderStub(DAT_0126fa2c);
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    void* pvB = 0;
    void* pvA = 0;
    if (!LoadShaderCode(pcFileName, pvCode, uiCodeSize, pvA, pvB, iFlags))
    {
        delete pkShader;
        return 0;
    }

    GeometryRelatedType* hShader = CreateHandle(pvCode);
    if (!hShader)
    {
        FUN_00aa0020(1, iFlags, "Failed CreatePixelShader call on %s\n", (long)pcShaderName);
        delete pkShader;
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->SetFileName(pcFileName);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    return pkShader;
}
}  // namespace fnv_00e97c60

extern void* DAT_0126fa2c;
int FUN_00aa0020(int, int, const char*, long);
struct NiMemObject
{
    static void* operator new(unsigned int) throw();
};
struct PixelBase : NiMemObject
{
    PixelBase(void*, int) throw();
    virtual void destroy(int);
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21(void*);
    virtual void f22();
    virtual void f23(int);
    virtual void f24();
    virtual void f25();
    virtual void f26(void*, void*);
    virtual void f27();
    virtual void f28(void*);
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32(void*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
};
struct Pixel : PixelBase
{
    int unk2c;
    Pixel() throw() : PixelBase(DAT_0126fa2c, 2), unk2c(0)
    {}
    virtual void destroy(int);
};
struct Creator
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual bool compile(void*, void*, GeometryRelatedType**, void**, void**, void**, int);
    Pixel* FUN_00e97d80(void*, void*, void*, int, int, int);
};
// @fnv 0x00e97d80
Pixel* Creator::FUN_00e97d80(void* a, void* b, void* apShaderName, int d, int e, int f)
{
    Pixel* shader = new Pixel;
    if (!shader)
        return 0;
    GeometryRelatedType* first;
    void* second = 0;
    first = 0;
    void* third = 0;
    void* fourth = 0;
    if (!compile(a, b, &first, &second, &fourth, &third, f))
    {
        shader->destroy(1);
        return 0;
    }
    void* pShaderHandle = reinterpret_cast<NiD3DShaderProgramCreatorAsm*>(this)->FUN_00e988d0(first);
    if (!pShaderHandle)
    {
        FUN_00aa0020(1, f, "Failed CreatePixelShader call on %s\n", (long)apShaderName);
        shader->destroy(1);
        return 0;
    }
    shader->f21(apShaderName);
    shader->f23(0);
    shader->f26(second, first);
    shader->f28(this);
    shader->f32(pShaderHandle);
    return shader;
}

int __cdecl FUN_00aa0020(int eError, int bRecoverable, const char* pcFormat, ...);

struct VertexShaderCreatorHLSL
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual bool LoadShaderCode(const char* pcFileName, const char* pcEntryPoint, void*& pvCode,
                                unsigned int& uiCodeSize, void*& pvConstants, void*& pvConstantsExtra,
                                int bRecoverable);

    void* CreateVertexShaderChecked(void* pvCode, void** phDecl, unsigned int uiUsage, void* pvConstants,
                                    void* pvConstantsExtra, bool bSoftwareVP);
    NiD3DVertexShader* FUN_00e97af0(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderName,
                                    const char* pcShaderTarget, const char* pcDefines, void* hDecl,
                                    unsigned int uiUsage, bool bSoftwareVP, int bRecoverable);
};

// Creates a NiD3DVertexShader, loads its shader code, builds the shader handle, and sets its name, code, creator, usage and declaration.
// @fnv 0x00e97af0
NiD3DVertexShader* VertexShaderCreatorHLSL::FUN_00e97af0(const char* pcFileName, const char* pcEntryPoint,
                                                         const char* pcShaderName, const char* pcShaderTarget,
                                                         const char* pcDefines, void* hDecl, unsigned int uiUsage,
                                                         bool bSoftwareVP, int bRecoverable)
{
    NiD3DVertexShader* pkVertexShader = new NiD3DVertexShader(DAT_0126fa2c);
    if (!pkVertexShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    void* pvConstantsExtra = 0;
    void* pvConstants = 0;
    if (!LoadShaderCode(pcFileName, pcEntryPoint, pvCode, uiCodeSize, pvConstants, pvConstantsExtra, bRecoverable))
    {
        delete pkVertexShader;
        return 0;
    }

    void* hShader = CreateVertexShaderChecked(pvCode, &hDecl, uiUsage, pvConstants, pvConstantsExtra, bSoftwareVP);
    if (!hShader)
    {
        FUN_00aa0020(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        delete pkVertexShader;
        return 0;
    }

    pkVertexShader->SetName(pcShaderName);
    pkVertexShader->SetFileName(0);
    pkVertexShader->SetProgramCode(uiCodeSize, pvCode);
    pkVertexShader->SetCreator(this);
    pkVertexShader->SetD3DPixelShader(hShader);
    pkVertexShader->SetShaderUsage(uiUsage);
    pkVertexShader->SetVertexDeclaration(hDecl);
    pkVertexShader->SetSoftwareVertexProcessing(bSoftwareVP);
    return pkVertexShader;
}
