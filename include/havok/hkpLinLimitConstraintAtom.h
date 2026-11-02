// include/havok/hkpLinLimitConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPLINLIMITCONSTRAINTATOM_H
#define FNV_HAVOK_HKPLINLIMITCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpLinLimitConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_ucAxisIndex;  // +0x2
    char pad3[0x1];
    hkReal m_kMinimumCorner;  // +0x4
    hkReal m_kMaximumCorner;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpLinLimitConstraintAtom[(sizeof(hkpLinLimitConstraintAtom) == 0xC) ? 1 : -1];
#endif
