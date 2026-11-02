// include/havok/hkpPointToPlaneConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xA0.
#ifndef FNV_HAVOK_HKPPOINTTOPLANECONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPPOINTTOPLANECONSTRAINTDATAATOMS_H

#include "hkBase.h"
#include "hkpLinConstraintAtom.h"
#include "hkpSetLocalTransformsConstraintAtom.h"
#pragma pack(push, 1)
class hkpPointToPlaneConstraintDataAtoms
{
  public:
    hkpSetLocalTransformsConstraintAtom m_kTransforms;  // +0x0
    hkpLinConstraintAtom m_vLinearConstraint;           // +0x90
    char pad94[0xC];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpPointToPlaneConstraintDataAtoms[(sizeof(hkpPointToPlaneConstraintDataAtoms) == 0xA0) ? 1 : -1];
#endif
