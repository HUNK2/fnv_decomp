// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NID3DSHADERCONSTANTMAP_H
#define FNV_NID3DSHADERCONSTANTMAP_H

#include "layout_support.h"
#include "NiRefObject.h"
#include "layout_support.h"
class Direct3DDeviceInterface;
class NiD3DShaderConstantMap;
class NiD3DShaderProgram;
class NiShaderConstantMap;
class NiShaderConstantMapEntry;
class ShaderPassRenderer;
class GraphicsRenderer;
enum NiGPUProgram__ProgramType
{
    NiGPUProgram__ProgramType_PROGRAM_VERTEX = 0,
    NiGPUProgram__ProgramType_PROGRAM_VERTEX_CLIPPING_PLANES = 1,
    NiGPUProgram__ProgramType_PROGRAM_PIXEL = 2,
    NiGPUProgram__ProgramType_PROGRAM_MAX = 3
};
#pragma pack(push, 4)
class NiShaderConstantMap : public NiRefObject
{
  public:
    // base NiRefObject at +0x0, size 8
    NiGPUProgram__ProgramType m_iProgramType;  // +0x8, 4 bytes
    // NiShaderConstantMap
    // void __cdecl NiShaderConstantMap::*()
    // NiGPUProgram::ProgramType __cdecl NiShaderConstantMap::*()
    // const char* __cdecl NiShaderConstantMap::*()
    // bool __cdecl NiShaderConstantMap::*(const char*, char*, unsigned int, unsigned int&)
    // bool __cdecl NiShaderConstantMap::*(const char*, unsigned int&, unsigned int&)
    // LookUpPredefinedMappingType
    // bool __cdecl NiShaderConstantMap::*(unsigned int, NiFixedString&)
    // bool __cdecl NiShaderConstantMap::*(const char*, unsigned int&)
    // bool __cdecl NiShaderConstantMap::*(unsigned int, NiFixedString&)
    // void __cdecl NiShaderConstantMap::*()
    // void __cdecl NiShaderConstantMap::*()
    // NiShaderConstantMap& __cdecl NiShaderConstantMap::*(const NiShaderConstantMap&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiShaderConstantMap) == 12);
FNV_STATIC_ASSERT(offsetof(NiShaderConstantMap, m_iProgramType) == 8);
#pragma pack(push, 4)
class NiD3DShaderConstantMap : public NiShaderConstantMap
{
  public:
    static void* operator new(unsigned int size);
    NiD3DShaderConstantMap(GraphicsRenderer* renderer, unsigned int type);
    // base NiShaderConstantMap at +0x0, size 12
    NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > m_kEntries;         // +0xC, 16 bytes
    NiTObjectArray<NiPointer<NiShaderConstantMapEntry> > m_kDefinedEntries;  // +0x1C, 16 bytes
    bool m_bHasChanges;                                                      // +0x2C, 1 bytes
    unsigned char layoutPadding2D[3];
    NiD3DShaderProgram* m_pShaderProgram;   // +0x30, 4 bytes
    unsigned int m_uiErrorCode;             // +0x34, 4 bytes
    Direct3DDeviceInterface* m_pD3DDevice;  // +0x38, 4 bytes
    GraphicsRenderer* m_pShaderObject;      // +0x3C, 4 bytes
    ShaderPassRenderer* m_pRenderState;     // +0x40, 4 bytes
    // IsExactKindOf
    // DynamicCast
    // NiD3DShaderConstantMap
    // void __cdecl NiD3DShaderConstantMap::*()
    // bool __cdecl NiD3DShaderConstantMap::*()
    // void __cdecl NiD3DShaderConstantMap::*(bool)
    // unsigned int __cdecl NiD3DShaderConstantMap::*()
    // unsigned int __cdecl NiD3DShaderConstantMap::*()
    // unsigned int __cdecl NiD3DShaderConstantMap::*(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, const void*, bool)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, const void*, bool)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, const void*, bool)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, const void*, bool)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*)
    // void __cdecl NiD3DShaderConstantMap::*(GraphicsRenderer*)
    // const char* __cdecl NiD3DShaderConstantMap::*()
    // bool __cdecl NiD3DShaderConstantMap::*(void*, unsigned int, NiShaderConstantMap::ObjectMappings, NiDynamicEffect*, NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*, NiGeometryBufferData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&, unsigned int)
    // void __cdecl NiD3DShaderConstantMap::*()
    // void __cdecl NiD3DShaderConstantMap::*(NiTObjectArray<NiPointer<NiShaderConstantMapEntry> >*)
    // void __cdecl NiD3DShaderConstantMap::*(Direct3DDeviceInterface*)
    // void __cdecl NiD3DShaderConstantMap::*(ShaderPassRenderer*)
    // const void* __cdecl NiD3DShaderConstantMap::*(NiShaderConstantMapEntry*, NiExtraData*)
    // const void* __cdecl NiD3DShaderConstantMap::*(NiShaderConstantMapEntry*)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(unsigned int, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(unsigned int, NiShaderConstantMapEntry*, unsigned int)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(unsigned int, NiShaderConstantMapEntry*, NiGeometry*, const NiSkinInstance*, const NiPropertyState*, const NiTransform&, const NiBound&, unsigned int)
    // unsigned int __cdecl NiD3DShaderConstantMap::*(unsigned int, NiShaderConstantMapEntry*, unsigned int)
    // NiD3DShaderConstantMap& __cdecl NiD3DShaderConstantMap::*(const NiD3DShaderConstantMap&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiD3DShaderConstantMap) == 68);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_kEntries) == 12);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_kDefinedEntries) == 28);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_bHasChanges) == 44);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_pShaderProgram) == 48);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_uiErrorCode) == 52);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_pD3DDevice) == 56);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_pShaderObject) == 60);
FNV_STATIC_ASSERT(offsetof(NiD3DShaderConstantMap, m_pRenderState) == 64);
#endif
