// include/havok/hkpRagdollMotorConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPRAGDOLLMOTORCONSTRAINTATOM_H
#define FNV_HAVOK_HKPRAGDOLLMOTORCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpConstraintMotor;
#pragma pack(push, 1)
class hkpRagdollMotorConstraintAtom : public hkpConstraintAtom
{
  public:
    hkBool m_bLimitEnabled;  // +0x2
    char pad3[0x1];
    hkInt16 m_iInitializedOffset;           // +0x4
    hkInt16 m_iPreviousTargetAnglesOffset;  // +0x6
    char pad8[0x8];
    hkMatrix3 m_kMotorAxes;             // +0x10
    hkpConstraintMotor* m_ppMotors[3];  // +0x40
    char pad4C[0x4];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRagdollMotorConstraintAtom[(sizeof(hkpRagdollMotorConstraintAtom) == 0x50) ? 1 : -1];
#endif
