// include/havok/hkpVehicleDefaultBrake.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTBRAKE_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTBRAKE_H

#include "hkBase.h"
#include "hkpVehicleBrake.h"
class hkpVehicleDefaultBrakeWheelBrakingProperties;
#pragma pack(push, 1)
class hkpVehicleDefaultBrake : public hkpVehicleBrake
{
  public:
    hkArray<hkpVehicleDefaultBrakeWheelBrakingProperties> m_kWheelBrakingProperties;  // +0x8
    hkReal m_fWheelBlockTime;                                                         // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultBrake[(sizeof(hkpVehicleDefaultBrake) == 0x18) ? 1 : -1];
#endif
