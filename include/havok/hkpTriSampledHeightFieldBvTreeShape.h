// include/havok/hkpTriSampledHeightFieldBvTreeShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPTRISAMPLEDHEIGHTFIELDBVTREESHAPE_H
#define FNV_HAVOK_HKPTRISAMPLEDHEIGHTFIELDBVTREESHAPE_H

#include "hkBase.h"
#include "hkpSingleShapeContainer.h"
#pragma pack(push, 1)
class hkpTriSampledHeightFieldBvTreeShape
{
  public:
    char pad0[0x14];
    hkpSingleShapeContainer m_kChildContainer;  // +0x14
    hkInt32 m_iChildSize;                       // +0x1C
    hkBool m_bCheckHeightFieldBounds;           // +0x20
    hkUint8 m_ucUnknownByte[12];                // +0x21
    char pad2D[0x3];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpTriSampledHeightFieldBvTreeShape[(sizeof(hkpTriSampledHeightFieldBvTreeShape) == 0x30) ? 1 : -1];
#endif
