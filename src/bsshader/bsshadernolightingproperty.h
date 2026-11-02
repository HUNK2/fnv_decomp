// Reconstructed source layout for BSShaderNoLightingProperty.
// Covers getter 0x008d8520, which returns the base map texture pointer.
#ifndef FNV_BSSHADERNOLIGHTINGPROPERTY_H
#define FNV_BSSHADERNOLIGHTINGPROPERTY_H


#include "layout_support.h"
#include "NiProperty.h"

class NiTexture;
class FNVRenderPassArray;

// NiShadeProperty (0x20 bytes) extends NiProperty (0x18) with shader flags.
#pragma pack(push, 4)
class NiShadeProperty : public NiProperty
{
  public:
    unsigned short m_uiObjectFlags;  // +0x18
    int m_iShaderType;        // +0x1C
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiShadeProperty) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiShadeProperty, m_uiObjectFlags) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiShadeProperty, m_iShaderType) == 0x1C);

// Clamp modes shared by texturing properties.
class NiTexturingProperty
{
  public:
    enum ClampMode
    {
        etClampS,
        etClampT,
        etClampBoth,
        etClampEdge,
        etClampMirror,
        etClampMax
    };
};

// 32-bit RGBA color (4 bytes).
class RgbaColor
{
  public:
    unsigned int rgba;
};
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 4);

// BSShaderProperty (0x68 bytes) extends NiShadeProperty.
#pragma pack(push, 4)
class BSShaderProperty : public NiShadeProperty
{
  public:
    unsigned int ulFlags[2];                  // +0x20
    float fAlpha;                             // +0x28
    float fFadeAlpha;                         // +0x2C
    float m_fAmbientReflectionScale;          // +0x30
    float m_fSpecularExponent;                // +0x34
    int iLastRenderPassState;                 // +0x38
    FNVRenderPassArray* pRenderPassList;      // +0x3C
    FNVRenderPassArray* m_pRenderPassArray1;  // +0x40
    FNVRenderPassArray* m_pRenderPassArray2;  // +0x44
    FNVRenderPassArray* m_pRenderPassArray3;  // +0x48
    FNVRenderPassArray* m_pRenderPassArray4;  // +0x4C
    FNVRenderPassArray* m_pRenderPassArray5;  // +0x50
    FNVRenderPassArray* m_pRenderPassArray6;  // +0x54
    int m_iRenderPassCount;                   // +0x58
    float fDepthBias;                         // +0x5C
    float m_fValueAfterDepthBias;             // +0x60
    float m_fEnvironmentMapScale;             // +0x64
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderProperty) == 0x68);

// BSShaderNoLightingProperty. m_pNoLightingTexture is the first member after the
// 0x68-byte base; the covered getter returns its raw pointer.
#pragma pack(push, 4)
class BSShaderNoLightingProperty : public BSShaderProperty
{
  public:
    NiPointer<NiTexture> m_pNoLightingTexture;    // +0x68
    BSStringT<char> m_kTextureFilePath;           // +0x6C
    NiTexturingProperty::ClampMode m_eClampMode;  // +0x74
    RgbaColor m_kEmissiveColor;                   // +0x78

// @fnv 0x008d8520
    NiTexture* GetBaseTexture()
    {
        return m_pNoLightingTexture.m_pObject;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(offsetof(BSShaderNoLightingProperty, m_pNoLightingTexture) == 0x68);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLightingProperty, m_kTextureFilePath) == 0x6C);

#endif
