// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NISOURCETEXTURE_H
#define FNV_NISOURCETEXTURE_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObjectNET.h"
#include "layout_support.h"
class NiPersistentSrcTextureRendererData;
class NiPixelData;
class NiStream;
class NiSourceTexture;
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
    void LoadBinary(NiStream&);
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
#pragma pack(push, 4)
class NiSourceTexture : public NiTexture
{
  public:
    // base NiTexture at +0x0, size 48
    NiFixedString m_pcCacheFileName;                                                  // +0x30, 4 bytes
    NiFixedString m_kDeviceFilename;                                                  // +0x34, 4 bytes
    NiPointer<NiPersistentSrcTextureRendererData> m_spPersistentTextureRendererData;  // +0x38, 4 bytes
    NiPointer<NiPixelData> m_spAppPixelData;                                          // +0x3C, 4 bytes
    bool m_bIsStatic;                                                                 // +0x40, 1 bytes
    bool m_bLoadDirectToRenderer;                                                     // +0x41, 1 bytes
    bool m_bKeepRendererDataPersistent;                                               // +0x42, 1 bytes
    char m_cPixelLayout;                                                              // +0x43, 1 bytes
    NiFile* m_pFile;                                                                  // +0x44, 4 bytes
    NiSourceTexture() throw();
    static NiSourceTexture* Create(const NiFixedString&, NiTexture__FormatPrefs&, bool, bool);
    void DestroyAppPixelData();
    void LoadBinary(NiStream&);
    // const NiRTTI* __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(NiStream&)
    // void __cdecl NiSourceTexture::*(NiStream&)
    // bool __cdecl NiSourceTexture::*(NiStream&)
    // void __cdecl NiSourceTexture::*(NiStream&)
    // bool __cdecl NiSourceTexture::*(NiObject*)
    // NiObject* __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(NiTPrimitiveArray<char *>*)
    // Create
    // NiSourceTexture* __cdecl NiSourceTexture::*(const NiFixedString&)
    // void __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(NiPixelData*)
    // unsigned int __cdecl NiSourceTexture::*()
    // unsigned int __cdecl NiSourceTexture::*()
    // const NiFixedString& __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiSourceTexture::*()
    // GetSourcePixelData
    // GetPersistentSourceRendererData
    // void __cdecl NiSourceTexture::*(NiPersistentSrcTextureRendererData*)
    // void __cdecl NiSourceTexture::*(bool)
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(bool)
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(bool)
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(bool)
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(bool)
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(bool)
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*(NiStream&)
    // NiFile* __cdecl NiSourceTexture::*()
    // bool __cdecl NiSourceTexture::*()
    // bool __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*()
    // void __cdecl NiSourceTexture::*()
    // NiSourceTexture
    // void __cdecl NiSourceTexture::*()
    // NiSourceTexture& __cdecl NiSourceTexture::*(const NiSourceTexture&)
    // void __cdecl NiSourceTexture::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiSourceTexture) == 72);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_pcCacheFileName) == 48);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_kDeviceFilename) == 52);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_spPersistentTextureRendererData) == 56);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_spAppPixelData) == 60);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_bIsStatic) == 64);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_bLoadDirectToRenderer) == 65);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_bKeepRendererDataPersistent) == 66);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_cPixelLayout) == 67);
FNV_STATIC_ASSERT(offsetof(NiSourceTexture, m_pFile) == 68);
#endif
