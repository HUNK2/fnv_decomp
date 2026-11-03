
// src/fallout_shared/speedtree/bstreemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/speedtree/bstreemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bstreemanager_decls.h"
void* FUN_00664840(bool create);
void SetGlobalFloatFromUInt(unsigned int value);
void ClampAndStoreValue(float value);
struct NP
{
    NP& operator=(void*);
};
extern NP DAT_011f95e4;
void SetGlobalValue(unsigned int value);
struct FUN_006652c0_shell
{
    void SetByteAtOffset44(unsigned char value);
};
struct Setting_S
{
    float* Float(void);
    float f;
};
struct originalRuntimeFloatSetting1295_t
{
    Setting_S* Float(void);
};
extern originalRuntimeFloatSetting1295_t originalRuntimeFloatSetting1295;
float FUN_006655a0();
extern unsigned char __cdecl GetFirstProcessListByte(void);
extern unsigned char* __cdecl _FUN_00664840(bool);
unsigned char BSTreeManager_AreTreesVisible(bool abCreateIfNotFound);

struct NiRenderTargetGroup;

struct NiRenderer
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual NiRenderTargetGroup* GetCurrentRenderTargetGroup();
    static NiRenderer* ms_pRenderer;
    void TryUnlock();
};

struct GraphicsRenderer : public NiRenderer
{
    bool BeginUsingRenderTargetGroup(NiRenderTargetGroup* pkTarget, unsigned int uiClone);
};

void __cdecl PushRefCountedSlot(NiRenderTargetGroup* pkTarget);

// @fnv 0x00b6b7d0
void FUN_00b6b7d0(NiRenderTargetGroup* pkTarget, unsigned int uiClone)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkTarget == 0)
    {
        pkTarget = pkRenderer->GetCurrentRenderTargetGroup();
    }
    if (*(bool*)((char*)pkRenderer + 0x208))
    {
        pkRenderer->TryUnlock();
    }
    NiRenderTargetGroup* pkTarget2 = pkTarget;
    if (pkTarget2 == 0)
    {
        pkTarget2 = NiRenderer::ms_pRenderer->GetCurrentRenderTargetGroup();
    }
    ((GraphicsRenderer*)NiRenderer::ms_pRenderer)->BeginUsingRenderTargetGroup(pkTarget2, uiClone);
    PushRefCountedSlot(pkTarget);
}
