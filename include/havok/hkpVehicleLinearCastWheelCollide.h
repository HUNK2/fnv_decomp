// include/havok/hkpVehicleLinearCastWheelCollide.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x34.
#ifndef FNV_HAVOK_HKPVEHICLELINEARCASTWHEELCOLLIDE_H
#define FNV_HAVOK_HKPVEHICLELINEARCASTWHEELCOLLIDE_H

#include "hkBase.h"
#include "hkpRejectChassisListener.h"
#include "hkpVehicleWheelCollide.h"
class hkpVehicleLinearCastWheelCollideWheelState;
#pragma pack(push, 1)
class hkpVehicleLinearCastWheelCollide : public hkpVehicleWheelCollide
{
  public:
    hkUint32 m_uiWheelCount;                                             // +0xC
    hkArray<hkpVehicleLinearCastWheelCollideWheelState> m_kWheelStates;  // +0x10
    hkpRejectChassisListener m_kRejectChassisListener;                   // +0x1C
    hkReal m_fMaxExtraPenetration;                                       // +0x2C
    hkReal m_fMaxExtraPenetrationAgainstFixed;                           // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleLinearCastWheelCollide[(sizeof(hkpVehicleLinearCastWheelCollide) == 0x34) ? 1 : -1];
#endif
