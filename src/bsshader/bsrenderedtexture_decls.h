// bsshader/bsrenderedtexture_decls.h: declares NiRenderedTexture, BSRenderedTexture
#ifndef BSRENDEREDTEXTURE_DECLS_H
#define BSRENDEREDTEXTURE_DECLS_H

struct NiRTTI;
extern NiRTTI DAT_012708e4;
class NiRenderTargetGroup;
class NiRenderedTexture
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual NiRTTI* GetType();
    unsigned char data[0x44];
    unsigned int face;
    __forceinline bool IsExactKindOf(const NiRTTI* type)
    {
        return GetType() == type;
    }
};
class BSRenderedTexture
{
  public:
    unsigned char base[8];
    NiRenderTargetGroup* m_apRenderTargetGroups[6];
    char middle_pad20[4];
    char m_acDataAtOffset36[4];
    char m_acDataAtOffset40[4];
    int m_iDataAtOffset44;
    NiRenderedTexture* spTexture[4];
    NiRenderTargetGroup* GetGroup();
};
#endif
