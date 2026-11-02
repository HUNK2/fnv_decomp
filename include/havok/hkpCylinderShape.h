// include/havok/hkpCylinderShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPCYLINDERSHAPE_H
#define FNV_HAVOK_HKPCYLINDERSHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#pragma pack(push, 1)
class hkpCylinderShape : public hkpConvexShape
{
  public:
    enum VertexIdEncoding
    {
        VERTEX_ID_ENCODING_IS_BASE_A_SHIFT = 7,
        VERTEX_ID_ENCODING_SIN_SIGN_SHIFT = 6,
        VERTEX_ID_ENCODING_COS_SIGN_SHIFT = 5,
        VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT = 4,
        VERTEX_ID_ENCODING_VALUE_MASK = 15
    };
    hkReal m_fCylinderRadius;         // +0x14
    hkReal m_fCylinderRadiusSquared;  // +0x18
    char pad1C[0x4];
    hkVector4 m_kVertexA;         // +0x20
    hkVector4 m_kVertexB;         // +0x30
    hkVector4 m_kPerpendicular1;  // +0x40
    hkVector4 m_kPerpendicular2;  // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCylinderShape[(sizeof(hkpCylinderShape) == 0x60) ? 1 : -1];
#endif
