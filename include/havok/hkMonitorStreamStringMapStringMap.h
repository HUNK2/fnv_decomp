// include/havok/hkMonitorStreamStringMapStringMap.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKMONITORSTREAMSTRINGMAPSTRINGMAP_H
#define FNV_HAVOK_HKMONITORSTREAMSTRINGMAPSTRINGMAP_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkMonitorStreamStringMapStringMap
{
  public:
    hkUint64 m_iOwnerObjectOffset;  // +0x0
    hkStringPtr m_kStringBuffer;    // +0x8
    char padC[0x4];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkMonitorStreamStringMapStringMap[(sizeof(hkMonitorStreamStringMapStringMap) == 0x10) ? 1 : -1];
#endif
