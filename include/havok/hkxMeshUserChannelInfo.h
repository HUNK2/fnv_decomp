// include/havok/hkxMeshUserChannelInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKXMESHUSERCHANNELINFO_H
#define FNV_HAVOK_HKXMESHUSERCHANNELINFO_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkxMeshUserChannelInfo
{
  public:
    char pad0[0x14];
    hkStringPtr m_name;        // +0x14
    hkStringPtr m_pClassName;  // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMeshUserChannelInfo[(sizeof(hkxMeshUserChannelInfo) == 0x1C) ? 1 : -1];
#endif
