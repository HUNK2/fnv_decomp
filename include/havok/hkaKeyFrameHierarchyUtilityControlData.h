// include/havok/hkaKeyFrameHierarchyUtilityControlData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKAKEYFRAMEHIERARCHYUTILITYCONTROLDATA_H
#define FNV_HAVOK_HKAKEYFRAMEHIERARCHYUTILITYCONTROLDATA_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaKeyFrameHierarchyUtilityControlData
{
  public:
    hkReal m_fHierarchyGain;               // +0x0
    hkReal m_fVelocityDamping;             // +0x4
    hkReal m_fAccelerationGain;            // +0x8
    hkReal m_fVelocityGain;                // +0xC
    hkReal m_positionGain;                 // +0x10
    hkReal m_fPositionMaxLinearVelocity;   // +0x14
    hkReal m_fPositionMaxAngularVelocity;  // +0x18
    hkReal m_snapGain;                     // +0x1C
    hkReal m_fSnapMaxLinearVelocity;       // +0x20
    hkReal m_fSnapMaxAngularVelocity;      // +0x24
    hkReal m_fSnapMaxLinearDistance;       // +0x28
    hkReal m_fSnapMaxAngularDistance;      // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaKeyFrameHierarchyUtilityControlData[(sizeof(hkaKeyFrameHierarchyUtilityControlData) == 0x30)
                                                                    ? 1
                                                                    : -1];
#endif
