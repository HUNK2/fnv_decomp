// include/havok/hkpSimpleContactConstraintDataInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPSIMPLECONTACTCONSTRAINTDATAINFO_H
#define FNV_HAVOK_HKPSIMPLECONTACTCONSTRAINTDATAINFO_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpSimpleContactConstraintDataInfo
{
  public:
    hkUint16 m_flags;        // +0x0
    hkUint16 m_uiEdgeIndex;  // +0x2
    hkUint32 m_data[7];      // +0x4
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpSimpleContactConstraintDataInfo[(sizeof(hkpSimpleContactConstraintDataInfo) == 0x20) ? 1 : -1];
#endif
