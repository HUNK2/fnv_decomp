// Unit-private C++03 declaration closure. No authored helper bodies.
// PC layout and ordered virtual declarations: see NOTES and community_virtual_declarations.json.
#ifndef LIGHTING30_FACTORY_TYPES_H
#define LIGHTING30_FACTORY_TYPES_H

#include <stddef.h>
typedef unsigned int UInt32;
typedef unsigned short UInt16;
#define LIGHTING30_JOIN2(a, b) a##b
#define LIGHTING30_JOIN(a, b) LIGHTING30_JOIN2(a, b)
#define LIGHTING30_ASSERT(x) typedef char LIGHTING30_JOIN(lighting30_assert_, __LINE__)[(x) ? 1 : -1]
LIGHTING30_ASSERT(sizeof(void*) == 4);
class NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiSkinInstance;
class NiGeometryBufferData;
class NiPropertyState;
class NiDynamicEffectState;
class NiTransform;
class NiBound;
class NiShaderDeclaration;
class NiShaderConstantMap;
class NiGPUProgram;
class NiD3DShaderDeclaration;
class NiDX9ShaderDeclaration;
class NiD3DPass;
class NiD3DShaderConstantMap;
class D3DRenderStateGroup;
class NiD3DVertexShader;
class NiD3DPixelShader;
class NiShaderConstantMapEntry;
class Lighting30ShaderProperty;
class GraphicsRenderer;
class ShaderPassRenderer;
class NiDX9RenderState;
class NiDX9VertexBufferManager;
class NiVBChip;
class NiGeometryData;
class CloningProcess;
class NiStream;
class NiObjectGroup;
class NiControllerManager;
struct IDirect3DDevice9;
struct IDirect3DVertexDeclaration9;
typedef IDirect3DDevice9* LPDIRECT3DDEVICE9;
typedef IDirect3DVertexDeclaration9* LPDIRECT3DVERTEXDECLARATION9;
template <class T> class NiTPrimitiveArray;
typedef NiTPrimitiveArray<char*> NiViewerStringsArray;
class NiSkinPartition
{
  public:
    class Partition;
};
class NiAlphaProperty
{
  public:
    enum AlphaFunction
    {
        ONE,
        ZERO,
        SRC_COLOR,
        INV_SRC_COLOR,
        DEST_COLOR,
        INV_DEST_COLOR,
        SRC_ALPHA,
        INV_SRC_ALPHA,
        DEST_ALPHA,
        INV_DEST_ALPHA,
        SRC_ALPHA_SAT,
        COUNT
    };
};
class BSShaderManager
{
  public:
    enum RenderPassType
    {
        BSSM_EMPTY = 0
    };
};
class BSShaderProperty;
class NiFixedString
{
  public:
    char* m_kHandle;
};
class RgbaColor
{
  public:
    float r, g, b, a;
};
class NiPoint4
{
  public:
    float x, y, z, w;
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
};
class NiMemObject
{
  public:
    static void* __cdecl operator new(size_t);
    static void __cdecl operator delete(void*);
};
class NiRefObject : public NiMemObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
LIGHTING30_ASSERT(sizeof(NiRefObject) == 8);
class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsNiNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;
    virtual NiObject* MakeClone(CloningProcess* apCloning);
    virtual void LoadBinary(NiStream* apStream);
    virtual void LinkObject(NiStream* apStream);
    virtual void RegisterStreamables(NiStream* apStream);
    virtual void SaveBinary(NiStream* apStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void AddViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess* apCloning);
    virtual void PostLinkObject(NiStream* apStream);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(NiBound* apNewBound);
    virtual void GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup* apGroup);
    virtual NiControllerManager* IsControllerManager() const;
};
LIGHTING30_ASSERT(sizeof(NiObject) == 8);
class NiShader : public NiRefObject
{
  public:
    virtual ~NiShader();
    virtual NiRTTI* GetRTTI();
    virtual NiNode* IsNiNode();
    virtual BSFadeNode* IsFadeNode();
    virtual BSMultiBoundNode* IsMultiBoundNode();
    virtual NiGeometry* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeometry();
    virtual NiTriStrips* IsTriStrips();
    virtual NiTriShape* IsTriShape();
    virtual BSSegmentedTriShape* IsSegmentedTriShape();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual NiParticles* IsParticlesGeom();
    virtual NiLines* IsLineGeometry();
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject();
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject();
    virtual bhkRigidBody* IsBhkRigidBody();
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint();
    virtual bool IsFormInitialized();
    virtual void Initialize();
    virtual bool SetupGeometry(NiGeometry* apGeometry);
    virtual UInt32 GetGeometryRenderCount(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                          NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                          const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                          const NiBound& arWorldBound);
    virtual void SetupGeometryShader(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                     NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                     const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                     const NiBound& arWorldBound);
    virtual void UpdateGeometryEffects(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                       NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                       const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                       const NiBound& arWorldBound);
    virtual UInt32 RenderPartitionedSkinGeometry(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                                 const NiSkinPartition::Partition* apPartition,
                                                 NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                                 const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                                 const NiBound& arWorldBound);
    virtual UInt32 SetupTransformationsAlt(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                           const NiSkinPartition::Partition* apPartition,
                                           NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                           const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                           const NiBound& arWorldBound);
    virtual UInt32 RenderPartitionedGeometry(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                             const NiSkinPartition::Partition* apPartition,
                                             NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                             const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                             const NiBound& arWorldBound);
    virtual NiGeometryBufferData* vPrepareGeometryForRendering(NiGeometry* apGeometry,
                                                               const NiSkinPartition::Partition* apPartition,
                                                               NiGeometryBufferData* apRendererData,
                                                               const NiPropertyState* apState);
    virtual UInt32 GetGeometryPassCount(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                        const NiSkinPartition::Partition* apPartition,
                                        NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                        const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                        const NiBound& arWorldBound);
    virtual UInt32 RenderUnpartitionedGeometry(NiGeometry* apGeometry, const NiSkinInstance* apSkin,
                                               NiGeometryBufferData* apRendererData, const NiPropertyState* apState,
                                               const NiDynamicEffectState* apEffects, const NiTransform& arWorld,
                                               const NiBound& arWorldBound);
    virtual void SetupTextures(NiPropertyState* apState);
    virtual void UpdateConstants(NiPropertyState* apState);
    virtual void SetBlendAlpha(NiPropertyState* apState);
    virtual void SetTestAlpha(NiPropertyState* apState);
    virtual void PreRenderSetup(NiPropertyState* apState, bool abFirstPass);
    virtual void PostRenderSetup(NiPropertyState* apState);
    virtual int HasPasses();
    virtual int GetMaxPasses();
    virtual void StreamCanSkip();
    virtual NiShaderDeclaration* BuildShaderDeclaration(UInt32 auiMaxStreamEntryCount, UInt32 auiStreamCount = 1);
    virtual bool GetNextPass(UInt32& auiPassId);
    virtual bool SetAlphaBlend(UInt32 auiPassId, bool abAlphaBlend, bool abUsePreviousSrcBlendMode,
                               NiAlphaProperty::AlphaFunction aeSrcBlendMode, bool abUsePreviousDestBlendMode,
                               NiAlphaProperty::AlphaFunction aeDestBlendMode);
    virtual void SetUsesVertexShader(bool abUses);
    virtual bool BindGPUProgram(UInt32 auiPassId, NiGPUProgram* apProgram, UInt32& auiProgramId);
    virtual NiShaderConstantMap* CreateShaderConstantMap(UInt32 auiPassId, UInt32 auiProgramId);
    virtual bool ResolveSamplerId(UInt32 auiPassId, UInt32& auiSamplerId, const NiFixedString& arSemantic,
                                  const NiFixedString& arVariableName, UInt32 auiInstance = 0);
    virtual void* GetShaderInstanceDesc();
    NiFixedString m_kName;
    UInt32 m_uiShaderIdentifier;
    bool m_bShaderEnabled;
};
LIGHTING30_ASSERT(sizeof(NiShader) == 0x14);
class NiD3DShaderInterface : public NiShader
{
  public:
    virtual ~NiD3DShaderInterface();
    virtual NiD3DShaderDeclaration* SelectVertexDeclaration();
    virtual void UseShaderDeclaration(NiD3DShaderDeclaration* pkShaderDecl);
    virtual void HandleResetDevice(void* pkShaderDecl);
    virtual void HandleLostDevice();
    virtual void UnloadShader();
    virtual bool BuildVertexShader();
    virtual bool IsShaderAvailable();
    virtual bool CanRenderGeometry();
    virtual bool IsShaderSupported();
    virtual bool IsShaderValid();
    virtual bool IsShaderEnabled();
    virtual void SetIsBest(bool bIsBest);
    LPDIRECT3DDEVICE9 m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    NiDX9RenderState* m_pRenderState;
    bool m_bShaderState;
};
LIGHTING30_ASSERT(sizeof(NiD3DShaderInterface) == 0x24);
class NiD3DShader : public NiD3DShaderInterface
{
  public:
    virtual ~NiD3DShader();
    virtual void ResetPasses();
    bool m_bIsInitialized;
    bool m_bSoftwareVertexProcessing;
    NiPointer<NiD3DShaderDeclaration> m_spShaderDeclaration;
    D3DRenderStateGroup* m_pRenderStateGroup;
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
    UInt32 m_uiShaderType;
};
LIGHTING30_ASSERT(sizeof(NiD3DShader) == 0x3c);
class NiD3DDefaultShader : public NiD3DShader
{
  public:
    enum PassFogStatus
    {
        NO_FOG = 0,
        BLACK_FOG = 1,
        STANDARD_FOG = 2
    };
    bool m_bUseFog;
    bool m_bFogEnabled;
    UInt32 m_uiDefaultShaderFlags;
    UInt32 m_uiPassCount;
    UInt32 m_uiActivePass;
    UInt32 m_uiPassFlags;
    PassFogStatus* m_pPassFogStatus;
    UInt32 m_uiPassFogStatusCount;
    const NiDynamicEffectState* m_pDynamicEffectState;
};
LIGHTING30_ASSERT(sizeof(NiD3DDefaultShader) == 0x5c);
class BSShader : public NiD3DDefaultShader
{
  public:
    virtual void SetRenderPass(UInt32 aeType);
    virtual void SetShaders(BSShaderManager::RenderPassType aeType = BSShaderManager::BSSM_EMPTY);
    virtual void Func_62(UInt32 aeType);
    virtual void Func_63(UInt32 aeType);
    virtual void RestoreSavedStates(UInt32 aeType);
    virtual void RestoreTechnique(UInt32 uiTechnique);
    virtual void ConfigureTextureStages();
    virtual void ConfigureAllTextureStages();
    virtual void StartMultiPass(NiPropertyState* pShaderProps);
    virtual void StopMultiPass();
    virtual NiDX9ShaderDeclaration* GetShaderDeclaration(NiGeometry*, BSShaderProperty* property);
    virtual void InitShaderConstants();
    virtual void Reinitialize();
    virtual void ClearAllTextureStages();
    virtual void ClearTextureStages(NiD3DPass* apPass);
    virtual void Func_75();
    virtual void CreateD3DPass();
    virtual void Func_77();
    virtual void Func_78(UInt32* apeType, int a2);
    NiPointer<NiD3DPass> spRenderPass;
    unsigned int m_ePass;
    bool m_bIsBest;
    int m_iPassId;
};
LIGHTING30_ASSERT(sizeof(BSShader) == 0x6c);
class NiShaderDeclaration : public NiObject
{
  public:
    enum ShaderParameter
    {
        SHADERPARAM_INVALID = 0xFFFFFFFF,
        SHADERPARAM_NI_POSITION = 0x0,
        SHADERPARAM_NI_BLENDWEIGHT = 0x1,
        SHADERPARAM_NI_BLENDINDICES = 0x2,
        SHADERPARAM_NI_NORMAL = 0x3,
        SHADERPARAM_NI_COLOR = 0x4,
        SHADERPARAM_NI_TEXCOORD0 = 0x5,
        SHADERPARAM_NI_TEXCOORD1 = 0x6,
        SHADERPARAM_NI_TEXCOORD2 = 0x7,
        SHADERPARAM_NI_TEXCOORD3 = 0x8,
        SHADERPARAM_NI_TEXCOORD4 = 0x9,
        SHADERPARAM_NI_TEXCOORD5 = 0xA,
        SHADERPARAM_NI_TEXCOORD6 = 0xB,
        SHADERPARAM_NI_TEXCOORD7 = 0xC,
        SHADERPARAM_NI_TANGENT = 0xD,
        SHADERPARAM_NI_BINORMAL = 0xE,
        SHADERPARAM_DATA_ZERO = 0xF,
        SHADERPARAM_DATA_ONE = 0x10,
        SHADERPARAM_SKIP_COUNT_MASK = 0x40000000,
        SHADERPARAM_EXTRA_DATA_MASK = 0x80000000,
    };
    enum ShaderParameterType
    {
        SPTYPE_FLOAT1 = 0x0,
        SPTYPE_FLOAT2 = 0x1,
        SPTYPE_FLOAT3 = 0x2,
        SPTYPE_FLOAT4 = 0x3,
        SPTYPE_UBYTECOLOR = 0x4,
        SPTYPE_UBYTE4 = 0x5,
        SPTYPE_SHORT2 = 0x6,
        SPTYPE_SHORT4 = 0x7,
        SPTYPE_NORMUBYTE4 = 0x8,
        SPTYPE_NORMSHORT2 = 0x9,
        SPTYPE_NORMSHORT4 = 0xA,
        SPTYPE_NORMUSHORT2 = 0xB,
        SPTYPE_NORMUSHORT4 = 0xC,
        SPTYPE_UDEC3 = 0xD,
        SPTYPE_NORMDEC3 = 0xE,
        SPTYPE_FLOAT16_2 = 0xF,
        SPTYPE_FLOAT16_4 = 0x10,
        SPTYPE_NONE = 0x11,
        SPTYPE_COUNT = 0x12,
    };
    enum ShaderParameterUsage
    {
        SPUSAGE_POSITION = 0x0,
        SPUSAGE_BLENDWEIGHT = 0x1,
        SPUSAGE_BLENDINDICES = 0x2,
        SPUSAGE_NORMAL = 0x3,
        SPUSAGE_PSIZE = 0x4,
        SPUSAGE_TEXCOORD = 0x5,
        SPUSAGE_TANGENT = 0x6,
        SPUSAGE_BINORMAL = 0x7,
        SPUSAGE_TESSFACTOR = 0x8,
        SPUSAGE_POSITIONT = 0x9,
        SPUSAGE_COLOR = 0xA,
        SPUSAGE_FOG = 0xB,
        SPUSAGE_DEPTH = 0xC,
        SPUSAGE_SAMPLE = 0xD,
        SPUSAGE_COUNT = 0xE,
    };
    enum ShaderParameterTesselator
    {
        SPTESS_DEFAULT = 0x0,
        SPTESS_PARTIALU = 0x1,
        SPTESS_PARTIALV = 0x2,
        SPTESS_CROSSUV = 0x3,
        SPTESS_UV = 0x4,
        SPTESS_LOOKUP = 0x5,
        SPTESS_LOOKUPPRESAMPLED = 0x6,
        SPTESS_COUNT = 0x7,
    };
    virtual bool SetEntry(UInt32, UInt32, ShaderParameter, ShaderParameterType, UInt32);
    virtual bool RemoveEntry(UInt32, UInt32);
};
class NiD3DShaderDeclaration : public NiShaderDeclaration
{
  public:
    class ShaderStreamInfo;
    virtual bool SetEntryAlt(UInt32, UInt32, UInt32, ShaderParameter, ShaderParameterType, ShaderParameterUsage, UInt32,
                             ShaderParameterTesselator);
    virtual void SetFloatValues(UInt32, UInt32, float*);
    virtual void ClearAllEntries(UInt32);
    virtual UInt32 GetVertexStride(UInt32);
    virtual void SetSoftwareVertexProcessing();
    virtual bool GetSoftwareVertexProcessing();
    virtual NiVBChip* CreateVertexBufferChip(NiGeometryData*, NiSkinInstance*, NiSkinPartition::Partition*, UInt16,
                                             NiVBChip*, UInt32, void*);
    virtual bool GenerateVertexParameters(LPDIRECT3DVERTEXDECLARATION9*, UInt32*);
    virtual LPDIRECT3DVERTEXDECLARATION9 GetD3DDeclaration();
    GraphicsRenderer* m_pOwnerShader;
    NiDX9VertexBufferManager* m_pShaderStreamInfo;
    LPDIRECT3DDEVICE9 m_pD3DDevice;
    UInt32 m_uiVertexElementCount;
    UInt32 m_uiBufferStride;
    UInt32 m_uiShaderRegisterCount;
    UInt32 m_uiRegisterStreamCount;
    ShaderStreamInfo* m_pShaderRegisterStream;
    bool m_bHasChanges;
};
LIGHTING30_ASSERT(sizeof(NiD3DShaderDeclaration) == 0x2c);
struct _D3DVERTEXELEMENT9;
class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    _D3DVERTEXELEMENT9* m_pkVertexElements;
    LPDIRECT3DVERTEXDECLARATION9 m_pkD3DVertexDeclaration;
    static NiD3DVertexDeclaration* Create(GraphicsRenderer*, UInt32, UInt32);
};
LIGHTING30_ASSERT(sizeof(NiD3DVertexDeclaration) == 0x34);
class Lighting30Shader : public BSShader
{
  public:
    virtual void UpdateDiffuseNormalStages(UInt32, Lighting30ShaderProperty*);
    virtual void UpdatePassTextureStages(UInt32, Lighting30ShaderProperty*);
    virtual void SetRenderStatesForPass(UInt32, Lighting30ShaderProperty*);
    virtual void InitializeShaderData();
    virtual void InitializeVertexShader();
    virtual void InitializePixelShader();
    virtual bool ConfigureShaderPass();
    NiPointer<NiD3DShaderConstantMap> m_spFillColorConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFogConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFirstPassConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondPassConstantMap;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration1;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration2;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration3;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration4;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration5;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration6;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration7;
    NiPointer<NiD3DVertexDeclaration> m_pVertexDeclaration8;
    NiGeometryBufferData* m_pGeometryBufferData;
    UInt32 m_uiShaderOptions;
    Lighting30Shader(NiD3DVertexDeclaration*, NiD3DVertexDeclaration*, NiD3DVertexDeclaration*,
                     NiD3DVertexDeclaration*);
    static BSShader* CreateShader();
    static void InvalidateShaderConstants();
};
LIGHTING30_ASSERT(sizeof(Lighting30Shader) == 0xa4);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_spFillColorConstantMap) == 0x6c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_spSecondPassConstantMap) == 0x78);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration1) == 0x7c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration2) == 0x80);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration3) == 0x84);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration4) == 0x88);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration5) == 0x8c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration6) == 0x90);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration7) == 0x94);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pVertexDeclaration8) == 0x98);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_pGeometryBufferData) == 0x9c);
LIGHTING30_ASSERT(offsetof(Lighting30Shader, m_uiShaderOptions) == 0xa0);
extern GraphicsRenderer* g_pkRenderer;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
#endif
