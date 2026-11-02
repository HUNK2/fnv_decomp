// include/havok/hkpSpringAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPSPRINGACTION_H
#define FNV_HAVOK_HKPSPRINGACTION_H

#include "hkBase.h"
#include "hkpBinaryAction.h"
#pragma pack(push, 1)
class hkpSpringAction : public hkpBinaryAction
{
  public:
    hkVector4 m_kLastForce;    // +0x20
    hkVector4 m_kPositionA;    // +0x30
    hkVector4 m_kPositionB;    // +0x40
    hkReal m_fRestLength;      // +0x50
    hkReal m_fSpringStrength;  // +0x54
    hkReal m_fMotorDamping;    // +0x58
    hkBool m_bSpringEnabled;   // +0x5C
    hkBool m_bElastic;         // +0x5D
    char pad5E[0x2];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSpringAction[(sizeof(hkpSpringAction) == 0x60) ? 1 : -1];
#endif
