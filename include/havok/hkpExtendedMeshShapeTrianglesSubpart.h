// include/havok/hkpExtendedMeshShapeTrianglesSubpart.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPEXTENDEDMESHSHAPETRIANGLESSUBPART_H
#define FNV_HAVOK_HKPEXTENDEDMESHSHAPETRIANGLESSUBPART_H

#include "hkBase.h"
#include "hkpExtendedMeshShapeSubpart.h"
#pragma pack(push, 1)
class hkpExtendedMeshShapeTrianglesSubpart : public hkpExtendedMeshShapeSubpart
{
  public:
    hkInt32 m_iVertexStride;         // +0x14
    void* m_pMaterialIndexBase;      // +0x18
    hkInt32 m_iTriangleIndexStride;  // +0x1C
    hkInt32 m_iStridedVertexCount;           // +0x20
    char pad24[0xC];
    hkVector4 m_kVertexTransform;      // +0x30
    void* m_pMaterialDataBase;         // +0x40
    hkInt32 m_iMaterialStriding;       // +0x44
    hkInt8 m_ucIndexStridingType;      // +0x48 (IndexStridingType)
    hkInt8 m_bFlipAlternateTriangles;  // +0x49
    char pad4A[0x2];
    hkInt32 m_iTriangleOffset;  // +0x4C
    hkUlong m_ulUserData;       // +0x50
    char pad54[0xC];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpExtendedMeshShapeTrianglesSubpart[(sizeof(hkpExtendedMeshShapeTrianglesSubpart) == 0x60) ? 1 : -1];
#endif
