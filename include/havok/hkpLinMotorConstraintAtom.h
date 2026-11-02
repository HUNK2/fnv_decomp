// include/havok/hkpLinMotorConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPLINMOTORCONSTRAINTATOM_H
#define FNV_HAVOK_HKPLINMOTORCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpConstraintMotor;
#pragma pack(push, 1)
class hkpLinMotorConstraintAtom : public hkpConstraintAtom
{
  public:
    hkBool m_bLimitEnabled;                   // +0x2
    hkUint8 m_ucMotorAxis;                    // +0x3
    hkInt16 m_iInitializedOffset;             // +0x4
    hkInt16 m_sPreviousTargetPositionOffset;  // +0x6
    hkReal m_vVector;                         // +0x8
    hkpConstraintMotor* m_pMotor;             // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpLinMotorConstraintAtom[(sizeof(hkpLinMotorConstraintAtom) == 0x10) ? 1 : -1];
#endif
