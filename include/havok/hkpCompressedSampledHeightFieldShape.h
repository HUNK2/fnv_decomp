// include/havok/hkpCompressedSampledHeightFieldShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x80.
#ifndef FNV_HAVOK_HKPCOMPRESSEDSAMPLEDHEIGHTFIELDSHAPE_H
#define FNV_HAVOK_HKPCOMPRESSEDSAMPLEDHEIGHTFIELDSHAPE_H

#include "hkBase.h"
#include "hkpSampledHeightFieldShape.h"
#pragma pack(push, 1)
class hkpCompressedSampledHeightFieldShape : public hkpSampledHeightFieldShape
{
  public:
    hkArray<hkUint16> m_kStorage;  // +0x60
    hkBool m_bFlipTriangleOrder;   // +0x6C
    char pad6D[0x3];
    hkReal m_offset;  // +0x70
    hkReal m_vScale;  // +0x74
    char pad78[0x8];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpCompressedSampledHeightFieldShape[(sizeof(hkpCompressedSampledHeightFieldShape) == 0x80) ? 1 : -1];
#endif
