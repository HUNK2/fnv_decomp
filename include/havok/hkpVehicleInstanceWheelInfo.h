// include/havok/hkpVehicleInstanceWheelInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xE0.
#ifndef FNV_HAVOK_HKPVEHICLEINSTANCEWHEELINFO_H
#define FNV_HAVOK_HKPVEHICLEINSTANCEWHEELINFO_H

#include "hkBase.h"
#include "hkContactPoint.h"
#pragma pack(push, 1)
class hkpVehicleInstanceWheelInfo
{
  public:
    hkContactPoint m_vContactPoint;    // +0x0
    hkReal m_fSuspensionLength;        // +0x20
    void* m_pUserData;                 // +0x24
    hkUint32 m_uiContactShapeKeys[8];  // +0x28
    char pad48[0x8];
    hkVector4 m_vContactPointVelocity;  // +0x50
    hkVector4 m_vContactNormal;         // +0x60
    hkReal m_fContactFriction;          // +0x70
    char pad74[0xC];
    hkVector4 m_vHardPointWs;             // +0x80
    hkVector4 m_vRayEndPointWs;           // +0x90
    hkVector4 m_vSuspensionDirectionWs;   // +0xA0
    hkQuaternion m_qSteeringOrientation;  // +0xB0
    hkReal m_fValueAtOffsetC0;            // +0xC0
    hkReal m_fSpinAngle;                  // +0xC4
    hkReal m_fSkidEnergyDensity;          // +0xC8
    hkReal m_fSideForce;                  // +0xCC
    hkReal m_fSuspensionForce;            // +0xD0
    hkReal m_fForwardForce;               // +0xD4
    char padD8[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleInstanceWheelInfo[(sizeof(hkpVehicleInstanceWheelInfo) == 0xE0) ? 1 : -1];
#endif
