// include/havok/hkpStiffSpringConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPSTIFFSPRINGCONSTRAINTDATA_H
#define FNV_HAVOK_HKPSTIFFSPRINGCONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpStiffSpringConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpStiffSpringConstraintData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpStiffSpringConstraintDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpStiffSpringConstraintData[(sizeof(hkpStiffSpringConstraintData) == 0x50) ? 1 : -1];
#endif
