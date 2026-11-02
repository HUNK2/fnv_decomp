// include/havok/hkpPlaneShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPPLANESHAPE_H
#define FNV_HAVOK_HKPPLANESHAPE_H

#include "hkBase.h"
#include "hkpHeightFieldShape.h"
#pragma pack(push, 1)
class hkpPlaneShape : public hkpHeightFieldShape
{
  public:
    hkVector4 m_kTriangleNormal;   // +0x10
    hkVector4 m_kAabbCenter;       // +0x20
    hkVector4 m_kAabbHalfExtents;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPlaneShape[(sizeof(hkpPlaneShape) == 0x40) ? 1 : -1];
#endif
