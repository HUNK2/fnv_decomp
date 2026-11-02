// gamebryo2.2/corelibs/nimain/nipixelformat_decls.h: declares NiPixelFormat, NiComponentSpec
#ifndef FNV_NIPIXELFORMAT_DECLS_H
#define FNV_NIPIXELFORMAT_DECLS_H

// NiPixelFormat: Gamebryo pixel format description.
#include "layout_support.h"

class NiPixelFormat
{
  public:
    enum Format
    {
        FORMAT_RGB = 0,
        FORMAT_RGBA,
        FORMAT_PAL,
        FORMAT_PALALPHA,
        FORMAT_DXT1,
        FORMAT_DXT3,
        FORMAT_DXT5,
        FORMAT_RGB24_NONINTERLEAVED,
        FORMAT_BUMP,
        FORMAT_BUMPLUMA,
        FORMAT_RENDERERSPECIFIC,
        FORMAT_ONE_CHANNEL,
        FORMAT_TWO_CHANNEL,
        FORMAT_THREE_CHANNEL,
        FORMAT_FOUR_CHANNEL,
        FORMAT_DEPTH_STENCIL,
        FORMAT_UNKNOWN,
        FORMAT_MAX
    };

    enum Representation
    {
        REP_FIXED = 0,
        REP_HALF,
        REP_FLOAT,
        REP_INDEX,
        REP_COMPRESSED,
        REP_UNKNOWN,
        REP_MAX
    };

    enum Component
    {
        COMP_RED = 0,
        COMP_GREEN,
        COMP_BLUE,
        COMP_ALPHA,
        COMP_COMPRESSED,
        COMP_OFFSET_U,
        COMP_OFFSET_V,
        COMP_OFFSET_W,
        COMP_OFFSET_Q,
        COMP_LUMA,
        COMP_HEIGHT,
        COMP_VECTOR_X,
        COMP_VECTOR_Y,
        COMP_VECTOR_Z,
        COMP_PADDING,
        COMP_INTENSITY,
        COMP_INDEX,
        COMP_DEPTH,
        COMP_STENCIL,
        COMP_EMPTY,
        COMP_MAX,
        NUM_COMPS = 4
    };

    enum TextureTileMode
    {
        TILE_NONE = 0,
        TILE_CONSOLE,
        TILE_MAX
    };

    struct NiComponentSpec
    {
        Component m_eComponent;
        Representation m_eRepresentation;
        unsigned char m_ucBits;
        bool m_bSigned;
    };

    NiPixelFormat();
    bool operator==(const NiPixelFormat& other) const;
    bool operator!=(const NiPixelFormat& other) const;
    unsigned char GetPixelBitData(Component component) const;

  protected:
    unsigned char m_uiObjectFlags;
    unsigned char m_ucBitsPerPixel;
    Format m_eFormat;
    TextureTileMode m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    NiComponentSpec m_akComponents[NUM_COMPS];
};

FNV_STATIC_ASSERT(sizeof(NiPixelFormat) == 0x44);

#endif
