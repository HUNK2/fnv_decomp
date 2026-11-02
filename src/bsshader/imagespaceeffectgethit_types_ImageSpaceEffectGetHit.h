// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACEEFFECTGETHIT_H
#define FNV_IMAGESPACEEFFECTGETHIT_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class ImageSpaceEffect;
class ImageSpaceEffect__EffectInput;
class ImageSpaceEffectWithTwoTextures;
class ImageSpaceManager;
class ImageSpaceEffectParam;
class ImageSpaceTexture;
class NiTPrimitiveArray_ImageSpaceEffect___;
class NiTPrimitiveArray_ImageSpaceEffect__EffectInput___;
class NiTPrimitiveArray_ImageSpaceEffectParam___;
class NiTPrimitiveArray_ImageSpaceTexture___;
class NiTPrimitiveArray_int_;
#ifndef FNV_IMAGESPACEEFFECTGETHIT_FILTERMODE_DEFINED
#define FNV_IMAGESPACEEFFECTGETHIT_FILTERMODE_DEFINED
enum NiTexturingProperty__FilterMode
{
    NiTexturingProperty__FilterMode_FILTER_NEAREST = 0,
    NiTexturingProperty__FilterMode_FILTER_BILERP = 1,
    NiTexturingProperty__FilterMode_FILTER_TRILERP = 2,
    NiTexturingProperty__FilterMode_FILTER_NEAREST_MIPNEAREST = 3,
    NiTexturingProperty__FilterMode_FILTER_NEAREST_MIPLERP = 4,
    NiTexturingProperty__FilterMode_FILTER_BILERP_MIPNEAREST = 5,
    NiTexturingProperty__FilterMode_FILTER_ANISO = 6,
    NiTexturingProperty__FilterMode_FILTER_MAGLERP_MINANISO = 7,
    NiTexturingProperty__FilterMode_FILTER_MAX_MODES = 8
};
#endif
enum NiTexturingProperty__ClampMode
{
    NiTexturingProperty__ClampMode_CLAMP_S_CLAMP_T = 0,
    NiTexturingProperty__ClampMode_CLAMP_S_WRAP_T = 1,
    NiTexturingProperty__ClampMode_WRAP_S_CLAMP_T = 2,
    NiTexturingProperty__ClampMode_WRAP_S_WRAP_T = 3,
    NiTexturingProperty__ClampMode_CLAMP_MAX_MODES = 4
};
#pragma pack(push, 4)
class NiTPrimitiveArray_ImageSpaceEffect___ : public NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> >
{
  public:
    // base NiTArray<ImageSpaceEffect *,NiTMallocInterface<ImageSpaceEffect *> > at +0x0, size 16
    // NiTPrimitiveArray<ImageSpaceEffect *>
    // void __cdecl NiTPrimitiveArray<ImageSpaceEffect *>::*()
    // NiTPrimitiveArray<ImageSpaceEffect *>& __cdecl NiTPrimitiveArray<ImageSpaceEffect *>::*(const NiTPrimitiveArray<ImageSpaceEffect *>&)
    // void __cdecl NiTPrimitiveArray<ImageSpaceEffect *>::*()
    // void __cdecl NiTPrimitiveArray<ImageSpaceEffect *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceEffect___) == 16);
#pragma pack(push, 4)
class NiTPrimitiveArray_ImageSpaceEffectParam___
    : public NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >
{
  public:
    void SetAt(unsigned int, ImageSpaceEffectParam*&);

    // base NiTArray<ImageSpaceEffectParam *,NiTMallocInterface<ImageSpaceEffectParam *> > at +0x0, size 16
    // NiTPrimitiveArray<ImageSpaceEffectParam *>
    // void __cdecl NiTPrimitiveArray<ImageSpaceEffectParam *>::*()
    // NiTPrimitiveArray<ImageSpaceEffectParam *>& __cdecl NiTPrimitiveArray<ImageSpaceEffectParam *>::*(const NiTPrimitiveArray<ImageSpaceEffectParam *>&)
    // void __cdecl NiTPrimitiveArray<ImageSpaceEffectParam *>::*()
    // void __cdecl NiTPrimitiveArray<ImageSpaceEffectParam *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceEffectParam___) == 16);
#pragma pack(push, 4)
class NiTPrimitiveArray_ImageSpaceTexture___
    : public NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> >
{
  public:
    unsigned int AddFirstEmpty(unsigned int);

    // base NiTArray<ImageSpaceTexture *,NiTMallocInterface<ImageSpaceTexture *> > at +0x0, size 16
    // NiTPrimitiveArray<ImageSpaceTexture *>
    // void __cdecl NiTPrimitiveArray<ImageSpaceTexture *>::*()
    // NiTPrimitiveArray<ImageSpaceTexture *>& __cdecl NiTPrimitiveArray<ImageSpaceTexture *>::*(const NiTPrimitiveArray<ImageSpaceTexture *>&)
    // void __cdecl NiTPrimitiveArray<ImageSpaceTexture *>::*()
    // void __cdecl NiTPrimitiveArray<ImageSpaceTexture *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceTexture___) == 16);
#pragma pack(push, 4)
class NiTPrimitiveArray_ImageSpaceEffect__EffectInput___
    : public NiTArray<ImageSpaceEffect__EffectInput*, NiTMallocInterface<ImageSpaceEffect__EffectInput*> >
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_ImageSpaceEffect__EffectInput___) == 16);
#pragma pack(push, 4)
class NiTPrimitiveArray_int_ : public NiTArray<int, NiTMallocInterface<int> >
{
  public:
    // base NiTArray<int,NiTMallocInterface<int> > at +0x0, size 16
    // NiTPrimitiveArray<int>
    // void __cdecl NiTPrimitiveArray<int>::*()
    // NiTPrimitiveArray<int>& __cdecl NiTPrimitiveArray<int>::*(const NiTPrimitiveArray<int>&)
    // void __cdecl NiTPrimitiveArray<int>::*()
    // void __cdecl NiTPrimitiveArray<int>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_int_) == 16);
#pragma pack(push, 4)
class ImageSpaceEffect
{
  public:
    ImageSpaceEffect();
    virtual ~ImageSpaceEffect();
    void SetTextureArrayCount(int);
    void SetEffectAt(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int);
    void SetEffectAt(int, int, int, int, int);

    bool bIsActive;       // +0x4, 1 bytes
    bool bParamsChanged;  // +0x5, 1 bytes
    unsigned char layoutPadding6[2];
    NiTPrimitiveArray_ImageSpaceEffect___ pEffectList;                 // +0x8, 16 bytes
    NiTPrimitiveArray_ImageSpaceEffectParam___ pEffectParamList;       // +0x18, 16 bytes
    NiTPrimitiveArray_ImageSpaceTexture___ pTextures;                  // +0x28, 16 bytes
    NiTPrimitiveArray_ImageSpaceEffect__EffectInput___ pEffectInputs;  // +0x38, 16 bytes
    NiTPrimitiveArray_int_ pEffectOutput;                              // +0x48, 16 bytes
    // ImageSpaceEffect
    // void __cdecl ImageSpaceEffect::*(bool)
    // ImageSpaceTexture* __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int)
    // void __cdecl ImageSpaceEffect::*(int, ImageSpaceEffect*, ImageSpaceEffectParam*, int)
    // void __cdecl ImageSpaceEffect::*(int, ImageSpaceTexture*, NiTexturingProperty::FilterMode)
    // ImageSpaceEffect& __cdecl ImageSpaceEffect::*(const ImageSpaceEffect&)
    // void __cdecl ImageSpaceEffect::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffect) == 88);

FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, bIsActive) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, bParamsChanged) == 5);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectList) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectParamList) == 24);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pTextures) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectInputs) == 56);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectOutput) == 72);
#pragma pack(push, 4)
class ImageSpaceTexture
{
  public:
    ImageSpaceTexture();
    ~ImageSpaceTexture();
    bool m_bTextureFlag1;  // +0x0, 1 bytes
    bool m_bTextureFlag2;  // +0x1, 1 bytes
    bool m_bTextureFlag3;  // +0x2, 1 bytes
    unsigned char layoutPadding3[1];
    NiPointer<NiObject> pTexture;                          // +0x4, 4 bytes
    NiTexturingProperty__FilterMode m_eTextureFilterMode;  // +0x8, 4 bytes
    NiTexturingProperty__ClampMode m_eClampMode;           // +0xC, 4 bytes
    // ImageSpaceTexture
    // void __cdecl ImageSpaceTexture::*()
    // BSRenderedTexture* __cdecl ImageSpaceTexture::*()
    // NiTexture* __cdecl ImageSpaceTexture::*()
    // SetTexture
    // void __cdecl ImageSpaceTexture::*(bool)
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::FilterMode)
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::ClampMode)
    // ImageSpaceTexture& __cdecl ImageSpaceTexture::*(ImageSpaceTexture&)
    // void* __cdecl ImageSpaceTexture::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceTexture) == 16);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag1) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag2) == 1);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag3) == 2);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, pTexture) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_eTextureFilterMode) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_eClampMode) == 12);
#pragma pack(push, 4)
class ImageSpaceEffectWithTwoTextures : public ImageSpaceEffect
{
  public:
    ImageSpaceEffectWithTwoTextures();
    void SetEffectParamAt(int, int, int);

    void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
    bool UpdateParams(ImageSpaceEffectParam*);
    // base ImageSpaceEffect at +0x0, size 88
    float* pVector4;                         // +0x58, 4 bytes
    ImageSpaceTexture m_kEffectTextures[2];  // +0x5C, 32 bytes
    // ImageSpaceEffectWithTwoTextures
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
    // void __cdecl ImageSpaceEffectWithTwoTextures::*(ImageSpaceManager*, ImageSpaceEffectParam*)
    // void __cdecl ImageSpaceEffectWithTwoTextures::*(ImageSpaceEffectParam*)
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
    // bool __cdecl ImageSpaceEffectWithTwoTextures::*()
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
    // bool __cdecl ImageSpaceEffectWithTwoTextures::*(ImageSpaceEffectParam*)
    // const char* __cdecl ImageSpaceEffectWithTwoTextures::*()
    // ImageSpaceEffectWithTwoTextures& __cdecl ImageSpaceEffectWithTwoTextures::*(ImageSpaceEffectWithTwoTextures&)
    // void __cdecl ImageSpaceEffectWithTwoTextures::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffectWithTwoTextures) == 124);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffectWithTwoTextures, pVector4) == 88);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffectWithTwoTextures, m_kEffectTextures) == 92);
#endif
