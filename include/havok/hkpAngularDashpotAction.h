// include/havok/hkpAngularDashpotAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPANGULARDASHPOTACTION_H
#define FNV_HAVOK_HKPANGULARDASHPOTACTION_H
#include "hkBase.h"
#include "hkpBinaryAction.h"
#pragma pack(push, 1)
class hkpAngularDashpotAction : public hkpBinaryAction
{
  public:
    hkQuaternion m_rotation;   // +0x20
    hkReal m_fSpringStrength;  // +0x30
    hkReal m_fMotorDamping;    // +0x34
    char pad38[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAngularDashpotAction[(sizeof(hkpAngularDashpotAction) == 0x40) ? 1 : -1];
#endif
