// include/havok/hkpVehicleDefaultSuspension.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTSUSPENSION_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTSUSPENSION_H

#include "hkBase.h"
#include "hkpVehicleSuspension.h"
class hkpVehicleDefaultSuspensionWheelSpringSuspensionParameters;
#pragma pack(push, 1)
class hkpVehicleDefaultSuspension : public hkpVehicleSuspension
{
  public:
    hkArray<hkpVehicleDefaultSuspensionWheelSpringSuspensionParameters> m_kWheelSpringSuspensionParameters;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultSuspension[(sizeof(hkpVehicleDefaultSuspension) == 0x20) ? 1 : -1];
#endif
