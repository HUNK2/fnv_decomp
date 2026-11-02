// include/havok/hkpVehicleDefaultBrakeWheelBrakingProperties.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTBRAKEWHEELBRAKINGPROPERTIES_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTBRAKEWHEELBRAKINGPROPERTIES_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpVehicleDefaultBrakeWheelBrakingProperties
{
  public:
    hkReal m_fMaxBrakingTorque;      // +0x0
    hkReal m_fMinPedalInputToBlock;  // +0x4
    hkBool m_bConnectedToHandbrake;  // +0x8
    char pad9[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultBrakeWheelBrakingProperties
    [(sizeof(hkpVehicleDefaultBrakeWheelBrakingProperties) == 0xC) ? 1 : -1];
#endif
