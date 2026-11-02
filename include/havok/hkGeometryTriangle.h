// include/havok/hkGeometryTriangle.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKGEOMETRYTRIANGLE_H
#define FNV_HAVOK_HKGEOMETRYTRIANGLE_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkGeometryTriangle
{
  public:
    hkInt32 m_kPointA;               // +0x0
    hkInt32 m_kPointB;               // +0x4
    hkInt32 m_iThirdValue;               // +0x8
    hkInt32 m_iMaterialIndex;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkGeometryTriangle[(sizeof(hkGeometryTriangle) == 0x10) ? 1 : -1];
#endif
