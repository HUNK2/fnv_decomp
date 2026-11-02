// include/havok/hkpConvexVerticesShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPCONVEXVERTICESSHAPE_H
#define FNV_HAVOK_HKPCONVEXVERTICESSHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
class hkpCompressedMeshShapeConvexPiece;
class hkpConvexVerticesConnectivity;
class hkpConvexVerticesShapeFourVectors;
#pragma pack(push, 1)
class hkpConvexVerticesShape : public hkpConvexShape
{
  public:
    char pad14[0xC];
    hkVector4 m_kAabbHalfExtents;                                   // +0x20
    hkVector4 m_kAabbCenter;                                        // +0x30
    hkArray<hkpConvexVerticesShapeFourVectors> m_kRotatedVertices;  // +0x40
    hkInt32 m_iStridedVertexCount;                                          // +0x4C
    hkpCompressedMeshShapeConvexPiece* m_pConvexPiece;              // +0x50
    hkArray<hkVector4> m_kVertexPositions;                          // +0x54
    hkpConvexVerticesConnectivity* m_pConnectivity;                 // +0x60
    char pad64[0xC];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexVerticesShape[(sizeof(hkpConvexVerticesShape) == 0x70) ? 1 : -1];
#endif
