// include/havok/hkpVehicleDataWheelComponentParams.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKPVEHICLEDATAWHEELCOMPONENTPARAMS_H
#define FNV_HAVOK_HKPVEHICLEDATAWHEELCOMPONENTPARAMS_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpVehicleDataWheelComponentParams
{
  public:
    hkReal m_fSphereRadius;                // +0x0
    hkReal m_fViscosityFriction;           // +0x4
    hkReal m_fMaxFriction;                 // +0x8
    hkReal m_fSlipAngle;                   // +0xC
    hkReal m_fSlipVelocity;                // +0x10
    hkReal m_fMaxContactBodyAcceleration;  // +0x14
    hkReal m_fForceFeedbackMultiplier;     // +0x18
    hkReal m_fMaxFrictionForce;            // +0x1C
    hkReal m_fFrictionEqualizer;           // +0x20
    hkInt8 m_iAxle;                        // +0x24
    char pad25[0x3];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpVehicleDataWheelComponentParams[(sizeof(hkpVehicleDataWheelComponentParams) == 0x28) ? 1 : -1];
#endif
