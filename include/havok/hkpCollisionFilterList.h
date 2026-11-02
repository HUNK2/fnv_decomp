// include/havok/hkpCollisionFilterList.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x3C.
#ifndef FNV_HAVOK_HKPCOLLISIONFILTERLIST_H
#define FNV_HAVOK_HKPCOLLISIONFILTERLIST_H

#include "hkBase.h"
#include "hkpCollisionFilter.h"
#pragma pack(push, 1)
class hkpCollisionFilterList : public hkpCollisionFilter
{
  public:
    hkArray<hkpCollisionFilter*> m_kFilters;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCollisionFilterList[(sizeof(hkpCollisionFilterList) == 0x3C) ? 1 : -1];
#endif
