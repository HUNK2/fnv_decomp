// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIRENDERTARGETGROUP_H
#define FNV_NIRENDERTARGETGROUP_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class Ni2DBuffer;
class NiDepthStencilBuffer;
class NiRenderTargetGroup;
class NiRenderTargetGroup__RendererData;
#pragma pack(push, 4)
class NiRenderTargetGroup : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    bool m_bNeedsResolve;       // +0x8, 1 bytes
    bool m_bFlagBeforePadding;  // +0x9, 1 bytes
    unsigned char layoutPaddingA[2];
    unsigned int SystemStateFlags;  // +0xC, 4 bytes
    bool m_bFlagBeforeBuffers;      // +0x10, 1 bytes
    unsigned char layoutPadding11[1];
    unsigned short RenderBufferSet;                                      // +0x12, 2 bytes
    NiPointer<Ni2DBuffer> m_aspRenderTargetBuffers[4];                   // +0x14, 16 bytes
    unsigned int RenderTargetBufferInfo;                                 // +0x24, 4 bytes
    NiPointer<NiDepthStencilBuffer> m_spRenderTargetDepthStencilBuffer;  // +0x28, 4 bytes
    NiRenderTargetGroup__RendererData* m_pTextureRendererData;           // +0x2C, 4 bytes
    // const NiRTTI* __cdecl NiRenderTargetGroup::*()
    // void __cdecl NiRenderTargetGroup::*(NiStream&)
    // void __cdecl NiRenderTargetGroup::*(NiStream&)
    // bool __cdecl NiRenderTargetGroup::*(NiStream&)
    // void __cdecl NiRenderTargetGroup::*(NiStream&)
    // bool __cdecl NiRenderTargetGroup::*(NiObject*)
    // NiObject* __cdecl NiRenderTargetGroup::*()
    // void __cdecl NiRenderTargetGroup::*(NiTPrimitiveArray<char *>*)
    // Create
    // void __cdecl NiRenderTargetGroup::*()
    // bool __cdecl NiRenderTargetGroup::*()
    // bool __cdecl NiRenderTargetGroup::*()
    // bool __cdecl NiRenderTargetGroup::*()
    // NiRenderTargetGroup
    // NiRenderTargetGroup& __cdecl NiRenderTargetGroup::*(const NiRenderTargetGroup&)
    // void __cdecl NiRenderTargetGroup::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiRenderTargetGroup) == 48);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, m_bNeedsResolve) == 8);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, m_bFlagBeforePadding) == 9);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, SystemStateFlags) == 12);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, m_bFlagBeforeBuffers) == 16);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, RenderBufferSet) == 18);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, m_aspRenderTargetBuffers) == 20);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, RenderTargetBufferInfo) == 36);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, m_spRenderTargetDepthStencilBuffer) == 40);
FNV_STATIC_ASSERT(offsetof(NiRenderTargetGroup, m_pTextureRendererData) == 44);
#endif
