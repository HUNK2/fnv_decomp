// include/havok/hkaSkeletonMapperData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKASKELETONMAPPERDATA_H
#define FNV_HAVOK_HKASKELETONMAPPERDATA_H

#include "hkBase.h"
class hkaSkeleton;
class hkaSkeletonMapperDataChainMapping;
class hkaSkeletonMapperDataSimpleMapping;
#pragma pack(push, 1)
class hkaSkeletonMapperData
{
  public:
    enum MappingType
    {
        HK_RAGDOLL_MAPPING = 0,
        HK_RETARGETING_MAPPING = 1
    };
    hkaSkeleton* m_pSkeletonA;                                      // +0x0
    hkaSkeleton* m_pSkeletonB;                                      // +0x4
    hkArray<hkaSkeletonMapperDataSimpleMapping> m_kSimpleMappings;  // +0x8
    hkArray<hkaSkeletonMapperDataChainMapping> m_kChainMappings;    // +0x14
    hkArray<hkInt16> m_kUnmappedBones;                              // +0x20
    char pad2C[0x4];
    hkQsTransform m_kExtractedMotionMapping;  // +0x30
    hkBool m_bKeepUnmappedLocal;              // +0x60
    char pad61[0x3];
    hkInt32 m_eMappingType;  // +0x64 (MappingType)
    char pad68[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaSkeletonMapperData[(sizeof(hkaSkeletonMapperData) == 0x70) ? 1 : -1];
#endif
