// include/havok/hkpWheelConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x160.
#ifndef FNV_HAVOK_HKPWHEELCONSTRAINTDATA_H
#define FNV_HAVOK_HKPWHEELCONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpWheelConstraintDataAtoms.h"
#pragma pack(push, 1)
class hkpWheelConstraintData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpWheelConstraintDataAtoms m_kBridgeAtoms;  // +0x10
    hkVector4 m_kAxleDirectionInBodyB;           // +0x140
    hkVector4 m_kSteeringDirectionInBodyB;       // +0x150
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpWheelConstraintData[(sizeof(hkpWheelConstraintData) == 0x160) ? 1 : -1];
#endif
