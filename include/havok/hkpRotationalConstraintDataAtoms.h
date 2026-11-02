// include/havok/hkpRotationalConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x80.
#ifndef FNV_HAVOK_HKPROTATIONALCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPROTATIONALCONSTRAINTDATAATOMS_H

#include "hkBase.h"
#include "hkpAngConstraintAtom.h"
#include "hkpSetLocalRotationsConstraintAtom.h"
#pragma pack(push, 1)
class hkpRotationalConstraintDataAtoms
{
  public:
    hkpSetLocalRotationsConstraintAtom m_kLocalRotations;  // +0x0
    hkpAngConstraintAtom m_vAngularConstraint;             // +0x70
    char pad74[0xC];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRotationalConstraintDataAtoms[(sizeof(hkpRotationalConstraintDataAtoms) == 0x80) ? 1 : -1];
#endif
