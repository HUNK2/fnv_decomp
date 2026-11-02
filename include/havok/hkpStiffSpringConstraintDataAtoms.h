// include/havok/hkpStiffSpringConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPSTIFFSPRINGCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPSTIFFSPRINGCONSTRAINTDATAATOMS_H

#include "hkBase.h"
#include "hkpSetLocalTranslationsConstraintAtom.h"
#include "hkpStiffSpringConstraintAtom.h"
#pragma pack(push, 1)
class hkpStiffSpringConstraintDataAtoms
{
  public:
    hkpSetLocalTranslationsConstraintAtom m_kSetLocalTranslationsConstraintAtom;  // +0x0
    hkpStiffSpringConstraintAtom m_kStiffSpringConstraintAtom;                    // +0x30
    char pad38[0x8];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpStiffSpringConstraintDataAtoms[(sizeof(hkpStiffSpringConstraintDataAtoms) == 0x40) ? 1 : -1];
#endif
