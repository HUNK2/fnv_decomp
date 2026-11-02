// include/havok/hkpDashpotAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPDASHPOTACTION_H
#define FNV_HAVOK_HKPDASHPOTACTION_H

#include "hkBase.h"
#include "hkpBinaryAction.h"
#pragma pack(push, 1)
class hkpDashpotAction : public hkpBinaryAction
{
  public:
    hkVector4 m_kPoint[2];     // +0x20
    hkReal m_fSpringStrength;  // +0x40
    hkReal m_fMotorDamping;    // +0x44
    char pad48[0x8];
    hkVector4 m_fContactImpulse;  // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpDashpotAction[(sizeof(hkpDashpotAction) == 0x60) ? 1 : -1];
#endif
