// include/havok/hkpVehicleData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1A0.
#ifndef FNV_HAVOK_HKPVEHICLEDATA_H
#define FNV_HAVOK_HKPVEHICLEDATA_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#include "hkpVehicleFrictionDescription.h"
class hkpVehicleDataWheelComponentParams;
#pragma pack(push, 1)
class hkpVehicleData : public hkReferencedObject
{
  public:
    char pad8[0x8];
    hkVector4 m_kGravity;  // +0x10
    hkInt8 m_iWheelCount;  // +0x20
    char pad21[0xF];
    hkRotation m_kChassisOrientation;                            // +0x30
    hkReal m_fChassisMass;                                       // +0x60
    hkReal m_fTorqueMax;                                         // +0x64
    hkReal m_fTorqueMin;                                         // +0x68
    hkReal m_fTorqueFactor;                                      // +0x6C
    hkReal m_fTorquePitchFactor;                                 // +0x70
    hkReal m_fTorqueRollFactor;                                  // +0x74
    hkReal m_fTorqueYawFactor;                                   // +0x78
    hkReal m_fExtraTorqueFactor;                                 // +0x7C
    hkReal m_fChassisUnitInertiaRoll;                            // +0x80
    hkReal m_fChassisUnitInertiaPitch;                           // +0x84
    hkReal m_fChassisUnitInertiaYaw;                             // +0x88
    hkArray<hkpVehicleDataWheelComponentParams> m_kWheelParams;  // +0x8C
    hkArray<hkInt8> m_kNumWheelsPerAxle;                         // +0x98
    hkpVehicleFrictionDescription m_kFrictionDescription;        // +0xA4
    char pad174[0xC];
    hkVector4 m_vChassisUnitInertiaAndMassInv;  // +0x180
    hkBool m_bWheelsUseChassisForGround;        // +0x190
    char pad191[0xF];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleData[(sizeof(hkpVehicleData) == 0x1A0) ? 1 : -1];
#endif
