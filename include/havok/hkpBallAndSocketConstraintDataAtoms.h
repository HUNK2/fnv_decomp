// include/havok/hkpBallAndSocketConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPBALLANDSOCKETCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPBALLANDSOCKETCONSTRAINTDATAATOMS_H

#include "hkBase.h"
#include "hkpBallSocketConstraintAtom.h"
#include "hkpSetLocalTranslationsConstraintAtom.h"
#pragma pack(push, 1)
class hkpBallAndSocketConstraintDataAtoms
{
  public:
    hkpSetLocalTranslationsConstraintAtom m_kSetLocalTranslationsConstraintAtom;  // +0x0
    hkpBallSocketConstraintAtom m_kBallSocket;                                    // +0x30
    char pad38[0x8];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpBallAndSocketConstraintDataAtoms[(sizeof(hkpBallAndSocketConstraintDataAtoms) == 0x40) ? 1 : -1];
#endif
