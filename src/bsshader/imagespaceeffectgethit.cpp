// bsshader/imagespaceeffectgethit.cpp: Standin (4 functions)

#include "imagespaceeffectgethit_types_ImageSpaceEffectGetHit.h"
#include "imagespaceeffectgethit_types_ImageSpaceShaderParam.h"
#include "MemoryManager.h"
#include "imagespaceeffectgethit_decls.h"
extern MemoryManager g_memoryManager;

// Updates two shader parameters from global constants using a computed angle, sets DAT_012003c4, and returns true.
// @fnv 0x00c03740
bool ImageSpaceEffectWithTwoTextures::UpdateParams(ImageSpaceEffectParam* param)
{
    ImageSpaceShaderParam* shader = reinterpret_cast<ImageSpaceShaderParam*>(pEffectParamList.m_pBase[3]);
    float angle = static_cast<float>(DAT_011f940c / DAT_01012640 * DAT_0104eea0);
    shader->SetShaderConstantVector4(0, 0.0f, 0.0f, DAT_0120240c * DAT_012023fc, DAT_0120240c);
    float cosine = static_cast<float>(cos(angle));
    float sine = static_cast<float>(sin(angle));
    shader->SetShaderConstantVector4(1, sine * DAT_01202400, cosine * DAT_01202400, 1.0f, 1.0f);
    DAT_012003c4 = DAT_010162c0;
    return true;
}

// @fnv 0x00c03810
ImageSpaceEffectWithTwoTextures::ImageSpaceEffectWithTwoTextures()
{
    pTextures.AddFirstEmpty(4);
}

struct Standin
{
    void FUN_00c03580();
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00c03580, then if bit 0 of flags is set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00c03890
void* Standin::ReleaseIfFlagged(unsigned int flags)
{
    FUN_00c03580();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern MemoryManager g_memoryManager;
struct ImageSpaceManagerX
{
    int unk00;
    NiTPrimitiveArray_ImageSpaceEffect___ kEffects;
    ImageSpaceEffect* GetEffect(unsigned int index)
    {
        return kEffects.m_pBase[index];
    }
};
struct ImageSpaceTextureArrayX
{
    void SetSize(unsigned int size);
};
struct ImageSpaceParamArrayX
{
    __declspec(noalias) void SetAt(unsigned int index, ImageSpaceEffectParam* const& element);
};
struct ImageSpaceShaderParamX : ImageSpaceShaderParam
{
    ImageSpaceShaderParamX();
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};
struct ImageSpaceEffectX : ImageSpaceEffect
{
    void SetEffectParamAt(int pass, int input, int output);
    void SetupEffect(ImageSpaceManagerX* manager, ImageSpaceEffectParam* param);
    ImageSpaceParamArrayX& Params()
    {
        return *(ImageSpaceParamArrayX*)&pEffectParamList;
    }
};
// Sets texture and parameter arrays, configures four effect slots, and creates shader constants for the fourth slot.
// @fnv 0x00c038b0
void ImageSpaceEffectX::SetupEffect(ImageSpaceManagerX* manager, ImageSpaceEffectParam* param)
{
    SetTextureArrayCount(4);
    ((ImageSpaceTextureArrayX*)&pTextures)->SetSize(4);
    Params().SetAt(0, 0);
    SetEffectParamAt(0, 1, 0);
    SetEffectAt(0, manager->GetEffect(34), 0, 2);
    Params().SetAt(1, 0);
    SetEffectAt(1, 2, 3, 0, 0);
    SetEffectAt(1, manager->GetEffect(17), 0, 2);
    Params().SetAt(2, 0);
    SetEffectAt(2, 2, 3, 0, 0);
    SetEffectAt(2, manager->GetEffect(17), 0, 2);
    ImageSpaceShaderParamX* shaderParam = new ImageSpaceShaderParamX;
    shaderParam->AllocateShaderConstants(0, 2);
    shaderParam->m_bTextureFlags[2] = false;
    Params().SetAt(3, shaderParam);
    SetEffectAt(3, 1, 2, 0, 0);
    SetEffectAt(3, manager->GetEffect(44), shaderParam, 0);
}
