// include/havok/hkGeometry.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKGEOMETRY_H
#define FNV_HAVOK_HKGEOMETRY_H

#include "hkBase.h"
class hkGeometryTriangle;
#pragma pack(push, 1)
class hkGeometry
{
  public:
    hkArray<hkVector4> m_kVertices;                 // +0x0
    hkArray<hkGeometryTriangle> m_uiTriangleCount;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkGeometry[(sizeof(hkGeometry) == 0x18) ? 1 : -1];
#endif
