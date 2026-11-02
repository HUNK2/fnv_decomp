// include/havok/hkpOverwritePivotConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x4.
#ifndef FNV_HAVOK_HKPOVERWRITEPIVOTCONSTRAINTATOM_H
#define FNV_HAVOK_HKPOVERWRITEPIVOTCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpOverwritePivotConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_bCopyPivotAtoPivotB;  // +0x2
    char pad3[0x1];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpOverwritePivotConstraintAtom[(sizeof(hkpOverwritePivotConstraintAtom) == 0x4) ? 1 : -1];
#endif
