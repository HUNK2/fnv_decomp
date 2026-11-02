// include/havok/hkxLight.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKXLIGHT_H
#define FNV_HAVOK_HKXLIGHT_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxLight : public hkReferencedObject
{
  public:
    enum LightType
    {
        POINT_LIGHT = 0,
        DIRECTIONAL_LIGHT = 1,
        SPOT_LIGHT = 2
    };
    hkInt8 m_type;  // +0x8 (LightType)
    char pad9[0x7];
    hkVector4 m_vContactPosition;      // +0x10
    hkVector4 m_direction;     // +0x20
    hkUint32 m_kDiffuseColor;  // +0x30
    hkReal m_fConeAngle;       // +0x34
    char pad38[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxLight[(sizeof(hkxLight) == 0x40) ? 1 : -1];
#endif
