// include/havok/hkxMaterial.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x80.
#ifndef FNV_HAVOK_HKXMATERIAL_H
#define FNV_HAVOK_HKXMATERIAL_H

#include "hkBase.h"
class hkReferencedObject;
class hkxMaterialTextureStage;
#pragma pack(push, 1)
class hkxMaterial
{
  public:
    enum TextureType
    {
        TEX_UNKNOWN = 0,
        TEX_DIFFUSE = 1,
        TEX_REFLECTION = 2,
        TEX_BUMP = 3,
        TEX_NORMAL = 4,
        TEX_DISPLACEMENT = 5,
        TEX_SPECULAR = 6,
        TEX_SPECULARANDGLOSS = 7,
        TEX_OPACITY = 8,
        TEX_EMISSIVE = 9,
        TEX_REFRACTION = 10,
        TEX_GLOSS = 11,
        TEX_NOTEXPORTED = 12
    };
    char pad0[0x14];
    hkStringPtr m_name;                                 // +0x14
    hkArray<hkxMaterialTextureStage> m_kTextureStages;  // +0x18
    char pad24[0xC];
    hkVector4 m_afDiffuseColor;               // +0x30
    hkVector4 m_afAmbientColor;               // +0x40
    hkVector4 m_afSpecularColor;              // +0x50
    hkVector4 m_afEmissiveColor;              // +0x60
    hkArray<hkxMaterial*> m_kSubMaterials;    // +0x70
    hkReferencedObject* m_pMaterialUserData;  // +0x7C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMaterial[(sizeof(hkxMaterial) == 0x80) ? 1 : -1];
#endif
