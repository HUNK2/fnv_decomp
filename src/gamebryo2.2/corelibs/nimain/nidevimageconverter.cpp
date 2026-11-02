// gamebryo2.2/corelibs/nimain/nidevimageconverter.cpp: NiDevImageConverter, Converter, NiDevImageConverterStandIn, ImageConverterBase and more (34 functions)

#include "nidevimageconverter_decls.h"

// @fnv 0x00a7a4f0
bool NiDevImageConverter::ConvertMipLevel(NiPixelData& dst, const NiPixelData& src, int mip)
{
    const NiPixelFormat& sf = src.m_kPixelFormat;
    const NiPixelFormat& df = dst.m_kPixelFormat;
    if (src.GetWidth() != dst.GetWidth() || src.GetHeight() != dst.GetHeight())
        return false;
    unsigned faces = src.m_uiFaces;
    if (faces != dst.m_uiFaces)
        return false;
    unsigned uiFirstLevel, uiLastLevel;
    if (mip == -1)
    {
        uiLastLevel = dst.m_uiMipmapLevels;
        if (src.m_uiMipmapLevels < uiLastLevel)
            return false;
        uiFirstLevel = 0;
        --uiLastLevel;
    }
    else
    {
        if ((unsigned)mip >= src.m_uiMipmapLevels || (unsigned)mip >= dst.m_uiMipmapLevels)
            return false;
        uiFirstLevel = uiLastLevel = mip;
    }
    if (sf == df)
    {
        for (unsigned face = 0; face < faces; ++face)
            for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
        if (src.m_spPalette)
        {
            if (!dst.m_spPalette)
                dst.FUN_00a76a60(new NiPalette(*src.m_spPalette));
            else
                dst.m_spPalette->FUN_00a8b190(*src.m_spPalette);
        }
        return true;
    }
    int dstFormat = df.m_eFormat;
    int srcFormat = sf.m_eFormat;
    unsigned dstBpp = df.m_ucBitsPerPixel;
    unsigned srcBpp = sf.m_ucBitsPerPixel;
    PixelFormatBitLayout dstBits(df), srcBits(sf);
    if (dstFormat == 4 || dstFormat == 5 || dstFormat == 6)
        return false;
    if (dstBpp == 24 &&
        (dstBits.m_uiGreenMask != 0xff00 || (dstBits.m_uiRedMask != 0xff && dstBits.m_uiRedMask != 0xff0000)))
        return false;
    PixelConvertFunc convert;
    if (sf == DAT_011aa180)
    {
        if (!src.m_spPalette)
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 24)
                convert = Convert4BitPalettedTo24Bit;
            else if (dstBpp == 32)
                convert = ExpandPalettedImage;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa1c8))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.m_spPalette)
                return false;
            if (!dst.m_spPalette)
                dst.FUN_00a76a60(new NiPalette(*src.m_spPalette));
            else
                dst.m_spPalette->FUN_00a8b190(*src.m_spPalette);
            NiPalette* palette = dst.m_spPalette;
            NiPalette::PaletteColorEntry* entries;
            unsigned paletteCount = palette->GetEntries(entries);
            for (unsigned entry = 0; entry < paletteCount; ++entry)
                entries->a = 255;
            return true;
        }
    }
    else if (sf == DAT_011aa1c8)
    {
        if (!src.m_spPalette)
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 24)
                convert = Convert4BitPalettedTo24Bit;
            else if (dstBpp == 32)
                convert = FUN_00a79310;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa180))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.m_spPalette)
                return false;
            unsigned paletteCount;
            dst.FUN_00a76a60(new NiPalette(false, 16, src.GetPalette()->GetEntries(paletteCount)));
            return true;
        }
    }
    else if (sf == DAT_011aa210)
    {
        if (!src.m_spPalette)
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 16)
                convert = ConvertPaletteTo16Bit;
            else if (dstBpp == 24)
                convert = FUN_00a79e20;
            else if (dstBpp == 32)
                convert = FUN_00a798c0;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa258))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.m_spPalette)
                return false;
            if (!dst.m_spPalette)
                dst.FUN_00a76a60(new NiPalette(*src.m_spPalette));
            else
                dst.m_spPalette->FUN_00a8b190(*src.m_spPalette);
            NiPalette* palette = dst.m_spPalette;
            NiPalette::PaletteColorEntry* entries;
            unsigned paletteCount = palette->GetEntries(entries);
            for (unsigned entry = 0; entry < paletteCount; ++entry)
                entries->a = 255;
            return true;
        }
    }
    else if (sf == DAT_011aa258)
    {
        if (!src.m_spPalette)
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 16)
                convert = FUN_00a79ae0;
            else if (dstBpp == 24)
                convert = FUN_00a79e20;
            else if (dstBpp == 32)
                convert = ConvertPalettizedToFormat;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa210))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.m_spPalette)
                return false;
            unsigned paletteCount;
            dst.FUN_00a76a60(new NiPalette(false, 256, src.GetPalette()->GetEntries(paletteCount)));
            return true;
        }
    }
    else if (sf == DAT_011aa2e8)
    {
        if (!(dstFormat == 0 || dstFormat == 1))
            return false;
        if (dstBpp == 16)
            convert = ConvertPixelsTo16Bit;
        else if (dstBpp == 24)
            convert = FUN_00a7a160;
        else if (dstBpp == 32)
            convert = ConvertRGBToFormat;
        else
            return false;
    }
    else if (sf == SOURCE_FORMAT_RGB)
    {
        if (!(dstFormat == 0 || dstFormat == 1))
            return false;
        if (dstBpp == 16)
            convert = ConvertRGBAToPacked;
        else if (dstBpp == 24)
            convert = FUN_00a77110;
        else if (dstBpp == 32)
            convert = FUN_00a771d0;
        else
            return false;
    }
    else if (sf == DAT_011aa408)
    {
        if (!(dstFormat == 8 || dstFormat == 9))
            return false;
        if (dstBpp == 16)
            convert = FUN_00a77880;
        else if (dstBpp == 32)
            convert = FUN_00a77800;
        else
            return false;
    }
    else if (sf == DAT_011aa450)
    {
        if (!(dstFormat == 8 || dstFormat == 9))
            return false;
        if (dstBpp == 16)
            convert = ConvertRgbToPacked16;
        else if (dstBpp == 32)
            convert = FUN_00a776b0;
        else
            return false;
    }
    else if (sf == DAT_011aa330 && df == DAT_011aa3c0)
        convert = FUN_00a76d70;
    else if (sf == DAT_011aa3c0 && df == DAT_011aa330)
        convert = FUN_00a76e90;
    else
    {
        if (srcFormat != 0 && srcFormat != 1)
            return false;
        if (df == SOURCE_FORMAT_RGB)
        {
            if (srcBpp == 16)
            {
                if (srcBits.m_uiAlphaMask)
                    convert = ConvertPixelsToBytes;
                else
                    convert = FUN_00a773d0;
            }
            else if (srcBpp == 24)
                convert = ConvertRgbToRgba;
            else if (srcBpp == 32)
            {
                if (srcBits.m_uiAlphaMask)
                    convert = ConvertPixelFormat;
                else
                    convert = ConvertPackedPixelsToRGBA;
            }
            else
                return false;
        }
        else if (df == DAT_011aa2e8)
        {
            if (srcBpp == 16)
                convert = UnpackPixels;
            else if (srcBpp == 24)
                convert = FUN_00a7a1f0;
            else if (srcBpp == 32)
                convert = ConvertPixelsToRgb;
            else
                return false;
        }
        else
            return false;
    }
    for (unsigned face = 0; face < faces; ++face)
        for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
            convert(dst.m_puiWidth[level], dst.m_puiHeight[level], dst.GetSizeInBytes(level),
                    dst.GetPixels(level, face), src.m_spPalette, dstBits, src.GetPixels(level, face), srcBits);
    return true;
}

// Checks whether a source NiPixelFormat can be converted to a destination NiPixelFormat, validating endianness, compression, bit depth and format pairs.
// @fnv 0x00a77e40
bool NiDevImageConverter::CanConvertPixelFormat(const NiPixelFormat& sf, const NiPixelFormat& df)
{
    NiPixelFormat::Format dstFormat = df.GetFormat();
    unsigned dstBpp = df.GetBitsPerPixel();
    PixelFormatBitLayout bits(df);
    if (sf == df)
        return true;
    if (!sf.GetLittleEndian() || !df.GetLittleEndian() || df.IsCompressed())
        return false;
    if (dstBpp == 24 && (bits.m_uiGreenMask != 0xff00 || (bits.m_uiRedMask != 0xff && bits.m_uiRedMask != 0xff0000)))
        return false;
    if (sf == DAT_011aa180 || sf == DAT_011aa1c8)
    {
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else if (df != DAT_011aa180 && df != DAT_011aa1c8)
            return false;
    }
    else if (sf == DAT_011aa210 || sf == DAT_011aa258)
    {
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp != 16 && dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else if (df != DAT_011aa210 && df != DAT_011aa258)
            return false;
    }
    else if (sf == DAT_011aa2e8 || sf == SOURCE_FORMAT_RGB || sf.IsField4InRange())
    {
        if (dstFormat == 0 || dstFormat == 1 || dstFormat == 8 || dstFormat == 9)
        {
            if (dstBpp != 16 && dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else
            return false;
    }
    else if (sf == DAT_011aa408 || sf == DAT_011aa450)
    {
        if (dstFormat == 8 || dstFormat == 9)
        {
            if (dstBpp != 16 && dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else
            return false;
    }
    else if (sf == DAT_011aa330 || sf == DAT_011aa3c0)
    {
        if (dstBpp != 16)
            return false;
    }
    else
        return false;
    return true;
}

// @fnv 0x00a78050
bool NiDevImageConverter::IsSupportedSourceFormat(const NiPixelFormat& format)
{
    if (format == DAT_011aa180 || format == DAT_011aa210 || format == DAT_011aa2e8)
        return true;
    return false;
}

// @fnv 0x00a78010
bool NiDevImageConverter::IsSupportedDestinationFormat(const NiPixelFormat& format)
{
    if (format == DAT_011aa1c8 || format == DAT_011aa258 || format == SOURCE_FORMAT_RGB)
        return true;
    return false;
}

struct FUN_00a78630_shell : public NiDevImageConverter
{
    void* SelectPlatformFormat(int, void*, void*, void*);
};

// Dispatches on ePlatform: returns gNiPoint3StartupSrc or kDesiredFmt for case 0, calls virtual slots 18-20 for platforms 6/4/5, else returns 0.
// @fnv 0x00a78630
void* FUN_00a78630_shell::SelectPlatformFormat(int ePlatform, void* kFmtPrefs, void* kSrcFmt, void* kDesiredFmt)
{
    typedef void*(__thiscall * VFn)(void*, void*, void*, void*);

    switch (ePlatform)
    {
    case 0:
        if ((*(int*)((char*)kDesiredFmt + 4) == 2 || *(int*)((char*)kDesiredFmt + 4) == 3 ||
             *(unsigned char*)((char*)kDesiredFmt + 1) == 16) &&
            *(int*)kFmtPrefs == 4)
        {
            return &gNiPoint3StartupSrc;
        }
        return kDesiredFmt;
    case 6:
        return ((VFn)(*(void***)this)[18])(this, kFmtPrefs, kSrcFmt, kDesiredFmt);
    case 4:
        return ((VFn)(*(void***)this)[19])(this, kFmtPrefs, kSrcFmt, kDesiredFmt);
    case 5:
        return ((VFn)(*(void***)this)[20])(this, kFmtPrefs, kSrcFmt, kDesiredFmt);
    default:
        return 0;
    }
}

struct FUN_00a7aff0_shell : public NiDevImageConverter
{
    void FUN_00a7aff0();
};

struct RecursiveSpinLock
{
    int value;
    void Lock(char const*);
};

template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* next;
        LinkedListEntry* prev;
        void* data;
    };
    static LinkedListEntry* ms_pFreeList;
};

struct BSShaderLightingProperty
{
    void ClearLights();
};

struct NiD3DDefaultShader
{
    static void __cdecl SetShaderName(char const*);
};

extern int DAT_0109d9c4;
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
void __fastcall FUN_00a76680(void* pThis);

struct VirtualObj_00a7aff0
{
    virtual ~VirtualObj_00a7aff0();
};

struct Obj_00a7aff0
{
    void* vftable;
    char pad0[0x77c];
    char field_780[0x210];
    PoolAllocatorBase<unsigned int>::LinkedListEntry* head;  // +0x990
    PoolAllocatorBase<unsigned int>::LinkedListEntry* tail;  // +0x994
    unsigned int count;                                       // +0x998
};

// @fnv 0x00a7aff0
void FUN_00a7aff0_shell::FUN_00a7aff0()
{
    Obj_00a7aff0* self = (Obj_00a7aff0*)this;
    self->vftable = &DAT_0109d9c4;
    while (self->count)
    {
        PoolAllocatorBase<unsigned int>::LinkedListEntry* node = self->head;
        self->head = node->next;
        if (self->head)
        {
            self->head->prev = 0;
        }
        else
        {
            self->tail = 0;
        }
        VirtualObj_00a7aff0* entry = (VirtualObj_00a7aff0*)node->data;
        node->data = 0;
        g_011c5f80.Lock(0);
        node->prev = 0;
        node->next = PoolAllocatorBase<unsigned int>::ms_pFreeList;
        PoolAllocatorBase<unsigned int>::ms_pFreeList = node;
        if (--DAT_011c5f84 == 0)
        {
            g_011c5f80.value = 0;
        }
        --self->count;
        if (entry)
        {
            delete entry;
        }
    }
    ((BSShaderLightingProperty*)&self->head)->ClearLights();
    typedef void(__fastcall * InitCapsFn)(void*);
    ((InitCapsFn)&NiD3DDefaultShader::SetShaderName)(&self->field_780);
    FUN_00a76680(self);
}

struct FUN_00a77940_shell
{
    int m_iWordAt00;
    int m_iWordAt04;
    int FUN_00a77940();
};

// @fnv 0x00a77940
int FUN_00a77940_shell::FUN_00a77940()
{
    if (m_iWordAt04 == 2 || m_iWordAt04 == 3)
        return 1;
    return 0;
}

struct FUN_00a7b0a0_shell : public NiDevImageConverter
{
    void* FUN_00a7b0a0();
};

// @fnv 0x00a7b0a0
void* FUN_00a7b0a0_shell::FUN_00a7b0a0()
{
    return (char*)this + 0x990;
}

// @fnv 0x00a79e20
void __cdecl FUN_00a79e20(unsigned int width, unsigned int height, unsigned int, unsigned char* dst, void* tableSrc,
                          void* codeSrc, const unsigned char* src)
{
    unsigned char* table = *(unsigned char**)((unsigned char*)tableSrc + 0x14);
    unsigned int* codePtr = (unsigned int*)codeSrc;
    if (codePtr[1] != 0xff00)
        return;
    unsigned int code = codePtr[0];
    if (code == 0xff)
    {
        if (height <= 0)
            return;
        unsigned int uiRows = height;
        do
        {
            if (width <= 0)
                continue;
            unsigned int uiCols = width;
            do
            {
                *dst = table[*src * 4];
                ++dst;
                *dst = table[*src * 4 + 1];
                ++dst;
                *dst = table[*src * 4 + 2];
                ++dst;
                ++src;
            } while (--uiCols != 0);
        } while (--uiRows != 0);
    }
    else if (code == 0x00ff0000)
    {
        if (height <= 0)
            return;
        unsigned int uiRows = height;
        do
        {
            if (width <= 0)
                continue;
            unsigned int uiCols = width;
            do
            {
                *dst = table[*src * 4 + 2];
                ++dst;
                *dst = table[*src * 4 + 1];
                ++dst;
                *dst = table[*src * 4];
                ++dst;
                ++src;
            } while (--uiCols != 0);
        } while (--uiRows != 0);
    }
}

struct FUN_00a77980_shell
{
    unsigned char FUN_00a77980(int value);
};

// Scans four int entries at offset 0x14 for value and returns the byte at offset 0x1c + i*12 for the matching entry, else 0.
// @fnv 0x00a77980
unsigned char FUN_00a77980_shell::FUN_00a77980(int value)
{
    unsigned int i = 0;
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14);
    while (i < 4)
    {
        if (*p == value)
        {
            return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1c + i * 12);
        }
        ++i;
        p += 3;
    }
    return 0;
}

struct NiImageReader
{
};

struct NodePoolView
{
    void* AddHead(void);
};

struct FUN_00a7b0b0_shell
{
    void __thiscall PushImageReaderNode(NiImageReader* pkReader);
};

// Allocates a node from the pool at self+0x998, stores pkReader at offset 8, and links the node into the list at self+0x990/0x994.
// @fnv 0x00a7b0b0
void __thiscall FUN_00a7b0b0_shell::PushImageReaderNode(NiImageReader* pkReader)
{
    char* self = (char*)this;
    NodePoolView* pool = (NodePoolView*)(self + 0x998);
    void* node = pool->AddHead();
    *(NiImageReader**)((char*)node + 8) = pkReader;
    *(void**)((char*)node + 4) = 0;
    void* head = *(void**)(self + 0x990);
    *(void**)node = head;
    head = *(void**)(self + 0x990);
    if (head)
    {
        *(void**)((char*)head + 4) = node;
        ++*(unsigned int*)(self + 0x998);
        *(void**)(self + 0x990) = node;
    }
    else
    {
        ++*(unsigned int*)(self + 0x998);
        *(void**)(self + 0x994) = node;
        *(void**)(self + 0x990) = node;
    }
}

namespace fnv_00a7b260 {
struct FUN_00a7aff0_shell
{
    void FUN_00a7aff0();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a7aff0, then deletes this with size 0xA00 when bit 0 of a is set, and returns this.
// @fnv 0x00a7b260
void* FUN_00a7aff0_shell::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00a7aff0();
    if (auiFlags & 1)
        _delete(this, 0xA00);
    return this;
}
}  // namespace fnv_00a7b260

struct PalEntry_a79ef0
{
    unsigned char r, g, b, a;
};
struct Palette_a79ef0
{
    char pad[0x14];
    PalEntry_a79ef0* m_pkEntryArray;
};
struct Format_a79ef0
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShl[4];
    unsigned char m_aucShr[4];
};

// Builds a 256-entry table mapping palette RGBA through the format's shift/mask fields, then writes one converted pixel per source byte into pDst.
// @fnv 0x00a79ef0
void __cdecl ConvertPalettizedToFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused,
                                       unsigned int* pDst, Palette_a79ef0* pkPalette, Format_a79ef0* pkFormat,
                                       const unsigned char* pSrc)
{
    unsigned int auiTable[256];
    PalEntry_a79ef0* pkEntries = pkPalette->m_pkEntryArray;
    for (unsigned int i = 0; i < 256; i++)
    {
        auiTable[i] =
            (((unsigned int)pkEntries[i].r >> pkFormat->m_aucShr[0]) << pkFormat->m_aucShl[0]) &
                pkFormat->m_auiMask[0] |
            (((unsigned int)pkEntries[i].g >> pkFormat->m_aucShr[1]) << pkFormat->m_aucShl[1]) &
                pkFormat->m_auiMask[1] |
            (((unsigned int)pkEntries[i].b >> pkFormat->m_aucShr[2]) << pkFormat->m_aucShl[2]) &
                pkFormat->m_auiMask[2] |
            (((unsigned int)pkEntries[i].a >> pkFormat->m_aucShr[3]) << pkFormat->m_aucShl[3]) & pkFormat->m_auiMask[3];
    }
    unsigned int* puiDst = pDst;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *puiDst++ = auiTable[*pSrc++];
        }
    }
}

void* _NiMalloc(unsigned int);
void _NiFree(void*);
extern int DAT_00ff0000;

struct FUN_00a78f70_PalEntry
{
    unsigned char r, g, b, a;
};
struct FUN_00a78f70_Pal
{  // NiPalette
    virtual ~FUN_00a78f70_Pal();
    unsigned int m_uiRefCount;  // +04
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00a78f70_PalEntry* entries;  // +14
};
struct FUN_00a78f70_Fmt
{
    unsigned int mask0;
    unsigned int mask1;
};

// @fnv 0x00a78f70
void Convert4BitPalettedTo24Bit(unsigned int width, unsigned int height, unsigned int unused, unsigned char* dst,
                                FUN_00a78f70_Pal* pal, FUN_00a78f70_Fmt* fmt, unsigned char* src)
{
    FUN_00a78f70_PalEntry* entries = pal->entries;
    if (fmt->mask1 != 0xff00)
        return;
    unsigned char* p = (unsigned char*)_NiMalloc(width * height);
    unsigned char* pTempBuffer = p;
    for (unsigned int i = 0; i < width / 2 * height; i++)
    {
        *p++ = src[i] >> 4;
        *p++ = src[i] & 0xf;
    }
    unsigned char* pRead = pTempBuffer;
    if (fmt->mask0 == 0xff)
    {
        for (unsigned int y = 0; y < height; y++)
        {
            for (unsigned int x = 0; x < width; x++)
            {
                *dst++ = entries[*pRead].r;
                *dst++ = entries[*pRead].g;
                *dst++ = entries[*pRead].b;
                pRead++;
            }
        }
    }
    else if (fmt->mask0 == (unsigned int)&DAT_00ff0000)
    {
        for (unsigned int y = 0; y < height; y++)
        {
            for (unsigned int x = 0; x < width; x++)
            {
                *dst++ = entries[*pRead].b;
                *dst++ = entries[*pRead].g;
                *dst++ = entries[*pRead].r;
                pRead++;
            }
        }
    }
    _NiFree(pTempBuffer);
}

struct NiPixelFormatMaskView
{
    unsigned int GetMask(int) const;
    unsigned char GetPixelBitData(int) const;
};

static inline unsigned char FindComponentBits(const NiPixelFormat* kFmt, int kind)
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (kFmt->m_akComponents[i].kind == kind)
        {
            return kFmt->m_akComponents[i].bits;
        }
    }
    return 0;
}

struct FUN_00a779b0
{
    unsigned int m_uiMasks[4];
    unsigned char m_ucBits[4];
    unsigned char m_ucShifts[4];

    FUN_00a779b0(const NiPixelFormat* kFmt);
};

// Builds per-component masks, bit counts and 8-minus-bits shifts from a NiPixelFormat for all four components.
// @fnv 0x00a779b0
FUN_00a779b0::FUN_00a779b0(const NiPixelFormat* kFmt)
{
    const NiPixelFormatMaskView* maskView = reinterpret_cast<const NiPixelFormatMaskView*>(kFmt);

    m_uiMasks[0] = maskView->GetMask(0);
    m_ucBits[0] = maskView->GetPixelBitData(0);
    m_ucShifts[0] = 8 - FindComponentBits(kFmt, 0);

    m_uiMasks[1] = maskView->GetMask(1);
    m_ucBits[1] = maskView->GetPixelBitData(1);
    m_ucShifts[1] = 8 - FindComponentBits(kFmt, 1);

    m_uiMasks[2] = maskView->GetMask(2);
    m_ucBits[2] = maskView->GetPixelBitData(2);
    m_ucShifts[2] = 8 - FindComponentBits(kFmt, 2);

    m_uiMasks[3] = maskView->GetMask(3);
    m_ucBits[3] = maskView->GetPixelBitData(3);
    m_ucShifts[3] = 8 - FindComponentBits(kFmt, 3);
}

struct FormatPrefs_a78a50
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};

struct PixelFormatQuery_a78a50 : public NiPixelFormat
{
    bool IsPalettizedFmt() const;
    unsigned char GetComponentBits(int kind) const;
};

extern const NiPixelFormat g_kFmtDXT1_a78a50;
extern const NiPixelFormat g_kFmtDXT3_a78a50;
extern const NiPixelFormat g_kFmtDXT5_a78a50;
extern const NiPixelFormat g_kFmtRGBA128_a78a50;
extern const NiPixelFormat g_kFmtRGBA64_a78a50;
extern const NiPixelFormat g_kFmtRGBA16_a78a50;
extern const NiPixelFormat g_kFmtRGB16_a78a50;
extern const NiPixelFormat g_kFmtDefault_a78a50;

static inline unsigned char FindAlphaBits_a78a50(const NiPixelFormat& kFmt)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        if (kFmt.m_akComponents[i].kind == 3)
            return kFmt.m_akComponents[i].bits;
    }
    return 0;
}

static inline bool IsPal_a78a50(const NiPixelFormat& kFmt)
{
    return kFmt.m_eFormat == NiPixelFormat::FORMAT_PAL || kFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA;
}

// @fnv 0x00a78a50
const NiPixelFormat* __stdcall FUN_00a78a50(const FormatPrefs_a78a50& kPrefs, const NiPixelFormat& kSrcFmt,
                                            const NiPixelFormat& kDestFmt)
{
    bool bAlpha;
    if (IsPal_a78a50(kSrcFmt))
        bAlpha = (kSrcFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA);
    else
        bAlpha = FindAlphaBits_a78a50(kSrcFmt) > 0;
    if (kSrcFmt.IsCompressed())
        bAlpha = true;

    int eLayout = kPrefs.m_ePreferredPixelLayout;
    if (eLayout == 14)
        return &g_kFmtRGBA128_a78a50;
    if (eLayout == 13)
        return &g_kFmtRGBA64_a78a50;
    if (eLayout == 12)
        return &g_kFmtRGBA64_a78a50;
    if (eLayout == 1)
    {
        return bAlpha ? &g_kFmtRGBA16_a78a50 : &g_kFmtRGB16_a78a50;
    }
    if (eLayout == 0 || eLayout == 5)
    {
        if (kPrefs.m_eAlphaFormat == 2)
            return &g_kFmtDXT5_a78a50;
        return &g_kFmtDXT1_a78a50;
    }
    if (eLayout == 3)
    {
        int eDestFormat = kDestFmt.m_eFormat;
        if (eDestFormat == NiPixelFormat::FORMAT_DXT1)
            return &g_kFmtDXT1_a78a50;
        if (eDestFormat == NiPixelFormat::FORMAT_DXT3)
            return &g_kFmtDXT3_a78a50;
        if (eDestFormat == NiPixelFormat::FORMAT_DXT5)
            return &g_kFmtDXT5_a78a50;
        if (kPrefs.m_eAlphaFormat == 2)
            return &g_kFmtDXT5_a78a50;
        return &g_kFmtDXT1_a78a50;
    }
    if (eLayout == 6)
    {
        const PixelFormatQuery_a78a50& kDest = static_cast<const PixelFormatQuery_a78a50&>(kDestFmt);
        if (kDest.IsField4InRange() || kDest.IsPalettizedFmt())
        {
            int eDestFormat = kDestFmt.m_eFormat;
            if (eDestFormat == NiPixelFormat::FORMAT_DXT1)
                return &g_kFmtDXT1_a78a50;
            if (eDestFormat == NiPixelFormat::FORMAT_DXT3)
                return &g_kFmtDXT3_a78a50;
            if (eDestFormat == NiPixelFormat::FORMAT_DXT5)
                return &g_kFmtDXT5_a78a50;
            if (kPrefs.m_eAlphaFormat == 2)
                return &g_kFmtDXT5_a78a50;
            return &g_kFmtDXT1_a78a50;
        }
        if (kDestFmt.m_ucBitsPerPixel == 16)
        {
            bool bDestAlpha;
            if (kDest.IsPalettizedFmt())
                bDestAlpha = (kDestFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA);
            else
                bDestAlpha = kDest.GetComponentBits(3) > 0;
            if (kDest.IsField4InRange())
                bDestAlpha = true;

            int iAlphaMode = kPrefs.m_eAlphaFormat;
            bool bUseAlpha = (iAlphaMode == 1 || iAlphaMode == 2 || (iAlphaMode != 0 && bDestAlpha));
            if (bUseAlpha)
                return &g_kFmtRGBA16_a78a50;
            return &g_kFmtRGB16_a78a50;
        }
    }
    return &g_kFmtDefault_a78a50;
}

struct PalEntry_a798c0
{
    unsigned char r, g, b, a;
};
struct Palette_a798c0
{
    void* vftable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    PalEntry_a798c0* m_pkEntryArray;
};
struct Format_a798c0
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShl[4];
    unsigned char m_aucShr[4];
};

// Builds a 256-entry lookup table from the palette using the format masks/shifts, then converts the source indices into destination pixels.
// @fnv 0x00a798c0
void __cdecl FUN_00a798c0(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned int* pDst,
                          Palette_a798c0* pkPalette, Format_a798c0* pkFormat, const unsigned char* pSrc)
{
    unsigned int auiTable[256];
    PalEntry_a798c0* pkEntries = pkPalette->m_pkEntryArray;
    for (unsigned int i = 0; i < 256; i++)
        auiTable[i] = (((0xffu >> pkFormat->m_aucShr[3]) << pkFormat->m_aucShl[3]) & pkFormat->m_auiMask[3]) |
                      (((pkEntries[i].b >> pkFormat->m_aucShr[2]) << pkFormat->m_aucShl[2]) & pkFormat->m_auiMask[2]) |
                      (((pkEntries[i].g >> pkFormat->m_aucShr[1]) << pkFormat->m_aucShl[1]) & pkFormat->m_auiMask[1]) |
                      (((pkEntries[i].r >> pkFormat->m_aucShr[0]) << pkFormat->m_aucShl[0]) & pkFormat->m_auiMask[0]);
    unsigned int* pDstPixel = pDst;
    for (unsigned int y = 0; y < uiHeight; y++)
        for (unsigned int x = 0; x < uiWidth; x++)
            *pDstPixel++ = auiTable[*pSrc++];
}

void strcpy_s(char* dst, unsigned int size, const char* src);
void _fnv_StandardizeFilePath(char* path);

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };
    virtual ~NiFile();
    virtual operator bool() const;
    static NiFile* GetFile(const char* pcName, OpenMode eMode, unsigned int uiBufferSize);
};

struct NiFilename_a77d10
{
    char m_acDriveLetter[3];
    char m_acFolderPath[256];
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acPlatformSubDir[256];
    NiFilename_a77d10(const char* pcFullPath);
    const char* GetExt() const
    {
        return m_acExtension;
    }
};

struct ImageReader_a77d10
{
    virtual ~ImageReader_a77d10();
    virtual bool IsExtensionSupported(const char* pcExt) const;
    virtual NiPixelData* ReadFile(NiFile& kIst, NiPixelData* pkOptDest);
};

struct ReaderNode_a77d10
{
    ReaderNode_a77d10* m_pkNext;
    ReaderNode_a77d10* m_pkPrev;
    ImageReader_a77d10* m_element;
};

struct ImageConverter_a77d10 : public NiDevImageConverter
{
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    ReaderNode_a77d10* m_pkHead;
    static ImageReader_a77d10* const& GetNext(ReaderNode_a77d10*& pkPos)
    {
        ImageReader_a77d10* const& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return element;
    }
    NiPixelData* FUN_00a77d10(const char* pcFilename, NiPixelData* pkOptDest, NiFile* pkIstr);
};

// @fnv 0x00a77d10
NiPixelData* ImageConverter_a77d10::FUN_00a77d10(const char* pcFilename, NiPixelData* pkOptDest, NiFile* pkIstr)
{
    ReaderNode_a77d10* pkPos = m_pkHead;
    char acStandardFilename[260];
    strcpy_s(acStandardFilename, 260, pcFilename);
    _fnv_StandardizeFilePath(acStandardFilename);
    NiFilename_a77d10 kFileName(acStandardFilename);

    while (pkPos)
    {
        ImageReader_a77d10* pkReader = GetNext(pkPos);
        if (pkReader->IsExtensionSupported(kFileName.GetExt()))
        {
            NiFile* pkFile = pkIstr ? pkIstr : NiFile::GetFile(acStandardFilename, NiFile::READ_ONLY, 0x8000);
            if (!pkFile || !(*pkFile))
            {
                delete pkFile;
                return 0;
            }
            NiPixelData* pkData = pkReader->ReadFile(*pkFile, pkOptDest);
            if (pkData)
            {
                delete pkFile;
                return pkData;
            }
            if (!pkIstr)
                delete pkFile;
        }
    }
    delete pkIstr;
    return 0;
}

struct FormatPrefs_a786e0
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};
struct PixelFormat_a786e0 : NiPixelFormat
{
    bool FUN_00a77940() const;
};
extern const NiPixelFormat DAT_011aad98;
extern const NiPixelFormat DAT_011aa768;
extern const NiPixelFormat DAT_011aa6d8;
extern const NiPixelFormat DAT_011aa600;
extern const NiPixelFormat DAT_011aa648;
extern const NiPixelFormat DAT_011aa690;
extern const NiPixelFormat DAT_011aa570;
extern const NiPixelFormat DAT_011aa5b8;
extern const NiPixelFormat DAT_011aab58;
extern const NiPixelFormat DAT_011aaac8;
extern const NiPixelFormat DAT_011aa960;
extern const NiPixelFormat DAT_011aa9f0;
extern const NiPixelFormat DAT_011aa8d0;
extern const NiPixelFormat DAT_011aa498;
extern const NiPixelFormat DAT_011aa4e0;
extern const NiPixelFormat DAT_011aa528;

// @fnv 0x00a786e0
const NiPixelFormat* __stdcall FUN_00a786e0(const FormatPrefs_a786e0& prefs, const NiPixelFormat& src,
                                            const NiPixelFormat& dest)
{
    if (prefs.m_ePreferredPixelLayout == 7)
    {
        if (prefs.m_eAlphaFormat == 0)
            return &DAT_011aad98;
        return &DAT_011aa768;
    }
    if (prefs.m_ePreferredPixelLayout == 8)
        return &DAT_011aa6d8;
    if (prefs.m_ePreferredPixelLayout == 9)
        return &DAT_011aa600;
    if (prefs.m_ePreferredPixelLayout == 10)
        return &DAT_011aa648;
    if (prefs.m_ePreferredPixelLayout == 11)
        return &DAT_011aa690;
    if (prefs.m_ePreferredPixelLayout == 14)
        return &DAT_011aa570;
    if (prefs.m_ePreferredPixelLayout == 13)
        return &DAT_011aa5b8;
    if (prefs.m_ePreferredPixelLayout == 12)
        return &DAT_011aa5b8;
    if (prefs.m_ePreferredPixelLayout == 2)
    {
        if (prefs.m_eAlphaFormat == 0)
            return &DAT_011aab58;
        return &DAT_011aaac8;
    }
    if (prefs.m_ePreferredPixelLayout == 1)
    {
        if (prefs.m_eAlphaFormat == 1)
            return &DAT_011aa960;
        if (prefs.m_eAlphaFormat == 2)
            return &DAT_011aa9f0;
        return &DAT_011aa8d0;
    }
    if (prefs.m_ePreferredPixelLayout == 0 || prefs.m_ePreferredPixelLayout == 5)
    {
        if (prefs.m_eAlphaFormat == 2)
            return &DAT_011aa528;
        return &DAT_011aa498;
    }
    if (prefs.m_ePreferredPixelLayout == 3)
    {
        if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT1)
            return &DAT_011aa498;
        if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT3)
            return &DAT_011aa4e0;
        if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT5)
            return &DAT_011aa528;
        if (prefs.m_eAlphaFormat == 2)
            return &DAT_011aa528;
        return &DAT_011aa498;
    }
    if (prefs.m_ePreferredPixelLayout == 4)
        return &DAT_011aa450;
    if (prefs.m_ePreferredPixelLayout == 6)
    {
        if (dest.IsField4InRange() || static_cast<const PixelFormat_a786e0&>(dest).FUN_00a77940())
        {
            if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT1)
                return &DAT_011aa498;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT3)
                return &DAT_011aa4e0;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT5)
                return &DAT_011aa528;
            if (prefs.m_eAlphaFormat == 2)
                return &DAT_011aa528;
            return &DAT_011aa498;
        }
        if (dest.m_ucBitsPerPixel == 16)
        {
            bool alpha;
            if (static_cast<const PixelFormat_a786e0&>(dest).FUN_00a77940())
                alpha = dest.m_eFormat == NiPixelFormat::FORMAT_PALALPHA;
            else
                alpha = reinterpret_cast<FUN_00a77980_shell*>(const_cast<NiPixelFormat*>(&dest))->FUN_00a77980(3) > 0;
            if (dest.IsField4InRange())
                alpha = true;
            if (prefs.m_eAlphaFormat == 1)
                return &DAT_011aa960;
            if (prefs.m_eAlphaFormat == 2)
                return &DAT_011aa9f0;
            if (prefs.m_eAlphaFormat == 0)
                return &DAT_011aa8d0;
            if (alpha)
                return &DAT_011aa9f0;
            return &DAT_011aa8d0;
        }
        if (dest.m_ucBitsPerPixel == 32)
        {
            if (prefs.m_eAlphaFormat == 0)
                return &DAT_011aab58;
            if (prefs.m_eAlphaFormat == 1 || prefs.m_eAlphaFormat == 2)
                return &DAT_011aaac8;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_RGB)
                return &DAT_011aab58;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_RGBA)
                return &DAT_011aaac8;
        }
    }
    return &dest;
}

extern const NiPixelFormat DAT_011aa498;
extern const NiPixelFormat DAT_011aa4e0;
extern const NiPixelFormat DAT_011aa528;
extern const NiPixelFormat DAT_011aa570;
extern const NiPixelFormat DAT_011aa5b8;
extern const NiPixelFormat DAT_011aa8d0;
extern const NiPixelFormat DAT_011aa9f0;
extern const NiPixelFormat DAT_011aaac8;

struct FormatPrefs_a78910
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};

struct PixFmtQuery_a78910
{
    bool Check_a77940() const;
};

static inline unsigned char GetAlphaBits_a78910(const NiPixelFormat& kFmt)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        if (kFmt.m_akComponents[i].kind == 3)
            return kFmt.m_akComponents[i].bits;
    }
    return 0;
}

static __forceinline const NiPixelFormat* PickCompressed_a78910(const NiPixelFormat& kFmt, bool bAlpha)
{
    NiPixelFormat::Format eFormat = kFmt.m_eFormat;
    if (eFormat == NiPixelFormat::FORMAT_DXT1)
        return &DAT_011aa498;
    if (eFormat == NiPixelFormat::FORMAT_DXT3)
        return &DAT_011aa4e0;
    if (eFormat == NiPixelFormat::FORMAT_DXT5)
        return &DAT_011aa528;
    return bAlpha ? &DAT_011aa528 : &DAT_011aa498;
}

static inline bool IsPalettized_a78910(const NiPixelFormat& kFmt)
{
    return kFmt.m_eFormat == NiPixelFormat::FORMAT_PAL || kFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA;
}

struct ImageConverter_a78910 : public NiDevImageConverter
{
    const NiPixelFormat* SelectFormat(const FormatPrefs_a78910& kPrefs, const NiPixelFormat& kSrcFmt,
                                      const NiPixelFormat& kDestFmt);
};

// Chooses a target NiPixelFormat from the preferred layout and source alpha/compression, falling back to compressed or default formats.
// @fnv 0x00a78910
const NiPixelFormat* ImageConverter_a78910::SelectFormat(const FormatPrefs_a78910& kPrefs, const NiPixelFormat& kSrcFmt,
                                                         const NiPixelFormat& kDestFmt)
{
    bool bAlpha;
    if (IsPalettized_a78910(kSrcFmt))
        bAlpha = (kSrcFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA);
    else
        bAlpha = GetAlphaBits_a78910(kSrcFmt) > 0;
    if (kSrcFmt.IsCompressed())
        bAlpha = true;

    int eLayout = kPrefs.m_ePreferredPixelLayout;
    if (eLayout == 14)
        return &DAT_011aa570;
    if (eLayout == 13)
        return &DAT_011aa5b8;
    if (eLayout == 2)
        return &DAT_011aaac8;
    if (eLayout == 1)
        return bAlpha ? &DAT_011aa9f0 : &DAT_011aa8d0;
    if (eLayout == 0 || eLayout == 5)
        return bAlpha ? &DAT_011aa528 : &DAT_011aa498;
    if (eLayout == 3)
        return PickCompressed_a78910(kDestFmt, bAlpha);
    if (eLayout == 4)
        return &DAT_011aa450;
    if (eLayout == 6)
    {
        if (((const PixFmtQuery_a78910*)&kDestFmt)->Check_a77940() || kDestFmt.IsField4InRange())
            return PickCompressed_a78910(kDestFmt, bAlpha);
        unsigned char ucBpp = kDestFmt.m_ucBitsPerPixel;
        if (ucBpp == 16)
            return bAlpha ? &DAT_011aa9f0 : &DAT_011aa8d0;
        if (ucBpp == 64)
            return &DAT_011aa5b8;
        if (ucBpp == 128)
            return &DAT_011aa570;
    }
    return &DAT_011aaac8;
}

void* __cdecl FUN_00aa1070(unsigned);
void __cdecl FUN_00aa10f0(void*);
// Expands 4-bit paletted source pixels into a 32-bit color buffer using the palette and bit-shift masks, then frees the temporary buffer.
// @fnv 0x00a790a0
void __cdecl ExpandPalettedImage(unsigned width, unsigned height, unsigned unused, unsigned char* dst,
                                 const NiPalette* palette, const NiDevImageConverter::PixelFormatBitLayout& bits,
                                 const unsigned char* src, const NiDevImageConverter::PixelFormatBitLayout& srcBits)
{
    const NiPalette::PaletteColorEntry* entries = palette->m_pColorEntries;
    unsigned char* expanded = (unsigned char*)FUN_00aa1070(width * height);
    unsigned count = (width >> 1) * height;
    unsigned char* saved = expanded;
    for (unsigned i = 0; i < count; ++i)
    {
        *expanded++ = src[i] >> 4;
        *expanded++ = src[i] & 15;
    }
    const unsigned char* read = saved;
    unsigned colors[16];
    for (unsigned i = 0; i < 16; ++i)
    {
        colors[i] =
            (((unsigned)entries[i].r >> bits.m_ucRedSourceShift) << bits.m_ucRedDestinationShift & bits.m_uiRedMask) |
            (((unsigned)entries[i].g >> bits.m_ucGreenSourceShift) << bits.m_ucGreenDestinationShift &
             bits.m_uiGreenMask) |
            (((unsigned)entries[i].b >> bits.m_ucBlueSourceShift) << bits.m_ucBlueDestinationShift &
             bits.m_uiBlueMask) |
            (((255u >> bits.m_ucAlphaSourceShift) << bits.m_ucAlphaDestinationShift) & bits.m_uiAlphaMask);
    }
    unsigned* output = (unsigned*)dst;
    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x)
            *output++ = colors[*read++];
    FUN_00aa10f0(saved);
}

void* FUN_00aa1070(unsigned int uiSize);
void NiFree(void* pvMem);

struct PalEntry_a79310
{
    unsigned char r, g, b, a;
};
struct Palette_a79310
{
    char pad[0x14];
    PalEntry_a79310* m_pkEntryArray;
};
struct Format_a79310
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShl[4];
    unsigned char m_aucShr[4];
};

// Expands 4-bit packed palette indices into 32-bit colors using the palette and format masks, writes them to pDst, and frees the temporary buffer.
// @fnv 0x00a79310
void __cdecl FUN_00a79310(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned int* pDst,
                          Palette_a79310* pkPalette, Format_a79310* pkFormat, const unsigned char* pSrc)
{
    PalEntry_a79310* pkEntries = pkPalette->m_pkEntryArray;
    unsigned char* pucOut = (unsigned char*)FUN_00aa1070(uiWidth * uiHeight);
    unsigned int uiBytes = (uiWidth >> 1) * uiHeight;
    unsigned char* pucIndices = pucOut;
    for (unsigned int i = 0; i < uiBytes; i++)
    {
        *pucOut++ = pSrc[i] >> 4;
        *pucOut++ = pSrc[i] & 0xf;
    }

    unsigned char* pucRead = pucIndices;
    unsigned int auiColors[16];
    for (unsigned int i = 0; i < 16; i++)
    {
        auiColors[i] = (((pkEntries[i].r >> pkFormat->m_aucShr[0]) << pkFormat->m_aucShl[0]) & pkFormat->m_auiMask[0]) |
                       (((pkEntries[i].g >> pkFormat->m_aucShr[1]) << pkFormat->m_aucShl[1]) & pkFormat->m_auiMask[1]) |
                       (((pkEntries[i].b >> pkFormat->m_aucShr[2]) << pkFormat->m_aucShl[2]) & pkFormat->m_auiMask[2]) |
                       (((pkEntries[i].a >> pkFormat->m_aucShr[3]) << pkFormat->m_aucShl[3]) & pkFormat->m_auiMask[3]);
    }

    unsigned int* puiDst = pDst;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
            *puiDst++ = auiColors[*pucRead++];
    }
    NiFree(pucIndices);
}

// Builds a 256-entry palette table from the palette using the format's channel shifts/masks, then converts each source index to a 16-bit output pixel.
// @fnv 0x00a79ae0
void __cdecl FUN_00a79ae0(unsigned width, unsigned height, unsigned unused, unsigned char* dst,
                          const NiPalette* pPalette, const NiDevImageConverter::PixelFormatBitLayout& kFormat,
                          const unsigned char* src, const NiDevImageConverter::PixelFormatBitLayout& unusedFmt)
{
    unsigned short paletteTable[256];
    const NiPalette::PaletteColorEntry* paletteEntries = pPalette->m_pColorEntries;
    unsigned alphaLeftShift = kFormat.m_ucAlphaDestinationShift;
    signed char alphaRightShift = kFormat.m_ucAlphaSourceShift;
    unsigned short blueMask;
    unsigned short alphaMask = (unsigned short)kFormat.m_uiAlphaMask;
    unsigned char blueRightShift = kFormat.m_ucBlueSourceShift;
    unsigned blueLeftShift = kFormat.m_ucBlueDestinationShift;
    blueMask = (unsigned short)kFormat.m_uiBlueMask;
    char greenRightShift = kFormat.m_ucGreenSourceShift;
    unsigned greenLeftShift;
    greenLeftShift = kFormat.m_ucGreenDestinationShift;
    unsigned short greenMask = (unsigned short)kFormat.m_uiGreenMask;
    unsigned redLeftShift;
    unsigned char redRightShift = kFormat.m_ucRedSourceShift;
    unsigned uiIndex = 0;
    redLeftShift = kFormat.m_ucRedDestinationShift;
    unsigned short redMask = (unsigned short)kFormat.m_uiRedMask;
    for (; uiIndex < 256; ++uiIndex)
    {
        paletteTable[uiIndex] =
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].r >> redRightShift)) << redLeftShift & redMask) |
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].g >> greenRightShift)) << greenLeftShift &
             greenMask) |
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].b >> blueRightShift)) << blueLeftShift &
             blueMask) |
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].a >> alphaRightShift)) << alphaLeftShift &
             alphaMask);
    }
    unsigned short* output = (unsigned short*)dst;
    for (unsigned row = 0; row < height; ++row)
        for (unsigned col = 0; col < width; ++col)
            *output++ = paletteTable[*src++];
}

struct ConverterBase
{
    ConverterBase() throw();
    virtual void method();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
};
struct ConverterCodec
{
    ConverterCodec() throw();
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
};
struct ReaderAllocator
{
    void* Allocate(unsigned int);
};
extern ReaderAllocator DAT_011f6238;
struct ReaderStorage
{
    static void* operator new(unsigned int size) throw()
    {
        return DAT_011f6238.Allocate(size);
    }
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
};
struct NiBMPReader : ReaderStorage
{
    __declspec(nothrow) NiBMPReader() throw();
};
struct FUN_00a8d750 : ReaderStorage
{
    __declspec(nothrow) FUN_00a8d750() throw();
};
struct FUN_00a8c190 : ReaderStorage
{
    __declspec(nothrow) FUN_00a8c190() throw();
};
struct ReaderNode
{
    ReaderNode* next;
    ReaderNode* prev;
    ReaderStorage* value;
};
struct NodePool
{
    unsigned int count;
    ReaderNode* FUN_0043a010();
};
struct ReaderList
{
    ReaderNode* head;
    ReaderNode* tail;
    NodePool pool;
    __forceinline void AddHead(ReaderStorage* reader)
    {
        ReaderNode* node = pool.FUN_0043a010();
        node->value = reader;
        node->prev = 0;
        node->next = head;
        if (head)
            head->prev = node;
        else
            tail = node;
        ++pool.count;
        head = node;
    }
};
struct FUN_00a7b110 : ConverterBase
{
    virtual void method();
    ConverterCodec codec;
    ReaderList readers;
    FUN_00a7b110();
};
// Initializes the reader list and adds a NiBMPReader, FUN_00a8d750 and FUN_00a8c190 reader to its head.
// @fnv 0x00a7b110
FUN_00a7b110::FUN_00a7b110()
{
    readers.pool.count = 0;
    readers.head = 0;
    readers.tail = 0;
    readers.AddHead(new NiBMPReader);
    readers.AddHead(new FUN_00a8d750);
    readers.AddHead(new FUN_00a8c190);
}

extern "C" void __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);

struct NiPathStandIn
{
    static void __cdecl FUN_00aa2a00(char* pcPath);
};

class NiFilenameStandIn
{
  public:
    NiFilenameStandIn(const char* pcFullPath);
    const char* GetExt() const
    {
        return m_acExtension;
    }
    char m_acDriveLetter[3];
    char m_acFolderPath[256];
    char m_acExtension[256];
    char m_acBaseName[256];
    char m_acPlatformSubDir[256];
};

class NiFileStandIn
{
  public:
    virtual ~NiFileStandIn();
    virtual operator bool() const;
    static NiFileStandIn* __cdecl FUN_00aa1a20(const char* pcName, int eMode, unsigned int uiBufferSize);
};

class NiImageReaderStandIn
{
  public:
    virtual ~NiImageReaderStandIn();
    virtual bool IsExtensionSupported(const char* pcExt) const;
};

typedef void* NiTListIterator;

template <class T> struct NiTListItem
{
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    T m_element;
};

template <class T> class NiTPointerListStandIn
{
  public:
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
    NiTListIterator GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListIterator& kPos) const
    {
        T* pElement = &((NiTListItem<T>*)kPos)->m_element;
        kPos = ((NiTListItem<T>*)kPos)->m_pkNext;
        return *pElement;
    }
};

class NiDevImageConverterStandIn : public NiDevImageConverter
{
  public:
    int m_784, m_788, m_78c, m_790, m_794, m_798, m_79c, m_7a0;
    int m_7a4, m_7a8, m_7ac, m_7b0, m_7b4, m_7b8, m_7bc, m_7c0;
    int m_7c4, m_7c8, m_7cc, m_7d0, m_7d4, m_7d8, m_7dc, m_7e0;
    int m_7e4, m_7e8, m_7ec, m_7f0, m_7f4, m_7f8, m_7fc, m_800;
    int m_804, m_808, m_80c, m_810, m_814, m_818, m_81c, m_820;
    int m_824, m_828, m_82c, m_830, m_834, m_838, m_83c, m_840;
    int m_844, m_848, m_84c, m_850, m_854, m_858, m_85c, m_860;
    int m_864, m_868, m_86c, m_870, m_874, m_878, m_87c, m_880;
    int m_884, m_888, m_88c, m_890, m_894, m_898, m_89c, m_8a0;
    int m_8a4, m_8a8, m_8ac, m_8b0, m_8b4, m_8b8, m_8bc, m_8c0;
    int m_8c4, m_8c8, m_8cc, m_8d0, m_8d4, m_8d8, m_8dc, m_8e0;
    int m_8e4, m_8e8, m_8ec, m_8f0, m_8f4, m_8f8, m_8fc, m_900;
    int m_904, m_908, m_90c, m_910, m_914, m_918, m_91c, m_920;
    int m_924, m_928, m_92c, m_930, m_934, m_938, m_93c, m_940;
    int m_944, m_948, m_94c, m_950, m_954, m_958, m_95c, m_960;
    int m_964, m_968, m_96c, m_970, m_974, m_978, m_97c, m_980;
    int m_984, m_988, m_98c;
    NiTPointerListStandIn<NiImageReaderStandIn*> m_kImageReaderList;
    bool FUN_00a77ae0(const char* pcFilename);
};

// Copies the path, normalizes it, then tries each registered image reader's extension match and opens the file to test readability.
// @fnv 0x00a77ae0
bool NiDevImageConverterStandIn::FUN_00a77ae0(const char* pcFilename)
{
    char acStandardFilename[0x104];
    NiTListIterator kIter = m_kImageReaderList.GetHeadPos();
    FUN_00ec65a6(acStandardFilename, 0x104, pcFilename);
    NiPathStandIn::FUN_00aa2a00(acStandardFilename);
    NiFilenameStandIn kFileName(acStandardFilename);
    while (kIter)
    {
        NiImageReaderStandIn* pkReader = m_kImageReaderList.GetNext(kIter);
        if (pkReader->IsExtensionSupported(kFileName.GetExt()))
        {
            NiFileStandIn* pkIstr = NiFileStandIn::FUN_00aa1a20(acStandardFilename, 0, 0x8000);
            if (!pkIstr)
                return false;
            if (*pkIstr)
            {
                delete pkIstr;
                return true;
            }
            delete pkIstr;
            return false;
        }
    }
    return false;
}

namespace fnv_00a77bd0 {
int __cdecl _strcpy_s(char*, unsigned int, const char*);
void __cdecl _fnv_StandardizeFilePath(char*);
class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY
    };
    virtual ~NiFile();
    virtual operator bool();
    static NiFile* GetFile(const char*, OpenMode, unsigned int);
};
struct FileName
{
    char drive[3], directory[256], name[256], extension[256], path[256];
    FileName(const char*);
};
struct Reader
{
    virtual ~Reader();
    virtual bool supports(const char*);
    virtual void v2();
    virtual bool read(NiFile*, int&, int&, int&, int&, int&);
};
struct ReaderNode
{
    ReaderNode* next;
    ReaderNode* prev;
    NiPointer<Reader> data;
};
inline Reader*& NextReader(ReaderNode*& position)
{
    Reader*& result = position->data.m_pObject;
    position = position->next;
    return result;
}
struct Converter
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    ReaderNode* head;
    bool ReadFileWithReader(const char*, int&, int&, int&, int&, int&);
};
// @fnv 0x00a77bd0
bool Converter::ReadFileWithReader(const char* apPath, int& a2, int& a3, int& a4, int& a5, int& a6)
{
    ReaderNode* node = head;
    char acFilePath[260];
    _strcpy_s(acFilePath, 260, apPath);
    _fnv_StandardizeFilePath(acFilePath);
    FileName fileNameParts(acFilePath);
    while (node)
    {
        Reader* reader = NextReader(node);
        if (reader->supports(fileNameParts.name))
        {
            NiFile* file = NiFile::GetFile(acFilePath, NiFile::READ_ONLY, 0x8000);
            if (file && *file)
            {
                if (reader->read(file, a4, a5, a2, a3, a6))
                {
                    delete file;
                    return true;
                }
                delete file;
            }
            else
            {
                delete file;
                return false;
            }
        }
    }
    return false;
}
}  // namespace fnv_00a77bd0

struct ImageConverterBase
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool CanConvertPixelFormat(const NiPixelFormat& kSrc, const NiPixelFormat& kDest);
    virtual NiPixelData* ConvertImageData(const NiPixelData& kSrc, const NiPixelFormat& kDest, NiPixelData* pkOptDest,
                                          bool bMipmap);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual bool ConvertMipLevel(NiPixelData& kDest, const NiPixelData& kSrc, int iMipmapLevel);
    virtual void vfn_34();
    virtual void vfn_38();
    virtual const NiPixelFormat* GetDestinationPixelFormat(int a1, int a2, const NiPixelFormat& kSrc, int a4);
    NiPixelData* FUN_00a78570(int a1, int a2, const NiPixelData& kSrc, int a4);
};
inline unsigned PixelDataMipmapLevels(const NiPixelData& k)
{
    return k.m_uiMipmapLevels;
}
inline unsigned PixelDataFaces(const NiPixelData& k)
{
    return k.m_uiFaces;
}
// Converts kSrc to the destination pixel format, returning a new NiPixelData or a pointer to kSrc if no conversion is needed.
// @fnv 0x00a78570
NiPixelData* ImageConverterBase::FUN_00a78570(int a1, int a2, const NiPixelData& kSrc, int a4)
{
    const NiPixelFormat* pkFmt = GetDestinationPixelFormat(a1, a2, kSrc.m_kPixelFormat, a4);
    if (pkFmt == &kSrc.m_kPixelFormat)
        return (NiPixelData*)&kSrc;
    if (!pkFmt)
        return 0;
    if (*pkFmt == kSrc.m_kPixelFormat)
        return (NiPixelData*)&kSrc;
    if (!CanConvertPixelFormat(kSrc.m_kPixelFormat, *pkFmt))
        return 0;
    NiPixelData* pkDest =
        new NiPixelData(kSrc.GetWidth(), kSrc.GetHeight(), *pkFmt, PixelDataMipmapLevels(kSrc), PixelDataFaces(kSrc));
    return ConvertMipLevel(*pkDest, kSrc, -1) ? pkDest : 0;
}

// Allocates destination pixel data and fills it using differences between neighboring source bytes.
// @fnv 0x00a78be0
NiPixelData* __stdcall FUN_00a78be0(const NiPixelData& src, const NiPixelFormat& fmt)
{
    unsigned width = src.m_puiWidth[0], height = src.m_puiHeight[0];
    unsigned levels = src.m_uiMipmapLevels;
    NiPixelData* dst;
    unsigned dstStride, srcStride;
    unsigned level, x, y;
    unsigned char* out;
    const unsigned char *in, *below, *right;
    if (src.m_kPixelFormat == SOURCE_FORMAT_RGB)
    {
        dst = new NiPixelData(width, height, DAT_011aa450, levels, 1);
        for (level = 0; level < levels; ++level)
        {
            out = dst->m_pucPixels + dst->m_puiOffsetInBytes[level];
            width = src.m_puiWidth[level];
            height = src.m_puiHeight[level];
            in = src.m_pucPixels + src.m_puiOffsetInBytes[level];
            for (y = 0; y < height; ++y)
                for (x = width; x > 0; --x)
                {
                    out[2] = in[3];
                    out[3] = in[0];
                    in += 4;
                    out += 4;
                }
        }
        dstStride = 4;
        srcStride = 4;
    }
    else if (src.m_kPixelFormat == DAT_011aa2e8 && fmt == DAT_011aa450)
    {
        dst = new NiPixelData(width, height, DAT_011aa450, levels, 1);
        for (level = 0; level < levels; ++level)
        {
            out = dst->m_pucPixels + dst->m_puiOffsetInBytes[level];
            width = src.m_puiWidth[level];
            height = src.m_puiHeight[level];
            in = src.m_pucPixels + src.m_puiOffsetInBytes[level];
            for (y = 0; y < height; ++y)
                for (x = width; x > 0; --x)
                {
                    out[2] = 255;
                    out[3] = in[0];
                    in += 3;
                    out += 4;
                }
        }
        dstStride = 4;
        srcStride = 3;
    }
    else if (src.m_kPixelFormat == DAT_011aa2e8)
    {
        dst = new NiPixelData(width, height, DAT_011aa408, levels, 1);
        dstStride = 2;
        srcStride = 3;
    }
    else
        return 0;
    for (level = 0; level < levels; ++level)
    {
        out = dst->m_pucPixels + dst->m_puiOffsetInBytes[level];
        width = src.m_puiWidth[level];
        const unsigned char* in = src.m_pucPixels + src.m_puiOffsetInBytes[level];
        right = in + srcStride;
        below = in + width * srcStride;
        width--;
        height = src.m_puiHeight[level] - 1;
        for (y = 0; y < height; ++y)
        {
            for (x = 0; x < width; ++x)
            {
                unsigned short value = in[0];
                unsigned short delta = (unsigned short)(below[0] - value);
                out[0] = (unsigned char)(right[0] - value);
                out[1] = (unsigned char)delta;
                out += dstStride;
                in += srcStride;
                right += srcStride;
                below += srcStride;
            }
            if (x)
                out[0] = (unsigned char)(in[0] - *(in - srcStride));
            else
                out[0] = 0;
            out[1] = (unsigned char)(below[0] - in[0]);
            in += srcStride;
            out += dstStride;
            right += srcStride;
            below += srcStride;
        }
        below = in - (width + 1) * srcStride;
        for (x = 0; x < width; ++x)
        {
            unsigned short value = in[0];
            unsigned short delta = (unsigned short)(value - below[0]);
            out[0] = (unsigned char)(right[0] - value);
            out[1] = (unsigned char)delta;
            out += dstStride;
            below += srcStride;
            in += srcStride;
            right += srcStride;
        }
        if (x)
        {
            out[0] = (unsigned char)(in[0] - *(in - srcStride));
            if (y)
                out[1] = (unsigned char)(in[0] - below[0]);
            else
                out[1] = 0;
        }
        else
        {
            out[0] = 0;
            if (y)
                out[1] = (unsigned char)(in[0] - below[0]);
            else
                out[1] = 0;
        }
    }
    return dst;
}

struct PixelFormatQuery : NiPixelFormat
{
    bool IsPalettized() const throw();
};

class MipPixelData : public NiMemObject
{
  public:
    virtual ~MipPixelData() throw();
    virtual void DeleteThis() throw();
    unsigned m_uiRefCount;
    NiPixelFormat m_kPixelFormat;
    NiPalette* m_pColorEntries;
    unsigned char* m_pucPixels;
    unsigned* m_puiWidth;
    unsigned* m_puiHeight;
    unsigned* m_puiOffsetInBytes;
    unsigned m_uiMipmapLevels;
    unsigned m_uiPixelStride;
    unsigned m_uiRevID;
    unsigned m_uiFaces;
    bool m_bNoConvert;
    MipPixelData(unsigned, unsigned, const NiPixelFormat&, unsigned, unsigned) throw();
    void SetPalette(NiPalette*) throw();
    unsigned GetSizeInBytes(unsigned level) const throw()
    {
        return m_puiOffsetInBytes[level + 1] - m_puiOffsetInBytes[level];
    }
    unsigned char* GetPixels(unsigned level) throw()
    {
        return m_pucPixels + m_puiOffsetInBytes[level];
    }
};

struct PixelDataRef
{
    MipPixelData* m_pObject;
    PixelDataRef() throw() : m_pObject(0)
    {}
    PixelDataRef& operator=(MipPixelData*) throw();
    void Release() throw();
};

class MipImageConverter
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool QueryImageProperties(const char*, NiPixelFormat&, bool&, unsigned&, unsigned&, unsigned&) throw();
    virtual MipPixelData* LoadPixelDataFromFile(const char*, MipPixelData*, int) throw();
    MipPixelData* FUN_00a7ae60(const char** ppcFileNames, unsigned uiNumLevels, MipPixelData* pkCurrentObject);
};

// Queries the first file's properties, allocates a MipPixelData buffer, and copies each mipmap level from the source files into it.
// @fnv 0x00a7ae60
MipPixelData* MipImageConverter::FUN_00a7ae60(const char** ppcFileNames, unsigned uiNumLevels, MipPixelData* pkCurrentObject)
{
    if (!ppcFileNames[0])
        return 0;

    PixelFormatQuery kFormat;
    bool bMipmap;
    unsigned uiWidth, uiHeight, uiFaces;
    if (!QueryImageProperties(ppcFileNames[0], kFormat, bMipmap, uiWidth, uiHeight, uiFaces) || uiFaces != 1)
        return 0;

    MipPixelData* pkDest = new MipPixelData(uiWidth, uiHeight, kFormat, uiNumLevels, 1);
    if (!pkDest)
        return 0;

    for (unsigned i = 0; i < uiNumLevels; i++)
    {
        if (!ppcFileNames[i])
        {
            delete pkDest;
            return 0;
        }

        PixelDataRef spSrc;
        if (i == 0 && pkCurrentObject)
            spSrc = pkCurrentObject;
        else
            spSrc = LoadPixelDataFromFile(ppcFileNames[i], 0, 0);

        MipPixelData* pkSrc = *(MipPixelData* volatile*)&spSrc.m_pObject;
        if (!pkSrc)
        {
            delete pkDest;
            return 0;
        }

        unsigned uiSize = pkDest->GetSizeInBytes(i);
        if (uiSize != pkSrc->GetSizeInBytes(0))
        {
            delete pkDest;
            spSrc.Release();
            return 0;
        }

        fnv_zlib_memcpy(pkDest->GetPixels(i), pkSrc->GetPixels(0), uiSize);

        if (i == 0 && kFormat.IsPalettized())
            pkDest->SetPalette(pkSrc->m_pColorEntries);

        spSrc.Release();
    }

    return pkDest;
}

inline void* __cdecl operator new(unsigned int, void* memory) throw()
{
    return memory;
}

namespace Mipmap {

struct Format
{
    unsigned int unk0;

    unsigned int unk4;

    unsigned int unk8;

    unsigned int unkc;

    unsigned int unk10;

    unsigned int unk14;

    unsigned int unk18;

    unsigned int unk1c;

    unsigned int unk20;

    unsigned int unk24;

    unsigned int unk28;

    unsigned int unk2c;

    unsigned int unk30;

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;
    Format();
    bool FUN_00a76540(const Format&);
};
extern Format DAT_011aa2e8, DAT_011aa2a0;

struct NiMemObject
{
    static void* operator new(unsigned int);
};

struct Image : NiMemObject
{
    unsigned int unk0, unk4;
    Format format;

    unsigned int unk4c;

    unsigned char* pixels;

    unsigned int* widths;

    unsigned int* heights;

    unsigned int* offsets;

    unsigned int levels;

    unsigned int unk64, unk68, faces, unk70;
    Image(unsigned int, unsigned int, const Format&, int, unsigned int) throw();

    unsigned char* const& Base() const
    {
        return pixels;
    }
    unsigned char* Pixels(unsigned int level, unsigned int face) const
    {
        return Base() + offsets[level] + face * offsets[levels];
    }
    unsigned int Faces() const
    {
        return faces;
    }
    unsigned int Width(unsigned int level = 0) const
    {
        return widths[level];
    }
    unsigned int Height(unsigned int level = 0) const
    {
        return heights[level];
    }
};

struct Converter
{
    virtual void slot0();

    virtual void slot4();

    virtual void slot8();

    virtual void slotc();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual bool IsRGBA(const Format&);
    virtual bool IsRGB(const Format&);
    virtual void slot28();
    virtual void slot2c();
    virtual bool Convert(Image*, Image*, int);

    Image* GenerateMipmaps(Image*, Image*);
};

// Generates RGB or RGBA mip levels by averaging pixels from the preceding level.
// @fnv 0x00a78090
Image* Converter::GenerateMipmaps(Image* source, Image* destination)
{
    const Format& sourceFormat = source->format;
    Format format;

    if (IsRGB(sourceFormat))
        format = DAT_011aa2e8;
    else if (IsRGBA(sourceFormat))
        format = DAT_011aa2a0;
    else
        return 0;

    Image* output = destination;

    if (!output || !output->format.FUN_00a76540(format) || output->levels <= 1 || output->faces != source->faces)
    {
        void* storage = Image::operator new(sizeof(Image));
        if (storage)
            output = ::new (storage) Image(source->Width(), source->Height(), format, 0, source->Faces());
        else
            output = 0;
    }

    unsigned int levels = output->levels;

    if (source != output && !Convert(output, source, 0))
        return 0;

    for (unsigned int face = 0; face < source->faces; ++face)
    {

        if (format.FUN_00a76540(DAT_011aa2e8))
        {

            for (unsigned int level = 1; level < levels; ++level)
            {

                unsigned char* src = output->Pixels(level - 1, face);

                unsigned char* dst = output->Pixels(level, face);

                unsigned int width = output->widths[level];

                unsigned int height = output->heights[level];

                unsigned int priorWidth = output->widths[level - 1];

                unsigned int row = priorWidth * 3;

                if (priorWidth == 1)
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        *dst++ = (unsigned int)(src[0] + src[3]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[5]) >> 1;

                        src += 6;
                    }
                }

                else if (output->heights[level - 1] == 1)
                {
                    for (unsigned int x = 0; x < width; ++x)
                    {
                        *dst++ = (unsigned int)(src[0] + src[3]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[5]) >> 1;

                        src += 6;
                    }
                }

                else
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        for (unsigned int x = 0; x < width; ++x)
                        {
                            *dst++ = (unsigned int)(src[0] + src[3] + src[row + 0] + src[row + 3]) >> 2;

                            *dst++ = (unsigned int)(src[1] + src[4] + src[row + 1] + src[row + 4]) >> 2;

                            *dst++ = (unsigned int)(src[2] + src[5] + src[row + 2] + src[row + 5]) >> 2;

                            src += 6;
                        }
                        src += row;
                    }
                }
            }
        }

        else if (format.FUN_00a76540(DAT_011aa2a0))
        {

            for (unsigned int level = 1; level < levels; ++level)
            {
                // This mip reads its predecessor: 1 <= level < levels.
                __assume(((level <= levels - 1) & (level >= 1)) != 0);

                unsigned char* src = output->Pixels(level - 1, face);

                unsigned char* dst = output->Pixels(level, face);

                unsigned int width = output->widths[level];

                unsigned int height = output->heights[level];

                unsigned int priorWidth = output->widths[level - 1];

                unsigned int row = priorWidth * 4;

                if (priorWidth == 1)
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        *dst++ = (unsigned int)(src[0] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[5]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[6]) >> 1;

                        *dst++ = (unsigned int)(src[3] + src[7]) >> 1;

                        src += 8;
                    }
                }

                else if (output->heights[level - 1] == 1)
                {
                    for (unsigned int x = 0; x < width; ++x)
                    {
                        *dst++ = (unsigned int)(src[0] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[5]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[6]) >> 1;

                        *dst++ = (unsigned int)(src[3] + src[7]) >> 1;

                        src += 8;
                    }
                }

                else
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        for (unsigned int x = 0; x < width; ++x)
                        {
                            *dst++ = (unsigned int)(src[0] + src[4] + src[row + 0] + src[row + 4]) >> 2;

                            *dst++ = (unsigned int)(src[1] + src[5] + src[row + 1] + src[row + 5]) >> 2;

                            *dst++ = (unsigned int)(src[2] + src[6] + src[row + 2] + src[row + 6]) >> 2;

                            *dst++ = (unsigned int)(src[3] + src[7] + src[row + 3] + src[row + 7]) >> 2;

                            src += 8;
                        }
                        src += row;
                    }
                }
            }
        }
    }
    return output;
}

}

// Converts an 8-bit paletted image to 16-bit using the given NiPalette and pixel format bit layouts.
// @fnv 0x00a795d0
void __cdecl ConvertPaletteTo16Bit(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestSize,
                                   unsigned char* pucDest, const NiPalette* pkPalette,
                                   const NiDevImageConverter::PixelFormatBitLayout& kDestBits,
                                   const unsigned char* pucSrc,
                                   const NiDevImageConverter::PixelFormatBitLayout& kSrcBits)
{
    const NiPalette::PaletteColorEntry* pkEntries = pkPalette->m_pColorEntries;
    unsigned short ausPalette[256];
    unsigned int i;

    for (i = 0; i < 256; i++)
    {
        ausPalette[i] =
            (unsigned short)((((pkEntries[i].r >> kDestBits.m_ucRedSourceShift) << kDestBits.m_ucRedDestinationShift) &
                              kDestBits.m_uiRedMask) |
                             (((pkEntries[i].g >> kDestBits.m_ucGreenSourceShift)
                               << kDestBits.m_ucGreenDestinationShift) &
                              kDestBits.m_uiGreenMask) |
                             (((pkEntries[i].b >> kDestBits.m_ucBlueSourceShift)
                               << kDestBits.m_ucBlueDestinationShift) &
                              kDestBits.m_uiBlueMask) |
                             (((0xffu >> kDestBits.m_ucAlphaSourceShift) << kDestBits.m_ucAlphaDestinationShift) &
                              kDestBits.m_uiAlphaMask));
    }

    unsigned short* pusDest = (unsigned short*)pucDest;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
            *pusDest++ = ausPalette[*pucSrc++];
    }
}

extern int DAT_00ff0000;

// Swaps BGR to RGB pixel order when the source has a 0xFF00 green mask and 0xFF red mask, or copies raw bytes when the red mask is 0xFF.
// @fnv 0x00a7a160
void __cdecl FUN_00a7a160(unsigned int uiWidth, unsigned int uiHeight, unsigned int, unsigned char* pDst,
                          const NiPalette*, const NiDevImageConverter::PixelFormatBitLayout& kSrcBits,
                          const unsigned char* pSrc, const NiDevImageConverter::PixelFormatBitLayout&)
{
    if (kSrcBits.m_uiGreenMask == 0xFF00u)
    {
        if (kSrcBits.m_uiRedMask == (unsigned int)&DAT_00ff0000)
        {
            if (uiHeight <= 0)
                return;
            unsigned int y = uiHeight;
            const unsigned char* src = pSrc;
            unsigned char* dst = pDst;
            do
            {
                if (uiWidth > 0)
                {
                    unsigned int x = uiWidth;
                    do
                    {
                        *dst++ = src[2];
                        *dst++ = src[1];
                        *dst++ = src[0];
                        src += 3;
                    } while (--x);
                }
            } while (--y);
        }
        else if (kSrcBits.m_uiRedMask == 0xFFu)
        {
            fnv_zlib_memcpy(pDst, pSrc, uiWidth * uiHeight * 3);
        }
    }
}

struct Format_a7a1f0
{
    int unk00;
    int unk04;
};

void __cdecl FUN_00ec44d0(void* destination, const void* source, unsigned int size);

// @fnv 0x00a7a1f0
void __cdecl FUN_00a7a1f0(unsigned int width, unsigned int height, unsigned int unused, unsigned char* destination,
                          unsigned int unused2, unsigned int FlushUsageData, unsigned char* source,
                          Format_a7a1f0* format)
{
    if (format->unk04 != 0xff00)
        return;

    if (format->unk00 == reinterpret_cast<unsigned int>(&DAT_00ff0000))
    {
        for (unsigned int row = 0; row < height; ++row)
        {
            for (unsigned int column = 0; column < width; ++column)
            {
                *destination++ = source[2];
                *destination++ = source[1];
                *destination++ = source[0];
                source += 3;
            }
        }
    }
    else if (format->unk00 == 0xff)
    {
        FUN_00ec44d0(destination, source, width * height * 3);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*) throw();

class NiRefObj
{
  public:
    virtual void vfn_00();
    virtual void DeleteThis() throw();
    void IncRefCount() throw()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};

template <class T> NiPointer<T>& NiPointer<T>::operator=(T* pObject) throw()
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            ((NiRefObj*)m_pObject)->DecRefCount();
        m_pObject = pObject;
        if (m_pObject)
            ((NiRefObj*)m_pObject)->IncRefCount();
    }
    return *this;
}

static inline bool IsPowerOf2(unsigned int uiValue) throw()
{
    if (uiValue == 0)
        return false;
    return (uiValue & (uiValue - 1)) == 0;
}

static inline unsigned int GetNumMipmapLevels(const NiPixelData* pkData) throw()
{
    return pkData->m_uiMipmapLevels;
}

static inline unsigned int GetFaceTotal(const NiPixelData* pkData) throw()
{
    return pkData->m_uiFaces;
}

struct ConverterTable;
typedef bool(__fastcall* ConvertProc)(NiDevImageConverter*, ConverterTable*, NiPixelData&, const NiPixelData&, int);
typedef NiPixelData*(__thiscall* BumpProc)(NiDevImageConverter*, const NiPixelData&, const NiPixelFormat&);
struct ConverterTable
{
    void* entry00;
    void* entry04;
    void* entry08;
    void* entry0C;
    void* entry10;
    void* entry14;
    void* entry18;
    void* entry1C;
    void* entry20;
    void* entry24;
    void* entry28;
    void* entry2C;
    ConvertProc convert;
    BumpProc bump;
};
struct ConverterView
{
    ConverterTable* dispatch;
};

struct NiDevImageConverterEx : NiDevImageConverter
{
    NiPixelData* GenerateMipmaps(const NiPixelData* pkSrc, NiPixelData* pkDst) throw();
    NiPixelData* FUN_00a7a280(const NiPixelData& kSrc, const NiPixelFormat& kDstFmt, NiPixelData* pkDst,
                              bool bWithMipmaps) throw();
};

// Converts source pixel data to a destination format, optionally expanding compressed data, generating mipmaps, and converting to bump maps.
// @fnv 0x00a7a280
NiPixelData* NiDevImageConverterEx::FUN_00a7a280(const NiPixelData& kSrc, const NiPixelFormat& kDstFmt,
                                                 NiPixelData* pkDst, bool bWithMipmaps) throw()
{
    NiPointer<NiPixelData> spExpanded;
    const NiPixelData* pkSrc = &kSrc;
    if (!kSrc.m_kPixelFormat.GetLittleEndian() || !kDstFmt.GetLittleEndian())
        return 0;

    if (kSrc.m_kPixelFormat.IsCompressed() && kDstFmt.GetFormat() != kSrc.m_kPixelFormat.GetFormat())
    {
        spExpanded = m_kPixelDataExpander.ExpandPixelData(kSrc);
        pkSrc = spExpanded;
    }

    NiPointer<NiPixelData> spMipmap;
    const NiPixelData* mipSource = 0;
    if (bWithMipmaps && pkSrc->m_uiMipmapLevels <= 1 && IsPowerOf2(pkSrc->GetWidth()) &&
        FUN_00a77920(pkSrc->GetHeight()) &&
        (kDstFmt.GetFormat() == NiPixelFormat::FORMAT_RGB || kDstFmt.GetFormat() == NiPixelFormat::FORMAT_RGBA ||
         kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMP || kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMPLUMA))
    {
        spMipmap = GenerateMipmaps(pkSrc, pkDst);
        if (spMipmap)
            mipSource = spMipmap;
        else
            mipSource = pkSrc;
    }
    else
        mipSource = pkSrc;

    if (pkDst && pkDst->m_kPixelFormat == kDstFmt && (!bWithMipmaps || pkDst->m_uiMipmapLevels > 1))
    {
        if (pkDst == mipSource)
            return pkDst;
        else
        {
            ConverterTable* table = reinterpret_cast<ConverterView*>(this)->dispatch;
            if (table->convert(this, table, *pkDst, *mipSource, -1))
                return pkDst;
        }
    }

    NiPointer<NiPixelData> spBump;
    const NiPixelData* bumpSource = mipSource;
    if (kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMP || kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMPLUMA)
    {
        spBump = ConvertToBumpMap(*mipSource, kDstFmt);
        if (spBump)
            bumpSource = spBump;
    }

    NiPixelData* pkNew = new NiPixelData(bumpSource->GetWidth(), bumpSource->GetHeight(), kDstFmt,
                                         GetNumMipmapLevels(bumpSource), GetFaceTotal(bumpSource));
    if (ConvertMipLevel(*pkNew, *bumpSource, -1))
        return pkNew;
    return 0;
}
