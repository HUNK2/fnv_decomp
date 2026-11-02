// include/havok/hkpMassChangerModifierConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPMASSCHANGERMODIFIERCONSTRAINTATOM_H
#define FNV_HAVOK_HKPMASSCHANGERMODIFIERCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpModifierConstraintAtom.h"
#pragma pack(push, 1)
class hkpMassChangerModifierConstraintAtom : public hkpModifierConstraintAtom
{
  public:
    hkVector4 m_kFactorA;  // +0x20
    hkVector4 m_kFactorB;  // +0x30
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpMassChangerModifierConstraintAtom[(sizeof(hkpMassChangerModifierConstraintAtom) == 0x40) ? 1 : -1];
#endif
