// include/havok/hkaSkeletonMapper.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x80.
#ifndef FNV_HAVOK_HKASKELETONMAPPER_H
#define FNV_HAVOK_HKASKELETONMAPPER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#include "hkaSkeletonMapperData.h"
#pragma pack(push, 1)
class hkaSkeletonMapper : public hkReferencedObject
{
  public:
    enum ConstraintSource
    {
        NO_CONSTRAINTS = 0,
        REFERENCE_POSE = 1,
        CURRENT_POSE = 2
    };
    char pad8[0x8];
    hkaSkeletonMapperData m_kMappingData;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaSkeletonMapper[(sizeof(hkaSkeletonMapper) == 0x80) ? 1 : -1];
#endif
