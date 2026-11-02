// bsshader/beamshader.cpp: BeamPassShader, BloodSplatterBeamShader, DistantLODShader (6 functions)

#include "beamshader_types_BeamShader.h"
#include "beamshader_types_NiConsoleShaderDeclaration.h"
#include "beamshader_types_NiD3DShaderConstantMap.h"

extern GraphicsRenderer* g_pkRenderer;
extern const char g_emptyTopicInfoPrompt[1];
extern "C" const char DAT_010A1E50[];
extern "C" const char DAT_010af454[];

class DeclarationSlots
{
  public:
#define F(N) virtual void f##N();
    F(0)
    F(1)
    F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) F(12) F(13) F(14) F(15) F(16) F(17) F(18) F(19) F(20) F(21)
        F(22) F(23) F(24) F(25) F(26) F(27) F(28) F(29) F(30) F(31) F(32) F(33)
            F(34) virtual void f35(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    F(36) F(37) F(38) F(39) F(40) F(41) F(42) F(43) F(44) virtual void f45();
#undef F
};

class BeamShaderSlots
{
  public:
#define F(N) virtual void f##N();
    F(0)
    F(1)
    F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) F(12) F(13) F(14) F(15) F(16) F(17) F(18) virtual void f19();
    F(20)
    F(21)
    F(22) F(23) F(24) F(25) F(26) F(27) F(28) F(29) F(30) F(31) F(32) F(33) F(34) F(35) F(36) F(37) F(38) F(39) F(40)
        F(41) F(42) F(43) F(44) F(45) F(46) F(47) virtual void f48(void*);
    F(49)
    F(50)
    F(51) F(52) F(53) F(54) F(55) F(56) F(57) F(58) F(59) F(60) F(61) F(62) F(63) F(64) F(65) F(66) F(67) F(68) F(69)
        F(70) virtual void f71();
    F(72) F(73) F(74) F(75) F(76) F(77) F(78) virtual void f79();
    virtual void f80();
#undef F
};

class BloodSplatterBeamShader : public BeamShader
{
  public:
    static void* operator new(unsigned int) throw();
    BloodSplatterBeamShader(NiD3DVertexDeclaration*);
    static BSShader* CreateShader();
};

// @fnv 0x00bc4af0
BSShader* BloodSplatterBeamShader::CreateShader()
{
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create((NiRenderer*)g_pkRenderer, 5, 1);
    DeclarationSlots* declarationSlots = (DeclarationSlots*)declaration;
    declarationSlots->f35(0, 0, 0, 2, 0);
    declarationSlots->f35(1, 3, 3, 2, 0);
    declarationSlots->f35(2, 5, 4, 3, 0);
    declarationSlots->f35(3, 7, 5, 1, 0);
    declarationSlots->f45();

    BloodSplatterBeamShader* pShader = new BloodSplatterBeamShader(declaration);
    BeamShaderSlots* shaderSlots = (BeamShaderSlots*)pShader;
    shaderSlots->f19();
    shaderSlots->f79();
    shaderSlots->f80();
    shaderSlots->f71();
    shaderSlots->f48(declaration);
    return pShader;
}

class MapPointer
{
  public:
    NiD3DShaderConstantMap* m_pShaderConstantMap;

    MapPointer& operator=(NiD3DShaderConstantMap* pointer)
    {
        if (m_pShaderConstantMap != pointer)
        {
            if (m_pShaderConstantMap)
                m_pShaderConstantMap->DecRefCount();
            m_pShaderConstantMap = pointer;
            if (m_pShaderConstantMap)
                m_pShaderConstantMap->IncRefCount();
        }
        return *this;
    }
};

class DistantLODShader
{
  public:
    unsigned char padding0[0x18];
    GraphicsRenderer* m_pShaderObject;
    unsigned char padding1[0x14];
    MapPointer m_spFirstShaderConstantMap;
    MapPointer m_spSecondShaderConstantMap;
    unsigned char padding2[0x3c];
    float m_fVars[16];

    void UpdateShaderConstants();
};

// Creates the shader constant maps for the shader if not already present, setting constants on the first map.
// @fnv 0x00bc4ed0
void DistantLODShader::UpdateShaderConstants()
{
    if (!m_spSecondShaderConstantMap.m_pShaderConstantMap)
    {
        NiD3DShaderConstantMap* map = new NiD3DShaderConstantMap(m_pShaderObject, 0);
        m_spSecondShaderConstantMap = map;
        m_spSecondShaderConstantMap.m_pShaderConstantMap->SetConstant(DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, 0);
        m_spSecondShaderConstantMap.m_pShaderConstantMap->SetConstant(DAT_010af454, 0x10000009, 0, 4, 4,
                                                                      g_emptyTopicInfoPrompt, 0x40, 4, &m_fVars[0], 0);
    }
    if (!m_spFirstShaderConstantMap.m_pShaderConstantMap)
    {
        NiD3DShaderConstantMap* map = new NiD3DShaderConstantMap(m_pShaderObject, 2);
        m_spFirstShaderConstantMap = map;
    }
}

#include "beamshader_pass.h"
// Ensures the pass has a stage, then assigns vertex/pixel shaders and sets the pass render states.
// @fnv 0x00bc4c00
void BeamPassShader::SetupPass()
{
    BeamPassPointer p;
    BeamStagePointer stage;
    p = pass.m_pObject;
    if (p.object->GetStageCount() < 1)
    {
        BeamStage::CreateNewStage((NiPointer<BeamStage>&)stage);
        ConfigureBeamStage(stage.object, 0, 1, 2, true);
        stage.object->state->FUN_00e890c0(7, 0, 0, false);
        p.object->FUN_00e802b0(p.object->stages, stage.object);
    }
    p.object->vertex = vertex;
    p.object->pixel = pixel;
    p.object->SetRenderState(22, 1, true);
    p.object->SetRenderState(168, 15, true);
    p.object->SetRenderState(27, 1, true);
    p.object->SetRenderState(19, 5, true);
    p.object->SetRenderState(20, 6, true);
    p.object->SetRenderState(15, 0, true);
    p.object->SetRenderState(52, 0, true);
    p.object->SetRenderState(7, 1, true);
    p.object->SetRenderState(23, 4, true);
    p.object->SetRenderState(14, 0, true);
}

// @fnv 0x00bc4ea0
bool BeamPassShader::InitializePass()
{
    if (!pass.m_pObject)
        NiD3DPass::CreateD3DPass(pass);
    SetupPass();
    return true;
}

struct Holder
{
    void FUN_00bc49a0();
};
void __cdecl _delete(void*, unsigned int);
struct S
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bc49a0 on this, deletes this with size 0xc0 when flag has bit 0 set, and returns this.
// @fnv 0x00bc4e70
void* S::DestroyIfFlagged(unsigned int auiFlags)
{
    ((Holder*)this)->FUN_00bc49a0();
    if (auiFlags & 1)
        _delete(this, 0xc0);
    return this;
}

class ShaderBaseStub
{
  public:
    virtual ~ShaderBaseStub();
};

class FUN_00bc49a0 : public ShaderBaseStub
{
  public:
    static NiPointer<NiRefObject> ms_spShared;
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    NiPointer<NiD3DPass> m_spPass;
    NiPointer<NiRefObject> m_spVertexShaderObject;
    NiPointer<NiRefObject> m_spPixelShaderObject;
    virtual ~FUN_00bc49a0();
};

// Clears the shared pointer and the pass and two other reference-counted pointers, releasing them.
// @fnv 0x00bc49a0
FUN_00bc49a0::~FUN_00bc49a0()
{
    ms_spShared = 0;
    m_spPass = 0;
    m_spVertexShaderObject = 0;
    m_spPixelShaderObject = 0;
}
