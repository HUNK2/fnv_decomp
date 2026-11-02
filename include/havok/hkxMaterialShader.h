// include/havok/hkxMaterialShader.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKXMATERIALSHADER_H
#define FNV_HAVOK_HKXMATERIALSHADER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxMaterialShader : public hkReferencedObject
{
  public:
    enum ShaderType
    {
        EFFECT_TYPE_INVALID = 0,
        EFFECT_TYPE_UNKNOWN = 1,
        EFFECT_TYPE_HLSL_INLINE = 2,
        EFFECT_TYPE_CG_INLINE = 3,
        EFFECT_TYPE_HLSL_FILENAME = 4,
        EFFECT_TYPE_CG_FILENAME = 5,
        EFFECT_TYPE_MAX_ID = 6
    };
    hkStringPtr m_name;  // +0x8
    hkUint8 m_type;      // +0xC (ShaderType)
    char padD[0x3];
    hkStringPtr m_kVertexShader;    // +0x10
    hkStringPtr m_kFragmentShader;  // +0x14
    hkStringPtr m_kGeometryShader;  // +0x18
    hkArray<hkUint8> m_data;        // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMaterialShader[(sizeof(hkxMaterialShader) == 0x28) ? 1 : -1];
#endif
