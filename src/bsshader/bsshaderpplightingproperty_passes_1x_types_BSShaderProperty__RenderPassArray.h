// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERPROPERTY_RENDERPASSARRAY_H
#define FNV_BSSHADERPROPERTY_RENDERPASSARRAY_H

#include "layout_support.h"
#include "layout_support.h"
class BSShaderProperty__RenderPass;
class NiGeometry;
class ShadowSceneLight;
class BSShaderProperty__RenderPassArray;
#pragma pack(push, 4)
class BSShaderProperty__RenderPassArray
{
  public:
    NiTObjectArray<BSShaderProperty__RenderPass*> m_kRenderPasses;  // +0x0, 16 bytes
    unsigned int iSize;                                             // +0x10, 4 bytes
    void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*,
             ShadowSceneLight*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderProperty__RenderPassArray) == 20);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPassArray, m_kRenderPasses) == 0);
FNV_STATIC_ASSERT(offsetof(BSShaderProperty__RenderPassArray, iSize) == 16);
#endif
