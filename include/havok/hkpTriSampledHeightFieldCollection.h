// include/havok/hkpTriSampledHeightFieldCollection.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPTRISAMPLEDHEIGHTFIELDCOLLECTION_H
#define FNV_HAVOK_HKPTRISAMPLEDHEIGHTFIELDCOLLECTION_H

#include "hkBase.h"
#include "hkpShapeCollection.h"
class hkpSampledHeightFieldShape;
#pragma pack(push, 1)
class hkpTriSampledHeightFieldCollection : public hkpShapeCollection
{
  public:
    hkpSampledHeightFieldShape* m_pHeightFieldShape;  // +0x18
    hkInt32 m_iChildSize;                             // +0x1C
    hkReal m_fSphereRadius;                           // +0x20
    hkArray<hkUint16> m_kWeldingInfo;                 // +0x24
    hkVector4 m_kTriangleExtrusion;                   // +0x30
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpTriSampledHeightFieldCollection[(sizeof(hkpTriSampledHeightFieldCollection) == 0x40) ? 1 : -1];
#endif
