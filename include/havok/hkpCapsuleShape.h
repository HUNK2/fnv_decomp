// include/havok/hkpCapsuleShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPCAPSULESHAPE_H
#define FNV_HAVOK_HKPCAPSULESHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#pragma pack(push, 1)
class hkpCapsuleShape : public hkpConvexShape
{
  public:
    enum RayHitType
    {
        HIT_CAP0 = 0,
        HIT_CAP1 = 1,
        HIT_BODY = 2
    };
    char pad14[0xC];
    hkVector4 m_kVertexA;  // +0x20
    hkVector4 m_kVertexB;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCapsuleShape[(sizeof(hkpCapsuleShape) == 0x40) ? 1 : -1];
#endif
