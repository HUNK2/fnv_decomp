// bsshader/watershader.cpp: WaterShader, MaterialShader, WaterShaderLoader, WaterShaderReleaser and more (12 functions)

#include "watershader_decls.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);
#pragma intrinsic(memset)

// Creates the vertex and pixel shader constant maps once, registers their constants and stores the resulting handles in globals.
// @fnv 0x00b86f20
void WaterShader::UpdateShaderConstants()
{
    WaterShaderThreadState* threadState = WaterShaderGetThreadState();
    WaterShaderMemContext m_uiMemoryContext(threadState, 29);
    if (!m_spSecondShaderConstantMap.m_pObject)
    {
        NiD3DShaderConstantMap* vertexMap = new NiD3DShaderConstantMap(m_pShaderObject, 0);
        m_spSecondShaderConstantMap = vertexMap;
        m_spSecondShaderConstantMap.m_pObject->vfn_68("WorldViewProjTranspose", 0x20000009, 0, "", 0, 0, 0, false);
        DAT_011ff4a0 = m_spSecondShaderConstantMap.m_pObject->vfn_70("WorldViewProjTranspose");
        m_spSecondShaderConstantMap.m_pObject->vfn_68("WorldTranspose", 0x20000009, 4, "", 0, 0, 0, false);
        DAT_011ff4a4 = m_spSecondShaderConstantMap.m_pObject->vfn_70("WorldTranspose");
        m_spSecondShaderConstantMap.m_pObject->vfn_8("CommonData", 0x10000009, 0, 8, 3, "", 0x30, 4, DAT_011ff548,
                                                     false);
        DAT_011ff4a8 = m_spSecondShaderConstantMap.m_pObject->vfn_70("CommonData");
    }
    if (!m_spFirstShaderConstantMap.m_pObject)
    {
        NiD3DShaderConstantMap* pixelMap = new NiD3DShaderConstantMap(m_pShaderObject, 2);
        m_spFirstShaderConstantMap = pixelMap;
        m_spFirstShaderConstantMap.m_pObject->vfn_8("CommonData", 0x10000009, 0, 1, 7, "", 0x70, 4, DAT_011ff588,
                                                    false);
        DAT_011ff4ac = m_spFirstShaderConstantMap.m_pObject->vfn_70("CommonData");
        m_spFirstShaderConstantMap.m_pObject->vfn_8("VarAmounts", 0x10000007, 0, 8, 1, "", 0x10, 4, DAT_011ff5f8,
                                                    false);
        DAT_011ff4b0 = m_spFirstShaderConstantMap.m_pObject->vfn_70("VarAmounts");
        m_spFirstShaderConstantMap.m_pObject->vfn_8("FogData", 0x1000000c, 0, 9, 2, "", 0x20, 4, DAT_011ff608, false);
        DAT_011ff4b4 = m_spFirstShaderConstantMap.m_pObject->vfn_70("FogData");
        m_spFirstShaderConstantMap.m_pObject->vfn_8("DepthData", 0x10000007, 0, 11, 1, "", 0x10, 4, DAT_011ff628,
                                                    false);
        DAT_011ff4b8 = m_spFirstShaderConstantMap.m_pObject->vfn_70("DepthData");
        m_spFirstShaderConstantMap.m_pObject->vfn_8("SunLightData", 0x1000000c, 0, 12, 2, "", 0x20, 4, DAT_011ff638,
                                                    false);
        DAT_011ff4bc = m_spFirstShaderConstantMap.m_pObject->vfn_70("SunLightData");
        m_spFirstShaderConstantMap.m_pObject->vfn_8("LightData", 0x10000009, 0, 14, 17, "", 0x110, 4, DAT_011ff658,
                                                    false);
        DAT_011ff4c0 = m_spFirstShaderConstantMap.m_pObject->vfn_70("LightData");
    }
    m_uiMemoryContext.Restore(threadState);
}

// @fnv 0x00b86bd0
WaterShader::WaterShader()
{
    m_iPassId = 13;
    m_bIsInitialized = true;
    m_spSecondTexture = 0;
    m_spTexture4 = 0;
    m_spFirstTexture = 0;
    WaterShaderTextures = 0;
    DAT_011ff370 = this;
    DAT_011ff104 = false;
    DAT_011ff103 = false;
    DAT_011ff102 = false;
    DAT_011ff458 = RgbaColor(0.0f, 0.0f, 0.0f, 0.0f);
    if (fnv_particle_shader_renderer_level <= 2)
        DAT_011ff100 = false;
    memset(&DAT_011ff118, 0, sizeof(DAT_011ff118.count) + sizeof(DAT_011ff118.active));
    memset(&DAT_011ff110, 0, sizeof(DAT_011ff110.frame) + sizeof(DAT_011ff110.flags));
}

// Builds a vertex declaration with four entries, creates and initializes a WaterShader, assigns the declaration, and returns the shader.
// @fnv 0x00b86de0
BSShader* WaterShader::CreateShader()
{
    WaterShaderThreadState* threadState = WaterShaderGetThreadState();
    WaterShaderMemContext m_uiMemoryContext(threadState, 29);
    NiD3DVertexDeclaration* declaration = NiD3DVertexDeclaration::Create(DAT_011f9508, 4, 1);
    declaration->SetEntry(0, 0, 0, 2, 0);
    declaration->SetEntry(1, 3, 3, 2, 0);
    declaration->SetEntry(2, 5, 4, 4, 0);
    declaration->SetEntry(3, 7, 5, 1, 0);
    declaration->vfn_b4();
    WaterShader* shader = new WaterShader;
    shader->Initialize();
    shader->InitializeShaderData();
    shader->InitWaterPasses();
    shader->vfn_11c();
    shader->UseShaderDeclaration(declaration);
    m_uiMemoryContext.Restore(threadState);
    return shader;
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011ff498;

// @fnv 0x00b827b0
GlobalObjectO2_00a7b610* __cdecl FUN_00b827b0()
{
    return &g_011ff498;
}

extern "C" void __cdecl _delete(void*, int);

struct FUN_00b86db0_shell
{
    void* FUN_00b86db0(int);
};

// Calls FUN_00b824b0, then deletes this with size 0x250 when bit 0 of arg is set, and returns this.
// @fnv 0x00b86db0
void* FUN_00b86db0_shell::FUN_00b86db0(int aiFlags)
{
    extern void __cdecl FUN_00b824b0();
    FUN_00b824b0();
    if (aiFlags & 1)
        _delete(this, 0x250);
    return this;
}

extern unsigned int DAT_011f91e4;
void __cdecl FUN_00b98480(int, int);
void __cdecl _FUN_00b98070(int, int);
struct FUN_00b86b80_inner
{
    unsigned char _0[0x24];
    unsigned int m_flags;
    unsigned char _1[0x38];
    unsigned char m_b60;
};
struct FUN_00b86b80_arg
{
    unsigned char _0[0xc];
    FUN_00b86b80_inner* m_p;
};
// Reads the global mode and the inner object's flags and byte, calling FUN_00b98480 or _FUN_00b98070 depending on the mode and flag checks.
// @fnv 0x00b86b80
void __stdcall FUN_00b86b80(FUN_00b86b80_arg* apArg)
{
    FUN_00b86b80_inner* pInner = apArg->m_p;
    unsigned int mode = DAT_011f91e4;
    if (pInner && (pInner->m_flags & 0x10000) > 0)
        FUN_00b98480(0, 0);
    if (mode != 0x288 && mode != 0x289 && pInner->m_b60 != 0)
        _FUN_00b98070(0, 0);
}

struct WaterPassOps
{
    void FUN_00b79950(NiD3DVertexShader*);
    void FUN_00b80600(NiD3DPixelShader*);
};

extern unsigned int DAT_11ff120;
extern unsigned int DAT_11ff124;
extern unsigned int DAT_11ff128;
extern unsigned int DAT_11ff12c;
extern unsigned int DAT_11ff130;
extern unsigned int DAT_11ff134;
extern unsigned int DAT_11ff138;
extern unsigned int DAT_11ff13c;
extern unsigned int DAT_11ff140;
extern unsigned int DAT_11ff144;
extern unsigned int DAT_11ff148;
extern unsigned int DAT_11ff14c;
extern unsigned int DAT_11ff150;
extern unsigned int DAT_11ff154;
extern unsigned int DAT_11ff158;
extern unsigned int DAT_11ff15c;
extern unsigned int DAT_11ff160;
extern unsigned int DAT_11ff164;
extern unsigned int DAT_11ff168;
extern unsigned int DAT_11ff16c;
extern unsigned int DAT_11ff170;
extern unsigned int DAT_11ff174;
extern unsigned int DAT_11ff178;
extern unsigned int DAT_11ff17c;
extern unsigned int DAT_11ff180;
extern unsigned int DAT_11ff184;
extern unsigned int DAT_11ff188;
extern unsigned int DAT_11ff18c;
extern unsigned int DAT_11ff190;
extern unsigned int DAT_11ff198;
extern unsigned int DAT_11ff19c;
extern unsigned int DAT_11ff1a0;
extern unsigned int DAT_11ff1a4;
extern unsigned int DAT_11ff1a8;
extern unsigned int DAT_11ff1ac;
extern unsigned int DAT_11ff1b0;
extern unsigned int DAT_11ff1b4;
extern unsigned int DAT_11ff1b8;
extern unsigned int DAT_11ff1bc;
extern unsigned int DAT_11ff1c0;
extern unsigned int DAT_11ff1c4;
extern unsigned int DAT_11ff1c8;
extern unsigned int DAT_11ff1cc;
extern unsigned int DAT_11ff1d0;
extern unsigned int DAT_11ff1d4;
extern unsigned int DAT_11ff1d8;
extern unsigned int DAT_11ff1dc;
extern unsigned int DAT_11ff1e0;
extern unsigned int DAT_11ff1e4;
extern unsigned int DAT_11ff1e8;
extern unsigned int DAT_11ff1ec;
extern unsigned int DAT_11ff1f0;
extern unsigned int DAT_11ff1f4;
extern unsigned int DAT_11ff1f8;
extern unsigned int DAT_11ff1fc;
extern unsigned int DAT_11ff200;
extern unsigned int DAT_11ff204;
extern unsigned int DAT_11ff208;
extern unsigned int DAT_11ff20c;
extern unsigned int DAT_11ff210;
extern unsigned int DAT_11ff214;
extern unsigned int DAT_11ff218;
extern unsigned int DAT_11ff21c;
extern unsigned int DAT_11ff220;
extern unsigned int DAT_11ff224;
extern unsigned int DAT_11ff228;
extern unsigned int DAT_11ff230;
extern unsigned int DAT_11ff234;
extern unsigned int DAT_11ff238;
extern unsigned int DAT_11ff23c;
extern unsigned int DAT_11ff240;
extern unsigned int DAT_11ff244;
struct Ref112
{
    virtual void Unused();
    virtual void DeleteThis();
    long refs;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Stage112
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
    int count;
    void FUN_00e7def0(unsigned int);
    void FUN_00e7ecd0();
    void Release()
    {
        --count;
        if (!count)
            FUN_00e7ecd0();
    }
};
struct StagePtr112
{
    Stage112* p;
    StagePtr112() : p(0)
    {}
    ~StagePtr112()
    {
        if (p)
            p->Release();
    }
};
struct WaterConstantState
{
    void SetNodeValue(unsigned int, unsigned int, unsigned int);
};
extern WaterConstantState* __cdecl FUN_00e7f5d0();
struct Pass112
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* stages;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    WaterConstantState* map;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    Ref112* pixel;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    Ref112* vertex;
    void FUN_00e802b0(void*, Stage112*);
    void FUN_00b80040(unsigned int, unsigned int, unsigned int);
};
extern void __cdecl FUN_00e804d0(Pass112**);
extern void __cdecl AssignStageFromPool(Stage112**);
extern void __cdecl ConfigureBeamStage(Stage112*, unsigned int, unsigned int, unsigned int, unsigned int);
static __forceinline void AssignPassConstant(Pass112* pass, unsigned int index, unsigned int kind, unsigned int stages)
{
    if (!pass->map)
        pass->map = FUN_00e7f5d0();
    pass->map->SetNodeValue(index, kind, stages);
}
static __forceinline void AssignRef112(Ref112*& dst, Ref112* src)
{
    Ref112* old = dst;
    if (old != src)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->refs) == 0)
                old->DeleteThis();
        }
        dst = src;
        if (src)
            InterlockedIncrement(&src->refs);
    }
}
static __forceinline void SetSpecial112(Pass112* pass)
{
    AssignPassConstant(pass, 0x13, 5, 1);
    AssignPassConstant(pass, 0x14, 2, 1);
}
struct Water112 : WaterShader
{
    bool InitWaterPasses();
};
// @fnv 0x00b83dd0
bool Water112::InitWaterPasses()
{
    for (int iPass = 0; iPass < 74; ++iPass)
    {
        Pass112** slot = (Pass112**)&spRenderPass[iPass];
        if ((*slot) == 0)
        {
            FUN_00e804d0(slot);
            StagePtr112 declaration;
            AssignStageFromPool(&declaration.p);
            ConfigureBeamStage(declaration.p, 0, 3, 2, 1);
            declaration.p->FUN_00e7def0(1);
            (*slot)->FUN_00e802b0((*slot)->stages, declaration.p);
            AssignStageFromPool(&declaration.p);
            ConfigureBeamStage(declaration.p, 1, 3, 2, 1);
            declaration.p->FUN_00e7def0(1);
            (*slot)->FUN_00e802b0((*slot)->stages, declaration.p);
            AssignStageFromPool(&declaration.p);
            ConfigureBeamStage(declaration.p, 2, 1, 2, 1);
            declaration.p->FUN_00e7def0(1);
            (*slot)->FUN_00e802b0((*slot)->stages, declaration.p);
            AssignStageFromPool(&declaration.p);
            ConfigureBeamStage(declaration.p, 3, 1, 2, 1);
            declaration.p->FUN_00e7def0(1);
            (*slot)->FUN_00e802b0((*slot)->stages, declaration.p);
            AssignStageFromPool(&declaration.p);
            ConfigureBeamStage(declaration.p, 4, 3, 2, 1);
            declaration.p->FUN_00e7def0(1);
            (*slot)->FUN_00e802b0((*slot)->stages, declaration.p);
            AssignPassConstant(*slot, 0x0f, 1, 1);
            AssignPassConstant(*slot, 0x18, 0, 1);
            AssignPassConstant(*slot, 0x19, 5, 1);
            if (iPass != 0x21)
            {
                if (iPass != 0x24 && iPass != 0x48 && iPass != 0x25 && iPass != 0x49)
                {
                    AssignPassConstant(*slot, 0x1b, 1, 1);
                    (*slot)->FUN_00b80040(5, 6, 0);
                }
                else
                {
                    AssignPassConstant(*slot, 0x1b, 1, 1);
                    SetSpecial112(*slot);
                }
            }
            if ((iPass >= 0x11 && iPass <= 0x1c) || (iPass >= 0x37 && iPass <= 0x42))
            {
                AssignPassConstant(*slot, 0x34, 1, 1);
            }
            else if ((iPass >= 0 && iPass <= 0x1c) || (iPass >= 0x26 && iPass <= 0x42) || iPass == 0x24 ||
                     iPass == 0x48)
            {
                AssignPassConstant(*slot, 0x34, 1, 1);
                AssignPassConstant(*slot, 0x38, 6, 1);
                AssignPassConstant(*slot, 0x39, 1, 1);
                AssignPassConstant(*slot, 0x3a, 1, 1);
                AssignPassConstant(*slot, 0x37, 1, 1);
            }
            if (iPass == 0x23 || iPass == 0x47)
            {
                AssignPassConstant(*slot, 0xa8, 0, 1);
                AssignPassConstant(*slot, 0x0e, 0, 1);
                AssignPassConstant(*slot, 0x34, 1, 1);
                AssignPassConstant(*slot, 0x38, 3, 1);
                AssignPassConstant(*slot, 0x39, 0xff, 1);
                AssignPassConstant(*slot, 0x37, 3, 1);
                AssignPassConstant(*slot, 0x3a, 0, 1);
            }
        }
    }
    AssignRef112(((Pass112*)spRenderPass[0].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[0].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[0].m_pObject);
    DAT_11ff120 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[1].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[1].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[1].m_pObject);
    DAT_11ff124 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[2].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[2].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[2].m_pObject);
    DAT_11ff128 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[3].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[3].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[3].m_pObject);
    DAT_11ff12c = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[4].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[4].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[4].m_pObject);
    DAT_11ff130 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[5].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[5].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[5].m_pObject);
    DAT_11ff134 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[6].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[6].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[6].m_pObject);
    DAT_11ff138 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[7].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[7].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[7].m_pObject);
    DAT_11ff13c = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[8].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[8].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[8].m_pObject);
    DAT_11ff140 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[9].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[9].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[9].m_pObject);
    DAT_11ff144 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[10].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[10].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[10].m_pObject);
    DAT_11ff148 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[11].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[11].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[11].m_pObject);
    DAT_11ff14c = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[12].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[12].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[12].m_pObject);
    DAT_11ff150 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[13].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[13].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[13].m_pObject);
    DAT_11ff154 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[14].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[14].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[14].m_pObject);
    DAT_11ff158 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[15].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[15].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[15].m_pObject);
    DAT_11ff15c = 0xe;
    AssignRef112(((Pass112*)spRenderPass[16].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[16].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[16].m_pObject);
    DAT_11ff160 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[17].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[17].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[17].m_pObject);
    DAT_11ff164 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[18].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[18].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[18].m_pObject);
    DAT_11ff168 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[19].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[19].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[19].m_pObject);
    DAT_11ff16c = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[20].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[20].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[20].m_pObject);
    DAT_11ff170 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[21].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[21].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[21].m_pObject);
    DAT_11ff174 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[22].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[22].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[22].m_pObject);
    DAT_11ff178 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[23].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[23].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[23].m_pObject);
    DAT_11ff17c = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[24].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[24].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[24].m_pObject);
    DAT_11ff180 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[25].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[25].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[25].m_pObject);
    DAT_11ff184 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[26].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[26].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[26].m_pObject);
    DAT_11ff188 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[27].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[27].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[27].m_pObject);
    DAT_11ff18c = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[28].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[28].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[28].m_pObject);
    DAT_11ff190 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[29].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[29].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[29].m_pObject);
    DAT_11ff190 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[30].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[30].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[30].m_pObject);
    DAT_11ff198 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[31].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[31].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[31].m_pObject);
    DAT_11ff19c = 0xe;
    AssignRef112(((Pass112*)spRenderPass[32].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[32].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[32].m_pObject);
    DAT_11ff1a0 = 0xe;
    AssignRef112(((Pass112*)spRenderPass[33].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[33].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[33].m_pObject);
    DAT_11ff1a4 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[34].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[34].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[34].m_pObject);
    DAT_11ff1a8 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[35].m_pObject)->vertex, (Ref112*)m_spVertexShader1.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[35].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[35].m_pObject);
    DAT_11ff1ac = 0;
    AssignRef112(((Pass112*)spRenderPass[36].m_pObject)->vertex, (Ref112*)m_spVertexShader3.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[36].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[36].m_pObject);
    DAT_11ff1b0 = 0x4e;
    AssignRef112(((Pass112*)spRenderPass[37].m_pObject)->vertex, (Ref112*)m_spVertexShader3.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[37].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[37].m_pObject);
    DAT_11ff1b4 = 0x4e;
    AssignRef112(((Pass112*)spRenderPass[38].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[38].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[0].m_pObject);
    DAT_11ff1b8 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[39].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[39].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[1].m_pObject);
    DAT_11ff1bc = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[40].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[40].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[2].m_pObject);
    DAT_11ff1c0 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[41].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[41].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[3].m_pObject);
    DAT_11ff1c4 = 0x3e;
    AssignRef112(((Pass112*)spRenderPass[42].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[42].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[4].m_pObject);
    DAT_11ff1c8 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[43].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[43].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[5].m_pObject);
    DAT_11ff1cc = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[44].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[44].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[6].m_pObject);
    DAT_11ff1d0 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[45].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[45].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[7].m_pObject);
    DAT_11ff1d4 = 0x2e;
    AssignRef112(((Pass112*)spRenderPass[46].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[46].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[8].m_pObject);
    DAT_11ff1d8 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[47].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[47].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[9].m_pObject);
    DAT_11ff1dc = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[48].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[48].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[10].m_pObject);
    DAT_11ff1e0 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[49].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    AssignRef112(((Pass112*)spRenderPass[49].m_pObject)->pixel, (Ref112*)m_aspPixelShaders[11].m_pObject);
    DAT_11ff1e4 = 0x1e;
    AssignRef112(((Pass112*)spRenderPass[50].m_pObject)->vertex, (Ref112*)m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[50].m_pObject)->FUN_00b80600(m_aspPixelShaders[12].m_pObject);
    DAT_11ff1e8 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[51].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[51].m_pObject)->FUN_00b80600(m_aspPixelShaders[13].m_pObject);
    DAT_11ff1ec = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[52].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[52].m_pObject)->FUN_00b80600(m_aspPixelShaders[14].m_pObject);
    DAT_11ff1f0 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[53].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[53].m_pObject)->FUN_00b80600(m_aspPixelShaders[15].m_pObject);
    DAT_11ff1f4 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[54].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[54].m_pObject)->FUN_00b80600(m_aspPixelShaders[16].m_pObject);
    DAT_11ff1f8 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[55].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[55].m_pObject)->FUN_00b80600(m_aspPixelShaders[17].m_pObject);
    DAT_11ff1fc = 0x3e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[56].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[56].m_pObject)->FUN_00b80600(m_aspPixelShaders[18].m_pObject);
    DAT_11ff200 = 0x3e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[57].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[57].m_pObject)->FUN_00b80600(m_aspPixelShaders[19].m_pObject);
    DAT_11ff204 = 0x3e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[58].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[58].m_pObject)->FUN_00b80600(m_aspPixelShaders[20].m_pObject);
    DAT_11ff208 = 0x3e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[59].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[59].m_pObject)->FUN_00b80600(m_aspPixelShaders[21].m_pObject);
    DAT_11ff20c = 0x2e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[60].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[60].m_pObject)->FUN_00b80600(m_aspPixelShaders[22].m_pObject);
    DAT_11ff210 = 0x2e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[61].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[61].m_pObject)->FUN_00b80600(m_aspPixelShaders[23].m_pObject);
    DAT_11ff214 = 0x2e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[62].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[62].m_pObject)->FUN_00b80600(m_aspPixelShaders[24].m_pObject);
    DAT_11ff218 = 0x2e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[63].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[63].m_pObject)->FUN_00b80600(m_aspPixelShaders[25].m_pObject);
    DAT_11ff21c = 0x1e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[64].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[64].m_pObject)->FUN_00b80600(m_aspPixelShaders[26].m_pObject);
    DAT_11ff220 = 0x1e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[65].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[65].m_pObject)->FUN_00b80600(m_aspPixelShaders[27].m_pObject);
    DAT_11ff224 = 0x1e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[66].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[66].m_pObject)->FUN_00b80600(m_aspPixelShaders[28].m_pObject);
    DAT_11ff228 = 0x1e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[67].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[67].m_pObject)->FUN_00b80600(m_aspPixelShaders[29].m_pObject);
    DAT_11ff228 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[68].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[68].m_pObject)->FUN_00b80600(m_aspPixelShaders[30].m_pObject);
    DAT_11ff230 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[69].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[69].m_pObject)->FUN_00b80600(m_aspPixelShaders[31].m_pObject);
    DAT_11ff234 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[70].m_pObject)->FUN_00b79950(m_spVertexShader1.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[70].m_pObject)->FUN_00b80600(m_aspPixelShaders[32].m_pObject);
    DAT_11ff238 = 0xe;
    reinterpret_cast<WaterPassOps*>(spRenderPass[71].m_pObject)->FUN_00b79950(m_spVertexShader2.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[71].m_pObject)->FUN_00b80600(m_aspPixelShaders[35].m_pObject);
    DAT_11ff23c = 0;
    reinterpret_cast<WaterPassOps*>(spRenderPass[72].m_pObject)->FUN_00b79950(m_spVertexShader3.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[72].m_pObject)->FUN_00b80600(m_aspPixelShaders[36].m_pObject);
    DAT_11ff240 = 0x4e;
    reinterpret_cast<WaterPassOps*>(spRenderPass[73].m_pObject)->FUN_00b79950(m_spVertexShader3.m_pObject);
    reinterpret_cast<WaterPassOps*>(spRenderPass[73].m_pObject)->FUN_00b80600(m_aspPixelShaders[37].m_pObject);
    DAT_11ff244 = 0x4e;
    return true;
}

struct TextureReceiver
{
    void* BSRenderedTexture_GetTexture(int);
};
struct TextureBinding
{
    int unk00, unk04;
    void* texture;
};
struct TextureBindings
{
    TextureBinding* slots[5];
};
struct ShaderState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    TextureBindings* bindings;
};
extern ShaderState* DAT_0126f74c;
extern TextureReceiver* DAT_011f943c;
extern void* DAT_011f9510;
struct MaterialProperties
{
    int unk00;
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
    unsigned char flag60, flag61, flag62, flag63;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    unsigned char flag80, flag81, flag82, flag83;
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
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    TextureReceiver* texture138;
    TextureReceiver* texture13C;
    int unk140;
    TextureReceiver* texture144;
    void* texture148;
};
struct ShaderArgument
{
    int unk00, unk04, unk08;
    MaterialProperties* properties;
};
struct MaterialShader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    void BindMaterialTextures(ShaderArgument* argument);
};
// Clears the five texture slots, then binds textures from the material properties (unless mode is 0x288/0x289) and calls v66.
// @fnv 0x00b863a0
void MaterialShader::BindMaterialTextures(ShaderArgument* argument)
{
    unsigned int mode = DAT_011f91e4;
    ShaderState* state = DAT_0126f74c;
    MaterialProperties* properties = argument->properties;
    state->bindings->slots[0]->texture = 0;
    state->bindings->slots[1]->texture = 0;
    state->bindings->slots[2]->texture = 0;
    state->bindings->slots[3]->texture = 0;
    state->bindings->slots[4]->texture = 0;
    if (mode != 0x288 && mode != 0x289)
    {
        if (properties->texture13C && properties->flag80)
        {
            TextureBinding* target = state->bindings->slots[0];
            target->texture = properties->texture13C->BSRenderedTexture_GetTexture(0);
        }
        else
            state->bindings->slots[0]->texture = DAT_011f9510;
        if (DAT_011f943c && properties->flag81)
        {
            TextureBinding* target = state->bindings->slots[1];
            target->texture = DAT_011f943c->BSRenderedTexture_GetTexture(0);
        }
        if (properties->texture138)
        {
            TextureBinding* target = state->bindings->slots[2];
            target->texture = properties->texture138->BSRenderedTexture_GetTexture(0);
        }
        else
            state->bindings->slots[2]->texture = DAT_011f9510;
        if (properties->flag60 && properties->texture148)
            state->bindings->slots[3]->texture = properties->texture148;
        if (properties->texture144 && properties->flag63)
        {
            TextureBinding* target = state->bindings->slots[4];
            target->texture = properties->texture144->BSRenderedTexture_GetTexture(0);
        }
        v66();
    }
}

class D3DPassB824B0
{
  public:
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
            DeleteThis();
    }
    void DeleteThis();
    int unk00;
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
    unsigned int m_uiRefCount;
};
class D3DShaderProgramB824B0 : public NiRefObject
{
};
class TextureB824B0 : public NiRefObject
{
};
struct ShaderConstantB824B0
{
    float x;
    float y;
    float z;
    float w;
};
extern const ShaderConstantB824B0 g_kZeroConstantB824B0;
extern ShaderConstantB824B0 g_akVertexConstantsB824B0[11];
extern ShaderConstantB824B0 g_akPixelConstantsB824B0[31];
class ShaderBaseB824B0
{
  public:
    virtual ~ShaderBaseB824B0();
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
};
class FUN_00b824b0 : public ShaderBaseB824B0
{
  public:
    virtual ~FUN_00b824b0();
    NiPointer<D3DPassB824B0> m_aspPasses[74];
    NiPointer<D3DShaderProgramB824B0> m_spWaterVertexShader;
    NiPointer<D3DShaderProgramB824B0> m_spWaterVertexShaderVc;
    NiPointer<D3DShaderProgramB824B0> m_spWaterVertexShaderLighting;
    NiPointer<D3DShaderProgramB824B0> m_aspWaterPixelShaders[38];
    NiPointer<TextureB824B0> m_spNormalMapTexture;
    NiPointer<TextureB824B0> m_spReflectionTexture;
    NiPointer<TextureB824B0> m_spRefractionTexture;
    NiPointer<TextureB824B0> m_spInteriorReflectionTexture;
    NiPointer<TextureB824B0> m_spDetailTexture;
    NiPointer<TextureB824B0> m_spNoiseMap;
};

// Destructor that nulls the water shader NiPointers and arrays and zeroes the global vertex and pixel constant arrays.
// @fnv 0x00b824b0
FUN_00b824b0::~FUN_00b824b0()
{
    m_spWaterVertexShader = 0;
    m_spWaterVertexShaderVc = 0;
    m_spWaterVertexShaderLighting = 0;
    for (unsigned int i = 0; i < 74; ++i)
        m_aspPasses[i] = 0;
    for (unsigned int i = 0; i < 38; ++i)
        m_aspWaterPixelShaders[i] = 0;
    for (int i = 0; i < 11; ++i)
        g_akVertexConstantsB824B0[i] = g_kZeroConstantB824B0;
    for (int i = 0; i < 31; ++i)
        g_akPixelConstantsB824B0[i] = g_kZeroConstantB824B0;
}

struct WaterShaderDesc
{
    const char* pcFile;
    _D3DXMACRO kMacros[9];
};

struct WaterShaderScratch
{
    WaterShaderDesc kVertexDelta;
    WaterShaderDesc kVertexLighting;
    WaterShaderDesc kVertexVc;
    char acPixelFile[0x100];
    char acName[0x104];
    char acFile[0x104];
    char acLightingFile[0x100];
};

inline void InitWaterVertexBase(WaterShaderDesc& desc)
{
    desc.pcFile = "water\\2_ab\\v\\water.v.hlsl";
    desc.kMacros[0].Name = 0;
    desc.kMacros[0].Definition = 0;
    desc.kMacros[1].Name = 0;
    desc.kMacros[1].Definition = 0;
    fnv_zlib_memset(&desc.kMacros[2], 0, 56);
}

inline void InitWaterVertexVariant(WaterShaderDesc& desc, const char* macro)
{
    desc.pcFile = "water\\2_ab\\v\\water.v.hlsl";
    desc.kMacros[0].Name = macro;
    desc.kMacros[0].Definition = "";
    desc.kMacros[1].Name = 0;
    fnv_zlib_memset(&desc.kMacros[1].Definition, 0, 60);
}

class WaterShaderMemScope
{
    WaterShaderThreadState* pState;
    int iPrevious;

  public:
    WaterShaderMemScope(int m_uiMemoryContext) : pState(WaterShaderGetThreadState())
    {
        iPrevious = pState->m_uiMemoryContext;
        pState->m_uiMemoryContext = m_uiMemoryContext;
    }
    ~WaterShaderMemScope()
    {
        pState->m_uiMemoryContext = iPrevious;
    }
};

class WaterShaderLoader : public WaterShader
{
  public:
    void FUN_00b827c0();
};

// @fnv 0x00b827c0
void WaterShaderLoader::FUN_00b827c0()
{
    WaterShaderMemScope kScope(0x1d);

    WaterShaderScratch scratch;
    InitWaterVertexBase(scratch.kVertexDelta);
    GetShaderPath(scratch.kVertexDelta.pcFile, scratch.acFile);
    sprintf_s(scratch.acName, 0x104, "WATER000.vso");
    m_spVertexShader1 = CompileVertexShader(scratch.acFile, scratch.kVertexDelta.kMacros, "vs_1_1", scratch.acName);

    InitWaterVertexVariant(scratch.kVertexVc, "VERTEX_COLORS");
    GetShaderPath(scratch.kVertexVc.pcFile, scratch.acFile);
    sprintf_s(scratch.acName, 0x104, "WATER001.vso");
    m_spVertexShader2 = CompileVertexShader(scratch.acFile, scratch.kVertexVc.kMacros, "vs_1_1", scratch.acName);

    InitWaterVertexVariant(scratch.kVertexLighting, "LIGHTING");
    GetShaderPath(scratch.kVertexLighting.pcFile, scratch.acFile);
    sprintf_s(scratch.acName, 0x104, "WATER002.vso");
    m_spVertexShader3 = CompileVertexShader(scratch.acFile, scratch.kVertexLighting.kMacros, "vs_1_1", scratch.acName);

    int iLevel = fnv_particle_shader_renderer_level;
    const char* pcProfile = "ps_2_0";
    if (iLevel >= 7)
        pcProfile = "ps_3_0";
    else if (iLevel >= 6)
        pcProfile = "ps_2_b";
    else if (iLevel >= 5)
        pcProfile = "ps_2_a";
    else if (iLevel >= 2)
        pcProfile = "ps_2_0";

    if (iLevel > 4)
        sprintf_s(scratch.acPixelFile, 0x100, "water\\2_ab\\p\\water.p.hlsl");
    else
        sprintf_s(scratch.acPixelFile, 0x100, "water\\2_0\\p\\water.p.hlsl");
    sprintf_s(scratch.acLightingFile, 0x100, "water\\2_ab\\p\\waterlighting.p.hlsl");

    WaterShaderDesc kPixel[38] = {
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFRACTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFRACTIONS", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "FOG", "", 0}},
        {scratch.acPixelFile,
         {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFRACTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFRACTIONS", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"UNDERWATER", "", "REFRACTIONS", "", "FOG", "", 0}},
        {scratch.acPixelFile,
         {"WATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFRACTIONS", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFRACTIONS", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile,
         {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "WADING", "", "DEPTH", "", "FOG", "",
          0}},
        {scratch.acPixelFile,
         {"WATER", "", "INTERIORWATER", "", "REFRACTIONS", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile,
         {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "WADING", "", "DEPTH", "", "FOG", "", 0}},
        {scratch.acPixelFile,
         {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "REFRACTIONS", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFRACTIONS", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "REFLECTIONS", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "INTERIORWATER", "", "WADING", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "REFLECTIONS", "", "LOD", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"WATER", "", "LOD", "", "FOG", "", 0}},
        {scratch.acPixelFile, {"STENCIL", "", 0}},
        {scratch.acLightingFile, {0}},
        {scratch.acLightingFile, {"WADING", "", 0}},
    };

    for (int i = 0; i < 38; i++)
    {
        if (kPixel[i].pcFile)
        {
            GetShaderPath(kPixel[i].pcFile, scratch.acFile);
            sprintf_s(scratch.acName, 0x104, "WATER%03i.pso", i);
            m_aspPixelShaders[i] = CompilePixelShader(scratch.acFile, kPixel[i].kMacros, pcProfile, scratch.acName);
        }
    }
}

struct WaterShaderReleaser : WaterShader
{
    void ReleaseBase();
    void FUN_00b861c0();
};

// @fnv 0x00b861c0
void WaterShaderReleaser::FUN_00b861c0()
{
    ReleaseBase();
    InitWaterPasses();
}

struct WaterVec3
{

    float x, y, z;

    __forceinline WaterVec3()
    {}

    __forceinline WaterVec3(float a, float b, float c) : x(a), y(b), z(c)
    {}

    __forceinline WaterVec3 operator-(const WaterVec3& v) const
    {
        return WaterVec3(x - v.x, y - v.y, z - v.z);
    }

    __forceinline WaterVec3 operator*(float f) const
    {
        WaterVec3 result = *this;
        result *= f;
        return result;
    }

    __forceinline WaterVec3& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
};

struct WaterVec4
{

    float x, y, z, w;

    __forceinline WaterVec4()
    {}

    __forceinline WaterVec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};

struct WaterLight
{

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

    WaterVec3 position;

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

    float intensity;

    int unk0c8;

    int unk0cc;

    int unk0d0;

    WaterVec3 diffuse;

    float radius;
};

struct WaterLightNode
{
    WaterLightNode* next;
    int unk04;
    WaterLight* light;
};

struct WaterMaterial
{

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

    unsigned char enabled;
    unsigned char unk061, unk062, unk063;

    int unk064;

    int unk068;

    float scaleX;

    float scaleY;

    float fogFactor;

    float fogHeight;

    int unk07c;

    unsigned char unk080, unk081, opacity, unk083;

    unsigned int alpha;

    WaterVec4 color1;

    WaterVec4 color2;

    WaterVec4 color3;

    WaterVec4 color4;

    int unk0c8;

    int unk0cc;

    float reflection;

    float lightScale;

    WaterVec4 color5;

    int unk0e8;

    int unk0ec;

    int unk0f0;

    int unk0f4;

    int unk0f8;

    int unk0fc;

    float amount;

    float refraction;

    int unk108;

    int unk10c;

    int unk110;

    int unk114;

    float height;

    int unk11c;

    float fogAlpha;

    float reflectivity;

    WaterLightNode* lights;

    int unk12c;

    unsigned int lightCount;
};

struct WaterRenderArg
{
    int unk00, unk04, unk08;
    WaterMaterial* material;
};

struct WaterProperties
{

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

    void* data;
};

struct WaterGeometry
{

    int unk000;

    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    void* bound;

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

    WaterProperties* properties;

    void* geometryData;
};

struct WaterTransformSink
{
    void FUN_00e6fbb0(void*, int);
};

struct WaterProgram
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void slot8();

    virtual void slot9();

    virtual void slot10();

    virtual void slot11();

    virtual void slot12();

    virtual void slot13();

    virtual void slot14();

    virtual void slot15();

    virtual void slot16();

    virtual void slot17();

    virtual void slot18();

    virtual void slot19();

    virtual void slot20();

    virtual void slot21();

    virtual void slot22();

    virtual void slot23();

    virtual void slot24();

    virtual void slot25();

    virtual void slot26();

    virtual void slot27();

    virtual void slot28();

    virtual void slot29();

    virtual void Setup(void*, WaterGeometry*, void*, int, void*, WaterRenderArg*, int, void*, void*, int, int);
};

struct WaterRenderContext
{

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

    void* vertexShader;

    int unk048;

    int unk04c;

    int unk050;

    int unk054;

    int unk058;

    void* pixelShader;
};

struct WaterSetup
{

    int unk000;

    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    WaterTransformSink* transform;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    WaterProgram* vertex;

    WaterProgram* pixel;

    void FUN_00b864d0(WaterRenderArg*);
};

struct WaterFog
{

    int unk000;

    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    WaterVec3 color;

    float nearDistance;

    float farDistance;

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

    float power;
};

extern WaterGeometry** DAT_011f91e0;

extern WaterVec4 DAT_011fa2a0, DAT_011f4288;

extern WaterVec3 DAT_011f474c;

extern unsigned char DAT_011f91c4;

extern double DAT_01020758;

extern const double DAT_01012070;

extern float DAT_011ff108;

WaterFog* FUN_00b55520(int);

void UpdateRendererStateCount(int, int);

void FUN_00b98180(int, int, unsigned int, int);

void FUN_00b980c0(int, int, int, int);

void AddToSlot(unsigned int, int);

extern WaterVec4 DAT_011ff598;

extern WaterVec4 DAT_011ff5a8;

extern WaterVec4 DAT_011ff5b8;

extern WaterVec4 DAT_011ff618;

extern WaterVec4 DAT_011ff648;

extern WaterVec4 DAT_011ff398;

extern WaterVec4 DAT_011ff3a8;

extern WaterVec4 DAT_011ff568;

extern float DAT_011ff5c8;

extern float DAT_011ff5cc;

extern float DAT_011ff5d0;

extern float DAT_011ff5d4;

extern float DAT_011ff5d8;

extern float DAT_011ff5dc;

extern float DAT_011ff5e0;

extern float DAT_011ff5e4;

extern WaterVec3 DAT_011ff5e8, DAT_011ff558;

extern WaterVec4 DAT_011ff668[], DAT_011ff6e8[];

__forceinline void SetWaterAlpha(WaterMaterial* material, unsigned int mode)
{

    if (mode == 0x288 || mode == 0x289)
    {

        AddToSlot(material->alpha, 0);

        return;
    }

    if (!material->enabled)
        return;

    if (mode != 0x29a && mode != 0x2ab)
    {

        UpdateRendererStateCount(1, 0);

        FUN_00b98180(2, 255, material->alpha, 0);

        FUN_00b980c0(0, 0, 3, 0);

        AddToSlot(255, 0);

        return;
    }

    UpdateRendererStateCount(1, 0);

    FUN_00b98180(2, 255, material->alpha, 0);

    FUN_00b980c0(0, 0, 0, 0);

    AddToSlot(255, 0);
}

// Fills global water shader constants from the material, fog and lights, then calls Setup on the vertex and pixel WaterPrograms.
// @fnv 0x00b864d0
void WaterSetup::FUN_00b864d0(WaterRenderArg* arg)
{

    WaterSetup* volatile savedSetup = this;

    unsigned int mode = DAT_011f91e4;

    WaterGeometry* geometry = *DAT_011f91e0;

    void* world = &geometry->unk068;

    void* bound = geometry->bound;

    if (!bound)
        bound = &DAT_011f4288;

    void* properties = geometry->properties->data;

    void* geometryData = geometry->geometryData;

    transform->FUN_00e6fbb0(world, 0);

    WaterVec4 light = DAT_011fa2a0;

    WaterVec3 vDifference = WaterVec3(light.x, light.y, light.z) - DAT_011f474c;

    (*reinterpret_cast<WaterVec4*>(DAT_011ff588)) = WaterVec4(vDifference.x, vDifference.y, vDifference.z, 0);

    WaterMaterial* material = arg->material;

    DAT_011ff598 = material->color1;

    DAT_011ff5a8 = material->color2;

    DAT_011ff5b8 = material->color3;

    DAT_011ff5c8 = material->height;

    DAT_011ff5d0 = material->amount;

    const float refraction = material->refraction / DAT_01020758;

    DAT_011ff5d4 = refraction < DAT_01012070 ? 1.0f : refraction;

    DAT_011ff5d8 = material->scaleX;

    DAT_011ff5dc = material->scaleY;

    DAT_011ff5e0 = material->reflection;

    DAT_011ff5e4 = DAT_011ff108;

    WaterVec3 vCamera = DAT_011f474c;

    DAT_011ff558.x = DAT_011ff5e8.x = vCamera.x;

    DAT_011ff558.y = DAT_011ff5e8.y = vCamera.y;

    DAT_011ff558.z = DAT_011ff5e8.z = vCamera.z;

    (*reinterpret_cast<WaterVec4*>(DAT_011ff5f8)) = material->color4;

    WaterFog* fog = FUN_00b55520(DAT_011f91c4);

    if (fog)
    {

        float farDistance = fog->farDistance;

        float power = fog->power;

        WaterVec3 color = fog->color;

        (*reinterpret_cast<WaterVec4*>(DAT_011ff608)) =
            WaterVec4(farDistance, farDistance - fog->nearDistance, material->fogFactor, material->fogHeight);

        DAT_011ff618 = WaterVec4(color.x, color.y, color.z, material->fogAlpha);

        DAT_011ff5cc = power;
    }

    (*reinterpret_cast<WaterVec4*>(DAT_011ff628)) = material->color5;

    (*reinterpret_cast<WaterVec4*>(DAT_011ff638)) = DAT_011ff398;

    DAT_011ff648 = DAT_011ff3a8;

    float reflectivity = material->reflectivity;

    (*reinterpret_cast<WaterVec4*>(DAT_011ff548)).x = reflectivity;
    (*reinterpret_cast<WaterVec4*>(DAT_011ff548)).y = reflectivity;
    (*reinterpret_cast<WaterVec4*>(DAT_011ff548)).z = reflectivity;
    (*reinterpret_cast<WaterVec4*>(DAT_011ff548)).w = reflectivity;

    SetWaterAlpha(material, mode);

    float opacity = material->opacity;

    DAT_011ff568.x = opacity;
    DAT_011ff568.y = opacity;
    DAT_011ff568.z = opacity;
    DAT_011ff568.w = opacity;

    DAT_011ff658[0] = (float)material->lightCount;

    if (material->lights)
    {

        unsigned int index = 0;

        for (WaterLightNode* node = material->lights; node;)
        {

            WaterLight*& entry = node->light;

            node = node->next;

            WaterLight* pointLight = entry;

            if (pointLight)
            {

                WaterVec3 position = pointLight->position;

                reinterpret_cast<WaterVec4*>(DAT_011ff658 + 4)[index] =
                    WaterVec4(position.x, position.y, position.z, pointLight->radius);

                float strength = pointLight->intensity;

                WaterVec3 diffuse = pointLight->diffuse;

                diffuse *= strength;

                WaterVec3 vScaled = diffuse * material->lightScale;

                reinterpret_cast<WaterVec4*>(DAT_011ff658 + 36)[index] = WaterVec4(vScaled.x, vScaled.y, vScaled.z, 1);

                index++;
            }
        }
    }

    WaterSetup* setup = savedSetup;

    WaterProgram* vertex = setup->vertex;
    if (vertex)
    {
        void* shader = reinterpret_cast<WaterRenderContext*>(DAT_0126f74c)->vertexShader;
        if (shader)
            vertex->Setup(shader, geometry, geometryData, 0, properties, arg, 0, world, bound, 0, 1);
    }

    WaterProgram* pixel = setup->pixel;
    if (pixel)
    {
        void* shader = reinterpret_cast<WaterRenderContext*>(DAT_0126f74c)->pixelShader;
        if (shader)
            pixel->Setup(shader, geometry, geometryData, 0, properties, arg, 0, world, bound, 0, 1);
    }
}
