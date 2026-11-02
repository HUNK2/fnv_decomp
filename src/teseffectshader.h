// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESEFFECTSHADER_H
#define FNV_TESEFFECTSHADER_H

#include "layout_support.h"
#include "effectshader_NiPoint3.h"
#include "effectshader_TESForm.h"
#include "TESTexture.h"
class BGSDebris;
class EffectShaderData;
class TESEffectShader;
enum _D3DBLEND
{
    _D3DBLEND_D3DBLEND_ZERO = 0,
    _D3DBLEND_D3DBLEND_ONE = 1,
    _D3DBLEND_D3DBLEND_SRCCOLOR = 4,
    _D3DBLEND_D3DBLEND_INVSRCCOLOR = 5,
    _D3DBLEND_D3DBLEND_SRCALPHA = 6,
    _D3DBLEND_D3DBLEND_INVSRCALPHA = 7,
    _D3DBLEND_D3DBLEND_DESTCOLOR = 8,
    _D3DBLEND_D3DBLEND_INVDESTCOLOR = 9,
    _D3DBLEND_D3DBLEND_DESTALPHA = 10,
    _D3DBLEND_D3DBLEND_INVDESTALPHA = 11,
    _D3DBLEND_D3DBLEND_BLENDFACTOR = 12,
    _D3DBLEND_D3DBLEND_INVBLENDFACTOR = 13,
    _D3DBLEND_D3DBLEND_CONSTANTALPHA = 14,
    _D3DBLEND_D3DBLEND_INVCONSTANTALPHA = 15,
    _D3DBLEND_D3DBLEND_SRCALPHASAT = 16,
    _D3DBLEND_D3DBLEND_FORCE_DWORD = 2147483647
};
enum _D3DBLENDOP
{
    _D3DBLENDOP_D3DBLENDOP_ADD = 0,
    _D3DBLENDOP_D3DBLENDOP_SUBTRACT = 1,
    _D3DBLENDOP_D3DBLENDOP_MIN = 2,
    _D3DBLENDOP_D3DBLENDOP_MAX = 3,
    _D3DBLENDOP_D3DBLENDOP_REVSUBTRACT = 4,
    _D3DBLENDOP_D3DBLENDOP_FORCE_DWORD = 2147483647
};
enum _NDLZCMPFUNC
{
    _NDLZCMPFUNC_NDLZCMP_NEVER = 0,
    _NDLZCMPFUNC_NDLZCMP_LESS = 4,
    _NDLZCMPFUNC_NDLZCMP_EQUAL = 2,
    _NDLZCMPFUNC_NDLZCMP_LESSEQUAL = 6,
    _NDLZCMPFUNC_NDLZCMP_GREATER = 1,
    _NDLZCMPFUNC_NDLZCMP_NOTEQUAL = 5,
    _NDLZCMPFUNC_NDLZCMP_GREATEREQUAL = 3,
    _NDLZCMPFUNC_NDLZCMP_ALWAYS = 7,
    _NDLZCMPFUNC_NDLZCMP_FORCE_DWORD = 2147483647
};
class EffectShaderData
{
  public:
    void Initialize();
    void Endian();
    unsigned char cFlags;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    _D3DBLEND m_eDestinationBlend;                // +0x4, 4 bytes
    _D3DBLENDOP m_eBlendOperation;                // +0x8, 4 bytes
    _NDLZCMPFUNC m_eDepthCompareFunction;         // +0xC, 4 bytes
    unsigned int BlendDepthState;                 // +0x10, 4 bytes
    float BlendDepthParameters;                   // +0x14, 4 bytes
    float DepthCompareParameters;                 // +0x18, 4 bytes
    float IndexedFloatParameters;                 // +0x1C, 4 bytes
    float ShaderFloatParameterSet;                // +0x20, 4 bytes
    float ShaderParameterFormatSet;               // +0x24, 4 bytes
    float SevenFloatParameterRecord;              // +0x28, 4 bytes
    float SixFloatAndUnsignedIntegerRecord;       // +0x2C, 4 bytes
    float SixFloatUnsignedIntegerAndFloatRecord;  // +0x30, 4 bytes
    float ExtendedFloatFlagParameters;            // +0x34, 4 bytes
    unsigned int ShaderFloatParameterBlock;       // +0x38, 4 bytes
    float SixFloatRecordWithMiddleFlag;           // +0x3C, 4 bytes
    float FloatFlagParameters;                    // +0x40, 4 bytes
    float SixFloatRecordWithLeadingFlag;          // +0x44, 4 bytes
    float BlendFloatParameters;                   // +0x48, 4 bytes
    float AlphaBlendParameters;                   // +0x4C, 4 bytes
    float BlendStateParameters;                   // +0x50, 4 bytes
    float BlendFactorState;                       // +0x54, 4 bytes
    float BlendModeConfiguration;                 // +0x58, 4 bytes
    _D3DBLEND m_eSourceBlend;                     // +0x5C, 4 bytes
    _D3DBLEND m_eAlphaSourceBlend;                // +0x60, 4 bytes
    _D3DBLENDOP m_eAlphaBlendOperation;           // +0x64, 4 bytes
    _NDLZCMPFUNC m_eAlphaDepthCompareFunction;    // +0x68, 4 bytes
    _D3DBLEND m_eAlphaDestinationBlend;           // +0x6C, 4 bytes
    float AlphaBlendSettings;                     // +0x70, 4 bytes
    float m_fAlphaBlendParameter;                 // +0x74, 4 bytes
    float BlendFactorParameters;                  // +0x78, 4 bytes
    float m_fShaderFloatParameter1;               // +0x7C, 4 bytes
    float m_fShaderFloatParameter2;               // +0x80, 4 bytes
    float m_fShaderFloatParameter3;               // +0x84, 4 bytes
    float m_fShaderFloatParameter4;               // +0x88, 4 bytes
    float m_fShaderFloatParameter5;               // +0x8C, 4 bytes
    float m_fShaderFloatParameter6;               // +0x90, 4 bytes
    NiPoint3 VelocityState;                       // +0x94, 12 bytes
    NiPoint3 m_kVectorState2;                     // +0xA0, 12 bytes
    float m_fShaderFloatParameter7;               // +0xAC, 4 bytes
    float m_fShaderFloatParameter8;               // +0xB0, 4 bytes
    float m_fShaderFloatParameter9;               // +0xB4, 4 bytes
    float m_fShaderFloatParameter10;              // +0xB8, 4 bytes
    unsigned int m_uiColorParameter1;             // +0xBC, 4 bytes
    unsigned int m_uiColorParameter2;             // +0xC0, 4 bytes
    unsigned int m_uiColorParameter3;             // +0xC4, 4 bytes
    float m_fShaderFloatParameter11;              // +0xC8, 4 bytes
    float m_fShaderFloatParameter12;              // +0xCC, 4 bytes
    float m_fShaderFloatParameter13;              // +0xD0, 4 bytes
    float m_fShaderFloatParameter14;              // +0xD4, 4 bytes
    float m_fShaderFloatParameter15;              // +0xD8, 4 bytes
    float m_fShaderFloatParameter16;              // +0xDC, 4 bytes
    float m_fShaderFloatParameter17;              // +0xE0, 4 bytes
    float m_fShaderFloatParameter18;              // +0xE4, 4 bytes
    float m_fShaderFloatParameter19;              // +0xE8, 4 bytes
    float m_fShaderFloatParameter20;              // +0xEC, 4 bytes
    float m_fShaderFloatParameter21;              // +0xF0, 4 bytes
    BGSDebris* pAddonModels;                      // +0xF4, 4 bytes
    float DebrisModelSettings;                    // +0xF8, 4 bytes
    float EffectShaderAddonData;                  // +0xFC, 4 bytes
    float DebrisColorSettings;                    // +0x100, 4 bytes
    float EffectShaderColorData;                  // +0x104, 4 bytes
    float EffectShaderParameters;                 // +0x108, 4 bytes
    unsigned int m_uiBaseColor;                   // +0x10C, 4 bytes
    float m_fFloatAfterDefaultColor;              // +0x110, 4 bytes
    unsigned int m_uiIntegerParameter1;           // +0x114, 4 bytes
    unsigned int m_uiIntegerParameter2;           // +0x118, 4 bytes
    float m_fFirstValueAfterIntegerFields;        // +0x11C, 4 bytes
    float m_fSecondValueAfterIntegerFields;       // +0x120, 4 bytes
    float UnsignedIntAndSixFloatData;             // +0x124, 4 bytes
    float SixFloatValueSet;                       // +0x128, 4 bytes
    float FiveFloatData;                          // +0x12C, 4 bytes
    float FourFloatValueSet;                      // +0x130, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(EffectShaderData) == 308);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, cFlags) == 0);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eDestinationBlend) == 4);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eBlendOperation) == 8);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eDepthCompareFunction) == 12);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendDepthState) == 16);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendDepthParameters) == 20);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, DepthCompareParameters) == 24);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, IndexedFloatParameters) == 28);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, ShaderFloatParameterSet) == 32);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, ShaderParameterFormatSet) == 36);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, SevenFloatParameterRecord) == 40);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, SixFloatAndUnsignedIntegerRecord) == 44);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, SixFloatUnsignedIntegerAndFloatRecord) == 48);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, ExtendedFloatFlagParameters) == 52);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, ShaderFloatParameterBlock) == 56);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, SixFloatRecordWithMiddleFlag) == 60);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, FloatFlagParameters) == 64);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, SixFloatRecordWithLeadingFlag) == 68);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendFloatParameters) == 72);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, AlphaBlendParameters) == 76);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendStateParameters) == 80);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendFactorState) == 84);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendModeConfiguration) == 88);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eSourceBlend) == 92);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eAlphaSourceBlend) == 96);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eAlphaBlendOperation) == 100);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eAlphaDepthCompareFunction) == 104);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_eAlphaDestinationBlend) == 108);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, AlphaBlendSettings) == 112);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fAlphaBlendParameter) == 116);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, BlendFactorParameters) == 120);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter1) == 124);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter2) == 128);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter3) == 132);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter4) == 136);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter5) == 140);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter6) == 144);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, VelocityState) == 148);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_kVectorState2) == 160);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter7) == 172);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter8) == 176);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter9) == 180);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter10) == 184);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_uiColorParameter1) == 188);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_uiColorParameter2) == 192);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_uiColorParameter3) == 196);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter11) == 200);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter12) == 204);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter13) == 208);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter14) == 212);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter15) == 216);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter16) == 220);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter17) == 224);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter18) == 228);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter19) == 232);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter20) == 236);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fShaderFloatParameter21) == 240);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, pAddonModels) == 244);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, DebrisModelSettings) == 248);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, EffectShaderAddonData) == 252);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, DebrisColorSettings) == 256);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, EffectShaderColorData) == 260);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, EffectShaderParameters) == 264);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_uiBaseColor) == 268);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fFloatAfterDefaultColor) == 272);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_uiIntegerParameter1) == 276);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_uiIntegerParameter2) == 280);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fFirstValueAfterIntegerFields) == 284);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, m_fSecondValueAfterIntegerFields) == 288);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, UnsignedIntAndSixFloatData) == 292);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, SixFloatValueSet) == 296);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, FiveFloatData) == 300);
FNV_STATIC_ASSERT(offsetof(EffectShaderData, FourFloatValueSet) == 304);
class TESEffectShader : public TESForm
{
  public:
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    virtual void InitItem();
    EffectShaderData* GetData();
    BGSDebris* GetAddonModels();
    void SetAddonModels(BGSDebris* models);
    EffectShaderData Data;                // +0x18, 308 bytes
    TESTexture m_kFillTexture;            // +0x14C, 12 bytes
    TESTexture m_kParticleShaderTexture;  // +0x158, 12 bytes
    TESTexture m_kHolesTexture;           // +0x164, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(TESEffectShader) == 368);
FNV_STATIC_ASSERT(offsetof(TESEffectShader, Data) == 24);
FNV_STATIC_ASSERT(offsetof(TESEffectShader, m_kFillTexture) == 332);
FNV_STATIC_ASSERT(offsetof(TESEffectShader, m_kParticleShaderTexture) == 344);
FNV_STATIC_ASSERT(offsetof(TESEffectShader, m_kHolesTexture) == 356);
class BGSDebris : public TESForm
{
  public:
    virtual ~BGSDebris();
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
class ParticleShader
{
  public:
    static unsigned int GetShaderParticleCount();
};
#endif
