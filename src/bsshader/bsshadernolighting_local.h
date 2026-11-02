// Local unit header for bsshader/bsshadernolighting.cpp.
// asserts), plus a forward declaration of NiGeometry (opaque parameter) and the
// layout-neutral SelectVertexDeclaration member declaration added to BSShaderNoLighting.
#ifndef FNV_BSSHADERNOLIGHTING_LOCAL_H
#define FNV_BSSHADERNOLIGHTING_LOCAL_H

#include "layout_support.h"
// PC allocation operators absent from the task's minimal shared declaration.
#ifndef FNV_NIMEMOBJECT_H
#define FNV_NIMEMOBJECT_H
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
#endif
#include "NiObject.h"
#include "NiProperty.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
class NiD3DPass;
class NiD3DVertexShader;
class NiD3DPixelShader;
class NiD3DVertexDeclaration;
class NiD3DShaderDeclaration;
template <> class NiPointer<NiD3DPass>
{
  public:
    NiD3DPass* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer();
};
template <> class NiPointer<NiD3DVertexShader>
{
  public:
    NiD3DVertexShader* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer();
};
template <> class NiPointer<NiD3DPixelShader>
{
  public:
    NiD3DPixelShader* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer();
};
template <> class NiPointer<NiD3DVertexDeclaration>
{
  public:
    NiD3DVertexDeclaration* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer();
    operator NiD3DShaderDeclaration*() const;
};
class NiRenderer;
extern NiRenderer* DAT_011f9508;
class NiGeometry;
class NiTransform;
class NiPropertyState;
class NiMaterialProperty;
class BSShaderNoLightingProperty;
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
class NiD3DVertexShader : public NiRefObject
{
};
class NiD3DPixelShader : public NiRefObject
{
};
struct BSNoLightingShaderConfig
{
    const char* path;
    _D3DXMACRO macros[9];
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
template <class T> inline void AssignShader(NiPointer<T>& dest, T* value)
{
    if (dest.m_pObject != value)
    {
        if (dest.m_pObject)
            dest.m_pObject->DecRefCount();
        dest.m_pObject = value;
        if (value)
            value->IncRefCount();
    }
}
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
class NiD3DVertexDeclaration;
class VertexDeclarationLayout;
class _D3DVERTEXELEMENT9;
#pragma pack(push, 4)
class NiShaderDeclaration : public NiObject
{
  public:
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual COMUnknownInterface* GetD3DDeclaration();
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
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
    // base NiD3DShaderDeclaration at +0x0, size 44
    _D3DVERTEXELEMENT9* m_pkVertexElements;         // +0x2C, 4 bytes
    COMUnknownInterface* m_pkD3DVertexDeclaration;  // +0x30, 4 bytes
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

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERPROPERTY_H
#define FNV_BSSHADERPROPERTY_H
#include "layout_support.h"
#include "NiProperty.h"
class BSShaderProperty;
class BSShaderProperty__RenderPassArray;
class NiShadeProperty;
#pragma pack(push, 4)
class NiShadeProperty : public NiProperty
{
  public:
    // base NiProperty at +0x0, size 24
    unsigned short m_uiObjectFlags;  // +0x18, 2 bytes
    unsigned char layoutPadding1A[2];
    int m_iShaderType;  // +0x1C, 4 bytes
    // const NiRTTI* __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*(NiStream&)
    // void __cdecl NiShadeProperty::*(NiStream&)
    // bool __cdecl NiShadeProperty::*(NiStream&)
    // void __cdecl NiShadeProperty::*(NiStream&)
    // bool __cdecl NiShadeProperty::*(NiObject*)
    // NiObject* __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiShadeProperty::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiShadeProperty::*(unsigned short, unsigned short)
    // void __cdecl NiShadeProperty::*(bool, unsigned short)
    // bool __cdecl NiShadeProperty::*(unsigned short)
    // NiShadeProperty
    // void __cdecl NiShadeProperty::*(bool)
    // bool __cdecl NiShadeProperty::*()
    // bool __cdecl NiShadeProperty::*(const NiShadeProperty&)
    // int __cdecl NiShadeProperty::*()
    // int __cdecl NiShadeProperty::*()
    // NiShadeProperty* __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*()
    // int __cdecl NiShadeProperty::*()
    // void __cdecl NiShadeProperty::*()
    // NiShadeProperty& __cdecl NiShadeProperty::*(const NiShadeProperty&)
    // void __cdecl NiShadeProperty::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiShadeProperty) == 32);
FNV_STATIC_ASSERT(offsetof(NiShadeProperty, m_uiObjectFlags) == 24);
FNV_STATIC_ASSERT(offsetof(NiShadeProperty, m_iShaderType) == 28);
#pragma pack(push, 4)
class BSShaderProperty : public NiShadeProperty
{
  public:
    // base NiShadeProperty at +0x0, size 32
    unsigned long ulFlags[2];                                // +0x20, 8 bytes
    float fAlpha;                                            // +0x28, 4 bytes
    float fFadeAlpha;                                        // +0x2C, 4 bytes
    float m_fAmbientReflectionScale;                         // +0x30, 4 bytes
    float m_fSpecularExponent;                               // +0x34, 4 bytes
    int iLastRenderPassState;                                // +0x38, 4 bytes
    BSShaderProperty__RenderPassArray* pRenderPassList;      // +0x3C, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray1;  // +0x40, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray2;  // +0x44, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray3;  // +0x48, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray4;  // +0x4C, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray5;  // +0x50, 4 bytes
    BSShaderProperty__RenderPassArray* m_pRenderPassArray6;  // +0x54, 4 bytes
    int m_iRenderPassCount;                                  // +0x58, 4 bytes
    float fDepthBias;                                        // +0x5C, 4 bytes
    float m_fValueAfterDepthBias;                            // +0x60, 4 bytes
    float m_fEnvironmentMapScale;                            // +0x64, 4 bytes
    // const NiRTTI* __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl BSShaderProperty::*(NiStream&)
    // void __cdecl BSShaderProperty::*(NiStream&)
    // bool __cdecl BSShaderProperty::*(NiStream&)
    // void __cdecl BSShaderProperty::*(NiStream&)
    // bool __cdecl BSShaderProperty::*(NiObject*)
    // NiObject* __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(NiStream&)
    // BSShaderProperty
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // void __cdecl BSShaderProperty::*(int)
    // bool __cdecl BSShaderProperty::*(BSShaderProperty*)
    // bool __cdecl BSShaderProperty::*(unsigned int)
    // void __cdecl BSShaderProperty::*(unsigned int, bool)
    // void __cdecl BSShaderProperty::*(float)
    // float __cdecl BSShaderProperty::*()
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(float)
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(unsigned int)
    // unsigned int __cdecl BSShaderProperty::*()
    // int __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(int)
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(float)
    // void __cdecl BSShaderProperty::*(NiAVObject*)
    // void __cdecl BSShaderProperty::*(NiAVObject*, bool)
    // void __cdecl BSShaderProperty::*(NiAVObject*, BSShaderProperty::EShaderPropertyFlag, bool)
    // bool __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(bool)
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(float)
    // void __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*(unsigned int&)
    // void __cdecl BSShaderProperty::*(bool)
    // float __cdecl BSShaderProperty::*()
    // void __cdecl BSShaderProperty::*()
    // BSShaderProperty& __cdecl BSShaderProperty::*(const BSShaderProperty&)
    // void __cdecl BSShaderProperty::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderProperty) == 104);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, ulFlags) == 32);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, fAlpha) == 40);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, fFadeAlpha) == 44);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fAmbientReflectionScale) == 48);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fSpecularExponent) == 52);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, iLastRenderPassState) == 56);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, pRenderPassList) == 60);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray1) == 64);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray2) == 68);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray3) == 72);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray4) == 76);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray5) == 80);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_pRenderPassArray6) == 84);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_iRenderPassCount) == 88);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, fDepthBias) == 92);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fValueAfterDepthBias) == 96);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty, m_fEnvironmentMapScale) == 100);
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERNOLIGHTING_H
#define FNV_BSSHADERNOLIGHTING_H
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
#include "layout_support.h"
class BSShader;
class BSShaderNoLighting;
class Direct3DDeviceInterface;
class RgbaColor;
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
class NiShader;
class NiShaderConstantMapEntry;
class ShaderPassRenderer;
class GraphicsRenderer;
class NiD3DVertexDeclaration;
enum BSShaderManager__eBSSMPassEnum
{
    BSShaderManager__eBSSMPassEnum_BSSM_DISABLED = 0,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERPASSES_FIRST = 1,
    BSShaderManager__eBSSMPassEnum_BSSM_ZONLY = 1,
    BSShaderManager__eBSSMPassEnum_BSSM_ZONLY_At = 2,
    BSShaderManager__eBSSMPassEnum_BSSM_ZONLY_S = 3,
    BSShaderManager__eBSSMPassEnum_BSSM_ZONLY_TEXEFFECT = 4,
    BSShaderManager__eBSSMPassEnum_BSSM_ZONLY_TEXEFFECT_S = 5,
    BSShaderManager__eBSSMPassEnum_BSSM_CONSTALPHA = 6,
    BSShaderManager__eBSSMPassEnum_BSSM_CONSTALPHA_At = 7,
    BSShaderManager__eBSSMPassEnum_BSSM_CONSTALPHA_S = 8,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_OCCLUSION = 9,
    BSShaderManager__eBSSMPassEnum_BSSM_3XZONLY = 10,
    BSShaderManager__eBSSMPassEnum_BSSM_3XZONLY_S = 11,
    BSShaderManager__eBSSMPassEnum_BSSM_3XZONLY_Vc = 12,
    BSShaderManager__eBSSMPassEnum_BSSM_3XZONLY_SVc = 13,
    BSShaderManager__eBSSMPassEnum_BSSM_3XZONLY_TEXEFFECT = 14,
    BSShaderManager__eBSSMPassEnum_BSSM_3XZONLY_TEXEFFECT_S = 15,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTHMAP = 16,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTHMAP_At = 17,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTHMAP_S = 18,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTHMAP_SAt = 19,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LF = 20,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LV = 21,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFS = 22,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVS = 23,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFP = 24,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVP = 25,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFSP = 26,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVSP = 27,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFShp = 28,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVShp = 29,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFSShp = 30,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVSShp = 31,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFPShp = 32,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVPShp = 33,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFSPShp = 34,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LVSPShp = 35,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFB = 36,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFSB = 37,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFPB = 38,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_DIRONLY_LFSPB = 39,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LF = 40,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LV = 41,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFS = 42,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVS = 43,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFP = 44,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVP = 45,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFSP = 46,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVSP = 47,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFShp = 48,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVShp = 49,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFSShp = 50,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVSShp = 51,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFPShp = 52,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVPShp = 53,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFSPShp = 54,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LVSPShp = 55,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFB = 56,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFSB = 57,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFPB = 58,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_NOALPHA_1POINT_LFSPB = 59,
    BSShaderManager__eBSSMPassEnum_BSSM_LEAVES_AD = 60,
    BSShaderManager__eBSSMPassEnum_BSSM_LEAVES_ADPt = 61,
    BSShaderManager__eBSSMPassEnum_BSSM_FRONDS = 62,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDAD = 63,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDAD_Shp = 64,
    BSShaderManager__eBSSMPassEnum_BSSM_PARTICLE_PREPASS = 65,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING = 66,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_VC = 67,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_TexVC = 68,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_MAT = 69,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_S = 70,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_VC_S = 71,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_TexVC_S = 72,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_MAT_S = 73,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_FALLOFF = 74,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_VC_FALLOFF = 75,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_TexVC_FALLOFF = 76,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_MAT_FALLOFF = 77,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_FALLOFF_S = 78,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_VC_FALLOFF_S = 79,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_TexVC_FALLOFF_S = 80,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_MAT_FALLOFF_S = 81,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_PSYS = 82,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_PSYS_SUBTEX_OFFSET = 83,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_PSYS_PREMULT_ALPHA = 84,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_PSYS_SUBTEX_OFFSET_PREMULT_ALPHA = 85,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_STRIP_PSYS = 86,
    BSShaderManager__eBSSMPassEnum_BSSM_NOLIGHTING_STRIP_PSYS_SUBTEX = 87,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_Mn = 88,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_F = 89,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_FAt = 90,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS = 91,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_G = 92,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_H = 93,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_Fg = 94,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_Px = 95,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_GPx = 96,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_S = 97,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SH = 98,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SG = 99,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SFg = 100,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_Sb = 101,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_Shp = 102,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_GShp = 103,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_HShp = 104,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_FgShp = 105,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_PxShp = 106,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_GPxShp = 107,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SShp = 108,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SGShp = 109,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SHShp = 110,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SFgShp = 111,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_SbShp = 112,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2 = 113,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_G = 114,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_H = 115,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_Fg = 116,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_Px = 117,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_GPx = 118,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_S = 119,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SG = 120,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SH = 121,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SFg = 122,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_Sb = 123,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_Shp = 124,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_GShp = 125,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_HShp = 126,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_FgShp = 127,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_PxShp = 128,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_GPxShp = 129,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SShp = 130,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SGShp = 131,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SHShp = 132,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SFgShp = 133,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS2_SbShp = 134,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_ONELIGHT = 135,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS_DIRANDPT = 136,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT10 = 137,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT10_G = 138,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT10_Fg = 139,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT10_S = 140,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT10_SG = 141,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT10_SFg = 142,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4 = 143,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4_Opt = 144,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4_G = 145,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4_Fg = 146,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4_S = 147,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4_SG = 148,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT4_SFg = 149,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10 = 150,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10_Opt = 151,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10_G = 152,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10_Fg = 153,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10_S = 154,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10_SG = 155,
    BSShaderManager__eBSSMPassEnum_BSSM_ADTS10_SFg = 156,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2 = 157,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_G = 158,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_Px = 159,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_GPx = 160,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_Fg = 161,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_S = 162,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_SG = 163,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_SFg = 164,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_Sb = 165,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_Shp = 166,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_GShp = 167,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_PxShp = 168,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_GPxShp = 169,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_FgShp = 170,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_SShp = 171,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_SGShp = 172,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_SFgShp = 173,
    BSShaderManager__eBSSMPassEnum_BSSM_AD2_SbShp = 174,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3 = 175,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_G = 176,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_Px = 177,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_GPx = 178,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_Fg = 179,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_S = 180,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_SG = 181,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_SFg = 182,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_Sb = 183,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_Shp = 184,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_GShp = 185,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_PxShp = 186,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_GPxShp = 187,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_FgShp = 188,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_SShp = 189,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_SGShp = 190,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_SFgShp = 191,
    BSShaderManager__eBSSMPassEnum_BSSM_AD3_SbShp = 192,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT = 193,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Opt = 194,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_OptLOD = 195,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Mn = 196,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_G = 197,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Fg = 198,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Px = 199,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_PxOpt = 200,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_GPx = 201,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_H = 202,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_S = 203,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SG = 204,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SFg = 205,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Sb = 206,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SH = 207,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Shp = 208,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_MnShp = 209,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_GShp = 210,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_FgShp = 211,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_PxShp = 212,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_GPxShp = 213,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_HShp = 214,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SShp = 215,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SGShp = 216,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SFgShp = 217,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SbShp = 218,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_SHShp = 219,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2 = 220,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_G = 221,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_Fg = 222,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_Px = 223,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_GPx = 224,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_H = 225,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_S = 226,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SG = 227,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SFg = 228,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_Sb = 229,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SH = 230,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_Shp = 231,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_GShp = 232,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_FgShp = 233,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_PxShp = 234,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_GPxShp = 235,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_HShp = 236,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SShp = 237,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SGShp = 238,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SFgShp = 239,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SbShp = 240,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT2_SHShp = 241,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2 = 242,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_Fg = 243,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_Px = 244,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_S = 245,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_SFg = 246,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_Sb = 247,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_Shp = 248,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_FgShp = 249,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_PxShp = 250,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_SShp = 251,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_SFgShp = 252,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT2_SbShp = 253,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3 = 254,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_Fg = 255,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_Px = 256,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_S = 257,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_SFg = 258,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_Sb = 259,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_Shp = 260,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_FgShp = 261,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_PxShp = 262,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_SShp = 263,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_SFgShp = 264,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT3_SbShp = 265,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE = 266,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_Fg = 267,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_H = 268,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_S = 269,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_Vc = 270,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_SVc = 271,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_SFg = 272,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_Sb = 273,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_SH = 274,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXTURE_Px = 275,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULAR_START = 276,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR = 276,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_H = 277,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_Px = 278,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_S = 279,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_SH = 280,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_Sb = 281,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_Shp = 282,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_HShp = 283,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_PxShp = 284,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_SShp = 285,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_SHShp = 286,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARDIR_SbShp = 287,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT = 288,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT_H = 289,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT_Px = 290,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT_S = 291,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT_SH = 292,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT_Sb = 293,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT2 = 294,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT2_H = 295,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT2_Px = 296,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT2_S = 297,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT2_SH = 298,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT2_Sb = 299,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT3 = 300,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT3_H = 301,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT3_Px = 302,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT3_S = 303,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT3_SH = 304,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SPECULARPT3_Sb = 305,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULAR_END = 305,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_START = 306,
    BSShaderManager__eBSSMPassEnum_BSSM_3XOCCLUSION = 306,
    BSShaderManager__eBSSMPassEnum_BSSM_3XPLACEHOLDER0 = 307,
    BSShaderManager__eBSSMPassEnum_BSSM_3XPLACEHOLDER1 = 308,
    BSShaderManager__eBSSMPassEnum_BSSM_3XPLACEHOLDER2 = 309,
    BSShaderManager__eBSSMPassEnum_BSSM_3XPLACEHOLDER3 = 310,
    BSShaderManager__eBSSMPassEnum_BSSM_3XPLACEHOLDER4 = 311,
    BSShaderManager__eBSSMPassEnum_BSSM_3XPLACEHOLDER5 = 312,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING = 313,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_S = 314,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_H = 315,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_Px = 316,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_Pxo = 317,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_Fg = 318,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SFg = 319,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_G = 320,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SG = 321,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_Vc = 322,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcS = 323,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPx = 324,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxo = 325,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcG = 326,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSG = 327,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_Spc = 328,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SSpc = 329,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_HSpc = 330,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_PxSpc = 331,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_PxoSpc = 332,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_FgSpc = 333,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SFgSpc = 334,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_GSpc = 335,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SGSpc = 336,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSpc = 337,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSSpc = 338,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxSpc = 339,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxoSpc = 340,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcGSpc = 341,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSGSpc = 342,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_Shp = 343,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SShp = 344,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_HShp = 345,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_PxShp = 346,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_PxoShp = 347,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_FgShp = 348,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SFgShp = 349,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_GShp = 350,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SGShp = 351,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcShp = 352,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSShp = 353,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxShp = 354,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxoShp = 355,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcGShp = 356,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSGShp = 357,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_ShpSpc = 358,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SShpSpc = 359,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_HShpSpc = 360,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_PxShpSpc = 361,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_PxoShpSpc = 362,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_FgShpSpc = 363,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SFgShpSpc = 364,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_GShpSpc = 365,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SGShpSpc = 366,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcShpSpc = 367,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSShpSpc = 368,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxShpSpc = 369,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcPxoShpSpc = 370,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcGShpSpc = 371,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_VcSGShpSpc = 372,
    BSShaderManager__eBSSMPassEnum_BSSM_3XSILHOUETTE = 373,
    BSShaderManager__eBSSMPassEnum_BSSM_3XSILHOUETTE_Vc = 374,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP = 375,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP_W = 376,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP_Vc = 377,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP_WVc = 378,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP_S = 379,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP_SVc = 380,
    BSShaderManager__eBSSMPassEnum_BSSM_3XENVMAP_EYE = 381,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SIMPLESHADOW = 382,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SIMPLESHADOW_Vc = 383,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SIMPLESHADOW_S = 384,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_SIMPLESHADOW_VcS = 385,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTHMAP = 386,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTHMAP_Vc = 387,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTHMAP_S = 388,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTHMAP_VcS = 389,
    BSShaderManager__eBSSMPassEnum_BSSM_3XRENDERNORMALS = 390,
    BSShaderManager__eBSSMPassEnum_BSSM_3XRENDERNORMALS_S = 391,
    BSShaderManager__eBSSMPassEnum_BSSM_3XRENDERNORMALS_FIRE = 392,
    BSShaderManager__eBSSMPassEnum_BSSM_3XRENDERNORMALS_CLEAR = 393,
    BSShaderManager__eBSSMPassEnum_BSSM_3XRENDERNORMALS_CLEAR_S = 394,
    BSShaderManager__eBSSMPassEnum_BSSM_3XCONSTALPHA = 395,
    BSShaderManager__eBSSMPassEnum_BSSM_3XCONSTALPHA_Vc = 396,
    BSShaderManager__eBSSMPassEnum_BSSM_3XCONSTALPHA_S = 397,
    BSShaderManager__eBSSMPassEnum_BSSM_3XCONSTALPHA_SVc = 398,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTH = 399,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTH_Vc = 400,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTH_S = 401,
    BSShaderManager__eBSSMPassEnum_BSSM_3XDEPTH_SVc = 402,
    BSShaderManager__eBSSMPassEnum_BSSM_3XVELOCITY = 403,
    BSShaderManager__eBSSMPassEnum_BSSM_3XVELOCITY_S = 404,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLOCALMAP = 405,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLOCALMAP_S = 406,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLOCALMAP_CLEAR = 407,
    BSShaderManager__eBSSMPassEnum_BSSM_3XTEXEFFECT = 408,
    BSShaderManager__eBSSMPassEnum_BSSM_3XTEXEFFECT_S = 409,
    BSShaderManager__eBSSMPassEnum_BSSM_3XLIGHTING_END = 409,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERNORMALS = 410,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERNORMALS_S = 411,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERNORMALS_FIRE = 412,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERNORMALS_CLEAR = 413,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERNORMALS_CLEAR_S = 414,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTH = 415,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTH_S = 416,
    BSShaderManager__eBSSMPassEnum_BSSM_DEPTH_Mn = 417,
    BSShaderManager__eBSSMPassEnum_BSSM_VELOCITY = 418,
    BSShaderManager__eBSSMPassEnum_BSSM_VELOCITY_S = 419,
    BSShaderManager__eBSSMPassEnum_BSSM_LOCALMAP = 420,
    BSShaderManager__eBSSMPassEnum_BSSM_LOCALMAP_S = 421,
    BSShaderManager__eBSSMPassEnum_BSSM_LOCALMAP_CLEAR = 422,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2xDIFF = 423,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND_G = 424,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDAD_A = 425,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDAD_AShp = 426,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND_GA = 427,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2xDIFF_A = 428,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O = 429,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O_Shp = 430,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O_Simple = 431,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O_SimpleShp = 432,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O4 = 433,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O4_Shp = 434,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O4_Simple = 435,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND1O4_SimpleShp = 436,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O = 437,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O_Shp = 438,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O_Simple = 439,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O_SimpleShp = 440,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O4 = 441,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O4_Shp = 442,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O4_Simple = 443,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND2O4_SimpleShp = 444,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O = 445,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O_Shp = 446,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O_Simple = 447,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O_SimpleShp = 448,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O4 = 449,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O4_Shp = 450,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O4_Simple = 451,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND3O4_SimpleShp = 452,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O = 453,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O_Shp = 454,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O_Simple = 455,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O_SimpleShp = 456,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O4 = 457,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O4_Shp = 458,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O4_Simple = 459,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND4O4_SimpleShp = 460,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O = 461,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O_Shp = 462,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O_Simple = 463,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O_SimpleShp = 464,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O4 = 465,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O4_Shp = 466,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O4_Simple = 467,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND5O4_SimpleShp = 468,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O = 469,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O_Shp = 470,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O_Simple = 471,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O_SimpleShp = 472,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O4 = 473,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O4_Shp = 474,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O4_Simple = 475,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND6O4_SimpleShp = 476,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O = 477,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O_Shp = 478,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O_Simple = 479,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O_SimpleShp = 480,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O4 = 481,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O4_Shp = 482,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O4_Simple = 483,
    BSShaderManager__eBSSMPassEnum_BSSM_LAND7O4_SimpleShp = 484,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDO_Am = 485,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDLO_A = 486,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SIMPLESHADOW = 487,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SIMPLESHADOW_S = 488,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SIMPLESHADOW_LAND = 489,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_SIMPLESHADOW_Sb = 490,
    BSShaderManager__eBSSMPassEnum_BSSM_ADT_Sbb = 491,
    BSShaderManager__eBSSMPassEnum_BSSM_DISTANT_TREE_BASE = 492,
    BSShaderManager__eBSSMPassEnum_BSSM_DISTANT_TREE_SILHOUETTE = 493,
    BSShaderManager__eBSSMPassEnum_BSSM_FIRST_ALPHA_PASS = 494,
    BSShaderManager__eBSSMPassEnum_BSSM_SKYBASEPRE = 494,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY = 495,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY_MOON_STARS_MASK = 496,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY_STARS = 497,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY_TEXTURE = 498,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY_CLOUDS = 499,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY_CLOUDS_UNDERWATER = 500,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_LOD = 501,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_LOD_NO_REFLECTIONS = 502,
    BSShaderManager__eBSSMPassEnum_BSSM_PARTICLE = 503,
    BSShaderManager__eBSSMPassEnum_BSSM_BOLT = 504,
    BSShaderManager__eBSSMPassEnum_BSSM_BEAM = 505,
    BSShaderManager__eBSSMPassEnum_BSSM_ENVMAP_FIRST = 506,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_ENVMAP = 506,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_ENVMAP_S = 507,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_ENVMAP_W = 508,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_ENVMAP_EYE = 509,
    BSShaderManager__eBSSMPassEnum_BSSM_ENVMAP_LAST = 509,
    BSShaderManager__eBSSMPassEnum_BSSM_GEOMDECAL = 510,
    BSShaderManager__eBSSMPassEnum_BSSM_GEOMDECAL_S = 511,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_TEXEFFECT = 512,
    BSShaderManager__eBSSMPassEnum_BSSM_2x_TEXEFFECT_S = 513,
    BSShaderManager__eBSSMPassEnum_BSSM_FOG = 514,
    BSShaderManager__eBSSMPassEnum_BSSM_FOG_A = 515,
    BSShaderManager__eBSSMPassEnum_BSSM_FOG_S = 516,
    BSShaderManager__eBSSMPassEnum_BSSM_FOG_SA = 517,
    BSShaderManager__eBSSMPassEnum_BSSM_FOG_Sb = 518,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_NONFOG_DEPTH = 519,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_SHADE = 520,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_FIRST = 521,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_FRONT = 521,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_BACK = 522,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_SINGLE = 523,
    BSShaderManager__eBSSMPassEnum_BSSM_VFOG_LAST = 523,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LF = 524,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LV = 525,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFS = 526,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVS = 527,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFP = 528,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVP = 529,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFSP = 530,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVSP = 531,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFShp = 532,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVShp = 533,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFSShp = 534,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVSShp = 535,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFPShp = 536,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVPShp = 537,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFSPShp = 538,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LVSPShp = 539,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFB = 540,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFSB = 541,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFPB = 542,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_DIRONLY_LFSPB = 543,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LF = 544,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LV = 545,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFS = 546,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVS = 547,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFP = 548,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVP = 549,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFSP = 550,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVSP = 551,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFShp = 552,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVShp = 553,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFSShp = 554,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVSShp = 555,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFPShp = 556,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVPShp = 557,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFSPShp = 558,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LVSPShp = 559,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFB = 560,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFSB = 561,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFPB = 562,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_1POINT_LFSPB = 563,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_SHADOW_L = 564,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_SHADOW_LS = 565,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_SHADOW_LB = 566,
    BSShaderManager__eBSSMPassEnum_BSSM_GRASS_SHADOW_LSB = 567,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_STENCIL = 568,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_STENCIL_Vc = 569,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_FIRST = 570,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING = 570,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_REFLECTIONS_NO_REFRACTIONS = 571,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_REFRACTIONS = 572,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_REFLECTIONS = 573,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH = 574,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS = 575,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_NO_REFRACTIONS = 576,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS = 577,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING = 578,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS_NO_REFRACTIONS = 579,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_REFRACTIONS = 580,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS = 581,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH = 582,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS = 583,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFRACTIONS = 584,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS = 585,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_SPECULAR_LIGHTING = 586,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_Vc = 587,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_REFLECTIONS_Vc = 588,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_REFRACTIONS_Vc = 589,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 590,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_Vc = 591,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS_Vc = 592,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_NO_REFRACTIONS_Vc = 593,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 594,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_Vc = 595,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS_Vc = 596,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_REFRACTIONS_Vc = 597,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 598,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_Vc = 599,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS_Vc = 600,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFRACTIONS_Vc = 601,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 602,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_SPECULAR_LIGHTING_Vc = 603,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_WADING_LAST = 603,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_FIRST = 604,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER = 604,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NO_REFLECTIONS_NO_REFRACTIONS = 605,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NO_REFRACTIONS = 606,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NO_REFLECTIONS = 607,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR = 608,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NO_REFLECTIONS_NO_REFRACTIONS = 609,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NO_REFRACTIONS = 610,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NO_REFLECTIONS = 611,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH = 612,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_NO_REFLECTIONS = 613,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_NO_REFRACTIONS = 614,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS = 615,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH = 616,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS = 617,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_NO_REFRACTIONS = 618,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS = 619,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_SPECULAR_LIGHTING = 620,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_UNDERWATER = 621,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_Vc = 622,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 623,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NO_REFRACTIONS_Vc = 624,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NO_REFLECTIONS_Vc = 625,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_Vc = 626,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 627,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NO_REFRACTIONS_Vc = 628,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NO_REFLECTIONS_Vc = 629,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_Vc = 630,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_NO_REFLECTIONS_Vc = 631,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_NO_REFRACTIONS_Vc = 632,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 633,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_Vc = 634,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc = 635,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_NO_REFRACTIONS_Vc = 636,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS_Vc = 637,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_SPECULAR_LIGHTING_Vc = 638,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_LAST = 638,
    BSShaderManager__eBSSMPassEnum_BSSM_PRECIPITATION_RAIN = 639,
    BSShaderManager__eBSSMPassEnum_BSSM_SKYBASEPOST = 640,
    BSShaderManager__eBSSMPassEnum_BSSM_SKY_SUNGLARE = 641,
    BSShaderManager__eBSSMPassEnum_BSSM_POST_ALPHA_LAST = 641,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_START = 642,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH = 642,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_S = 643,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH = 644,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_S = 645,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH = 646,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_S = 647,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_At = 648,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_SAt = 649,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_At = 650,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_SAt = 651,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_At = 652,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_At_S = 653,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_Vc = 654,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_SVc = 655,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_Vc = 656,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_SVc = 657,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_Vc = 658,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_Vc_S = 659,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_AtVc = 660,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_SAtVc = 661,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_AtVc = 662,
    BSShaderManager__eBSSMPassEnum_BSSM_3XWATER_DEPTH_SAtVc = 663,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_AtVc = 664,
    BSShaderManager__eBSSMPassEnum_BSSM_NLWATER_DEPTH_AtVc_S = 665,
    BSShaderManager__eBSSMPassEnum_BSSM_WATER_DEPTH_LAST = 665,
    BSShaderManager__eBSSMPassEnum_BSSM_BLOOD_SPLATTER_FLARE = 666,
    BSShaderManager__eBSSMPassEnum_BSSM_BLOOD_SPLATTER = 667,
    BSShaderManager__eBSSMPassEnum_BSSM_RENDERPASSES_LAST = 667,
    BSShaderManager__eBSSMPassEnum_BSSM_SHADOWVOLUME_BACK = 668,
    BSShaderManager__eBSSMPassEnum_BSSM_SHADOWVOLUME_FRONT = 669,
    BSShaderManager__eBSSMPassEnum_BSSM_SHADOWVOLUME_WIRE = 670,
    BSShaderManager__eBSSMPassEnum_BSSM_TILE = 671,
    BSShaderManager__eBSSMPassEnum_BSSM_IMAGESPACE = 672,
    BSShaderManager__eBSSMPassEnum_BSSM_UNUSEDPASSES_FIRST = 673,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT = 673,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_G = 674,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_At = 675,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_GAt = 676,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_S = 677,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_SG = 678,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_SAt = 679,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_SGAt = 680,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBIENT_Sb = 681,
    BSShaderManager__eBSSMPassEnum_BSSM_ENVMAP = 682,
    BSShaderManager__eBSSMPassEnum_BSSM_ENVMAP_Vc = 683,
    BSShaderManager__eBSSMPassEnum_BSSM_ENVMAP_S = 684,
    BSShaderManager__eBSSMPassEnum_BSSM_ENVMAP_SVc = 685,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEDIR = 686,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT = 687,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEDIR_S = 688,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT_S = 689,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEDIR_Sb = 690,
    BSShaderManager__eBSSMPassEnum_BSSM_DIFFUSEPT_Sb = 691,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARDIR_Sb = 692,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARPT_Sb = 693,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARDIR = 694,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARPT = 695,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARDIR_S = 696,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARPT_S = 697,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARDIR_Mb = 698,
    BSShaderManager__eBSSMPassEnum_BSSM_SPECULARDIR_Md = 699,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX = 700,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_Vc = 701,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_F = 702,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FVc = 703,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_G = 704,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_GVc = 705,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FG = 706,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FGVc = 707,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_Fg = 708,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_A = 709,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_AVc = 710,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FA = 711,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FAVc = 712,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_GA = 713,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_GAVc = 714,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FgA = 715,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FFg = 716,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FGA = 717,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FGAVc = 718,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_GFgA = 719,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_FGFgA = 720,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_S = 721,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SVc = 722,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SF = 723,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFVc = 724,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SG = 725,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SGVc = 726,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFG = 727,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFGVc = 728,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFg = 729,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFFg = 730,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFA = 731,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFAVc = 732,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SGA = 733,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SGAVc = 734,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFgA = 735,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFGA = 736,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFGAVc = 737,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SGFgA = 738,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SFGFgA = 739,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_Sb = 740,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SbF = 741,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFDIRANDPT = 742,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFDIRANDPT_S = 743,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFDIRANDPT_Sb = 744,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXEFFECT = 745,
    BSShaderManager__eBSSMPassEnum_BSSM_TEXEFFECT_S = 746,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDDIFF = 747,
    BSShaderManager__eBSSMPassEnum_BSSM_LANDDIFF_A = 748,
    BSShaderManager__eBSSMPassEnum_BSSM_SELFILLUMALPHA = 749,
    BSShaderManager__eBSSMPassEnum_BSSM_SELFILLUMALPHA_S = 750,
    BSShaderManager__eBSSMPassEnum_BSSM_SELFILLUM_SKY = 751,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SA = 752,
    BSShaderManager__eBSSMPassEnum_BSSM_AMBDIFFTEX_SAVc = 753,
    BSShaderManager__eBSSMPassEnum_BSSM_SELFILLUMALPHABLOCK = 754,
    BSShaderManager__eBSSMPassEnum_BSSM_SELFILLUMALPHABLOCK_S = 755,
    BSShaderManager__eBSSMPassEnum_BSSM_UNUSEDPASSES_LAST = 755,
    BSShaderManager__eBSSMPassEnum_BSSM_COUNT = 756
};
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
    virtual void vfn_08();
    virtual void vfn_0c();
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
    ~BSShader();
    static void GetShaderPath(const char*, char*);
    NiD3DVertexShader* CompileVertexShader(const char*, const _D3DXMACRO*, const char*, const char*);
    NiD3DPixelShader* CompilePixelShader(const char*, const _D3DXMACRO*, const char*, const char*);
    // base NiD3DDefaultShader at +0x0, size 92
    NiPointer<NiD3DPass> spRenderPass;       // +0x5C, 4 bytes
    BSShaderManager__eBSSMPassEnum m_ePass;  // +0x60, 4 bytes
    bool m_bIsBest;                          // +0x64, 1 bytes
    unsigned char layoutPadding65[3];
    int m_iPassId;  // +0x68, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShader) == 108);
FNV_STATIC_ASSERT(offsetof(BSShader, spRenderPass) == 92);
FNV_STATIC_ASSERT(offsetof(BSShader, m_ePass) == 96);
FNV_STATIC_ASSERT(offsetof(BSShader, m_bIsBest) == 100);
FNV_STATIC_ASSERT(offsetof(BSShader, m_iPassId) == 104);
#pragma pack(push, 4)
class RgbaColor
{
  public:
    RgbaColor(float R, float G, float B, float A) : r(R), g(G), b(B), a(A)
    {}
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
    // void __cdecl RgbaColor::*(float, float, float, float)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // bool __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor __cdecl RgbaColor::*(const RgbaColor&)
    // operator-
    // operator*
    // operator/
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // RgbaColor& __cdecl RgbaColor::*(const RgbaColor&)
    // operator*=
    // operator/=
    // void __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl RgbaColor::*(const char*)
    // float __cdecl RgbaColor::*()
    // void __cdecl RgbaColor::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, g) == 4);
FNV_STATIC_ASSERT(offsetof(RgbaColor, b) == 8);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);
#pragma pack(push, 4)
class BSShaderNoLighting : public BSShader
{
  public:
    NiPointer<NiD3DPass> spRenderPass[30];                             // +0x6C, 120 bytes
    NiPointer<NiD3DVertexShader> m_spTreeVertexShader[28];             // +0xE4, 112 bytes
    NiPointer<NiD3DPixelShader> m_spPixelShaderVariants[7];            // +0x154, 28 bytes
    NiShaderConstantMapEntry* m_pFirstShaderConstantMapEntry;          // +0x170, 4 bytes
    NiShaderConstantMapEntry* m_pSecondShaderConstantMapEntry;         // +0x174, 4 bytes
    NiShaderConstantMapEntry* m_pShaderConstantMapEntry3;              // +0x178, 4 bytes
    NiShaderConstantMapEntry* m_pShaderConstantMapEntry4;              // +0x17C, 4 bytes
    NiShaderConstantMapEntry* m_pShaderConstantMapEntry5;              // +0x180, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant1;   // +0x184, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_spVertexDeclaration;           // +0x188, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant3;   // +0x18C, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant4;   // +0x190, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant5;   // +0x194, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant6;   // +0x198, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant7;   // +0x19C, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant8;   // +0x1A0, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant9;   // +0x1A4, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant10;  // +0x1A8, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant11;  // +0x1AC, 4 bytes
    NiPointer<NiD3DVertexDeclaration> m_pkVertexDeclarationVariant12;  // +0x1B0, 4 bytes
    BSShaderNoLighting(NiD3DVertexDeclaration* d0, NiD3DVertexDeclaration* d1, NiD3DVertexDeclaration* d2,
                       NiD3DVertexDeclaration* d3, NiD3DVertexDeclaration* d4, NiD3DVertexDeclaration* d5,
                       NiD3DVertexDeclaration* d6, NiD3DVertexDeclaration* d7, NiD3DVertexDeclaration* d8,
                       NiD3DVertexDeclaration* d9, NiD3DVertexDeclaration* d10, NiD3DVertexDeclaration* d11);
    ~BSShaderNoLighting();
    static BSShader* CreateShader();
    void FUN_00bc77e0();
    void PrepareShaderPass(const NiPropertyState*);
    void CopyEntriesToGlobalBuffer(NiGeometry*, const NiTransform&);
    void UpdateGlobalMatrix(const NiPropertyState*);
    void FUN_00bc7100();
    void UpdateMaterialColor(BSShaderNoLightingProperty*, NiMaterialProperty*);
    void InitializeShaderData();
    NiD3DShaderDeclaration* SelectVertexDeclaration(NiGeometry* pkGeometry, BSShaderProperty* pkShaderProperty);
    // const NiRTTI* __cdecl BSShaderNoLighting::*()
    // BSShaderNoLighting
    // void __cdecl BSShaderNoLighting::*()
    // unsigned int __cdecl BSShaderNoLighting::*(NiGeometry*, const NiSkinInstance*, const NiSkinPartition::Partition*, NiGeometryData::RendererData*, const NiPropertyState*, const NiDynamicEffectState*, const NiTransform&, const NiBound&)
    // void __cdecl BSShaderNoLighting::*(unsigned int)
    // void __cdecl BSShaderNoLighting::*(unsigned int)
    // void __cdecl BSShaderNoLighting::*(unsigned int)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*()
    // void __cdecl BSShaderNoLighting::*(BSShaderNoLightingProperty*, NiMaterialProperty*)
    // void __cdecl BSShaderNoLighting::*(const NiPropertyState*)
    // void __cdecl BSShaderNoLighting::*(NiGeometry*, const NiTransform&)
    // void __cdecl BSShaderNoLighting::*()
    // bool __cdecl BSShaderNoLighting::*()
    // NiD3DShaderDeclaration* __cdecl BSShaderNoLighting::*(NiGeometry*, BSShaderProperty*)
    // void __cdecl BSShaderNoLighting::*()
    // void __cdecl BSShaderNoLighting::*()
    // void __cdecl BSShaderNoLighting::*()
    // bool __cdecl BSShaderNoLighting::*()
    // BSShaderNoLighting& __cdecl BSShaderNoLighting::*(const BSShaderNoLighting&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderNoLighting) == 436);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, spRenderPass) == 108);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_spTreeVertexShader) == 228);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_spPixelShaderVariants) == 340);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pFirstShaderConstantMapEntry) == 368);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pSecondShaderConstantMapEntry) == 372);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pShaderConstantMapEntry3) == 376);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pShaderConstantMapEntry4) == 380);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pShaderConstantMapEntry5) == 384);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant1) == 388);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_spVertexDeclaration) == 392);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant3) == 396);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant4) == 400);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant5) == 404);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant6) == 408);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant7) == 412);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant8) == 416);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant9) == 420);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant10) == 424);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant11) == 428);
FNV_STATIC_ASSERT(offsetof(BSShaderNoLighting, m_pkVertexDeclarationVariant12) == 432);
#endif

#endif

inline NiPointer<NiD3DVertexDeclaration>::operator NiD3DShaderDeclaration*() const
{
    return m_pObject;
}
extern RgbaColor DAT_011a9be0;
extern RgbaColor DAT_01202010;

#include "NiPoint3.h"
class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};
class NiTransform
{
  public:
    float m_kOrientation[9];
    NiPoint3 m_kTranslation;
    float m_fScale;
    void ResetToIdentity();
};
class NiSkinInstance;
class NiGeometryBufferData;
class NiD3DShaderProgram;
class NiGeometryData
{
  public:
    unsigned char pad00[0x34];
    NiGeometryBufferData* m_pTextureRendererData;
};
class NiGeometry
{
  public:
    const NiTransform& GetWorldTransform() const
    {
        return m_kWorldSpaceTransform;
    }
    unsigned char pad00[0x20];
    NiBound* m_kWorldBound;
    unsigned char pad24[0x44];
    NiTransform m_kWorldSpaceTransform;
    unsigned char pad9c[0x1c];
    NiGeometryData* m_spGeometryData;
    NiSkinInstance* m_spSkinningInstance;
};
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_kWorldSpaceTransform) == 0x68);
FNV_STATIC_ASSERT(offsetof(NiGeometry, m_spGeometryData) == 0xb8);
class NiPropertyState
{
  public:
    NiProperty* m_spProperties[7];
};
class NiAlphaProperty : public NiProperty
{
  public:
    unsigned short m_uiObjectFlags;
};
class NiWireframeProperty : public NiProperty
{
  public:
    unsigned short m_uiObjectFlags;
};
class BSShaderNoLightingProperty : public BSShaderProperty
{
  public:
    unsigned char pad68[8];
    RgbaColor kFalloff;
};
class NiD3DPass
{
  public:
    unsigned char pad00[0x44];
    NiD3DShaderProgram* m_spPixelShaderObject;
    unsigned char pad48[0x14];
    NiD3DShaderProgram* m_spVertexShaderObject;
};
class GraphicsRenderer
{
  public:
    void ApplyObjectTransform(const NiTransform&, bool);
};
class ShaderPassRenderer
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void SetWireframeProperty(NiWireframeProperty*);
};
class NiD3DShaderConstantMap : public NiRefObject
{
  public:
    virtual void vfn_08();
    virtual void vfn_0c();
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
    virtual unsigned int ConfigureShaderConstantMap(NiD3DShaderProgram*, NiGeometry*, const NiSkinInstance*,
                                                    const void*, NiGeometryBufferData*, const NiPropertyState*,
                                                    const void*, const NiTransform&, const NiBound&, unsigned int,
                                                    bool);
};
extern NiGeometry** DAT_011f91e0;
extern unsigned int DAT_011f91e4;
extern NiBound DAT_011f4288;
extern NiPoint3 DAT_011f474c;
extern int DAT_0126f74c;
extern RgbaColor DAT_01202020;
extern RgbaColor DAT_01202030;
void __cdecl FUN_00b97e30(unsigned int, unsigned int);
void __cdecl FUN_00b97de0(unsigned int, unsigned int);
