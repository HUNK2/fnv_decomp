// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIPIXELDATA_H
#define FNV_NIPIXELDATA_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class NiPalette;
class NiPixelData;
class NiPixelFormat;
class NiPixelFormat__NiComponentSpec;
enum NiPixelFormat__Format
{
    NiPixelFormat__Format_FORMAT_RGB = 0,
    NiPixelFormat__Format_FORMAT_RGBA = 1,
    NiPixelFormat__Format_FORMAT_PAL = 2,
    NiPixelFormat__Format_FORMAT_PALALPHA = 3,
    NiPixelFormat__Format_FORMAT_DXT1 = 4,
    NiPixelFormat__Format_FORMAT_DXT3 = 5,
    NiPixelFormat__Format_FORMAT_DXT5 = 6,
    NiPixelFormat__Format_FORMAT_RGB24NONINTERLEAVED = 7,
    NiPixelFormat__Format_FORMAT_BUMP = 8,
    NiPixelFormat__Format_FORMAT_BUMPLUMA = 9,
    NiPixelFormat__Format_FORMAT_RENDERERSPECIFIC = 10,
    NiPixelFormat__Format_FORMAT_ONE_CHANNEL = 11,
    NiPixelFormat__Format_FORMAT_TWO_CHANNEL = 12,
    NiPixelFormat__Format_FORMAT_THREE_CHANNEL = 13,
    NiPixelFormat__Format_FORMAT_FOUR_CHANNEL = 14,
    NiPixelFormat__Format_FORMAT_DEPTH_STENCIL = 15,
    NiPixelFormat__Format_FORMAT_UNKNOWN = 16,
    NiPixelFormat__Format_FORMAT_MAX = 17
};
enum NiPixelFormat__Tiling
{
    NiPixelFormat__Tiling_TILE_NONE = 0,
    NiPixelFormat__Tiling_TILE_CONSOLE = 1,
    NiPixelFormat__Tiling_TILE_MAX = 2
};
enum NiPixelFormat__Component
{
    NiPixelFormat__Component_COMP_RED = 0,
    NiPixelFormat__Component_COMP_GREEN = 1,
    NiPixelFormat__Component_COMP_BLUE = 2,
    NiPixelFormat__Component_COMP_ALPHA = 3,
    NiPixelFormat__Component_COMP_COMPRESSED = 4,
    NiPixelFormat__Component_COMP_OFFSET_U = 5,
    NiPixelFormat__Component_COMP_OFFSET_V = 6,
    NiPixelFormat__Component_COMP_OFFSET_W = 7,
    NiPixelFormat__Component_COMP_OFFSET_Q = 8,
    NiPixelFormat__Component_COMP_LUMA = 9,
    NiPixelFormat__Component_COMP_HEIGHT = 10,
    NiPixelFormat__Component_COMP_VECTOR_X = 11,
    NiPixelFormat__Component_COMP_VECTOR_Y = 12,
    NiPixelFormat__Component_COMP_VECTOR_Z = 13,
    NiPixelFormat__Component_COMP_PADDING = 14,
    NiPixelFormat__Component_COMP_INTENSITY = 15,
    NiPixelFormat__Component_COMP_INDEX = 16,
    NiPixelFormat__Component_COMP_DEPTH = 17,
    NiPixelFormat__Component_COMP_STENCIL = 18,
    NiPixelFormat__Component_COMP_EMPTY = 19,
    NiPixelFormat__Component_COMP_MAX = 20,
    NiPixelFormat__Component_NUM_COMPS = 4
};
enum NiPixelFormat__Representation
{
    NiPixelFormat__Representation_REP_FIXED = 0,
    NiPixelFormat__Representation_REP_HALF = 1,
    NiPixelFormat__Representation_REP_FLOAT = 2,
    NiPixelFormat__Representation_REP_INDEX = 3,
    NiPixelFormat__Representation_REP_COMPRESSED = 4,
    NiPixelFormat__Representation_REP_UNKNOWN = 5,
    NiPixelFormat__Representation_REP_MAX = 6
};
#pragma pack(push, 4)
class NiPixelFormat__NiComponentSpec
{
  public:
    NiPixelFormat__Component m_eComponent;            // +0x0, 4 bytes
    NiPixelFormat__Representation m_eRepresentation;  // +0x4, 4 bytes
    unsigned char m_ucBitsPerComponent;               // +0x8, 1 bytes
    bool m_bSigned;                                   // +0x9, 1 bytes
    unsigned char layoutPaddingA[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPixelFormat__NiComponentSpec) == 12);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat__NiComponentSpec, m_eComponent) == 0);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat__NiComponentSpec, m_eRepresentation) == 4);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat__NiComponentSpec, m_ucBitsPerComponent) == 8);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat__NiComponentSpec, m_bSigned) == 9);
#pragma pack(push, 4)
class NiPixelFormat
{
  public:
    unsigned char m_uiObjectFlags;          // +0x0, 1 bytes
    unsigned char m_ucBitsPerPixel;  // +0x1, 1 bytes
    unsigned char layoutPadding2[2];
    NiPixelFormat__Format m_eFormat;                   // +0x4, 4 bytes
    NiPixelFormat__Tiling m_eTiling;                   // +0x8, 4 bytes
    unsigned int m_uiRendererHint;                     // +0xC, 4 bytes
    unsigned int m_uiExtraData;                        // +0x10, 4 bytes
    NiPixelFormat__NiComponentSpec m_akComponents[4];  // +0x14, 48 bytes
    // void __cdecl NiPixelFormat::*(unsigned char, unsigned char, unsigned char)
    // unsigned char __cdecl NiPixelFormat::*(unsigned char, unsigned char)
    // void __cdecl NiPixelFormat::*(bool, unsigned char)
    // bool __cdecl NiPixelFormat::*(unsigned char)
    // NiPixelFormat
    // NiPixelFormat __cdecl NiPixelFormat::*(unsigned char, unsigned int, unsigned int, unsigned int, unsigned int)
    // NiPixelFormat::Format __cdecl NiPixelFormat::*()
    // unsigned char __cdecl NiPixelFormat::*()
    // unsigned int __cdecl NiPixelFormat::*()
    // unsigned int __cdecl NiPixelFormat::*()
    // bool __cdecl NiPixelFormat::*()
    // void __cdecl NiPixelFormat::*(NiPixelFormat::Format)
    // void __cdecl NiPixelFormat::*(unsigned char)
    // void __cdecl NiPixelFormat::*(unsigned int)
    // void __cdecl NiPixelFormat::*(unsigned int)
    // void __cdecl NiPixelFormat::*(bool)
    // bool __cdecl NiPixelFormat::*(unsigned int, NiPixelFormat::Component&, NiPixelFormat::Representation&, unsigned char&, bool&)
    // void __cdecl NiPixelFormat::*(unsigned int, NiPixelFormat::Component, NiPixelFormat::Representation, unsigned char, bool)
    // unsigned int __cdecl NiPixelFormat::*()
    // bool __cdecl NiPixelFormat::*()
    // bool __cdecl NiPixelFormat::*()
    // bool __cdecl NiPixelFormat::*()
    // unsigned int __cdecl NiPixelFormat::*(NiPixelFormat::Component)
    // unsigned char __cdecl NiPixelFormat::*(NiPixelFormat::Component)
    // unsigned char __cdecl NiPixelFormat::*(NiPixelFormat::Component)
    // unsigned char __cdecl NiPixelFormat::*()
    // bool __cdecl NiPixelFormat::*(const NiPixelFormat&)
    // bool __cdecl NiPixelFormat::*(const NiPixelFormat&)
    // void __cdecl NiPixelFormat::*(NiStream&)
    // void __cdecl NiPixelFormat::*(NiStream&)
    // void __cdecl NiPixelFormat::*(NiPixelFormat::Format, unsigned char, unsigned int*)
    // unsigned int __cdecl NiPixelFormat::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPixelFormat) == 68);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_uiObjectFlags) == 0);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_ucBitsPerPixel) == 1);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_eFormat) == 4);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_eTiling) == 8);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_uiRendererHint) == 12);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_uiExtraData) == 16);
FNV_STATIC_ASSERT(offsetof(NiPixelFormat, m_akComponents) == 20);
#pragma pack(push, 4)
class NiPixelData : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    NiPixelFormat m_kPixelFormat;      // +0x8, 68 bytes
    NiPointer<NiPalette> m_spPalette;  // +0x4C, 4 bytes
    unsigned char* m_pucPixels;        // +0x50, 4 bytes
    unsigned int* m_puiWidth;          // +0x54, 4 bytes
    unsigned int* m_puiHeight;         // +0x58, 4 bytes
    unsigned int* m_puiOffsetInBytes;  // +0x5C, 4 bytes
    unsigned int m_uiMipmapLevels;     // +0x60, 4 bytes
    unsigned int m_uiPixelStride;      // +0x64, 4 bytes
    unsigned int m_uiRevID;            // +0x68, 4 bytes
    unsigned int m_uiFaces;            // +0x6C, 4 bytes
    bool m_bOwnsPixelData;             // +0x70, 1 bytes
    unsigned char layoutPadding71[3];
    // const NiRTTI* __cdecl NiPixelData::*()
    // void __cdecl NiPixelData::*(NiStream&)
    // void __cdecl NiPixelData::*(NiStream&)
    // bool __cdecl NiPixelData::*(NiStream&)
    // void __cdecl NiPixelData::*(NiStream&)
    // bool __cdecl NiPixelData::*(NiObject*)
    // NiObject* __cdecl NiPixelData::*()
    // void __cdecl NiPixelData::*(NiTPrimitiveArray<char *>*)
    // NiPixelData
    // void __cdecl NiPixelData::*()
    // unsigned int __cdecl NiPixelData::*()
    // unsigned int __cdecl NiPixelData::*()
    // unsigned int __cdecl NiPixelData::*(unsigned int, unsigned int)
    // unsigned int __cdecl NiPixelData::*(unsigned int, unsigned int)
    // unsigned int __cdecl NiPixelData::*()
    // unsigned int __cdecl NiPixelData::*(unsigned int, unsigned int)
    // int __cdecl NiPixelData::*(unsigned int, unsigned int)
    // unsigned int __cdecl NiPixelData::*()
    // unsigned int __cdecl NiPixelData::*()
    // const NiPixelFormat& __cdecl NiPixelData::*()
    // void __cdecl NiPixelData::*(NiPalette*)
    // GetPalette
    // GetPixels
    // void __cdecl NiPixelData::*()
    // unsigned int __cdecl NiPixelData::*()
    // operator()
    // unsigned int __cdecl NiPixelData::*(unsigned int, unsigned int)
    // void __cdecl NiPixelData::*(bool)
    // bool __cdecl NiPixelData::*()
    // void __cdecl NiPixelData::*(unsigned int, unsigned int, unsigned int)
    // void __cdecl NiPixelData::*()
    // NiPixelData& __cdecl NiPixelData::*(const NiPixelData&)
    // void __cdecl NiPixelData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPixelData) == 116);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_kPixelFormat) == 8);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_spPalette) == 76);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_pucPixels) == 80);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_puiWidth) == 84);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_puiHeight) == 88);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_puiOffsetInBytes) == 92);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_uiMipmapLevels) == 96);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_uiPixelStride) == 100);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_uiRevID) == 104);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_uiFaces) == 108);
FNV_STATIC_ASSERT(offsetof(NiPixelData, m_bOwnsPixelData) == 112);
#endif
