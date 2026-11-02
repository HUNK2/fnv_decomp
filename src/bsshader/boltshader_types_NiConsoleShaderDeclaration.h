// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICONSOLESHADERDECLARATION_H
#define FNV_NICONSOLESHADERDECLARATION_H

#include "layout_support.h"
#include "NiObject.h"
class Direct3DDeviceInterface;
class COMUnknownInterface;
class NiD3DShaderDeclaration;
class NiD3DShaderDeclaration__ShaderRegisterStream;
class NiShaderDeclaration;
class GraphicsRenderer;
class NiRenderer;
class NiD3DVertexDeclaration;
class VertexDeclarationLayout;
class _D3DVERTEXELEMENT9;
#pragma pack(push, 4)
class NiShaderDeclaration : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    // const NiRTTI* __cdecl NiShaderDeclaration::*()
    // void __cdecl NiShaderDeclaration::*()
    // NiShaderDeclaration
    // NiShaderDeclaration& __cdecl NiShaderDeclaration::*(const NiShaderDeclaration&)
    // void __cdecl NiShaderDeclaration::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiShaderDeclaration) == 8);
#pragma pack(push, 4)
class NiD3DShaderDeclaration : public NiShaderDeclaration
{
  public:
    // base NiShaderDeclaration at +0x0, size 8
    GraphicsRenderer* m_pOwnerShader;                                       // +0x8, 4 bytes
    VertexDeclarationLayout* m_pShaderStreamInfo;                           // +0xC, 4 bytes
    Direct3DDeviceInterface* m_pD3DDevice;                                  // +0x10, 4 bytes
    unsigned int m_uiVertexElementCount;                                    // +0x14, 4 bytes
    unsigned int m_uiBufferStride;                                          // +0x18, 4 bytes
    unsigned int m_uiShaderRegisterCount;                                   // +0x1C, 4 bytes
    unsigned int m_uiRegisterStreamCount;                                   // +0x20, 4 bytes
    NiD3DShaderDeclaration__ShaderRegisterStream* m_pShaderRegisterStream;  // +0x24, 4 bytes
    bool m_bHasChanges;                                                     // +0x28, 1 bytes
    unsigned char layoutPadding29[3];
    // void __cdecl NiD3DShaderDeclaration::*()
    // unsigned int __cdecl NiD3DShaderDeclaration::*(NiShaderDeclaration::ShaderParameterType)
    // SetEntry
    // bool __cdecl NiD3DShaderDeclaration::*(unsigned int, unsigned int)
    // bool __cdecl NiD3DShaderDeclaration::*()
    // unsigned int __cdecl NiD3DShaderDeclaration::*()
    // bool __cdecl NiD3DShaderDeclaration::*()
    // void __cdecl NiD3DShaderDeclaration::*()
    // void __cdecl NiD3DShaderDeclaration::*()
    // NiD3DShaderDeclaration
    // bool __cdecl NiD3DShaderDeclaration::*(NiRenderer*, unsigned int, unsigned int)
    // void __cdecl NiD3DShaderDeclaration::*()
    // void __cdecl NiD3DShaderDeclaration::*(NiShaderDeclaration::ShaderParameterType, unsigned int)
    // NiD3DShaderDeclaration& __cdecl NiD3DShaderDeclaration::*(const NiD3DShaderDeclaration&)
    // void __cdecl NiD3DShaderDeclaration::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiD3DShaderDeclaration) == 44);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_pOwnerShader) == 8);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_pShaderStreamInfo) == 12);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_pD3DDevice) == 16);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_uiVertexElementCount) == 20);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_uiBufferStride) == 24);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_uiShaderRegisterCount) == 28);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_uiRegisterStreamCount) == 32);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_pShaderRegisterStream) == 36);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderDeclaration, m_bHasChanges) == 40);
#pragma pack(push, 4)
class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    // base NiD3DShaderDeclaration at +0x0, size 44
    _D3DVERTEXELEMENT9* m_pkVertexElements;         // +0x2C, 4 bytes
    COMUnknownInterface* m_pkD3DVertexDeclaration;  // +0x30, 4 bytes
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
    // void __cdecl NiD3DVertexDeclaration::*()
    // NiD3DVertexDeclaration* __cdecl NiD3DVertexDeclaration::*(NiRenderer*, unsigned int, unsigned int)
    // SetEntry
    // bool __cdecl NiD3DVertexDeclaration::*(unsigned int, unsigned int)
    // bool __cdecl NiD3DVertexDeclaration::*(unsigned int)
    // unsigned int __cdecl NiD3DVertexDeclaration::*()
    // NiVBChip* __cdecl NiD3DVertexDeclaration::*(NiGeometryData*, NiSkinInstance*, NiSkinPartition::Partition*, unsigned short, NiVBChip*, unsigned int, void*)
    // bool __cdecl NiD3DVertexDeclaration::*(COMUnknownInterface*&, unsigned int&)
    // unsigned int __cdecl NiD3DVertexDeclaration::*(unsigned int)
    // COMUnknownInterface* __cdecl NiD3DVertexDeclaration::*()
    // bool __cdecl NiD3DVertexDeclaration::*(_D3DDECLUSAGE, unsigned int, NiShaderDeclaration::ShaderParameter&, NiShaderDeclaration::ShaderParameterType&, NiShaderDeclaration::ShaderParameterUsage&, NiD3DShaderDeclaration::ShaderParameterTesselator&)
    // NiD3DVertexDeclaration
    // NiD3DVertexDeclaration& __cdecl NiD3DVertexDeclaration::*(const NiD3DVertexDeclaration&)
    // void __cdecl NiD3DVertexDeclaration::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiD3DVertexDeclaration) == 52);
FNV_STATIC_ASSERT(offsetof(NiD3DVertexDeclaration, m_pkVertexElements) == 44);
FNV_STATIC_ASSERT(offsetof(NiD3DVertexDeclaration, m_pkD3DVertexDeclaration) == 48);
#endif
