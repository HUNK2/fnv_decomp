// gamebryo2.2/corelibs/nimain/niddsreader_decls_decl_niddsreader.h: declares NiPixelFormat, NiImageReader, NiBMPReader
#ifndef NIDDSREADER_DECLS_H
#define NIDDSREADER_DECLS_H
class NiPixelFormat
{
  public:
    bool operator!=(const NiPixelFormat& other) const;  // declared for the original code (decl_variants.py)

  public:
    NiPixelFormat();
    bool operator==(const NiPixelFormat&) const;
    unsigned char flags, bits;
    unsigned short pad;
    unsigned int data[16];
};
extern const NiPixelFormat DAT_011aa2e8;
extern void(__stdcall* DAT_00fdf054)(void*);
class NiImageReader
{
  public:
    virtual void vfn_0();
    unsigned char pad[124];
    unsigned char lock[128];
    NiImageReader()
    {
        DAT_00fdf054(lock);
    }
};
class NiBMPReader : public NiImageReader
{
  public:
    unsigned int height, width;
    NiPixelFormat format;
    unsigned short unknown;
    unsigned short padding;
    unsigned int x, y;
    bool b1, b2;
    virtual void vfn_0();
    NiBMPReader();
};
#endif
