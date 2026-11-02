// Private research declarations for this source unit; not a canonical header.
// PC field layout is supported by the covered instructions and clean JohnnyGuitar
// NiPixelFormat declarations. See identity_review.md for cross-platform limits.
#ifndef FNV_PIXELFORMAT_PC_TYPES_H
#define FNV_PIXELFORMAT_PC_TYPES_H

#include <stddef.h>
#define FNV_PIXELFORMAT_JOIN_(a, b) a##b
#define FNV_PIXELFORMAT_JOIN(a, b) FNV_PIXELFORMAT_JOIN_(a, b)
#define FNV_PIXELFORMAT_ASSERT(x) typedef char FNV_PIXELFORMAT_JOIN(fnv_pixelformat_assert_, __LINE__)[(x) ? 1 : -1]

// Microsoft D3DFORMAT (D3D9Types.h), legacy PC D3D9 values.
// https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dformat
// These are enum/type facts; no renderer implementation was consulted.
enum _D3DFORMAT
{
    D3DFMT_UNKNOWN = 0,
    D3DFMT_R8G8B8 = 20,
    D3DFMT_A8R8G8B8 = 21,
    D3DFMT_X8R8G8B8 = 22,
    D3DFMT_R5G6B5 = 23,
    D3DFMT_X1R5G5B5 = 24,
    D3DFMT_A1R5G5B5 = 25,
    D3DFMT_A4R4G4B4 = 26,
    D3DFMT_R3G3B2 = 27,
    D3DFMT_A8 = 28,
    D3DFMT_A8R3G3B2 = 29,
    D3DFMT_X4R4G4B4 = 30,
    D3DFMT_A2B10G10R10 = 31,
    D3DFMT_A8B8G8R8 = 32,
    D3DFMT_X8B8G8R8 = 33,
    D3DFMT_G16R16 = 34,
    D3DFMT_A2R10G10B10 = 35,
    D3DFMT_A16B16G16R16 = 36,
    D3DFMT_A8P8 = 40,
    D3DFMT_P8 = 41,
    D3DFMT_L8 = 50,
    D3DFMT_A8L8 = 51,
    D3DFMT_A4L4 = 52,
    D3DFMT_V8U8 = 60,
    D3DFMT_L6V5U5 = 61,
    D3DFMT_X8L8V8U8 = 62,
    D3DFMT_Q8W8V8U8 = 63,
    D3DFMT_V16U16 = 64,
    D3DFMT_A2W10V10U10 = 67,
    D3DFMT_D16_LOCKABLE = 70,
    D3DFMT_D32 = 71,
    D3DFMT_D15S1 = 73,
    D3DFMT_D24S8 = 75,
    D3DFMT_D24X8 = 77,
    D3DFMT_D24X4S4 = 79,
    D3DFMT_D16 = 80,
    D3DFMT_L16 = 81,
    D3DFMT_D32F_LOCKABLE = 82,
    D3DFMT_D24FS8 = 83,
    D3DFMT_VERTEXDATA = 100,
    D3DFMT_INDEX16 = 101,
    D3DFMT_INDEX32 = 102,
    D3DFMT_Q16W16V16U16 = 110,
    D3DFMT_R16F = 111,
    D3DFMT_G16R16F = 112,
    D3DFMT_A16B16G16R16F = 113,
    D3DFMT_R32F = 114,
    D3DFMT_G32R32F = 115,
    D3DFMT_A32B32G32R32F = 116,
    D3DFMT_CxV8U8 = 117,
    D3DFMT_UYVY = 0x59565955,
    D3DFMT_R8G8_B8G8 = 0x47424752,
    D3DFMT_YUY2 = 0x32595559,
    D3DFMT_G8R8_G8B8 = 0x42475247,
    D3DFMT_DXT1 = 0x31545844,
    D3DFMT_DXT2 = 0x32545844,
    D3DFMT_DXT3 = 0x33545844,
    D3DFMT_DXT4 = 0x34545844,
    D3DFMT_DXT5 = 0x35545844,
    D3DFMT_MULTI2_ARGB8 = 0x3154454d,
    D3DFMT_FORCE_DWORD = 0x7fffffff,
};
typedef _D3DFORMAT D3DFORMAT;

// PC community declaration: NiMemObject is an empty, non-polymorphic base.
class NiMemObject
{
};

class NiPixelFormat : public NiMemObject
{
  public:
    enum Format
    {
        FORMAT_RGB = 0,
        FORMAT_RGBA = 1,
        FORMAT_PAL = 2,
        FORMAT_PALALPHA = 3,
        FORMAT_DXT1 = 4,
        FORMAT_DXT3 = 5,
        FORMAT_DXT5 = 6,
        FORMAT_RGB24NONINTERLEAVED = 7,
        FORMAT_BUMP = 8,
        FORMAT_BUMPLUMA = 9,
        FORMAT_RENDERERSPECIFIC = 10,
        FORMAT_ONE_CHANNEL = 11,
        FORMAT_TWO_CHANNEL = 12,
        FORMAT_THREE_CHANNEL = 13,
        FORMAT_FOUR_CHANNEL = 14,
        FORMAT_DEPTH_STENCIL = 15,
        FORMAT_UNKNOWN = 16,
        FORMAT_MAX = 17
    };
    enum Component
    {
        COMP_RED = 0,
        COMP_GREEN = 1,
        COMP_BLUE = 2,
        COMP_ALPHA = 3,
        COMP_COMPRESSED = 4,
        COMP_OFFSET_U = 5,
        COMP_OFFSET_V = 6,
        COMP_OFFSET_W = 7,
        COMP_OFFSET_Q = 8,
        COMP_LUMA = 9,
        COMP_HEIGHT = 10,
        COMP_VECTOR_X = 11,
        COMP_VECTOR_Y = 12,
        COMP_VECTOR_Z = 13,
        COMP_PADDING = 14,
        COMP_INTENSITY = 15,
        COMP_INDEX = 16,
        COMP_DEPTH = 17,
        COMP_STENCIL = 18,
        COMP_EMPTY = 19,
        COMP_MAX = 20,
        NUM_COMPS = 4
    };
    enum TextureTileMode
    {
        TILE_NONE = 0,
        TILE_CONSOLE = 1,
        TILE_MAX = 2
    };
    enum Representation
    {
        NORM_INT = 0,
        HALF = 1,
        FLOAT = 2,
        INDEX = 3,
        COMPRESSED = 4,
        UNKNOWN = 5,
        INT = 6,
        COUNT = 7
    };
    class NiComponentSpec
    {
      public:
        Component m_eComponent;
        Representation m_eRepresentation;
        unsigned char m_ucBitsPerComponent;
        bool m_bSigned;
    };

    unsigned char m_uiObjectFlags;
    unsigned char m_ucBitsPerPixel;
    Format m_eFormat;
    TextureTileMode m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    NiComponentSpec m_akComponents[NUM_COMPS];

    // Genuine const declarations; PC targets are qualified caller-derived mappings.
    unsigned int __thiscall GetMask(Component eComponent) const;
    unsigned char __thiscall GetPixelBitData(Component eComponent) const;
};

class NiD3DTextureData : public NiPixelFormat
{
  public:
    // Genuine supplied candidate name. The machine ABI and enum values are PC.
    static D3DFORMAT __cdecl ConvertPixelFormatToD3DFormat(const NiPixelFormat& kPixelFormat);
};

FNV_PIXELFORMAT_ASSERT(sizeof(D3DFORMAT) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiMemObject) == 1);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::Format) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::Component) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::TextureTileMode) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::Representation) == 4);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat::NiComponentSpec) == 12);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_eComponent) == 0);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_eRepresentation) == 4);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_ucBitsPerComponent) == 8);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat::NiComponentSpec, m_bSigned) == 9);
FNV_PIXELFORMAT_ASSERT(sizeof(NiPixelFormat) == 68);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_uiObjectFlags) == 0);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_ucBitsPerPixel) == 1);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_eFormat) == 4);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_eTiling) == 8);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_uiRendererHint) == 12);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_uiExtraData) == 16);
FNV_PIXELFORMAT_ASSERT(offsetof(NiPixelFormat, m_akComponents) == 20);
FNV_PIXELFORMAT_ASSERT(sizeof(NiD3DTextureData) == 68);
#endif
