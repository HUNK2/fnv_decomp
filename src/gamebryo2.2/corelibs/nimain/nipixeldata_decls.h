// gamebryo2.2/corelibs/nimain/nipixeldata_decls.h: declares NiObject, NiPixelFormat, NiPalettePointer, NiPixelData
#ifndef FNV_NIPIXELDATA_DECLS_H
#define FNV_NIPIXELDATA_DECLS_H


class NiObject
{
  public:
    unsigned int m_uiRefCount;
    NiObject() throw();
    virtual ~NiObject() throw()
    {}
    virtual void DeleteThis()
    {}
};
typedef char FNV_NiObject_must_be_8[(sizeof(NiObject) == 8) ? 1 : -1];

class NiPixelFormat
{
  public:
    unsigned char m_uiObjectFlags;
    unsigned char m_ucBitsPerPixel;
    unsigned char m_ucUnknownByte[2];
    int m_eFormat;
    unsigned int m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    unsigned char m_akComponents[48];

    NiPixelFormat() throw();
};
typedef char FNV_NiPixelFormat_must_be_68[(sizeof(NiPixelFormat) == 68) ? 1 : -1];

class NiPalettePointer
{
  public:
    void* value;
    NiPalettePointer() throw() : value(0)
    {}
};

class NiPixelData : public NiObject
{
  public:
    NiPixelFormat m_kPixelFormat;
    NiPalettePointer m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
    unsigned int m_uiFaces;
    bool m_bOwnsPixelData;
    unsigned char m_ucUnknownByte[3];

    NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format, unsigned int mipmapLevels,
                unsigned int faces) throw();
    static unsigned int CalculateMipmapLevels(unsigned int width, unsigned int height);
    void AllocateData(unsigned int mipmapLevels, unsigned int faces, unsigned int totalBytes);
};
typedef char FNV_NiPixelData_must_be_116[(sizeof(NiPixelData) == 116) ? 1 : -1];

extern "C" void* __cdecl fnv_zlib_memcpy(void* destination, const void* source, unsigned int size);

#endif
