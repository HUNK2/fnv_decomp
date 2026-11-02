// include/havok/hkpPrismaticConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xD0.
#ifndef FNV_HAVOK_HKPPRISMATICCONSTRAINTDATA_H
#define FNV_HAVOK_HKPPRISMATICCONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpPrismaticConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpPrismaticConstraintData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpPrismaticConstraintDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPrismaticConstraintData[(sizeof(hkpPrismaticConstraintData) == 0xD0) ? 1 : -1];
#endif
