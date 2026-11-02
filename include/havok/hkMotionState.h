// include/havok/hkMotionState.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xB0.
#ifndef FNV_HAVOK_HKMOTIONSTATE_H
#define FNV_HAVOK_HKMOTIONSTATE_H

#include "hkBase.h"
#include "hkSweptTransform.h"
#pragma pack(push, 1)
class hkMotionState
{
  public:
    hkTransform m_kMotionTransform;      // +0x0
    hkSweptTransform m_kSweptTransform;  // +0x40
    hkVector4 m_kDeltaAngle;             // +0x90
    hkReal m_fObjectRadius;              // +0xA0
    hkReal m_fLinearDamping;             // +0xA4
    hkReal m_fAngularDamping;            // +0xA8
    hkUint8 m_fSurfaceFriction;          // +0xAC
    hkUint8 m_fRestitution;              // +0xAD
    hkUint8 m_uiDeactivationClass;       // +0xAE
    char padAF[0x1];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMotionState[(sizeof(hkMotionState) == 0xB0) ? 1 : -1];
#endif
