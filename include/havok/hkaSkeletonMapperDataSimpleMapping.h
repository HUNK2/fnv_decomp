// include/havok/hkaSkeletonMapperDataSimpleMapping.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKASKELETONMAPPERDATASIMPLEMAPPING_H
#define FNV_HAVOK_HKASKELETONMAPPERDATASIMPLEMAPPING_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaSkeletonMapperDataSimpleMapping
{
  public:
    hkInt16 m_sBoneA;  // +0x0
    hkInt16 m_sBoneB;  // +0x2
    char pad4[0xC];
    hkQsTransform m_kAFromBTransform;  // +0x10
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkaSkeletonMapperDataSimpleMapping[(sizeof(hkaSkeletonMapperDataSimpleMapping) == 0x40) ? 1 : -1];
#endif
