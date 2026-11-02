// include/havok/hkpStorageExtendedMeshShapeShapeSubpartStorage.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPESHAPESUBPARTSTORAGE_H
#define FNV_HAVOK_HKPSTORAGEEXTENDEDMESHSHAPESHAPESUBPARTSTORAGE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpStorageExtendedMeshShapeMaterial;
#pragma pack(push, 1)
class hkpStorageExtendedMeshShapeShapeSubpartStorage : public hkReferencedObject
{
  public:
    hkArray<hkUint8> m_kMaterialIndices8;                       // +0x8
    hkArray<hkpStorageExtendedMeshShapeMaterial> m_kMaterials;  // +0x14
    hkArray<hkUint16> m_kMaterialIndices16;                     // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpStorageExtendedMeshShapeShapeSubpartStorage
    [(sizeof(hkpStorageExtendedMeshShapeShapeSubpartStorage) == 0x2C) ? 1 : -1];
#endif
