// MSVC9 SP1 layout check: PASS
// CodeView tag codeview-tag-layout:sha256:36e0a9263f6adaa82628844d2452e2877a9895682d5dc437b88709308025b9f0; PC corrections inherited from generate_headers.py.
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef WATERSHADER_DECLS_H
#define WATERSHADER_DECLS_H

#define NiPointer FNV_STUB_NiPointer
#include "layout_support.h"
#include "NiFixedString.h"
#define FNV_NIMEMOBJECT_H
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
#include "NiRefObject.h"
#undef NiPointer
// Game NiPointer: the research stub omits the default ctor, but the
// original TU was compiled with it (member arrays are implicitly
// constructed via eh_vector_constructor_iterator, singles inline to
// plain zero stores). Bodies are the stub’s verbatim plus the ctor.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer()
    {
        m_pObject = 0;
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
};
#include "layout_support.h"
class BeamStage;
class BSShader;
class Direct3DDeviceInterface;
class WaterShader;
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
class NiD3DDefaultShader;
class NiD3DDefaultShader__PassFogStatus;
class NiD3DPass;
class NiD3DPixelShader;
class D3DRenderStateGroup;
class NiD3DShader;
class NiD3DShaderConstantMap;
class NiD3DShaderDeclaration;
class NiD3DShaderInterface;
class NiD3DVertexShader;
class NiDynamicEffectState;
class NiScreenElements;
class NiShader;
class NiTexture;
class ShaderPassRenderer;
class GraphicsRenderer;
enum BSShaderManager__eBSSMPassEnum
{
    BSSM_DISABLED = 0
};
#pragma pack(push, 4)
class NiShader : public NiRefObject
{
  public:
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
    virtual bool Initialize();
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
    virtual void UseShaderDeclaration(NiD3DShaderDeclaration*);
    // base NiRefObject at +0x0, size 8
    NiFixedString m_kName;              // +0x8, 4 bytes
    unsigned int m_uiShaderIdentifier;  // +0xC, 4 bytes
    bool m_bShaderEnabled;              // +0x10, 1 bytes
    unsigned char layoutPadding11[3];
    // IsExactKindOf
    // DynamicCast
    // NiShader
    // void __cdecl NiShader::*()
    // const NiFixedString& __cdecl NiShader::*()
    // unsigned int __cdecl NiShader::*()
    // void __cdecl NiShader::*(const NiFixedString&)
    // void __cdecl NiShader::*(unsigned int)
    // NiShader& __cdecl NiShader::*(const NiShader&)
    // void __cdecl NiShader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiShader) == 20);
FNV_STATIC_ASSERT(offsetof(NiShader, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiShader, m_uiShaderIdentifier) == 12);
FNV_STATIC_ASSERT(offsetof(NiShader, m_bShaderEnabled) == 16);
#pragma pack(push, 4)
class NiD3DShaderInterface : public NiShader
{
  public:
    // base NiShader at +0x0, size 20
    Direct3DDeviceInterface* m_pD3DDevice;  // +0x14, 4 bytes
    GraphicsRenderer* m_pShaderObject;      // +0x18, 4 bytes
    ShaderPassRenderer* m_pRenderState;     // +0x1C, 4 bytes
    bool m_bShaderState;                    // +0x20, 1 bytes
    unsigned char layoutPadding21[3];
    // const NiRTTI* __cdecl NiD3DShaderInterface::*()
    // void __cdecl NiD3DShaderInterface::*(Direct3DDeviceInterface*)
    // void __cdecl NiD3DShaderInterface::*(ShaderPassRenderer*)
    // void __cdecl NiD3DShaderInterface::*(GraphicsRenderer*)
    // unsigned int __cdecl NiD3DShaderInterface::*(GraphicsRenderer*)
    // unsigned int __cdecl NiD3DShaderInterface::*()
    // NiD3DShaderInterface
    // void __cdecl NiD3DShaderInterface::*()
    // bool __cdecl NiD3DShaderInterface::*()
    // NiD3DShaderInterface& __cdecl NiD3DShaderInterface::*(const NiD3DShaderInterface&)
    // void __cdecl NiD3DShaderInterface::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiD3DShaderInterface) == 36);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderInterface, m_pD3DDevice) == 20);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderInterface, m_pShaderObject) == 24);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderInterface, m_pRenderState) == 28);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderInterface, m_bShaderState) == 32);
#pragma pack(push, 4)
class NiD3DShader : public NiD3DShaderInterface
{
  public:
    // base NiD3DShaderInterface at +0x0, size 36
    bool m_bIsInitialized;             // +0x24, 1 bytes
    bool m_bSoftwareVertexProcessing;  // +0x25, 1 bytes
    unsigned char layoutPadding26[2];
    NiPointer<NiD3DShaderDeclaration> m_spShaderDeclaration;        // +0x28, 4 bytes
    D3DRenderStateGroup* m_pRenderStateGroup;                       // +0x2C, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;   // +0x30, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;  // +0x34, 4 bytes
    unsigned int m_uiShaderType;                                    // +0x38, 4 bytes
    // const NiRTTI* __cdecl NiD3DShader::*()
    // NiD3DShader
    // void __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*()
    // unsigned int __cdecl NiD3DShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DShader::*(NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DShader::*(NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // NiGeometryData::RendererData* __cdecl NiD3DShader::*(NiGeometry*, const NiSkinPartition::Partition*, NiGeometryData::RendererData*, const NiPropertyState*)
    // unsigned int __cdecl NiD3DShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DShader::*()
    // unsigned int __cdecl NiD3DShader::*()
    // NiD3DShaderDeclaration* __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*(NiD3DShaderDeclaration*)
    // void __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*(NiGeometry*)
    // void __cdecl NiD3DShader::*(NiD3DShader*, NiGeometry*)
    // void __cdecl NiD3DShader::*(NiGeometry*)
    // void __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*(bool)
    // bool __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*(bool)
    // bool __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*()
    // bool __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*(bool)
    // bool __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*(bool)
    // void __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*()
    // void __cdecl NiD3DShader::*(const NiTextureEffect*, BeamStage*, bool, GraphicsRenderer*)
    // NiD3DShader& __cdecl NiD3DShader::*(const NiD3DShader&)
    // void __cdecl NiD3DShader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiD3DShader) == 60);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_bIsInitialized) == 36);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_bSoftwareVertexProcessing) == 37);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_spShaderDeclaration) == 40);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_pRenderStateGroup) == 44);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_spFirstShaderConstantMap) == 48);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_spSecondShaderConstantMap) == 52);
FNV_STATIC_ASSERT(offsetof(NiD3DShader, m_uiShaderType) == 56);
#pragma pack(push, 4)
class NiD3DDefaultShader : public NiD3DShader
{
  public:
    // base NiD3DShader at +0x0, size 60
    bool m_bUseFog;      // +0x3C, 1 bytes
    bool m_bFogEnabled;  // +0x3D, 1 bytes
    unsigned char layoutPadding3E[2];
    unsigned int m_uiDefaultShaderFlags;                  // +0x40, 4 bytes
    unsigned int m_uiPassCount;                           // +0x44, 4 bytes
    unsigned int m_uiActivePass;                          // +0x48, 4 bytes
    unsigned int m_uiPassFlags;                           // +0x4C, 4 bytes
    NiD3DDefaultShader__PassFogStatus* m_pPassFogStatus;  // +0x50, 4 bytes
    unsigned int m_uiPassFogStatusCount;                  // +0x54, 4 bytes
    const NiDynamicEffectState* m_pDynamicEffectState;    // +0x58, 4 bytes
    // const NiRTTI* __cdecl NiD3DDefaultShader::*()
    // NiD3DDefaultShader
    // void __cdecl NiD3DDefaultShader::*()
    // bool __cdecl NiD3DDefaultShader::*()
    // unsigned int __cdecl NiD3DDefaultShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DDefaultShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DDefaultShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // void __cdecl NiD3DDefaultShader::*(bool)
    // void __cdecl NiD3DDefaultShader::*()
    // void __cdecl NiD3DDefaultShader::*()
    // unsigned int __cdecl NiD3DDefaultShader::*(NiGeometry*, const NiSkinInstance*, NiGeometryBufferData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // void __cdecl NiD3DDefaultShader::*(_D3DBLEND, _D3DBLEND, bool, bool)
    // void __cdecl NiD3DDefaultShader::*(const NiTexturingProperty::Map*)
    // BeamStage* __cdecl NiD3DDefaultShader::*(const NiTexturingProperty::Map*, unsigned int)
    // NiD3DDefaultShader& __cdecl NiD3DDefaultShader::*(const NiD3DDefaultShader&)
    // void __cdecl NiD3DDefaultShader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiD3DDefaultShader) == 92);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_bUseFog) == 60);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_bFogEnabled) == 61);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_uiDefaultShaderFlags) == 64);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_uiPassCount) == 68);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_uiActivePass) == 72);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_uiPassFlags) == 76);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_pPassFogStatus) == 80);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_uiPassFogStatusCount) == 84);
FNV_STATIC_ASSERT(offsetof(NiD3DDefaultShader, m_pDynamicEffectState) == 88);
#pragma pack(push, 4)
class BSShader : public NiD3DDefaultShader
{
  public:
    // base NiD3DDefaultShader at +0x0, size 92
    NiPointer<NiD3DPass> spRenderPass;       // +0x5C, 4 bytes
    BSShaderManager__eBSSMPassEnum m_ePass;  // +0x60, 4 bytes
    bool m_bIsBest;                          // +0x64, 1 bytes
    unsigned char layoutPadding65[3];
    int m_iPassId;  // +0x68, 4 bytes
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    BSShader();
    static void GetShaderPath(const char*, char*);
    NiD3DVertexShader* CompileVertexShader(const char*, const _D3DXMACRO*, const char*, const char*);
    NiD3DPixelShader* CompilePixelShader(const char*, const _D3DXMACRO*, const char*, const char*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShader) == 108);
FNV_STATIC_ASSERT(offsetof(BSShader, spRenderPass) == 92);
FNV_STATIC_ASSERT(offsetof(BSShader, m_ePass) == 96);
FNV_STATIC_ASSERT(offsetof(BSShader, m_bIsBest) == 100);
FNV_STATIC_ASSERT(offsetof(BSShader, m_iPassId) == 104);

#pragma pack(push, 4)
class WaterShader : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[74];              // +0x6C, 296 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShader1;     // +0x194, 4 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShader2;     // +0x198, 4 bytes
    NiPointer<NiD3DVertexShader> m_spVertexShader3;     // +0x19C, 4 bytes
    NiPointer<NiD3DPixelShader> m_aspPixelShaders[38];  // +0x1A0, 152 bytes
    NiPointer<NiTexture> m_spFirstTexture;              // +0x238, 4 bytes
    NiPointer<NiTexture> m_spSecondTexture;             // +0x23C, 4 bytes
    NiPointer<NiTexture> m_spThirdTexture;              // +0x240, 4 bytes
    NiPointer<NiTexture> m_spTexture4;                  // +0x244, 4 bytes
    NiPointer<NiTexture> WaterShaderTextures;           // +0x248, 4 bytes
    NiPointer<NiTexture> m_spFourthWaterTexture;        // +0x24C, 4 bytes
    WaterShader();
    static BSShader* CreateShader();
    void InitializeShaderData();
    void UpdateShaderConstants();
    void InitWaterPasses();
    virtual ~WaterShader();
    // const NiRTTI* __cdecl WaterShader::*()
    // WaterShader
    // void __cdecl WaterShader::*()
    // WaterShader* __cdecl WaterShader::*()
    // void __cdecl WaterShader::*(unsigned int)
    // void __cdecl WaterShader::*(unsigned int)
    // void __cdecl WaterShader::*(unsigned int)
    // void __cdecl WaterShader::*(const NiPropertyState*)
    // void __cdecl WaterShader::*(const NiPropertyState*)
    // void __cdecl WaterShader::*(const NiPropertyState*)
    // void __cdecl WaterShader::*()
    // bool __cdecl WaterShader::*()
    // void __cdecl WaterShader::*()
    // void __cdecl WaterShader::*(unsigned int, bool)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*(NiTexture*)
    // NiTexture* __cdecl WaterShader::*()
    // void __cdecl WaterShader::*(NiTexture*)
    // void __cdecl WaterShader::*()
    // void __cdecl WaterShader::*()
    // bool __cdecl WaterShader::*()
    // WaterShader& __cdecl WaterShader::*(const WaterShader&)
    // void __cdecl WaterShader::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WaterShader) == 592);
FNV_STATIC_ASSERT(offsetof(WaterShader, spRenderPass) == 108);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spVertexShader1) == 404);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spVertexShader2) == 408);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spVertexShader3) == 412);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_aspPixelShaders) == 416);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spFirstTexture) == 568);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spSecondTexture) == 572);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spThirdTexture) == 576);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spTexture4) == 580);
FNV_STATIC_ASSERT(offsetof(WaterShader, WaterShaderTextures) == 584);
FNV_STATIC_ASSERT(offsetof(WaterShader, m_spFourthWaterTexture) == 588);

class NiD3DPass
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class NiTexture : public NiRefObject
{
};
class NiGPUProgram : public NiRefObject
{
};
class NiD3DShaderProgram : public NiGPUProgram
{
};
class NiD3DVertexShader : public NiD3DShaderProgram
{
};
class NiD3DPixelShader : public NiD3DShaderProgram
{
};
class NiRenderer;
class NiD3DShaderDeclaration : public NiRefObject
{
  public:
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
    virtual bool SetEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual bool vfn_b4();
};
class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
};
extern NiRenderer* DAT_011f9508;
class NiShaderConstantMapEntry : public NiRefObject
{
};
class NiD3DShaderConstantMap : public NiRefObject
{
  public:
    virtual unsigned int vfn_8(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                               unsigned int, unsigned int, const void*, bool);
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
    virtual unsigned int vfn_68(const char*, unsigned int, unsigned int, const char*, unsigned int, unsigned int,
                                const void*, bool);
    virtual void vfn_6c();
    virtual NiShaderConstantMapEntry* vfn_70(const char*);
    unsigned char constantMapState[0x3c];
    NiD3DShaderConstantMap(GraphicsRenderer*, unsigned int);
};

struct WaterShaderThreadState
{
    unsigned char precedingThreadState[0x2b4];
    int m_uiMemoryContext;
};
extern "C" volatile unsigned int _tls_index;
extern "C" unsigned long __readfsdword(unsigned long);
#pragma intrinsic(__readfsdword)
inline WaterShaderThreadState* WaterShaderGetThreadState()
{
    unsigned int index = _tls_index;
    return reinterpret_cast<WaterShaderThreadState**>(__readfsdword(0x2c))[index];
}
class WaterShaderMemContext
{
    // Valid MEM_CONTEXT values are nonnegative; -1 marks an already-restored guard.
    int previous;

  public:
    WaterShaderMemContext(WaterShaderThreadState* state, int m_uiMemoryContext) : previous(state->m_uiMemoryContext)
    {
        state->m_uiMemoryContext = m_uiMemoryContext;
    }
    void Restore(WaterShaderThreadState* state)
    {
        state->m_uiMemoryContext = previous;
        previous = -1;
    }
    ~WaterShaderMemContext()
    {
        if (previous != -1)
            WaterShaderGetThreadState()->m_uiMemoryContext = previous;
    }
};
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int fnv_particle_shader_renderer_level;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4a0;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4a4;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4a8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4ac;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4b0;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4b4;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4b8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4bc;
extern NiPointer<NiShaderConstantMapEntry> DAT_011ff4c0;
extern float DAT_011ff548[12];
extern float DAT_011ff588[28];
extern float DAT_011ff5f8[4];
extern float DAT_011ff608[8];
extern float DAT_011ff628[4];
extern float DAT_011ff638[8];
extern float DAT_011ff658[68];
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
extern WaterShader* DAT_011ff370;
extern RgbaColor DAT_011ff458;
extern bool DAT_011ff100;
extern bool DAT_011ff102;
extern bool DAT_011ff103;
extern bool DAT_011ff104;
struct WaterShaderFrameState
{
    unsigned int frame;
    short flags;
};
extern WaterShaderFrameState DAT_011ff110;
struct WaterShaderUpdateState
{
    unsigned short count;
    unsigned char active;
};
extern WaterShaderUpdateState DAT_011ff118;
#endif
