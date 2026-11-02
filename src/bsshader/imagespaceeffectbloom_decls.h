// bsshader/imagespaceeffectbloom_decls.h: declares MemoryManager, RgbaColor, ImageSpaceShaderParam, RenderStateMap, ImageSpaceManager
#ifndef FNV_IMAGESPACEEFFECTBLOOM_DECLS_H
#define FNV_IMAGESPACEEFFECTBLOOM_DECLS_H


// the allocation entry points use the canonical MemoryManager signatures.
class IMemoryHeap;
class MemoryManager
{
  public:
    unsigned char layoutPadding0[297];
    bool m_bPoolAllocationEnabled;
    unsigned char layoutPadding12A[2];
    void* Allocate(unsigned int size);
    void Deallocate(void* pointer);
};
extern MemoryManager g_memoryManager;

template <class T> class NiTMallocInterface
{
};
template <class T, class Allocator> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, const T& item);
};
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
};

class ImageSpaceTexture;
class ImageSpaceEffect;
class ImageSpaceEffectParam;
class ImageSpaceShaderParam;
class BSRenderedTexture;
class NiTexture;
class NiD3DShaderConstantMap;

class ImageSpaceEffectParam
{
  public:
    virtual ~ImageSpaceEffectParam();
    NiTPrimitiveArray<int> m_kTextureTypes;
    NiTPrimitiveArray<int> m_kFilterModes;
};

class RgbaColor
{
  public:
    float r, g, b, a;
};

class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    int m_eShaderFilterMode;
    int m_eClearFlags;
    RgbaColor m_eTextureClampMode;
    float* m_pfVertexShaderConstants;
    int m_iVertexShaderConstantCount;
    float* m_pfPixelShaderConstants;
    int m_iPixelShaderConstantCount;
    NiD3DShaderConstantMap* m_pVertexShaderConstantMap;
    NiD3DShaderConstantMap* m_pPixelShaderConstantMap;
    bool m_bTextureFlags[3];
    unsigned char layoutPadding57[1];
    NiTPrimitiveArray<NiTexture*> m_kShaderTextures;
    NiTPrimitiveArray<int> m_kTextureFilterModes;
    struct RenderStateMap
    {
        void** m_ppVirtualMethodTable;
        unsigned int m_uiHashSize;
        void* m_ppkHashTable;
        unsigned int m_uiCount;
    } m_kRenderStateMap;

    ImageSpaceShaderParam();
    void AllocateShaderConstants(int vertexCount, int pixelCount);
    void SetShaderConstantVector4(int index, float x, float y, float z, float w);
    static void* operator new(unsigned int size) throw()
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
    virtual ~ImageSpaceEffect();
    bool bIsActive;
    bool bParamsChanged;
    unsigned char layoutPadding6[2];
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    NiTPrimitiveArray<ImageSpaceEffectParam*> pEffectParamList;
    NiTPrimitiveArray<ImageSpaceTexture*> pTextures;
    struct ImageSpaceEffectInput;
    NiTPrimitiveArray<ImageSpaceEffectInput*> pEffectInputs;
    NiTPrimitiveArray<int> pEffectOutput;
    void SetTextureArrayCount(int count);
    void SetEffectAt(int index, ImageSpaceEffect* effect, ImageSpaceEffectParam* param, int output);
    // No identity candidate is available for the one-input setup helper.
    void SetEffectParamAt(int effectIndex, int textureIndex, int filterMode);
};

// Only the PC prefix read by Setup is required here.
class ImageSpaceManager
{
  public:
    BSRenderedTexture* m_pCurrentRenderedTexture;
    NiTPrimitiveArray<ImageSpaceEffect*> pEffectList;
    ImageSpaceEffect* GetEffect(int index)
    {
        return pEffectList.m_pBase[index];
    }
};

class BloomImageSpaceEffect : public ImageSpaceEffect
{
  public:
    void Setup(ImageSpaceManager* manager, ImageSpaceEffectParam* param);
};

extern float DAT_012023f4;
extern float DAT_012023f8;

typedef char BloomShaderParamSizeCheck[sizeof(ImageSpaceShaderParam) == 0x88 ? 1 : -1];
typedef char BloomEffectSizeCheck[sizeof(ImageSpaceEffect) == 0x58 ? 1 : -1];
#endif
