// include/havok/hkpVehicleRayCastWheelCollide.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x24.
#ifndef FNV_HAVOK_HKPVEHICLERAYCASTWHEELCOLLIDE_H
#define FNV_HAVOK_HKPVEHICLERAYCASTWHEELCOLLIDE_H

#include "hkBase.h"
#include "hkpRejectChassisListener.h"
#include "hkpVehicleWheelCollide.h"
class hkpAabbPhantom;
#pragma pack(push, 1)
class hkpVehicleRayCastWheelCollide : public hkpVehicleWheelCollide
{
  public:
    hkUint32 m_uiWheelCount;                               // +0xC
    hkpAabbPhantom* m_pPhantom;                            // +0x10
    hkpRejectChassisListener m_kChassisRejectionListener;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleRayCastWheelCollide[(sizeof(hkpVehicleRayCastWheelCollide) == 0x24) ? 1 : -1];
#endif
