// include/havok/hkpMeshShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPMESHSHAPE_H
#define FNV_HAVOK_HKPMESHSHAPE_H

#include "hkBase.h"
#include "hkpShapeCollection.h"
class hkpMeshShapeSubpart;
#pragma pack(push, 1)
class hkpMeshShape : public hkpShapeCollection
{
  public:
    enum MeshShapeIndexStridingType
    {
        INDICES_INVALID = 0,
        INDICES_INT16 = 1,
        INDICES_INT32 = 2,
        INDICES_MAX_ID = 3
    };
    enum MeshShapeMaterialIndexStridingType
    {
        MATERIAL_INDICES_INVALID = 0,
        MATERIAL_INDICES_INT8 = 1,
        MATERIAL_INDICES_INT16 = 2,
        MATERIAL_INDICES_MAX_ID = 3
    };
    char pad18[0x8];
    hkVector4 m_kScaling;                      // +0x20
    hkInt32 m_iNumBitsForSubpartIndex;         // +0x30
    hkArray<hkpMeshShapeSubpart> m_kSubparts;  // +0x34
    hkArray<hkUint16> m_kWeldingInfo;          // +0x40
    hkUint8 m_eWeldingType;                    // +0x4C (WeldingType)
    char pad4D[0x3];
    hkReal m_fSphereRadius;  // +0x50
    hkInt32 m_auiShapeKeys[3];        // +0x54
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMeshShape[(sizeof(hkpMeshShape) == 0x60) ? 1 : -1];
#endif
