//
// NiD3DPass: the Nivid3D render pass object.
//
// The NiD3DPass and D3DRenderStateGroup layouts below are copied verbatim
// generated header), together with their layout asserts.
#ifndef NID3DPASS_H
#define NID3DPASS_H


#include "layout_support.h"

class NiD3DPixelShader;
class NiD3DShaderConstantMap;
class BeamStage;
class NiD3DVertexShader;
class NiD3DRenderStateGroup__NiD3DRSEntry;

#pragma pack(push, 4)

// A group of D3D render states owned either by a pass or by the renderer pool.
class D3DRenderStateGroup
{
  public:
    bool m_bHasBeenApplied;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    unsigned int m_uiRenderStateEntryCount;                       // +0x4, 4 bytes
    NiD3DRenderStateGroup__NiD3DRSEntry* m_pkRenderStateEntries;  // +0x8, 4 bytes
    unsigned int m_uiFreeEntryCount;                              // +0xC, 4 bytes
    NiD3DRenderStateGroup__NiD3DRSEntry* m_pkFreeEntries;         // +0x10, 4 bytes

    // Hands out a group owned by the renderer, marking it renderer owned.
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();

    // Records (state, value) and applies it when enabled.
    void SetRenderState(unsigned int state, unsigned int value, bool enable);
};

// One draw call of the Nivid3D renderer: its texture stages plus the render
// states and shaders that select the pipeline state for those stages.
class NiD3DPass
{
  public:
    void** m_ppVirtualMethodTable;                                                // +0x0, 4 bytes
    char m_szName[16];                                              // +0x4, 16 bytes
    unsigned int m_uiStageMask;                                     // +0x14, 4 bytes
    unsigned int m_uiNumberOfStages;                                // +0x18, 4 bytes
    unsigned int m_uiStageOffset;                                   // +0x1C, 4 bytes
    NiTObjectArray<NiPointer<BeamStage> > m_kStageArray;            // +0x20, 16 bytes
    D3DRenderStateGroup* m_pRenderStateGroup;                       // +0x30, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;   // +0x34, 4 bytes
    char* m_pcPixelShaderFile;                                      // +0x38, 4 bytes
    char* m_pcPixelShaderFunction;                                  // +0x3C, 4 bytes
    char* m_pcPixelShaderProfile;                                   // +0x40, 4 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderObject;              // +0x44, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;  // +0x48, 4 bytes
    char m_bUsesSecondShaderConstantMap;                            // +0x4C, 1 bytes
    unsigned char layoutPadding4D[3];
    char* m_pcVertexShaderFile;                           // +0x50, 4 bytes
    char* m_pcVertexShaderFunction;                       // +0x54, 4 bytes
    char* m_pcVertexShaderProfile;                        // +0x58, 4 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShaderObject;  // +0x5C, 4 bytes
    bool m_bIsInitialized;                                // +0x60, 1 bytes
    bool m_bHasBeenApplied;                               // +0x61, 1 bytes
    unsigned char layoutPadding62[2];
    unsigned int m_uiRefCount;  // +0x64, 4 bytes

    // Points the pass at a render state group and drives the source and
    // destination blend states from it.
    void SetAlphaBlendMode(unsigned int uiSrcBlend, unsigned int uiDestBlend, bool bSrcAlpha);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(D3DRenderStateGroup) == 20);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_bHasBeenApplied) == 0);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_uiRenderStateEntryCount) == 4);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_pkRenderStateEntries) == 8);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_uiFreeEntryCount) == 12);
FNV_STATIC_ASSERT(offsetof(D3DRenderStateGroup, m_pkFreeEntries) == 16);
// @fnv 0x00b80040
void NiD3DPass::SetAlphaBlendMode(unsigned int uiSrcBlend, unsigned int uiDestBlend, bool bSrcAlpha)
{
    if (!m_pRenderStateGroup)
        m_pRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pRenderStateGroup->SetRenderState(0x13, uiSrcBlend, true);
    if (!m_pRenderStateGroup)
        m_pRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    m_pRenderStateGroup->SetRenderState(0x14, uiDestBlend, true);
}
FNV_STATIC_ASSERT(sizeof(NiD3DPass) == 104);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_szName) == 4);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiStageMask) == 20);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiNumberOfStages) == 24);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiStageOffset) == 28);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_kStageArray) == 32);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pRenderStateGroup) == 48);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spFirstShaderConstantMap) == 52);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pcPixelShaderFile) == 56);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pcPixelShaderFunction) == 60);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pcPixelShaderProfile) == 64);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spPixelShaderObject) == 68);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spSecondShaderConstantMap) == 72);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_bUsesSecondShaderConstantMap) == 76);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pcVertexShaderFile) == 80);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pcVertexShaderFunction) == 84);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pcVertexShaderProfile) == 88);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spVertexShaderObject) == 92);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_bIsInitialized) == 96);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_bHasBeenApplied) == 97);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiRefCount) == 100);

#endif