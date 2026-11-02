// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACETEXTURE_H
#define FNV_IMAGESPACETEXTURE_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class NiTexture;
class ImageSpaceTexture;
#ifndef FNV_NITEXTURINGPROPERTY_FILTERMODE_DEFINED
#define FNV_NITEXTURINGPROPERTY_FILTERMODE_DEFINED
enum NiTexturingProperty__FilterMode
{
    NiTexturingProperty__FilterMode_FILTER_NEAREST = 0,
    NiTexturingProperty__FilterMode_FILTER_BILERP = 1,
    NiTexturingProperty__FilterMode_FILTER_TRILERP = 2,
    NiTexturingProperty__FilterMode_FILTER_NEAREST_MIPNEAREST = 3,
    NiTexturingProperty__FilterMode_FILTER_NEAREST_MIPLERP = 4,
    NiTexturingProperty__FilterMode_FILTER_BILERP_MIPNEAREST = 5,
    NiTexturingProperty__FilterMode_FILTER_ANISO = 6,
    NiTexturingProperty__FilterMode_FILTER_MAGLERP_MINANISO = 7,
    NiTexturingProperty__FilterMode_FILTER_MAX_MODES = 8
};
#endif
enum NiTexturingProperty__ClampMode
{
    NiTexturingProperty__ClampMode_CLAMP_S_CLAMP_T = 0,
    NiTexturingProperty__ClampMode_CLAMP_S_WRAP_T = 1,
    NiTexturingProperty__ClampMode_WRAP_S_CLAMP_T = 2,
    NiTexturingProperty__ClampMode_WRAP_S_WRAP_T = 3,
    NiTexturingProperty__ClampMode_CLAMP_MAX_MODES = 4
};
#pragma pack(push, 4)
class ImageSpaceTexture
{
  public:
    bool m_bTextureFlag1;  // +0x0, 1 bytes
    bool m_bTextureFlag2;  // +0x1, 1 bytes
    bool m_bTextureFlag3;  // +0x2, 1 bytes
    unsigned char layoutPadding3[1];
    NiPointer<NiObject> pTexture;                          // +0x4, 4 bytes
    NiTexturingProperty__FilterMode m_eTextureFilterMode;  // +0x8, 4 bytes
    NiTexturingProperty__ClampMode m_eClampMode;           // +0xC, 4 bytes
    static void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    ImageSpaceTexture()
    {
        m_bTextureFlag1 = false;
        m_bTextureFlag2 = false;
        m_bTextureFlag3 = false;
        pTexture.m_pObject = 0;
        m_eTextureFilterMode = (NiTexturingProperty__FilterMode)0;
        m_eClampMode = (NiTexturingProperty__ClampMode)0;
    }
    void SetTexture(NiTexture* texture);
    // ImageSpaceTexture
    // void __cdecl ImageSpaceTexture::*()
    // BSRenderedTexture* __cdecl ImageSpaceTexture::*()
    // NiTexture* __cdecl ImageSpaceTexture::*()
    // SetTexture
    // void __cdecl ImageSpaceTexture::*(bool)
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*()
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::FilterMode)
    // void __cdecl ImageSpaceTexture::*(NiTexturingProperty::ClampMode)
    // ImageSpaceTexture& __cdecl ImageSpaceTexture::*(ImageSpaceTexture&)
    // void* __cdecl ImageSpaceTexture::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceTexture) == 16);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag1) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag2) == 1);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_bTextureFlag3) == 2);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, pTexture) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_eTextureFilterMode) == 8);
FNV_STATIC_ASSERT(offsetof(ImageSpaceTexture, m_eClampMode) == 12);
#endif
