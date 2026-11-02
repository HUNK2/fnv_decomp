// imagespaceshaderblur_blur_reload_support.h: declares D3DXMACRO, BSShaderManager, BSShaderMacro, Setting, INISettingCollection and more
#ifndef FNV_BLUR_RELOAD_SUPPORT_H
#define FNV_BLUR_RELOAD_SUPPORT_H

// Declaration facts: public yvileapsis/yUI-NVSE CommonLib shader headers;
// NiTArray/ImageSpaceEffect layout follows the accepted bloom declarations
// (decomp/src/bsshader/imagespaceeffectbloom_decls.h).
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
class BSShaderManager
{
  public:
    struct BSShaderMacro
    {
        const char* pcPath;
        D3DXMACRO kMacros[9];
    };
};
typedef char ShaderMacroSize[(sizeof(BSShaderManager::BSShaderMacro) == 76) ? 1 : -1];
class NiD3DPass;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
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
};
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
};
class ImageSpaceTexture;
class ImageSpaceEffectParam;
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
};
typedef char ImageSpaceEffectSizeCheck[sizeof(ImageSpaceEffect) == 88 ? 1 : -1];
class Setting
{
  public:
    virtual ~Setting();
    virtual bool IsPrefSetting() const;
    union Value
    {
        bool b;
        int i;
        unsigned int u;
        float f;
        const char* s;
    };
    Value uValue;
    const char* pKey;
};
class INISettingCollection
{
  public:
    struct Display
    {
        static Setting bDoTestHDR;
    };
};
class BSShader
{
  public:
    virtual ~BSShader();
    virtual void DeleteThis();                     // slot 1
    virtual void GetRTTI();                        // slot 2
    virtual void IsNiNode();                       // slot 3
    virtual void IsFadeNode();                     // slot 4
    virtual void IsMultiBoundNode();               // slot 5
    virtual void IsGeometry();                     // slot 6
    virtual void IsTriBasedGeometry();             // slot 7
    virtual void IsTriStrips();                    // slot 8
    virtual void IsTriShape();                     // slot 9
    virtual void IsSegmentedTriShape();            // slot 10
    virtual void IsResizableTriShape();            // slot 11
    virtual void IsParticlesGeom();                // slot 12
    virtual void IsLineGeometry();                 // slot 13
    virtual void IsBhkNiCollisionObject();         // slot 14
    virtual void IsBhkBlendCollisionObject();      // slot 15
    virtual void IsBhkRigidBody();                 // slot 16
    virtual void IsBhkLimitedHingeConstraint();    // slot 17
    virtual void IsFormInitialized();              // slot 18
    virtual void Initialize();                     // slot 19
    virtual void SetupGeometry();                  // slot 20
    virtual void GetGeometryRenderCount();         // slot 21
    virtual void SetupGeometryShader();            // slot 22
    virtual void UpdateGeometryEffects();          // slot 23
    virtual void RenderPartitionedSkinGeometry();  // slot 24
    virtual void SetupTransformationsAlt();        // slot 25
    virtual void RenderPartitionedGeometry();      // slot 26
    virtual void vPrepareGeometryForRendering();   // slot 27
    virtual void GetGeometryPassCount();           // slot 28
    virtual void RenderUnpartitionedGeometry();    // slot 29
    virtual void SetupTextures();                  // slot 30
    virtual void UpdateConstants();                // slot 31
    virtual void SetBlendAlpha();                  // slot 32
    virtual void SetTestAlpha();                   // slot 33
    virtual void PreRenderSetup();                 // slot 34
    virtual void PostRenderSetup();                // slot 35
    virtual void HasPasses();                      // slot 36
    virtual void GetMaxPasses();                   // slot 37
    virtual void StreamCanSkip();                  // slot 38
    virtual void BuildShaderDeclaration();         // slot 39
    virtual void GetNextPass();                    // slot 40
    virtual void SetAlphaBlend();                  // slot 41
    virtual void SetUsesVertexShader();            // slot 42
    virtual void BindGPUProgram();                 // slot 43
    virtual void CreateShaderConstantMap();        // slot 44
    virtual void ResolveSamplerId();               // slot 45
    virtual void GetShaderInstanceDesc();          // slot 46
    virtual void SelectVertexDeclaration();        // slot 47
    virtual void UseShaderDeclaration();           // slot 48
    virtual void HandleResetDevice();              // slot 49
    virtual void HandleLostDevice();               // slot 50
    virtual void UnloadShader();                   // slot 51
    virtual void BuildVertexShader();              // slot 52
    virtual void IsShaderAvailable();              // slot 53
    virtual void CanRenderGeometry();              // slot 54
    virtual void IsShaderSupported();              // slot 55
    virtual void IsShaderValid();                  // slot 56
    virtual void IsShaderEnabled();                // slot 57
    virtual void SetIsBest();                      // slot 58
    virtual void ResetPasses();                    // slot 59
    virtual void SetRenderPass();                  // slot 60
    virtual void SetShaders();                     // slot 61
    virtual void Func_62();                        // slot 62
    virtual void Func_63();                        // slot 63
    virtual void RestoreSavedStates();             // slot 64
    virtual void RestoreTechnique();               // slot 65
    virtual void ConfigureTextureStages();         // slot 66
    virtual void ConfigureAllTextureStages();      // slot 67
    virtual void StartMultiPass();                 // slot 68
    virtual void StopMultiPass();                  // slot 69
    virtual void GetShaderDeclaration();           // slot 70
    virtual void InitShaderConstants();            // slot 71
    virtual void Reinitialize();                   // slot 72
    virtual void ClearAllTextureStages();          // slot 73
    virtual void ClearTextureStages();             // slot 74
    virtual void Func_75();                        // slot 75
    virtual void CreateD3DPass();                  // slot 76
    virtual void Func_77();                        // slot 77
    virtual void Func_78();                        // slot 78
    unsigned char layoutPadding4[88];              // NiD3DDefaultShader storage, +0x4..+0x5B
    NiPointer<NiD3DPass> spRenderPass;             // +0x5C
    int m_ePass;                                   // +0x60 BSShaderManager::eBSSMPassEnum
    bool m_bIsBest;                                // +0x64
    unsigned char layoutPadding65[3];
    int m_iPassId;  // +0x68
};
typedef char BSShaderSizeCheck[sizeof(BSShader) == 108 ? 1 : -1];
class ImageSpaceEffectShader : public BSShader, public ImageSpaceEffect
{
  public:
    ImageSpaceEffectShader();
    virtual void InitShaders(const BSShaderManager::BSShaderMacro&, const BSShaderManager::BSShaderMacro&, const char*,
                             const char*, const char*);
    virtual void SetupShaderDeclaration();
    virtual void Func_81();
    virtual void SetParameters();
    virtual bool SetupPasses();
};
typedef char ImageSpaceShaderSizeCheck[sizeof(ImageSpaceEffectShader) == 196 ? 1 : -1];
#endif
