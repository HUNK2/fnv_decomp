// include/havok/hkpAngConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x4.
#ifndef FNV_HAVOK_HKPANGCONSTRAINTATOM_H
#define FNV_HAVOK_HKPANGCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpAngConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_ucFirstConstrainedAxis;  // +0x2
    hkUint8 m_ucNumConstrainedAxes;    // +0x3
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAngConstraintAtom[(sizeof(hkpAngConstraintAtom) == 0x4) ? 1 : -1];
#endif
