// bsshader/bsshaderbloodsplatter.cpp: BSShaderBloodSplatter, BloodShader (17 functions)

#include "bsshaderbloodsplatter_types_BSShaderBloodSplatter.h"
#include "bsshaderbloodsplatter_types_BSShaderManager.h"
#include "bsshaderbloodsplatter_types_NiConsoleShaderDeclaration.h"

extern GraphicsRenderer* g_pkRenderer;
extern float g_splatterDefaultFirst;
extern float g_splatterDefaultSecond;
extern float g_splatterValueA;
extern char g_splatterWhiteFlashPath[];
extern char g_splatterWhiteFlashTexture;

struct SplatterFloat4
{
    float x;
    float y;
    float z;
    float w;
};

// @fnv 0x00b80e70
BSShader* BSShaderBloodSplatter::CreateShader()
{
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create(g_pkRenderer, 2, 1);
    typedef void(__thiscall * Method5)(void*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    typedef void(__thiscall * Method0)(void*);
    reinterpret_cast<Method5>((*reinterpret_cast<void***>(declaration))[35])(declaration, 0, 0, 0, 2, 0);
    reinterpret_cast<Method5>((*reinterpret_cast<void***>(declaration))[35])(declaration, 1, 7, 5, 1, 0);
    reinterpret_cast<Method0>((*reinterpret_cast<void***>(declaration))[45])(declaration);

    BSShaderBloodSplatter* shader = new BSShaderBloodSplatter;
    reinterpret_cast<Method0>((*reinterpret_cast<void***>(shader))[19])(shader);
    shader->InitializeShaderData();
    shader->ConfigureShaderPass();
    typedef void(__thiscall * Method1)(void*, void*);
    reinterpret_cast<Method0>((*reinterpret_cast<void***>(shader))[71])(shader);
    reinterpret_cast<Method1>((*reinterpret_cast<void***>(shader))[48])(shader, declaration);
    return shader;
}

// @fnv 0x00b80d30
BSShaderBloodSplatter::BSShaderBloodSplatter() : BSShader()
{
    SplatterFloat4 values = {g_splatterDefaultFirst, g_splatterDefaultFirst, 0.0f, g_splatterDefaultSecond};
    m_iPassId = 0x17;
    *reinterpret_cast<SplatterFloat4*>(&g_splatterValueA) = values;
    BSShaderManager::GetTexture(g_splatterWhiteFlashPath, true,
                                *reinterpret_cast<NiPointer<NiTexture>*>(&g_splatterWhiteFlashTexture), true, false);
}

#include "bsshaderbloodsplatter_decls.h"

// Configures two NiD3DPass objects with two texture stages each, render states, vertex and pixel shaders, and returns true.
// @fnv 0x00b807d0
bool BSShaderBloodSplatter::ConfigureShaderPass()
{
    NiD3DPass::CreateD3DPass(spRenderPass[0]);
    for (unsigned int i = 0; i < 2; ++i)
    {
        NiPointer<BeamStage> stage;
        BeamStage::CreateNewStage(stage);
        ConfigureBeamStage(stage, i, 3, 2, true);
        stage->FUN_00e7def0(1);
        spRenderPass[0].m_pObject->FUN_00e802b0(spRenderPass[0].m_pObject->m_uiStageMask, stage);
    }
    spRenderPass[0].m_pObject->SetRenderState(27, 1, true);
    spRenderPass[0].m_pObject->SetRenderState(7, 0, true);
    spRenderPass[0].m_pObject->SetRenderState(14, 0, true);
    {
        NiD3DPass* pass = spRenderPass[0].m_pObject;
        pass->SetRenderState(19, 1, true);
        pass->SetRenderState(20, 3, true);
    }
    spRenderPass[0].m_pObject->SetVertexShader(m_spTreeVertexShader[0].m_pObject);
    spRenderPass[0].m_pObject->SetPixelShader(m_spPixelShaderVariants[0].m_pObject);
    NiD3DPass::CreateD3DPass(spRenderPass[1]);
    for (unsigned int i = 0; i < 2; ++i)
    {
        NiPointer<BeamStage> stage;
        BeamStage::CreateNewStage(stage);
        ConfigureBeamStage(stage, i, 3, 2, true);
        stage->FUN_00e7def0(1);
        spRenderPass[1].m_pObject->FUN_00e802b0(spRenderPass[1].m_pObject->m_uiStageMask, stage);
    }
    spRenderPass[1].m_pObject->SetRenderState(27, 1, true);
    spRenderPass[1].m_pObject->SetRenderState(7, 0, true);
    spRenderPass[1].m_pObject->SetRenderState(14, 0, true);
    {
        NiD3DPass* pass = spRenderPass[1].m_pObject;
        pass->SetRenderState(19, 2, true);
        pass->SetRenderState(20, 2, true);
    }
    spRenderPass[1].m_pObject->SetVertexShader(m_spTreeVertexShader[1].m_pObject);
    spRenderPass[1].m_pObject->SetPixelShader(m_spPixelShaderVariants[1].m_pObject);
    return true;
}

struct SplatterShaderInfo
{
    const char* file;
    _D3DXMACRO macros[9];
};
// @fnv 0x00b80090
void BSShaderBloodSplatter::InitializeShaderData()
{
    SplatterShaderInfo vertex;
    vertex.file = "BloodSplatter\\BloodSplatter.v.hlsl";
    vertex.macros[0].Name = 0;
    fnv_zlib_memset(&vertex.macros[0].Definition, 0, 68);
    SplatterShaderInfo pixel;
    pixel.file = "BloodSplatter\\BloodSplatter.p.hlsl";
    pixel.macros[0].Name = 0;
    fnv_zlib_memset(&pixel.macros[0].Definition, 0, 68);
    SplatterShaderInfo flareVertexShader;
    flareVertexShader.file = "BloodSplatter\\BloodSplatter.v.hlsl";
    flareVertexShader.macros[0].Name = "FLARE";
    flareVertexShader.macros[0].Definition = "";
    flareVertexShader.macros[1].Name = 0;
    fnv_zlib_memset(&flareVertexShader.macros[1].Definition, 0, 60);
    SplatterShaderInfo flarePixelShader;
    flarePixelShader.file = "BloodSplatter\\BloodSplatter.p.hlsl";
    flarePixelShader.macros[0].Name = "FLARE";
    flarePixelShader.macros[0].Definition = "";
    flarePixelShader.macros[1].Name = 0;
    fnv_zlib_memset(&flarePixelShader.macros[1].Definition, 0, 60);
    char shaderPath[260];
    char outputFile[260];
    GetShaderPath(vertex.file, shaderPath);
    sprintf_s(outputFile, 260, "BS.vso");
    m_spTreeVertexShader[0] = CompileVertexShader(shaderPath, vertex.macros, "vs_1_1", outputFile);
    GetShaderPath(flareVertexShader.file, shaderPath);
    sprintf_s(outputFile, 260, "BSF.vso");
    m_spTreeVertexShader[1] = CompileVertexShader(shaderPath, flareVertexShader.macros, "vs_1_1", outputFile);
    GetShaderPath(pixel.file, shaderPath);
    sprintf_s(outputFile, 260, "BS.pso");
    m_spPixelShaderVariants[0] = CompilePixelShader(shaderPath, pixel.macros, "ps_2_a", outputFile);
    GetShaderPath(flarePixelShader.file, shaderPath);
    sprintf_s(outputFile, 260, "BSF.pso");
    m_spPixelShaderVariants[1] = CompilePixelShader(shaderPath, flarePixelShader.macros, "ps_2_a", outputFile);
}

// @fnv 0x00b81110
void BSShaderBloodSplatter::FUN_00b81110(unsigned int value)
{
    m_iPassId = (value != 3) ? 3 : 0;
}

// @fnv 0x00b805d0
void BSShaderBloodSplatter::FUN_00b805d0(unsigned int pass)
{
    switch (pass)
    {
    case 0x2f0:
        DAT_0126f74c = spRenderPass[1].m_pObject;
        break;
    case 0x2f1:
        DAT_0126f74c = spRenderPass[0].m_pObject;
        break;
    }
}

// Assigns value to the NiRefObject pointer at offset 0x44, releasing the old reference and incrementing the new one's ref count.
// @fnv 0x00b80600
void BSShaderBloodSplatter::FUN_00b80600(NiRefObject* value)
{
    NiRefObject** ppSlot = reinterpret_cast<NiRefObject**>(reinterpret_cast<char*>(this) + 0x44);
    NiRefObject* old = *ppSlot;
    if (old != value)
    {
        if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            reinterpret_cast<void(__thiscall*)(void*)>((*reinterpret_cast<void***>(old))[1])(old);
        *ppSlot = value;
        if (value)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
}

struct FUN_00b807c0_shell
{
    int __thiscall FUN_00b807c0(void* a, void* b);
};

// @fnv 0x00b807c0
int __thiscall FUN_00b807c0_shell::FUN_00b807c0(void* a, void* b)
{
    return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x28);
}

extern int g_011fedc8;

// @fnv 0x00b807b0
int* __cdecl FUN_00b807b0()
{
    return &g_011fedc8;
}

struct FUN_00b80380_shell
{
    void FUN_00b80380();
};
// Calls the virtual function at vtable slot 74 on this for each of the two pointers stored at this+0x6c and this+0x70.
// @fnv 0x00b80380
void FUN_00b80380_shell::FUN_00b80380()
{
    typedef void(__thiscall * Fn)(void*, void*);
    void** p = (void**)((char*)this + 0x6c);
    int n = 2;
    do
    {
        void* a = *p;
        Fn f = (*(Fn**)this)[74];
        f(this, a);
        ++p;
    } while (--n != 0);
}

struct FUN_00b80b20_shell : BSShaderBloodSplatter
{
    bool FUN_00b80b20();
};

// @fnv 0x00b80b20
bool FUN_00b80b20_shell::FUN_00b80b20()
{
    InitializeShaderData();
    return ConfigureShaderPass();
}

void __cdecl _delete(void*, unsigned int);
struct Standin00b80e40
{
    void __thiscall FUN_00b80650();
    void* __thiscall FUN_00b80e40(unsigned int);
};
// Calls FUN_00b80650, then deletes this with size 0x84 when bit 0 of a1 is set, and returns this.
// @fnv 0x00b80e40
void* __thiscall Standin00b80e40::FUN_00b80e40(unsigned int auiFlags)
{
    FUN_00b80650();
    if (auiFlags & 1)
        _delete(this, 0x84);
    return this;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator-(const NiPoint3& p) const
    {
        return NiPoint3(x - p.x, y - p.y, z - p.z);
    }
    float operator*(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    void ComputeMagnitude();
};

struct Picker_00b803b0
{
    bool FUN_00b5bca0(const NiPoint3& akStart, const NiPoint3& kWorldPosition, NiPoint3& kHit);
};
extern Picker_00b803b0* DAT_011f91c8;
extern float DAT_011fed90;
extern SplatterFloat4 DAT_011fed94;

struct Camera_00b803b0
{
    char pad00[0x68];
    float m00;  // +0x68
    float m01, m02;
    float m10;  // +0x74
    float m11, m12;
    float m20;  // +0x80
    float m21, m22;
    NiPoint3 m_kWorldTranslate;  // +0x8c
    bool ProjectPointToScreen(const NiPoint3& kPt, float& fX, float& fY, float& fZ, float fZeroTolerance);
};

// @fnv 0x00b803b0
void __cdecl FUN_00b803b0(Camera_00b803b0* pkCamera)
{
    DAT_011fed90 = 0.0f;
    NiPoint3 kHit;
    if (DAT_011f91c8->FUN_00b5bca0(pkCamera->m_kWorldTranslate, NiPoint3(pkCamera->m00, pkCamera->m10, pkCamera->m20),
                                   kHit))
    {
        NiPoint3 kWorldPosition(pkCamera->m00, pkCamera->m10, pkCamera->m20);
        NiPoint3 kDelta = kHit - pkCamera->m_kWorldTranslate;
        kWorldPosition.ComputeMagnitude();
        kDelta.ComputeMagnitude();
        DAT_011fed90 = kDelta * kWorldPosition;
        float fX, fY, fZ;
        if (pkCamera->ProjectPointToScreen(kHit, fX, fY, fZ, 1e-05f))
        {
            if (fX < 0.0f)
                fX = 0.0f;
            else if (fX > 1.0f)
                fX = 1.0f;
            if (fY < 0.0f)
                fY = 0.0f;
            else if (fY > 1.0f)
                fY = 1.0f;
            SplatterFloat4 kResult;
            kResult.x = fX * 2.0 - 1.0f;
            kResult.y = 2.0 * fY - 1.0f;
            kResult.z = fZ;
            kResult.w = 0.1f;
            DAT_011fed94 = kResult;
        }
        else
        {
            SplatterFloat4 kResult;
            kResult.x = 0.0f;
            kResult.y = 0.0f;
            kResult.z = 0.0f;
            kResult.w = 0.1f;
            DAT_011fed94 = kResult;
        }
    }
    else
    {
        SplatterFloat4 kResult;
        kResult.x = 0.0f;
        kResult.y = 0.0f;
        kResult.z = 0.0f;
        kResult.w = 0.1f;
        DAT_011fed94 = kResult;
    }
}

struct FUN_00b80f50_shell : public BSShaderBloodSplatter
{
    void CreateShaderConstantMaps();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char $SG3295[];
extern char _DAT_010A1E50[];
extern int DAT_011fedb4;
extern float DAT_011feda4;

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    static void __cdecl operator delete(void*);
    virtual void v0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};

struct NiD3DShaderConstantMap : BSFadeNode
{
    NiD3DShaderConstantMap(void*, int);
    virtual int AddEntry(const char* pcKey, unsigned int uiFlags, unsigned int uiExtra, unsigned int uiShaderRegister,
                         unsigned int uiRegisterCount, const char* pcVariableName, unsigned int uiConstantDataSize,
                         unsigned int uiDataStride, const void* pvDataSource, bool bCopyData);
    char m_auiShapeKeys[0x44 - 8];
};

template <class T> struct NiPointerS
{
    T* m_pObject;
    NiPointerS& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator!() const
    {
        return m_pObject == 0;
    }
};

// Lazily creates the two NiD3DShaderConstantMap objects stored at offsets 0x30 and 0x34 and registers their shader constant entries.
// @fnv 0x00b80f50
void FUN_00b80f50_shell::CreateShaderConstantMaps()
{
    NiPointerS<NiD3DShaderConstantMap>& pAlphaMap = *(NiPointerS<NiD3DShaderConstantMap>*)((char*)this + 0x30);
    NiPointerS<NiD3DShaderConstantMap>& m_pVertexShaderConstantMap =
        *(NiPointerS<NiD3DShaderConstantMap>*)((char*)this + 0x34);
    if (!pAlphaMap)
    {
        pAlphaMap = new NiD3DShaderConstantMap(*(void**)((char*)this + 0x18), 2);
        pAlphaMap->AddEntry("alpha", 0x10000007, 0, 0, 1, $SG3295, 0x10, 4, &DAT_011fedb4, false);
    }
    if (!m_pVertexShaderConstantMap)
    {
        m_pVertexShaderConstantMap = new NiD3DShaderConstantMap(*(void**)((char*)this + 0x18), 0);
        m_pVertexShaderConstantMap->AddEntry(_DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        m_pVertexShaderConstantMap->AddEntry("lightloc", 0x10000007, 0, 4, 1, $SG3295, 0x10, 4, &g_splatterValueA,
                                             false);
        m_pVertexShaderConstantMap->AddEntry("ctrl", 0x10000007, 0, 5, 1, $SG3295, 0x10, 4, &DAT_011feda4, false);
    }
}

struct ShaderBase
{
    virtual ~ShaderBase();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
};
struct PassRef
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int refs;
    void FUN_00e80190();
    void Release()
    {
        --refs;
        if (!refs)
            FUN_00e80190();
    }
};
struct RefView
{
    virtual void v00();
    virtual void Delete();
    long refs;
    void Release()
    {
        if (InterlockedDecrement(&refs) == 0)
            Delete();
    }
};
struct FUN_00b80650 : ShaderBase
{
    NiPointer<NiD3DPass> passes[2];
    NiPointer<NiD3DVertexShader> vertex[2];
    NiPointer<NiD3DPixelShader> pixel[2];
    virtual ~FUN_00b80650();
};
// Releases the two pass, vertex-shader and pixel-shader references and the white-flash texture, clearing each pointer.
// @fnv 0x00b80650
FUN_00b80650::~FUN_00b80650()
{
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (passes[i].m_pObject)
        {
            ((PassRef*)passes[i].m_pObject)->Release();
            passes[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (vertex[i].m_pObject)
        {
            ((RefView*)vertex[i].m_pObject)->Release();
            vertex[i].m_pObject = 0;
        }
    }
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (pixel[i].m_pObject)
        {
            ((RefView*)pixel[i].m_pObject)->Release();
            pixel[i].m_pObject = 0;
        }
    }
    if (*(RefView**)&g_splatterWhiteFlashTexture)
    {
        (*(RefView**)&g_splatterWhiteFlashTexture)->Release();
        *(RefView**)&g_splatterWhiteFlashTexture = 0;
    }
}

struct FUN_00b80b30_item
{
    int unk00;
    int unk04;
    unsigned int m_u08;
    void ApplyPairToState(void* pValue);
};

struct FUN_00b80b30_pass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FUN_00b80b30_item** m_ppItems;
};

struct FUN_00b80b30_sub
{
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void* v51();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int m_arr60[2];
};

struct FUN_00b80b30_arg
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00b80b30_sub* m_pSub;
};

struct FUN_00b80b30_mgr
{
    void* FUN_00ba3780();
};

extern FUN_00b80b30_mgr DAT_012005a4;
extern int DAT_011f91e4;
extern int DAT_011fedc4;

class FUN_00b80b30_cls
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    FUN_00b80b30_pass* m_pPass6c;
    FUN_00b80b30_pass* m_p70;
    void InitPassItems(FUN_00b80b30_arg* a1);
};

// Fills the pass items' m_u08 from the sub's m_arr60 and calls ApplyPairToState with sub->v51(), branching on DAT_011f91e4, then calls v108().
// @fnv 0x00b80b30
void FUN_00b80b30_cls::InitPassItems(FUN_00b80b30_arg* apArg)
{
    FUN_00b80b30_sub* sub = apArg->m_pSub;
    if (DAT_011f91e4 == 0x2f1)
    {
        FUN_00b80b30_pass* pass = m_pPass6c;
        for (unsigned int i = 0; i < 2; i++)
        {
            FUN_00b80b30_item* item = pass->m_ppItems[i];
            item->m_u08 = sub->m_arr60[i];
            void* value = sub->v51();
            item->ApplyPairToState(value);
        }
    }
    else if (DAT_011f91e4 == 0x2f0)
    {
        FUN_00b80b30_pass* pass = m_p70;
        FUN_00b80b30_item* pFirstItem = pass->m_ppItems[0];
        pFirstItem->m_u08 = sub->m_arr60[0];
        void* value0 = sub->v51();
        pFirstItem->ApplyPairToState(value0);
        FUN_00b80b30_item* pSecondItem = pass->m_ppItems[1];
        if (DAT_012005a4.FUN_00ba3780())
        {
            pSecondItem->m_u08 = (unsigned int)DAT_012005a4.FUN_00ba3780();
        }
        else
        {
            pSecondItem->m_u08 = DAT_011fedc4;
        }
        void* value1 = sub->v51();
        pSecondItem->ApplyPairToState(value1);
    }
    v108();
}

namespace fnv_00b80c20 {
struct Bound
{
    float x, y, z, radius;
};
extern Bound DAT_011f4288;
extern unsigned int DAT_011f91e4;
extern float DAT_011ad874, DAT_011ad878;
struct WorldTransform
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22, x, y, z, scale;
};
struct GeomData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    void* data;
};
struct GeomStub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    Bound* bound;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    WorldTransform transform;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    GeomData* mesh;
    void* properties;
};
extern GeomStub** DAT_011f91e0;
struct RendererStub
{
    void FUN_00e6fbb0(WorldTransform*, int);
};
struct EffectObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    float scale;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float* value;
};
struct RenderInput
{
    unsigned int unk00, unk04, unk08;
    EffectObject* object;
};
struct ConstantMapView
{
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
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void Apply(void*, GeomStub*, void*, int, void*, RenderInput*, int, WorldTransform*, Bound*, int, int);
};
struct BloodShader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    RendererStub* renderer;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    ConstantMapView* pixelMap;
    ConstantMapView* vertexMap;
    void ApplyBloodShader(RenderInput*);
};
// Computes a scaled value from the render input's object, applies the pixel and vertex constant maps to the current geometry with the bound and transform.
// @fnv 0x00b80c20
void BloodShader::ApplyBloodShader(RenderInput* input)
{
    GeomStub* geom = *DAT_011f91e0;
    WorldTransform* transform = &geom->transform;
    Bound* bound = geom->bound;
    if (!bound)
        bound = &DAT_011f4288;
    void* data = geom->mesh->data;
    void* properties = geom->properties;
    renderer->FUN_00e6fbb0(transform, 0);
    float value = *input->object->value * input->object->scale;
    *(float*)&DAT_011fedb4 = value * DAT_011ad878;
    if (DAT_011f91e4 == 0x2f0)
        *(float*)&DAT_011fedb4 = DAT_011fed90 * DAT_011ad874 * *(float*)&DAT_011fedb4;
    ConstantMapView* map = pixelMap;
    if (map)
    {
        NiD3DPixelShader* shader = DAT_0126f74c->m_spPixelShaderObject.m_pObject;
        if (shader)
            map->Apply(shader, geom, properties, 0, data, input, 0, transform, bound, 0, 1);
    }
    map = vertexMap;
    if (map)
    {
        NiD3DVertexShader* shader = DAT_0126f74c->m_spVertexShaderObject.m_pObject;
        if (shader)
            map->Apply(shader, geom, properties, 0, data, input, 0, transform, bound, 0, 1);
    }
}
}  // namespace fnv_00b80c20
