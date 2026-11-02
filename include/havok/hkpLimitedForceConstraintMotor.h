// include/havok/hkpLimitedForceConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPLIMITEDFORCECONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPLIMITEDFORCECONSTRAINTMOTOR_H

#include "hkBase.h"
#include "hkpConstraintMotor.h"
#pragma pack(push, 1)
class hkpLimitedForceConstraintMotor : public hkpConstraintMotor
{
  public:
    hkReal m_fMinForce;  // +0xC
    hkReal m_fMaxForce;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpLimitedForceConstraintMotor[(sizeof(hkpLimitedForceConstraintMotor) == 0x14) ? 1 : -1];
#endif
