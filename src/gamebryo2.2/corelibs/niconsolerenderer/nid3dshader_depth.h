#ifndef FNV_NID3DSHADER_DEPTH_H
#define FNV_NID3DSHADER_DEPTH_H


#include "NiMemObject.h"
enum D3DFORMAT
{
    D3DFMT_UNKNOWN = 0
};
class NiPixelFormat;
class Ni2DBuffer;
struct DepthDesc;
struct DepthSurface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual int __stdcall GetDesc(DepthDesc*);
};
struct DepthDesc
{
    unsigned int format;
    unsigned int type, usage, pool, multitype, multiquality, width, height;
};
struct DepthDevice
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual int __stdcall CheckDeviceFormat(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                            unsigned int);
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual int __stdcall CreateDepthStencilSurface(unsigned int, unsigned int, unsigned int, unsigned int,
                                                    unsigned int, unsigned int, DepthSurface**, void*);
};
class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    unsigned char pad[0x5c0];
    unsigned int adapter, deviceType;
    unsigned int unused;
    unsigned int adapterFormat;
};
class NiDX9AdditionalDepthStencilBufferData : public NiMemObject
{
  public:
    void** vtable;
    unsigned int refs;
    Ni2DBuffer* parent;
    NiPixelFormat* format;
    unsigned int preference;
    DepthSurface* surface;
    unsigned int reserved18, reserved1c, d3dFormat, flags;
    static void* operator new(unsigned int) throw();
    NiDX9AdditionalDepthStencilBufferData() throw();
    static NiDX9AdditionalDepthStencilBufferData* Create(DepthDevice*, Ni2DBuffer**, const NiPixelFormat*,
                                                         unsigned int);
};
class Ni2DBuffer
{
  public:
    unsigned int vtable, refs, width, height;
    void SetRefObject(NiDX9AdditionalDepthStencilBufferData*);
};
class NiD3DTextureData
{
  public:
    static D3DFORMAT ConvertPixelFormatToD3DFormat(const NiPixelFormat*);
};
NiPixelFormat* CreatePixelFormat(unsigned int);
char* GetHRESULTText(unsigned int);
class NiD3DDefaultShader
{
  public:
    static void __cdecl SetShaderName(const char*);
};
extern DepthDevice* DAT_0126f0d8;
extern int DAT_011bf400;
extern char DAT_010ef1f0;

#endif
