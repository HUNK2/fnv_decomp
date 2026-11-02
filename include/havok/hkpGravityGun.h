// include/havok/hkpGravityGun.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPGRAVITYGUN_H
#define FNV_HAVOK_HKPGRAVITYGUN_H

#include "hkBase.h"
#include "hkpFirstPersonGun.h"
#pragma pack(push, 1)
class hkpGravityGun : public hkpFirstPersonGun
{
  public:
    hkArray<void*> m_kPickedBodies;  // +0x20
    hkInt32 m_iMaxPickedBodies;      // +0x2C
    hkReal m_fMaxPickMass;           // +0x30
    hkReal m_fMaxPickDistance;       // +0x34
    hkReal m_fPickAngle;             // +0x38
    hkReal m_fHoldDistance;          // +0x3C
    hkVector4 m_kGrabPosition;       // +0x40
    hkVector4 m_kTargetPosition;     // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpGravityGun[(sizeof(hkpGravityGun) == 0x60) ? 1 : -1];
#endif
