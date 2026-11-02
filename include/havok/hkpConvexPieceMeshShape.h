// include/havok/hkpConvexPieceMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x24.
#ifndef FNV_HAVOK_HKPCONVEXPIECEMESHSHAPE_H
#define FNV_HAVOK_HKPCONVEXPIECEMESHSHAPE_H

#include "hkBase.h"
#include "hkpShapeCollection.h"
class hkpConvexPieceStreamData;
#pragma pack(push, 1)
class hkpConvexPieceMeshShape : public hkpShapeCollection
{
  public:
    hkpConvexPieceStreamData* m_pConvexPieceStreamData;  // +0x18
    hkpShapeCollection* m_pDisplayMesh;                  // +0x1C
    hkReal m_fSphereRadius;                              // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexPieceMeshShape[(sizeof(hkpConvexPieceMeshShape) == 0x24) ? 1 : -1];
#endif
