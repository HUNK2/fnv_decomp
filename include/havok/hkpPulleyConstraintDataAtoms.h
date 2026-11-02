// include/havok/hkpPulleyConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPPULLEYCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPPULLEYCONSTRAINTDATAATOMS_H

#include "hkBase.h"
#include "hkpPulleyConstraintAtom.h"
#include "hkpSetLocalTranslationsConstraintAtom.h"
#pragma pack(push, 1)
class hkpPulleyConstraintDataAtoms
{
  public:
    hkpSetLocalTranslationsConstraintAtom m_kTranslations;  // +0x0
    hkpPulleyConstraintAtom m_kPulley;                      // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPulleyConstraintDataAtoms[(sizeof(hkpPulleyConstraintDataAtoms) == 0x70) ? 1 : -1];
#endif
