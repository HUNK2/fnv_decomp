// include/havok/hkpModifierConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPMODIFIERCONSTRAINTATOM_H
#define FNV_HAVOK_HKPMODIFIERCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpModifierConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0xE];
    hkUint16 m_usModifierAtomSize;    // +0x10
    hkUint16 m_iChildSize;            // +0x12
    hkpConstraintAtom* m_pChildAtom;  // +0x14
    hkUint32 m_auiShapeKeys[2];                // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpModifierConstraintAtom[(sizeof(hkpModifierConstraintAtom) == 0x20) ? 1 : -1];
#endif
