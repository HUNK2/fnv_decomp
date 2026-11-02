// include/havok/hkpSoftContactModifierConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPSOFTCONTACTMODIFIERCONSTRAINTATOM_H
#define FNV_HAVOK_HKPSOFTCONTACTMODIFIERCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpModifierConstraintAtom.h"
#pragma pack(push, 1)
class hkpSoftContactModifierConstraintAtom : public hkpModifierConstraintAtom
{
  public:
    hkReal m_fTau;      // +0x20
    hkReal m_fDamping;  // +0x24
    char pad28[0x8];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpSoftContactModifierConstraintAtom[(sizeof(hkpSoftContactModifierConstraintAtom) == 0x30) ? 1 : -1];
#endif
