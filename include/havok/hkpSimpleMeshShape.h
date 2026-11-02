// include/havok/hkpSimpleMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x44.
#ifndef FNV_HAVOK_HKPSIMPLEMESHSHAPE_H
#define FNV_HAVOK_HKPSIMPLEMESHSHAPE_H

#include "hkBase.h"
#include "hkpShapeCollection.h"
class hkpSimpleMeshShapeTriangle;
#pragma pack(push, 1)
class hkpSimpleMeshShape : public hkpShapeCollection
{
  public:
    hkArray<hkVector4> m_kVertices;                         // +0x18
    hkArray<hkpSimpleMeshShapeTriangle> m_uiTriangleCount;  // +0x24
    hkArray<hkUint8> m_kMaterialIndices8;                   // +0x30
    hkReal m_fSphereRadius;                                 // +0x3C
    hkUint8 m_eWeldingType;                                 // +0x40 (WeldingType)
    char pad41[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSimpleMeshShape[(sizeof(hkpSimpleMeshShape) == 0x44) ? 1 : -1];
#endif
