// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_IMAGESPACESHADERPARAM_H
#define FNV_IMAGESPACESHADERPARAM_H

#include "layout_support.h"
#include "layout_support.h"
class DFALL_NiTMapItem_unsigned_int_unsigned_int___;
class ImageSpaceEffectParam;
class ImageSpaceShaderParam;
class RgbaColor;
class NiD3DShaderConstantMap;
class NiTMap_unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_;
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator;
class NiTPrimitiveArray_enum_BSTextureManager__eTextureType_;
class NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_;
class NiTexture;
enum BSTextureManager__eTextureType
{
    BSTextureManager__eTextureType_TEX_UNKNOWN = -1,
    BSTextureManager__eTextureType_TEX_HDR_FIRST = 0,
    BSTextureManager__eTextureType_TEX_HDR_DOWNSAMPLE = 0,
    BSTextureManager__eTextureType_TEX_HDR_DOWNSAMPLE_ANISOINTERMEDIATE = 1,
    BSTextureManager__eTextureType_TEX_HDR_BLURSWAP = 2,
    BSTextureManager__eTextureType_TEX_HDR_LAST = 2,
    BSTextureManager__eTextureType_TEX_IMAGESPACE_FIRST = 3,
    BSTextureManager__eTextureType_TEX_IMAGESPACE_SWAP = 3,
    BSTextureManager__eTextureType_TEX_IMAGESPACE_LAST = 3,
    BSTextureManager__eTextureType_TEX_MAIN_FIRST = 4,
    BSTextureManager__eTextureType_TEX_MAIN_IMAGESPACE = 4,
    BSTextureManager__eTextureType_TEX_MAIN_FIRSTPERSON = 5,
    BSTextureManager__eTextureType_TEX_MAIN_MENUBG = 6,
    BSTextureManager__eTextureType_TEX_MAIN_LAST = 6,
    BSTextureManager__eTextureType_TEX_TESWATER_FIRST = 7,
    BSTextureManager__eTextureType_TEX_TESWATER_FFT = 7,
    BSTextureManager__eTextureType_TEX_TESWATER_GREY = 8,
    BSTextureManager__eTextureType_TEX_TESWATER_REFLECTION = 9,
    BSTextureManager__eTextureType_TEX_TESWATER_LOD_REFLECTION = 10,
    BSTextureManager__eTextureType_TEX_TESWATER_REFRACTION = 11,
    BSTextureManager__eTextureType_TEX_TESWATER_RAIN = 12,
    BSTextureManager__eTextureType_TEX_TESWATER_SCRAMBLEMAP = 13,
    BSTextureManager__eTextureType_TEX_TESWATER_IFFT_BUTTERFLYMAP = 14,
    BSTextureManager__eTextureType_TEX_TESWATER_HIGH_W = 15,
    BSTextureManager__eTextureType_TEX_TESWATER_HIGH_AMPLITUDE = 16,
    BSTextureManager__eTextureType_TEX_TESWATER_DEPTH = 17,
    BSTextureManager__eTextureType_TEX_TESWATER_NOISE_HEIGHTMAP = 18,
    BSTextureManager__eTextureType_TEX_TESWATER_NOISE_NORMALMAP = 19,
    BSTextureManager__eTextureType_TEX_TESWATER_DISPLACEMENT = 20,
    BSTextureManager__eTextureType_TEX_TESWATER_DEBUG_DISPLAY = 21,
    BSTextureManager__eTextureType_TEX_TESWATER_LAST = 21,
    BSTextureManager__eTextureType_TEX_TREES_FIRST = 22,
    BSTextureManager__eTextureType_TEX_TREES_CANOPYSHADOWMASK = 22,
    BSTextureManager__eTextureType_TEX_TREES_LAST = 22,
    BSTextureManager__eTextureType_TEX_BLUR_FIRST = 23,
    BSTextureManager__eTextureType_TEX_BLURFULL_BUFFER = 23,
    BSTextureManager__eTextureType_TEX_BLURFULL_SWAP = 24,
    BSTextureManager__eTextureType_TEX_BLUR_LAST = 24,
    BSTextureManager__eTextureType_TEX_BLUR20_FIRST = 25,
    BSTextureManager__eTextureType_TEX_BLUR20_BUFFER = 25,
    BSTextureManager__eTextureType_TEX_BLUR20_LAST = 25,
    BSTextureManager__eTextureType_TEX_GETHIT_FIRST = 26,
    BSTextureManager__eTextureType_TEX_GETHIT_BUFFER = 26,
    BSTextureManager__eTextureType_TEX_GETHIT_LAST = 26,
    BSTextureManager__eTextureType_TEX_LOCALMAP_FIRST = 27,
    BSTextureManager__eTextureType_TEX_LOCALMAP_FINAL = 27,
    BSTextureManager__eTextureType_TEX_LOCALMAP_COLOR = 28,
    BSTextureManager__eTextureType_TEX_LOCALMAP_NORMALS = 29,
    BSTextureManager__eTextureType_TEX_LOCALMAP_LAST = 29,
    BSTextureManager__eTextureType_TEX_REFRACTION_FIRST = 30,
    BSTextureManager__eTextureType_TEX_REFRACTION_NORMALS = 30,
    BSTextureManager__eTextureType_TEX_REFRACTION_LAST = 30,
    BSTextureManager__eTextureType_TEX_VFOG_FIRST = 31,
    BSTextureManager__eTextureType_TEX_VFOG = 31,
    BSTextureManager__eTextureType_TEX_SCENE_DEPTH_BUFFER = 32,
    BSTextureManager__eTextureType_TEX_VFOG_SWAP = 33,
    BSTextureManager__eTextureType_TEX_VFOG_LAST = 33,
    BSTextureManager__eTextureType_TEX_VELOCITY_FIRST = 34,
    BSTextureManager__eTextureType_TEX_VELOCITY = 34,
    BSTextureManager__eTextureType_TEX_VELOCITY_SWAP = 35,
    BSTextureManager__eTextureType_TEX_VELOCITY_LAST = 35,
    BSTextureManager__eTextureType_TEX_DOF_FIRST = 36,
    BSTextureManager__eTextureType_TEX_DOF_BLUR = 36,
    BSTextureManager__eTextureType_TEX_DOF_BLUR_SWAP = 37,
    BSTextureManager__eTextureType_TEX_DOF_MASK = 38,
    BSTextureManager__eTextureType_TEX_DOF_LAST = 38,
    BSTextureManager__eTextureType_TEX_DEPTH_RADIALBLUR_FIRST = 39,
    BSTextureManager__eTextureType_TEX_DEPTH_RADIALBLUR_BLUR = 39,
    BSTextureManager__eTextureType_TEX_DEPTH_RADIALBLUR_LAST = 39,
    BSTextureManager__eTextureType_TEX_CUBEMAP_FIRST = 40,
    BSTextureManager__eTextureType_TEX_CUBEMAP_CAMERA = 40,
    BSTextureManager__eTextureType_TEX_CUBEMAP_LAST = 40,
    BSTextureManager__eTextureType_TEX_SHADOWS_FIRST = 41,
    BSTextureManager__eTextureType_TEX_SHADOWS_SHADOWMAP = 41,
    BSTextureManager__eTextureType_TEX_SHADOWS_SHADOWMAPFRUSTUM = 42,
    BSTextureManager__eTextureType_TEX_SHADOWS_LAST = 42,
    BSTextureManager__eTextureType_TEX_ENVMAP_FIRST = 43,
    BSTextureManager__eTextureType_TEX_ENVMAP_WINDOWS = 43,
    BSTextureManager__eTextureType_TEX_ENVMAP_LAST = 43,
    BSTextureManager__eTextureType_TEX_INTERFACE_FIRST = 44,
    BSTextureManager__eTextureType_TEX_INTERFACE_RENDEREDMENU = 44,
    BSTextureManager__eTextureType_TEX_INTERFACE_RENDEREDMENU_SWAP = 45,
    BSTextureManager__eTextureType_TEX_INTERFACE_VATS = 46,
    BSTextureManager__eTextureType_TEX_INTERFACE_RACESEXMENU = 47,
    BSTextureManager__eTextureType_TEX_INTERFACE_TEMP = 48,
    BSTextureManager__eTextureType_TEX_INTERFACE_LAST = 48,
    BSTextureManager__eTextureType_TEX_NOISE_FIRST = 49,
    BSTextureManager__eTextureType_TEX_NOISE_BUFFER = 49,
    BSTextureManager__eTextureType_TEX_NOISE_LAST = 49,
    BSTextureManager__eTextureType_TEX_DECAL_FIRST = 50,
    BSTextureManager__eTextureType_TEX_DECAL_OCCLUSION = 50,
    BSTextureManager__eTextureType_TEX_DECAL_LAST = 50,
    BSTextureManager__eTextureType_TEX_COUNT = 51
};
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
enum NiRenderer__ClearFlags
{
    NiRenderer__ClearFlags_CLEAR_BACKBUFFER = 1,
    NiRenderer__ClearFlags_CLEAR_STENCIL = 2,
    NiRenderer__ClearFlags_CLEAR_ZBUFFER = 4,
    NiRenderer__ClearFlags_CLEAR_NONE = 0,
    NiRenderer__ClearFlags_CLEAR_ALL = 7
};
#pragma pack(push, 4)
class NiTPrimitiveArray_enum_BSTextureManager__eTextureType_
    : public NiTArray<BSTextureManager__eTextureType, NiTMallocInterface<BSTextureManager__eTextureType> >
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_enum_BSTextureManager__eTextureType_) == 16);
#pragma pack(push, 4)
class NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_
    : public NiTArray<NiTexturingProperty__FilterMode, NiTMallocInterface<NiTexturingProperty__FilterMode> >
{
  public:
    // base NiTArray<enum NiTexturingProperty::FilterMode,NiTMallocInterface<enum NiTexturingProperty::FilterMode> > at +0x0, size 16
    // NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>
    // void __cdecl NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>::*()
    // NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>& __cdecl NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>::*(const NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>&)
    // void __cdecl NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>::*()
    // void __cdecl NiTPrimitiveArray<enum NiTexturingProperty::FilterMode>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_) == 16);
#pragma pack(push, 4)
class ImageSpaceEffectParam
{
  public:
    void** m_ppVirtualMethodTable;                                                         // +0x0, 4 bytes
    NiTPrimitiveArray_enum_BSTextureManager__eTextureType_ m_kTextureTypes;  // +0x4, 16 bytes
    NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_ m_kFilterModes;  // +0x14, 16 bytes
    // ImageSpaceEffectParam
    // ImageSpaceEffectParam& __cdecl ImageSpaceEffectParam::*(const ImageSpaceEffectParam&)
    // void __cdecl ImageSpaceEffectParam::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceEffectParam) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffectParam, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffectParam, m_kTextureTypes) == 4);
FNV_STATIC_ASSERT(offsetof(ImageSpaceEffectParam, m_kFilterModes) == 20);
#pragma pack(push, 4)
class RgbaColor
{
  public:
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
class DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*()
    // void __cdecl DFALL<NiTMapItem<unsigned int,unsigned int> >::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_unsigned_int_unsigned_int___) == 1);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
    : public DFALL_NiTMapItem_unsigned_int_unsigned_int___
{
  public:
    // base DFALL<NiTMapItem<unsigned int,unsigned int> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                // +0x4, 4 bytes
    NiTMapItem<unsigned int, unsigned int>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int, unsigned int&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(void*&, unsigned int&, unsigned int&)
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(unsigned int)
    // NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>& __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*(const NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_) == 16);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_,
                           m_kItemCount) == 12);
#pragma pack(push, 4)
class NiTMap_unsigned_int_unsigned_int_
    : public NiTMapBase_DFALL_NiTMapItem_unsigned_int_unsigned_int____unsigned_int_unsigned_int_
{
  public:
    // base NiTMapBase<DFALL<NiTMapItem<unsigned int,unsigned int> >,unsigned int,unsigned int> at +0x0, size 16
    // NiTMap<unsigned int,unsigned int>
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
    // NiTMapItem<unsigned int,unsigned int>* __cdecl NiTMap<unsigned int,unsigned int>::*()
    // void __cdecl NiTMap<unsigned int,unsigned int>::*(NiTMapItem<unsigned int,unsigned int>*)
    // NiTMap<unsigned int,unsigned int>& __cdecl NiTMap<unsigned int,unsigned int>::*(const NiTMap<unsigned int,unsigned int>&)
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
    // void __cdecl NiTMap<unsigned int,unsigned int>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMap_unsigned_int_unsigned_int_) == 16);
#pragma pack(push, 4)
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    // base ImageSpaceEffectParam at +0x0, size 36
    NiTexturingProperty__FilterMode m_eShaderFilterMode;           // +0x24, 4 bytes
    NiRenderer__ClearFlags m_eClearFlags;                          // +0x28, 4 bytes
    RgbaColor m_eTextureClampMode;                                 // +0x2C, 16 bytes
    float* m_pfVertexShaderConstants;                              // +0x3C, 4 bytes
    int m_iVertexShaderConstantCount;                              // +0x40, 4 bytes
    float* m_pfPixelShaderConstants;                               // +0x44, 4 bytes
    int m_iPixelShaderConstantCount;                               // +0x48, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_pVertexShaderConstantMap;  // +0x4C, 4 bytes
    NiPointer<NiD3DShaderConstantMap> m_pPixelShaderConstantMap;   // +0x50, 4 bytes
    bool m_bTextureFlags[3];                                       // +0x54, 3 bytes
    unsigned char layoutPadding57[1];
    NiTObjectArray<NiPointer<NiTexture> > m_kShaderTextures;                        // +0x58, 16 bytes
    NiTPrimitiveArray_enum_NiTexturingProperty__FilterMode_ m_kTextureFilterModes;  // +0x68, 16 bytes
    NiTMap_unsigned_int_unsigned_int_ m_kRenderStateMap;                            // +0x78, 16 bytes
    ImageSpaceShaderParam();
    void AllocateShaderConstants(int, int);
    // ImageSpaceShaderParam
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(int, int)
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(int, unsigned int, unsigned int)
    // void __cdecl ImageSpaceShaderParam::*()
    // void __cdecl ImageSpaceShaderParam::*(unsigned int, unsigned int)
    // void __cdecl ImageSpaceShaderParam::*(NiD3DPass*)
    // ImageSpaceShaderParam& __cdecl ImageSpaceShaderParam::*(const ImageSpaceShaderParam&)
    // void __cdecl ImageSpaceShaderParam::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceShaderParam) == 136);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eShaderFilterMode) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eClearFlags) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_eTextureClampMode) == 44);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pfVertexShaderConstants) == 60);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_iVertexShaderConstantCount) == 64);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pfPixelShaderConstants) == 68);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_iPixelShaderConstantCount) == 72);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pVertexShaderConstantMap) == 76);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_pPixelShaderConstantMap) == 80);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_bTextureFlags) == 84);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kShaderTextures) == 88);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kTextureFilterModes) == 104);
FNV_STATIC_ASSERT(offsetof(ImageSpaceShaderParam, m_kRenderStateMap) == 120);
#endif
