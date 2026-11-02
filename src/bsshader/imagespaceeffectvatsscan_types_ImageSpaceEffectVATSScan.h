// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACEEFFECTVATSSCAN_H
#define FNV_IMAGESPACEEFFECTVATSSCAN_H

#include "layout_support.h"
#include "layout_support.h"
class ImageSpaceEffect;
class ImageSpaceEffect__EffectInput;
class ImageSpaceEffectParam;
class ImageSpaceManager;
class ImageSpaceEffectMultiTexture;
class ImageSpaceTexture;
class NiTPrimitiveArray_ImageSpaceEffect___;
class NiTPrimitiveArray_ImageSpaceEffect__EffectInput___;
class NiTPrimitiveArray_ImageSpaceEffectParam___;
class NiTPrimitiveArray_ImageSpaceTexture___;
class NiTPrimitiveArray_int_;
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
    void SetSize(unsigned int size);
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
    void** m_ppVirtualMethodTable;      // +0x0, 4 bytes
    bool bIsActive;       // +0x4, 1 bytes
    bool bParamsChanged;  // +0x5, 1 bytes
    unsigned char layoutPadding6[2];
    NiTPrimitiveArray_ImageSpaceEffect___ pEffectList;                 // +0x8, 16 bytes
    NiTPrimitiveArray_ImageSpaceEffectParam___ pEffectParamList;       // +0x18, 16 bytes
    NiTPrimitiveArray_ImageSpaceTexture___ pTextures;                  // +0x28, 16 bytes
    NiTPrimitiveArray_ImageSpaceEffect__EffectInput___ pEffectInputs;  // +0x38, 16 bytes
    NiTPrimitiveArray_int_ pEffectOutput;                              // +0x48, 16 bytes
    __declspec(noinline) ImageSpaceEffect();
    void SetTextureArrayCount(int count);
    void SetEffectAt(int index, ImageSpaceEffect* effect, ImageSpaceEffectParam* params, int flags);
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
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, bIsActive) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, bParamsChanged) == 5);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectList) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectParamList) == 24);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pTextures) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectInputs) == 56);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffect, pEffectOutput) == 72);
#pragma pack(push, 4)
class ImageSpaceEffectMultiTexture : public ImageSpaceEffect
{
  public:
    ImageSpaceEffectMultiTexture();
    void Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* params);
    void SetEntryRanges(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
    // base ImageSpaceEffect at +0x0, size 88
    // ImageSpaceEffectMultiTexture
    // void __cdecl ImageSpaceEffectMultiTexture::*()
    // void __cdecl ImageSpaceEffectMultiTexture::*(ImageSpaceManager*, ImageSpaceEffectParam*)
    // void __cdecl ImageSpaceEffectMultiTexture::*(ImageSpaceEffectParam*)
    // void __cdecl ImageSpaceEffectMultiTexture::*()
    // const char* __cdecl ImageSpaceEffectMultiTexture::*()
    // bool __cdecl ImageSpaceEffectMultiTexture::*(ImageSpaceEffectParam*)
    // ImageSpaceEffectMultiTexture& __cdecl ImageSpaceEffectMultiTexture::*(const ImageSpaceEffectMultiTexture&)
    // void __cdecl ImageSpaceEffectMultiTexture::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffectMultiTexture) == 88);
#endif
