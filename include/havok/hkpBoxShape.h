// include/havok/hkpBoxShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPBOXSHAPE_H
#define FNV_HAVOK_HKPBOXSHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#pragma pack(push, 1)
class hkpBoxShape : public hkpConvexShape
{
  public:
    char pad14[0xC];
    hkVector4 m_vHalfExtents;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBoxShape[(sizeof(hkpBoxShape) == 0x30) ? 1 : -1];
#endif
