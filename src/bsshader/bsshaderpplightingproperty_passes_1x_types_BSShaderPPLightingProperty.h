// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERPPLIGHTINGPROPERTY_H
#define FNV_BSSHADERPPLIGHTINGPROPERTY_H

#include "layout_support.h"
#include "NiProperty.h"
#include "layout_support.h"
class BSShaderLightingProperty;
class BSShaderPPLightingProperty;
class NiGeometry;
class ShadowSceneLight;
class BSShaderPPLightingProperty__TangentSpaceData;
class BSShaderPPLightingProperty__TextureEffectData;
class BSShaderProperty;
class BSShaderProperty__RenderPass;
class BSShaderProperty__RenderPassArray;
class BSTextureSet;
class RgbaColor;
class NiShadeProperty;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___;
class NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight_____AntiBloatAllocator;
class NiTListItem_ShadowSceneLight___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___;
class NiTPointerListSingleThread_ShadowSceneLight___;
class NiTexture;
enum NiTexturingProperty__ClampMode
{
    NiTexturingProperty__ClampMode_CLAMP_S_CLAMP_T = 0,
    NiTexturingProperty__ClampMode_CLAMP_S_WRAP_T = 1,
    NiTexturingProperty__ClampMode_WRAP_S_CLAMP_T = 2,
    NiTexturingProperty__ClampMode_WRAP_S_WRAP_T = 3,
    NiTexturingProperty__ClampMode_CLAMP_MAX_MODES = 4
};
#pragma pack(push, 4)
class NiShadeProperty : public NiProperty
{
  public:
    // base NiProperty at +0x0, size 24
    unsigned short m_uiObjectFlags;  // +0x18, 2 bytes
    unsigned char layoutPadding1A[2];
    int m_iShaderType;  // +0x1C, 4 bytes
    // const NiRTTI* __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*(NiStream&)
    // void __cdecl NiShadeProperty::*(NiStream&)
    // bool __cdecl NiShadeProperty::*(NiStream&)
    // void __cdecl NiShadeProperty::*(NiStream&)
    // bool __cdecl NiShadeProperty::*(NiObject*)
    // NiObject* __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiShadeProperty::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiShadeProperty::*(unsigned short, unsigned short)
    // void __cdecl NiShadeProperty::*(bool, unsigned short)
    // bool __cdecl NiShadeProperty::*(unsigned short)
    // NiShadeProperty
    // void __cdecl NiShadeProperty::*(bool)
    // bool __cdecl NiShadeProperty::*()
    // bool __cdecl NiShadeProperty::*(const NiShadeProperty&)
    // int __cdecl NiShadeProperty::*()
    // int __cdecl NiShadeProperty::*()
    // NiShadeProperty* __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*()
    // int __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*()
    // NiShadeProperty& __cdecl NiShadeProperty::*(const NiShadeProperty&)
    // void __cdecl NiShadeProperty::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiShadeProperty) == 32);
FNV_STATIC_ASSERT(offsetof(NiShadeProperty, m_uiObjectFlags) == 24);
FNV_STATIC_ASSERT(offsetof(NiShadeProperty, m_iShaderType) == 28);
#pragma pack(push, 4)
class BSShaderProperty : public NiShadeProperty
{
  public:
    // base NiShadeProperty at +0x0, size 32
    unsigned long ulFlags[2];                                // +0x20, 8 bytes
    float fAlpha;                                            // +0x28, 4 bytes
    float fFadeAlpha;                                        // +0x2C, 4 bytes
    float m_fAmbientReflectionScale;                         // +0x30, 4 bytes
    float m_fSpecularExponent;                               // +0x34, 4 bytes
    int iLastRenderPassState;                                // +0x38, 4 bytes
    BSShaderProperty__RenderPassArray* pRenderPassList;      // +0x3C, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray1;  // +0x40, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray2;  // +0x44, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray3;  // +0x48, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray4;  // +0x4C, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray5;  // +0x50, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray6;  // +0x54, 4 bytes
    int m_iRenderPassCount;                                  // +0x58, 4 bytes
    float fDepthBias;                                        // +0x5C, 4 bytes
    float m_fValueAfterDepthBias;                            // +0x60, 4 bytes
    float m_fEnvironmentMapScale;                            // +0x64, 4 bytes
    // const NiRTTI* __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl BSShaderProperty::*(NiStream&)
    // void __cdecl BSShaderProperty::*(NiStream&)
    // bool __cdecl BSShaderProperty::*(NiStream&)
    // void __cdecl BSShaderProperty::*(NiStream&)
    // bool __cdecl BSShaderProperty::*(NiObject*)
    // NiObject* __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(NiStream&)
    // BSShaderProperty
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // bool __cdecl BSShaderProperty::*(BSShaderProperty*)
    // bool __cdecl BSShaderProperty::*(unsigned int)
    // void __cdecl BSShaderProperty::*(unsigned int, bool)
    // void __cdecl BSShaderProperty::*(float)
    // float __cdecl BSShaderProperty::*()
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(float)
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(unsigned int)
    // unsigned int __cdecl BSShaderProperty::*()
    // int __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(int)
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(float)
    // void __cdecl BSShaderProperty::*(NiAVObject*)
    // void __cdecl BSShaderProperty::*(NiAVObject*, bool)
    // void __cdecl BSShaderProperty::*(NiAVObject*, BSShaderProperty::EShaderPropertyFlag, bool)
    // bool __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(bool)
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(float)
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(unsigned int&)
    // void __cdecl BSShaderProperty::*(bool)
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*()
    // BSShaderProperty& __cdecl BSShaderProperty::*(const BSShaderProperty&)
    // void __cdecl BSShaderProperty::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderProperty) == 104);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, ulFlags) == 32);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, fAlpha) == 40);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, fFadeAlpha) == 44);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fAmbientReflectionScale) == 48);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fSpecularExponent) == 52);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, iLastRenderPassState) == 56);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, pRenderPassList) == 60);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray1) == 64);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray2) == 68);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray3) == 72);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray4) == 76);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray5) == 80);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray6) == 84);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_iRenderPassCount) == 88);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, fDepthBias) == 92);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fValueAfterDepthBias) == 96);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fEnvironmentMapScale) == 100);
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___
{
  public:
    NiTListItem_ShadowSceneLight___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_ShadowSceneLight___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(NiTListItem<ShadowSceneLight *>*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(NiTListItem<ShadowSceneLight *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*, NiTListItem<ShadowSceneLight *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*, NiTListItem<ShadowSceneLight *>*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(const NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *> at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(ShadowSceneLight*&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(ShadowSceneLight*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*, ShadowSceneLight*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*, ShadowSceneLight*&)
    // ShadowSceneLight*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // ShadowSceneLight*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // ShadowSceneLight*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*)
    // ShadowSceneLight*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*&)
    // ShadowSceneLight*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*&)
    // ShadowSceneLight* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // ShadowSceneLight* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // ShadowSceneLight* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(ShadowSceneLight*&)
    // ShadowSceneLight* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(ShadowSceneLight*&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(int __cdecl (void*, void*)*)
    // NiTListItem<ShadowSceneLight *>* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(NiTListItem<ShadowSceneLight *>*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *>::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___) == 12);
#pragma pack(push, 4)
class NiTPointerListSingleThread_ShadowSceneLight___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__ShadowSceneLight___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,ShadowSceneLight *> at +0x0, size 12
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListSingleThread_ShadowSceneLight___) == 12);
#pragma pack(push, 4)
class BSShaderLightingProperty : public BSShaderProperty
{
  public:
    // base BSShaderProperty at +0x0, size 104
    NiTPointerListSingleThread_ShadowSceneLight___ m_kShadowSceneLights;  // +0x68, 12 bytes
    float m_fForcedDarkness;                                              // +0x74, 4 bytes
    unsigned int m_uiLightCount;                                          // +0x78, 4 bytes
    bool m_bHasForcedDarkness;                                            // +0x7C, 1 bytes
    unsigned char layoutPadding7D[3];
    void* m_pLightData;  // +0x80, 4 bytes
    // const NiRTTI* __cdecl BSShaderLightingProperty::*()
    // void __cdecl BSShaderLightingProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl BSShaderLightingProperty::*(NiStream&)
    // void __cdecl BSShaderLightingProperty::*(NiStream&)
    // bool __cdecl BSShaderLightingProperty::*(NiStream&)
    // void __cdecl BSShaderLightingProperty::*(NiStream&)
    // bool __cdecl BSShaderLightingProperty::*(NiObject*)
    // NiObject* __cdecl BSShaderLightingProperty::*()
    // BSShaderLightingProperty
    // void __cdecl BSShaderLightingProperty::*()
    // bool __cdecl BSShaderLightingProperty::*(ShadowSceneLight*, NiBound*, void*&)
    // void __cdecl BSShaderLightingProperty::*(NiBound*)
    // bool __cdecl BSShaderLightingProperty::*(NiBound*)
    // ShadowSceneLight* __cdecl BSShaderLightingProperty::*(void*&)
    // ShadowSceneLight* __cdecl BSShaderLightingProperty::*(void*&)
    // ShadowSceneLight* __cdecl BSShaderLightingProperty::*(void*&)
    // ShadowSceneLight* __cdecl BSShaderLightingProperty::*(void*&)
    // ShadowSceneLight* __cdecl BSShaderLightingProperty::*(void*&)
    // ShadowSceneLight* __cdecl BSShaderLightingProperty::*(void*&)
    // void __cdecl BSShaderLightingProperty::*(ShadowSceneLight*, NiBound*)
    // void __cdecl BSShaderLightingProperty::*(ShadowSceneLight*)
    // unsigned short __cdecl BSShaderLightingProperty::*()
    // unsigned short __cdecl BSShaderLightingProperty::*()
    // unsigned short __cdecl BSShaderLightingProperty::*()
    // void __cdecl BSShaderLightingProperty::*(int, RgbaColor)
    // void __cdecl BSShaderLightingProperty::*(unsigned int, ShadowSceneLight*, float)
    // void __cdecl BSShaderLightingProperty::*(unsigned int, ShadowSceneLight*, float)
    // void __cdecl BSShaderLightingProperty::*(unsigned int, ShadowSceneLight*, float)
    // void __cdecl BSShaderLightingProperty::*(unsigned int, ShadowSceneLight*, float)
    // void __cdecl BSShaderLightingProperty::*(int)
    // void __cdecl BSShaderLightingProperty::*(float)
    // float __cdecl BSShaderLightingProperty::*()
    // void __cdecl BSShaderLightingProperty::*(unsigned int)
    // unsigned int __cdecl BSShaderLightingProperty::*()
    // void __cdecl BSShaderLightingProperty::*()
    // void __cdecl BSShaderLightingProperty::*(NiTriBasedGeom*)
    // void __cdecl BSShaderLightingProperty::*(bool)
    // BSShaderLightingProperty& __cdecl BSShaderLightingProperty::*(const BSShaderLightingProperty&)
    // void __cdecl BSShaderLightingProperty::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderLightingProperty) == 132);
FNV_STATIC_ASSERT(offsetof(BSShaderLightingProperty, m_kShadowSceneLights) == 104);
FNV_STATIC_ASSERT(offsetof(BSShaderLightingProperty, m_fForcedDarkness) == 116);
FNV_STATIC_ASSERT(offsetof(BSShaderLightingProperty, m_uiLightCount) == 120);
FNV_STATIC_ASSERT(offsetof(BSShaderLightingProperty, m_bHasForcedDarkness) == 124);
FNV_STATIC_ASSERT(offsetof(BSShaderLightingProperty, m_pLightData) == 128);
#pragma pack(push, 4)
class RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
    // void __cdecl RgbaColor::*(float, float, float, float)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor __cdecl RgbaColor::*(const RgbaColor&)
    // operator-
    // operator*
    // operator/
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // operator*=
    // operator/=
    // void __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl RgbaColor::*(const char*)
    // float __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
#pragma pack(push, 4)
class BSShaderPPLightingProperty : public BSShaderLightingProperty
{
  public:
    // base BSShaderLightingProperty at +0x0, size 132
    float m_fEmissiveMultiple;               // +0x84, 4 bytes
    float m_fSpecularScale;                  // +0x88, 4 bytes
    RgbaColor m_kEmissiveColor;              // +0x8C, 16 bytes
    RgbaColor m_kSpecularColor;              // +0x9C, 16 bytes
    NiPointer<BSTextureSet> m_spTextureSet;  // +0xAC, 4 bytes
    unsigned short m_usTextureFlags;         // +0xB0, 2 bytes
    unsigned char layoutPaddingB2[2];
    NiPointer<NiTexture>* m_ppTextureSlots[7];  // +0xB4, 28 bytes
    unsigned char* m_pTextureFlags;             // +0xD0, 4 bytes
    unsigned short m_usTextureIndex;            // +0xD4, 2 bytes
    unsigned char layoutPaddingD6[2];
    bool* m_pbTextureHasAlpha;                                                     // +0xD8, 4 bytes
    NiPointer<BSShaderPPLightingProperty__TangentSpaceData> m_spTangentSpaceData;  // +0xDC, 4 bytes
    float* m_pfTextureSpecularExponents;                                           // +0xE0, 4 bytes
    NiTexturingProperty__ClampMode m_eClampMode;                                   // +0xE4, 4 bytes
    NiPointer<BSShaderPPLightingProperty__TextureEffectData> spTexEffectData;      // +0xE8, 4 bytes
    float m_fValueBeforeTextureCount;                                              // +0xEC, 4 bytes
    int m_iTextureCount;                                                           // +0xF0, 4 bytes
    float m_fFirstFloatAfterTextureCount;                                          // +0xF4, 4 bytes
    float m_fSecondFloatAfterTextureCount;                                         // +0xF8, 4 bytes
    float m_fThirdFloatAfterTextureCount;                                          // +0xFC, 4 bytes
    float m_fFourthFloatAfterTextureCount;                                         // +0x100, 4 bytes
    float m_fFifthFloatAfterTextureCount;                                          // +0x104, 4 bytes
    float m_fSixthFloatAfterTextureCount;                                          // +0x108, 4 bytes
    BSShaderProperty__RenderPass* m_pRenderPassEntry;                              // +0x10C, 4 bytes
    // const NiRTTI* __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl BSShaderPPLightingProperty::*(NiStream&)
    // void __cdecl BSShaderPPLightingProperty::*(NiStream&)
    // bool __cdecl BSShaderPPLightingProperty::*(NiStream&)
    // void __cdecl BSShaderPPLightingProperty::*(NiStream&)
    // bool __cdecl BSShaderPPLightingProperty::*(NiObject*)
    // NiObject* __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(NiStream&)
    // BSShaderPPLightingProperty
    // void __cdecl BSShaderPPLightingProperty::*()
    // bool __cdecl BSShaderPPLightingProperty::*(NiGeometry*)
    // unsigned short __cdecl BSShaderPPLightingProperty::*(NiGeometry*)
    // NiTexture* __cdecl BSShaderPPLightingProperty::*()
    // NiTexture* __cdecl BSShaderPPLightingProperty::*(unsigned int)
    // NiTexture* __cdecl BSShaderPPLightingProperty::*(unsigned int)
    // NiTexture* __cdecl BSShaderPPLightingProperty::*(unsigned int)
    // NiTexture* __cdecl BSShaderPPLightingProperty::*(unsigned int)
    // NiPoint3* __cdecl BSShaderPPLightingProperty::*()
    // NiPoint3* __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(float*)
    // bool __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(bool)
    // void __cdecl BSShaderPPLightingProperty::*(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char)
    // void __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(unsigned int, BSTextureSet*)
    // NiTexture* __cdecl BSShaderPPLightingProperty::*(unsigned short)
    // bool __cdecl BSShaderPPLightingProperty::*(int)
    // float __cdecl BSShaderPPLightingProperty::*(int)
    // void __cdecl BSShaderPPLightingProperty::*(BSShaderPPLightingProperty::TextureEffectData*)
    // BSShaderPPLightingProperty::TextureEffectData* __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(NiAVObject*, bool, float, bool, float, bool)
    // bool __cdecl BSShaderPPLightingProperty::*(NiAVObject*)
    // float __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(float)
    // int __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(int)
    // float __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(float)
    // float __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(float)
    // bool __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(BSTextureSet*)
    // void __cdecl BSShaderPPLightingProperty::*(BSTextureSet*)
    // void __cdecl BSShaderPPLightingProperty::*(const char*, BSTextureSet*)
    // void __cdecl BSShaderPPLightingProperty::*()
    // BSShaderProperty* __cdecl BSShaderPPLightingProperty::*(NiGeometry*, bool, bool)
    // void __cdecl BSShaderPPLightingProperty::*(void __cdecl (NiTexture*, unsigned long, void*)*, void*)
    // float __cdecl BSShaderPPLightingProperty::*()
    // float __cdecl BSShaderPPLightingProperty::*()
    // float __cdecl BSShaderPPLightingProperty::*()
    // float __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(float, float, float)
    // void __cdecl BSShaderPPLightingProperty::*(float)
    // void __cdecl BSShaderPPLightingProperty::*()
    // void __cdecl BSShaderPPLightingProperty::*(NiGeometry*, bool, bool)
    // void __cdecl BSShaderPPLightingProperty::*(NiGeometry*, ShadowSceneLight*, unsigned short&, bool, bool&, bool)
    // void __cdecl BSShaderPPLightingProperty::*(NiGeometry*, ShadowSceneLight*, unsigned short&, bool, bool&, bool, bool)
    // void __cdecl BSShaderPPLightingProperty::*(NiGeometry*, bool, bool, BSShaderAccumulator*)
    // void __cdecl BSShaderPPLightingProperty::*(NiGeometry*, bool, bool)
    // void __cdecl BSShaderPPLightingProperty::*(NiGeometry*, bool)
    // BSShaderPPLightingProperty& __cdecl BSShaderPPLightingProperty::*(const BSShaderPPLightingProperty&)
    // void __cdecl BSShaderPPLightingProperty::*()
    BSShaderProperty__RenderPass* AddAmbientDiffuseTexturePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short&, bool,
                                                                  bool&, bool, bool, bool, bool, bool, bool);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderPPLightingProperty) == 272);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fEmissiveMultiple) == 132);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fSpecularScale) == 136);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_kEmissiveColor) == 140);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_kSpecularColor) == 156);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_spTextureSet) == 172);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_usTextureFlags) == 176);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_ppTextureSlots) == 180);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_pTextureFlags) == 208);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_usTextureIndex) == 212);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_pbTextureHasAlpha) == 216);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_spTangentSpaceData) == 220);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_pfTextureSpecularExponents) == 224);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_eClampMode) == 228);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, spTexEffectData) == 232);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fValueBeforeTextureCount) == 236);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_iTextureCount) == 240);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fFirstFloatAfterTextureCount) == 244);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fSecondFloatAfterTextureCount) == 248);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fThirdFloatAfterTextureCount) == 252);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fFourthFloatAfterTextureCount) == 256);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fFifthFloatAfterTextureCount) == 260);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_fSixthFloatAfterTextureCount) == 264);
FNV_STATIC_ASSERT(offsetof(BSShaderPPLightingProperty, m_pRenderPassEntry) == 268);
#endif
