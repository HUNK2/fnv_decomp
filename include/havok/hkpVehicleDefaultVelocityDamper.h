// include/havok/hkpVehicleDefaultVelocityDamper.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTVELOCITYDAMPER_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTVELOCITYDAMPER_H

#include "hkBase.h"
#include "hkpVehicleVelocityDamper.h"
#pragma pack(push, 1)
class hkpVehicleDefaultVelocityDamper : public hkpVehicleVelocityDamper
{
  public:
    hkReal m_fSpinDamping;           // +0x8
    hkReal m_fCollisionSpinDamping;  // +0xC
    hkReal m_fCollisionThreshold;    // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultVelocityDamper[(sizeof(hkpVehicleDefaultVelocityDamper) == 0x14) ? 1 : -1];
#endif
