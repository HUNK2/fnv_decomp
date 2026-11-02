// include/havok/hkpPositionConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x24.
#ifndef FNV_HAVOK_HKPPOSITIONCONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPPOSITIONCONSTRAINTMOTOR_H

#include "hkBase.h"
#include "hkpLimitedForceConstraintMotor.h"
#pragma pack(push, 1)
class hkpPositionConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkReal m_fTau;                           // +0x14
    hkReal m_fMotorDamping;                  // +0x18
    hkReal m_fProportionalRecoveryVelocity;  // +0x1C
    hkReal m_fConstantRecoveryVelocity;      // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPositionConstraintMotor[(sizeof(hkpPositionConstraintMotor) == 0x24) ? 1 : -1];
#endif
