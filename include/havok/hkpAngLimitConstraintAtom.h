// include/havok/hkpAngLimitConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPANGLIMITCONSTRAINTATOM_H
#define FNV_HAVOK_HKPANGLIMITCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpAngLimitConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_bLimitEnabled;           // +0x2
    hkUint8 m_ucLimitAxis;             // +0x3
    hkReal m_fMinAngle;                // +0x4
    hkReal m_fMaxAngle;                // +0x8
    hkReal m_fAngularLimitsTauFactor;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAngLimitConstraintAtom[(sizeof(hkpAngLimitConstraintAtom) == 0x10) ? 1 : -1];
#endif
