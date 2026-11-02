// include/havok/hkpStorageExtendedMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x110.
#ifndef FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPE_H
#define FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPE_H

#include "hkBase.h"
class hkpStorageExtendedMeshShapeMeshSubpartStorage;
class hkpStorageExtendedMeshShapeShapeSubpartStorage;
#pragma pack(push, 1)
class hkpStorageExtendedMeshShape
{
  public:
    char pad0[0xF0];
    hkArray<hkpStorageExtendedMeshShapeMeshSubpartStorage*> m_kMeshSubparts;    // +0xF0
    hkArray<hkpStorageExtendedMeshShapeShapeSubpartStorage*> m_kShapeSubparts;  // +0xFC
    char pad108[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpStorageExtendedMeshShape[(sizeof(hkpStorageExtendedMeshShape) == 0x110) ? 1 : -1];
#endif
