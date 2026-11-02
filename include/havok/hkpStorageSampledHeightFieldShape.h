// include/havok/hkpStorageSampledHeightFieldShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x80.
#ifndef FNV_HAVOK_HKPSTORAGESAMPLEDHEIGHTFIELDSHAPE_H
#define FNV_HAVOK_HKPSTORAGESAMPLEDHEIGHTFIELDSHAPE_H

#include "hkBase.h"
#include "hkpSampledHeightFieldShape.h"
#pragma pack(push, 1)
class hkpStorageSampledHeightFieldShape : public hkpSampledHeightFieldShape
{
  public:
    hkArray<hkReal> m_kStorage;  // +0x60
    char pad6C[0x14];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpStorageSampledHeightFieldShape[(sizeof(hkpStorageSampledHeightFieldShape) == 0x80) ? 1 : -1];
#endif
