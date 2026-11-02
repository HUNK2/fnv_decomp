// include/havok/hkpHingeConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xB0.
#ifndef FNV_HAVOK_HKPHINGECONSTRAINTDATA_H
#define FNV_HAVOK_HKPHINGECONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpHingeConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpHingeConstraintData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpHingeConstraintDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpHingeConstraintData[(sizeof(hkpHingeConstraintData) == 0xB0) ? 1 : -1];
#endif
