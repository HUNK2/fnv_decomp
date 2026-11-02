// include/havok/hkpSphereShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPSPHERESHAPE_H
#define FNV_HAVOK_HKPSPHERESHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#pragma pack(push, 1)
class hkpSphereShape : public hkpConvexShape
{
  public:
    hkUint32 m_aiValuesD34[3];  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSphereShape[(sizeof(hkpSphereShape) == 0x20) ? 1 : -1];
#endif
