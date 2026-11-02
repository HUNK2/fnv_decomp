// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NID3DSHADER_H
#define FNV_NID3DSHADER_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
#include "layout_support.h"
class Direct3DDeviceInterface;
class D3DRenderStateGroup;
class NiD3DShader;
class NiD3DShaderConstantMap;
class NiD3DShaderDeclaration;
class NiD3DShaderInterface;
class NiShader;
class ShaderPassRenderer;
class GraphicsRenderer;
#pragma pack(push, 4)
class NiShader : public NiRefObject
{
  public:
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
    static unsigned int IsRendererActive();
    static void InitializePoint3();
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
#endif
