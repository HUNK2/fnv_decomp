// include/havok/hkpGenericConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x58.
#ifndef FNV_HAVOK_HKPGENERICCONSTRAINTDATA_H
#define FNV_HAVOK_HKPGENERICCONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintData.h"
#include "hkpGenericConstraintDataScheme.h"
#pragma pack(push, 1)
class hkpGenericConstraintData : public hkpConstraintData
{
  public:
    hkpBridgeAtoms m_kBridgeAtoms;                           // +0xC
    hkpGenericConstraintDataScheme m_kConstraintDataScheme;  // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpGenericConstraintData[(sizeof(hkpGenericConstraintData) == 0x58) ? 1 : -1];
#endif
