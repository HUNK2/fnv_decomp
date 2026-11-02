// include/havok/hkpDisableEntityCollisionFilter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPDISABLEENTITYCOLLISIONFILTER_H
#define FNV_HAVOK_HKPDISABLEENTITYCOLLISIONFILTER_H

#include "hkBase.h"
#include "hkpCollisionFilter.h"
class hkpEntity;
#pragma pack(push, 1)
class hkpDisableEntityCollisionFilter : public hkpCollisionFilter
{
  public:
    char pad30[0x4];
    hkArray<hkpEntity*> m_kDisabledEntities;  // +0x34
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpDisableEntityCollisionFilter[(sizeof(hkpDisableEntityCollisionFilter) == 0x40) ? 1 : -1];
#endif
