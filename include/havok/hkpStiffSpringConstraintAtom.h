// include/havok/hkpStiffSpringConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPSTIFFSPRINGCONSTRAINTATOM_H
#define FNV_HAVOK_HKPSTIFFSPRINGCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpStiffSpringConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0x2];
    hkReal m_fRestLength;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpStiffSpringConstraintAtom[(sizeof(hkpStiffSpringConstraintAtom) == 0x8) ? 1 : -1];
#endif
