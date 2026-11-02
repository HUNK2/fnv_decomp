// include/havok/hkAabbUint32.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKAABBUINT32_H
#define FNV_HAVOK_HKAABBUINT32_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkAabbUint32
{
  public:
    hkUint32 m_kMinimumCorner[3];  // +0x0
    hkUint8 m_ucExpansionMin[3];   // +0xC
    hkUint8 m_ucExpansionShift;    // +0xF
    hkUint32 m_kMaximumCorner[3];  // +0x10
    hkUint8 m_ucExpansionMax[3];   // +0x1C
    hkUint8 m_expansionMaxXYZ;     // +0x1F
};
#pragma pack(pop)
typedef char fnv_hk_size_hkAabbUint32[(sizeof(hkAabbUint32) == 0x20) ? 1 : -1];
#endif
