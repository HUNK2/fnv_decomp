// include/havok/hkpRotationalConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x90.
#ifndef FNV_HAVOK_HKPROTATIONALCONSTRAINTDATA_H
#define FNV_HAVOK_HKPROTATIONALCONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpRotationalConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpRotationalConstraintData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpRotationalConstraintDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRotationalConstraintData[(sizeof(hkpRotationalConstraintData) == 0x90) ? 1 : -1];
#endif
