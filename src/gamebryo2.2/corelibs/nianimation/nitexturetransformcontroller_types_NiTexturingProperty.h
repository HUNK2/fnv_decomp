// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITEXTURINGPROPERTY_H
#define FNV_NITEXTURINGPROPERTY_H

#include "layout_support.h"
#include "NiProperty.h"
#include "layout_support.h"
class NiTPrimitiveArray_NiTexturingProperty__Map___;
class NiTPrimitiveArray_NiTexturingProperty__ShaderMap___;
class NiTexturingProperty;
class NiTexturingProperty__Map;
class NiTexturingProperty__ShaderMap;
#pragma pack(push, 4)
class NiTPrimitiveArray_NiTexturingProperty__Map___
    : public NiTArray<NiTexturingProperty__Map*, NiTMallocInterface<NiTexturingProperty__Map*> >
{
  public:
    // base NiTArray<NiTexturingProperty::Map *,NiTMallocInterface<NiTexturingProperty::Map *> > at +0x0, size 16
    // NiTPrimitiveArray<NiTexturingProperty::Map *>
    // void __cdecl NiTPrimitiveArray<NiTexturingProperty::Map *>::*()
    // NiTPrimitiveArray<NiTexturingProperty::Map *>& __cdecl NiTPrimitiveArray<NiTexturingProperty::Map *>::*(const NiTPrimitiveArray<NiTexturingProperty::Map *>&)
    // void __cdecl NiTPrimitiveArray<NiTexturingProperty::Map *>::*()
    // void __cdecl NiTPrimitiveArray<NiTexturingProperty::Map *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_NiTexturingProperty__Map___) == 16);
class NiTPrimitiveArray_NiTexturingProperty__ShaderMap___
    : public NiTArray<NiTexturingProperty__ShaderMap*, NiTMallocInterface<NiTexturingProperty__ShaderMap*> >
{
};
typedef NiTPrimitiveArray_NiTexturingProperty__ShaderMap___ NiTexturingProperty__ShaderMapArray;
#pragma pack(push, 4)
class NiTexturingProperty : public NiProperty
{
  public:
    // base NiProperty at +0x0, size 24
    unsigned short m_uiObjectFlags;  // +0x18, 2 bytes
    unsigned char layoutPadding1A[2];
    NiTPrimitiveArray_NiTexturingProperty__Map___ m_kStringArray;        // +0x1C, 16 bytes
    NiTPrimitiveArray_NiTexturingProperty__ShaderMap___* m_pShaderMaps;  // +0x2C, 4 bytes
    unsigned int FUN_00a46410();
    // const NiRTTI* __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(NiStream&)
    // void __cdecl NiTexturingProperty::*(NiStream&)
    // bool __cdecl NiTexturingProperty::*(NiStream&)
    // void __cdecl NiTexturingProperty::*(NiStream&)
    // bool __cdecl NiTexturingProperty::*(NiObject*)
    // NiObject* __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiTexturingProperty::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiTexturingProperty::*(unsigned short, unsigned short)
    // void __cdecl NiTexturingProperty::*(bool, unsigned short)
    // bool __cdecl NiTexturingProperty::*(unsigned short)
    // NiTexturingProperty
    // void __cdecl NiTexturingProperty::*()
    // GetBaseMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // GetDarkMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // GetDetailMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // GetGlossMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // GetGlowMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // GetBumpMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::BumpMap*)
    // GetNormalMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // GetParallaxMap
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::ParallaxMap*)
    // GetDecalMap
    // void __cdecl NiTexturingProperty::*(unsigned int, NiTexturingProperty::Map*)
    // unsigned int __cdecl NiTexturingProperty::*()
    // unsigned int __cdecl NiTexturingProperty::*()
    // GetShaderMap
    // void __cdecl NiTexturingProperty::*(unsigned int, NiTexturingProperty::ShaderMap*)
    // unsigned int __cdecl NiTexturingProperty::*()
    // unsigned int __cdecl NiTexturingProperty::*()
    // NiTexturingProperty::ApplyMode __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::ApplyMode)
    // bool __cdecl NiTexturingProperty::*(const NiTexturingProperty&)
    // int __cdecl NiTexturingProperty::*()
    // int __cdecl NiTexturingProperty::*()
    // NiTexturingProperty* __cdecl NiTexturingProperty::*()
    // bool __cdecl NiTexturingProperty::*()
    // NiTexture* __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(NiTexture*)
    // NiTexturingProperty::ClampMode __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::ClampMode)
    // NiTexturingProperty::FilterMode __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::FilterMode)
    // unsigned int __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(unsigned int)
    // const NiTPrimitiveArray<NiTexturingProperty::Map *>& __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*(unsigned int, NiTexturingProperty::Map*)
    // void __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*()
    // const NiFixedString& __cdecl NiTexturingProperty::*(unsigned int)
    // bool __cdecl NiTexturingProperty::*(const NiFixedString&, unsigned int&)
    // bool __cdecl NiTexturingProperty::*(NiTexturingProperty::MapEnum, unsigned int)
    // void __cdecl NiTexturingProperty::*(NiTexturingProperty::Map*)
    // void __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*()
    // void __cdecl NiTexturingProperty::*()
    // NiTexturingProperty& __cdecl NiTexturingProperty::*(const NiTexturingProperty&)
    // void __cdecl NiTexturingProperty::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTexturingProperty) == 48);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty, m_uiObjectFlags) == 24);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty, m_kStringArray) == 28);
FNV_STATIC_ASSERT(offsetof(NiTexturingProperty, m_pShaderMaps) == 44);
#endif
