// include/havok/hkpCharacterProxyCinfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x80.
#ifndef FNV_HAVOK_HKPCHARACTERPROXYCINFO_H
#define FNV_HAVOK_HKPCHARACTERPROXYCINFO_H

#include "hkBase.h"
class hkpShapePhantom;
#pragma pack(push, 1)
class hkpCharacterProxyCinfo
{
  public:
    hkVector4 m_vContactPosition;            // +0x0
    hkVector4 m_fVelocity;           // +0x10
    hkReal m_fDynamicFriction;       // +0x20
    hkReal m_fStaticFriction;        // +0x24
    hkReal m_fKeepContactTolerance;  // +0x28
    char pad2C[0x4];
    hkVector4 m_vStart;                       // +0x30
    hkReal m_fExtraUpStaticFriction;          // +0x40
    hkReal m_fExtraDownStaticFriction;        // +0x44
    hkpShapePhantom* m_pCharacterPhantom;     // +0x48
    hkReal m_fKeepDistance;                   // +0x4C
    hkReal m_fContactAngleSensitivity;        // +0x50
    hkUint32 m_uiUserPlanes;                  // +0x54
    hkReal m_fMaxCharacterSpeedForSolver;     // +0x58
    hkReal m_fCharacterStrength;              // +0x5C
    hkReal m_fCharacterMass;                  // +0x60
    hkReal m_fMaximumSlope;                        // +0x64
    hkReal m_fPenetrationRecoverySpeed;       // +0x68
    hkInt32 m_iMaxCastIterations;             // +0x6C
    hkBool m_bRefreshManifoldInCheckSupport;  // +0x70
    char pad71[0xF];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCharacterProxyCinfo[(sizeof(hkpCharacterProxyCinfo) == 0x80) ? 1 : -1];
#endif
