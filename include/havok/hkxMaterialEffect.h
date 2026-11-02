// include/havok/hkxMaterialEffect.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKXMATERIALEFFECT_H
#define FNV_HAVOK_HKXMATERIALEFFECT_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxMaterialEffect : public hkReferencedObject
{
  public:
    enum EffectType
    {
        EFFECT_TYPE_INVALID = 0,
        EFFECT_TYPE_UNKNOWN = 1,
        EFFECT_TYPE_HLSL_FX_INLINE = 2,
        EFFECT_TYPE_CG_FX_INLINE = 3,
        EFFECT_TYPE_HLSL_FX_FILENAME = 4,
        EFFECT_TYPE_CG_FX_FILENAME = 5,
        EFFECT_TYPE_MAX_ID = 6
    };
    hkStringPtr m_name;  // +0x8
    hkUint8 m_type;      // +0xC (EffectType)
    char padD[0x3];
    hkArray<hkUint8> m_data;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMaterialEffect[(sizeof(hkxMaterialEffect) == 0x1C) ? 1 : -1];
#endif
