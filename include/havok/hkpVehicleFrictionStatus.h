// include/havok/hkpVehicleFrictionStatus.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x48.
#ifndef FNV_HAVOK_HKPVEHICLEFRICTIONSTATUS_H
#define FNV_HAVOK_HKPVEHICLEFRICTIONSTATUS_H

#include "hkBase.h"
#include "hkpVehicleFrictionStatusAxisStatus.h"
#pragma pack(push, 1)
class hkpVehicleFrictionStatus
{
  public:
    hkpVehicleFrictionStatusAxisStatus m_kAxisEndPoints[2];  // +0x0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleFrictionStatus[(sizeof(hkpVehicleFrictionStatus) == 0x48) ? 1 : -1];
#endif
