// include/havok/hkpRagdollLimitsDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xB0.
#ifndef FNV_HAVOK_HKPRAGDOLLLIMITSDATAATOMS_H
#define FNV_HAVOK_HKPRAGDOLLLIMITSDATAATOMS_H

#include "hkBase.h"
#include "hkpConeLimitConstraintAtom.h"
#include "hkpSetLocalRotationsConstraintAtom.h"
#include "hkpTwistLimitConstraintAtom.h"
#pragma pack(push, 1)
class hkpRagdollLimitsDataAtoms
{
  public:
    enum Axis
    {
        AXIS_TWIST = 0,
        AXIS_PLANES = 1,
        AXIS_CROSS_PRODUCT = 2
    };
    hkpSetLocalRotationsConstraintAtom m_kLocalRotations;  // +0x0
    hkpTwistLimitConstraintAtom m_kTwistLimit;             // +0x70
    hkpConeLimitConstraintAtom m_kConeLimit;               // +0x84
    hkpConeLimitConstraintAtom m_kPlaneLimit;              // +0x98
    char padAC[0x4];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRagdollLimitsDataAtoms[(sizeof(hkpRagdollLimitsDataAtoms) == 0xB0) ? 1 : -1];
#endif
