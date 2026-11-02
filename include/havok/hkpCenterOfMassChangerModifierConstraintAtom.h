// include/havok/hkpCenterOfMassChangerModifierConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPCENTEROFMASSCHANGERMODIFIERCONSTRAINTATOM_H
#define FNV_HAVOK_HKPCENTEROFMASSCHANGERMODIFIERCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpModifierConstraintAtom.h"
#pragma pack(push, 1)
class hkpCenterOfMassChangerModifierConstraintAtom : public hkpModifierConstraintAtom
{
  public:
    hkVector4 m_kDisplacementA;  // +0x20
    hkVector4 m_kDisplacementB;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCenterOfMassChangerModifierConstraintAtom
    [(sizeof(hkpCenterOfMassChangerModifierConstraintAtom) == 0x40) ? 1 : -1];
#endif
