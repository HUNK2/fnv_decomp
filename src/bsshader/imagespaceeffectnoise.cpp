// bsshader/imagespaceeffectnoise.cpp: free functions (2 functions)

#include "imagespaceeffectnoise_decls.h"

// @fnv 0x00c05180
void NoiseImageSpaceEffect::Setup(ImageSpaceManager* manager, ImageSpaceEffectParam*)
{
    SetTextureArrayCount(1);
    textures.SetSize(2);
    ImageSpaceShaderParam* shader = new ImageSpaceShaderParam;
    shader->AllocateShaderConstants(0, 4);
    params.SetAt(0, shader);
    SetEffectParamAt(0, 1, 0);
    SetEffectAt(0, manager->effects->noise, shader, 0);
}

class ImageSpaceEffectParam;
class NiTPrimitiveArray_ImageSpaceEffectParam___
{
  public:
    void SetAt(unsigned int, ImageSpaceEffectParam*&);
};

// Allocates an 8-byte parameter from two ints and stores it at uiIndex in the array at pThis+0x38.
// @fnv 0x00ba3b10
void __fastcall SetEffectParamAt(char* pThis, int, unsigned int uiIndex, int a2, int a3)
{
    int* p = (int*)g_memoryManager.Allocate(8);
    p[0] = a2;
    ImageSpaceEffectParam* param = (ImageSpaceEffectParam*)p;
    p[1] = a3;
    ((NiTPrimitiveArray_ImageSpaceEffectParam___*)(pThis + 0x38))->SetAt(uiIndex, param);
}
