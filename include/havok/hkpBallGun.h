// include/havok/hkpBallGun.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPBALLGUN_H
#define FNV_HAVOK_HKPBALLGUN_H

#include "hkBase.h"
#include "hkpFirstPersonGun.h"
#pragma pack(push, 1)
class hkpBallGun : public hkpFirstPersonGun
{
  public:
    hkReal m_fBulletRadius;       // +0x20
    hkReal m_fBulletVelocity;     // +0x24
    hkReal m_fBulletMass;         // +0x28
    hkReal m_fBulletSpread;       // +0x2C
    hkInt32 m_iBulletBatchCount;  // +0x30
    char pad34[0xC];
    hkVector4 m_kBulletDirection;  // +0x40
    void* m_pBulletQueue;          // +0x50
    char pad54[0xC];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBallGun[(sizeof(hkpBallGun) == 0x60) ? 1 : -1];
#endif
