// include/havok/hkpStorageExtendedMeshShapeMaterial.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPEMATERIAL_H
#define FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPEMATERIAL_H

#include "hkBase.h"
#include "hkpMeshMaterial.h"
#pragma pack(push, 1)
class hkpStorageExtendedMeshShapeMaterial : public hkpMeshMaterial
{
  public:
    hkHalf m_fElasticity;  // +0x4
    hkHalf m_fSlipAngle;   // +0x6
    hkUlong m_ulUserData;  // +0x8
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpStorageExtendedMeshShapeMaterial[(sizeof(hkpStorageExtendedMeshShapeMaterial) == 0xC) ? 1 : -1];
#endif
