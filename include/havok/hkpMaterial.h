// include/havok/hkpMaterial.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPMATERIAL_H
#define FNV_HAVOK_HKPMATERIAL_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpMaterial
{
  public:
    enum ResponseType
    {
        RESPONSE_INVALID = 0,
        RESPONSE_SIMPLE_CONTACT = 1,
        RESPONSE_REPORTING = 2,
        RESPONSE_NONE = 3,
        RESPONSE_MAX_ID = 4
    };
    hkInt8 m_eResponseType;  // +0x0 (ResponseType)
    char pad1[0x3];
    hkReal m_fSlipAngle;   // +0x4
    hkReal m_fElasticity;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMaterial[(sizeof(hkpMaterial) == 0xC) ? 1 : -1];
#endif
