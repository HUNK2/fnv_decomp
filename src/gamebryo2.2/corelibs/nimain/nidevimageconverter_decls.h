// gamebryo2.2/corelibs/nimain/nidevimageconverter_decls.h: declares NiMemObject, NiPixelFormat, Component, NiPalette, PaletteColorEntry and more
#ifndef NIDEVIMAGECONVERTER_DECLS_H
#define NIDEVIMAGECONVERTER_DECLS_H

class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};
class NiPixelFormat
{
  public:
    unsigned char m_uiObjectFlags, m_ucBitsPerPixel;
    unsigned short m_ucUnknownByte;
    enum Format
    {
        FORMAT_RGB,
        FORMAT_RGBA,
        FORMAT_PAL,
        FORMAT_PALALPHA,
        FORMAT_DXT1,
        FORMAT_DXT3,
        FORMAT_DXT5,
        FORMAT_RGB24NONINTERLEAVED,
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
    Format m_eFormat;
    int m_eTiling;
    unsigned m_uiRendererHint, m_uiExtraData;
    struct Component
    {
        int kind, representation;
        unsigned char bits;
        bool sign;
        unsigned short padding;
    } m_akComponents[4];
    Format GetFormat() const throw()
    {
        return m_eFormat;
    }
    unsigned char GetBitsPerPixel() const throw()
    {
        return m_ucBitsPerPixel;
    }
    bool IsCompressed() const throw()
    {
        return m_eFormat >= FORMAT_DXT1 && m_eFormat <= FORMAT_DXT5;
    }
    bool GetLittleEndian() const throw()
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    NiPixelFormat() throw();
    bool operator==(const NiPixelFormat&) const throw();
    bool operator!=(const NiPixelFormat&) const;
    bool IsField4InRange() const;
};
struct NiPoint3StartupTable;
extern NiPoint3StartupTable gNiPoint3StartupSrc;
#define SOURCE_FORMAT_RGB reinterpret_cast<const NiPixelFormat&>(gNiPoint3StartupSrc)
extern const NiPixelFormat DAT_011aa180;
extern const NiPixelFormat DAT_011aa1c8;
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa258;
extern const NiPixelFormat DAT_011aa2e8;
extern const NiPixelFormat DAT_011aa330;
extern const NiPixelFormat DAT_011aa3c0;
extern const NiPixelFormat DAT_011aa408;
extern const NiPixelFormat DAT_011aa450;
class NiPalette : public NiMemObject
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned m_uiRefCount;
    bool m_bAlpha;
    unsigned char m_ucUnknownByte[3];
    unsigned m_uiNumColors, m_uiRevID;
    struct PaletteColorEntry
    {
        unsigned char r, g, b, a;
    }* m_pColorEntries;
    void* m_pTextureRendererData;
    NiPalette *m_pkPrev, *m_pkNext;
    NiPalette(const NiPalette&) throw();
    NiPalette(bool, unsigned, const PaletteColorEntry*) throw();
    void FUN_00a8b190(const NiPalette&);
    unsigned GetEntries(PaletteColorEntry*& entries) const throw()
    {
        entries = m_pColorEntries;
        return m_uiNumColors;
    }
    PaletteColorEntry* GetEntries(unsigned& count) const throw()
    {
        PaletteColorEntry* entries = m_pColorEntries;
        count = m_uiNumColors;
        return entries;
    }
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*) throw();
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer() throw() : m_pObject(0)
    {}
    operator T*() const throw()
    {
        return m_pObject;
    }
    T* operator->() const throw()
    {
        return m_pObject;
    }
    T& operator*() const throw()
    {
        return *m_pObject;
    }
    NiPointer& operator=(T*) throw();
    ~NiPointer() throw()
    {
        if (m_pObject && InterlockedDecrement((volatile long*)&m_pObject->m_uiRefCount) == 0)
            m_pObject->DeleteThis();
    }
};
class NiPixelData : public NiMemObject
{
  public:
    virtual void vfn_00();
    virtual void DeleteThis() throw();
    unsigned m_uiRefCount;
    NiPixelFormat m_kPixelFormat;
    NiPointer<NiPalette> m_spPalette;
    unsigned char* m_pucPixels;
    unsigned *m_puiWidth, *m_puiHeight, *m_puiOffsetInBytes;
    unsigned m_uiMipmapLevels, m_uiPixelStride, m_uiRevID, m_uiFaces;
    bool m_bOwnsPixelData;
    NiPixelData(unsigned, unsigned, const NiPixelFormat&, unsigned, unsigned) throw();
    void FUN_00a76a60(NiPalette*);
    NiPalette* GetPalette() const throw()
    {
        return m_spPalette;
    }
    unsigned GetWidth(unsigned level = 0) const throw()
    {
        return m_puiWidth[level];
    }
    unsigned GetHeight(unsigned level = 0) const throw()
    {
        return m_puiHeight[level];
    }
    const unsigned char* GetPixels(unsigned level, unsigned face) const throw()
    {
        return m_pucPixels + m_puiOffsetInBytes[level] + face * m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    unsigned char* GetPixels(unsigned level, unsigned face)
    {
        return m_pucPixels + m_puiOffsetInBytes[level] + face * m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    unsigned GetSizeInBytes(unsigned level) const throw()
    {
        return m_puiOffsetInBytes[level + 1] - m_puiOffsetInBytes[level];
    }
};
class PixelDataExpander
{
  public:
    NiPixelData* ExpandPixelData(const NiPixelData&) throw();
};
class NiDevImageConverter
{
  public:
    class PixelFormatBitLayout
    {
      public:
        unsigned m_uiRedMask, m_uiGreenMask, m_uiBlueMask, m_uiAlphaMask;
        unsigned char m_ucRedDestinationShift, m_ucGreenDestinationShift, m_ucBlueDestinationShift,
            m_ucAlphaDestinationShift, m_ucRedSourceShift, m_ucGreenSourceShift, m_ucBlueSourceShift,
            m_ucAlphaSourceShift;
        PixelFormatBitLayout(const NiPixelFormat&);
    };
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool CanConvertPixelFormat(const NiPixelFormat&, const NiPixelFormat&);
    virtual NiPixelData* ConvertImageData(const NiPixelData&, const NiPixelFormat&, NiPixelData*, bool);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool IsSupportedDestinationFormat(const NiPixelFormat&);
    virtual bool IsSupportedSourceFormat(const NiPixelFormat&);
    virtual NiPixelData* ConvertBetweenPixelData(const NiPixelData*, NiPixelData*) throw();
    virtual void vfn_2c();
    virtual bool ConvertMipLevel(NiPixelData&, const NiPixelData&, int) throw();
    virtual NiPixelData* ConvertToBumpMap(const NiPixelData&, const NiPixelFormat&) throw();
    unsigned char m_base[0x77c];
    PixelDataExpander m_kPixelDataExpander;
};
extern "C" void* __cdecl fnv_zlib_memcpy(void*, const void*, unsigned);
typedef void(__cdecl* PixelConvertFunc)(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                        const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                        const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a76d70(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a76e90(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelsTo16Bit(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                  const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                  const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRGBToFormat(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRGBAToPacked(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                 const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                 const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a77110(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a771d0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl UnpackPixels(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelsToBytes(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                  const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                  const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a773d0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRgbToRgba(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                              const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                              const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelsToRgb(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelFormat(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPackedPixelsToRGBA(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                       const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                       const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a776b0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRgbToPacked16(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                  const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                  const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a77800(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a77880(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl Convert4BitPalettedTo24Bit(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                        const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                        const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ExpandPalettedImage(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                 const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                 const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a79310(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPaletteTo16Bit(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                   const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                   const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a798c0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a79ae0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a79e20(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPalettizedToFormat(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                       const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                       const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a7a160(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a7a1f0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
bool __cdecl FUN_00a77920(unsigned) throw();
#endif
