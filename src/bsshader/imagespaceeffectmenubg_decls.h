// bsshader/imagespaceeffectmenubg_decls.h: declares NiTexture, NiTexturingProperty, RgbaColor, NiD3DShaderConstantMap, ImageSpaceShaderParam and more
#ifndef FNV_IMAGESPACEEFFECTMENUBG_DECLS_H
#define FNV_IMAGESPACEEFFECTMENUBG_DECLS_H

#include "layout_support.h"
#include "MemoryManager.h"
#include "NiRefObject.h"

extern MemoryManager g_memoryManager;
extern bool DAT_011f941e;
class NiTexture : public NiRefObject
{
};
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
class ImageSpaceTexture;
class ImageSpaceEffectParam;
class ImageSpaceEffect;

// PC array layout and the operations used by this effect.
template <> class NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceTexture** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, ImageSpaceTexture*& value);
};
template <> class NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> >
{
  public:
    virtual ~NiTArray();
    ImageSpaceEffectParam** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetAt(unsigned int index, ImageSpaceEffectParam* const& value);
};

class NiTexturingProperty
{
  public:
    enum FilterMode
    {
        FILTER_NEAREST,
        FILTER_BILERP,
        FILTER_TRILERP
    };
    enum ClampMode
    {
        CLAMP_S_CLAMP_T,
        CLAMP_S_WRAP_T,
        WRAP_S_CLAMP_T,
        WRAP_S_WRAP_T
    };
};
class ImageSpaceEffectParam
{
  public:
    void** m_ppVirtualMethodTable;
    NiTArray<int, NiTMallocInterface<int> > m_kTextureTypes;
    NiTArray<NiTexturingProperty::FilterMode, NiTMallocInterface<NiTexturingProperty::FilterMode> > m_kFilterModes;
};
class RgbaColor
{
  public:
    float r, g, b, a;
};
class NiD3DShaderConstantMap : public NiRefObject
{
};
template <class Key, class Value> class NiTMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<Key, Value>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
};
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    NiTexturingProperty::FilterMode m_eShaderFilterMode;  // +0x24
    unsigned int m_eClearFlags;
    RgbaColor m_eTextureClampMode;
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    NiPointer<NiD3DShaderConstantMap> m_pVertexShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    NiTObjectArray<NiPointer<NiTexture> > m_kShaderTextures;
    NiTArray<NiTexturingProperty::FilterMode, NiTMallocInterface<NiTexturingProperty::FilterMode> >
        m_kTextureFilterModes;
    NiTMap<unsigned int, unsigned int> m_kRenderStateMap;
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};
class ImageSpaceTexture
{
  public:
    bool m_bTextureFlag1, m_bTextureFlag2, m_bTextureFlag3;
    NiPointer<NiTexture> pTexture;
    NiTexturingProperty::FilterMode m_eTextureFilterMode;
    NiTexturingProperty::ClampMode m_eClampMode;
    ImageSpaceTexture()
        : m_bTextureFlag1(false), m_bTextureFlag2(false), m_bTextureFlag3(false),
          m_eTextureFilterMode(NiTexturingProperty::FILTER_NEAREST), m_eClampMode(NiTexturingProperty::CLAMP_S_CLAMP_T)
    {}
    void SetTexture(NiTexture* texture);
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};
class ImageSpaceEffect
{
  public:
    void** m_ppVirtualMethodTable;
    bool bIsActive, bParamsChanged;
    NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> > pEffectList;
    NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > pEffectParamList;
    NiTArray<ImageSpaceTexture*, NiTMallocInterface<ImageSpaceTexture*> > pTextures;
    NiTArray<void*, NiTMallocInterface<void*> > pEffectInputs;
    NiTArray<int, NiTMallocInterface<int> > pEffectOutput;
    void SetTextureArrayCount(int count);
    void SetTextureArrayAt(int index, int first, int second, NiTexturingProperty::FilterMode firstFilter,
                           NiTexturingProperty::FilterMode secondFilter);
    void SetEffectAt(int index, ImageSpaceEffect* effect, ImageSpaceEffectParam* parameters, int output);
};
// Only the manager prefix accessed by Setup is needed here.
class ImageSpaceManager
{
  public:
    enum ImageSpaceEffectEnum
    {
        EFFECT_SHADER_MENUBG = 49
    };
    void** m_ppVirtualMethodTable;
    NiTArray<ImageSpaceEffect*, NiTMallocInterface<ImageSpaceEffect*> > pEffectList;
};
class ImageSpaceEffectMenuBackground : public ImageSpaceEffect
{
  public:
    ImageSpaceTexture* m_pBackgroundTexture;
    float m_fBackgroundBlendAmount;
    bool m_bMenuBackgroundEnabled;
    void Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* parameters);
};
class BSShaderManager
{
  public:
    static void GetTexture(const char* path, bool load, NiPointer<NiTexture>& texture, bool first, bool second);
};
FNV_STATIC_ASSERT(sizeof(ImageSpaceTexture) == 16);
FNV_STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 136);
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffect) == 88);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kShaderTextures) == 88);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kRenderStateMap) == 120);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffectMenuBackground, m_pBackgroundTexture) == 88);
#endif
