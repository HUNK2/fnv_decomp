// include/havok/hkpLimitedHingeConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xE0.
#ifndef FNV_HAVOK_HKPLIMITEDHINGECONSTRAINTDATA_H
#define FNV_HAVOK_HKPLIMITEDHINGECONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpLimitedHingeConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpLimitedHingeConstraintData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpLimitedHingeConstraintDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpLimitedHingeConstraintData[(sizeof(hkpLimitedHingeConstraintData) == 0xE0) ? 1 : -1];
#endif
