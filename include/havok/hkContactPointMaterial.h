// include/havok/hkContactPointMaterial.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKCONTACTPOINTMATERIAL_H
#define FNV_HAVOK_HKCONTACTPOINTMATERIAL_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkContactPointMaterial
{
  public:
    enum FlagEnum
    {
        CONTACT_IS_NEW = 1,
        CONTACT_USES_SOLVER_PATH2 = 2,
        CONTACT_BREAKOFF_OBJECT_ID = 4,
        CONTACT_IS_DISABLED = 8
    };
    hkUlong m_ulUserData;   // +0x0
    hkUint8 m_fSlipAngle;   // +0x4
    hkUint8 m_fElasticity;  // +0x5
    hkUint8 m_usFlags;      // +0x6
    hkUint8 m_flags;        // +0x7
};
#pragma pack(pop)
typedef char fnv_hk_size_hkContactPointMaterial[(sizeof(hkContactPointMaterial) == 0x8) ? 1 : -1];
#endif
