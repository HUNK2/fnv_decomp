// include/havok/hkpReorientAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPREORIENTACTION_H
#define FNV_HAVOK_HKPREORIENTACTION_H

#include "hkBase.h"
#include "hkpUnaryAction.h"
#pragma pack(push, 1)
class hkpReorientAction : public hkpUnaryAction
{
  public:
    char pad1C[0x4];
    hkVector4 m_vRotationAxis;  // +0x20
    hkVector4 m_vUpAxis;        // +0x30
    hkReal m_fSpringStrength;   // +0x40
    hkReal m_fMotorDamping;     // +0x44
    char pad48[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpReorientAction[(sizeof(hkpReorientAction) == 0x50) ? 1 : -1];
#endif
