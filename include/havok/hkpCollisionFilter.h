// include/havok/hkpCollisionFilter.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPCOLLISIONFILTER_H
#define FNV_HAVOK_HKPCOLLISIONFILTER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpCollisionFilter : public hkReferencedObject
{
  public:
    enum hkpFilterType
    {
        HK_FILTER_UNKNOWN = 0,
        HK_FILTER_NULL = 1,
        HK_FILTER_GROUP = 2,
        HK_FILTER_LIST = 3,
        HK_FILTER_CUSTOM = 4,
        HK_FILTER_PAIR = 5,
        HK_FILTER_CONSTRAINT = 6
    };
    char pad8[0x10];
    hkUint32 m_uiPreTypePadding[2];   // +0x18
    hkUint32 m_type;                  // +0x20 (hkpFilterType)
    hkUint32 m_uiPostTypePadding[3];  // +0x24
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCollisionFilter[(sizeof(hkpCollisionFilter) == 0x30) ? 1 : -1];
#endif
