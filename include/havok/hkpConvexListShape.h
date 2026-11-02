// include/havok/hkpConvexListShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPCONVEXLISTSHAPE_H
#define FNV_HAVOK_HKPCONVEXLISTSHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#pragma pack(push, 1)
class hkpConvexListShape : public hkpConvexShape
{
  public:
    char pad14[0x4];
    hkReal m_fMaximumRadius;  // +0x18
    char pad1C[0x4];
    hkVector4 m_kAabbHalfExtents;  // +0x20
    hkVector4 m_kAabbCenter;       // +0x30
    hkBool m_bUseCachedAabb;       // +0x40
    char pad41[0x3];
    hkArray<hkpConvexShape*> m_kChildShapes;  // +0x44
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexListShape[(sizeof(hkpConvexListShape) == 0x50) ? 1 : -1];
#endif
