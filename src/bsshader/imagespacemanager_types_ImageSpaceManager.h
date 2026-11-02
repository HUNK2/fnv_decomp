// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACEMANAGER_H
#define FNV_IMAGESPACEMANAGER_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class BSTextureManager
{
  public:
    enum RenderTargetType
    {
        BSTM_RT_SCENE_DEPTH_BUFFER = 33
    };
};
class BSRenderedTexture;
class ImageSpaceEffect;
class ImageSpaceManager;
class ImageSpaceModifierParameterData;
class ImageSpaceTexture;
class RgbaColor;
class NiPoint2;
class NiRect_float_;
class NiScreenElements;
class NiScreenElementsData;
class NiTexture;
class NiTPrimitiveArray_ImageSpaceEffect___;
enum ImageSpaceManager__ImageSpaceEffectEnum
{
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_REFRACTION = 0,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLOOM = 1,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_HDR = 2,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_CINEMATIC = 3,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_DEPTH_OF_FIELD = 4,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_DEPTH_RADIAL_BLUR = 5,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_RADIAL_BLUR = 6,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_FULLSCREEN_BLUR = 7,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_GETHIT = 8,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SUNBEAMS = 9,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_INTERFACE = 10,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_VATS_SCAN = 11,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_MOTION_BLUR = 12,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_ENDOFFRAME_END = 13,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_VOLUMETRIC_FOG = 13,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_MAP = 14,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_MENUBG = 15,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR_START = 16,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR3 = 16,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR5 = 17,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR7 = 18,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR9 = 19,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR11 = 20,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR13 = 21,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR15 = 22,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BLUR_END = 22,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR3 = 23,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR5 = 24,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR7 = 25,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR9 = 26,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR11 = 27,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR13 = 28,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_BRIGHTPASS_BLUR15 = 29,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_TV = 30,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_WATER_FFT = 31,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_WATER_DISPLACEMENT = 32,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_NOISE = 33,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_TOP_LEVEL_END = 34,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_NIGHTVISION = 34,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_END = 34,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_START = 34,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_COPY = 34,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_COPY_RENDER_TARGET1 = 35,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_RESTORE_EDRAM = 36,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_NULL = 37,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_COPYWITHALPHA = 38,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_STENCILCOPY = 39,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_STENCILCOPY_NOTEX_NODEPTH = 40,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_REFRACTION = 41,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_VOLUMETRIC_FOG = 42,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR = 43,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_DOUBLEVIS = 44,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_ALPHAMULT = 45,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLEND = 46,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_TEXTUREMASK = 47,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_MAP = 48,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_MENUBG = 49,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_CINEMATIC = 50,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_DEPTH_OF_FIELD = 51,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_DEPTH_OF_FIELD_MASK = 52,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_MOTION_BLUR = 53,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_RADIAL_BLUR = 54,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_RADIAL_BLUR_MED = 55,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_RADIAL_BLUR_HIGH = 56,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_SUNBEAMS = 57,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_BLENDINSHADER = 58,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_BLENDINSHADER_CINEMATIC = 59,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_BLENDINSHADER_CINEMATIC_ALPHAMASK = 60,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_BLUR = 61,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_BRIGHTPASSFILTER = 62,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE16 = 63,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE9 = 64,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE4 = 65,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE4_LUMCLAMP = 66,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE4_LIGHTADAPT = 67,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE16_LUMCLAMP = 68,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_DOWNSAMPLE16_LIGHTADAPT = 69,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_LIGHTADAPT = 70,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_HDR_LUMCLAMP = 71,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_INTERFACE_SCANLINES_BLEND = 72,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_INTERFACE_VATS_SCANLINES_BLEND = 73,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_INTERFACE_SINGLEPASS = 74,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_INTERFACE_VATS_SCAN = 75,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_INTERFACE_MENUUNPACK = 76,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_TV = 77,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR_START = 78,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR3 = 78,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR5 = 79,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR7 = 80,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR9 = 81,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR11 = 82,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR13 = 83,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR15 = 84,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BLUR_END = 84,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR_START = 85,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR3 = 85,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR5 = 86,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR7 = 87,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR9 = 88,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR11 = 89,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR13 = 90,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR15 = 91,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_BRIGHTPASS_BLUR_END = 91,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_START = 92,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_WATER_SPECTRUM = 93,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_HORIZONTAL_BUTTERFLY = 94,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_VERTICAL_BUTTERFLY = 95,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_HORIZONTAL_SCRAMBLE = 96,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_VERTICAL_SCRAMBLE = 97,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_NORMALS = 98,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_FILTER = 99,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_DISPLAY_NORMALS = 100,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_DISPLAY_HIGHW = 101,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_DISPLAY_AMPLITUDE = 102,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_DISPLAY_WATER_SPECTRUM = 103,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_DISPLAY_WATER_HEIGHT = 104,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_FFT_END = 104,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_START = 105,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_CLEAR_SIMULATION = 105,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_TEX_OFFSET = 106,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_WADING_RIPPLE = 107,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_RAIN_RIPPLE = 108,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_WADING_HEIGHTMAP = 109,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_RAIN_HEIGHTMAP = 110,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_BLEND_HEIGHTMAPS = 111,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_SMOOTH_HEIGHTMAP = 112,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_NORMALS = 113,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_WATER_DISPLACEMENT_END = 113,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_NOISE_SCROLL_AND_BLEND = 114,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_SHADER_NOISE_NORMALMAP = 115,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_COUNT = 116,
    ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_NONE = -1
};
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
enum NiTexturingProperty__ClampMode
{
    NiTexturingProperty__ClampMode_CLAMP_S_CLAMP_T = 0,
    NiTexturingProperty__ClampMode_CLAMP_S_WRAP_T = 1,
    NiTexturingProperty__ClampMode_WRAP_S_CLAMP_T = 2,
    NiTexturingProperty__ClampMode_WRAP_S_WRAP_T = 3,
    NiTexturingProperty__ClampMode_CLAMP_MAX_MODES = 4
};
enum ImageSpaceEffectDepthOfField__DepthOfFieldMode
{
    ImageSpaceEffectDepthOfField__DepthOfFieldMode_DOF_FRONT_BACK = 0,
    ImageSpaceEffectDepthOfField__DepthOfFieldMode_DOF_FRONT = 1,
    ImageSpaceEffectDepthOfField__DepthOfFieldMode_DOF_BACK = 2,
    ImageSpaceEffectDepthOfField__DepthOfFieldMode_DOF_NONE = 3
};
enum ImageSpaceEffectDepthRadialBlur__RadialBlurMode
{
    ImageSpaceEffectDepthRadialBlur__RadialBlurMode_DOF_FRONT_BACK = 0,
    ImageSpaceEffectDepthRadialBlur__RadialBlurMode_DOF_FRONT = 1,
    ImageSpaceEffectDepthRadialBlur__RadialBlurMode_DOF_BACK = 2,
    ImageSpaceEffectDepthRadialBlur__RadialBlurMode_DOF_NONE = 3
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
class ImageSpaceModifierParameterData
{
  public:
    float m_afFirstParameterSet[15];        // +0x0, 60 bytes
    float m_afSecondParameterSet[3];        // +0x3C, 12 bytes
    float m_afThirdParameterSet[3];         // +0x48, 12 bytes
    float m_afFourthParameterSet[4];        // +0x54, 16 bytes
    float m_afColorAndAlphaParameters[12];  // +0x64, 48 bytes
    unsigned int ShaderConstantData;        // +0x94, 4 bytes
    // void __cdecl ImageSpaceModifierParameterData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierParameterData) == 152);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afFirstParameterSet) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afSecondParameterSet) == 60);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afThirdParameterSet) == 72);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afFourthParameterSet) == 84);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afColorAndAlphaParameters) == 100);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, ShaderConstantData) == 148);
#pragma pack(push, 4)
class ImageSpaceTexture
{
  public:
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
    // void __cdecl ImageSpaceTexture::*(BSTextureManager::RenderTargetType)
    // void __cdecl ImageSpaceTexture::*(bool)
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::FilterMode)
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::ClampMode)
    // ImageSpaceTexture& __cdecl ImageSpaceTexture::*(ImageSpaceTexture&)
    // void* __cdecl ImageSpaceTexture::*(unsigned int)
    // declarations for the targets of this unit's covered code
    NiTexture* GetTexture();
    NiTexture* GetTexture() const;
    BSRenderedTexture* GetRenderedTexture() const;
    void CreateRenderTargetTexture(BSTextureManager::RenderTargetType);
    BSRenderedTexture* FUN_00ba3770();
    void FUN_00ba3840(unsigned int textureType);
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
class NiPoint2
{
  public:
    float x;  // +0x0, 4 bytes
    float y;  // +0x4, 4 bytes
    // NiPoint2
    // operator[]
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&)
    // operator-
    // operator*
    // NiPoint2 __cdecl NiPoint2::*(float)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&, const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*(const NiPoint2&)
    // float __cdecl NiPoint2::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiPoint2::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint2) == 8);
FNV_STATIC_ASSERT(offsetof(NiPoint2, x) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint2, y) == 4);
#pragma pack(push, 4)
class NiRect_float_
{
  public:
    float m_fMinimumU;  // +0x0, 4 bytes
    float m_fMaximumU;  // +0x4, 4 bytes
    float m_fMinimumV;  // +0x8, 4 bytes
    float m_fMaximumV;  // +0xC, 4 bytes
    // void __cdecl NiRect<float>::*(float, float, float, float)
    // void __cdecl NiRect<float>::*(NiStream&)
    // void __cdecl NiRect<float>::*(NiStream&)
    // char* __cdecl NiRect<float>::*(const char*)
    // void __cdecl NiRect<float>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiRect_float_) == 16);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMinimumU) == 0);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMaximumU) == 4);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMinimumV) == 8);
FNV_STATIC_ASSERT(offsetof(NiRect_float_, m_fMaximumV) == 12);
#pragma pack(push, 4)
class ImageSpaceManager
{
  public:
    void CreateMenuBackgroundGeometry();
    static bool m_bHasEndOfFrameEffects;
    void BeginParamModifiers();
    void SetupEffects();
    bool IsEffectActive(ImageSpaceManager__ImageSpaceEffectEnum);
    void PrepareEndOfFrameEffects();
    static ImageSpaceManager* FUN_004e3270();
    BSRenderedTexture* m_pCurrentRenderedTexture;                             // +0x0, 4 bytes
    NiTPrimitiveArray_ImageSpaceEffect___ pEffectList;                        // +0x4, 16 bytes
    ImageSpaceModifierParameterData m_kBlendedParameterData;                  // +0x14, 152 bytes
    const ImageSpaceModifierParameterData* m_pCurrentModifierParameterData;   // +0xAC, 4 bytes
    const ImageSpaceModifierParameterData* m_pPreviousModifierParameterData;  // +0xB0, 4 bytes
    ImageSpaceModifierParameterData m_kModifierParameterData[2];              // +0xB4, 304 bytes
    bool m_bEndOfFrameEffectsEnabled;                                         // +0x1E4, 1 bytes
    unsigned char layoutPadding1E5[3];
    int m_iEndOfFrameEffectCount;                                               // +0x1E8, 4 bytes
    ImageSpaceManager__ImageSpaceEffectEnum m_eEndOfFrameEffect;                // +0x1EC, 4 bytes
    GeometryPointer<NiScreenElements> m_pMenuBackgroundScreenGeometry;          // +0x1F0, 4 bytes
    GeometryPointer<NiScreenElementsData> m_pMenuBackgroundScreenElementsData;  // +0x1F4, 4 bytes
    NiPointer<NiScreenElements> m_pMenuBackgroundScreenElements;                // +0x1F8, 4 bytes
    bool m_bPartialRenderEnabled;                                               // +0x1FC, 1 bytes
    unsigned char layoutPadding1FD[3];
    NiPointer<NiScreenElements> m_pPartialRenderScreenElements;                // +0x200, 4 bytes
    ImageSpaceTexture m_kDepthTexture;                                         // +0x204, 16 bytes
    RgbaColor m_kModifierColor;                                                // +0x214, 16 bytes
    RgbaColor m_kPartialRenderColor;                                           // +0x224, 16 bytes
    float m_fPartialRenderBlend;                                               // +0x234, 4 bytes
    RgbaColor m_kAccumulatedColor;                                             // +0x238, 16 bytes
    RgbaColor m_kWeatherFadeColor;                                             // +0x248, 16 bytes
    float m_fFadeColorAlpha;                                                   // +0x258, 4 bytes
    float m_fDoubleVisionStrength;                                             // +0x25C, 4 bytes
    float m_fWeatherBlurRadius;                                                // +0x260, 4 bytes
    float m_fWeatherDoubleVisionStrength;                                      // +0x264, 4 bytes
    float m_fAdditionalImageSpaceValue;                                        // +0x268, 4 bytes
    float m_fRadialBlurStrength;                                               // +0x26C, 4 bytes
    float m_fRadialBlurRampUp;                                                 // +0x270, 4 bytes
    float m_fRadialBlurStart;                                                  // +0x274, 4 bytes
    float m_fRadialBlurRampDown;                                               // +0x278, 4 bytes
    float m_fRadialBlurDownStart;                                              // +0x27C, 4 bytes
    float m_fWeatherRadialBlurStrength;                                        // +0x280, 4 bytes
    float m_fWeatherRadialBlurRampUp;                                          // +0x284, 4 bytes
    float m_fWeatherRadialBlurStart;                                           // +0x288, 4 bytes
    float m_fWeatherRadialBlurRampDown;                                        // +0x28C, 4 bytes
    float m_fWeatherRadialBlurDownStart;                                       // +0x290, 4 bytes
    NiPoint2 m_kRadialBlurCenter;                                              // +0x294, 8 bytes
    NiPoint2 m_kWeatherRadialBlurCenter;                                       // +0x29C, 8 bytes
    float m_fDepthOfFieldStrength;                                             // +0x2A4, 4 bytes
    float m_fDepthOfFieldMaskConstant;                                         // +0x2A8, 4 bytes
    float m_fDepthOfFieldDistance;                                             // +0x2AC, 4 bytes
    float m_fDepthOfFieldRange;                                                // +0x2B0, 4 bytes
    float m_fDepthOfFieldEffectStrength;                                       // +0x2B4, 4 bytes
    float m_fDepthOfFieldEffectDistance;                                       // +0x2B8, 4 bytes
    float m_fDepthOfFieldEffectRange;                                          // +0x2BC, 4 bytes
    float m_fDepthOfFieldMaskValue;                                            // +0x2C0, 4 bytes
    ImageSpaceEffectDepthOfField__DepthOfFieldMode m_eDepthOfFieldMode;        // +0x2C4, 4 bytes
    ImageSpaceEffectDepthOfField__DepthOfFieldMode m_eDepthOfFieldTargetMode;  // +0x2C8, 4 bytes
    bool m_bDepthOfFieldUsesObject;                                            // +0x2CC, 1 bytes
    bool m_bMenuBackgroundBlendEnabled;                                        // +0x2CD, 1 bytes
    unsigned char layoutPadding2CE[2];
    float m_fBlurRadius;                                                // +0x2D0, 4 bytes
    float m_fRadialBlurTransition;                                      // +0x2D4, 4 bytes
    float m_fRadialBlurStartValue;                                      // +0x2D8, 4 bytes
    float m_fRadialBlurDistance;                                        // +0x2DC, 4 bytes
    float m_fRadialBlurRange;                                           // +0x2E0, 4 bytes
    NiPoint2 m_kRadialBlurOrigin;                                       // +0x2E4, 8 bytes
    ImageSpaceEffectDepthRadialBlur__RadialBlurMode m_eRadialBlurMode;  // +0x2EC, 4 bytes
    float m_fMenuBackgroundBlendValue;                                  // +0x2F0, 4 bytes
    float m_fMenuBackgroundBlendTarget;                                 // +0x2F4, 4 bytes
    RgbaColor m_kMenuBackgroundTint;                                    // +0x2F8, 16 bytes
    NiRect_float_ m_kMenuBackgroundRect;                                // +0x308, 16 bytes
    BSRenderedTexture* m_pMenuBackgroundTexture;                        // +0x318, 4 bytes
    // ImageSpaceManager
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // ImageSpaceEffect* __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceEffectEnum)
    // void __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceEffectEnum, ImageSpaceEffect*)
    // bool __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceEffectEnum)
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // RenderEffect
    // void __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceEffectEnum, unsigned int, ImageSpaceManager::ImageSpaceParamOperationEnum, float)
    // void __cdecl ImageSpaceManager::*(bool)
    // void __cdecl ImageSpaceManager::*(const ImageSpaceModifierParameterData*)
    // void __cdecl ImageSpaceManager::*(const ImageSpaceModifierParameterData*)
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceEffectEnum, unsigned int, float*, float)
    // void __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceEffectEnum, unsigned int, float*, float)
    // void __cdecl ImageSpaceManager::*(RgbaColor&)
    // void __cdecl ImageSpaceManager::*(RgbaColor&)
    // void __cdecl ImageSpaceManager::*(RgbaColor&)
    // void __cdecl ImageSpaceManager::*(RgbaColor&)
    // void __cdecl ImageSpaceManager::*(float)
    // void __cdecl ImageSpaceManager::*(float)
    // void __cdecl ImageSpaceManager::*(float)
    // void __cdecl ImageSpaceManager::*(float)
    // SetRadialBlurParameters
    void SetRadialBlurParameters(float, float, float, float, float, const NiPoint2&);
    // SetDepthOfFieldParameters
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void __cdecl SetBlurRadiusParamModifier(float);
    // declarations added by this unit for the covered uniform functions
    void FUN_00b8b130(float, unsigned int, float, float, float);
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    void FUN_00b8b360();
    bool FUN_00b8b390(unsigned int);
    void FUN_00b8b3f0();
    void FUN_00b8b440(bool);
    void FUN_00b8b540(RgbaColor&);
    void ApplyTintColorParamModifier(RgbaColor&);
    void FUN_00b8b5c0(RgbaColor&);
    void ApplyTintColorParamModifierWeather(RgbaColor&);
    void FUN_00b8b610(RgbaColor&);
    void SetFadeColorParamModifier(RgbaColor&);
    void FUN_00b8b690(RgbaColor&);
    void ApplyFadeColorParamModifierWeather(RgbaColor&);
    BSRenderedTexture* GetDepthRenderedTexture();
    void FUN_00b8b6e0(float, float, float, float, float, const NiPoint2&);
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, const NiPoint2&);
    // void __cdecl ImageSpaceManager::*(float)
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*(ImageSpaceManager::ImageSpaceParamOperationEnum, float, float)
    // void __cdecl ImageSpaceManager::*(const NiBound&, NiPoint2&)
    // void __cdecl ImageSpaceManager::*(const NiBound&, NiPoint2&)
    // void __cdecl ImageSpaceManager::*(const bool)
    // void __cdecl ImageSpaceManager::*(const NiPoint2&)
    // BSRenderedTexture* __cdecl ImageSpaceManager::*(bool)
    // BSRenderedTexture* __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // float __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*(RgbaColor)
    // void __cdecl ImageSpaceManager::*(float)
    // void __cdecl ImageSpaceManager::*(bool)
    // void __cdecl ImageSpaceManager::*(float)
    // void __cdecl ImageSpaceManager::*(bool, NiScreenElements*)
    // void __cdecl ImageSpaceManager::*(float, float, NiPointer<NiScreenElements>&)
    // NiTexture* __cdecl ImageSpaceManager::*()
    // ImageSpaceTexture* __cdecl ImageSpaceManager::*()
    // BSRenderedTexture* __cdecl ImageSpaceManager::*()
    // SetDepthTexture
    // void __cdecl ImageSpaceManager::*()
    // NiScreenElements* __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*(NiScreenElements*)
    // void __cdecl ImageSpaceManager::*(const RgbaColor&)
    // const RgbaColor& __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*(float, float, float, float)
    // void __cdecl ImageSpaceManager::*()
    // const NiRect<float>* __cdecl ImageSpaceManager::*()
    // BSRenderedTexture* __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // void __cdecl ImageSpaceManager::*()
    // ImageSpaceManager& __cdecl ImageSpaceManager::*(ImageSpaceManager&)
    // void* __cdecl ImageSpaceManager::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceManager) == 796);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pCurrentRenderedTexture) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, pEffectList) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kBlendedParameterData) == 20);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pCurrentModifierParameterData) == 172);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pPreviousModifierParameterData) == 176);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kModifierParameterData) == 180);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_bEndOfFrameEffectsEnabled) == 484);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_iEndOfFrameEffectCount) == 488);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_eEndOfFrameEffect) == 492);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pMenuBackgroundScreenGeometry) == 496);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pMenuBackgroundScreenElementsData) == 500);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pMenuBackgroundScreenElements) == 504);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_bPartialRenderEnabled) == 508);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pPartialRenderScreenElements) == 512);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kDepthTexture) == 516);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kModifierColor) == 532);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kPartialRenderColor) == 548);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fPartialRenderBlend) == 564);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kAccumulatedColor) == 568);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kWeatherFadeColor) == 584);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fFadeColorAlpha) == 600);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDoubleVisionStrength) == 604);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherBlurRadius) == 608);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherDoubleVisionStrength) == 612);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fAdditionalImageSpaceValue) == 616);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurStrength) == 620);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurRampUp) == 624);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurStart) == 628);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurRampDown) == 632);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurDownStart) == 636);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherRadialBlurStrength) == 640);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherRadialBlurRampUp) == 644);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherRadialBlurStart) == 648);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherRadialBlurRampDown) == 652);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fWeatherRadialBlurDownStart) == 656);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kRadialBlurCenter) == 660);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kWeatherRadialBlurCenter) == 668);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldStrength) == 676);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldMaskConstant) == 680);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldDistance) == 684);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldRange) == 688);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldEffectStrength) == 692);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldEffectDistance) == 696);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldEffectRange) == 700);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fDepthOfFieldMaskValue) == 704);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_eDepthOfFieldMode) == 708);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_eDepthOfFieldTargetMode) == 712);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_bDepthOfFieldUsesObject) == 716);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_bMenuBackgroundBlendEnabled) == 717);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fBlurRadius) == 720);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurTransition) == 724);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurStartValue) == 728);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurDistance) == 732);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fRadialBlurRange) == 736);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kRadialBlurOrigin) == 740);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_eRadialBlurMode) == 748);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fMenuBackgroundBlendValue) == 752);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_fMenuBackgroundBlendTarget) == 756);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kMenuBackgroundTint) == 760);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_kMenuBackgroundRect) == 776);
FNV_STATIC_ASSERT(offsetof(ImageSpaceManager, m_pMenuBackgroundTexture) == 792);
#endif
