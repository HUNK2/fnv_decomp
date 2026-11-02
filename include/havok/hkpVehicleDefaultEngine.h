// include/havok/hkpVehicleDefaultEngine.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTENGINE_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTENGINE_H

#include "hkBase.h"
#include "hkpVehicleEngine.h"
#pragma pack(push, 1)
class hkpVehicleDefaultEngine : public hkpVehicleEngine
{
  public:
    hkReal m_fMinRPM;                    // +0x8
    hkReal m_fOptRPM;                    // +0xC
    hkReal m_fMaxRPM;                    // +0x10
    hkReal m_fMaxTorque;                 // +0x14
    hkReal m_fTorqueFactorAtMinRPM;      // +0x18
    hkReal m_fTorqueFactorAtMaxRPM;      // +0x1C
    hkReal m_fResistanceFactorAtMinRPM;  // +0x20
    hkReal m_fResistanceFactorAtOptRPM;  // +0x24
    hkReal m_fResistanceFactorAtMaxRPM;  // +0x28
    hkReal m_fClutchSlipRPM;             // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultEngine[(sizeof(hkpVehicleDefaultEngine) == 0x30) ? 1 : -1];
#endif
