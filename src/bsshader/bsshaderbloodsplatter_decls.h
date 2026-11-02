// bsshader/bsshaderbloodsplatter_decls.h: declares NiD3DVertexShader, NiD3DPixelShader, BeamStage, D3DRenderStateGroup, NiD3DPass
#ifndef BSSHADERBLOODSPLATTER_DECLS_H
#define BSSHADERBLOODSPLATTER_DECLS_H

#include "bsshaderbloodsplatter_types_BSShaderBloodSplatter.h"

class NiD3DVertexShader : public NiRefObject
{
};
class NiD3DPixelShader : public NiRefObject
{
};

#define SPLATTER_ASSIGN(T)                                                                                             \
    inline NiPointer<T>& NiPointer<T>::operator=(T* object)                                                            \
    {                                                                                                                  \
        if (m_pObject != object)                                                                                       \
        {                                                                                                              \
            T* old = m_pObject;                                                                                        \
            if (old)                                                                                                   \
                old->DecRefCount();                                                                                    \
            m_pObject = object;                                                                                        \
            if (m_pObject)                                                                                             \
                m_pObject->IncRefCount();                                                                              \
        }                                                                                                              \
        return *this;                                                                                                  \
    }
SPLATTER_ASSIGN(NiD3DVertexShader)
SPLATTER_ASSIGN(NiD3DPixelShader)

class BeamStage
{
  public:
    unsigned char layoutPrefix[0x60];
    unsigned int m_uiRefCount;
    void FUN_00e7def0(unsigned int);
    void ReturnToPool();
    void DecRefCount()
    {
        --m_uiRefCount;
        if (m_uiRefCount == 0)
            ReturnToPool();
    }
    static void CreateNewStage(NiPointer<BeamStage>&);
};
template <> class NiPointer<BeamStage>
{
  public:
    BeamStage* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    BeamStage* operator->() const
    {
        return m_pObject;
    }
    operator BeamStage*() const
    {
        return m_pObject;
    }
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
class NiD3DPass
{
  public:
    unsigned char layoutPrefix[0x14];
    unsigned int m_uiStageMask;
    unsigned char layoutStages[0x18];
    D3DRenderStateGroup* m_pRenderStateGroup;
    unsigned char layoutPixel[0x10];
    NiPointer<NiD3DPixelShader> m_spPixelShaderObject;
    unsigned char layoutVertex[0x14];
    NiPointer<NiD3DVertexShader> m_spVertexShaderObject;
    static void CreateD3DPass(NiPointer<NiD3DPass>&);
    void FUN_00e802b0(unsigned int, BeamStage*);
    void SetRenderState(unsigned int state, unsigned int value, bool save)
    {
        if (!m_pRenderStateGroup)
            m_pRenderStateGroup = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        m_pRenderStateGroup->SetRenderState(state, value, save);
    }
    void SetVertexShader(NiD3DVertexShader* shader)
    {
        m_spVertexShaderObject = shader;
    }
    void SetPixelShader(NiD3DPixelShader* shader)
    {
        m_spPixelShaderObject = shader;
    }
};
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern NiD3DPass* DAT_0126f74c;
#undef SPLATTER_ASSIGN
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_uiStageMask) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_pRenderStateGroup) == 0x30);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spPixelShaderObject) == 0x44);
FNV_STATIC_ASSERT(offsetof(NiD3DPass, m_spVertexShaderObject) == 0x5c);
FNV_STATIC_ASSERT(offsetof(BeamStage, m_uiRefCount) == 0x60);
#endif
