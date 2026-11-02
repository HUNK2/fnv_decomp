// include/havok/hkpMalleableConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPMALLEABLECONSTRAINTDATA_H
#define FNV_HAVOK_HKPMALLEABLECONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintData.h"
#pragma pack(push, 1)
class hkpMalleableConstraintData : public hkpConstraintData
{
  public:
    hkpConstraintData* m_pConstraintData;  // +0xC
    hkpBridgeAtoms m_kBridgeAtoms;         // +0x10
    hkReal m_fSpringStrength;              // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMalleableConstraintData[(sizeof(hkpMalleableConstraintData) == 0x20) ? 1 : -1];
#endif
