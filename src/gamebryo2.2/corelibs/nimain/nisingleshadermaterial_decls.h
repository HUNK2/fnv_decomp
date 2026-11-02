// gamebryo2.2/corelibs/nimain/nisingleshadermaterial_decls.h: declares NiMemObject, NiPixelFormat, Ni2DBuffer, NiDepthStencilBuffer
#ifndef NISINGLESHADERMATERIAL_DECLS_H
#define NISINGLESHADERMATERIAL_DECLS_H
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
};
struct NiPixelFormat
{
    unsigned int unknown;
    unsigned int format;
};
class NiRenderer;
struct NiDepthStencilBuffer;
struct Ni2DBuffer : NiMemObject
{
    virtual ~Ni2DBuffer();
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
    virtual bool CreateRendererData(const NiPixelFormat&, unsigned int);
    unsigned int references, width, height;
    void* rendererData;
    Ni2DBuffer() throw();
};
struct NiDepthStencilBuffer : Ni2DBuffer
{
    virtual ~NiDepthStencilBuffer();
    NiDepthStencilBuffer() throw()
    {}
    static NiDepthStencilBuffer* Create(unsigned int, unsigned int, NiRenderer*, const NiPixelFormat&, unsigned int);
};
#endif
