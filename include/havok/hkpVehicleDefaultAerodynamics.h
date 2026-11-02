// include/havok/hkpVehicleDefaultAerodynamics.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTAERODYNAMICS_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTAERODYNAMICS_H

#include "hkBase.h"
#include "hkpVehicleAerodynamics.h"
#pragma pack(push, 1)
class hkpVehicleDefaultAerodynamics : public hkpVehicleAerodynamics
{
  public:
    hkReal m_fAirDensity;       // +0x8
    hkReal m_fFrontalArea;      // +0xC
    hkReal m_fDragCoefficient;  // +0x10
    hkReal m_fLiftCoefficient;  // +0x14
    char pad18[0x8];
    hkVector4 m_vExtraGravityWorldSpace;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultAerodynamics[(sizeof(hkpVehicleDefaultAerodynamics) == 0x30) ? 1 : -1];
#endif
