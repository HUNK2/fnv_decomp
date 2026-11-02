// include/havok/hkpTwistLimitConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPTWISTLIMITCONSTRAINTATOM_H
#define FNV_HAVOK_HKPTWISTLIMITCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpTwistLimitConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_bLimitEnabled;    // +0x2
    hkUint8 m_ucTwistAxis;      // +0x3
    hkUint8 m_ucReferenceAxis;  // +0x4
    char pad5[0x3];
    hkReal m_fMinAngle;                // +0x8
    hkReal m_fMaxAngle;                // +0xC
    hkReal m_fAngularLimitsTauFactor;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpTwistLimitConstraintAtom[(sizeof(hkpTwistLimitConstraintAtom) == 0x14) ? 1 : -1];
#endif
