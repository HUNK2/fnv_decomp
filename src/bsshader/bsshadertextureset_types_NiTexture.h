// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITEXTURE_H
#define FNV_NITEXTURE_H

#include "layout_support.h"
#include "NiObjectNET.h"
class NiTexture;
class NiTexture__FormatPrefs;
class NiTexture__RendererData;
enum NiTexture__FormatPrefs__PixelLayout
{
    NiTexture__FormatPrefs__PixelLayout_PALETTIZED_8 = 0,
    NiTexture__FormatPrefs__PixelLayout_HIGH_COLOR_16 = 1,
    NiTexture__FormatPrefs__PixelLayout_TRUE_COLOR_32 = 2,
    NiTexture__FormatPrefs__PixelLayout_COMPRESSED = 3,
    NiTexture__FormatPrefs__PixelLayout_BUMPMAP = 4,
    NiTexture__FormatPrefs__PixelLayout_PALETTIZED_4 = 5,
    NiTexture__FormatPrefs__PixelLayout_PIX_DEFAULT = 6,
    NiTexture__FormatPrefs__PixelLayout_SINGLE_COLOR_8 = 7,
    NiTexture__FormatPrefs__PixelLayout_SINGLE_COLOR_16 = 8,
    NiTexture__FormatPrefs__PixelLayout_SINGLE_COLOR_32 = 9,
    NiTexture__FormatPrefs__PixelLayout_DOUBLE_COLOR_32 = 10,
    NiTexture__FormatPrefs__PixelLayout_DOUBLE_COLOR_64 = 11,
    NiTexture__FormatPrefs__PixelLayout_FLOAT_COLOR_32 = 12,
    NiTexture__FormatPrefs__PixelLayout_FLOAT_COLOR_64 = 13,
    NiTexture__FormatPrefs__PixelLayout_FLOAT_COLOR_128 = 14
};
enum NiTexture__FormatPrefs__AlphaFormat
{
    NiTexture__FormatPrefs__AlphaFormat_NONE = 0,
    NiTexture__FormatPrefs__AlphaFormat_BINARY = 1,
    NiTexture__FormatPrefs__AlphaFormat_SMOOTH = 2,
    NiTexture__FormatPrefs__AlphaFormat_ALPHA_DEFAULT = 3
};
enum NiTexture__FormatPrefs__MipFlag
{
    NiTexture__FormatPrefs__MipFlag_NO = 0,
    NiTexture__FormatPrefs__MipFlag_YES = 1,
    NiTexture__FormatPrefs__MipFlag_MIP_DEFAULT = 2
};
#pragma pack(push, 4)
class NiTexture__FormatPrefs
{
  public:
    NiTexture__FormatPrefs__PixelLayout m_ePreferredPixelLayout;  // +0x0, 4 bytes
    NiTexture__FormatPrefs__AlphaFormat m_eAlphaFormat;           // +0x4, 4 bytes
    NiTexture__FormatPrefs__MipFlag m_eMipFlag;                   // +0x8, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTexture__FormatPrefs) == 12);
FNV_STATIC_ASSERT(offsetof(NiTexture__FormatPrefs, m_ePreferredPixelLayout) == 0);
FNV_STATIC_ASSERT(offsetof(NiTexture__FormatPrefs, m_eAlphaFormat) == 4);
FNV_STATIC_ASSERT(offsetof(NiTexture__FormatPrefs, m_eMipFlag) == 8);
#pragma pack(push, 4)
class NiTexture : public NiObjectNET
{
  public:
    // base NiObjectNET at +0x0, size 24
    NiTexture__FormatPrefs m_kTextureFormatPreferences;  // +0x18, 12 bytes
    NiTexture__RendererData* m_pTextureRendererData;     // +0x24, 4 bytes
    NiTexture* m_pkPrev;                                 // +0x28, 4 bytes
    NiTexture* m_pkNext;                                 // +0x2C, 4 bytes
    // const NiRTTI* __cdecl NiTexture::*()
    // void __cdecl NiTexture::*(NiStream&)
    // void __cdecl NiTexture::*(NiStream&)
    // bool __cdecl NiTexture::*(NiStream&)
    // void __cdecl NiTexture::*(NiStream&)
    // bool __cdecl NiTexture::*(NiObject*)
    // void __cdecl NiTexture::*(NiTPrimitiveArray<char *>*)
    // NiTexture
    // void __cdecl NiTexture::*()
    // void __cdecl NiTexture::*(unsigned int)
    // unsigned int __cdecl NiTexture::*()
    // PRIORITY_STATE __cdecl NiTexture::*()
    // void __cdecl NiTexture::*(PRIORITY_STATE)
    // bool __cdecl NiTexture::*(unsigned int)
    // void __cdecl NiTexture::*(unsigned int, bool)
    // bool __cdecl NiTexture::*()
    // void __cdecl NiTexture::*(bool)
    // const NiPixelFormat* __cdecl NiTexture::*()
    // void __cdecl NiTexture::*(NiTexture::RendererData*)
    // void __cdecl NiTexture::*(NiTexture::RendererData*)
    // NiTexture::RendererData* __cdecl NiTexture::*()
    // NiTexture* __cdecl NiTexture::*()
    // NiTexture* __cdecl NiTexture::*()
    // NiTexture* __cdecl NiTexture::*()
    // NiTexture* __cdecl NiTexture::*()
    // void __cdecl NiTexture::*()
    // void __cdecl NiTexture::*()
    // void __cdecl NiTexture::*()
    // void __cdecl NiTexture::*()
    // NiTexture& __cdecl NiTexture::*(const NiTexture&)
    // void __cdecl NiTexture::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTexture) == 48);
FNV_STATIC_ASSERT(offsetof(NiTexture, m_kTextureFormatPreferences) == 24);
FNV_STATIC_ASSERT(offsetof(NiTexture, m_pTextureRendererData) == 36);
FNV_STATIC_ASSERT(offsetof(NiTexture, m_pkPrev) == 40);
FNV_STATIC_ASSERT(offsetof(NiTexture, m_pkNext) == 44);
#endif
