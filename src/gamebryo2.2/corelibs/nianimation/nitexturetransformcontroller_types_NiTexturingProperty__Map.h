// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITEXTURINGPROPERTY_MAP_H
#define FNV_NITEXTURINGPROPERTY_MAP_H

#include "layout_support.h"
#include "layout_support.h"
class NiTexture;
class TextureMapTransform;
class NiTexturingProperty__Map;
#pragma pack(push, 4)
class NiTexturingProperty__Map
{
  public:
    void** m_ppVirtualMethodTable;          // +0x0, 4 bytes
    unsigned short m_uiObjectFlags;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    NiPointer<NiTexture> m_spTexture;         // +0x8, 4 bytes
    TextureMapTransform* m_pTextureTransform;  // +0xC, 4 bytes
    // void __cdecl NiTexturingProperty::Map::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiTexturingProperty::Map::*(unsigned short, unsigned short)
    // void __cdecl NiTexturingProperty::Map::*(bool, unsigned short)
    // bool __cdecl NiTexturingProperty::Map::*(unsigned short)
    // Map
    // bool __cdecl NiTexturingProperty::Map::*(const NiTexturingProperty::Map&)
    // bool __cdecl NiTexturingProperty::Map::*(const NiTexturingProperty::Map&)
    // NiTexture* __cdecl NiTexturingProperty::Map::*()
    // void __cdecl NiTexturingProperty::Map::*(NiTexture*)
    // NiTexturingProperty::ClampMode __cdecl NiTexturingProperty::Map::*()
    // void __cdecl NiTexturingProperty::Map::*(NiTexturingProperty::ClampMode)
    // NiTexturingProperty::FilterMode __cdecl NiTexturingProperty::Map::*()
    // void __cdecl NiTexturingProperty::Map::*(NiTexturingProperty::FilterMode)
    // unsigned int __cdecl NiTexturingProperty::Map::*()
    // void __cdecl NiTexturingProperty::Map::*(unsigned int)
    // GetTextureTransform
    // bool __cdecl NiTexturingProperty::Map::*(NiTexturingProperty::Map*)
    // NiTexturingProperty::Map& __cdecl NiTexturingProperty::Map::*(const NiTexturingProperty::Map&)
    // void __cdecl NiTexturingProperty::Map::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTexturingProperty__Map) == 16);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty__Map, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty__Map, m_uiObjectFlags) == 4);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty__Map, m_spTexture) == 8);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty__Map, m_pTextureTransform) == 12);
#endif
