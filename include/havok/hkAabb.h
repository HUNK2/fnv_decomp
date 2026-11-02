// include/havok/hkAabb.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKAABB_H
#define FNV_HAVOK_HKAABB_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkAabb
{
  public:
    hkVector4 m_kMinimumCorner;  // +0x0
    hkVector4 m_kMaximumCorner;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkAabb[(sizeof(hkAabb) == 0x20) ? 1 : -1];
#endif
