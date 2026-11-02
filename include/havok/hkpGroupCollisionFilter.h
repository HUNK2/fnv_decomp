// include/havok/hkpGroupCollisionFilter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xB4.
#ifndef FNV_HAVOK_HKPGROUPCOLLISIONFILTER_H
#define FNV_HAVOK_HKPGROUPCOLLISIONFILTER_H

#include "hkBase.h"
#include "hkpCollisionFilter.h"
#pragma pack(push, 1)
class hkpGroupCollisionFilter : public hkpCollisionFilter
{
  public:
    hkBool m_bEnableCollisionTable;  // +0x30
    char pad31[0x3];
    hkUint32 m_uiCollisionTable[32];  // +0x34
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpGroupCollisionFilter[(sizeof(hkpGroupCollisionFilter) == 0xB4) ? 1 : -1];
#endif
