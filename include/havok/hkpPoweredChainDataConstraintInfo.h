// include/havok/hkpPoweredChainDataConstraintInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPPOWEREDCHAINDATACONSTRAINTINFO_H
#define FNV_HAVOK_HKPPOWEREDCHAINDATACONSTRAINTINFO_H

#include "hkBase.h"
class hkpConstraintMotor;
#pragma pack(push, 1)
class hkpPoweredChainDataConstraintInfo
{
  public:
    hkVector4 m_kPivotInA;              // +0x0
    hkVector4 m_kPivotInB;              // +0x10
    hkQuaternion m_kRotationInA;        // +0x20
    hkQuaternion m_kRotationInB;        // +0x30
    hkpConstraintMotor* m_ppMotors[3];  // +0x40
    hkBool m_bUseMotors;                // +0x4C
    char pad4D[0x3];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpPoweredChainDataConstraintInfo[(sizeof(hkpPoweredChainDataConstraintInfo) == 0x50) ? 1 : -1];
#endif
