// bsshader/imagespaceeffectrefraction_decls.h: declares RgbaColor, WaterTintRecord, ImageSpaceShaderParam, ImageSpaceTexture, ImageSpaceManager and more
#ifndef IMAGESPACEEFFECTREFRACTION_DECLS_H
#define IMAGESPACEEFFECTREFRACTION_DECLS_H

#include "layout_support.h"
#include "MemoryManager.h"

class ImageSpaceEffect;
class ImageSpaceEffectParam;
class ImageSpaceManager;
class ImageSpaceTexture;
class NiTexture;
class BSRenderedTexture;
class NiRenderer;
extern MemoryManager g_memoryManager;

template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, const T& value);
};

class RgbaColor
{
  public:
    float r, g, b, a;
};
struct WaterTintRecord
{
    float r, g, b, a;
};
extern WaterTintRecord g_waterTintRecords[];

class ImageSpaceEffectParam
{
  public:
    void** m_ppVirtualMethodTable;
    NiTPrimitiveArray<int> m_kTextureTypes;
    NiTPrimitiveArray<int> m_kFilterModes;
};

class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    int m_eShaderFilterMode;
    unsigned int m_eClearFlags;
    RgbaColor m_eTextureClampMode;
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    void* m_pVertexShaderConstantMap;
    void* m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    NiTObjectArray<void*> m_kShaderTextures;
    NiTPrimitiveArray<int> m_kTextureFilterModes;
    void* m_kRenderStateMap[4];

    ImageSpaceShaderParam();
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* memory)
    {
        g_memoryManager.Deallocate(memory);
    }
};

class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;
    bool bIsActive;
    bool bParamsChanged;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<ImageSpaceEffectParam*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    NiTPrimitiveArray<void*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;

    ImageSpaceEffect();
    void SetTextureArrayCount(int count);
    void SetTextureArrayAt(int index, int first, int second, int firstFilter, int secondFilter);
    void SetEffectAt(int index, ImageSpaceEffect* effect, ImageSpaceEffectParam* param, int output);
};

class ImageSpaceTexture
{
  public:
    bool m_bTextureFlag1;
    bool m_bTextureFlag2;
    bool m_bTextureFlag3;
    void* pTexture;
    int m_eTextureFilterMode;
    int m_eClampMode;
    NiTexture* GetTexture();
    BSRenderedTexture* FUN_00ba3770();
    void FUN_00ba37a0(BSRenderedTexture* texture);
};

class RefractionImageSpaceEffect : public ImageSpaceEffect
{
  public:
    RefractionImageSpaceEffect();
    ImageSpaceTexture m_kRefractionTexture;
    void Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param);
    BSRenderedTexture* GetRefractionTexture(bool create);
};

class ImageSpaceManager
{
  public:
    BSRenderedTexture* m_pCurrentRenderedTexture;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
};

class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};

class BSTextureManager
{
  public:
    BSRenderedTexture* CreateRenderTargetTexture(NiRenderer* renderer, int type, unsigned int flags,
                                                 BSRenderedTexture* alias, unsigned int aliasOffset);
};
extern BSTextureManager* DAT_011f91a8;
extern int DAT_011bf400;
extern void* DAT_010bc560[];

FNV_STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 0x88);
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffect) == 0x58);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectParamList) == 0x18);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pTextures) == 0x28);
FNV_STATIC_ASSERT(offsetof(RefractionImageSpaceEffect, m_kRefractionTexture) == 0x58);
#endif
