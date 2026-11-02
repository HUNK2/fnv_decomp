// include/havok/hkpVehicleSuspension.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPVEHICLESUSPENSION_H
#define FNV_HAVOK_HKPVEHICLESUSPENSION_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpVehicleSuspensionSuspensionWheelParameters;
#pragma pack(push, 1)
class hkpVehicleSuspension : public hkReferencedObject
{
  public:
    hkArray<hkpVehicleSuspensionSuspensionWheelParameters> m_kWheelParams;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleSuspension[(sizeof(hkpVehicleSuspension) == 0x14) ? 1 : -1];
#endif
