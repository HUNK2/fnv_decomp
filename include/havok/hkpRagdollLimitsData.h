// include/havok/hkpRagdollLimitsData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC0.
#ifndef FNV_HAVOK_HKPRAGDOLLLIMITSDATA_H
#define FNV_HAVOK_HKPRAGDOLLLIMITSDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpRagdollLimitsDataAtoms.h"
#pragma pack(push, 1)
class hkpRagdollLimitsData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpRagdollLimitsDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRagdollLimitsData[(sizeof(hkpRagdollLimitsData) == 0xC0) ? 1 : -1];
#endif
