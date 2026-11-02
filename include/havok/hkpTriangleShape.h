// include/havok/hkpTriangleShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPTRIANGLESHAPE_H
#define FNV_HAVOK_HKPTRIANGLESHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#pragma pack(push, 1)
class hkpTriangleShape : public hkpConvexShape
{
  public:
    hkUint16 m_kWeldingInfo;     // +0x14
    hkUint8 m_eWeldingType;      // +0x16 (WeldingType)
    hkUint8 m_ucWeldingPadding;  // +0x17
    char pad18[0x8];
    hkVector4 m_kVertexA;          // +0x20
    hkVector4 m_kVertexB;          // +0x30
    hkVector4 m_kVertexC;          // +0x40
    hkVector4 m_kVertexTransform;  // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpTriangleShape[(sizeof(hkpTriangleShape) == 0x60) ? 1 : -1];
#endif
