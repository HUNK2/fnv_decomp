// include/havok/hkpCompressedMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xF0.
#ifndef FNV_HAVOK_HKPCOMPRESSEDMESHSHAPE_H
#define FNV_HAVOK_HKPCOMPRESSEDMESHSHAPE_H

#include "hkBase.h"
#include "hkAabb.h"
#include "hkpShapeCollection.h"
class hkpCompressedMeshShapeBigTriangle;
class hkpCompressedMeshShapeChunk;
class hkpCompressedMeshShapeConvexPiece;
class hkpNamedMeshMaterial;
#pragma pack(push, 1)
class hkpCompressedMeshShape : public hkpShapeCollection
{
  public:
    enum MaterialType
    {
        MATERIAL_NONE = 0,
        MATERIAL_SINGLE_VALUE_PER_CHUNK = 1,
        MATERIAL_ONE_BYTE_PER_TRIANGLE = 2,
        MATERIAL_TWO_BYTES_PER_TRIANGLE = 3,
        MATERIAL_FOUR_BYTES_PER_TRIANGLE = 4
    };
    hkInt32 m_iBitsPerIndex;      // +0x18
    hkInt32 m_iBitsPerWIndex;     // +0x1C
    hkInt32 m_iNumBitsForIndex;   // +0x20
    hkInt32 m_iNumBitsForWIndex;  // +0x24
    hkReal m_fSphereRadius;       // +0x28
    hkUint8 m_eWeldingType;       // +0x2C (WeldingType)
    hkUint8 m_ucMaterialType;     // +0x2D (MaterialType)
    char pad2E[0x2];
    hkArray<hkUint32> m_kMaterials;                              // +0x30
    hkArray<hkUint16> m_kMaterialIndices16;                      // +0x3C
    hkArray<hkUint8> m_kMaterialIndices8;                        // +0x48
    hkArray<hkTransform> m_kTransforms;                          // +0x54
    hkArray<hkVector4> m_kBigVertices;                           // +0x60
    hkArray<hkpCompressedMeshShapeBigTriangle> m_kBigTriangles;  // +0x6C
    hkArray<hkpCompressedMeshShapeChunk> m_kChunks;              // +0x78
    hkArray<hkpCompressedMeshShapeConvexPiece> m_kConvexPieces;  // +0x84
    hkReal m_eScriptError;                                       // +0x90
    char pad94[0xC];
    hkAabb m_kBounds;                                 // +0xA0
    void* m_pUserData;                                // +0xC0
    hkUint16 m_iIndexStriding;                        // +0xC4
    hkUint16 m_iNumTriangles;                         // +0xC6
    hkArray<hkpNamedMeshMaterial> m_kNamedMaterials;  // +0xC8
    char padD4[0x1C];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCompressedMeshShape[(sizeof(hkpCompressedMeshShape) == 0xF0) ? 1 : -1];
#endif
