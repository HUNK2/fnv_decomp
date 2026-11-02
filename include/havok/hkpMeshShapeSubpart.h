// include/havok/hkpMeshShapeSubpart.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x38.
#ifndef FNV_HAVOK_HKPMESHSHAPESUBPART_H
#define FNV_HAVOK_HKPMESHSHAPESUBPART_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpMeshShapeSubpart
{
  public:
    void* m_pMaterialIndexBase;      // +0x0
    hkInt32 m_iTriangleIndexStride;  // +0x4
    hkInt32 m_iStridedVertexCount;           // +0x8
    void* m_pMaterialDataBase;       // +0xC
    hkInt8 m_ucIndexStridingType;    // +0x10 (MeshShapeIndexStridingType)
    hkInt8 m_iMaterialIndexType;     // +0x11 (MeshShapeMaterialIndexStridingType)
    char pad12[0x2];
    hkInt32 m_iMaterialStriding;        // +0x14
    hkInt32 m_bFlipAlternateTriangles;  // +0x18
    hkInt32 m_iTriangleCount;           // +0x1C
    void* m_pVertexBase;                // +0x20
    hkInt32 m_iVertexStriding;          // +0x24
    void* m_pIndexBase;                 // +0x28
    hkInt32 m_iIndexStriding;           // +0x2C
    hkInt32 m_iNumTriangles;            // +0x30
    hkInt32 m_iTriangleOffset;          // +0x34
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMeshShapeSubpart[(sizeof(hkpMeshShapeSubpart) == 0x38) ? 1 : -1];
#endif
