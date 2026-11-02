// bsshader/imagespaceeffecthdr_decls.h: declares MemoryManager, ImageSpaceShaderParam, ImageSpaceManager, NiRenderTargetGroup, NiRenderer
#ifndef IMAGESPACEEFFECTHDR_DECLS_H
#define IMAGESPACEEFFECTHDR_DECLS_H

#include <stddef.h>
void operator delete(void*);
class ImageSpaceEffect;
class ImageSpaceEffectParam;
class ImageSpaceManager;
class ImageSpaceTexture;
class MemoryManager
{
  public:
    void* Allocate(unsigned int size);
};
extern MemoryManager g_memoryManager;
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int);
    // SetAt consumes the reference without retaining its address.
    __declspec(noalias) void SetAt(unsigned int, const T&);
};
class ImageSpaceEffectParam
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned char textureArrays[32];
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    int m_eShaderFilterMode;
    int m_eClearFlags;
    float m_eTextureClampMode[4];
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    void* m_pVertexShaderConstantMap;
    void* m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    unsigned char layoutPadding57;
    unsigned char inputArraysAndStates[48];
    ImageSpaceShaderParam();
    static void* operator new(size_t size)
    {
        return g_memoryManager.Allocate(size);
    }
    void AllocateShaderConstants(int, int);
    void FUN_00b8a7c0();
    void CopyParamData(int, const float*, unsigned int);
};
class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;
    bool bIsActive, bParamsChanged;
    unsigned char layoutPadding6[2];
    NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> > pEffectList;
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > pEffectParamList;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > pTextures;
    unsigned char remainingArrays[32];
    void SetTextureArrayCount(int);
    void SetEffectAt(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int);
};
class HDRImageSpaceEffect : public ImageSpaceEffect
{
  public:
    float m_afHDRParameters[4];
    bool m_bUseLowResolutionPath;
    unsigned char layoutPadding69[3];
    float* pVector4;
    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
};
class ImageSpaceManager
{
  public:
    ImageSpaceEffect* GetEffect(int index)
    {
        return pEffectList.m_pBase[index];
    }
    void** m_ppVirtualMethodTable;
    NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> > pEffectList;
};
class NiRenderTargetGroup
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual unsigned int Unk_23(unsigned int);
};
class NiRenderer
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual NiRenderTargetGroup* vfn_c8();
    static NiRenderer* ms_pRenderer;
    char _pdbpad_4[4];
    char m_acRendererDataA[4];
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
extern bool DAT_011f941f;
extern bool DAT_011f9420;
extern const float DAT_011add48[];
extern const float DAT_011add88[];
extern const float DAT_011ade88[];
typedef char shader_param_size[(sizeof(ImageSpaceShaderParam) == 0x88) ? 1 : -1];
typedef char hdr_aniso_offset[(offsetof(HDRImageSpaceEffect, m_bUseLowResolutionPath) == 0x68) ? 1 : -1];
#endif
