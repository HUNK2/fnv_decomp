
// src/bsshader/imagespaceeffectwaterfft.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectwaterfft.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ImageSpaceTexture
{
    void* GetTexture();
    void AddRenderedTexture();
};

struct ImageSpaceTextureSet
{
    char _0[0x58];
    ImageSpaceTexture m_kTextureSlot0;
    char _1[0x0f];
    ImageSpaceTexture m_kTextureSlot1;
    char _2[0x0f];
    ImageSpaceTexture m_kTextureSlot2;
    char _3[0x0f];
    ImageSpaceTexture m_kTextureSlot3;
    char _4[0x0f];
    ImageSpaceTexture m_kTextureSlot4;
    char _5[0x1f];
    bool m_bHeaderParsed;
    void FUN_00ba1250();
};

// @fnv 0x00ba1250
void ImageSpaceTextureSet::FUN_00ba1250()
{
    if (m_kTextureSlot2.GetTexture())
        m_kTextureSlot2.AddRenderedTexture();
    if (m_kTextureSlot3.GetTexture())
        m_kTextureSlot3.AddRenderedTexture();
    if (m_kTextureSlot0.GetTexture())
        m_kTextureSlot0.AddRenderedTexture();
    if (m_kTextureSlot1.GetTexture())
        m_kTextureSlot1.AddRenderedTexture();
    if (m_kTextureSlot4.GetTexture())
        m_kTextureSlot4.AddRenderedTexture();
    m_bHeaderParsed = false;
}

struct MemoryManager
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;

struct ImageSpaceEffectParam
{
    int unk00;
};

struct ImageSpaceShaderParam : ImageSpaceEffectParam
{
    ImageSpaceShaderParam();
    void SetSizeEx(int a, int b);
    void SetFloats(int idx, const float* data, unsigned int count);
    void SetReferenceVector(int idx, float x, float y, float z, float w);

    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    char unk54;
    bool bFlag55;
    bool bFlag56;
    char unk57;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
};

struct ShaderParamArray
{
    __declspec(noalias) void SetAt(unsigned int idx, ImageSpaceEffectParam* const& val);
};

struct RenderTarget
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual unsigned int GetWidth(int i);
    virtual unsigned int GetHeight(int i);
};

class NiRenderer
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual RenderTarget* GetDefaultRenderTarget();
};
extern NiRenderer* DAT_011f9508;

extern const float DAT_011add48[16];
extern float DAT_012023e0;
extern float DAT_01013d84;
extern float DAT_01013974;

struct TextureArray
{
    virtual ~TextureArray();
    void** m_pBase;
    void* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};

struct EffectSource
{
    int unk00;
    TextureArray textures;
};

struct ImageSpaceEffectX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ShaderParamArray params;

    void SetTextureArraySize(int count);
    void SetTexture(int idx, void* tex, ImageSpaceEffectParam* param, int mode);
    void SetPass3(int a, int b, int c);
    void SetPass5(int a, int b, int c, int d, int e);
    void SetPass7(int a, int b, int c, int d, int e, int f, int g);
    void SetPass9(int a, int b, int c, int d, int e, int f, int g, int h, int i);
    void SetupShaderPasses(EffectSource* src, int unused);
};

// Configures four shader passes with textures and parameters from src, using the default render target dimensions for inverse scale factors.
// @fnv 0x00bd6bb0
void ImageSpaceEffectX::SetupShaderPasses(EffectSource* apSource, int unused)
{
    SetTextureArraySize(4);
    float width = DAT_011f9508->GetDefaultRenderTarget()->GetWidth(0);
    float height = DAT_011f9508->GetDefaultRenderTarget()->GetHeight(0);
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->SetSizeEx(0, 0x18);
        param->SetFloats(3, DAT_011add48, 0x40);
        param->SetReferenceVector(2, 1.0f / width, 1.0f / height, 0.0f, 0.0f);
        param->bFlag55 = false;
        SetTexture(0, apSource->textures.GetAt(65), param, 2);
        params.SetAt(0, param);
    }
    SetPass3(0, 1, 1);
    params.SetAt(1, 0);
    SetPass5(1, 2, 3, 0, 0);
    SetTexture(1, apSource->textures.GetAt(18), 0, 2);
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->SetSizeEx(0, 3);
        param->SetReferenceVector(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);
        param->bFlag56 = false;
        params.SetAt(2, param);
        SetPass7(2, 1, 2, 4, 0, 1, 0);
        SetTexture(2, apSource->textures.GetAt(51), param, 0);
    }
    {
        ImageSpaceShaderParam* param = new ImageSpaceShaderParam;
        param->SetSizeEx(0, 4);
        param->SetReferenceVector(0, 1.0f, DAT_01013974, DAT_01013d84, DAT_012023e0);
        param->bFlag56 = false;
        params.SetAt(3, param);
        SetPass9(3, 1, 2, 4, 5, 0, 1, 0, 0);
        SetTexture(3, apSource->textures.GetAt(52), param, 0);
    }
}
