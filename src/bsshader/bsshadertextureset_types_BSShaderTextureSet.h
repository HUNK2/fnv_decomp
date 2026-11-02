// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSSHADERTEXTURESET_H
#define FNV_BSSHADERTEXTURESET_H

#include "layout_support.h"
#include "NiObject.h"
#include "layout_support.h"
class BSShaderTextureSet;
class BSTextureSet;
#pragma pack(push, 4)
class BSTextureSet : public NiObject
{
  public:
    virtual void vfn_03() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_05() = 0;
    virtual void vfn_06() = 0;
    virtual void vfn_07() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_09() = 0;
    virtual void vfn_0a() = 0;
    virtual void vfn_0b() = 0;
    virtual void vfn_0c() = 0;
    virtual void vfn_0d() = 0;
    virtual void vfn_0e() = 0;
    virtual void vfn_0f() = 0;
    virtual void vfn_10() = 0;
    virtual void vfn_11() = 0;
    virtual void vfn_12() = 0;
    virtual void LoadBinary(NiStream& stream) = 0;
    virtual void vfn_14() = 0;
    virtual void vfn_15() = 0;
    virtual void SaveBinary(NiStream& stream) = 0;
    virtual void vfn_17() = 0;
    virtual void vfn_18() = 0;
    virtual void vfn_19() = 0;
    virtual void vfn_1a() = 0;
    virtual void vfn_1b() = 0;
    virtual void vfn_1c() = 0;
    virtual void vfn_1d() = 0;
    virtual void vfn_1e() = 0;
    virtual void vfn_1f() = 0;
    virtual void vfn_20() = 0;
    virtual void vfn_21() = 0;
    virtual void vfn_22() = 0;
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);
    // base NiObject at +0x0, size 8
    // void __cdecl BSTextureSet::*(NiStream&)
    // void __cdecl BSTextureSet::*(NiStream&)
    // bool __cdecl BSTextureSet::*(NiStream&)
    // void __cdecl BSTextureSet::*(NiStream&)
    // bool __cdecl BSTextureSet::*(NiObject*)
    // const NiRTTI* __cdecl BSTextureSet::*()
    // BSTextureSet
    // void __cdecl BSTextureSet::*()
    // BSTextureSet& __cdecl BSTextureSet::*(const BSTextureSet&)
    // void __cdecl BSTextureSet::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTextureSet) == 8);
#pragma pack(push, 4)
class BSShaderTextureSet : public BSTextureSet
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);
    // base BSTextureSet at +0x0, size 8
    BSStringT<char> m_kTextureNames[7];  // +0x8, 56 bytes
    // void __cdecl BSShaderTextureSet::*(NiStream&)
    // void __cdecl BSShaderTextureSet::*(NiStream&)
    // bool __cdecl BSShaderTextureSet::*(NiStream&)
    // void __cdecl BSShaderTextureSet::*(NiStream&)
    // bool __cdecl BSShaderTextureSet::*(NiObject*)
    // NiObject* __cdecl BSShaderTextureSet::*()
    // const NiRTTI* __cdecl BSShaderTextureSet::*()
    // const char* __cdecl BSShaderTextureSet::*(BSShaderProperty::TextureTypeEnum)
    // void __cdecl BSShaderTextureSet::*(BSShaderProperty::TextureTypeEnum, NiPointer<NiTexture>&)
    // void __cdecl BSShaderTextureSet::*(BSShaderProperty::TextureTypeEnum, const char*)
    // BSShaderTextureSet
    // void __cdecl BSShaderTextureSet::*()
    // BSShaderTextureSet& __cdecl BSShaderTextureSet::*(const BSShaderTextureSet&)
    // void __cdecl BSShaderTextureSet::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSShaderTextureSet) == 64);
FNV_STATIC_ASSERT(offsetof(BSShaderTextureSet, m_kTextureNames) == 8);
#endif
