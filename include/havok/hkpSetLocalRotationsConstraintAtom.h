// include/havok/hkpSetLocalRotationsConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPSETLOCALROTATIONSCONSTRAINTATOM_H
#define FNV_HAVOK_HKPSETLOCALROTATIONSCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpSetLocalRotationsConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0xE];
    hkRotation m_kRotationA;  // +0x10
    hkRotation m_kRotationB;  // +0x40
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpSetLocalRotationsConstraintAtom[(sizeof(hkpSetLocalRotationsConstraintAtom) == 0x70) ? 1 : -1];
#endif
