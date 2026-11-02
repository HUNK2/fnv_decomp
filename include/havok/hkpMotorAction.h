// include/havok/hkpMotorAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPMOTORACTION_H
#define FNV_HAVOK_HKPMOTORACTION_H

#include "hkBase.h"
#include "hkpUnaryAction.h"
#pragma pack(push, 1)
class hkpMotorAction : public hkpUnaryAction
{
  public:
    char pad1C[0x4];
    hkVector4 m_kAxisEndPoints;  // +0x20
    hkReal m_fSpinRate;          // +0x30
    hkReal m_fGain;              // +0x34
    hkBool m_bSlotEnabled;       // +0x38
    char pad39[0x7];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMotorAction[(sizeof(hkpMotorAction) == 0x40) ? 1 : -1];
#endif
