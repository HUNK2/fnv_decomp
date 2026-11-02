// include/havok/hkpGroupFilter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x100.
#ifndef FNV_HAVOK_HKPGROUPFILTER_H
#define FNV_HAVOK_HKPGROUPFILTER_H

#include "hkBase.h"
#include "hkpCollisionFilter.h"
#pragma pack(push, 1)
class hkpGroupFilter : public hkpCollisionFilter
{
  public:
    hkInt32 m_iNextFreeSystemGroup;        // +0x30
    hkUint32 m_uiCollisionGroupMasks[32];  // +0x34
    char padB4[0xC];
    hkVector4 m_kCollisionGroupMaskVectors[4];  // +0xC0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpGroupFilter[(sizeof(hkpGroupFilter) == 0x100) ? 1 : -1];
#endif
