// include/havok/hkpHingeLimitsData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xA0.
#ifndef FNV_HAVOK_HKPHINGELIMITSDATA_H
#define FNV_HAVOK_HKPHINGELIMITSDATA_H

#include "hkBase.h"
#include "hkpConstraintData.h"
#include "hkpHingeLimitsDataAtoms.h"
#pragma pack(push, 1)
class hkpHingeLimitsData : public hkpConstraintData
{
  public:
    char padC[0x4];
    hkpHingeLimitsDataAtoms m_kBridgeAtoms;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpHingeLimitsData[(sizeof(hkpHingeLimitsData) == 0xA0) ? 1 : -1];
#endif
