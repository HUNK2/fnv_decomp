// include/havok/hkaSkeletonMapperDataChainMapping.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKASKELETONMAPPERDATACHAINMAPPING_H
#define FNV_HAVOK_HKASKELETONMAPPERDATACHAINMAPPING_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaSkeletonMapperDataChainMapping
{
  public:
    hkInt16 m_sStartBoneA;  // +0x0
    hkInt16 m_sEndBoneA;    // +0x2
    hkInt16 m_sStartBoneB;  // +0x4
    hkInt16 m_sEndBoneB;    // +0x6
    char pad8[0x8];
    hkQsTransform m_kStartAFromBTransform;  // +0x10
    hkQsTransform m_kEndAFromBTransform;    // +0x40
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkaSkeletonMapperDataChainMapping[(sizeof(hkaSkeletonMapperDataChainMapping) == 0x70) ? 1 : -1];
#endif
