// include/havok/hkpMountedBallGun.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPMOUNTEDBALLGUN_H
#define FNV_HAVOK_HKPMOUNTEDBALLGUN_H

#include "hkBase.h"
#include "hkpBallGun.h"
#pragma pack(push, 1)
class hkpMountedBallGun : public hkpBallGun
{
  public:
    hkVector4 m_vContactPosition;  // +0x60
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMountedBallGun[(sizeof(hkpMountedBallGun) == 0x70) ? 1 : -1];
#endif
