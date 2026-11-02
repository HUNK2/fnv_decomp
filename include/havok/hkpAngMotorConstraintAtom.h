// include/havok/hkpAngMotorConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPANGMOTORCONSTRAINTATOM_H
#define FNV_HAVOK_HKPANGMOTORCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpConstraintMotor;
#pragma pack(push, 1)
class hkpAngMotorConstraintAtom : public hkpConstraintAtom
{
  public:
    hkBool m_bLimitEnabled;                              // +0x2
    hkUint8 m_ucMotorAxis;                               // +0x3
    hkInt16 m_iInitializedOffset;                        // +0x4
    hkInt16 m_iPreviousTargetAngleOffset;                // +0x6
    hkInt16 m_iCorrespondingAngLimitSolverResultOffset;  // +0x8
    char padA[0x2];
    hkReal m_fTargetAngle;         // +0xC
    hkpConstraintMotor* m_pMotor;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAngMotorConstraintAtom[(sizeof(hkpAngMotorConstraintAtom) == 0x14) ? 1 : -1];
#endif
