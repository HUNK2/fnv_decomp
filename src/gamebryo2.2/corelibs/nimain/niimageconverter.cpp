// gamebryo2.2/corelibs/nimain/niimageconverter.cpp: NiImageConverter, ImageOwner (17 functions)

#include "niimageconverter_worker.h"

// @fnv 0x00a76640
NiImageConverter* NiImageConverter::GetSharedImageConverter()
{
    return DAT_011f4a7c;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern long volatile DAT_011f4400;
struct NiRefObject2
{
    virtual ~NiRefObject2();
    virtual void DeleteThis();
    long refs;
    NiRefObject2() throw()
    {
        refs = 0;
        InterlockedIncrement(&DAT_011f4400);
    }
};
struct Sub80
{
    void FUN_00a8ae50() throw();
};
struct BSFadeNode
{
    static void* operator new(unsigned int) throw();
};
struct NiImageConverter2 : NiRefObject2
{
    char pad[0x78];
    Sub80 s;
    char pad2[0x6ff];
    NiImageConverter2() throw()
    {
        s.FUN_00a8ae50();
    }
    void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
};
inline void Rel(NiRefObject2* o)
{
    if (!InterlockedDecrement(&o->refs))
        o->DeleteThis();
}
// Allocates a NiImageConverter2, releases the previous global converter, stores the new one in DAT_011f4a7c and increments its reference count.
// @fnv 0x00a76ab0
void CreateImageConverter()
{
    NiRefObject2* p = new NiImageConverter2();
    if ((NiRefObject2*)DAT_011f4a7c != p)
    {
        if (DAT_011f4a7c)
            Rel((NiRefObject2*)DAT_011f4a7c);
        DAT_011f4a7c = (NiImageConverter*)p;
        if (p)
            InterlockedIncrement(&p->refs);
    }
}

struct NiFile;
struct NiImageReader;
struct NiPixelData;
struct NiPixelFormat;
struct NiStream;
struct blob68
{
    char b[68];
};

struct VTable_FUN_00a76d40
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual bool v20(const NiPixelFormat&) const;
    virtual bool v24(const NiPixelFormat&) const;
};

// @fnv 0x00a76d40
bool __fastcall FUN_00a76d40(const VTable_FUN_00a76d40* pThis, int, const NiPixelFormat& kSrcFmt)
{
    if (pThis->v20(kSrcFmt) || pThis->v24(kSrcFmt))
        return true;
    return false;
}

namespace fnv_00a76650 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long volatile DAT_011f4400;
struct Sub80
{
    void FUN_00a8ae50() throw();
};
struct NiRefObject
{
    unsigned int m_uiRefCount;
    NiRefObject() : m_uiRefCount(0)
    {
        InterlockedIncrement(&DAT_011f4400);
    }
    virtual ~NiRefObject();
};
struct FUN_00a76650 : NiRefObject
{
    FUN_00a76650();
    virtual ~FUN_00a76650();
};
// Constructs the object and calls FUN_00a8ae50 on the Sub80 subobject at offset 0x80.
// @fnv 0x00a76650
FUN_00a76650::FUN_00a76650()
{
    ((Sub80*)((char*)this + 0x80))->FUN_00a8ae50();
}
}  // namespace fnv_00a76650

namespace fnv_00a76680 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern long volatile DAT_011f4400;
extern void* DAT_011f4a78;
void _NiFreeAlias(void*) throw();
struct Sub80
{
    void FUN_00a8ada0() throw();
};
struct NiRefObject
{
    unsigned int m_uiRefCount;
    virtual ~NiRefObject()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
};
struct FUN_00a76680 : NiRefObject
{
    virtual ~FUN_00a76680();
};
// Frees the global DAT_011f4a78, clears it, then calls FUN_00a8ada0 on the sub-object at offset 0x80.
// @fnv 0x00a76680
FUN_00a76680::~FUN_00a76680()
{
    if (DAT_011f4a78)
        _NiFreeAlias(DAT_011f4a78);
    DAT_011f4a78 = 0;
    ((Sub80*)((char*)this + 0x80))->FUN_00a8ada0();
}
}  // namespace fnv_00a76680

struct FUN_00a76890_eq
{
    bool operator==(const NiPixelFormat&) const;
};

// @fnv 0x00a76890
bool __stdcall ArePixelFormatsEqual(void* apFormatA, void* apFormatB)
{
    NiPixelFormat& a = *(NiPixelFormat*)apFormatA;
    NiPixelFormat& b = *(NiPixelFormat*)apFormatB;
    return (*(FUN_00a76890_eq*)&a).operator==(b);
}

namespace fnv_00a76960 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct FileNameComponents
{
    FileNameComponents(const char* pcFullPath);
    void FUN_00aa29d0(char* pcPath, unsigned int uiLen);
    char m_acHead[0x303];
    char m_acTail[0x100];
};
struct NiGlobalStringTable
{
    static char* AddString(const char*);
};
int strcpy_s(char*, unsigned int, const char*);
extern const char* DAT_011f4a78;
extern char* EmptyFS;
// @fnv 0x00a76960
void FUN_00a76960(char** apszSource, char** apszDest)
{
    if (DAT_011f4a78)
    {
        FileNameComponents kName(*apszSource);
        strcpy_s(kName.m_acTail, 0x100, DAT_011f4a78);
        char acBuf[0x104];
        kName.FUN_00aa29d0(acBuf, 0x104);
        char* pcOldString = *apszDest;
        if (pcOldString != acBuf)
        {
            *apszDest = NiGlobalStringTable::AddString(acBuf);
            if (pcOldString != EmptyFS)
                InterlockedDecrement((long volatile*)(pcOldString - 8));
        }
    }
    else
    {
        char* pcNewString = *apszSource;
        if (*apszDest != pcNewString)
        {
            if (pcNewString != EmptyFS)
                InterlockedIncrement((long volatile*)(pcNewString - 8));
            if (*apszDest != EmptyFS)
                InterlockedDecrement((long volatile*)(*apszDest - 8));
            *apszDest = pcNewString;
        }
    }
}
}  // namespace fnv_00a76960

namespace fnv_00a76b30 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObj
{
    virtual void Unk0();
    virtual void Unk1();
    long m_refs;
    void DecRef()
    {
        if (!InterlockedDecrement(&m_refs))
            Unk1();
    }
};
// If the global RefObj pointer DAT_011f4a7c is set, decrements its reference count and clears the pointer.
// @fnv 0x00a76b30
void FUN_00a76b30()
{
    if (DAT_011f4a7c)
    {
        ((RefObj*)DAT_011f4a7c)->DecRef();
        DAT_011f4a7c = 0;
    }
}
}  // namespace fnv_00a76b30

namespace fnv_00a76b60 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct RefObj
{
    virtual void Unk0();
    virtual void Unk1();
    long m_refs;
    void AcquireReference()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRef()
    {
        if (!InterlockedDecrement(&m_refs))
            Unk1();
    }
};
// Replaces the global image converter pointer, releasing the previous reference and incrementing the new one's reference count.
// @fnv 0x00a76b60
void AssignImageConverter(NiImageConverter* conv)
{
    RefObj* p = (RefObj*)conv;
    if ((RefObj*)DAT_011f4a7c != p)
    {
        if (DAT_011f4a7c)
            ((RefObj*)DAT_011f4a7c)->DecRef();
        DAT_011f4a7c = conv;
        if (p)
            p->AcquireReference();
    }
}
}  // namespace fnv_00a76b60

namespace fnv_00a76c10 {
struct NiPixelData;
struct NiStream;
struct blob68
{
    char b[68];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiPixelFormat
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    static struct blob68 BuildPixelFormat(unsigned char, unsigned int, unsigned int, unsigned int, unsigned int);
    int GetFormat();
    unsigned char GetBitsPerPixel();
    unsigned int GetRendererHint();
    unsigned int GetExtraData();
    int GetTiling();
    bool GetLittleEndian();
    void SetFormat(int);
    void SetBitsPerPixel(unsigned char);
    void SetRendererHint(unsigned int);
    void SetExtraData(unsigned int);
    void SetTiling(int);
    void SetLittleEndian(bool);
    bool GetComponent(unsigned int, int*, int*, unsigned char*, bool*);
    void SetComponent(unsigned int, int, int, unsigned char, bool);
    unsigned int GetNumComponents();
    bool GetPalettized();
    bool GetPaletteHasAlpha();
    bool GetCompressed();
    unsigned int GetMask(int);
    unsigned char GetPixelBitData(int);
    unsigned char GetShift(int);
    unsigned char QBitsPerPixel();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void InitPixelFormat(int, unsigned char, int, bool, unsigned int, int, int, unsigned char, bool, int, int,
                         unsigned char, bool, int, int, unsigned char, bool, int, int, unsigned char, bool);
    void SetComponentFormat(int, unsigned char, unsigned int*);
    static unsigned int CalcMaskSize(unsigned int);
    unsigned char m_uiObjectFlags;
    unsigned char m_ucBitsPerPixel;
    char _pad_2[2];
    int m_eFormat;
    int m_eTiling;
    unsigned int m_uiRendererHint;
    unsigned int m_uiExtraData;
    char m_akComponents[48];
};
typedef char _sizecheck_NiPixelFormat[sizeof(NiPixelFormat) == 68 ? 1 : -1];
struct FUN_00a76c10_shell : public NiImageConverter
{
    NiPixelData* FUN_00a76c10(void*, void*, NiPixelData*, bool);
};

void* _memmove(void* dst, const void* src, unsigned int size);
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
};
struct PixelFormatOps
{
    bool operator==(const NiPixelFormat& other) const;
    bool operator!=(const NiPixelFormat& other) const;
};
struct NiPalette
{
    char data[0x24];
    NiPalette(const NiPalette& other);
    void FUN_00a8b190(const NiPalette& other);
    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct NiPixelData
{
    char base[8];
    NiPixelFormat m_kPixelFormat;
    NiPalette* m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    char tail[0x10];
    void FUN_00a76a60(NiPalette* pal);
    NiPalette* GetPalette() const
    {
        return m_spPalette;
    }
    NiPixelData* FUN_00a7c030(const NiPixelData& src);
};

// @fnv 0x00a76c10
NiPixelData* FUN_00a76c10_shell::FUN_00a76c10(void* src, void* apDestFmt, NiPixelData* pkOptDest, bool bMipmap)
{
    const NiPixelData& kSrc = *(const NiPixelData*)src;
    const NiPixelFormat& kDestFmt = *(const NiPixelFormat*)apDestFmt;
    if (((const PixelFormatOps*)&kSrc.m_kPixelFormat)->operator!=(kDestFmt))
        return 0;
    if (pkOptDest)
    {
        if (pkOptDest == &kSrc)
            return pkOptDest;
        if (((const PixelFormatOps*)&pkOptDest->m_kPixelFormat)->operator==(kDestFmt) &&
            *pkOptDest->m_puiWidth == *kSrc.m_puiWidth && *pkOptDest->m_puiHeight == *kSrc.m_puiHeight &&
            pkOptDest->m_uiMipmapLevels <= kSrc.m_uiMipmapLevels)
        {
            unsigned int uiMaxLevel = pkOptDest->m_uiMipmapLevels;
            for (unsigned int uiMip = 0; uiMip < uiMaxLevel; uiMip++)
            {
                _memmove(pkOptDest->m_pucPixels + pkOptDest->m_puiOffsetInBytes[uiMip],
                         kSrc.m_pucPixels + kSrc.m_puiOffsetInBytes[uiMip],
                         kSrc.m_puiOffsetInBytes[uiMip + 1] - kSrc.m_puiOffsetInBytes[uiMip]);
            }
            if (kSrc.m_spPalette)
            {
                if (!pkOptDest->m_spPalette)
                {
                    void* pal = BSFadeNode::operator new(0x24);
                    pkOptDest->FUN_00a76a60(pal ? new (pal) NiPalette(*kSrc.GetPalette()) : 0);
                }
                else
                    pkOptDest->m_spPalette->FUN_00a8b190(*kSrc.m_spPalette);
            }
            return pkOptDest;
        }
    }
    void* pNewPixelData = BSFadeNode::operator new(0x74);
    return pNewPixelData ? ((NiPixelData*)pNewPixelData)->FUN_00a7c030(kSrc) : 0;
}
}  // namespace fnv_00a76c10

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

struct FUN_00aa27d0
{
    FUN_00aa27d0(const char* pcPath);

    char m_acPrefix[0x103];
    char m_acPath[0x301];
};

class Loader766
{
  public:
    virtual void v00();
    virtual bool CanLoad(const char* pcPath);
    virtual void v02();
    virtual bool Load(NiFile* pkFile, void* p4, void* p5, void* p2, void* p3, void* p6);
};

class Owner766
{
  public:
    bool LoadFile(const char* pcFile, void* p2, void* p3, void* p4, void* p5, void* p6);

    char pad[0x80];
    Loader766 m_kLoader;
};

// Builds a path from pcFile, checks the loader can load it, opens the file read-only, and delegates to the loader's Load, deleting the file handle.
// @fnv 0x00a766d0
bool Owner766::LoadFile(const char* pcFile, void* p2, void* p3, void* p4, void* p5, void* p6)
{
    FUN_00aa27d0 kPath(pcFile);
    if (!m_kLoader.CanLoad(kPath.m_acPath))
        return false;
    NiFile* pkFile = NiFile::GetFile(pcFile, NiFile::READ_ONLY, 0x8000);
    if (!pkFile)
        return false;
    if (*pkFile)
    {
        if (m_kLoader.Load(pkFile, p4, p5, p2, p3, p6))
        {
            delete pkFile;
            return true;
        }
        delete pkFile;
        return false;
    }
    delete pkFile;
    return false;
}

struct Fmt
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShift[4];
    unsigned char m_aucBits[4];
};
static inline unsigned short Chan(unsigned int p, const Fmt* s, const Fmt* d, int c)
{
    unsigned char v = (unsigned char)((p & s->m_auiMask[c]) >> s->m_aucShift[c]);
    v = (unsigned char)(v << s->m_aucBits[c]);
    v = (unsigned char)(v >> d->m_aucBits[c]);
    return (unsigned short)((unsigned short)v << d->m_aucShift[c]) & (unsigned short)d->m_auiMask[c];
}
// Converts each 16-bit source pixel to the destination format by remapping its four channels through Chan and OR-ing them together.
// @fnv 0x00a76d70
void FUN_00a76d70(unsigned int uiWidth, unsigned int uiHeight, unsigned int, unsigned char* pucDst, unsigned int,
                  const Fmt* pDstFmt, const unsigned char* pucSrc, const Fmt* pSrcFmt)
{
    const unsigned short* pSrcPixels = (const unsigned short*)pucSrc;
    unsigned short* pDstPixels = (unsigned short*)pucDst;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *pDstPixels++ = Chan(*pSrcPixels, pSrcFmt, pDstFmt, 1) | Chan(*pSrcPixels, pSrcFmt, pDstFmt, 0) |
                            Chan(*pSrcPixels, pSrcFmt, pDstFmt, 2) | Chan(*pSrcPixels, pSrcFmt, pDstFmt, 3);
            pSrcPixels++;
        }
    }
}

struct NiPalette;
struct PixelFormatBitLayout;
void __cdecl FUN_00a76d70(unsigned int, unsigned int, unsigned int, unsigned char*, NiPalette const*,
                          PixelFormatBitLayout const&, unsigned char const*, PixelFormatBitLayout const&);

// @fnv 0x00a76e90
void __cdecl FUN_00a76e90(unsigned int a, unsigned int b, unsigned int c, unsigned char* d, NiPalette const* e,
                          PixelFormatBitLayout const& f, unsigned char const* g, PixelFormatBitLayout const& h)
{
    FUN_00a76d70(a, b, c, d, e, f, g, h);
}

void __cdecl BuildFullPath(void);

// @fnv 0x00aa29d0
void __cdecl FUN_00aa29d0(void)
{
    BuildFullPath();
}

#include <string.h>
void* _NiMalloc(unsigned int);
extern char* DAT_011f4a78;
int _strcpy_s(char*, unsigned int, const char*);
void _fnv_CopyFilePath(char*, unsigned int, const char*, unsigned int);

struct FileNameComponents
{
    char m_acFullPath[256];
    char m_acDriveLetter[3];
    char m_acFolderPath[256];
    char m_acBaseName[256];
    char m_acExtension[256];

    FileNameComponents(const char* pcPath);
    void SetExt(const char* pcExt)
    {
        _strcpy_s(m_acExtension, 0x100, pcExt);
    }
    void FUN_00aa29d0(char* pcDest, unsigned int uiDestLen);
};

// Populates a buffer from pcPath, setting its extension from DAT_011f4a78 when that value is non-null.
// @fnv 0x00a768b0
char* GetPathWithExtension(const char* pcPath)
{
    char* pcDest = (char*)_NiMalloc(0x104);
    if (DAT_011f4a78)
    {
        FileNameComponents kFilename(pcPath);
        kFilename.SetExt(DAT_011f4a78);
        kFilename.FUN_00aa29d0(pcDest, 0x104);
    }
    else
    {
        _fnv_CopyFilePath(pcDest, 0x104, pcPath, strlen(pcPath));
    }
    return pcDest;
}

namespace fnv_00a76bb0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern long volatile DAT_011f4400;
extern void* DAT_011f4a78;
void _NiFreeAlias(void*) throw();
struct Sub80
{
    void FUN_00a8ada0() throw();
};
struct NiRefObject
{
    unsigned int m_uiRefCount;
    virtual ~NiRefObject()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
};
struct FUN_00a76bb0 : NiRefObject
{
    char m_data[0x778];
    virtual ~FUN_00a76bb0();
    static void operator delete(void*, unsigned int);
};
// Frees and clears DAT_011f4a78, then calls FUN_00a8ada0 on the subobject at offset 0x80.
// @fnv 0x00a76bb0
FUN_00a76bb0::~FUN_00a76bb0()
{
    if (DAT_011f4a78)
        _NiFreeAlias(DAT_011f4a78);
    DAT_011f4a78 = 0;
    ((Sub80*)((char*)this + 0x80))->FUN_00a8ada0();
}
}  // namespace fnv_00a76bb0

struct ImageResult;
struct PathParts
{
    char directory[256];
    char drive[3];
    char extension[256];
    char filename[256];
    char platform[256];
    PathParts(const char*);
    const char* Ext() const
    {
        return extension;
    }
};
struct InputFile
{
    virtual ~InputFile();
    virtual operator bool() const;
    static InputFile* __cdecl FUN_00aa1a20(const char*, int, unsigned);
};
struct ImageLoader
{
    virtual ~ImageLoader();
    virtual bool Supports(const char*) const;
    virtual ImageResult* Read(InputFile&, ImageResult*);
};

struct ImageOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    ImageLoader loader;
    ImageResult* LoadImage(const char* name, ImageResult* destination, InputFile* supplied);
};
// Loads an image from a file path using the loader, returning the result or null on failure.
// @fnv 0x00a767c0
ImageResult* ImageOwner::LoadImage(const char* apPath, ImageResult* destination, InputFile* apInputFile)
{

    PathParts pathParts(apPath);
    if (loader.Supports(pathParts.Ext()))
    {
        InputFile* pInputFile = apInputFile ? apInputFile : InputFile::FUN_00aa1a20(apPath, 0, 32768);
        if (!pInputFile || !*pInputFile)
        {
            delete pInputFile;
            return 0;
        }
        ImageResult* result = loader.Read(*pInputFile, destination);
        if (result)
        {
            delete pInputFile;
            return result;
        }
        delete pInputFile;
    }
    else
    {
        delete apInputFile;
    }
    return 0;
}
