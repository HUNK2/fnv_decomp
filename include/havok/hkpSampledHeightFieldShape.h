// include/havok/hkpSampledHeightFieldShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPSAMPLEDHEIGHTFIELDSHAPE_H
#define FNV_HAVOK_HKPSAMPLEDHEIGHTFIELDSHAPE_H

#include "hkBase.h"
#include "hkpHeightFieldShape.h"
#pragma pack(push, 1)
class hkpSampledHeightFieldShape : public hkpHeightFieldShape
{
  public:
    enum HeightFieldType
    {
        HEIGHTFIELD_STORAGE = 0,
        HEIGHTFIELD_COMPRESSED = 1,
        HEIGHTFIELD_USER = 2,
        HEIGHTFIELD_MAX_ID = 3
    };
    hkInt32 m_iXResolution;              // +0x10
    hkInt32 m_iZResolution;              // +0x14
    hkReal m_fHeightScale;               // +0x18
    hkBool m_bUseProjectionBasedHeight;  // +0x1C
    hkUint8 m_ucHeightFieldType;         // +0x1D (HeightFieldType)
    char pad1E[0x2];
    hkVector4 m_kHeightScaleVector;  // +0x20
    hkVector4 m_kInverseScale;       // +0x30
    hkVector4 m_kOffset;             // +0x40
    hkVector4 SetCenterPosition;             // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSampledHeightFieldShape[(sizeof(hkpSampledHeightFieldShape) == 0x60) ? 1 : -1];
#endif
