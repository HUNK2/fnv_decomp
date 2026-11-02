// include/havok/hkpAngFrictionConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPANGFRICTIONCONSTRAINTATOM_H
#define FNV_HAVOK_HKPANGFRICTIONCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpAngFrictionConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_bLimitEnabled;        // +0x2
    hkUint8 m_ucFirstFrictionAxis;  // +0x3
    hkUint8 m_ucNumFrictionAxes;    // +0x4
    char pad5[0x3];
    hkReal m_fMaxFrictionTorque;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAngFrictionConstraintAtom[(sizeof(hkpAngFrictionConstraintAtom) == 0xC) ? 1 : -1];
#endif
