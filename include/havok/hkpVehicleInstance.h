// include/havok/hkpVehicleInstance.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xD4.
#ifndef FNV_HAVOK_HKPVEHICLEINSTANCE_H
#define FNV_HAVOK_HKPVEHICLEINSTANCE_H

#include "hkBase.h"
#include "hkpUnaryAction.h"
#include "hkpVehicleFrictionStatus.h"
class hkpTyremarksInfo;
class hkpVehicleAerodynamics;
class hkpVehicleBrake;
class hkpVehicleData;
class hkpVehicleDriverInput;
class hkpVehicleDriverInputStatus;
class hkpVehicleEngine;
class hkpVehicleInstanceWheelInfo;
class hkpVehicleSteering;
class hkpVehicleSuspension;
class hkpVehicleTransmission;
class hkpVehicleVelocityDamper;
class hkpVehicleWheelCollide;
#pragma pack(push, 1)
class hkpVehicleInstance : public hkpUnaryAction
{
  public:
    hkpVehicleData* m_data;                                  // +0x1C
    hkpVehicleDriverInput* m_pDriverInput;                   // +0x20
    hkpVehicleSteering* m_pSteering;                         // +0x24
    hkpVehicleEngine* m_pVehicleEngine;                      // +0x28
    hkpVehicleTransmission* m_pTransmission;                 // +0x2C
    hkpVehicleBrake* m_pBrake;                               // +0x30
    hkpVehicleSuspension* m_pSuspension;                     // +0x34
    hkpVehicleAerodynamics* m_pAerodynamics;                 // +0x38
    hkpVehicleWheelCollide* m_pWheelCollide;                 // +0x3C
    hkpTyremarksInfo* m_pTyremarksInfo;                      // +0x40
    hkpVehicleVelocityDamper* m_pVelocityDamper;             // +0x44
    hkArray<hkpVehicleInstanceWheelInfo> m_kWheelInfoArray;  // +0x48
    hkpVehicleFrictionStatus m_kFrictionStatus;              // +0x54
    hkpVehicleDriverInputStatus* m_pDriverInputStatus;       // +0x9C
    hkArray<hkBool> m_kSecondRealArray;                      // +0xA0
    hkReal m_fBrakeState;                                    // +0xAC
    hkBool m_bIsReversing;                                   // +0xB0
    char padB1[0x3];
    hkReal m_fFirstValueBeforeSteeringAngle;   // +0xB4
    hkReal m_fSecondValueBeforeSteeringAngle;  // +0xB8
    hkReal m_fMainSteeringAngle;               // +0xBC
    hkArray<hkReal> m_kWheelSteeringAngles;    // +0xC0
    hkBool m_iGearCount;                       // +0xCC
    hkInt8 m_iGearCapacity;                    // +0xCD
    hkBool m_bGearShiftActive;                 // +0xCE
    char padCF[0x1];
    hkReal m_fGearShiftTime;  // +0xD0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleInstance[(sizeof(hkpVehicleInstance) == 0xD4) ? 1 : -1];
#endif
