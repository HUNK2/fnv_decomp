// include/havok/hkpVelocityConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPVELOCITYCONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPVELOCITYCONSTRAINTMOTOR_H

#include "hkBase.h"
#include "hkpLimitedForceConstraintMotor.h"
#pragma pack(push, 1)
class hkpVelocityConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkReal m_fTau;                // +0x14
    hkReal m_fVelocityTarget;     // +0x18
    hkBool m_bUseVelocityTarget;  // +0x1C
    char pad1D[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVelocityConstraintMotor[(sizeof(hkpVelocityConstraintMotor) == 0x20) ? 1 : -1];
#endif
